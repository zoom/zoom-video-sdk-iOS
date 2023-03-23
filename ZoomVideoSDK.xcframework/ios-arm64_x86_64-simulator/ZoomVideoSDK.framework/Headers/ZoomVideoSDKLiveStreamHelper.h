//
//  ZoomVideoSDKLiveStreamHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/26.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKLiveStreamHelper
 @brief A class to operate the live stream.
 */
@interface ZoomVideoSDKLiveStreamHelper : NSObject

/*!
 @brief Call the function to start live stream.
 @param streamingURL The live stream URL by which you can live the session.
 @param key Stream key offered by the third platform on which you want to live stream your session.
 @param broadcastURL The URL of live stream website.
 @return Success means that the method is called successfully, otherwise not.
 @warning Only session host can start live Stream successfully.
 */
- (ZoomVideoSDKError)startLiveStreamWithStreamingURL:(NSString * _Nullable)streamingURL StreamingKey:(NSString * _Nullable)key BroadcastURL:(NSString * _Nullable)broadcastURL;

/*!
 @brief Set to stop live streaming.
 @return YES means stopping live streaming successfully, otherwise not.
 @warning The function is available only for host.
 */
- (ZoomVideoSDKError)stopLiveStream;

/*!
 @brief Check to see if you can start live streaming.
 @return The result of it.
 */
- (ZoomVideoSDKError)canStartLiveStream;

@end

