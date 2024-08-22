//
//  ZoomVideoSDKUserHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/7.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZoomVideoSDKUser;
/*!
 @class ZoomVideoSDKUserHelper
 @brief User control interface.
 */
@interface ZoomVideoSDKUserHelper : NSObject

/*!
 @brief Change a specific user's name.
 @param inputName user new name
 @param changeUser user in the session
 @return YES indicates that name change is success. Otherwise, this function returns NO.
 */
- (BOOL)changeName:(NSString* _Nullable)inputName withUser:(ZoomVideoSDKUser * _Nullable)changeUser;

/*!
 @brief Assign a user as the session host.
 @param user user in the session
 @return YES  indicates that the user is now the host. Otherwise, this function returns NO.
 @warning only session host can run this function, and userId should not be myself.
 */
- (BOOL)makeHost:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Assign a user as the session manager.
 @param user user in the session
 @return YES  indicates that the user is now the manager. Otherwise, this function returns NO.
 @warning only session host can run this function, and userId should not be myself.
 */
- (BOOL)makeManager:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Revoke manager rights from a user.
 @param user user in the session
 @return YES indicates that the user no longer has manager rights. Otherwise, this function returns NO.
 @warning only session host can run this function, and userId should not be myself.
 */
- (BOOL)revokeManager:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Remove user from session.
 @param user user in the session
 @return YES indicates that the function succeeds. Otherwise, this function returns NO.
 @warning The method is available only for the host, and the host can not remove himself.
 */
- (BOOL)removeUser:(ZoomVideoSDKUser * _Nullable)user;

/*!
 @brief Reclaim host permission.
 @return YES indicates that the function succeeds. Otherwise, this function returns NO.
 */
- (BOOL)reclaimHost;

@end
