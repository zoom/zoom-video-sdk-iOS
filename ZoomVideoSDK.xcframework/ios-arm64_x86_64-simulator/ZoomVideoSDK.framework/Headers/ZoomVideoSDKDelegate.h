//
//  ZoomVideoSDKDelegate.h
//  ZoomVideoSDK
//

#import <Foundation/Foundation.h>
#import "ZoomVideoSDKConstants.h"
#import "ZoomVideoSDKVideoRawData.h"
#import "ZoomVideoSDKAudioRawData.h"
#import "ZoomVideoSDKChatHelper.h"
#import "ZoomVideoSDKPreProcessRawData.h"
#import "ZoomVideoSDKVideoSender.h"
#import "ZoomVideoSDKShareSender.h"
#import "ZoomVideoSDKShareAudioSender.h"
#import "ZoomVideoSDKAudioSender.h"
#import "ZoomVideoSDKVideoCapability.h"
#import "ZoomVideoSDKVideoHelper.h"
#import "ZoomVideoSDKAudioHelper.h"
#import "ZoomVideoSDKShareHelper.h"
#import "ZoomVideoSDKRecordingHelper.h"
#import "ZoomVideoSDKLiveStreamHelper.h"
#import "ZoomVideoSDKUserHelper.h"
#import "ZoomVideoSDKLiveTranscriptionHelper.h"

@class ZoomVideoSDKRawDataPipe;
@class ZoomVideoSDKVideoCanvas;
@class ZoomVideoSDKUser;
@class ZoomVideoSDKProxySettingHandler;
@class ZoomVideoSDKSSLCertificateInfo;

/*!
 @brief A listener class that groups together the callbacks related to a session.
 */
@protocol ZoomVideoSDKDelegate <NSObject>
@optional
/*!
 @brief Callback: Invoked when the current user joins the session.
 */
- (void)onSessionJoin;

/*!
 @brief Callback: Invoked when the current user leaves the session.
 */
- (void)onSessionLeave;

/*!
 @brief Callback: Invoked when errors occur.
 @param ErrorType Provides error code associated with the error. See [ZoomVideoSDKError] for more information.
 @param details The detail of error message.
 */
- (void)onError:(ZoomVideoSDKError)ErrorType detail:(NSInteger)details;

/*!
 @brief Callback: Invoked when a user joins the session.
 @param helper User help utility.
 @param userArray List of users who have just joined the session.
 */
- (void)onUserJoin:(ZoomVideoSDKUserHelper * _Nullable)helper users:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/*!
 @brief Callback: Invoked when a user leaves the session.
 @param helper User helper utility.
 @param userArray List of users who have just left the session.
 */
- (void)onUserLeave:(ZoomVideoSDKUserHelper * _Nullable)helper users:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/*!
 @brief Invoked when a user makes changes to their video, such as starting or stopping their video.
 @param helper Video helper utility.
 @param userArray List of users who have just left the session.
 */
- (void)onUserVideoStatusChanged:(ZoomVideoSDKVideoHelper * _Nullable)helper user:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/*!
 @brief Callback: Invoked when a user makes changes to their audio, such as muting or unmuting their audio.
 @param helper Audio helper utility.
 @param userArray List of users who have just left the session.
 */
- (void)onUserAudioStatusChanged:(ZoomVideoSDKAudioHelper * _Nullable)helper user:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/*!
 @brief Callback: Invoked when a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing.
 @param helper Share helper utility.
 @param status Share status in enumeration. See [ZoomVideoSDKReceiveSharingStatus].
 */
- (void)onUserShareStatusChanged:(ZoomVideoSDKShareHelper * _Nullable)helper user:(ZoomVideoSDKUser * _Nullable)user status:(ZoomVideoSDKReceiveSharingStatus)status;

/*!
 @brief Callback: Invoked when a user makes changes to their live stream status.
 @param helper Live stream helper utility.
 @param status Live stream status in enumeration. See [ZoomVideoSDKLiveStreamStatus].
 */
- (void)onLiveStreamStatusChanged:(ZoomVideoSDKLiveStreamHelper * _Nullable)helper status:(ZoomVideoSDKLiveStreamStatus)status;

/*!
 @brief The chat privilege of participant has changed.
 @param helper Chat helper utility.
 @param currentPrivilege The new chat privilege. See [ZoomVideoSDKChatPrivilegeType].
*/
- (void)onChatPrivilegeChanged:(ZoomVideoSDKChatHelper * _Nullable)helper privilege:(ZoomVideoSDKChatPrivilegeType)currentPrivilege;

