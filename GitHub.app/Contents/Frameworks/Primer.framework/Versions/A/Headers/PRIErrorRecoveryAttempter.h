//
//  PRIErrorRecoveryAttempter.h
//  Primer
//
//  Created by Justin Spahr-Summers on 2014-06-19.
//  Copyright (c) 2014 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

#import "PRIMacros.h"

/// An error recovery object, conforming to the `NSErrorRecoveryAttempting`
/// informal protocol.
///
/// Place an instance of this class into the `NSRecoveryAttempterErrorKey` key
/// of an error's `userInfo` dictionary, 
@interface PRIErrorRecoveryAttempter : NSObject

/// An array of `PRIErrorRecoveryOption`s to use, in the order they should
/// appear in an alert.
///
/// The first option will be associated with the right-most and default button,
/// the second option to the left of that, etc.
@property (nonatomic, copy, readonly) NSArray *recoveryOptions;

/// The titles from the receiver's `recoveryOptions`.
@property (nonatomic, copy, readonly) NSArray *localizedRecoveryOptionTitles;

/// A signal that will forward values from the `PRIErrorRecoveryOption`
/// corresponding to the user's choice.
///
/// The option's `catchBlock` will be invoked on the main thread, and its signal
/// replayed on the main thread, then this signal will deliver its results on
/// the thread they are sent upon.
/// 
/// If no recovery option is chosen, this signal will complete (without sending
/// any values) when the recovery attempter is deallocated. If the recovery
/// option returns nil from its `catchBlock`, this signal will terminate with
/// the original error.
@property (nonatomic, strong, readonly) RACSignal *recoveryResults;

/// Initializes the recovery attempter with the given `PRIErrorRecoveryOption`s.
- (instancetype)initWithRecoveryOptions:(NSArray *)recoveryOptions;

- (instancetype)init PRI_NOPE("Use -initWithRecoveryOptions: instead");

@end
