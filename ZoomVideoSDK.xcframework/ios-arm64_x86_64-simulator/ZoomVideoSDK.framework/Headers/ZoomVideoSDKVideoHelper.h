//
//  ZoomVideoSDKVideoHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/6.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>

@protocol ZoomVideoSDKRawDataPipeDelegate;

/*!
 @class ZoomVideoSDKVideoStatus
 @brief Video status of user
 */
@interface ZoomVideoSDKVideoStatus : NSObject
/*!
 @brief if the camera is turned on. YES : camera turned on, NO : camera turned off
 */
@property (nonatomic, assign) BOOL          on;

@end


/**
 @brief Video preference interface.When setting custom modes, the maximum and minimum frame rates are provided by the developer. If the current bandwidth cannot maintain the minimum frame rate, the video system will drop to the next lower frame rate. The default maximum and minimum frame rates for other modes are 0.
 */

@interface ZoomVideoSDKVideoPreferenceSetting : NSObject
/**
 @brief Preferred video mode.
 */
@property (nonatomic, assign) ZoomVideoSDKVideoPreferenceMode mode;

/**
 @brief Minimum frame rate, default is 0.
 @note The value of minimumFrameRate range from 0 to 30. Otherwise, will use default frame-rate of Zoom.
 */
@property (nonatomic, assign) NSUInteger minimumFrameRate;

/**
 @brief Maximum frame rate, default is 0.
 @note The value of maximumFrameRate range from 0 to 30. Otherwise, will use default frame-rate of Zoom.
 */
@property (nonatomic, assign) NSUInteger maximumFrameRate;

@end


/*!
 @class ZoomVideoSDKVideoHelper
 @brief An interface to control video and manage cameras during a video session.
 */
@interface ZoomVideoSDKVideoHelper : NSObject

/*!
 @brief Subscribe video raw data with a delegate.
 @param delegate The delegate  which receives rawdata of preview video.
 @return ZoomVideoSDKError error code.
 */
- (ZoomVideoSDKError)startVideoPreview:(id<ZoomVideoSDKRawDataPipeDelegate>_Nullable)delegate;

/*!
 @brief UnSubscribe preview video raw data with the subscribed delegate.
 @param delegate The delegate  which receives rawdata of preview video.
 @return ZoomVideoSDKError error code.
 */
- (ZoomVideoSDKError)stopVideoPreview:(id<ZoomVideoSDKRawDataPipeDelegate> _Nullable)delegate;

/*!
 @brief Subscribe preview with a canvas view.
 @param view The view which draws the preview video.
 @param aspect The acpect mode of the preview.
 @return ZoomVideoSDKError error code.
 */
- (ZoomVideoSDKError)startVideoCanvasPreview:(UIView * _Nullable)view andAspectMode:(ZoomVideoSDKVideoAspect)aspect;

/*!
 @brief UnSubscribe preview with a canvas view.
 @param view The view which draws rawdata of preview video.
 @return ZoomVideoSDKError error code.
 */
- (ZoomVideoSDKError)stopVideoCanvasPreview:(UIView * _Nullable)view;

/*!
 @brief Call this method to start sending local video data from the camera.
 @return the result of it.
 */
- (ZoomVideoSDKError)startVideo;

/*!
 @brief Call this method to stop sending local video data from the camera.
 @return the result of it.
 */
- (ZoomVideoSDKError)stopVideo;

/*!
 @brief Call this method to rotate the video when the device is rotated.
 @param rotation The orientation you want to rotate.
 @return Returns YES if the rotation was successful, NO otherwise.
 @warning the function only for internal video source, it's not work for capture video source.
 */
- (BOOL)rotateMyVideo:(UIDeviceOrientation)rotation;

/*!
 @brief Mirrors the current user's video.
 @param enable YES to enable mirror my video, NO to reset the mirror effect back.
 @return the result of it.
 @warning Valid only for canvas.
 */
