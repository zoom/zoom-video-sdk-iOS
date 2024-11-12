//
//  ZoomVideoSDK.h
//  ZoomVideoSDK
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKSession.h>
#import <ZoomVideoSDK/ZoomVideoSDKUser.h>
#import <ZoomVideoSDK/ZoomVideoSDKDelegate.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>
#import <ZoomVideoSDK/ZoomVideoSDKAudioHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKUserHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoCanvas.h>
#import <ZoomVideoSDK/ZoomVideoSDKRawDataPipe.h>
#import <ZoomVideoSDK/ZoomVideoSDKShareHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKLiveStreamHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKChatHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKPhoneHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKCmdChannel.h>
#import <ZoomVideoSDK/ZoomVideoSDKRecordingHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKAudioSettingHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKTestAudioDeviceHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKLiveTranscriptionHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKNetworkConnectionHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKVirtualBackgroundHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKCRCHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKMaskHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKRemoteCameraControlHelper.h>

/*!
 @class ZoomVideoSDKExtendParams
 @brief ZoomVideoSDK extend params.
 */
@interface ZoomVideoSDKExtendParams : NSObject
/*!
 @brief Audio speaker test file path, only support mp3 format.The size cannot exceed 1M.
 */
@property (nonatomic, copy) NSString * _Nullable speakerTestFilePath;

@property (nonatomic, assign) NSInteger wrapperType;

@end

/*!
 @class ZoomVideoSDKInitParams
 @brief Parameter class use to initialize the ZoomVideoSDK.
 */
@interface ZoomVideoSDKInitParams : NSObject
/*!
 @brief [Required] The domain of ZoomVideoSDK.
 */
@property (nonatomic, copy) NSString * _Nullable domain;
/*!
 @brief [Optional] The Prefix of Log file name.
 */
@property (nonatomic, copy) NSString * _Nullable logFilePrefix;
/*!
 @brief [Optional] If you use screen share, you need create group id in your apple developer account, and setup here.
 */
@property (nonatomic, copy) NSString * _Nullable  appGroupId;
/*!
 @brief [Optional] enable/disable log of SDK. log path AppData/tmp
 */
@property (nonatomic, assign) BOOL                          enableLog;
/*!
 @brief [Optional] The video rawdata memory mode. Default is ZoomVideoSDKRawDataMemoryModeStack
 */
@property (nonatomic, assign) ZoomVideoSDKRawDataMemoryMode  videoRawdataMemoryMode;
/*!
 @brief [Optional] The share rawdata memory mode. Default is ZoomVideoSDKRawDataMemoryModeStack
 */
@property (nonatomic, assign) ZoomVideoSDKRawDataMemoryMode  shareRawdataMemoryMode;
/*!
 @brief [Optional] The audio rawdata memory mode. Default is ZoomVideoSDKRawDataMemoryModeStack
 */
@property (nonatomic, assign) ZoomVideoSDKRawDataMemoryMode  audioRawdataMemoryMode;
/*!
 @brief [Optional] The SDK extend params
 */
@property (nonatomic, strong) ZoomVideoSDKExtendParams * _Nullable extendParam;
@end

/*!
 @class ZoomVideoSDKVideoOptions
 @brief The video option of join session
 */
@interface ZoomVideoSDKVideoOptions : NSObject

/*!
 @brief Local video on or off
 */
@property (assign, nonatomic) BOOL localVideoOn;
/*!
 @brief set the multitaskingCameraAccessEnabled for AVCaptureSession of local camera. For more informaton, refer to https://developer.apple.com/documentation/avfoundation/avcapturesession/4013228-multitaskingcameraaccesssupporte
 */
@property (assign, nonatomic) BOOL multitaskingCameraAccessEnabled;

@end

/*!
 @class ZoomVideoSDKAudioOptions
 @brief The audio option of join session
 */
@interface ZoomVideoSDKAudioOptions : NSObject

/*!
 @brief Local audio connect or not
 */
@property (assign, nonatomic) BOOL connect;

/*!
 @brief Local audio mute or not
 */
@property (assign, nonatomic) BOOL mute;

/**
 @brief Determine if my voice in the mixed audio raw data or not. default is YES.
 */
@property (assign, nonatomic) BOOL isMyVoiceInMix;

/**
 @brief If the volume is muted or the volume is low, need to automatically adjust the volume of speaker? Default is NO.
 */
@property (nonatomic, assign) BOOL autoAdjustSpeakerVolume;
@end

/*!
 @class ZoomVideoSDKSessionContext
 @brief A Class contains the session information.
 */