/*!
 @brief Callback: Invoked when receiving a chat message.
 @param helper Chat helper utility.
 @param chatMessage the object which contains the message content. See [ZoomVideoSDKChatMessage].
 */
- (void)onChatNewMessageNotify:(ZoomVideoSDKChatHelper * _Nullable)helper message:(ZoomVideoSDKChatMessage * _Nullable)chatMessage;

/*!
 @brief Callback: Invoked when a user deletes a chat message.
 @param helper Chat helper utility.
 @param msgID The deleted message's ID.
 @param type Indicates by whom the message was deleted, which is defined in [ZoomVideoSDKChatMsgDeleteBy].
 */
- (void)onChatMsgDeleteNotification:(ZoomVideoSDKChatHelper * _Nullable)helper messageID:(NSString * __nonnull)msgID deleteBy:(ZoomVideoSDKChatMsgDeleteBy) type;

/*!
 @brief Callback: Invoked when the session host changes.
 @param helper User helper utility.
 @param user The host userInfo.
 */
- (void)onUserHostChanged:(ZoomVideoSDKUserHelper * _Nullable)helper users:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Callback: Invoked when the manager of the session changes.
 @param user See [ZoomVideoSDKUser].
*/
- (void)onUserManagerChanged:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Callback: Invoked when a user changes their name.
 @param user See [ZoomVideoSDKUser].
*/
- (void)onUserNameChanged:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Callback: Invoked when the active audio changes.
 @param helper Audio helper utility.
 @param userArray Active audio list.
 */
- (void)onUserActiveAudioChanged:(ZoomVideoSDKUserHelper * _Nullable)helper users:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/*!
 @brief Callback: Invoked when the session requires a password to join.
 */
- (void)onSessionNeedPassword:(ZoomVideoSDKError (^ _Nullable)(NSString * _Nullable password, BOOL leaveSessionIgnorePassword))completion;

/*!
 @brief Callback: Invoked when the provided session password is wrong or invalid.
 */
- (void)onSessionPasswordWrong:(ZoomVideoSDKError (^ _Nullable)(NSString * _Nullable password, BOOL leaveSessionIgnorePassword))completion;

/*!
 @brief Callback: Invoked when mixed (all users) audio raw data received
 @param rawData Audio raw data. see [ZoomVideoSDKAudioRawData].
 */
- (void)onMixedAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

/*!
 @brief Callback: Invoked when individual user's audio raw data received
 @param rawData Raw audio data. see [ZoomVideoSDKAudioRawData].
 */
- (void)onOneWayAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData user:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Callback: Invoked when receiving shared raw audio data.
 @param rawData rawData Raw audio data. See [ZoomVideoSDKAudioRawData].
 */
- (void)onSharedAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

/*!
 @brief Callback: Invoked when the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed.
 @param status Invite by phone status. See [ZoomVideoSDKPhoneStatus].
 @param failReason Invite by phone failed reason. See [ZoomVideoSDKPhoneFailedReason].
 */
- (void)onInviteByPhoneStatus:(ZoomVideoSDKPhoneStatus)status failReason:(ZoomVideoSDKPhoneFailedReason)failReason;

/**
 @brief Callback: Invoked when the command channel is ready to be used.
 When the SDK attempts to establish a connection for the command channel when joining a session, this callback is triggered once the connection attempt for the command channel is completed.
 @param success  YES,command channel is ready to be used. NO, Failure, command channel was unable to connect.
 */
- (void)onCmdChannelConnectResult:(BOOL)success;

/**
 @brief Callback: Invoked when receiving a message, data, or a command from the command channel. Once the command channel is active, this callback is triggered each time a message is received.
 @param commandContent Received command.
 @param sendUser The user who sent the command.
 */
- (void)onCommandReceived:(NSString * _Nullable)commandContent sendUser:(ZoomVideoSDKUser * _Nullable)sendUser;

/**
 @brief Callback for when the current user is granted camera control access.
 @note Once the current user sends the camera control request, this callback will be triggered with the result of the request.
 @param user The pointer to the user who received the request.
 @param isApproved The result of the camera control request.
 */
- (void)onCameraControlRequestResult:(ZoomVideoSDKUser*)user approved:(BOOL)isApproved;

