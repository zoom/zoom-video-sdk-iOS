//
//  ZoomVideoSDKShareAudioSender.h
//  ZoomVideoSDK
//
//  Created by Jackie Chen on 7/12/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ZoomVideoSDKShareAudioSender : NSObject


/*!
 @brief Sends audio raw data.
 @param data The audio data address..
 @param length The audio data length. It must be even numbers.
 @param rate The audio data sampling rate.
 @param channel The channel type.
 @return The result of sending data.
 @warning Supported audio data properties:
 Memo 8000/11025/16000/32000/44100/48000/50000/50400/96000/192000
 Stereo: 8000/16000/32000/44100/48000/50000/50400/96000/192000
 Channels: mono and stereo
 Rresolution: little-endian, 16bit
 */
- (ZoomVideoSDKError)sendShareAudio:(char *)data dataLength:(NSUInteger)length sampleRate:(NSUInteger)rate audioChannel:(ZoomVideoSDKAudioChannel)channel;
@end

