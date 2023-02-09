//
//  ZoomVideoSDKVideoSender.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2020/3/9.
//  Copyright © 2020 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @class ZoomVideoSDKVideoSender
 @brief A class for user to send video raw data.
*/
@interface ZoomVideoSDKVideoSender : NSObject
/*!
 @brief Interface for user to send video raw data.
 @param frameBuffer YUVI420 buffer.
 @param width frame width.
 @param height frame height.
 @param dataLength buffer length.
 @param rotation buffer rotation.
*/
- (void)sendVideoFrame:(char *)frameBuffer width:(NSUInteger)width height:(NSUInteger)height dataLength:(NSUInteger)dataLength rotation:(ZoomVideoSDKVideoRawDataRotation)rotation;

@end

