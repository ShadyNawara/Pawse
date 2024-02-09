//
//  main.m
//  Pawse
//
//  Created by Shady on 2/7/24.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"

BOOL hasAccessibilityAccess(void) {
    NSDictionary *options = @{(__bridge id)kAXTrustedCheckOptionPrompt: @YES};
    BOOL accessibilityEnabled = AXIsProcessTrustedWithOptions((__bridge CFDictionaryRef)options);
    
    return accessibilityEnabled;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        if (hasAccessibilityAccess()) {
            NSLog(@"We have accessibility access.");
        } else {
            NSLog(@"We do not have accessibility access.");
        }
        NSApplication *application = [NSApplication sharedApplication];
        AppDelegate *appDelegate = [[AppDelegate alloc] init];
        application.delegate = appDelegate;
        [application setActivationPolicy:NSApplicationActivationPolicyAccessory];
        [application run];
    }
    return EXIT_SUCCESS;
}
