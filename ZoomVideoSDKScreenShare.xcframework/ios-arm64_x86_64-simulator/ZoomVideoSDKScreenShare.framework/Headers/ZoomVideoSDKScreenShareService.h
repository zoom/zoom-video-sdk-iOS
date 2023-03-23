//
//  ZoomVideoSDKScreenShareService.h
//  ZoomVideoSDKScreenShare
//
//  Created by Zoom Video Communications on 2018/5/24.
//  Copyright © 2018 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

@interface ZoomVideoSDKScreenShareServiceInitParams : NSObject

/*!
 @brief If you use screen share, you need create group id in your apple developer account, and setup here.
 */
@property (nonatomic, copy) NSString * _Nullable appGroupId;

/*!
 @brief Share option, YES: share device sound when share screen, otherwise not..
 */
@property (nonatomic, assign) BOOL isWithDeviceAudio;

@end

@protocol ZoomVideoSDKScreenShareServiceDelegate <NSObject>

@required
- (void)ZoomVideoSDKScreenShareServiceFinishBroadcastWithError:(NSError *_Nullable)error;

@end

/*!
 @brief Screen share service.
 @warning If main target use virtual audio speaker, screen share only share the video data，can't share the audio data.
 */
@interface ZoomVideoSDKScreenShareService : NSObject

@property (assign, nonatomic) id<ZoomVideoSDKScreenShareServiceDelegate> _Nullable delegate;

- (instancetype _Nonnull)initWithParams:(ZoomVideoSDKScreenShareServiceInitParams *_Nullable)params;

- (void)broadcastStartedWithSetupInfo:(NSDictionary<NSString *,NSObject *> *_Nullable)setupInfo;

- (void)broadcastPaused;

- (void)broadcastResumed;

- (void)broadcastFinished;

- (void)processSampleBuffer:(CMSampleBufferRef _Nonnull )sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

@end
