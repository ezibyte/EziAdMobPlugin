//
//  EziAdMobDefinition.h
//  AdMobPlugin
//
//  Created by Paras Mendiratta on 19/08/13.
//
//

#ifndef AdMobPlugin_EziAdMobDefinition_h
#define AdMobPlugin_EziAdMobDefinition_h

#define JNI_HELPER_PATH             "../../cocos2dx/platform/android/jni/JniHelper.h"
#define CCCOMMON_PATH               "../../cocos2dx/platform/CCCommon.h"
#define ADMOB_BANNER_AD_ID          "a15102594f27e3b"
#define ADMOB_INTERSTITIAL_AD_ID    "a15102594f27e3b"


namespace EziAdMobWrapper
{
    typedef void (*adMobBannerAdReceived)(int);
    typedef void (*adMobBannerAdFailed)(int, const char*);
    typedef void (*adMobInterstitialAdReceived)(int);
    typedef void (*adMobInterstitialAdFailed)(int, const char*);
    
    struct GenderType
    {
        enum Target
        {
            kUnknown, // Default
            kMale,
            kFemale
        };
    };
    
    struct SizeType
    {
        enum BannerAd
        {
            kAdSizeBanner, // Default
            kAdSizeMediumRectangle,
            kAdSizeFullBanner,
            kAdSizeLeaderboard,
            kAdSizeSmartBannerPortrait,
            kAdSizeSmartBannerLandscape
            
        };
    };
    
    
    
    
    void initBannerAd(const char* adUnitID, float displayPointX, float displayPointY, EziAdMobWrapper::SizeType::BannerAd sizeType);
    void initInterstitial(const char* adUnitID);
    void setTestDevices(const char* devicesIDs);
    void setTargetGender(EziAdMobWrapper::GenderType::Target gender);
    void setBirthDay(unsigned int month, unsigned int day, unsigned int year);
    void setLocationWithCountryAndPincode(const char* pincode, const char* countryCode);
    void displayBannerAd(bool toDisplay);
    void displayInterstitialAd(bool toDisplay);
    
    void loadBannerAd();
    void loadInterstitialAd();
    void releaseManager();
}


#endif
