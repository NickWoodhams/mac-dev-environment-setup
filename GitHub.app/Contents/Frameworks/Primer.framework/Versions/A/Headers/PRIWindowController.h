//
//  PRIWindowController.h
//  Primer
//
//  Created by Matt Diephouse on 8/30/13.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import <Cocoa/Cocoa.h>

// An abstract class that adds conveniences for Primer window controllers.
//
// This should only be used by window controllers in Primer and not by window controllers in
// client apps. It assumes that the controller is in Primer and only searches the Primer.framework
// bundle for nibs.
@interface PRIWindowController : NSWindowController

// The name of the nib to load for this controller.
//
// If a subclass of PRIWindowController is available for client applications to subclass, this
// method should be overridden to explicitly provide the name of the PRIWindowController subclass,
// so that any nib within Primer is found correctly.
+ (NSString *)nibName;

// Initializes the window controller with a window nib named +nibName from the Primer.framework
// bundle.
//
// Returns the initialized object.
- (id)init;

@end
