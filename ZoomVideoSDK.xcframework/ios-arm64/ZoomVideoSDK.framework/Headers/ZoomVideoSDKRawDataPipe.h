//
//  ZoomVideoSDKRenderer.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2019/2/1.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZoomVideoSDKDelegate.h"

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
 @return The result of the method.
 */
- (ZoomVideoSDKError)subscribeWithDelegate:(id<ZoomVideoSDKRawDataPipeDelegate>)delegate
                                  resolution:(ZoomVideoSDKVideoResolution)resolution;

/*!
 @brief Call the function to unsubscribe video or share raw data.
 @return The result of the method.
 */
- (ZoomVideoSDKError)unSubscribeWithDelegate:(id<ZoomVideoSDKRawDataPipeDelegate>)delegate;

@end

