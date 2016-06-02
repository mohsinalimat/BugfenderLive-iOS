BugfenderLive SDK for iOS [![Available in CocoaPods](https://img.shields.io/cocoapods/v/BugfenderLive.svg)](https://cocoapods.org/pods/BugfenderLive) [![CocoaDocs](https://img.shields.io/badge/docs-%E2%9C%93-blue.svg)](http://cocoadocs.org/docsets/BugfenderLive/) 
===================

Bugfender is a cloud service to collect mobile application logs. Bugfender Live is a companion framework that also streams the screen of the iOS device for live debugging.

For more information check [Bugfender live](https://bugfender.com/live/). You'll need a Bugfender account.

BugfenderLive works on iOS 8.0 and better.

# Getting started

This library works together with BugfenderSDK. [Please install BugfenderSDK first](https://github.com/bugfender/BugfenderSDK-iOS).

Step 1. Add an entry to your Podfile:

```ruby
pod 'BugfenderLive', '~> 0.1' 
```

Step 2. Import BugfenderLive in your AppDelegate:

```objective-c
#import <BugfenderSDK/BugfenderSDK.h>
#import <BugfenderLive/BugfenderLive.h>
```

Step 3. Install BugfenderLive right **after enabling Bugfender**:

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    ...
    // Activate the remote logger with an App Key.
    [Bugfender enableAllWithToken:@"YOUR_API_KEY"];
    [BugfenderLive install];
    ...
}
```

Step 4. Disable Bitcode compilation: Select *Your Project* > *Your Target* > Build settings > Enable Bitcode: No

Run the application and look for your Device page in the [Bugfender website](https://app.bugfender.com/). You will see a new button on the top right indicating whether the device is online or offline. Press that button to see the screen of your device.

## Known limitations

 * The supplied libraries do not have Bitcode compilation. You will need to disable Bitcode compilation in your project.
 * For now only CocoaPods is supported because the manual installation is quite complex and error-prone. You may want to try it though!

