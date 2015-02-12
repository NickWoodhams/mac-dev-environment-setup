//
//  NSError+PRIExtensions.h
//  GitHub
//
//  Created by Joe Ricioppo on 8/11/10.
//  Copyright 2010 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRIErrorRecoveryAttempter;

/// Associated with a `PRIProblemLevel` value describing how critical the error
/// is.
extern NSString * const PRIProblemLevelErrorKey;

/// Describes how critical an NSError is.
///
/// Values of this type are ordered from least critical to most critical, and can
/// be compared using `>` and `<`.
///
/// PRIProblemLevelWarning  - A problem occurred that did not cause loss of data,
///                           and does not require user interaction to fix.
/// PRIProblemLevelError    - A problem occurred that did not cause loss of data,
///                           but which may require user interaction to fix. This
///                           is the default problem level if none is explicitly
///                           specified.
/// PRIProblemLevelCritical - A problem occurred that potentially caused data
///                           loss, and must be addressed by the user as soon as
///                           possible.
typedef enum : NSInteger {
    PRIProblemLevelWarning = -1,
    PRIProblemLevelError = 0,
    PRIProblemLevelCritical = 1
} PRIProblemLevel;

@interface NSError (PRIExtensions)

/// The value of PRIProblemLevelErrorKey in the receiver's `userInfo` dictionary.
@property (nonatomic, assign, readonly) PRIProblemLevel pri_problemLevel;

/// Behaves like +[NSError errorWithDomain:code:userInfo:], except that any
/// `optionalUserInfo` keys associated with NSNull values will be skipped.
///
/// This can be used to conveniently create a user info dictionary where some
/// values may be nil:
///
///  NSError *error = [NSError pri_errorWithDomain:SomeDomain code:SomeCode optionalUserInfo:@{
///      NSLocalizedDescriptionKey: maybeDescription ?: NSNull.null,
///      NSUnderlyingErrorKey: maybeUnderlyingError ?: NSNull.null
///  }];
+ (NSError *)pri_errorWithDomain:(NSString *)domain code:(NSInteger)code optionalUserInfo:(NSDictionary *)optionalUserInfo;

/// Retrieves the recovery options from `recoveryAttempter`, stores the options
/// and the recovery attempter into the user info dictionary, then invokes
/// +pri_errorWithDomain:code:optionalUserInfo:.
+ (NSError *)pri_errorWithDomain:(NSString *)domain code:(NSInteger)code recoveryAttempter:(PRIErrorRecoveryAttempter *)recoveryAttempter optionalUserInfo:(NSDictionary *)optionalUserInfo;

/// Invokes -pri_errorByReplacingDomain:code:addingOptionalUserInfo: with the
/// receiver's `domain` and `code`.
- (NSError *)pri_errorByAddingOptionalUserInfo:(NSDictionary *)optionalUserInfo;

/// Creates an error from the receiver, replacing its `domain` and `code`, and
/// adding to its `userInfo`.
///
/// This will also add `NSUnderlyingErrorKey` to the returned error, with a value
/// of the receiver.
///
/// newDomain        - The new domain for the returned error. This must not be
///                    nil.
/// newCode          - The new code for the returned error.
/// optionalUserInfo - `userInfo` entries to add to the returned error. Any keys
///                    associated with NSNull values will be omitted from the
///                    returned error. This argument may be nil.
///
/// Returns the transformed error.
- (NSError *)pri_errorByReplacingDomain:(NSString *)newDomain code:(NSInteger)newCode addingOptionalUserInfo:(NSDictionary *)optionalUserInfo;

@end
