//
//  ZoomVideoSDKVideoCapability.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2020/3/9.
//  Copyright © 2020 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKVideoCapability
 @brief Capabilitiy infomation of video source.
 */
@interface ZoomVideoSDKVideoCapability : NSObject
/*!
 @brief width of video.
 */
@property (nonatomic, assign) int width;
/*!
 @brief height of video.
 */
@property (nonatomic, assign) int height;
/*!
 @brief frame rate of video.
 */
@property (nonatomic, assign) int frame;

@end