- (ZoomVideoSDKError)mirrorMyVideo:(BOOL)enable;

/*!
 @brief Determine whether mirror my video is enabled.
 @return Returns YES if mirror  my video is enabled, otherwise NO.
 @warning this function only for canvas.
 */
- (BOOL)isMyVideoMirrored;

/*!
 @brief Switch to the next available camera.
 */
- (void)switchCamera;

/**
 @brief Adjust user's video resolution and frame-rate.
 @param preferenceSetting An instance of ZoomVideoSDKVideoPreferenceSetting.
 @return If the function succeeds, it will return Errors_Success.
 */
- (ZoomVideoSDKError)setVideoQualityPreference:(ZoomVideoSDKVideoPreferenceSetting * _Nullable)preferenceSetting;

#pragma mark - OriginalAspec -
/**
 @brief Determine whether current aspect ratio is the original aspect ratio of video.
 @return YES if is original aspect ratio, otherwise NO.
 */
- (BOOL)isOriginalAspectRatioEnabled;

/**
 @brief This function is used to set the aspect ratio of the video sent out.
 @param enabled false means the aspect ratio is 16:9, true means that using the original aspect ratio of video
 @return YES if is original aspect ratio, otherwise NO.
 @warning If session is using video source and data_mode is not VideoSourceDataMode_None, default always use original aspect ration of video.
 */
- (BOOL)enableOriginalAspectRatio:(BOOL)enabled;

#pragma mark - alpha channel -
/**
 @brief Determine if alpha channel mode can be enabled.
 @return YES means it can be enabled. Otherwise NO.
 @warning Only host can enable the alpha mode. Your account must have this feature turned on by Support.
 */
- (BOOL)canEnableAlphaChannelMode;

/**
 @brief Enable or disable video alpha channel mode.
 @param enable YES indicates to enable alpha channel mode. Otherwise, disable it.
 @return If the function succeeds, the return value is Errors_Success.
 Otherwise it failed. To get extended error information, see {@link ZoomVideoSDKError}.
 */
- (ZoomVideoSDKError)enableAlphaChannelMode:(BOOL)enable;

/**
 @brief Determine if alpha channel mode is enabled.
 @return YES indicates alpha channel mode is enabled. Otherwise NO.
 */
- (BOOL)isAlphaChannelModeEnabled;

/**
 @brief Determines whether the device hardware capabilities are capable of supporting video alpha mode.
 @return YES indicates that current device supports it,
 Otherwise, it indicates that the device performance is weak and does not support it.
 @warning Device should be iPhone 8/ 8 plus X or above or be iPad Pro 9.7 above, OS should be iOS 11 or above.
 And should be embed zoomcml.xcframework.
 */
- (BOOL)isDeviceSupportAlphaChannelMode;

#pragma mark - spotlight -
/**
 @brief Call this method to spotlight user's video.
 @param user The user which you want to spotlight
 @return If the function succeeds, the return value is Errors_Success,
 Otherwise failed. To get extended error information, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)spotLightVideo:(ZoomVideoSDKUser * _Nullable)user;

/**
 @brief Call this method to unSpotlight user's video.
 @param user The user which you want to unSpotlight
 @return If the function succeeds, the return value is Errors_Success,
 Otherwise failed. To get extended error information, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)unSpotLightVideo:(ZoomVideoSDKUser * _Nullable)user;

/**
 @brief Call this method to set all user's video unSpotlight.
 @return If the function succeeds, the return value is Errors_Success,
 Otherwise failed. To get extended error information, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)unSpotlightAllVideos;

/**
 @brief Call this method to get spotlighted video user list.
 @return If the function succeeds, the return value is Errors_Success,
 Otherwise failed. To get extended error information, see [ZoomVideoSDKError] enum.
 */
- (NSArray <ZoomVideoSDKUser *>* _Nullable)getSpotlightedVideoUserList;

@end
