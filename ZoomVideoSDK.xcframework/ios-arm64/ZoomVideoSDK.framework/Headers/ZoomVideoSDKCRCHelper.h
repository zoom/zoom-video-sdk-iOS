//
//  ZoomVideoSDKCRCHelper.h
//  ZoomVideoSDK
//
//  Created by ZOOM on 2023/4/4.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ZoomVideoSDKCRCHelper : NSObject


/*!
 @brief Queries if the CRC feature is enabled.
 @return YES means that the CRC is enabled, otherwise it's disabled.
 @warning only get the correct value after joining the session. Only available for the host/co-host.
 */
- (BOOL)isCRCEnabled;
/*!
 @brief Calls the CRC device.
 @param ipAddr The CRC device's IP address.
 @param protocol The protocol of the CRC device.
 @warning Only available for the host/co-host.
 @return If the function succeeds, the return value is Errors_Success.  Otherwise the function  returns a calling error. For more details, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)callCRCDevice:(NSString *)ipAddr protocol:(ZoomVideoSDKCRCProtocol)protocol;

/*!
 @brief Cancels the call to the CRC device.
 @warning Only available for the host/co-host.
 @return If the function succeeds, the return value is Errors_Success.  Otherwise the function  returns a calling error. For more details, see [ZoomVideoSDKError] enum.
 */
- (ZoomVideoSDKError)cancelCallCRCDevice;


@end

