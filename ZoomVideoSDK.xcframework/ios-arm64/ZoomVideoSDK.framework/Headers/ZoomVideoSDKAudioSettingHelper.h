//
//  ZoomVideoSDKAudioSettingHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2022/4/7.
//  Copyright © 2022 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKAudioSettingHelper
 @brief Audio setting interface.
 */
@interface ZoomVideoSDKAudioSettingHelper : NSObject

/*!
 @brief Call this method to enable or disable the original input of mic.
 @param enable YES to enable the original input of the microphone or NO to disable it.
 @return Error code defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)enableMicOriginalInput:(BOOL)enable;

/*!
 @brief Determine whether the original input of the microphone is enabled.
 @return YES if the original input of the microphone is enabled, otherwise NO.
 */
- (BOOL)isMicOriginalInputEnable;

/*!
 @brief Call this method to enable or disable the auto adjust input of mic.
 @param enable YES to enable auto adjust input or false to disable it.
 @return Error code defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)enableAutoAdjustMicVolume:(BOOL)enable;

/*!
 @brief Determine whether the original input of the microphone is enabled.
 @return YES if auto adjust input  is enabled, otherwise false.
 */
- (BOOL)isAutoAdjustMicVolumeEnabled;

@end
