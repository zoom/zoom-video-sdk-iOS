//
//  ZoomVideoSDKShareHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/13.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol ZoomVideoSDKShareSource;
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
 @param pSource External share source,To get extended error information, see {@link ZMVideoSDKShareSource}.
 @return If the function succeeds, it will return Errors_Success.Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)startSharingExternalSource:(id<ZoomVideoSDKShareSource>)pSource;

/*!
 @brief Stop view or screen share.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)stopShare;

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
 @brief Check other is audio or not share when screen sharing.
 @return The result of it.
 */
- (BOOL)isShareDeviceAudioEnabled;

/*!
 @brief Enble share audio when screen sharing.
 @param enable share audio or not.
 @return The result of it.
 */
- (BOOL)enableShareDeviceAudio:(BOOL)enable;

@end
