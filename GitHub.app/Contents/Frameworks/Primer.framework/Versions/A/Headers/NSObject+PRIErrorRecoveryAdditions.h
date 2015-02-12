//
//  NSObject+PRIErrorRecoveryAdditions.h
//  Primer
//
//  Created by Justin Spahr-Summers on 2014-06-20.
//  Copyright (c) 2014 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

// lol informal protocols
@interface NSObject (PRIErrorRecoveryAdditions)

/// Attempts to start error recovery.
///
/// error               - The error to recover from.
/// recoveryOptionIndex - The recovery option that was selected.
/// presentedInSheet    - Whether the error was originally presented in a sheet.
///                       If NO, the error must have been presented in an
///                       application modal dialog.
///
/// Returns a signal which sends a boolean indicating whether error recovery was
/// successfully _started_, then completes on the main thread.
- (RACSignal *)pri_attemptRecoveryFromError:(NSError *)error optionIndex:(NSUInteger)recoveryOptionIndex presentedInSheet:(BOOL)presentedInSheet;

@end
