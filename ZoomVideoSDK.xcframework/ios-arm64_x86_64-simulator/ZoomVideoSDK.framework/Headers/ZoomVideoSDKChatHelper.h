//
//  ZoomVideoSDKChatHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2019/1/9.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKChatMessage
 @brief A class that contains all the information for a message.
 */

@class ZoomVideoSDKUser;
@interface ZoomVideoSDKChatMessage : NSObject

/*!
 @brief The message ID.
 */
@property (nonatomic, strong) NSString   * _Nullable messageID;
/*!
 @brief The sender user.
 */
@property (nonatomic, strong) ZoomVideoSDKUser   * _Nullable senderUser;

/*!
 @brief The receiver user.
 */
@property (nonatomic, strong) ZoomVideoSDKUser   * _Nullable receiverUser;

/*!
 @brief The message content.
 */
@property (nonatomic, strong) NSString     * _Nullable content;
/*!
 @brief The message sent time in timestamp.
 */
@property (nonatomic, assign) long long    timeStamp;
/*!
 @brief The message is send to all user or not.
 */
@property (nonatomic, assign) BOOL         isChatToAll;
/*!
 @brief The message is send by me or not.
 */
@property (nonatomic, assign) BOOL         isSelfSend;

@end

/*!
 @class ZoomVideoSDKChatHelper
 @brief A class to operate the instant message in session.
 */
@interface ZoomVideoSDKChatHelper : NSObject


/*!
 @brief Call this method to send a chat message to a specific user.
 @param user The receiver.
 @param content The message content.
 @return The result of it.
 */
- (ZoomVideoSDKError)SendChatToUser:(ZoomVideoSDKUser * _Nullable)user Content:(NSString * _Nullable)content;

/*!
 @brief Call this method to send a chat message to all users.
 @param content The message content.
 @return The result of it.
 */
- (ZoomVideoSDKError)SendChatToAll:(NSString * _Nullable)content;

/**
 @brief Determine if a specific message can be deleted.
 @param msgID The message ID.
 @return YES if the message can be deleted, otherwise NO.
 */
-(BOOL)canChatMessageBeDeleted:(NSString *__nonnull)msgID;

/*!
 @brief Call this method to delete a specific chat message from the Zoom server.
 @warning This does not delete the message in your user interface.
 @param msgID The message ID.
 @return If the function succeeds, it will return Errors_Success, otherwise failed.
 */
- (ZoomVideoSDKError)deleteChatMessage:(NSString * __nonnull)msgID;

/*!
 @brief Determine whether chat is disabled.
 @return YES if chat is disabled, otherwise NO.
 */
- (BOOL)IsChatDisabled;

/*!
 @brief Determine whether private chat is disabled.
 @return YES if private chat is disabled, otherwise NO.
 */
- (BOOL)IsPrivateChatDisabled;

/*!
 @brief Set participant Chat Privilege when in session
 @param privilege The chat privilege of the participant
 @return If the function succeeds, it will return Errors_Success, otherwise failed.
 @warning Only meeting host/manager can run the function
 */
- (ZoomVideoSDKError)changeChatPrivilege:(ZoomVideoSDKChatPrivilegeType)privilege;

/*!
 @brief get participant Chat Privilege when in session
 @return the result of participant chat Privilege.
 */
- (ZoomVideoSDKChatPrivilegeType)getChatPrivilege;


@end
