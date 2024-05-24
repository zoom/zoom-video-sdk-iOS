//
//  ZoomVideoSDKFileTranserHandle.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 4/15/24.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDK.h>

#pragma mark - File Transfer -
@interface ZoomVideoSDKFileTransferProgress : NSObject
@property(nonatomic, assign)    NSUInteger ratio;       /// The ratio of the file transfer completed
@property(nonatomic, assign)    NSUInteger completeSize;/// The size of the file transferred so far in bytes
@property(nonatomic, assign)    NSUInteger bitPerSecond;/// The speed of the file transfer in bits per second
@end

@interface ZoomVideoSDKFileStatus : NSObject
@property(nonatomic, assign)    ZoomVideoSDKFileTransferStatus transStatus; // The status of the file transfer
@property(nonatomic, strong, nullable)    ZoomVideoSDKFileTransferProgress *transProgress; // The progress of the file transfer
@end

@interface ZoomVideoSDKFileTransferBaseInfo : NSObject
- (NSTimeInterval)getTimeStamp;
- (BOOL)isSendToAll;
- (NSUInteger)getFileSize;
- (NSString * _Nullable)getFileName;
- (ZoomVideoSDKFileStatus *_Nullable)getStatus;
@end

@interface ZoomVideoSDKSendFile : ZoomVideoSDKFileTransferBaseInfo
- (ZoomVideoSDKUser * _Nullable)getReceiver;
- (ZoomVideoSDKError)cancelSend;
@end

@interface ZoomVideoSDKReceiveFile : ZoomVideoSDKFileTransferBaseInfo
- (ZoomVideoSDKUser * _Nullable)getSender;
- (ZoomVideoSDKError)cancelReceive;
- (ZoomVideoSDKError)startReceive:(NSString * _Nullable)path;
@end

