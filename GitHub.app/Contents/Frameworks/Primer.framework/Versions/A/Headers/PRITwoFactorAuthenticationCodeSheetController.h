//
//  PRITwoFactorAuthenticationCodeSheetController.h
//  Primer
//
//  Created by Matt Diephouse on 8/30/13.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import <ReactiveCocoa/ReactiveCocoa.h>
#import <Primer/PRIWindowController.h>

// The medium used to deliver the one-time password.
//
// PRITwoFactorAuthenticationCodeMediumSMS - Delivered via SMS.
// PRITwoFactorAuthenticationCodeMediumApp - Delivered via an app.
typedef enum : NSInteger {
	PRITwoFactorAuthenticationCodeMediumSMS,
	PRITwoFactorAuthenticationCodeMediumApp,
} PRITwoFactorAuthenticationCodeMedium;

@protocol PRITwoFactorAuthenticationViewModel;

// A window controller that prompts for a 2FA code.
@interface PRITwoFactorAuthenticationCodeSheetController : PRIWindowController

// The view model with which the window controller was created.
@property (nonatomic, readonly, strong) id<PRITwoFactorAuthenticationViewModel> viewModel;

// Sends next when the sheet has been dismissed.
@property (nonatomic, readonly, strong) RACSignal *dismissed;

// Create a new controller with the given view model.
//
// viewModel - The view model for the window controller. Cannot be nil.
//
// Returns the initialized object.
- (id)initWithViewModel:(id<PRITwoFactorAuthenticationViewModel>)viewModel;

// Presents the sheet on the given window.
//
// window - The window to which the sheet should be attached. Cannot be nil.
//
// Returns a signal that completes when the sheet has been dismissed.
- (RACSignal *)presentOnWindow:(NSWindow *)window;

@end

// A view model that handles authenticating with a 2FA code.
@protocol PRITwoFactorAuthenticationViewModel <NSObject>

// The authentication code.
@property (nonatomic, copy) NSString *authenticationCode;

// The medium for one-time password delivery.
@property (nonatomic, readonly, assign) PRITwoFactorAuthenticationCodeMedium medium;

// The host for the server for which the authentication code is needed.
@property (nonatomic, readonly, copy) NSString *serverHost;

// Aunthenticate with `authenticationCode` on execution.
@property (nonatomic, readonly, strong) RACCommand *authenticateCommand;

// Re-send the authentication code on execution.
@property (nonatomic, readonly, strong) RACCommand *resendCodeCommand;

@end