/**
 @brief Callback: Invoked when cloud recording status has started, paused, stopped, resumed, or otherwise changed.
 @param status  Cloud recording status defined in [ZoomVideoSDKRecordingStatus].
 @param handler  could handle the action user Accept or Decline;
 */
- (void)onCloudRecordingStatus:(ZoomVideoSDKRecordingStatus)status recordAgreementHandler:(ZoomVideoSDKRecordAgreementHandler * _Nullable)handler;

/**
 @brief Callback: user agreement status change.
 @param user  the user which agree the record.
 */
- (void)onUserRecordAgreementNotification:(ZoomVideoSDKUser * _Nullable)user;
/**
 @brief Callback: Invoked when a host requests you to unmute yourself.
 */
- (void)onHostAskUnmute;

/**
 @brief Callback: Invoked when someone in a given session enables or disables multi-camera. All participants in the session receive this callback.
 @param status  Status for multipul camera user join or left. See [ZoomVideoSDKMultiCameraStreamStatus].
 @param user The user who enabled multi-camera. See [ZoomVideoSDKUser].
 @param videoPipe the data pipe for the multi-camera. See [ZoomVideoSDKRawDataPipe].
 */
- (void)onMultiCameraStreamStatusChanged:(ZoomVideoSDKMultiCameraStreamStatus)status parentUser:(ZoomVideoSDKUser *_Nullable)user videoPipe:(ZoomVideoSDKRawDataPipe *_Nullable)videoPipe;

/**
 @brief Callback: Invoked when someone enables/disables multi-camera. This callback is received by all participants
 @param status  Status for multipul camera user join or left. See [ZoomVideoSDKMultiCameraStreamStatus].
 @param user The user who enabled multi-camera. See [ZoomVideoSDKUser].
 @param videoCanvas the video canvas for the multi-camera. See [ZoomVideoSDKVideoCanvas].
 */
- (void)onMultiCameraStreamStatusChanged:(ZoomVideoSDKMultiCameraStreamStatus)status parentUser:(ZoomVideoSDKUser *_Nullable)user videoCanvas:(ZoomVideoSDKVideoCanvas *_Nullable)videoCanvas;

/**
 @brief Callback: Notify the mic status when testing.
 @param status The mic status. For more details, See [ZoomVideoSDKTestMicStatus].
 */
- (void)onTestMicStatusChanged:(ZoomVideoSDKTestMicStatus)status;

/**
 @brief Callback: Notify the current mic or speaker volume when testing.
 @param micVolume Specify the volume of the mic.
 @param speakerVolume Specify the volume of the speaker.
 */
- (void)onMicSpeakerVolumeChanged:(int)micVolume speakerVolume:(int)speakerVolume;

/**
 @brief Callback: Invoked when the SDK requires system permissions to continue functioning.
 @param permissionType The type of system permission that is required. See [ZoomVideoSDKSystemPermissionType].
 */
- (void)onSystemPermissionRequired:(ZoomVideoSDKSystemPermissionType)permissionType;

/**
 @brief Callback: Invoked when live transcription status changes.
 @param status The live transcription status. See [ZoomVideoSDKLiveTranscriptionStatus].
 */
- (void)onLiveTranscriptionStatus:(ZoomVideoSDKLiveTranscriptionStatus)status;

/**
 @brief Callback: when a live transcription message is received.
 @param messageInfo The live transcription message 
 */
- (void)onLiveTranscriptionMsgReceived:(ZoomVideoSDKLiveTranscriptionMessageInfo *_Nullable)messageInfo;

/**
 @brief Callback: Original language message received callback.
 @param messageInfo messageInfo The spoken language message, refer to {@link ZoomVideoSDKLiveTranscriptionMessageInfo}.
 */
- (void)onOriginalLanguageMsgReceived:(ZoomVideoSDKLiveTranscriptionMessageInfo *_Nullable)messageInfo;

/**
 @brief Callback: Invoked when a live translation error occurs.
 @param spokenLanguage The spoken message language.
 @param transcriptLanguage The message language you want to translate.
 */
- (void)onLiveTranscriptionMsgError:(ZoomVideoSDKLiveTranscriptionLanguage *_Nullable)spokenLanguage transLanguage:(ZoomVideoSDKLiveTranscriptionLanguage *_Nullable)transcriptLanguage;

