//
//  ZoomVideoSDKConstants.h
//  ZoomVideoSDK
//
#ifndef ZoomVideoSDKConstants_h
#define ZoomVideoSDKConstants_h

/*!
 @brief ZoomVideoSDKError An enumeration of error.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKError)
{
    Errors_Success = 0,///<Success.
    Errors_Wrong_Usage,
    Errors_Internal_Error,
    Errors_Uninitialize,
    Errors_Memory_Error,
    Errors_Load_Module_Error,
    Errors_UnLoad_Module_Error,
    Errors_Invalid_Parameter,
    Errors_Call_Too_Frequently,
    Errors_No_Impl,
    Errors_Dont_Support_Feature,
    Errors_Unknown,
    Errors_Remove_Folder_Fail,
    Errors_Auth_Base = 1000,
    Errors_Auth_Error,
    Errors_Auth_Empty_Key_or_Secret,
    Errors_Auth_Wrong_Key_or_Secret,
    Errors_Auth_DoesNot_Support_SDK,
    Errors_Auth_Disable_SDK,
    Errors_JoinSession_NoSessionName = 1500,
    Errors_JoinSession_NoSessionToken,
    Errors_JoinSession_NoUserName,
    Errors_JoinSession_Invalid_SessionName,
    Errors_JoinSession_Invalid_Password,
    Errors_JoinSession_Invalid_SessionToken,
    Errors_JoinSession_SessionName_TooLong,
    Errors_JoinSession_Token_MismatchedSessionName,
    Errors_JoinSession_Token_NoSessionName,
    Errors_JoinSession_Token_RoleType_EmptyOrWrong,
    Errors_JoinSession_Token_UserIdentity_TooLong,
    Errors_Session_Base = 2000,
    Errors_Session_Module_Not_Found,
    Errors_Session_Service_Invalid,
    Errors_Session_Join_Failed,
    Errors_Session_No_Rights,
    Errors_Session_Already_In_Progress,
    Errors_Session_Dont_Support_SessionType,
    Errors_Session_You_Have_No_Share,
    Errors_Session_Reconnecting,
    Errors_Session_Disconnecting,
    Errors_Session_Not_Started = 2010,
    Errors_Session_Need_Password,
    Errors_Session_Password_Wrong,
    Errors_Session_Remote_DB_Error,
    Errors_Session_Invalid_Param,
    Errors_Session_Client_Incompatible,
    Errors_Session_Account_FreeMinutesExceeded,
    Errors_Session_Audio_Error = 3000,
    Errors_Session_Audio_No_Microphone,
    Errors_Session_Audio_No_Speaker,
    Errors_Session_Video_Error = 4000,
    Errors_Session_Video_Device_Error,
    
    Errors_Session_Live_Stream_Error = 5000,
    Errors_Session_Phone_Error = 5500,
    Errors_Dont_Support_Multi_Stream_Video_User,
    Errors_Fail_Assign_User_Privilege,
    Errors_No_Recording_In_Process,
    Errors_Set_Virtual_Background_Fail,
    
    Errors_Malloc_Failed = 6001,
    Errors_Not_In_Session,
    Errors_No_License,
    
    Errors_Video_Module_Not_Ready,
    Errors_Video_Module_Error,
    Errors_Video_device_error,
    Errors_No_Video_Data,
    
    Errors_Share_Module_Not_Ready,
    Errors_Share_Module_Error,
    Errors_No_Share_Data,
    
    Errors_Audio_Module_Not_Ready,
    Errors_Audio_Module_Error,
    Errors_No_Audio_Data,
    
    Errors_Preprocess_Rawdata_Error,
    Errors_Rawdata_No_Device_Running,
    Errors_Rawdata_Init_Device,
    Errors_Rawdata_Virtual_Device,
    Errors_Rawdata_Cannot_Change_Virtual_Device_In_Preview,
    Errors_Rawdata_Internal_Error,
    Errors_Rawdata_Send_Too_Much_Data_In_Single_Time,
    Errors_Rawdata_Send_Too_Frequently,
    Errors_Rawdata_Virtual_Mic_Is_Terminate,

    Errors_Session_Share_Error = 7001,
    Errors_Session_Share_Module_Not_Ready,
    Errors_Session_Share_You_Are_Not_Sharing,
    Errors_Session_Share_Type_Is_Not_Support,
    Errors_Session_Share_Internal_Error,
    
    Errors_Session_Filetransfer_UnknownError = 7500,
    Errors_Session_Filetransfer_FileTypeBlocked,
    Errors_Session_Filetransfer_FileSizelimited,
    
    Errors_Spotlight_NotEnoughUsers = 7600,
    Errors_Spotlight_ToMuchSpotlightedUsers,
    Errors_Spotlight_UserCannotBeSpotlighted,
    Errors_Spotlight_UserWithoutVideo,
    Errors_Spotlight_UserNotSpotlighted
};

/*!
 @brief ZoomVideoSDKAudioType An enumeration of audio type.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKAudioType) {
    ZoomVideoSDKAudioType_None   = 0,
    ZoomVideoSDKAudioType_VOIP,
    ZoomVideoSDKAudioType_TELEPHONY,
    ZoomVideoSDKAudioType_Unknown,
};

/*!
 @brief ZoomVideoSDKVideoAspect An enumeration of video aspect.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoAspect) {
    ///Original Aspect
    ZoomVideoSDKVideoAspect_Original         = 0,
    ///Full Filled
    ZoomVideoSDKVideoAspect_Full_Filled,
    ///Letter Box
    ZoomVideoSDKVideoAspect_LetterBox,
    ///Pan And Scan
    ZoomVideoSDKVideoAspect_PanAndScan,
};

/*!
 @brief ZoomVideoSDKVideoType An enumeration of video type.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoType) {
    ///Video Camera Data
    ZoomVideoSDKVideoType_VideoData  = 1,
    ///Share Data
    ZoomVideoSDKVideoType_ShareData,
};

/*!
 @brief You can get share status in the user object [ZoomVideoSDKUser]
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKReceiveSharingStatus) {
    ZoomVideoSDKReceiveSharingStatus_None = 0, ///No view or screen share available.
    ZoomVideoSDKReceiveSharingStatus_Start, ///User started sharing.
    ZoomVideoSDKReceiveSharingStatus_Pause, /// User paused sharing.
    ZoomVideoSDKReceiveSharingStatus_Resume, /// User resumed sharing.
    ZoomVideoSDKReceiveSharingStatus_Stop, /// User stopped sharing.
};

/*!
 @brief ZoomVideoSDKLiveStreamStatus An enumeration of live stream status.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKLiveStreamStatus) {
    ZoomVideoSDKLiveStreamStatus_None = 1,
    ZoomVideoSDKLiveStreamStatus_InProgress,
    ZoomVideoSDKLiveStreamStatus_Connecting,
    ZoomVideoSDKLiveStreamStatus_FailedTimeout,
    ZoomVideoSDKLiveStreamStatus_StartFailed,
    ZoomVideoSDKLiveStreamStatus_Ended,
};
/*
 @brief ZoomVideoSDKFrameDataFormat An enumeration of raw data frame format.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKFrameDataFormat) {
    ZoomVideoSDKFrameDataFormat_I420            = 1,
    ZoomVideoSDKFrameDataFormat_I420_Limit,
};

/*!
 @brief ZoomVideoSDKVideoRawDataRotation The direction of video.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKVideoRawDataRotation) {
    /// video direction 0
    ZoomVideoSDKVideoRawDataRotationNone      = 1,
    /// video direction 90
    ZoomVideoSDKVideoRawDataRotation90,
    /// video direction 180
    ZoomVideoSDKVideoRawDataRotation180,
    /// video direction 270
    ZoomVideoSDKVideoRawDataRotation270,
};

/*!
 @brief ZoomVideoSDKVideoResolution An enumeration of video raw data resolution.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoResolution) {
    /// video resolution 90
    ZoomVideoSDKVideoResolution_90,
    /// video resolution 180
    ZoomVideoSDKVideoResolution_180,
    /// video resolution 360
    ZoomVideoSDKVideoResolution_360,
    /// video resolution 720
    ZoomVideoSDKVideoResolution_720,
    /// auto change
    ZoomVideoSDKVideoResolution_Auto = 100,
};

/*!
 @brief Rawdata memory mode.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKRawDataMemoryMode) {
    ZoomVideoSDKRawDataMemoryModeStack,
    ZoomVideoSDKRawDataMemoryModeHeap
};

/*!
 @brief user's rawdata status.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKUserRawdataStatus) {
    ZoomVideoSDKUserRawdataOn,
    ZoomVideoSDKUserRawdataOff
};

/*!
 @brief Status of telephone.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKPhoneStatus) {
    ZoomVideoSDKPhoneStatus_None,///<No status.
    ZoomVideoSDKPhoneStatus_Calling,///<In process of calling out.
    ZoomVideoSDKPhoneStatus_Ringing,///<In process of ringing.
    ZoomVideoSDKPhoneStatus_Accepted,///<Accept the call.
    ZoomVideoSDKPhoneStatus_Success,///<Call successful.
    ZoomVideoSDKPhoneStatus_Failed,///<Call failed.
    ZoomVideoSDKPhoneStatus_Canceling,///<In process of canceling the response to the previous state.
    ZoomVideoSDKPhoneStatus_Canceled, ///<Cancel successfully.
    ZoomVideoSDKPhoneStatus_Cancel_Failed,///<Cancel fails.
    ZoomVideoSDKPhoneStatus_Timeout,///<Timeout.
};


/*!
 @brief The reason for the failure of the telephone call.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKPhoneFailedReason) {
    ZoomVideoSDKPhoneFailedReason_None,///<For initialization.
    ZoomVideoSDKPhoneFailedReason_Busy,///<The telephone number is busy.
    ZoomVideoSDKPhoneFailedReason_Not_Available,///<The telephone number is out of service.
    ZoomVideoSDKPhoneFailedReason_User_Hangup,///<The user hangs up.
    ZoomVideoSDKPhoneFailedReason_Other_Fail,///<Other reasons.
    ZoomVideoSDKPhoneFailedReason_No_Answer,///<The user did not answer the call.
    ZoomVideoSDKPhoneFailedReason_Block_No_Host,///<The invitation by phone is blocked by the system due to an absent host.
    ZoomVideoSDKPhoneFailedReason_Block_High_Rate,///<The invite by phone is blocked by the system due to the high cost.
    ZoomVideoSDKPhoneFailedReason_Block_Too_Frequent,///<To join the session, the invitee would press one on the phone. An invitee who fails to respond will encounter a timeout. If there are too many invitee timeouts, the call invitation feature for this session will be blocked.
};

/*!
 @brief An enum representing the status of the recording status.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKRecordingStatus) {
    ZoomVideoSDKRecordingStatus_None,///<For initialization.
    ZoomVideoSDKRecordingStatus_Start,///The recording has successfully started or successfully resumed.
    ZoomVideoSDKRecordingStatus_Stop,///The recording has stopped.
    ZoomVideoSDKRecordingStatus_DiskFull,///Recording is unsuccessful due to insufficient storage space..Please try to:1.Free up storage space  2.Purchase additional storage space
    ZoomVideoSDKRecordingStatus_Pause, ///The recording has paused.
    ZoomVideoSDKRecordingStatus_Connecting, ///The recording connecting.
};

typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoPreferenceMode) {
    ZoomVideoSDKVideoPreferenceMode_Balance, ///Balance mode.
    ZoomVideoSDKVideoPreferenceMode_Sharpness,///Sharpness mode.
    ZoomVideoSDKVideoPreferenceMode_Smoothness,///Smoothness mode.
    ZoomVideoSDKVideoPreferenceMode_Custom,///Custom mode.
};

typedef NS_ENUM(NSUInteger, ZoomVideoSDKMultiCameraStreamStatus) {
    ZoomVideoSDKMultiCameraStreamStatus_JoinStart,  ///<Current user only. This status is received when the current user starts the attempt to use multiple cameras in the session.
    ZoomVideoSDKMultiCameraStreamStatus_JoinFail,   ///<Current user only. This status is received when the current user fails the attempt to use multiple cameras in the session.
    ZoomVideoSDKMultiCameraStreamStatus_Joined,     ///<Broadcasted to all users. This status is received when a new camera has been successfully added to the session as the multiple cameras.
    ZoomVideoSDKMultiCameraStreamStatus_Left,       ///<Broadcasted to all users. This status is received when a camera that is being used as the multiple cameras has left the session.
    ZoomVideoSDKMultiCameraStreamStatus_VideoOn,    ///<Broadcasted to all users. When some multiple camera is unmuted, you will receive the status.
    ZoomVideoSDKMultiCameraStreamStatus_VideoOff,   ///<Broadcasted to all users. When some multiple camera is muted, you will receive the status.
};

typedef NS_ENUM(NSUInteger, ZoomVideoSDKLiveTranscriptionStatus) {
    ZoomVideoSDKLiveTranscriptionStatus_Stop,   /// translation stop
    ZoomVideoSDKLiveTranscriptionStatus_Start,  /// translation start
};

typedef NS_ENUM(NSUInteger, ZoomVideoSDKLiveTranscriptionOperationType) {
    ZoomVideoSDKLiveTranscriptionOperationType_None,    /// operation  none
    ZoomVideoSDKLiveTranscriptionOperationType_Add,     /// operation  add
    ZoomVideoSDKLiveTranscriptionOperationType_Update,  /// operation  update
    ZoomVideoSDKLiveTranscriptionOperationType_Delete,  /// operation  delete
    ZoomVideoSDKLiveTranscriptionOperationType_Complete,/// operation  complete
    ZoomVideoSDKLiveTranscriptionOperationType_NotSupported,/// operation  not support
};

typedef NS_ENUM(NSUInteger, ZoomVideoSDKSystemPermissionType) {
    ZoomVideoSDKSystemPermissionType_Camera,    /// System permission - Camera is needed.
    ZoomVideoSDKSystemPermissionType_Microphone,      /// System permission - Microphone is needed.
};

/*!
 @brief The chat message delete type are sent in the onChatMsgDeleteNotification:messageID:deleteBy: callback.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKChatMsgDeleteBy)
{
    ZoomVideoSDKChatMsgDeleteBy_NONE ,    /// None.
    ZoomVideoSDKChatMsgDeleteBy_SELF,     /// Indicates that the message was deleted by myself.
    ZoomVideoSDKChatMsgDeleteBy_HOST,     /// Indicates that the message was deleted by the session host.
    ZoomVideoSDKChatMsgDeleteBy_DLP,      /// Indicates that the message was deleted by Data Loss Prevention (dlp). This happens when the message goes against the host organization's compliance policies.
};

typedef NS_ENUM(NSUInteger, ZoomVideoSDKDialInNumType)
{
    ZoomVideoSDKDialInNumType_None,     /// For initialization.
    ZoomVideoSDKDialInNumType_Toll,     /// Paid.
    ZoomVideoSDKDialInNumType_TollFree, /// Free.
};


/**
 * @brief Type of video network status.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKNetworkStatus)
{
    ZoomVideoSDKNetworkStatus_None,
    ZoomVideoSDKNetworkStatus_Bad,
    ZoomVideoSDKNetworkStatus_Normal,
    ZoomVideoSDKNetworkStatus_Good,
};

/**
 * @brief Type of record agreement type.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKRecordAgreementType)
{
    ZoomVideoSDKRecordAgreementType_Invalid,
    ZoomVideoSDKRecordAgreementType_Traditional,
    ZoomVideoSDKRecordAgreementType_Individual_Only,
};

/**
 * @brief Enumerations of the type for virtual background.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVirtualBackgroundDataType)
{
    ZoomVideoSDKVirtualBackgroundDataType_None,
    ZoomVideoSDKVirtualBackgroundDataType_Image,
    ZoomVideoSDKVirtualBackgroundDataType_Blur,
};

/**
 * @brief Enumerations of the type for crc protocol.
 */

