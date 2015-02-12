//
//  PRIMacros.h
//  Primer
//
//  Created by Josh Abernathy on 9/23/13.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

// An NSLog wrapper which provides more information about the app and the
// location of the log statement.
#define PRILog(fmt, ...) NSLog((@"[%d] (v%@) %s [Line %d] " fmt), NSProcessInfo.processInfo.processIdentifier, NSBundle.mainBundle.infoDictionary[(__bridge id)kCFBundleVersionKey], __func__, __LINE__, ##__VA_ARGS__);

// An attribute which marks the method as unavailable with the given compile
// time message. For example:
//
//   - (id)init PRI_NOPE("Use -initWithModel: instead.");
#define PRI_NOPE(msg) __attribute__((unavailable(msg)))
