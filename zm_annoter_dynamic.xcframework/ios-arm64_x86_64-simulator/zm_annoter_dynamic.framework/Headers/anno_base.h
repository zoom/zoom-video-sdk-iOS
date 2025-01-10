/******************************************************************************
*
* Copyright (C) 2013, Zoom Video Communications, Inc
*
* History:
*	April 2013 - Created - ken.ding@zoom.us
*	
******************************************************************************/

#ifndef __ANNO_BASE_H__
#define __ANNO_BASE_H__

#include "anno_caps.h"

#ifdef __LINUX_CLIENT__
	#include <stddef.h>
#endif

#ifdef __ANDROID__
	#include <stddef.h>
	#include "anno_format.h"
	#include "anno_types.h"
#endif

// ----------------------------------------------------------------------------
//	class inheritd by AnnoBaseObserver
// ----------------------------------------------------------------------------
class CAnnoEncrypter
{
public:
	virtual int EncryptEstimate(
		IN unsigned int ssrc,
		IN const unsigned char* data,
		IN unsigned int dataLen,
		OUT unsigned char& method,
		OUT unsigned int& estimatedLen
		) { return 0; }

	virtual int EncryptData(
		IN unsigned int ssrc,
		IN const unsigned char* data,
		IN unsigned int dataLen,
		OUT unsigned char& method,
		OUT unsigned char* encryptData,
		OUT unsigned int& encryptDataLen
		) { return 0; }
};

class CAnnoDecrypter
{
public:
	virtual int DecryptEstimate(
		IN unsigned int ssrc,
		IN unsigned char method, 
		IN const unsigned char* data,
		IN unsigned int dataLen,
		OUT unsigned int& estimatedLen
		) { return 0; }

	virtual int DecryptData(
		IN unsigned int ssrc,
		IN unsigned char method, 
		IN const unsigned char* data, 
		IN unsigned int dataLen,
		IN bool bFromMeshParent,
		OUT unsigned char* decryptData,
		OUT unsigned int& decryptDataLen
		) { return 0; }
};

class CAnnoRtpPacketSender
{
public:
	virtual int SendRtpPacket(
		IN unsigned int ssrc, 
		IN const unsigned char* data,
		IN unsigned int dataLen
		) { return 0; }
};

// ----------------------------------------------------------------------------
//	Forward declarations
// ----------------------------------------------------------------------------

class AnnoEngine;

// ----------------------------------------------------------------------------
//	AnnoBase Callbacks
// ----------------------------------------------------------------------------

class ANNO_DLLEXPORT AnnoBaseObserver 
	: public CAnnoEncrypter
	, public CAnnoDecrypter
	, public CAnnoRtpPacketSender
{
public:

	virtual int OnAnnoBaseEvent(
		IN	const AnnoEventType eventType, 
		IN	const WPARAM wParam, 
		IN	const LPARAM lParam
		) = 0;

	virtual int SendAnnoPdu(
		IN	const uint32_t targetId,
		IN	const unsigned char* data,	// observer must not release the memory
		IN	const size_t size
		) = 0;

	virtual int SendWbContent(const AnnoContent* content) 
	{ 
		return 0; 
	}

	virtual int SendWbMonitorInfo(const WbMonitorInfo* info)
	{ 
		return 0; 
	}

	
protected:
	virtual ~AnnoBaseObserver() {}
};

// ----------------------------------------------------------------------------
//	AnnoBase
// ----------------------------------------------------------------------------

class ANNO_DLLEXPORT AnnoBase
{
public:
	//
	// Retrieve this interface by passing into the previously created engine 
	// and increase reference count
	static AnnoBase* GetInterface(
		IN AnnoEngine* annoEngine
	);

	//
	// Release this interface and decrease referenced count
	virtual int Release() = 0;

	//
	// Start an annotation session
	virtual int AnnoStartup(
		IN	const AnnoStartupInput& annoStartupInput,
		IN	const AnnoConfig annoConfig
	) = 0;

	//
	// Shut down the annotation session
	virtual int AnnoShutdown() = 0;

	virtual int NewWhiteboard(
		IN	const AnnoStartupInput& annoStartupInput,
		IN	const WbConfig& wbConfig
	) = 0;

	virtual int CloseWhiteboard() = 0;

	virtual int RegisterObserver(IN	const AnnoBaseObserver& observer) = 0;
  virtual int DeregisterObserver(IN	const AnnoBaseObserver& observer) = 0;

	//
	// Call this method to pass remote annotation data into this session
	virtual int OnAnnoPduReceived(
		IN	const unsigned char* data,	// caller must release the memory
		IN	const size_t size
	) = 0;

	virtual int SetAnnoSetting(IN const void* pData) = 0;
	virtual int GetAnnoData(IN void*& data) = 0;

	virtual int ReceiveRTPPacket(
		IN const unsigned char* data, 
		IN unsigned int dataLen,
		IN unsigned int recvTimeMs,
		IN bool bFromMeshParent
	) = 0;

	virtual int OpenCloudWhiteboard(
		IN const AnnoStartupInput& annoStartupInput, 
		IN const CloudWBConfig& cloud_wb_config
	) = 0;

	virtual int CloseCloudWhiteboard() = 0;
    
	virtual int SetCloudWbInfo(
		IN const void* wbInfo
	) = 0;

    virtual int SendWCLWBMessage( 
		IN const uint8_t* p_data, 
		IN uint32_t data_len  
	) = 0; 

  virtual int StartWbCapture() = 0;
  virtual int StopWbCapture() = 0;
	virtual int SendWCLWBContent(IN const void* wb_content) = 0;

	
};

#endif // __ANNO_BASE_H__
