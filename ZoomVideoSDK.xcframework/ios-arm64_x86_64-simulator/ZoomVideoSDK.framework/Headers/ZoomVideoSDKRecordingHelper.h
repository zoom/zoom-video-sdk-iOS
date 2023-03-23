//
//  ZoomVideoSDKRecordingHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2021/12/23.
//  Copyright © 2021 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/*!
 @brief Class for recording agreement action.
 */
@interface ZoomVideoSDKRecordAgreementHandler : NSObject
/*!
 @brief get the recording agreement type.
 */
@property (assign, nonatomic, readonly) ZoomVideoSDKRecordAgreementType agreementType;
/*!
 @brief accept the indivdual record or traditional record.
 */
- (BOOL)accept;
/*!
 @brief decline the individual record or traditional record. For individual record, will not record that person, for traditional record, will leave the meeting.
 */
- (BOOL)decline;

@end

/*!
 @brief Class for using cloud recording in the session.
 See[ZoomVideoSDK.h#getRecordingHelper]
 */
@interface ZoomVideoSDKRecordingHelper : NSObject

/*!
 @brief Checks if the current user meets the requirements to start cloud recording.
 The following are the prerequisites to use the helper class:
 A cloud recording add-on plan
 Cloud recording feature enabled on the Web portal
 @return Errors_Success if the current user meets the requirements to start cloud recording. Otherwise, the current user does not meeting the requirements to start recording. See error codes defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)canStartRecording;

/*!
 @brief Start cloud recording.
 @return Errors_Successif the start cloud recording request was successful. Otherwise, the start cloud recording request failed. See error codes defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)startCloudRecording;

/*!
 @brief Stop cloud recording.
 @return Errors_Success if the stop cloud recording request was successful. Otherwise, the stop cloud recording request failed. See error codes defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)stopCloudRecording;

/*!
 @brief Pause the ongoing cloud recording.
 @return Errors_Success if the pause cloud recording request was successful. Otherwise, the pause cloud recording request failed. See error codes defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)pauseCloudRecording;

/*!
 @brief Resume the previously paused cloud recording.
 @return Errors_Success if the resume cloud recording request was successful. Otherwise, the resume cloud recording request failed. See error codes defined in [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)resumeCloudRecording;

/*!
 @brief Get the current status of cloud recording.
 @return cloud recording status value defined in [ZoomVideoSDKRecordingStatus].
 */
- (ZoomVideoSDKRecordingStatus)getCloudRecordingStatus;

@end
