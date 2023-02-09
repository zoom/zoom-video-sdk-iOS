//
//  ZoomVideoSDKAudioRawData.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2019/5/16.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKAudioRawData
 @brief A Class contains the information of audio raw data.
 */
@interface ZoomVideoSDKAudioRawData : NSObject

/*!
 @brief Pointer of audio buffer data.
 */
@property (nonatomic, assign) char      *buffer;

/*!
 @brief Audio buffer data length.
 */
@property (nonatomic, assign) NSInteger bufferLen;

/*!
 @brief Audio sampling rate.
 */
@property (nonatomic, assign) NSInteger sampleRate;

/*!
 @brief Number of audio channels.
 */
@property (nonatomic, assign) NSInteger channelNum;

/*!
 @brief Determine if the reference count for the interface pointer can be increased.
 @warning If you call addRef, the SDK will try to hold the raw data buffer until the reference becomes 0. When you finish using the raw data buffer, you must call releaseRef to release it.
 */
- (BOOL)canAddRef;

/*!
 @brief Increase reference count by 1. Adding a reference will ensure that the raw data buffer will not be released.
 @warning If you addRef, the SDK will try to hold the raw data buffer until the reference becomes 0. When you finish using the raw data buffer, you must call releaseRef;
 */
- (BOOL)addRef;

/*!
 @brief Decrease reference count by 1.
 @warning If you addRef, the SDK will try to hold the raw data buffer until the reference becomes 0. When you finish using the raw data buffer, you must call releaseRef;
 */
- (NSInteger)releaseRef;

@end