@interface ZoomVideoSDKSessionContext : NSObject
/*!
 @brief [Required] Session Name.
 sessionName The string length must be less than 150.
 Supported character scopes are: Letters, numbers, spaces, and the following characters:
 "!", "#", "$", "%", "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]", "^", "_", "{", "}", "|", "~", ","
 */
@property (nonatomic, copy) NSString * _Nullable sessionName;
/*!
 @brief [Optional] Session Password.
 */
@property (nonatomic, copy) NSString * _Nullable sessionPassword;
/*!
 @brief [Required] User Name.
 */
@property (nonatomic, copy) NSString * _Nullable userName;
/*!
 @brief [Required] JWT token to join session.
 */
@property (nonatomic, copy) NSString * _Nullable token;
/*!
 @brief [Optional] The amount of time in minutes after which an idle session will end.
 Default value: 40
 If the value is less than 0, the session will stay alive indefinitely.
 When there is only one user remaining in a session, that session is considered idle.
 */
@property (nonatomic, assign) NSInteger sessionIdleTimeoutMins;
/*!
 @brief [Optional] Whether to cancel the bandwidth limit, If YES is set, the network bandwidth is no longer limited, and better audio and video quality can be obtained.Bandwidth is not limited by default. If it is a wifi network, the bandwidth is not limited, and this setting is invalid.
 */
@property (nonatomic, assign) BOOL enable5GHighBandWidth;
/*!
 @brief [Optional]  Audio Option.
 */
@property (nonatomic, strong) ZoomVideoSDKAudioOptions * _Nullable audioOption;
/*!
 @brief [Optional] Video Option.
 */
@property (nonatomic, strong) ZoomVideoSDKVideoOptions * _Nullable videoOption;

/*!
@brief [Optional] Session external video source delegate.
*/
@property (weak, nonatomic) id<ZoomVideoSDKVideoSource> _Nullable externalVideoSourceDelegate;

/*!
@brief [Optional] Session pre-processer delegate.
*/
@property (weak, nonatomic) id<ZoomVideoSDKVideoSourcePreProcessor> _Nullable preProcessorDelegate;

/*!
@brief [Optional] Session external audio source delegate.
*/
@property (weak, nonatomic) id<ZoomVideoSDKVirtualAudioMic> _Nullable virtualAudioMicDelegate;

/*!
@brief [Optional] Session virtual speaker.
*/
@property (weak, nonatomic) id<ZoomVideoSDKVirtualAudioSpeaker> _Nullable virtualAudioSpeakerDelegate;
@end

/*!
 @class ZoomVideoSDK
 @brief Zoom Video SDK API manager. Main singleton object that controls the video session creation, event callbacks and other main features of video SDK.
 @warning Access to the class and all the other components of the VideoSDK by merging <ZoomVideoSDK/ZoomVideoSDK.h> into source code.
 @warning The user can only obtain SDK configuration by initializing the class.
 */
@interface ZoomVideoSDK : NSObject

/*!
 @brief The delegate of ZoomVideoSDK, a listener object that groups together all the callbacks related to a session.
 */
@property (weak, nonatomic) id<ZoomVideoSDKDelegate> _Nullable delegate;

/*!
 @brief Returns ZoomVideoSDK instance.
 */
+ (ZoomVideoSDK * _Nullable)shareInstance;

/*!
 @brief Initialize the Zoom SDK with the appropriate parameters in the ZoomVideoSDKInitParams object.
 @warning Need initialize first for doing the following steps.
 @param context Initialize the parameter configuration of the SDK, please See [ZoomVideoSDKInitParams].
 @return The result of initialize SDK.
 */
- (ZoomVideoSDKError)initialize:(ZoomVideoSDKInitParams * _Nonnull)context;

/*!
 @brief un-nitialize the Zoom SDK.
 @warning Only cleanup succesfully after initialized .
 @return The result of cleanup SDK.
 */
- (ZoomVideoSDKError)cleanup;

/*!
 @brief Call this method to join a session with the appropriate [ZoomVideoSDKSessionContext] parameters. When successful, the SDK will attempt to join a session. Use the callbacks in the delegate to confirm whether the SDK actually joined.
 @param context The context which contains the parameters.
 @return The state of join session, started or failed.
 */
- (ZoomVideoSDKSession * _Nullable)joinSession:(ZoomVideoSDKSessionContext * _Nonnull)context;

/*!
 @brief Call this method to leave a session previously joined through joinSession method call. When successful, the SDK will attempt to leave a session. Use the callbacks in the delegate to confirm whether the SDK actually left.
 @param end if end the session for host. YES if the host should end the entire session, or NO if the host should just leave the session.
 @warning only host can end session. You can get the isHost information from in-Session 'userInfo'.
 @return The result of it.
 */
- (ZoomVideoSDKError)leaveSession:(BOOL)end;

