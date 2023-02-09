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
 @brief Call the function to subscribe video or share data. You can subscribe your 'preview video' data with userid=0 before entering the session, you can just call it  after you called "joinSession:". Otherwise, you can subscribe video or share data using the real userid in callback "onUserJoin:".
 @param view the object of UIView, that's you need render video.
 @param aspect the video‘s aspect.
 @return The result of this method.
 */
- (ZoomVideoSDKError)subscribeWithView:(UIView * _Nullable)view andAspectMode:(ZoomVideoSDKVideoAspect)aspect;

/*!
 @brief Call the function to unsubscribe video or share data.
 @return The result of the method.
 */
- (ZoomVideoSDKError)unSubscribeWithView:(UIView * _Nullable)view;

@end
