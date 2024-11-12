//
//  ZoomVideoSDKMaskHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 4/19/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>

/**
 * The mask info to generate the mask bitmap.
 */
@interface ZoomVideoSDKMaskInfo : NSObject

@property (nonatomic, assign) ZoomVideoSDKMaskShape shape;
/**
 @brief The left margin. For rectangle and oval
 */
@property (nonatomic, assign) CGFloat left;

/**
 @brief The top margin. For rectangle and oval
 */
@property (nonatomic, assign) CGFloat top;

/**
 @brief The right margin. For rectangle and oval
 */
@property (nonatomic, assign) CGFloat right;

/**
 @brief The bottom margin. For rectangle and oval
 */
@property (nonatomic, assign) CGFloat bottom;

/**
 @brief The x-coordinate of the center of the circle to be drawn.
 */
@property (nonatomic, assign) CGFloat cx;

/**
 @brief The y-coordinate of the center of the circle to be drawn.
 */
@property (nonatomic, assign) CGFloat cy;

/**
 @brief The radius of the circle to be drawn.
 */
@property (nonatomic, assign) CGFloat radius;

@end

/**
 * The helper to set the video mask.
 */
@interface ZoomVideoSDKMaskHelper: NSObject

/**
 @brief Generate a mask UIImage based on the mask information that is located within the canvas width or the canvas height.
 *      The recommended aspect ratio is 1280 * 720 or 720 * 12880.
 @param maskInfos The mask informations used to generate mask.
 @param canvasWidth The canvas width used to locate the mask information.
 @param canvasHeight The canvas height used to locate the mask information.
 @return The mask UIImage
 */
- (UIImage * _Nullable)generateMask:(NSArray <ZoomVideoSDKMaskInfo *> * _Nullable)maskInfos width:(NSInteger)canvasWidth height:(NSInteger)canvasHeight;

/**
@brief Set the mask to self video.
@param maskImage UIIage generate by interface "generateMask:width:height:". Or you can generate the bitmap by yourself.
*             This mask image should meet the following conditions:
*             The area through which you want to see the video should be set to opaque
*             and the other areas should be set to transparent.
@param backgroundImage The background iamge.
@param isMirrored Whether the video that is based by the mask generate is mirrored.
*                  For {@link ZoomVideoSDKVideoCanvas}, the value {@link ZoomVideoSDKVideoHelper#isMyVideoMirrored()} can be passed in.
*                  For {@link ZoomVideoSDKRawDataPipe}, the correct value should be passed.
@return errorCode {@link ZoomVideoSDKError}.
*/
- (ZoomVideoSDKError)setVideoMask:(UIImage * _Nullable)maskImage background:(UIImage * _Nullable)backgroundImage mirror:(BOOL)isMirrored;
@end


