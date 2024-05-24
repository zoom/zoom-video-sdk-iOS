

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKUser.h>

#pragma mark - Statistic Information -
/*!
 @class ZoomVideoSDKSessionAudioStatisticInfo
 @brief Session audio statistic information
*/
@interface ZoomVideoSDKSessionAudioStatisticInfo : NSObject
/// The frequency in kilohertz (KHz) sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFrequency;
/// The audio latency (delay in network data transfer) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendLatency;
/// The audio jitter (change in latency) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendJitter;
/// The average audio packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossAvg;
/// The maximum audio packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossMax;

/// The frequency in kilohertz (KHz) received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFrequency;
/// The audio latency (delay in network data transfer) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvLatency;
/// The audio jitter (change in latency) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvJitter;
/// The average audio packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossAvg;
/// The maximum audio packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossMax;
@end

/*!
@class ZoomVideoSDKSessionASVStatisticInfo
@brief The Session video or share statistic information
*/
@interface ZoomVideoSDKSessionASVStatisticInfo : NSObject
/// The frame width in pixels sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFrameWidth;
/// The frame height in pixels sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFrameHeight;
/// The frame rate in FPS sent by the current user.
@property(nonatomic, assign, readonly) NSInteger  sendFps;
/// The video latency (delay in network data transfer) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendLatency;
/// The video jitter (change in latency) experienced by the current user while sending data.
@property(nonatomic, assign, readonly) NSInteger  sendJitter;
/// The average video packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossAvg;
/// The maximum video packet loss sent by the current user.
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossMax;

/// The frame width in pixels received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFrameWidth;
/// The frame height in pixels received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFrameHeight;
/// The frame rate in FPS received by the current user.
@property(nonatomic, assign, readonly) NSInteger  recvFps;
/// The video latency (delay in network data transfer) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvLatency;
/// The video jitter (change in latency) experienced by the current user while receiving data.
@property(nonatomic, assign, readonly) NSInteger  recvJitter;
/// The video average packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossAvg;
/// The maximum video packet loss received by the current user.
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossMax;
@end


#pragma mark - ZoomVideoSDKSession -
/*!
 @brief Zoom Video SDK session.
 */
@interface ZoomVideoSDKSession : NSObject

/*!
@brief Get the session's name.
*/
- (NSString * _Nullable)getSessionName;

/*!
@brief Get the session Id.
@warning Only the host can get the session Id.
*/
- (NSString * _Nullable)getSessionID;

/*!
@brief Get the session number.
@warning get the session number
*/
- (unsigned long long)getSessionNumber;

/*!
@brief Get the session's password.
*/
- (NSString * _Nullable)getSessionPassword;

/*!
@brief Get the session phone passcode.
@warning get the session phone passcode
*/
- (NSString * _Nullable)getSessionPhonePasscode;

/*!
@brief Get the host's name.
*/
- (NSString * _Nullable)getSessionHostName;

/*!
@brief Get the session's host user object.
*/
- (ZoomVideoSDKUser * _Nullable)getSessionHost;

/*!
@brief Get a list of the session's remote users.
*/
- (NSArray <ZoomVideoSDKUser *>* _Nullable)getRemoteUsers;

/*!
@brief Get the session's user object for myself.
*/
- (ZoomVideoSDKUser * _Nullable)getMySelf;

/*!
@brief Get the session's audio statistic information.
*/
- (ZoomVideoSDKSessionAudioStatisticInfo * _Nullable)getSessionAudioStatisticInfo;

/*!
@brief Get the session's video statistic information.
*/
- (ZoomVideoSDKSessionASVStatisticInfo * _Nullable)getSessionVideoStatisticInfo;
/*!
@brief Get the session's screen share statistic information.
*/
- (ZoomVideoSDKSessionASVStatisticInfo * _Nullable)getSessionShareStatisticInfo;

#pragma mark - file transfer -

/*!
@brief Determine whether file transfer is enabled.
@return True if file transfer is enabled, otherwise false.
*/
- (BOOL)isFileTransferEnable;

/*!
@brief Send file to all users in current session.
@param filePath The local path of the file
@return If the function succeeds, the return value is Errors_Success.
@warning this interface will related with chat  privilege see @{ZoomVideoSDKChatPrivilegeType}.
*/
- (ZoomVideoSDKError)transferFile:(NSString * _Nullable)filePath;

/*!
@brief Get the list of allowed file types in transfer.
@return The value of allowed file types in transfer, comma-separated if there are multiple values. Exe files are by default forbidden from being transferred.
*/
- (NSString *_Nullable)getTransferFileTypeWhiteList;

/*!
@brief Get the maximum size for file transfer.
@return The maximum number of bytes for file transfer.
*/
- (unsigned long long)getMaxTransferFileSize;

@end
