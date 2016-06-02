//
//  BugfenderLive.h
//  BugfenderLive
//
//  Created by gimix on 20/05/16.
//  Copyright © 2016 Bugfender. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Screen sharing to debug your mobile app
 * @discussion This is the entry point for the framework. It just needs to be
 * installed.
 */
@interface BugfenderLive : NSObject

/** Installs Bugfender Live
 * @discussion This is the only method that needs to be called. All operation
 * is done remotely from the Bugfender console.
 */
+(void)install;

@end
