//
//  ZoomVideoSDKAnnotationHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 4/19/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>


@interface ZoomVideoSDKAnnotationHelper: NSObject

/*!
 @brief Whether annotation was disabled or not by the share owner.
 @return The result of it.
 */
- (BOOL)isSenderDisableAnnotation;

/*!
 @brief Starts annotation.
 @return The result of it.
 */
- (ZoomVideoSDKError)startAnnotation;
/*!
 @brief Stops annotation.
 @return The result of it.
 */
- (ZoomVideoSDKError)stopAnnotation;

/*!
 @brief Set the annotation tool color.
 @param toolColor The specified color.
 @return The result of it.
 */
- (ZoomVideoSDKError)setToolColor:(nullable UIColor *)toolColor;
/*!
 @brief Gets the annotation tool color.
 @return The current tool color.
 */
- (nullable UIColor *)getToolColor;

/*!
 @brief Set the annotation tool type.
 @param type the specify annotation tool type.
 @return The result of it.
 @warning The tool type ZoomVideoSDKAnnotationToolType_Picker and ZoomVideoSDKAnnotationToolType_SpotLight are not support for viewer.
 */
- (ZoomVideoSDKError)setToolType:(ZoomVideoSDKAnnotationToolType)type;
/*!
 @brief Get the annotation tool type.
 @return The current tool type.
 */
- (ZoomVideoSDKAnnotationToolType)getToolType;

/*!
 @brief Set the annotation tool width.
 @param width The specified annotation tool width.
 @return The result of it.
 */
- (ZoomVideoSDKError)setToolWidth:(NSUInteger)width;
/*!
 @brief Get the annotation tool width.
 @return The current tool width.
 */
- (NSUInteger)getToolWidth;

/*!
 @brief Undoes one annotation content step.
 @return The result of it.
 */
- (ZoomVideoSDKError)undo;

/*!
 @brief Redoes one annotation content step.
 @return The result of it.
 */
- (ZoomVideoSDKError)redo;

/*!
 @brief Clears the annotation content.
 @param type the specify clear type.
 @return The result of it.
 */
- (ZoomVideoSDKError)clear:(ZoomVideoSDKAnnotationClearType)type;
@end


