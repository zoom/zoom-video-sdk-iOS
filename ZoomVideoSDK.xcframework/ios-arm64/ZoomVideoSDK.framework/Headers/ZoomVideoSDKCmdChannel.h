//
//  ZoomVideoSDKCmdChannel.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2021/12/22.
//  Copyright © 2021 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @brief The command channel
 allows users to send commands or data (such as plain text or a binary encoded into string) to other users in the same session.
 See [ZoomVideoSDK.h#getCmdChannel]
 */
@interface ZoomVideoSDKCmdChannel : NSObject
/**
 @brief Send custom commands or data to other users in the current session. Limit: up to 60 custom commands per second.
 @param commandContent the custom commands or data, represented in string format.
 @param user An instance of ZoomVideoSDKUser associated with the user who receives the command. See [ZoomVideoSDKUser]
 If receiver is set to nil, the command is broadcast to all users.
 @return Errors_Success if the command sends successfully. Otherwise, the send command request fails.
 See error codes defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)sendCommand:(NSString * _Nullable)commandContent receiveUser:(ZoomVideoSDKUser * _Nullable)user;

@end

