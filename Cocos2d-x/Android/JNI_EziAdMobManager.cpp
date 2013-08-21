//
//  JNI_EziSocialManager.cpp
//  FacebookGameDemo
//
//  Created by Paras Mendiratta on 11/04/13.
//
//

#include "EziAdMobDefinition.h"
#include "cocos2d.h"
#include "EziAdMobObject.h"
#include <string.h>
#include <jni.h>
#include <iostream>

#include JNI_HELPER_PATH
#include CCCOMMON_PATH

#pragma mark - AdMob Methods

void EziAdMobWrapper::initBannerAd(const char* adUnitID, float displayPointX, float displayPointY, EziAdMobWrapper::SizeType::BannerAd sizeType)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "initBannerAd",
                                                "(Ljava/lang/String;FFI)V"))
    {
        jfloat dx = (float)displayPointX;
        jfloat dy = (float)displayPointY;
        jint  type = (int)(sizeType);
        jstring adUnitIDArg = t.env->NewStringUTF(adUnitID);

        
        t.env->CallStaticVoidMethod(t.classID, t.methodID, adUnitIDArg, dx, dy, type);
        t.env->DeleteLocalRef(t.classID);
    }

}

void EziAdMobWrapper::initInterstitial(const char* adUnitID)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "initInterstitial",
                                                "(Ljava/lang/String;)V"))
    {
        jstring adUnitIDArg = t.env->NewStringUTF(adUnitID);
        
        
        t.env->CallStaticVoidMethod(t.classID, t.methodID, adUnitIDArg);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::setTestDevices(const char* devicesIDs)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "setTestDevices",
                                                "(Ljava/lang/String;)V"))
    {
        jstring testDevices = t.env->NewStringUTF(devicesIDs);
        
        
        t.env->CallStaticVoidMethod(t.classID, t.methodID, testDevices);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::setTargetGender(EziAdMobWrapper::GenderType::Target gender)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "setTargetGender",
                                                "(I)V"))
    {
        jint genderArg = 0;
        switch (gender)
        {
            case EziAdMobWrapper::GenderType::kUnknown:
                genderArg = 0;
                break;
            
            case EziAdMobWrapper::GenderType::kMale:
                genderArg = 1;
                break;

            case EziAdMobWrapper::GenderType::kFemale:
                genderArg = 2;
                break;
            
            default:
                break;
        }
                
        t.env->CallStaticVoidMethod(t.classID, t.methodID, genderArg);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::setBirthDay(unsigned int month, unsigned int day, unsigned int year)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "setBirthDay",
                                                "(III)V"))
    {
        jint monthArg   = (int)month;
        jint dayArg     = (int)day;
        jint yearArg    = (int)year;
        
        
        t.env->CallStaticVoidMethod(t.classID, t.methodID, monthArg, dayArg, yearArg);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::setLocationWithCountryAndPincode(const char* pincode, const char* countryCode)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "setLocationWithCountryAndPincode",
                                                "(Ljava/lang/String;Ljava/lang/String;)V"))
    {
        jstring pincodeDevices = t.env->NewStringUTF(pincode);
        jstring countryCodeDevices = t.env->NewStringUTF(countryCode);
        
        t.env->CallStaticVoidMethod(t.classID, t.methodID, pincodeDevices, countryCodeDevices);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::displayBannerAd(bool toDisplay)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "displayBannerAd",
                                                "(Z)V"))
    {
        jboolean toDisplayArg = toDisplay;
        t.env->CallStaticVoidMethod(t.classID, t.methodID, toDisplayArg);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::displayInterstitialAd(bool toDisplay)
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "displayInterstitialAd",
                                                "(Z)V"))
    {
        jboolean toDisplayArg = toDisplay;
        t.env->CallStaticVoidMethod(t.classID, t.methodID, toDisplayArg);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::loadBannerAd()
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "loadBannerAd",
                                                "(I)V"))
    {
        jint unusedParameter = 0;
        t.env->CallStaticVoidMethod(t.classID, t.methodID, unusedParameter);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::loadInterstitialAd()
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t,
                                                "com/ezibyte/admob/EziAdMobManager",
                                                "loadInterstitialAd",
                                                "(I)V"))
    {
        jint unusedParameter = 0;
        t.env->CallStaticVoidMethod(t.classID, t.methodID, unusedParameter);
        t.env->DeleteLocalRef(t.classID);
    }
}

void EziAdMobWrapper::releaseManager()
{
    
}

