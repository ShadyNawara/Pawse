//
//  AdjacentKeys.m
//  Pawse
//
//  Created by Shady on 2/7/24.
//

#import <Foundation/Foundation.h>
#import <Carbon/Carbon.h>

@interface AdjacentKeys : NSObject

+ (NSDictionary *)keyboardLayout;

@end

@implementation AdjacentKeys

+ (NSDictionary *)keyboardLayout {
    static NSDictionary *adjacencyDict;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        adjacencyDict = @{
            // Function Row
            @(kVK_Escape): @[@(kVK_ANSI_Grave), @(kVK_F1), @(kVK_ANSI_1)], // ESC adjacent to `~`, F1, and 1
            @(kVK_F1): @[@(kVK_Escape), @(kVK_F2), @(kVK_ANSI_1), @(kVK_ANSI_2)], // F1 adjacent to ESC, F2, 1, and 2
            @(kVK_F2): @[@(kVK_F1), @(kVK_F3), @(kVK_ANSI_2), @(kVK_ANSI_3)], // F2 adjacent to F1, F3, 2, and 3
            @(kVK_F3): @[@(kVK_F2), @(kVK_F4), @(kVK_ANSI_3), @(kVK_ANSI_4)], // F3 adjacent to F2, F4, 3, and 4
            @(kVK_F4): @[@(kVK_F3), @(kVK_F5), @(kVK_ANSI_4), @(kVK_ANSI_5)], // F4 adjacent to F3, F5, 4, and 5
            @(kVK_F5): @[@(kVK_F4), @(kVK_F6), @(kVK_ANSI_5), @(kVK_ANSI_6)], // F5 adjacent to F4, F6, 5, and 6
            @(kVK_F6): @[@(kVK_F5), @(kVK_F7), @(kVK_ANSI_6), @(kVK_ANSI_7)], // F6 adjacent to F5, F7, 6, and 7
            @(kVK_F7): @[@(kVK_F6), @(kVK_F8), @(kVK_ANSI_7), @(kVK_ANSI_8)], // F7 adjacent to F6, F8, 7, and 8
            @(kVK_F8): @[@(kVK_F7), @(kVK_F9), @(kVK_ANSI_8), @(kVK_ANSI_9)], // F8 adjacent to F7, F9, 8, and 9
            @(kVK_F9): @[@(kVK_F8), @(kVK_F10), @(kVK_ANSI_9), @(kVK_ANSI_0)], // F9 adjacent to F8, F10, 9, and 0
            @(kVK_F10): @[@(kVK_F9), @(kVK_F11), @(kVK_ANSI_0), @(kVK_ANSI_Minus)], // F10 adjacent to F9, F11, 0, and -
            @(kVK_F11): @[@(kVK_F10), @(kVK_F12), @(kVK_ANSI_Minus), @(kVK_ANSI_Equal)], // F11 adjacent to F10, F12, -, and =
            @(kVK_F12): @[@(kVK_F11), @(kVK_ANSI_Equal), @(kVK_Delete)], // F12 adjacent to F11, =, and delete
            
            // Numbers Row
            @(kVK_ANSI_Grave): @[@(kVK_Escape), @(kVK_ANSI_1), @(kVK_Tab)], // ` adjacent to ESC, 1, and Tab
            @(kVK_ANSI_1): @[@(kVK_ANSI_Grave), @(kVK_Escape), @(kVK_F1), @(kVK_ANSI_2), @(kVK_Tab), @(kVK_ANSI_Q)], // 1 adjacent to `, ESC, F1, 2, Tab, and Q
            @(kVK_ANSI_2): @[@(kVK_ANSI_1), @(kVK_F1), @(kVK_F2), @(kVK_ANSI_3), @(kVK_ANSI_Q), @(kVK_ANSI_W)], // 2 adjacent to 1, F1, F2, 3, Q, and W
            @(kVK_ANSI_3): @[@(kVK_ANSI_2), @(kVK_F2), @(kVK_F3), @(kVK_ANSI_4), @(kVK_ANSI_W), @(kVK_ANSI_E)], // 3 adjacent to 2, F2, F3, 4, W, and E
            @(kVK_ANSI_4): @[@(kVK_ANSI_3), @(kVK_F3), @(kVK_F4), @(kVK_ANSI_5), @(kVK_ANSI_E), @(kVK_ANSI_R)], // 4 adjacent to 3, F3, F4, 5, E, and R
            @(kVK_ANSI_5): @[@(kVK_ANSI_4), @(kVK_F4), @(kVK_F5), @(kVK_ANSI_6), @(kVK_ANSI_R), @(kVK_ANSI_T)], // 5 adjacent to 4, F4, F5, 6, R, and T
            @(kVK_ANSI_6): @[@(kVK_ANSI_5), @(kVK_F5), @(kVK_F6), @(kVK_ANSI_7), @(kVK_ANSI_T), @(kVK_ANSI_Y)], // 6 adjacent to 5, F5, F6, 7, T, and Y
            @(kVK_ANSI_7): @[@(kVK_ANSI_6), @(kVK_F6), @(kVK_F7), @(kVK_ANSI_8), @(kVK_ANSI_Y), @(kVK_ANSI_U)], // 7 adjacent to 6, F6, F7, 8, Y, and U
            @(kVK_ANSI_8): @[@(kVK_ANSI_7), @(kVK_F7), @(kVK_F8), @(kVK_ANSI_9), @(kVK_ANSI_U), @(kVK_ANSI_I)], // 8 adjacent to 7, F7, F8, 9, U, and I
            @(kVK_ANSI_9): @[@(kVK_ANSI_8), @(kVK_F8), @(kVK_F9), @(kVK_ANSI_0), @(kVK_ANSI_I), @(kVK_ANSI_O)], // 9 adjacent to 8, F8, F9, 0, I, and O
            @(kVK_ANSI_0): @[@(kVK_ANSI_9), @(kVK_F9), @(kVK_F10), @(kVK_ANSI_Minus), @(kVK_ANSI_O), @(kVK_ANSI_P)], // 0 adjacent to 9, F9, F10, -, O, and P
            @(kVK_ANSI_Minus): @[@(kVK_ANSI_0), @(kVK_F10), @(kVK_F11), @(kVK_ANSI_Equal), @(kVK_ANSI_P), @(kVK_ANSI_LeftBracket)], // - adjacent to 0, F10, F11, =, P, and [
            @(kVK_ANSI_Equal): @[@(kVK_ANSI_Minus), @(kVK_F11), @(kVK_F12), @(kVK_ANSI_LeftBracket), @(kVK_ANSI_RightBracket), @(kVK_Delete)], // = adjacent to -, F11, F12, [, ], and Delete
            @(kVK_Delete): @[@(kVK_ANSI_Equal), @(kVK_F12), @(kVK_ANSI_RightBracket), @(kVK_ANSI_Backslash)], // Delete adjacent to =, F12, ], and \
            
            // QWERTY Row
            @(kVK_Tab): @[@(kVK_ANSI_Grave), @(kVK_ANSI_Q), @(kVK_CapsLock), @(kVK_ANSI_1)], // Tab adjacent to `, Q, Caps Lock, and 1
            @(kVK_ANSI_Q): @[@(kVK_Tab), @(kVK_ANSI_1), @(kVK_ANSI_2), @(kVK_ANSI_W), @(kVK_ANSI_A), @(kVK_CapsLock)], // Q adjacent to Tab, 1, 2, W, A, and Caps Lock
            @(kVK_ANSI_W): @[@(kVK_ANSI_Q), @(kVK_ANSI_2), @(kVK_ANSI_3), @(kVK_ANSI_E), @(kVK_ANSI_S), @(kVK_ANSI_A)], // W adjacent to Q, 2, 3, E, S, and A
            @(kVK_ANSI_E): @[@(kVK_ANSI_W), @(kVK_ANSI_3), @(kVK_ANSI_4), @(kVK_ANSI_R), @(kVK_ANSI_D), @(kVK_ANSI_S)], // E adjacent to W, 3, 4, R, D, and S
            @(kVK_ANSI_R): @[@(kVK_ANSI_E), @(kVK_ANSI_4), @(kVK_ANSI_5), @(kVK_ANSI_T), @(kVK_ANSI_F), @(kVK_ANSI_D)], // R adjacent to E, 4, 5, T, F, and D
            @(kVK_ANSI_T): @[@(kVK_ANSI_R), @(kVK_ANSI_5), @(kVK_ANSI_6), @(kVK_ANSI_Y), @(kVK_ANSI_G), @(kVK_ANSI_F)], // T adjacent to R, 5, 6, Y, G, and F
            @(kVK_ANSI_Y): @[@(kVK_ANSI_T), @(kVK_ANSI_6), @(kVK_ANSI_7), @(kVK_ANSI_U), @(kVK_ANSI_H), @(kVK_ANSI_G)], // Y adjacent to T, 6, 7, U, H, and G
            @(kVK_ANSI_U): @[@(kVK_ANSI_Y), @(kVK_ANSI_7), @(kVK_ANSI_8), @(kVK_ANSI_I), @(kVK_ANSI_J), @(kVK_ANSI_H)], // U adjacent to Y, 7, 8, I, J, and H
            @(kVK_ANSI_I): @[@(kVK_ANSI_U), @(kVK_ANSI_8), @(kVK_ANSI_9), @(kVK_ANSI_O), @(kVK_ANSI_K), @(kVK_ANSI_J)], // I adjacent to U, 8, 9, O, K, and J
            @(kVK_ANSI_O): @[@(kVK_ANSI_I), @(kVK_ANSI_9), @(kVK_ANSI_0), @(kVK_ANSI_P), @(kVK_ANSI_L), @(kVK_ANSI_K)], // O adjacent to I, 9, 0, P, L, and K
            @(kVK_ANSI_P): @[@(kVK_ANSI_O), @(kVK_ANSI_0), @(kVK_ANSI_Minus), @(kVK_ANSI_LeftBracket), @(kVK_ANSI_Semicolon), @(kVK_ANSI_L)], // P adjacent to O, 0, -, [, ;, and L
            @(kVK_ANSI_LeftBracket): @[@(kVK_ANSI_P), @(kVK_ANSI_Minus), @(kVK_ANSI_Equal), @(kVK_ANSI_RightBracket), @(kVK_ANSI_Quote), @(kVK_ANSI_Semicolon)], // [ adjacent to P, -, =, ], ', and ;
            @(kVK_ANSI_RightBracket): @[@(kVK_ANSI_LeftBracket), @(kVK_ANSI_Equal), @(kVK_ANSI_Backslash), @(kVK_ANSI_Quote), @(kVK_Return)], // ] adjacent to [, =, \, ', and Return
            @(kVK_ANSI_Backslash): @[@(kVK_ANSI_RightBracket), @(kVK_Delete), @(kVK_Return)], // \ adjacent to ], Delete, and Return
            
            //Middle Row "ASD"
            @(kVK_CapsLock): @[@(kVK_Tab), @(kVK_ANSI_A), @(kVK_Shift), @(kVK_ANSI_Q)], // Caps Lock adjacent to Tab, A, Shift, and Q
            @(kVK_ANSI_A): @[@(kVK_CapsLock), @(kVK_Shift), @(kVK_ANSI_Q), @(kVK_ANSI_S), @(kVK_ANSI_Z), @(kVK_ANSI_W)], // A adjacent to Caps Lock, Shift, Q, S, Z, and W
            @(kVK_ANSI_S): @[@(kVK_ANSI_A), @(kVK_ANSI_W), @(kVK_ANSI_E), @(kVK_ANSI_D), @(kVK_ANSI_Z), @(kVK_ANSI_X)], // S adjacent to A, W, E, D, Z, and X
            @(kVK_ANSI_D): @[@(kVK_ANSI_S), @(kVK_ANSI_E), @(kVK_ANSI_R), @(kVK_ANSI_F), @(kVK_ANSI_X), @(kVK_ANSI_C)], // D adjacent to S, E, R, F, X, and C
            @(kVK_ANSI_F): @[@(kVK_ANSI_D), @(kVK_ANSI_R), @(kVK_ANSI_T), @(kVK_ANSI_G), @(kVK_ANSI_C), @(kVK_ANSI_V)], // F adjacent to D, R, T, G, C, and V
            @(kVK_ANSI_G): @[@(kVK_ANSI_F), @(kVK_ANSI_T), @(kVK_ANSI_Y), @(kVK_ANSI_H), @(kVK_ANSI_V), @(kVK_ANSI_B)], // G adjacent to F, T, Y, H, V, and B
            @(kVK_ANSI_H): @[@(kVK_ANSI_G), @(kVK_ANSI_Y), @(kVK_ANSI_U), @(kVK_ANSI_J), @(kVK_ANSI_B), @(kVK_ANSI_N)], // H adjacent to G, Y, U, J, B, and N
            @(kVK_ANSI_J): @[@(kVK_ANSI_H), @(kVK_ANSI_U), @(kVK_ANSI_I), @(kVK_ANSI_K), @(kVK_ANSI_N), @(kVK_ANSI_M)], // J adjacent to H, U, I, K, N, and M
            @(kVK_ANSI_K): @[@(kVK_ANSI_J), @(kVK_ANSI_I), @(kVK_ANSI_O), @(kVK_ANSI_L), @(kVK_ANSI_M)], // K adjacent to J, I, O, L, and M
            @(kVK_ANSI_L): @[@(kVK_ANSI_K), @(kVK_ANSI_O), @(kVK_ANSI_P), @(kVK_ANSI_Semicolon), @(kVK_ANSI_Period), @(kVK_ANSI_Comma)], // L adjacent to K, O, P, ;, ., and ,
            @(kVK_ANSI_Semicolon): @[@(kVK_ANSI_L), @(kVK_ANSI_P), @(kVK_ANSI_LeftBracket), @(kVK_ANSI_Quote), @(kVK_ANSI_Slash), @(kVK_ANSI_Period)], // ; adjacent to L, P, [, ', /, and .
            @(kVK_ANSI_Quote): @[@(kVK_ANSI_Semicolon), @(kVK_ANSI_LeftBracket), @(kVK_ANSI_RightBracket), @(kVK_RightShift), @(kVK_Return), @(kVK_ANSI_Slash)], // ' adjacent to ;, [, ], Right Shift, Return, and /
            @(kVK_Return): @[@(kVK_ANSI_Quote), @(kVK_ANSI_RightBracket), @(kVK_ANSI_Backslash), @(kVK_RightShift)], // Return adjacent to ', ], \, and Right Shift
            
            // Last Char Row "ZXCV"
            @(kVK_Shift): @[@(kVK_CapsLock), @(kVK_ANSI_Z), @(kVK_Function), @(kVK_Control), @(kVK_Option), @(kVK_ANSI_A)], // Left Shift adjacent to Caps Lock, Z, FN, Control, Option, and A
            @(kVK_ANSI_Z): @[@(kVK_Shift), @(kVK_ANSI_A), @(kVK_ANSI_S), @(kVK_ANSI_X), @(kVK_Option), @(kVK_Command)], // Z adjacent to Left Shift, A, S, X, Option, and Command
            @(kVK_ANSI_X): @[@(kVK_ANSI_Z), @(kVK_ANSI_S), @(kVK_ANSI_D), @(kVK_ANSI_C), @(kVK_Command), @(kVK_Space)], // X adjacent to Z, S, D, C, Command, and Space
            @(kVK_ANSI_C): @[@(kVK_ANSI_X), @(kVK_ANSI_D), @(kVK_ANSI_F), @(kVK_ANSI_V), @(kVK_Command), @(kVK_Space)], // C adjacent to X, D, F, V, Command, and Space
            @(kVK_ANSI_V): @[@(kVK_ANSI_C), @(kVK_ANSI_F), @(kVK_ANSI_G), @(kVK_ANSI_B), @(kVK_Space)], // V adjacent to C, F, G, B, and Space
            @(kVK_ANSI_B): @[@(kVK_ANSI_V), @(kVK_ANSI_G), @(kVK_ANSI_H), @(kVK_ANSI_N), @(kVK_Space)], // B adjacent to V, G, H, N, and Space
            @(kVK_ANSI_N): @[@(kVK_ANSI_B), @(kVK_ANSI_H), @(kVK_ANSI_J), @(kVK_ANSI_M), @(kVK_Space)], // N adjacent to B, H, J, M, and Space
            @(kVK_ANSI_M): @[@(kVK_ANSI_N), @(kVK_ANSI_J), @(kVK_ANSI_K), @(kVK_ANSI_Comma), @(kVK_Space) , @(kVK_RightCommand)], // M adjacent to N, J, K, ,, Space, and Rigth Command
            @(kVK_ANSI_Comma): @[@(kVK_ANSI_M), @(kVK_ANSI_K), @(kVK_ANSI_L), @(kVK_ANSI_Period), @(kVK_Space) , @(kVK_RightCommand), @(kVK_RightOption)], // , adjacent to M, K, L, ., Space, Right Command, and Right Option
            @(kVK_ANSI_Period): @[@(kVK_ANSI_Comma), @(kVK_ANSI_L), @(kVK_ANSI_Semicolon), @(kVK_ANSI_Slash), @(kVK_RightCommand), @(kVK_RightOption)], // . adjacent to ,, L, ;, /, Right Command, and Right Option
            @(kVK_ANSI_Slash): @[@(kVK_ANSI_Period), @(kVK_ANSI_Semicolon), @(kVK_ANSI_Quote), @(kVK_RightOption), @(kVK_RightShift), @(kVK_LeftArrow), @(kVK_UpArrow), @(kVK_DownArrow)], // / adjacent to ., ;, ', Right Option, Right Shift, left arrow, up arrow, and down arrow
            @(kVK_RightShift): @[@(kVK_ANSI_Slash), @(kVK_ANSI_Quote), @(kVK_Return), @(kVK_LeftArrow), @(kVK_UpArrow), @(kVK_DownArrow), @(kVK_RightArrow)], // Right Shift adjacent to /, ', Return, Left Arrow, Up Arrow, Bottom Arrow, and Right Arrow
            
            // Bottom Row
            @(kVK_Function): @[@(kVK_Shift), @(kVK_Control)], // FN adjacent to Shift and Control
            @(kVK_Control): @[@(kVK_Function), @(kVK_Shift), @(kVK_Option)], // Control adjacent to FN, Shift, and Option
            @(kVK_Option): @[@(kVK_Control), @(kVK_Command), @(kVK_Shift), @(kVK_ANSI_Z)], // Option adjacent to Control, Command, Shift, and Z
            @(kVK_Command): @[@(kVK_Option), @(kVK_Space), @(kVK_ANSI_Z), @(kVK_ANSI_X), @(kVK_ANSI_C)], // Command adjacent to Option, Space, Z, X, C
            @(kVK_Space): @[@(kVK_Command), @(kVK_ANSI_X), @(kVK_ANSI_C), @(kVK_ANSI_V), @(kVK_ANSI_B), @(kVK_ANSI_N), @(kVK_ANSI_M), @(kVK_ANSI_Comma), @(kVK_RightCommand)], // Space adjacent to Command, X, C, V, B, N, M, ,, and Right Command
            @(kVK_RightCommand): @[@(kVK_Space), @(kVK_RightOption)], // Right Command adjacent to Space and Right Option
            @(kVK_RightOption): @[@(kVK_RightCommand), @(kVK_ANSI_Period), @(kVK_ANSI_Slash), @(kVK_LeftArrow)], // Right Option adjacent to Right Command, ., /, and Left Arrow
            @(kVK_LeftArrow): @[@(kVK_RightOption), @(kVK_ANSI_Slash), @(kVK_RightShift), @(kVK_UpArrow), @(kVK_DownArrow), @(kVK_RightArrow)], // Left Arrow adjacent to Right Option, /, Right Shift, Up, Down, and Right Arrow
            @(kVK_UpArrow): @[@(kVK_ANSI_Slash), @(kVK_LeftArrow), @(kVK_DownArrow), @(kVK_RightShift), @(kVK_RightArrow)], // Up Arrow adjacent to /, Left Arrow, Down Arrow, Right Shift, Right Arrow
            @(kVK_DownArrow): @[@(kVK_ANSI_Slash), @(kVK_LeftArrow), @(kVK_UpArrow), @(kVK_RightShift), @(kVK_RightArrow)], // Down Arrow adjacent to /, Left Arrow, Up Arrow, Right Shift, Right Arrow
            @(kVK_RightArrow): @[@(kVK_ANSI_Slash), @(kVK_LeftArrow), @(kVK_UpArrow), @(kVK_DownArrow), @(kVK_RightShift)], // Right Arrow adjacent to /, Left Arrow, Up Arrow, Down Arrow, Right Shift
        };
    });
    return adjacencyDict;
}

@end
