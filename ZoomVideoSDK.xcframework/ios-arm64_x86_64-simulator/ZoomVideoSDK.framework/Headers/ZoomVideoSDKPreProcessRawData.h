//
//  ZoomVideoSDKPreProcessRawData.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2020/2/26.
//  Copyright © 2020 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKPreProcessRawData
 @brief A Class contains the information of device capture video frame.
 */
@interface ZoomVideoSDKPreProcessRawData : NSObject

/*!
 @brief The stream size.
 */
@property (nonatomic, assign) CGSize size;

/*!
 @brief The Y stride.
 */
@property (nonatomic, assign) int yStride;

/*!
 @brief The U stride.
 */
@property (nonatomic, assign) int uStride;

/*!
 @brief The V stride.
 */
@property (nonatomic, assign) int vStride;

/*!
 @brief Query video raw data is limited.
 */
@property (nonatomic, assign) BOOL isLimited;

/*!
 @brief Get the YUVI420 Y buffer.
 The Y component represents the luma or brightness value of the color.
 @return Y buffer
*/
- (char *)getYBuffer:(int)lineNum;

/*!
 @brief Get the YUVI420 U buffer.
 The U component represents the chroma value.
 @return U buffer
*/
- (char *)getUBuffer:(int)lineNum;

/*!
 @brief Get the YUVI420 V buffer.
 The V component represents the chroma value.
 @return V buffer
*/
- (char *)getVBuffer:(int)lineNum;

/*!
 @brief The raw data format of video data.
 */
@property (nonatomic, assign) ZoomVideoSDKFrameDataFormat format;

/*!
 @brief The video raw data rotation.
 */
@property (nonatomic, assign) ZoomVideoSDKVideoRawDataRotation rotation;

@end

