//
//  ZoomVideoSDKVirtualBackgroundHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2022/12/16.
//  Copyright © 2022 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @brief Virtual background item interface.
 */
@interface ZoomVideoSDKVirtualBackgroundItem : NSObject
/*!
 @brief Get the current item image file path.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable imageFilePath;
/*!
 @brief Get the current item image name.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable imageName;
/*!
 @brief Get the current item background type.
 */
@property (nonatomic, assign, readonly) ZoomVideoSDKVirtualBackgroundDataType type;
/*!
 @brief Determine whether the virtual background can be deleted.
 */
@property (nonatomic, assign, readonly) BOOL canVirtualBackgroundBeDeleted;

@end

/*!
 @brief virtual background helper.
 */
@interface ZoomVideoSDKVirtualBackgroundHelper : NSObject
/*!
 @brief Determine whether the user can support smart virtual backgrounds.
 @return YES means the user can support it and you can use it.
 @warning Device should be iPhone 8/ 8 plus X or above or be iPad Pro 9.7 above, OS should be iOS 11 or above.
 And should be embed zoomcml.xcframework.
 */
- (BOOL)isSupportVirtualBackground;

/*!
 @brief Add virtual background object.
 @param image image of virtual background.
 @return An object of type {@link ZoomVideoSDKVirtualBackgroundItem}. Once the function is called successfully, this parameter will store the pointer to the ZoomVideoSDKVirtualBackgroundItem*.
 */
- (ZoomVideoSDKVirtualBackgroundItem * _Nullable)addVirtualBackgroundItem:(UIImage *_Nullable)image;

/*!
 @brief Remove virtual background object.
 @param imageItem The ZoomVideoSDKVirtualBackgroundItem object to be removed.
 @return If the function succeeds, it will return Errors_Success.
 */
- (ZoomVideoSDKError)removeVirtualBackgroundItem:(ZoomVideoSDKVirtualBackgroundItem *_Nullable)imageItem;

/*!
 @brief Returns a collection of virtual background item as an object of type {@link ZoomVideoSDKVirtualBackgroundItem}.
 @return If the function succeeds, it will return a list of virtual background items
 */
- (NSArray<ZoomVideoSDKVirtualBackgroundItem * > * _Nullable)getVirtualBackgroundItemList;

/*!
 @brief Select virtual background item.
 @param imageItem The ZoomVideoSDKVirtualBackgroundItem object to select.
 @return If the function succeeds, it will return Errors_Success.
 */
- (ZoomVideoSDKError)setVirtualBackgroundItem:(ZoomVideoSDKVirtualBackgroundItem *_Nullable)imageItem;

/*!
 @brief Get a selected virtual background item.
 @return If the function succeeds, it will return the object of type {@link ZoomVideoSDKVirtualBackgroundItem}.
 */
- (ZoomVideoSDKVirtualBackgroundItem * _Nullable)getSelectedVirtualBackgroundItem;

@end

