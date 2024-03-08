//
//  ZoomVideoSDKLiveTranscriptionHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom on 7/5/22.
//  Copyright © 2022 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZoomVideoSDKLiveTranscriptionLanguage : NSObject
/*!
@brief language id of transcription language
*/
@property(nonatomic, assign, readonly) NSInteger languageID;

/*!
@brief localized language name of transcription language
*/
@property(nonatomic, copy, readonly) NSString * _Nullable languageName;

@end



@interface ZoomVideoSDKLiveTranscriptionMessageInfo : NSObject
/*!
@brief message id of transcription message
*/
@property (nonatomic, copy)NSString * _Nullable messageID;
/*!
@brief speaker id of transcription message
*/
@property (nonatomic, copy)NSString * _Nullable speakerID;
/*!
@brief speak name  of transcription message
*/
@property (nonatomic, copy)NSString * _Nullable speakerName;
/*!
@brief message content  of transcription message
*/
@property (nonatomic, copy)NSString * _Nullable messageContent;
/*!
@brief time stamp  of transcription message
*/
@property (nonatomic, assign)NSInteger timeStamp;
/*!
@brief message tpye  of transcription message
*/
@property (nonatomic, assign)ZoomVideoSDKLiveTranscriptionOperationType messageType;

@end


@interface ZoomVideoSDKLiveTranscriptionHelper : NSObject

/*!
@brief Query if the user can start live transcription.
*/
- (BOOL)canStartLiveTranscription;

/*!
@brief Get the current live transcription status.
@return the current live transcription status.
*/
- (ZoomVideoSDKLiveTranscriptionStatus)getLiveTranscriptionStatus;

/*!
@brief Start live transcription.If the session allows multi-language transcription, all users can start live transcription.
*/
- (ZoomVideoSDKError)startLiveTranscription;

/*!
@brief Stop live transcription.If the session allows multi-language transcription,all user can stop live transcription.
*/
- (ZoomVideoSDKError)stopLiveTranscription;

/*!
@brief Get the list of all available spoken languages in session.
@return If the function succeeds, the return value is the list of the available spoken languages in a session.Otherwise failed, the return value is NULL.
*/
- (NSArray <ZoomVideoSDKLiveTranscriptionLanguage*>* _Nullable )getAvailableSpokenLanguages;

/*!
@brief Set the spoken language of the current user.
@param languageID The spoken language ID.
@return If the function succeeds, the return value is Success. Otherwise failed.
*/
- (ZoomVideoSDKError)setSpokenLanguage:(NSInteger)languageID;

/*!
@brief Get the spoken language of the current user.
@return If the function succeeds, return the current spoken language.
*/
- (ZoomVideoSDKLiveTranscriptionLanguage * _Nullable)getSpokenLanguage;

/*!
@brief Enable or disable to receive original and translated content. If you enable this feature, you must start live transcription.
@return If the function succeeds, the return value is ZoomVideoSDKError.
*/

- (ZoomVideoSDKError)enableReceiveSpokenLanguageContent:(BOOL)enable;

/*!
@brief Determine whether the view history translation message is available.
@return True indicates that the view history transcription message is available. Otherwise False.
*/
- (BOOL)isAllowViewFullTranscriptEnable;

/*!
@brief Get the list of all history translation messages in a session.
@return If the function succeeds, the return value is a list of all history translation messages in a session.
*/
- (NSArray <ZoomVideoSDKLiveTranscriptionMessageInfo *> * _Nullable)getHistoryTranslationMessageList;

/*!
@brief Determine whether the feature to receive original and translated is available.
@return True indicates that the feature to receive original and translated is available. Otherwise False.
*/

- (BOOL)isReceiveSpokenLanguageContentEnabled;

/*!
@brief Get the list of all available translation languages in a session.
@return If the function succeeds, the return value is the list of all available translation languages in a session. Otherwise failed, the return value is NULL.
*/
- (NSArray <ZoomVideoSDKLiveTranscriptionLanguage*>* _Nullable)getAvailableTranslationLanguages;

/*!
@brief Set the translation language of the current user.
@param languageID The translation language ID. If the language id is set to -1, live translation will be disabled.
@return If the function succeeds, the return value is Success. Otherwise failed. To get extended error information,
*/
- (ZoomVideoSDKError)setTranslationLanguage:(NSInteger)languageID;

/*!
@brief Get the translation language of the current user.
@return If the function succeeds, return the current translation language.
*/
- (ZoomVideoSDKLiveTranscriptionLanguage * _Nullable)getTranslationLanguage;

@end


