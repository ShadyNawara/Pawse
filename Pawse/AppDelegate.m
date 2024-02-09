//
//  AppDelegate.m
//  Pawse
//
//  Created by Shady on 2/7/24.
//


#import "AppDelegate.h"
#import "AdjacentKeys.h"
#import <dlfcn.h>

@interface AppDelegate ()

@property (assign, nonatomic) CFMachPortRef eventTap;

@property (strong, nonatomic) NSStatusItem *statusItem;
@property (strong, nonatomic) NSMutableSet *pressedKeys;

@property (assign, nonatomic) BOOL enabled;


- (CGEventRef)handleKeyboardEvent:(CGEventTapProxy)proxy type:(CGEventType)type event:(CGEventRef)event;

@end

@implementation AppDelegate


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    self.enabled = YES;
    
    self.pressedKeys = [NSMutableSet set];
    
    [self setupMenuBar];
    
    [self startEventTap];
}

- (void)setupMenuBar {
    self.statusItem = [[NSStatusBar systemStatusBar] statusItemWithLength:NSVariableStatusItemLength];
    self.statusItem.button.image = [NSImage imageWithSystemSymbolName:@"cat.circle.fill" accessibilityDescription:nil];
    NSMenu *menu = [[NSMenu alloc] init];
    
    // Toggle Enabled/Disabled
    NSMenuItem *toggleEnabledItem = [[NSMenuItem alloc] initWithTitle:@"Pause for Paws" action:@selector(toggleEnabled:) keyEquivalent:@""];
    [menu addItem:toggleEnabledItem];
    
    [menu addItem:[NSMenuItem separatorItem]];
    
    // Quit
    NSMenuItem *quitItem = [[NSMenuItem alloc] initWithTitle:@"Quit" action:@selector(quitApp:) keyEquivalent:@""];
    [menu addItem:quitItem];
    
    self.statusItem.menu = menu;
    [self updateMenuItems];
}

- (void)toggleEnabled:(id)sender {
    self.enabled = !self.enabled;
    if (self.enabled && self.eventTap == NULL) {
        [self startEventTap];
    }
    else if (!self.enabled) {
        [self stopEventTap];
    }
    
    [self updateMenuItems];
}

- (void)updateMenuItems {
    self.statusItem.button.image = [NSImage imageWithSystemSymbolName:self.enabled ? @"cat.circle.fill" : @"cat.circle" accessibilityDescription:nil];
    for (NSMenuItem *item in self.statusItem.menu.itemArray) {
        if ([item.title isEqualToString:@"Pause for Paws"]) {
            item.state = self.enabled ? NSControlStateValueOn : NSControlStateValueOff;
        }
    }
}

- (void)quitApp:(id)sender {
    [self stopEventTap];
    [NSApplication.sharedApplication terminate:nil];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    [self stopEventTap];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return NO;
}

- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}

- (void)startEventTap {
    CGEventMask mask = CGEventMaskBit(NX_SYSDEFINED) | CGEventMaskBit(NX_KEYDOWN) | CGEventMaskBit(NX_KEYUP) | CGEventMaskBit(NX_FLAGSCHANGED);
    self.eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, mask, eventTapCallback, (__bridge void *)(self));
    
    if (!self.eventTap) {
        NSLog(@"Failed to create event tap");
        return;
    }
    
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, self.eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(self.eventTap, true);
    CFRelease(runLoopSource);
}

- (void)stopEventTap {
    if (self.eventTap) {
        CGEventTapEnable(self.eventTap, false);
        CFMachPortInvalidate(self.eventTap);
        CFRelease(self.eventTap);
        self.eventTap = NULL;
    }
}

CGEventRef eventTapCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *userInfo) {
    AppDelegate *delegate = (__bridge AppDelegate *)userInfo;
    return [delegate handleKeyboardEvent:proxy type:type event:event];
}

