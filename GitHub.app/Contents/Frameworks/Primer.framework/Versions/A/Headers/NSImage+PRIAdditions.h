//
//  NSImage+PRIAdditions.h
//  Primer
//
//  Created by Matt Diephouse on 8/9/13.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSImage (PRIAdditions)

// An image to use as the icon for a General preference pane.
+ (NSImage *)pri_preferencesGeneralIcon;

// An image to use as the icon for an Accounts preference pane.
+ (NSImage *)pri_preferencesAccountsIcon;

// An image to use as the icon for an Advanced preference pane.
+ (NSImage *)pri_preferencesAdvancedIcon;

@end