/*!
 @brief Returns the current session information.
 @return Session information See [SDKSessionInfo].
 */
- (ZoomVideoSDKSession * _Nullable)getSession;

/*!
 @brief Check if there is an active session between participants.
 @return YES if there is; NO if not
 */
- (BOOL)isInSession;

/*!
 @brief Returns Zoom SDK internal version.
 @return SDK version.
 */
- (NSString * _Nullable)getSDKVersion;

/**
 @brief Exporting a log file to local disk.
 @return If the function succeeds, the return value is the exported log file path.
 */
- (NSString * _Nullable)exportLog;

/**
 @brief Clean all exported logs.
 @return If the function succeeds, it will return Errors_Success. Otherwise failed.
 */
- (ZoomVideoSDKError)cleanAllExportedLogs;
/*!
 @brief Returns an instance to manage audio controls related to the current video SDK session.
 @return The object of ZoomVideoSDKAudioHelper. See [ZoomVideoSDKAudioHelper]
 */
- (ZoomVideoSDKAudioHelper * _Nullable)getAudioHelper;

/*!
 @brief Returns an instance to manage cameras and video during a video SDK session.
 @return The object of ZoomVideoSDKVideoHelper.  See [ZoomVideoSDKVideoHelper].
 */
- (ZoomVideoSDKVideoHelper * _Nullable)getVideoHelper;

/*!
 @brief Returns an instance to manage users present in a video SDK session.
 @return The object of ZoomVideoSDKUserHelper. See [ZoomVideoSDKUserHelper].
 */
- (ZoomVideoSDKUserHelper * _Nullable)getUserHelper;

/*!
 @brief Returns an instance to manage screen sharing during a video SDK session.
 @return The object of ZoomVideoSDKShareHelper. See [ZoomVideoSDKShareHelper].
 */
- (ZoomVideoSDKShareHelper * _Nullable)getShareHelper;

/*!
 @brief Returns an instance to manage live streaming during a video SDK session.
 @return The object of ZoomVideoSDKLiveStreamHelper. See [ZoomVideoSDKLiveStreamHelper].
 */
- (ZoomVideoSDKLiveStreamHelper * _Nullable)getLiveStreamHelper;

/*!
 @brief Returns an instance to send and receive chat messages within video SDK session participants.
 @return The object of ZoomVideoSDKChatHelper. See [ZoomVideoSDKChatHelper].
 */
- (ZoomVideoSDKChatHelper * _Nullable)getChatHelper;

/*!
 @brief Returns an instance to manage phone invitations during a video SDK session.
 @return The object of ZoomVideoSDKPhoneHelper. See [ZoomVideoSDKPhoneHelper].
 */
- (ZoomVideoSDKPhoneHelper * _Nullable)getPhoneHelper;

/*!
 @brief Returns an instance to use command channel features during a video SDK session.
 @return A [ZoomVideoSDKCmdChannel] instance.
 */
- (ZoomVideoSDKCmdChannel * _Nullable)getCmdChannel;

/*!
 @brief Returns an instance to manage cloud recordings during a video SDK session.
 @return A [ZoomVideoSDKRecordingHelper] instance.
 */
- (ZoomVideoSDKRecordingHelper * _Nullable)getRecordingHelper;

/*!
 @brief Get audio setting helper.
 @return A [ZoomVideoSDKAudioSettingHelper] instance.
 */
- (ZoomVideoSDKAudioSettingHelper * _Nullable)getAudioSettingHelper;

/*!
 @brief Get test audio device helper
 @return A [ZoomVideoSDKTestAudioDeviceHelper] instance.
 */
- (ZoomVideoSDKTestAudioDeviceHelper * _Nullable)getTestAudioDeviceHelper;

/*!
 @brief Get live transcription helper object.
 @return A [ZoomVideoSDKLiveTranscriptionHelper] instance.
 */
- (ZoomVideoSDKLiveTranscriptionHelper * _Nullable)getLiveTranscriptionHelper;

/*!
 @brief Get virtual background helper object.
 @return A [ZoomVideoSDKLiveTranscriptionHelper] instance.
 */
- (ZoomVideoSDKVirtualBackgroundHelper * _Nullable)getVirtualBackgroundHelper;

/**
 @brief Get crc helper object.
 @return If the function succeeds, the return value is the crc helper object. Otherwise returns nil.
 */
- (ZoomVideoSDKCRCHelper * _Nullable)getCRCHelper;

/*!
 @brief Get mask helper Object.
 @return If the function succeeds, the return value is the mask helper object. Otherwise returns nil.
 */
- (ZoomVideoSDKMaskHelper * _Nullable)getMaskHelper;

@end
