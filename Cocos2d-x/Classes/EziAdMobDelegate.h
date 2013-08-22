//
//  EziAdMobDelegate.h
//  AdMobPlugin
//
//  Created by Paras Mendiratta on 19/08/13.
//
//

#ifndef AdMobPlugin_EziAdMobDelegate_h
#define AdMobPlugin_EziAdMobDelegate_h


class EziAdMobDelegate
{
public:
    
    virtual void adMobBannerReceived(int tagID) {}
    virtual void adMobInterstitialAdReceived(int tagID) {}
    virtual void adMobBannerAdFailed(int tagID, const char* errorMessage) {}
    virtual void adMobInterstitialAdFailed(int tagID, const char* errorMessage) {}
    
};

#endif
