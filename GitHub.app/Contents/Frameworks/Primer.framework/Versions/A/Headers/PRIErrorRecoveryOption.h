//
//  PRIErrorRecoveryOption.h
//  Primer
//
//  Created by Justin Spahr-Summers on 2014-06-19.
//  Copyright (c) 2014 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

#import "PRIMacros.h"

/// Describes one recovery option for a `PRIErrorRecoveryAttempter`.
@interface PRIErrorRecoveryOption : NSObject <NSCopying>

/// The title for this option, as it would appear on a button in an alert.
@property (nonatomic, copy, readonly) NSString *localizedTitle;

/// A block that will return a signal to subscribe to if this recovery option is
/// selected by the user, or `nil` to immediately indicate a failed error
/// recovery.
///
/// The block will be passed the error that occurred.
@property (nonatomic, copy, readonly) RACSignal * (^catchBlock)(NSError *);

/// Returns a singleton recovery option with the title “Cancel” that consider
/// recovery to be successful, but simply forward the original error.
+ (instancetype)cancelRecoveryOption;

/// Initializes the recovery option with the given title and behavior.
///
/// This is the designated initializer for this class.
- (instancetype)initWithLocalizedTitle:(NSString *)localizedTitle catchBlock:(RACSignal * (^)(NSError *error))catchBlock;

- (instancetype)init PRI_NOPE("Use -initWithLocalizedTitle:catchBlock: instead");

@end
