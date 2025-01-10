//
//  ZoomVideoSDKCRCHelper.h
//  ZoomVideoSDK
//
//  Created by ZOOM on 2023/4/4.
//  Copyright © Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ZoomVideoSDKCRCHelper : NSObject


/*!
 @brief Queries if the CRC feature is enabled.
 @return YES means that the CRC is enabled, otherwise it's disabled.
 @warning Only available after joining the session. Only available for the host/manager.
 */
- (BOOL)isCRCEnabled;

/*!
 @brief Get the dial-in SIP address of a live session when CRC  is enabled.
 @return Return the live session SIP address when the CRC is enabled. Otherwise return nil.
 */
- (NSString * _Nullable)getSessionSIPAddress;

/*!
 @brief Calls the CRC device.
 @param ipAddr The CRC device's IP address.
 @param protocol The protocol of the CRC device.
 @warning Only available for the host/co-host.
 @return If the function succeeds, the return value is Errors_Success.  Otherwise the function  returns a calling error. For more details, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)callCRCDevice:(NSString * _Nullable)ipAddr protocol:(ZoomVideoSDKCRCProtocol)protocol;

/*!
 @brief Cancels the call to the CRC device.
 @warning Only available for the host/co-host.
 @return If the function succeeds, the return value is Errors_Success.  Otherwise the function  returns a calling error. For more details, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)cancelCallCRCDevice;


@end

