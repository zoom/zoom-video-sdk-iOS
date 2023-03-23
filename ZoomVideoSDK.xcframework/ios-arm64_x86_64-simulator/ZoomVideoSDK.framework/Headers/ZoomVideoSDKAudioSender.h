//
//  ZoomVideoSDKAudioSender.h
//  ZoomVideoSDK
//
//  Created by Zoom on 2021/3/16.
//  Copyright © 2021 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*!
 @brief A class for user to send audio raw data.
*/
@interface ZoomVideoSDKAudioSender : NSObject

/*!
 @brief send audio raw data, channel number must be mono, and sampling bits must be 16.
 @param data the address of audio data.
 @param dataLength the length of audio data, it must be even numbers.
 @param sampleRate sampling rate of audio data.
 @warning Supported audio data properties: Sample Rate: 8000/11025/32000/44100/48000/50000/50400/96000/192000/2822400 Channels: mono resolution: little-endian, 16bit
*/
- (ZoomVideoSDKError)send:(char *)data dataLength:(NSUInteger)dataLength sampleRate:(NSUInteger)sampleRate;

@end

NS_ASSUME_NONNULL_END