typedef NS_ENUM(NSUInteger, ZoomVideoSDKCRCProtocol) {
    ///H323
    ZoomVideoSDKCRCProtocol_H323        = 0,
    ///SIP
    ZoomVideoSDKCRCProtocol_SIP,
};

/**
 * @brief Enumerations of the type for crc call out status.
 */

typedef NS_ENUM(NSUInteger, ZoomVideoSDKCRCCallStatus) {
    ///OK
    ZoomVideoSDKCRCCallStatus_Success        = 0,
    ///Ring
    ZoomVideoSDKCRCCallStatus_Ring,
    ///Timeout
    ZoomVideoSDKCRCCallStatus_Timeout,
    ///Busy
    ZoomVideoSDKCRCCallStatus_Busy,
    ///Decline
    ZoomVideoSDKCRCCallStatus_Decline,
    ///Failed
    ZoomVideoSDKCRCCallStatus_Failed,
};

/**
 * @brief Enumerations of the type for annotation tool type.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKAnnotationToolType) {
    ZoomVideoSDKAnnotationToolType_None = 0,
    ZoomVideoSDKAnnotationToolType_Pen,
    ZoomVideoSDKAnnotationToolType_HighLighter,
    ZoomVideoSDKAnnotationToolType_AutoLine,
    ZoomVideoSDKAnnotationToolType_AutoRectangle,
    ZoomVideoSDKAnnotationToolType_AutoEllipse,
    ZoomVideoSDKAnnotationToolType_AutoArrow,
    ZoomVideoSDKAnnotationToolType_AutoRectangleFill,
    ZoomVideoSDKAnnotationToolType_AutoEllipseFill,
    ZoomVideoSDKAnnotationToolType_SpotLight,
    ZoomVideoSDKAnnotationToolType_Arrow,
    ZoomVideoSDKAnnotationToolType_ERASER,
    ZoomVideoSDKAnnotationToolType_Picker,
    ZoomVideoSDKAnnotationToolType_AutoRectangleSemiFill,
    ZoomVideoSDKAnnotationToolType_AutoEllipseSemiFill,
    ZoomVideoSDKAnnotationToolType_AutoDoubleArrow,
    ZoomVideoSDKAnnotationToolType_AutoDiamond,
    ZoomVideoSDKAnnotationToolType_AutoStampArrow,
    ZoomVideoSDKAnnotationToolType_AutoStampCheck,
    ZoomVideoSDKAnnotationToolType_AutoStampX,
    ZoomVideoSDKAnnotationToolType_AutoStampStar,
    ZoomVideoSDKAnnotationToolType_AutoStampHeart,
    ZoomVideoSDKAnnotationToolType_AutoStampQm,
};

/**
 * @brief Enumerations of the type for annotation clear type.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKAnnotationClearType) {
    ZoomVideoSDKAnnotationClearType_All = 0,    ///<Clear all annotations. Hosts, managers and shared meeting owners can use.
    ZoomVideoSDKAnnotationClearType_Others,     ///<Clear only the others' annotations. Only shared meeting owners can use.
    ZoomVideoSDKAnnotationClearType_My,         ///<Clear only your own annotations. Everyone can use.
};

/**
 * @brief Enumerations for the video subscribe failed reason.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKSubscribeFailReason) {
    ZoomVideoSDKSubscribeFailReason_None = 0,
    ZoomVideoSDKSubscribeFailReason_HasSubscribeShare, // has subscribe share and try to subscribe 720 video
    ZoomVideoSDKSubscribeFailReason_HasSubscribeExceededLimit,
    ZoomVideoSDKSubscribeFailReason_HasSubscribe1080POr720P,
    ZoomVideoSDKSubscribeFailReason_HasSubscribeOneShare, // try to subscribe the second share
};

/**
 * @brief Enumerations of the type for chat Privilege type
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKChatPrivilegeType) {
    /// Unknown type
    ZoomVideoSDKChatPrivilege_Unknown = 0,
    /// allow participant  to chat with everyone or only some one
    ZoomVideoSDKChatPrivilege_Everyone_Publicly_And_Privately,
    /// allow participant to chat with no one
    ZoomVideoSDKChatPrivilege_No_One,
    /// allow participant to chat with host,manager and everyone
    ZoomVideoSDKChatPrivilege_Everyone_Publicly,
};


typedef NS_ENUM(NSInteger, ZoomVideoSDKAudioChannel) {
    ZoomVideoSDKAudioChannel_Mono,         /// mono
    ZoomVideoSDKAudioChannel_Stereo,       /// stereo
};

typedef NS_ENUM(NSInteger, ZoomVideoSDKTestMicStatus) {
    ZoomVideoSDKMic_CanTest = 0,///<Test the mic via TestMicStartRecording. It is useless to call TestMicStopTesting/TestMicPlayRecording in this status.
    ZoomVideoSDKMic_Recording,///<Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless to call TestMicStartRecording in this status.
    ZoomVideoSDKMic_CanPlay,///<Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless call TestMicStartRecording in this status.
};


typedef NS_ENUM(NSInteger, ZoomVideoSDKFileTransferStatus) {
    FileTransferState_None = 0,         /// The file transfer has no state
    FileTransferState_ReadyToTransfer,  /// The file transfer is ready to start
    FileTransferState_Transfering,      /// The file transfer is in progress
    FileTransferState_TransferFailed,   /// The file transfer failed
    FileTransferState_TransferDone,     /// The file transfer completed successfully
};

typedef NS_ENUM(NSInteger, ZoomVideoSDKSessionLeaveReason) {
    ZoomVideoSDKSessionLeaveReason_Unknown = 0,     /// Unknown.
    ZoomVideoSDKSessionLeaveReason_BySelf,          /// Leave session by self.
    ZoomVideoSDKSessionLeaveReason_KickByHost,      /// Kicked by host.
    ZoomVideoSDKSessionLeaveReason_EndByHost,       /// Ended by host.
    ZoomVideoSDKSessionLeaveReason_NetworkError,    /// Network error.
};

/**
 @brief The mask shape.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKMaskShape) {
    ZoomVideoSDKMaskShape_Rectangle, ///Rectangle
    ZoomVideoSDKMaskShape_Circle,    ///Circle
    ZoomVideoSDKMaskShape_Oval,      ///Oval
};
#endif /* ZoomVideoSDKConstants_h */