- (CGEventRef)handleKeyboardEvent:(CGEventTapProxy)proxy type:(CGEventType)type event:(CGEventRef)event {
    NSEvent *nsEvent = [NSEvent eventWithCGEvent:event];
    if (type == NSEventTypeSystemDefined) {
        int64_t data = [nsEvent data1];
        int64_t data2 = [nsEvent data2];
        if (data2 >= 0) {
            return event;
        }
        
        int keyCode = (data & 0xFFFF0000) >> 16;
        int keyState = ((data & 0x0000FFFF) & 0xFF00) >> 8;
        
        int functionKeyCode = keyCode;
        switch (keyCode) {
            case 3:
                functionKeyCode = kVK_F1; // F1
                break;
            case 2:
                functionKeyCode = kVK_F2; // F2
                break;
            case 20:
                functionKeyCode = kVK_F7; // F7
                break;
            case 16:
                functionKeyCode = kVK_F8; // F8
                break;
            case 19:
                functionKeyCode = kVK_F9; // F9
                break;
            case 7:
                functionKeyCode = kVK_F10; // F10
                break;
            case 1:
                functionKeyCode = kVK_F11; // F11
                break;
            case 10:
                functionKeyCode = kVK_F12; // F12
                break;
            default:
                break;
        }
        if (keyState == 10) { // key down
            [self.pressedKeys addObject:@(functionKeyCode)];
        }
        else if(keyState == 11) { // key up
            [self.pressedKeys removeObject:@(functionKeyCode)];
        }
    }
    else if (type == NSEventTypeKeyDown || type == NSEventTypeKeyUp){
        int fixedKeyCode = [nsEvent keyCode];
        switch (fixedKeyCode) {
            case 160:
                fixedKeyCode = kVK_F3; // F3
                break;
            case 177:
                fixedKeyCode = kVK_F4; // F4
                break;
            case 176:
                fixedKeyCode = kVK_F5; // F5
                break;
            case 178:
                fixedKeyCode = kVK_F6; // F6
                break;
            default:
                break;
        }
        
        if (type == NSEventTypeKeyUp){
            [self.pressedKeys removeObject:@(fixedKeyCode)];
        }
        else {
            [self.pressedKeys addObject:@(fixedKeyCode)];
        }
    }
    
    else if (type == NSEventTypeFlagsChanged){
        if ([self.pressedKeys containsObject:@([nsEvent keyCode])]) {
            [self.pressedKeys removeObject:@([nsEvent keyCode])];
        }
        else {
            [self.pressedKeys addObject:@([nsEvent keyCode])];
        }
    }
    
    [self shouldPause];
    
    return event;
}

- (void)shouldPause {
    for (NSNumber *key in self.pressedKeys) {
        if([AdjacentKeys.keyboardLayout objectForKey:key]) {
            NSArray *adjacentKeys = AdjacentKeys.keyboardLayout[key];
            for (NSNumber *adjacentKey in adjacentKeys) {
                if ([self.pressedKeys containsObject:adjacentKey]) {
                    NSArray *secondDegreeAdjacentKeys = AdjacentKeys.keyboardLayout[adjacentKey];
                    for (NSNumber *secondDegreeAdjacentKey in secondDegreeAdjacentKeys) {
                        if (![secondDegreeAdjacentKey isEqual:key] && [self.pressedKeys containsObject:secondDegreeAdjacentKey]) {
                            NSLog(@"Pausing for Cat");
                            [self.pressedKeys removeAllObjects];
                            [self lockScreen];
                            return;
                        }
                    }
                }
            }
        }
    }
}

- (void)lockScreen {
    void *loginFramework = dlopen("/System/Library/PrivateFrameworks/login.framework/login", RTLD_LAZY);
    if (!loginFramework) {
        NSLog(@"Failed to load login framework");
        return;
    }
    
    void (*SACLockScreenImmediate)(void) = dlsym(loginFramework, "SACLockScreenImmediate");
    if (!SACLockScreenImmediate) {
        NSLog(@"Failed to locate SACLockScreenImmediate function");
        dlclose(loginFramework);
        return;
    }
    
    SACLockScreenImmediate();
    dlclose(loginFramework);
}

@end

