//
//  ZoomVideoSDKVideoCanvas.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/7.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 @class ZoomVideoSDKVideoCanvas
 @brief The video canvas is the display area of the video streams on the user’s local device. To instantiate a local video canvas instance and show the video stream of a user, simply initialize the ZoomVideoSDKVideoCanvas object, subscribe the userId of a specific user, and add it to your UIView.
 */
@interface ZoomVideoSDKVideoCanvas : NSObject

/*!
 @brief This canvas type.
 */
- (ZoomVideoSDKVideoType)canvasType;

/*!
 @brief The user video status.
 @warning This interface be marked as deprecated, then it will be instead by ZoomVideoSDKRawDataPipe.videoStatus() and ZoomVideoSDKVideoCanvas.videoStatus()
 */
- (ZoomVideoSDKVideoStatus *_Nullable)videoStatus;

/*!
 @brief The user share status.
 @warning This interface be marked as deprecated, then it will be instead by ZoomVideoSDKRawDataPipe.shareStatus() and ZoomVideoSDKVideoCanvas.shareStatus()
 */
- (ZoomVideoSDKShareStatus *_Nullable)shareStatus;

/*!
 @brief Subscribe to the user's video or share view.
 @param view the object of UIView, that's you need render data.
 @param aspect the render's aspect.
 @param resolution Specify a render's resolution, valid only for video canvas.
 @return The result of this method.
 */
- (ZoomVideoSDKError)subscribeWithView:(UIView * _Nullable)view
                            aspectMode:(ZoomVideoSDKVideoAspect)aspect
                         andResolution:(ZoomVideoSDKVideoResolution)resolution;

/*!
 @brief Subscribe to the user's video or share view in Picture-in-Picture mode for video calls.
 @param view the object of UIView, that's you need render data.
 @param aspect the render's aspect.
 @param resolution Specify a render's resolution, valid only for video canvas.
 @note To know more about PiP mode for video calls, please visit https://developer.apple.com/documentation/avkit/adopting_picture_in_picture_for_video_calls .
 @return The result of this method.
 */
- (ZoomVideoSDKError)subscribeWithPiPView:(UIView * _Nullable)view
                               aspectMode:(ZoomVideoSDKVideoAspect)aspect
                            andResolution:(ZoomVideoSDKVideoResolution)resolution;

/*!
 @brief Call the function to unsubscribe video or share data.
 @return The result of the method.
 */
- (ZoomVideoSDKError)unSubscribeWithView:(UIView * _Nullable)view;

/**
 @brief Set the video aspect mode.
 @param aspect The aspect mode of video.
 @param view The UIView object to render video.
 @return The result of the method.
 */
- (ZoomVideoSDKError)setAspectMode:(ZoomVideoSDKVideoAspect)aspect toView:(UIView * _Nullable)view;

/**
 @brief Set the video resolution.
 @param resolution The  video resolution. Valid only for video canvas
 @param view The UIView object to render video.
 @return If the function succeeds, it will return Error_Success.
 */
- (ZoomVideoSDKError)setResolution:(ZoomVideoSDKVideoResolution)resolution toView:(UIView * _Nullable)view;

@end
