//
//  ZoomVideoSDK.h
//  ZoomVideoSDK
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ZoomVideoSDKUser.h"
#import "ZoomVideoSDKDelegate.h"
#import "ZoomVideoSDKConstants.h"
#import "ZoomVideoSDKAudioHelper.h"
#import "ZoomVideoSDKVideoHelper.h"
#import "ZoomVideoSDKUserHelper.h"
#import "ZoomVideoSDKVideoCanvas.h"
#import "ZoomVideoSDKRawDataPipe.h"
#import "ZoomVideoSDKShareHelper.h"
#import "ZoomVideoSDKLiveStreamHelper.h"
#import "ZoomVideoSDKChatHelper.h"
#import "ZoomVideoSDKPhoneHelper.h"
#import "ZoomVideoSDKCmdChannel.h"
#import "ZoomVideoSDKRecordingHelper.h"
#import "ZoomVideoSDKAudioSettingHelper.h"
#import "ZoomVideoSDKTestAudioDeviceHelper.h"
#import "ZoomVideoSDKLiveTranscriptionHelper.h"
#import "ZoomVideoSDKNetworkConnectionHelper.h"
#import "ZoomVideoSDKVirtualBackgroundHelper.h"

/*!
 @class ZoomVideoSDKExtendParams
 @brief ZoomVideoSDK extend params.
 */
@interface ZoomVideoSDKExtendParams : NSObject
/*!
 @brief Audio speaker test file path, only support mp3 format.The size cannot exceed 1M.
 */
@property (nonatomic, copy) NSString * _Nullable speakerTestFilePath;
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
@property (nonatomic, assign) id<ZoomVideoSDKVideoSource> _Nullable externalVideoSourceDelegate;

/*!
@brief [Optional] Session pre-processer delegate.
*/
@property (nonatomic, assign) id<ZoomVideoSDKVideoSourcePreProcessor> _Nullable preProcessorDelegate;

/*!
@brief [Optional] Session external audio source delegate.
*/
@property (nonatomic, assign) id<ZoomVideoSDKVirtualAudioMic> _Nullable virtualAudioMicDelegate;

/*!
@brief [Optional] Session virtual speaker.
*/
@property (nonatomic, assign) id<ZoomVideoSDKVirtualAudioSpeaker> _Nullable virtualAudioSpeakerDelegate;
@end

/*!
 @class ZoomVideoSDKSessionAudioStatisticInfo
 @brief Session audio statistic information
*/
@interface ZoomVideoSDKSessionAudioStatisticInfo : NSObject
/// The frequency in kilohertz (KHz) sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFrequency;
/// The audio latency (delay in network data transfer) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendLatency;
/// The audio jitter (change in latency) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendJitter;
/// The average audio packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossAvg;
/// The maximum audio packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossMax;

/// The frequency in kilohertz (KHz) received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFrequency;
/// The audio latency (delay in network data transfer) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvLatency;
/// The audio jitter (change in latency) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvJitter;
/// The average audio packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossAvg;
/// The maximum audio packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossMax;
@end

/*!
@brief The Session video or share statistic information
*/

@interface ZoomVideoSDKSessionASVStatisticInfo : NSObject
/// The frame width in pixels sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFrameWidth;
/// The frame height in pixels sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFrameHeight;
/// The frame rate in FPS sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFps;
/// The video latency (delay in network data transfer) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendLatency;
/// The video jitter (change in latency) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendJitter;
/// The average video packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossAvg;
/// The maximum video packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossMax;

/// The frame width in pixels received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFrameWidth;
/// The frame height in pixels received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFrameHeight;
/// The frame rate in FPS received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFps;
/// The video latency (delay in network data transfer) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvLatency;
/// The video jitter (change in latency) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvJitter;
/// The video average packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossAvg;
/// The maximum video packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossMax;
@end


/*!
 @brief Zoom Video SDK session.
 */
@interface ZoomVideoSDKSession : NSObject

/*!
@brief Get the session's name.
*/
- (NSString * _Nullable)getSessionName;

/*!
@brief Get the session Id.
@warning Only the host can get the session Id.
*/
- (NSString * _Nullable)getSessionID;

/*!
@brief Get the session number.
@warning get the session number
*/
- (unsigned long long)getSessionNumber;

/*!
@brief Get the session's password.
*/
- (NSString * _Nullable)getSessionPassword;

/*!
@brief Get the session phone passcode.
@warning get the session phone passcode
*/
- (NSString * _Nullable)getSessionPhonePasscode;

/*!
@brief Get the host's name.
*/
- (NSString * _Nullable)getSessionHostName;

/*!
@brief Get the session's host user object.
*/
- (ZoomVideoSDKUser * _Nullable)getSessionHost;

/*!
@brief Get a list of the session's remote users.
*/
- (NSArray <ZoomVideoSDKUser *>* _Nullable)getRemoteUsers;

/*!
@brief Get the session's user object for myself.
*/
- (ZoomVideoSDKUser * _Nullable)getMySelf;

/*!
@brief Get the session's audio statistic information.
*/
- (ZoomVideoSDKSessionAudioStatisticInfo * _Nullable)getSessionAudioStatisticInfo;

