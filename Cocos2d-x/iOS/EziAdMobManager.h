//
//  EziAdMobManager.h
//  AdMobPlugin
//
//  Created by Paras Mendiratta on 18/08/13.
//
//

#import <Foundation/Foundation.h>
#import "GADBannerView.h"
#import "GADInterstitial.h"

@interface EziAdMobManager : NSObject <GADInterstitialDelegate>

+(EziAdMobManager*) sharedManager;

@end
