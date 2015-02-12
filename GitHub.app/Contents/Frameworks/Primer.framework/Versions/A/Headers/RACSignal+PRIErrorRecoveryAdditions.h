//
//  RACSignal+PRIErrorRecoveryAdditions.h
//  Primer
//
//  Created by Justin Spahr-Summers on 2014-06-19.
//  Copyright (c) 2014 GitHub. All rights reserved.
//

#import <ReactiveCocoa/ReactiveCocoa.h>

@interface RACSignal (PRIErrorRecoveryAdditions)

/// Invokes the given block if an error occurs on the signal, then forwards the
/// results from any recovery attempt initiated by the block.
///
/// recoveryBlock - A block that will present the user with options for error
///                 recovery. This block will be invoked upon the main thread, and
///                 must not be nil.
///
/// Returns a signal that will forward events from the receiver until an error
/// occurs, at which point it will invoke `recoveryBlock`. If the error has
/// a `PRIErrorRecoveryAttempter`, the returned signal will then begin
/// forwarding its `recoveryResults` signal. If there is no recovery attempter,
/// or it is not a `PRIErrorRecoveryAttempter`, the returned signal will simply
/// forward the original error on the main thread.
- (RACSignal *)pri_forwardResultsFromErrorRecoveryAttempt:(void (^)(NSError *error))recoveryBlock;

@end