/**
 @brief The callback will be triggered if the proxy requests to input the username and password.Use the handler to configure the related information. For more details, see {@link ZoomVideoSDKProxySettingHandler}.
 @param handler The handler will be destroyed once the function calls end.
 */
- (void)onProxySettingNotification:(ZoomVideoSDKProxySettingHandler *_Nonnull)handler;

/**
 @brief The callback will be triggered when the SSL is verified.Use the handler to check the related information. For more details, see {@link ZoomVideoSDKSSLCertVerificationHandler}.
 @param handler The handler will be destroyed once the function calls end.
 */
- (void)onSSLCertVerifiedFailNotification:(ZoomVideoSDKSSLCertificateInfo *_Nonnull)handler;


/**
 @brief Callback event of the user's video network quality changes.
 @param status status video network quality. For more details, See {@link ZoomVideoSDKNetworkStatus}.
 @param user The pointer to the user who speaks the message. For more details, refer to {@link ZoomVideoSDKUser}.
 */
- (void)onUserVideoNetworkStatusChanged:(ZoomVideoSDKNetworkStatus)status user:(ZoomVideoSDKUser *_Nullable)user;

/*!
 @brief Callback event of the call CRC device's status.
 @param state The call out status.
 */
- (void)onCallCRCDeviceStatusChanged:(ZoomVideoSDKCRCCallStatus)state;

/*!
 @brief Callback for the annotation helper clean up. After this callback, SDK will release the ZoomVideoSDKAnnotationHelper as well.
 @param helper The helper clean up object.
 */
- (void)onAnnotationHelperCleanUp:(ZoomVideoSDKAnnotationHelper *_Nullable)helper;

/*!
 @brief Callback for the annotation privilege change.
 @param enable YES means the user is able to annotate, NO means the user is not able to annotate.
 @param user The user who changed viewer's annotation privilege
 */
- (void)onAnnotationPrivilegeChange:(BOOL)enable shareOwner:(ZoomVideoSDKUser *_Nullable)user;

/**
 @brief Callback event for the subscribed user's video fail reason.
 @param failReason The fail reason. For more details, see {@link ZoomVideoSDKSubscribeFailReason}.
 @param user The pointer to the user whose view we would like to subscribe. For more details, refer to {@link ZoomVideoSDKUser}.
 @param view The view that failed to subscribe.
 */
- (void)onVideoCanvasSubscribeFail:(ZoomVideoSDKSubscribeFailReason)failReason user:(ZoomVideoSDKUser *_Nullable)user view:(UIView *_Nullable)view;

/**
 @brief Callback event for the subscribed user's share fail reason.
 @param failReason The fail reason. For more details, see {@link ZoomVideoSDKSubscribeFailReason}.
 @param user The pointer to the user whose view we would like to subscribe. For more details, refer to {@link ZoomVideoSDKUser}.
 @param view The view that failed to subscribe.
 */
- (void)onShareCanvasSubscribeFail:(ZoomVideoSDKSubscribeFailReason)failReason user:(ZoomVideoSDKUser *_Nullable)user view:(UIView *_Nullable)view;

@end

#pragma mark - ZoomVideoSDKVirtualAudioSpeaker
/*!
 @brief An interface that handles the virtual audio speaker.
 */
@protocol ZoomVideoSDKVirtualAudioSpeaker <NSObject>

@optional

/*!
 @brief Callback event for receiving the mixed audio raw data from the virtual speaker.
 @param rawData Audio's raw data.
 */
- (void)onVirtualSpeakerMixedAudioReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

/*!
 @brief Callback event for receiving the one way audio raw data of a selected user from the virtual speaker.
 @param rawData Audio's raw data.
 */
- (void)onVirtualSpeakerOneWayAudioReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData user:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Callback event for receiving the share audio raw data such as buffer, sampleRate, etc.
 @param rawData Audio's raw data.
 */
- (void)onVirtualSpeakerSharedAudioReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

@end

#pragma mark - ZoomVideoSDKRawDataPipeDelegate
/*!
 @brief Methods to manage events for receiving video raw data.
 */
@protocol ZoomVideoSDKRawDataPipeDelegate <NSObject>

@optional

/*!
 @brief This method is used to receive video's NV12 data(CVPixelBufferRef).
 @param pixelBuffer Video's CVPixelBufferRef data.
 */
- (void)onPixelBuffer:(CVPixelBufferRef _Nullable )pixelBuffer
             rotation:(ZoomVideoSDKVideoRawDataRotation)rotation;

