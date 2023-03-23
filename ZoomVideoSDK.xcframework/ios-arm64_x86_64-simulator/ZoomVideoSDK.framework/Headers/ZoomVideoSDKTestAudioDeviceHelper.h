//
//  ZoomVideoSDKTestAudioDeviceHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2022/6/20.
//  Copyright © 2022 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKTestAudioDeviceHelper
 @brief Test audio device interface.
 */
@interface ZoomVideoSDKTestAudioDeviceHelper : NSObject

/*!
 @brief Startthe mic test. This will start recording the input from the miic. Once the recording is complete, call stopMicTest to finish the recording.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)startMicTest;

/*!
 @brief Stop the microphone test. Before calling this, you must have successfully started the microphone test by calling startMicTest. Otherwise this returns an error.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)stopMicTest;

/*!
 @brief Play the microphone recorded sound. You must complete a microphone test by successfully executing startMicTest and stopMicTest before calling this. Otherwise this returns an error.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)playMicTest;

/*!
 @brief Start the speaker test.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)startSpeakerTest;

/*!
 @brief Stop the speaker test. Before calling this, you must have successfully started the speaker test by calling startSpeakerTest. Otherwise this returns an error.
 @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)stopSpeakerTest;

@end

