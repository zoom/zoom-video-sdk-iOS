//
//  ZoomVideoSDKShareHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/13.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKAnnotationHelper.h>

@protocol ZoomVideoSDKShareSource;
@protocol ZoomVideoSDKShareAudioSource;
/*!
 @class ZoomVideoSDKShareStatus
 @brief Share status of user
 */
@interface ZoomVideoSDKShareStatus : NSObject
/*!
 @brief The user's share status.
 */
@property (nonatomic, assign) ZoomVideoSDKReceiveSharingStatus  sharingStatus;

@end

/*!
 @class ZoomVideoSDKShareHelper
 @brief Share control interface.
 */
@interface ZoomVideoSDKShareHelper : NSObject

/*!
 @brief Share a selected view.
 @param view The view to be shared.
 @warning view, recommend to pass a single UIView's object, such as UIView, UIImageView or WKWebView.
 @warning It is not recommended to pass UIView after add subview WKWebView or UIImageView.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)startShareWithView:(UIView * _Nullable)view;

/*!
 @brief Share an external source.
 @param shareDelegate External share source,To get extended information, see {@link ZoomVideoSDKShareSource}.
 @param audioDelegate External share audio source,To get extended information, see {@link ZoomVideoSDKShareAudioSource}.
 @return If the function succeeds, it will return Errors_Success.Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 @warning   If audioDelegate is non-null, it means share user-defined audio at the same time.
 */
- (ZoomVideoSDKError)startSharingExternalSource:(id<ZoomVideoSDKShareSource> _Nullable)shareDelegate andAudioSource:(id <ZoomVideoSDKShareAudioSource> _Nullable)audioDelegate DEPRECATED_MSG_ATTRIBUTE("use startSharingExternalSource:andAudioSource:isPlaying: instead");;

/*!
 @brief Share an external source.
 @param shareDelegate External share source,To get extended information, see {@link ZoomVideoSDKShareSource}.
 @param audioDelegate External share audio source,To get extended information, see {@link ZoomVideoSDKShareAudioSource}.
 @param isPlaying YES to play shared audio raw data, false not to play.
 @return If the function succeeds, it will return Errors_Success.Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 @warning   If audioDelegate is non-null, it means share user-defined audio at the same time.
 */
- (ZoomVideoSDKError)startSharingExternalSource:(id<ZoomVideoSDKShareSource> _Nullable)shareDelegate andAudioSource:(id <ZoomVideoSDKShareAudioSource> _Nullable)audioDelegate isPlaying:(BOOL)isPlaying;

/**
 @brief Enable or disable local playback of shared audio raw data.
 @param bPlay YES to play shared audio raw data, NO not to play it.
 @return If the function succeeds, it will return Errors_Success. Otherwise failed. To get extended error information, see {@link ZoomVideoSDKError}.
 */
- (ZoomVideoSDKError)enablePlaySharingAudioRawdata:(BOOL)bPlay;

/*!
 @brief Stop view or screen share.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)stopShare;

/**
 @brief Pause share.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see {@link ZoomVideoSDKError}.
 */
- (ZoomVideoSDKError)pauseShare;

/**
 @brief Resume share.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see {@link ZoomVideoSDKError}.
 */
- (ZoomVideoSDKError)resumeShare;

/*!
 @brief Lock sharing the view or screen. Only the host can call this method.
 @param lock YES to lock sharing.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 @warning Only Host/Manger can call the function.
 */
- (ZoomVideoSDKError)lockShare:(BOOL)lock;

/*!
 @brief Determine whether sharing the view or screen is locked.
 @return YES indicates that sharing is locked, otherwise NO.
 */
- (BOOL)isShareLocked;

/*!
 @brief Determine whether the current user is sharing.
 @return YES indicates the current user is sharing, otherwise NO.
 */
- (BOOL)isSharingOut;

/*!
 @brief Determine whether other user is sharing.
 @return YES indicates another user is sharing, otherwise NO.
 */
- (BOOL)isOtherSharing;

/*!
 @brief Determine whether the current user is sharing the screen.
 @return YES indicates the current user is sharing the screen, otherwise NO.
 */
- (BOOL)isScreenSharingOut;

/*!
 @brief Determine if the SDK has enabled share device audio when screen sharing.
 @return The result of it.
 */
- (BOOL)isShareDeviceAudioEnabled;

/*!
 @brief Enable or disable the device audio  shared together when screen sharing.
 @param enable share audio out or not.
 @return The result of it.
 */
- (BOOL)enableShareDeviceAudio:(BOOL)enable;

/*!
 @brief Whether annotation feature is supported or not.
 @return The result of it.
 */
- (BOOL)isAnnotationFeatureSupport;

/*!
 @brief Disable or enable viewer’s annotation by the share owner.
 @param disable YES means annotation is disabled, NO means it is enabled.
 @return the result of this.
 @warning Only the share owner can call this function.
 */
- (ZoomVideoSDKError)disableViewerAnnotation:(BOOL)disable;

/*!
 @brief Whether annotation on current sharing is disabled or not.
 @return the result of this.
 @warning Only the share owner can call this function.
 */
- (BOOL)isViewerAnnotationDisabled;

/*!
 @brief Creates annotation helper based on shared view.
 @param view the shared view. Pass the nil will return the helper for self sharing.
 @return The result of it.
 @warning The view passed in this function should be subscribed share view. And if the share view aspect mode is full fill, the annotate not supported. When the share owner not  support the feature of annotate, the others should not do annotate in that case.
 */
- (ZoomVideoSDKAnnotationHelper * _Nullable)createAnnotationHelper:(UIView * _Nullable)view;

/*!
 @brief Destroys annotation helper.
 @param helper ZoomVideoSDKAnnotationHelper.
 @return The result of it.
 */
- (ZoomVideoSDKError)destroyAnnotationHelper:(ZoomVideoSDKAnnotationHelper * _Nullable)helper;

/*!
 @brief Enable or disable participants can share simultaneously.
 @param enable True to enable. False to disable.
 @return If the function succeeds, the return value is Errors_Success.
 @warning When you switch multi share from enable to disable, all sharing will be stopped
 */
- (ZoomVideoSDKError)enableMultiShare:(BOOL)enable;

/*!
 @brief Determine whether multi share is enabled or not..
 @return true enabled, false not enabled.
 */
- (BOOL)isMultiShareEnabled;
@end