/*
    
void Java_com_ezibyte_social_EziSocialManager_nativeFBFriendsRequestComplete(JNIEnv* env,
                                                                                 jobject thiz,
                                                                                 jlong callback_address,
                                                                                 jint responseCode,
                                                                                 jstring responseMessage,
                                                                                 jstring resultString)
{
        if (callback_address)
        {
            const char *responseMessageRawString = env->GetStringUTFChars(responseMessage, 0);


            const char* resultData = env->GetStringUTFChars(resultString, 0);
            
            (*reinterpret_cast<EziSocialWrapperNS::FBFriendsCallback>(callback_address))(responseCode, responseMessageRawString, resultData);
            
            // Clean up
            env->ReleaseStringUTFChars(responseMessage, responseMessageRawString);
            env->ReleaseStringUTFChars(resultString, resultData);

        }
        
        //env->DeleteLocalRef(stringArray);
}
    
void Java_com_ezibyte_social_EziSocialManager_nativeFBUserDetailsRequestComplete(JNIEnv* env,
                                                                                 jobject thiz,
                                                                                 jlong callback_address,
                                                                                 jint responseCode,
                                                                                 jstring responseMessage, jstring userDetailString)
{
    if (callback_address)
    {
        CCLOG("Welcome to JNI");
        const char* rawResponseMessage = env->GetStringUTFChars(responseMessage, 0);
        CCLOG("Conversion done.");

        const char* rawUserDetails = env->GetStringUTFChars(userDetailString, 0);
        
        (*reinterpret_cast<EziSocialWrapperNS::FBUserDetailCallback>(callback_address))(responseCode, rawResponseMessage, rawUserDetails);
        
        // Clean up
        env->ReleaseStringUTFChars(responseMessage, rawResponseMessage);
        env->ReleaseStringUTFChars(userDetailString, rawUserDetails);
        
    }
}
    
    void Java_com_ezibyte_social_EziSocialManager_nativeSendMailRequestComplete(JNIEnv* env,
                                                                                  jobject thiz,
                                                                                  jlong callback_address,
                                                                                  jint responseCode)
	{
		if (callback_address)
        {
			(*reinterpret_cast<EziSocialWrapperNS::MailCallback>(callback_address))(responseCode);
        }
	}
    
    void Java_com_ezibyte_social_EziSocialManager_nativeFBHighScoreRequestComplete(JNIEnv* env,
                                                                                  jobject thiz,
                                                                                  jlong callback_address,
                                                                                  jint responseCode, jstring responseMessage,
                                                                                  jstring friendList)
	{
		if (callback_address)
        {
            const char *responseMessageRawString = env->GetStringUTFChars(responseMessage, 0);
            const char *friendListRawString = env->GetStringUTFChars(friendList, 0);
            
			(*reinterpret_cast<EziSocialWrapperNS::FBScoresCallback>(callback_address))(responseCode, responseMessageRawString,friendListRawString);
        }
	}
    
    void Java_com_ezibyte_social_EziSocialManager_nativeRequestSentCallback(JNIEnv* env,
                                                                                   jobject thiz,
                                                                                   jlong callback_address,
                                                                                   jint  responseCode,
                                                                                   jstring responseMessage, jstring recipentIDs)
	{
		if (callback_address)
        {
            int responseCodeInt = (int)responseCode;
            const char *responseMessageRaw = env->GetStringUTFChars(responseMessage, 0);
            const char *recipentIDsRaw = env->GetStringUTFChars(recipentIDs, 0);            
        
			(*reinterpret_cast<EziSocialWrapperNS::FBSendRequestCallback>(callback_address))(responseCodeInt, responseMessageRaw, recipentIDsRaw);
        }
	}
    
    void Java_com_ezibyte_social_EziSocialManager_nativeFacebookRequestReceived(JNIEnv* env,
                                                                                   jobject thiz,
                                                                                   jlong callback_address,
                                                                                   jint responseCode,
                                                                                   jstring processedRequestID,
                                                                                   jstring message,
                                                                                   jstring senderID,
                                                                                   jstring senderName, jstring receiverID,
                                                                                   jstring data, jstring responseMessage)
	{
		if (callback_address)
        {
            const char *processedRequestIDRaw    = env->GetStringUTFChars(processedRequestID, 0);
            const char *messageRaw               = env->GetStringUTFChars(message, 0);
            const char *senderIDRaw              = env->GetStringUTFChars(senderID, 0);
            const char *senderNameRaw            = env->GetStringUTFChars(senderName, 0);
            const char *dataRaw                  = env->GetStringUTFChars(data, 0);
            const char *responseMessageRaw       = env->GetStringUTFChars(responseMessage, 0);
            const char *receiverIDRaw            = env->GetStringUTFChars(receiverID, 0);
            
            int responseType          = (int) responseCode;
            
			(*reinterpret_cast<EziSocialWrapperNS::FBRecieveRequestCallback>(callback_address))(responseType, processedRequestIDRaw, messageRaw, senderIDRaw, senderNameRaw, receiverIDRaw, dataRaw,  responseMessageRaw);
            
            // TODO:: Cleanup
        }
	}
    
    void Java_com_ezibyte_social_EziSocialManager_nativePhotoPostCallback(JNIEnv* env,
                                                                            jobject thiz,
                                                                            jlong callback_address,
                                                                            jint  responseCode,
                                                                            jstring responseMessage)
	{
		if (callback_address)
        {
            int responseCodeInt = (int)responseCode;
            const char *responseMessageRaw = env->GetStringUTFChars(responseMessage, 0);
            
			(*reinterpret_cast<EziSocialWrapperNS::FBPhotoPostCallback>(callback_address))(responseCodeInt, responseMessageRaw);
        }
	}

    
    void Java_com_ezibyte_social_EziSocialManager_nativeIncomingRequestCallback(JNIEnv* env,
                                                                            jobject thiz,
                                                                            jlong callback_address,
                                                                            jint  responseCode,
                                                                            jstring requestIDs, jstring responseMessage)
	{
		if (callback_address)
        {
            int responseCodeInt = (int)responseCode;
            
            const char *responseMessageRaw = env->GetStringUTFChars(responseMessage, 0);
            const char *requestIDsRaw = env->GetStringUTFChars(requestIDs, 0);
            
			(*reinterpret_cast<EziSocialWrapperNS::FBIncomingRequestCallback>(callback_address))(responseCodeInt, requestIDsRaw, responseMessageRaw);
            
            env->ReleaseStringUTFChars(responseMessage, responseMessageRaw);
            env->ReleaseStringUTFChars(requestIDs, requestIDsRaw);
        }
	}

};


*/
