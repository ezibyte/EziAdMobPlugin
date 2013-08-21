//
//  EziAdMobObject.cpp
//  AdMobPlugin
//
//  Created by Paras Mendiratta on 19/08/13.
//
//





#include "EziAdMobObject.h"
#include "EziAdMobDelegate.h"
#include "EziAdMobDefinition.h"


static EziAdMobObject* sharedAdmobObject;


// ---------------------------------------------------------
    #pragma mark - (C) Callback Methods
// ---------------------------------------------------------


// ---------------------------------------------------------
    #pragma mark - Destructor
// ---------------------------------------------------------

EziAdMobObject::~EziAdMobObject()
{
    
}

// ---------------------------------------------------------
    #pragma mark - Singleton Object
// ---------------------------------------------------------

EziAdMobObject::EziAdMobObject()
{
    mAdMobDelegate    = NULL;
}

EziAdMobObject*  EziAdMobObject::sharedObject()
{
    if (sharedAdmobObject == NULL)
    {
        sharedAdmobObject = new EziAdMobObject();
    }
    return sharedAdmobObject;
}


// ---------------------------------------------------------
    #pragma mark - Public Methods
// ---------------------------------------------------------

void EziAdMobObject::setAdMobDelegate(EziAdMobDelegate *admobDelegate)
{
    mAdMobDelegate = admobDelegate;
}

void EziAdMobObject::initBannerAd()
{
    EziAdMobObject::sharedObject()->initBannerAd(ADMOB_BANNER_AD_ID);
}

void EziAdMobObject::initBannerAd(const char* adUnitID)
{
    EziAdMobObject::sharedObject()->initBannerAd(adUnitID, ccp(0, 0), EziAdMobWrapper::SizeType::kAdSizeBanner);
}

void EziAdMobObject::initBannerAd(const char* adUnitID, EziAdMobWrapper::SizeType::BannerAd sizeType)
{
    EziAdMobObject::sharedObject()->initBannerAd(adUnitID, ccp(0, 0), sizeType);
}

void EziAdMobObject::initBannerAd(const char* adUnitID, CCPoint displayPoint, EziAdMobWrapper::SizeType::BannerAd sizeType)
{
    EziAdMobWrapper::initBannerAd(adUnitID, displayPoint.x, displayPoint.y, sizeType);
}

void EziAdMobObject::initInterstitial()
{
    EziAdMobObject::sharedObject()->initInterstitial(ADMOB_INTERSTITIAL_AD_ID);
}

void EziAdMobObject::initInterstitial(const char* adUnitID)
{
    EziAdMobWrapper::initInterstitial(adUnitID);
}

void EziAdMobObject::setTestDevices(const char* deviceID, ...)
{
    std::string devices = "";
    
    do
    {
        CC_BREAK_IF(deviceID == NULL);
        
        va_list args;
        va_start(args, deviceID);
        
        if (deviceID)
        {
            devices.append(deviceID);
            const char* i = va_arg(args, const char*);
            while(i)
            {
                devices.append(",");
                devices.append(i);
                i = va_arg(args, const char*);
            }
        }
        va_end(args);
        
    } while (false);
    
    CCLOG("Devices = %s", devices.c_str());
 
    EziAdMobWrapper::setTestDevices(devices.c_str());
}

void EziAdMobObject::setTargetGender(EziAdMobWrapper::GenderType::Target gender)
{
    EziAdMobWrapper::setTargetGender(gender);
}

void EziAdMobObject::setBirthDay(unsigned int month, unsigned int day, unsigned int year)
{
    EziAdMobWrapper::setBirthDay(month, day, year);
}

void EziAdMobObject::setLocationWithCountryAndPincode(const char* pincode, const char* countryCode)
{
    EziAdMobWrapper::setLocationWithCountryAndPincode(pincode, countryCode);
}

void EziAdMobObject::displayBannerAd(bool toDisplay)
{
    EziAdMobWrapper::displayBannerAd(toDisplay);
}

void EziAdMobObject::displayInterstitialAd(bool toDisplay)
{
    EziAdMobWrapper::displayInterstitialAd(toDisplay);
}

void EziAdMobObject::loadBannerAd()
{
    EziAdMobWrapper::loadBannerAd();
}

void EziAdMobObject::loadInterstitialAd()
{
    EziAdMobWrapper::loadInterstitialAd();
}

void EziAdMobObject::release()
{
    CCLOG("EziAdMob:: Shared Object released in C++");
    EziAdMobWrapper::releaseManager();
    delete sharedAdmobObject;
}

