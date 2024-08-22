//
//  ZoomVideoSDKVideoRawData.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2019/1/29.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>

/*!
 @class ZoomVideoSDKVideoRawData
 @brief A Class contains the information of video raw data.
 */
@interface ZoomVideoSDKVideoRawData : NSObject

/*!
 @brief The YUVI420 Y buffer. The Y component represents the luma or brightness values.
 */
@property (nonatomic, assign) char *yBuffer;

/*!
 @brief The YUVI420 U buffer. The U component represents the chroma values.
 */
@property (nonatomic, assign) char *uBuffer;

/*!
 @brief The YUVI420 V buffer. The Y component represents the chroma values.
 */
@property (nonatomic, assign) char *vBuffer;

/*!
 @brief The YUVI420 data buffer. The alpha component represents the chroma values.
 */
@property (nonatomic, assign) char *alphaBuffer;

/*!
 @brief the alpha buffer data length
 */
@property (nonatomic, assign) NSUInteger alphaBufferLen;

/*!
 @brief The stream size.
 */
@property (nonatomic, assign) CGSize size;

/*!
 @brief Query video raw data is limited.
 */
@property (nonatomic, assign) BOOL isLimited;

/*!
 @brief The raw data format of video data
 */
@property (nonatomic, assign) ZoomVideoSDKFrameDataFormat format;

/*!
 @brief The video raw data rotation.
 */
@property (nonatomic, assign) ZoomVideoSDKVideoRawDataRotation rotation;

/*!
 @brief Determine if the reference count for accessing the raw data buffer can be increased.
 @warning If you addRef, the SDK will try to hold the raw data buffer until the reference becomes 0. When you finish using the raw data buffer, you must call releaseRef;
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

