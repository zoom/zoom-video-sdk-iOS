//
//  ZoomVideoSDKRenderer.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2019/2/1.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKDelegate.h>

/*!
 @class ZoomVideoSDKRawDataPipe
 @brief A Class to manage the subscription and unsubscription of video or share raw data.
 */
@interface ZoomVideoSDKRawDataPipe : NSObject

/*!
 @brief Get the raw data data type.
 @return Share or Video data type. Refer to ZoomVideoSDKRawDataType for the list of enum [link ZoomVideoSDKRawDataType].
 */
- (ZoomVideoSDKVideoType)rawdataPipeType;
/*!
 @brief The user's video status.
 @warning video status. For more information, see [ZoomVideoSDKVideoStatus].
 */
- (ZoomVideoSDKVideoStatus *_Nullable)videoStatus;

/*!
 @brief The user's share status.
 @return share status. For more information, see  [ZoomVideoSDKShareStatus].
 */
- (ZoomVideoSDKShareStatus *_Nullable)shareStatus;

/*!
 @brief Call the function to subscribe video or share raw data. You can subscribe your 'preview video' data with userid=0 before entering the session, you can call it  just after you called "joinSession:". Otherwise, you can subscribe video or share raw data using the real userid in callback "onUserJoin:".
 @param delegate the object receive the "ZoomVideoSDKRawDataPipeDelegate" event.
 @param resolution the resolution you want to subscribe. Valid only for video data.
 @return The result of the method.
 @warning The param resolution can't using "ZoomVideoSDKVideoResolution_Auto" in this function. must be sperify the resolution you want.
 */
- (ZoomVideoSDKError)subscribeWithDelegate:(id<ZoomVideoSDKRawDataPipeDelegate> _Nullable)delegate
                                resolution:(ZoomVideoSDKVideoResolution)resolution;

/*!
 @brief Call the function to unsubscribe video or share raw data.
 @param delegate the object receive the "ZoomVideoSDKRawDataPipeDelegate" event.  Which pass in "subscribeWithDelegate:resolution:"
 @return The result of the method.
 */
- (ZoomVideoSDKError)unSubscribeWithDelegate:(id<ZoomVideoSDKRawDataPipeDelegate> _Nullable)delegate;

@end

