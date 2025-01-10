//
//  ZoomVideoSDKLiveStreamHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/26.
//  Copyright © Zoom Video Communications, Inc. All rights reserved.
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

@interface ZoomVideoSDKIncomingLiveStreamStatus : NSObject
/*!
 @brief The incoming live stream ID.
 */
@property(nonatomic, copy) NSString* _Nullable streamKeyID;
/**
 @brief Is the streaming software(such as OBS) connected to the Zoom platform?
 */
@property(nonatomic, assign) BOOL isRTMPConnected;
/**
 @brief Has the video stream been pushed to the session?
 */
@property(nonatomic, assign) BOOL isStreamPushed;

@end

@interface ZoomVideoSDKIncomingLiveStreamHelper : NSObject
/*!
 @brief Bind incoming live stream with a stream key ID.
 @param streamKeyID The stream key ID to bind.
 @return If the function succeeds, it will return Errors_Success.
 @warning Only host can bind incoming live stream.
 */
- (ZoomVideoSDKError)bindIncomingLiveStream:(NSString *_Nullable)streamKeyID;

/*!
 @brief Unbind the binded incoming live stream.
 @param streamKeyID The stream key ID to bind.
 @return If the function succeeds, it will return Errors_Success.
 @warning Only host can unbind incoming live stream.
 */
- (ZoomVideoSDKError)unbindIncomingLiveStream:(NSString *_Nullable)streamKeyID;

/*!
 @brief Get the status of binded streams.
 @note Will receive callback "-onIncomingLiveStreamStatusResponse:"
 @return If the function succeeds, it will return Errors_Success.
 @warning Only host can get incoming live stream status.
 */
- (ZoomVideoSDKError)getIncomingLiveStreamStatus;

/**
 @brief Start the binded stream as a special participant.
 @param streamKeyID The stream key ID to bind.
 @return If the function succeeds, it will return Errors_Success.
 @warning Only host can start incoming live stream.
 */
- (ZoomVideoSDKError)startIncomingLiveStream:(NSString *_Nullable)streamKeyID;

/*!
 @brief Stop the binded stream as a special participant.
 @param streamKeyID The stream key ID to bind.
 @return If the function succeeds, it will return Errors_Success.
 @warning Only host can stop incoming live stream.
 */
- (ZoomVideoSDKError)stopIncomingLiveStream:(NSString *_Nullable)streamKeyID;

@end

