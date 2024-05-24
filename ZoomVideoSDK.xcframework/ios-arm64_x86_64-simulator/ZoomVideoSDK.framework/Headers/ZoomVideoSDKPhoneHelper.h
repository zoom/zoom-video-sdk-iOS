//
//  ZoomVideoSDKPhoneHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2021/12/21.
//  Copyright © 2021 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class ZoomVideoSDKPhoneSupportCountryInfo
 @brief support country information interface.
 */
@interface ZoomVideoSDKPhoneSupportCountryInfo : NSObject
/*!
 @brief The country ID.
 */
@property (nonatomic, copy) NSString     * _Nullable countryID;
/*!
 @brief The country name.
 */
@property (nonatomic, copy) NSString     * _Nullable countryName;
/*!
 @brief The country code.
 */
@property (nonatomic, copy) NSString     * _Nullable countryCode;
@end


/*!
 @class ZoomVideoSDKDialInNumberInfo
 @brief For dial in number information.
 */
@interface ZoomVideoSDKDialInNumberInfo : NSObject
/*!
 @brief The country ID.
 */
@property (nonatomic, copy) NSString     * _Nullable countryID;
/*!
 @brief The country code.
 */
@property (nonatomic, copy) NSString     * _Nullable countryCode;
/*!
 @brief The country name.
 */
@property (nonatomic, copy) NSString     * _Nullable countryName;
/*!
 @brief Dial in number.
 */
@property (nonatomic, copy) NSString     * _Nullable number;
/*!
 @brief Dial in number format string for display.
 */
@property (nonatomic, strong) NSString     * _Nullable displayNumber;
/*!
 @brief Dial in number type.
 */
@property (nonatomic, assign) ZoomVideoSDKDialInNumType     type;
@end


/*!
 @class ZoomVideoSDKInvitePhoneUserInfo
 @brief The info for InvitePhoneUser.
 */
@interface ZoomVideoSDKInvitePhoneUserInfo : NSObject
/*!
 @brief The country code of the specified user must be in the support list.
 */
@property (nonatomic, copy) NSString     * _Nullable countryCode;

/*!
 @brief The phone number of specified user.
 */
@property (nonatomic, copy) NSString     * _Nullable phoneNumber;

/*!
 @brief The screen name of the specified user in the session.
 */
@property (nonatomic, copy) NSString     * _Nullable name;

/*!
 @brief true: Need press number one to agree to join the session, otherwise not.
 */
@property (nonatomic, assign) BOOL     bPressOne;

/*!
 @brief true: Play a greeting prompt tone when joining the session, otherwise not.
 */
@property (nonatomic, assign) BOOL     bGreeting;
@end


@interface ZoomVideoSDKPhoneHelper : NSObject

/*!
 @brief Determine if the session supports join by phone or not.
 @return YES indicates join by phone is supported, otherwise NO.
 */
- (BOOL)isSupportPhoneFeature;

/*!
 @brief Get the list of the country information where the session supports to join by telephone.
 @return List of the country information returns if the session supports to join by telephone. Otherwise nil.
 */
- (NSArray <ZoomVideoSDKPhoneSupportCountryInfo *>* _Nullable)getSupportCountryInfo;

/*!
 @brief Invite the specified user to join the session by call out.
 @param countryCode The country code of the specified user must be in the support list.
 @param phoneNumber The phone number of specified user.
 @param name The screen name of the specified user in the session.
 @return If the function succeeds, the return value is Errors_Success.Otherwise failed.
 */
- (ZoomVideoSDKError)inviteByPhone:(NSString *_Nonnull)countryCode phoneNumber:(NSString *_Nonnull)phoneNumber name:(NSString *_Nonnull)name
DEPRECATED_MSG_ATTRIBUTE("use invitePhoneUser: instead");

/*!
 @brief Invite the specified user to join the session by call out.
 @param inviteInfo The invite action's informations.
 @return If the function succeeds, the return value is Errors_Success.Otherwise failed.
 */
- (ZoomVideoSDKError)invitePhoneUser:(ZoomVideoSDKInvitePhoneUserInfo * _Nullable)inviteInfo;

/*!
 @brief Cancel the invitation that is being called out by phone.
 @return If the function succeeds, the return value is Errors_Success.Otherwise failed
 */
- (ZoomVideoSDKError)cancelInviteByPhone;

/*!
 @brief Get the status of the invitation by phone.
 @return If the function succeeds, the method returns the ZoomVideoSDKPhoneStatus of the invitation by phone. To get extended error information, see [ZoomVideoSDKPhoneStatus].
 */
- (ZoomVideoSDKPhoneStatus)getInviteByPhoneStatus;

/*!
 @brief Get video sdk dial in number information list.
 @return If the function succeeds, will return dial in information list
 */
- (NSArray <ZoomVideoSDKDialInNumberInfo *> * _Nullable)getSessionDialInNumbers;

@end
