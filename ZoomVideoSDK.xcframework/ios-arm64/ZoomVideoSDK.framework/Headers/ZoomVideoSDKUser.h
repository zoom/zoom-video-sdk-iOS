//
//  ZoomVideoSDKUserInfo.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/7.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKRawDataPipe.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoCanvas.h>
#import <ZoomVideoSDK/ZoomVideoSDKRemoteCameraControlHelper.h>
/*!
 @class ZoomVideoSDKVideoStatisticInfo
 @brief Video statistic information.
*/
@interface ZoomVideoSDKVideoStatisticInfo : NSObject
/*!
 @brief frame width
 */
@property (nonatomic, assign) NSInteger     width;
/*!
 @brief frame height
 */
@property (nonatomic, assign) NSInteger     height;
/*!
 @brief frame per second
 */
@property (nonatomic, assign) NSInteger     fps;
/*!
 @brief bits per second
 */
@property (nonatomic, assign) NSInteger     bps;
/**
 @brief Get video network status.
 */
@property (nonatomic, assign) ZoomVideoSDKNetworkStatus videoNetworkStatus;
@end

/*!
 @class ZoomVideoSDKShareStatisticInfo
 @brief Share statistic information.
*/
@interface ZoomVideoSDKShareStatisticInfo : NSObject
/*!
 @brief frame width
 */
@property (nonatomic, assign) NSInteger     width;
/*!
 @brief frame height
 */
@property (nonatomic, assign) NSInteger     height;
/*!
 @brief frame per second
 */
@property (nonatomic, assign) NSInteger     fps;
/*!
 @brief bits per second
 */
@property (nonatomic, assign) NSInteger     bps;

@end

/*!
 @class ZoomVideoSDKAudioStatus
 @brief Audio status of user
 */
@interface ZoomVideoSDKAudioStatus : NSObject
/*!
 @brief Determine whether the audio is muted.
 */
@property (nonatomic, assign) BOOL          isMuted;
/*!
 @brief Determine whether the user is talking.
 */
@property (nonatomic, assign) BOOL          talking;
/*!
 @brief Get audio type: VOIP (Voice over IP), Telephony, or None.
 */
@property (nonatomic, assign) ZoomVideoSDKAudioType  audioType;

@end

/*!
 @class ZoomVideoSDKUser
 @brief Zoom Video SDK user information.
 */
@interface ZoomVideoSDKUser : NSObject
/*!
 @brief Get the user's id.
 */
- (NSInteger)getUserID;
/*!
 @brief Get the name of the user in the session.
 */
- (NSString *_Nullable)getUserName;
/*!
 @brief Get the user's custom identity.. Which pass in jwt token or in SDKSessionContext.customUserId
 */
- (NSString *_Nullable)getCustomUserId;
/*!
 @brief Get the user's reference.
 */
- (NSString *_Nullable)getUserReference;
/*!
 @brief Determine whether the user is the host.
 */
- (BOOL)isHost;
/*!
 @brief Determine whether the user is the manager.
 */
- (BOOL)isManager;
/*!
 @brief are user agreed with the individual record.
 */
- (BOOL)isIndividualRecordAgreed;
/**
 @brief check if user be spotlighted.
 */
- (BOOL)isVideoSpotLighted;
/*!
 @brief Get the user's audio status.
 */
- (ZoomVideoSDKAudioStatus *_Nullable)audioStatus;
/*!
 @brief Get the user's video statistic information.
 */
- (ZoomVideoSDKVideoStatisticInfo *_Nullable)getVideoStatisticInfo;
/*!
 @brief Get the user's share statistic information.
 */
- (ZoomVideoSDKShareStatisticInfo *_Nullable)getShareStatisticInfo;
/*!
 @brief Get the user's video pipe.
 */
- (ZoomVideoSDKRawDataPipe *_Nullable)getVideoPipe;
/*!
 @brief Get the user's multi-camera stream list.
 @return a list of all streaming cameras pipe. For more information, see [ZoomVideoSDKRawDataPipe].
 */
- (NSArray <ZoomVideoSDKRawDataPipe *> *_Nullable)getMultiCameraStreamList;
/*!
 @brief Get the user's share pipe.
 */
- (ZoomVideoSDKRawDataPipe *_Nullable)getSharePipe;
/*!
 @brief Get the user's video canvas.
 */
- (ZoomVideoSDKVideoCanvas *_Nullable)getVideoCanvas;
/*!
 @brief Get the user's multi-camera canvas list.
 @return a list of all video canvas. For more information, see [ZoomVideoSDKVideoCanvas].
 */
- (NSArray <ZoomVideoSDKVideoCanvas *> *_Nullable)getMultiCameraCanvasList;

/*!
 @brief Get the helper class instance to access the remote camera control.
 @return If the function succeeds, the return value is the remote camera control helper object. Otherwise returns null. For more details, see {@link ZoomVideoSDKRemoteCameraControlHelper}.
 */
- (ZoomVideoSDKRemoteCameraControlHelper *_Nullable)getRemoteCameraControlHelper;

/*!
 @brief The user's share canvas.
 */
- (ZoomVideoSDKVideoCanvas *_Nullable)getShareCanvas;

/*!
 @brief Set the user's local volume. This does not affect how other participants hear the user.
 @param volume value can be >= 0 and <=10. If volume is 0, the user won't be able to hear related audio
 @param isSharingAudio if true, sets the volume of shared audio, otherwise sets the volume of the microphone.
 @return if success return YES, otherwise NO.
 */
- (BOOL)setUserVolume:(float)volume isShareAudio:(BOOL)isSharingAudio;

/*!
 @brief Get user volume.
 @param volume Store the obtained value.
 @param isSharingAudio if true, gets the volume of shared audio, otherwise gets the volume of the microphone.
 @return if success return YES, otherwise NO.
 */
- (BOOL)getUserVolume:(float * _Nullable)volume isShareAudio:(BOOL)isSharingAudio;

/*!
 @brief Determine which audio you can set, shared audio or microphone
 @param isSharingAudio if true, checks whether you can set the volume of shared audio, otherwise you can set the volume of the microphone.
 @return if success return YES, otherwise NO.
 */
- (BOOL)canSetUserVolume:(BOOL)isSharingAudio;

/*!
 @brief Send file to current user
 @param filePath The local path of the file.
 @return If the function succeeds, the return value is Errors_Success.
 @warning this interface will related with chat  privilege see @{ZoomVideoSDKChatPrivilegeType}.
 */
- (ZoomVideoSDKError)transferFile:(NSString * _Nullable)filePath;

@end