/*!
@brief Get the session's video statistic information.
*/
- (ZoomVideoSDKSessionASVStatisticInfo * _Nullable)getSessionVideoStatisticInfo;
/*!
@brief Get the session's screen share statistic information.
*/
- (ZoomVideoSDKSessionASVStatisticInfo * _Nullable)getSessionShareStatisticInfo;

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
@property (nullable, assign, nonatomic) id<ZoomVideoSDKDelegate> delegate;

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
@brief Notify common layer that application will resign active. Call the systematical method and then call the appWillResignActive via applicationWillResignActive.
@warning It is necessary to call the method in AppDelegate "- (void)applicationWillResignActive:(UIApplication *)application".
*/
- (void)appWillResignActive DEPRECATED_ATTRIBUTE;

/*!
 @brief Notify common layer that application did become active. Call the appDidBecomeActive via applicationDidBecomeActive.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationDidBecomeActive:(UIApplication *)application".
 */
- (void)appDidBecomeActive DEPRECATED_ATTRIBUTE;

/*!
 @brief Notify common layer that application did enter background. Call the appDidEnterBackgroud via applicationDidEnterBackground.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationDidEnterBackground:(UIApplication *)application".
 */
- (void)appDidEnterBackgroud DEPRECATED_ATTRIBUTE;

/*!
 @brief Notify common layer that application will terminate. Call the appWillTerminate via applicationWillTerminate.
 @warning It is necessary to call the method in AppDelegate "- (void)applicationWillTerminate:(UIApplication *)application".
 */
- (void)appWillTerminate DEPRECATED_MSG_ATTRIBUTE("Please use - (ZoomVideoSDKError)cleanup instead");

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

/*!
 @brief Returns an instance to manage audio controls related to the current video SDK session.
 @return The object of ZoomVideoSDKAudioHelper. See [ZoomVideoSDKAudioHelper]
 */
- (ZoomVideoSDKAudioHelper * _Nonnull)getAudioHelper;

/*!
 @brief Returns an instance to manage cameras and video during a video SDK session.
 @return The object of ZoomVideoSDKVideoHelper.  See [ZoomVideoSDKVideoHelper].
 */
- (ZoomVideoSDKVideoHelper * _Nonnull)getVideoHelper;

/*!
 @brief Returns an instance to manage users present in a video SDK session.
 @return The object of ZoomVideoSDKUserHelper. See [ZoomVideoSDKUserHelper].
 */
- (ZoomVideoSDKUserHelper * _Nonnull)getUserHelper;

/*!
 @brief Returns an instance to manage screen sharing during a video SDK session.
 @return The object of ZoomVideoSDKShareHelper. See [ZoomVideoSDKShareHelper].
 */
- (ZoomVideoSDKShareHelper * _Nonnull)getShareHelper;

/*!
 @brief Returns an instance to manage live streaming during a video SDK session.
 @return The object of ZoomVideoSDKLiveStreamHelper. See [ZoomVideoSDKLiveStreamHelper].
 */
- (ZoomVideoSDKLiveStreamHelper * _Nonnull)getLiveStreamHelper;

/*!
 @brief Returns an instance to send and receive chat messages within video SDK session participants.
 @return The object of ZoomVideoSDKChatHelper. See [ZoomVideoSDKChatHelper].
 */
- (ZoomVideoSDKChatHelper * _Nonnull)getChatHelper;

/*!
 @brief Returns an instance to manage phone invitations during a video SDK session.
 @return The object of ZoomVideoSDKPhoneHelper. See [ZoomVideoSDKPhoneHelper].
 */
- (ZoomVideoSDKPhoneHelper * _Nonnull)getPhoneHelper;

/*!
 @brief Returns an instance to use command channel features during a video SDK session.
 @return A [ZoomVideoSDKCmdChannel] instance.
 */
- (ZoomVideoSDKCmdChannel * _Nonnull)getCmdChannel;

/*!
 @brief Returns an instance to manage cloud recordings during a video SDK session.
 @return A [ZoomVideoSDKRecordingHelper] instance.
 */
- (ZoomVideoSDKRecordingHelper * _Nonnull)getRecordingHelper;

/*!
 @brief Get audio setting helper.
 @return A [ZoomVideoSDKAudioSettingHelper] instance.
 */
- (ZoomVideoSDKAudioSettingHelper * _Nonnull)getAudioSettingHelper;

/*!
 @brief Get test audio device helper
 @return A [ZoomVideoSDKTestAudioDeviceHelper] instance.
 */
- (ZoomVideoSDKTestAudioDeviceHelper * _Nonnull)getTestAudioDeviceHelper;

/*!
 @brief Get live transcription helper object.
 @return A [ZoomVideoSDKLiveTranscriptionHelper] instance.
 */
- (ZoomVideoSDKLiveTranscriptionHelper * _Nonnull)getLiveTranscriptionHelper;

/*!
 @brief Get virtual background helper object.
 @return A [ZoomVideoSDKLiveTranscriptionHelper] instance.
 */
- (ZoomVideoSDKVirtualBackgroundHelper * _Nonnull)getVirtualBackgroundHelper;

@end