/*!
 @brief This method is used to receive video's YUV420 data.
 @param rawData Video's YUV420 data.
 */
- (void)onRawDataFrameReceived:(ZoomVideoSDKVideoRawData * _Nullable)rawData;

/*!
 @brief Callback event when the sender stop/start to sending raw data.
 @param userRawdataStatus Raw data is sending or not.
 */
- (void)onRawDataStatusChanged:(ZoomVideoSDKUserRawdataStatus)userRawdataStatus;

@end

#pragma mark - ZoomVideoSDKVideoSourcePreProcessor
/*!
 @brief Methods to modify default device capture raw data. @See ZoomVideoSDKSessionContext#preProcessor.
 */
@protocol ZoomVideoSDKVideoSourcePreProcessor <NSObject>

@optional
/*!
 @brief Callback on device capture video frame.
 @param rawData See ZoomVideoSDKPreProcessRawData
 */
- (void)onPreProcessRawData:(ZoomVideoSDKPreProcessRawData * _Nullable)rawData;

@end

#pragma mark - ZoomVideoSDKVideoSource
/*!
 @brief Custom external video source interface.
 */
@protocol ZoomVideoSDKVideoSource <NSObject>

@optional

/*!
 @brief Callback for video source prepare.
 @param rawDataSender See ZoomVideoSDKVideoSender
 @param supportCapabilityArray See ZoomVideoSDKVideoCapability
 @param suggestCapability See ZoomVideoSDKVideoCapability
 */
- (void)onInitialize:(ZoomVideoSDKVideoSender *_Nonnull)rawDataSender
supportCapabilityArray:(NSArray *_Nonnull)supportCapabilityArray
   suggestCapability:(ZoomVideoSDKVideoCapability *_Nonnull)suggestCapability;

/*!
 @brief Callback for video size or fps changed.
 @param supportCapabilityArray See ZoomVideoSDKVideoCapability
 @param suggestCapability See ZoomVideoSDKVideoCapability
 */
- (void)onPropertyChange:(NSArray *_Nonnull)supportCapabilityArray
       suggestCapability:(ZoomVideoSDKVideoCapability *_Nonnull)suggestCapability;

/*!
 @brief Callback for video source should start send raw data.
 */
- (void)onStartSend;

/*!
 @brief Callback for video source should stop send raw data. eg.user mute video
 */
- (void)onStopSend;

/*!
 @brief Callback for video source uninitialized. eg.leave session.
 */
- (void)onUninitialized;

@end

/*!
 @brief An interface that handles a virtual audio microphone.
 */
@protocol ZoomVideoSDKVirtualAudioMic <NSObject>

@optional
/*!
 @brief Callback for virtual audio microphone initialization.
 @param rawDataSender you can send audio data based on this object, See ZoomVideoSDKAudioSender
 */
- (void)onMicInitialize:(ZoomVideoSDKAudioSender *_Nonnull)rawDataSender;

/*!
 @brief Callback for microphone to start sending raw data. For example, this could be sent if the user unmuted audio.
 */
- (void)onMicStartSend;

/*!
 @brief Callback for microphone to stop sending raw data. For example, this could be sent if the user muted audio.
 */
- (void)onMicStopSend;

/*!
 @brief Callback sent when the microphone is uninitialized. For example, if the user left the session.
 */
- (void)onMicUninitialized;

@end

#pragma mark - ZoomVideoSDKShareSource
/*!
 @brief Custom external share source interface.
 */
@protocol ZoomVideoSDKShareSource <NSObject>

@optional
/*!
 @brief Callback for share source can start send raw data.
 @param rawDataSender See [ZoomVideoSDKShareSender].
 */
- (void)onShareSendStarted:(ZoomVideoSDKShareSender *_Nullable)rawDataSender;

/*!
 @brief Callback for share source stop send raw data.
 */
- (void)onShareSendStopped;

@end

#pragma mark - ZoomVideoSDKShareAudioSource
/*!
 @brief Custom external share source interface.
 */
@protocol ZoomVideoSDKShareAudioSource <NSObject>

@optional
/*!
 @brief Callback for audio source to start sending raw data.
 @param sender The object of MobileRTCShareSender to send share source.
 */
- (void)onStartSendAudio:(ZoomVideoSDKShareAudioSender *_Nonnull)sender;

/*!
 @brief Callback for audio source to stop sending raw data.
 */
- (void)onStopSendAudio;

@end
