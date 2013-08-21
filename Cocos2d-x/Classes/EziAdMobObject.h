//
//  EziAdMobObject.h
//  AdMobPlugin
//
//  Created by Paras Mendiratta on 19/08/13.
//
//

#ifndef __AdMobPlugin__EziAdMobObject__
#define __AdMobPlugin__EziAdMobObject__



#include "EziAdMobDefinition.h"
#include "EziAdMobDelegate.h"

#include "Cocos2d.h"

using namespace cocos2d;


class EziAdMobObject
{
    EziAdMobObject();
    EziAdMobDelegate* mAdMobDelegate;
    
public:
    
    ~EziAdMobObject();
    
    static EziAdMobObject* sharedObject();
    
    void setAdMobDelegate(EziAdMobDelegate *admobDelegate);
    
    void initBannerAd();
    void initBannerAd(const char* adUnitID);
    void initBannerAd(const char* adUnitID, EziAdMobWrapper::SizeType::BannerAd sizeType);
    void initBannerAd(const char* adUnitID, CCPoint displayPoint, EziAdMobWrapper::SizeType::BannerAd sizeType);

    void initInterstitial();
    void initInterstitial(const char* adUnitID);

    void setTestDevices(const char* deviceID, ...);
    void setTargetGender(EziAdMobWrapper::GenderType::Target gender);
    void setBirthDay(unsigned int month, unsigned int day, unsigned int year);
    void setLocationWithCountryAndPincode(const char* pincode, const char* countryCode);

    void displayBannerAd(bool toDisplay);
    void displayInterstitialAd(bool toDisplay);
    
    void loadBannerAd();
    void loadInterstitialAd();
     
    void release();

};


#endif /* defined(__AdMobPlugin__EziAdMobObject__) */
