/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

c_code.h

DESCRIPTION: Scan code and the respective ascii code stored here.

Following Keys are not supported:
PRNT SCRN
PAUSE

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef KB_C_CODE_H_
#define KB_C_CODE_H_

/******************************************************************************************************/

//#include <avr/pgmspace.h>
#include "ascii.h"

/******************************************************************************************************/

#if !defined(KB_NOT_USED)
#define KB_NOT_USED 0
#endif

/******************************************************************************************************/
//SCAN CODES-SET 2
/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_SPACE)
#define KB_SCAN_CODE_SPACE 0x29
#endif

#if !defined(KB_SCAN_CODE_ENTER)
#define KB_SCAN_CODE_ENTER 0x5A
#endif

#if !defined(KB_SCAN_CODE_TAB)
#define KB_SCAN_CODE_TAB 0x0D
#endif

#if !defined(KB_SCAN_CODE_BACKSPACE)
#define KB_SCAN_CODE_BACKSPACE 0x66
#endif

#if !defined(KB_SCAN_CODE_INSERT)
#define KB_SCAN_CODE_INSERT 0x70
#endif

#if !defined(KB_SCAN_CODE_DELETE)
#define KB_SCAN_CODE_DELETE 0x71
#endif

#if !defined(KB_SCAN_CODE_ESCAPE)
#define KB_SCAN_CODE_ESCAPE 0x76
#endif

#if !defined(KB_SCAN_CODE_HOME)
#define KB_SCAN_CODE_HOME 0x6C
#endif

#if !defined(KB_SCAN_CODE_END)
#define KB_SCAN_CODE_END 0x69
#endif

#if !defined(KB_SCAN_CODE_PAGE_DOWN)
#define KB_SCAN_CODE_PAGE_DOWN 0x7A
#endif

#if !defined(KB_SCAN_CODE_PAGE_UP)
#define KB_SCAN_CODE_PAGE_UP 0x7D
#endif

#if !defined(KB_SCAN_CODE_PRINT_SCREEN)
#define KB_SCAN_CODE_PRINT_SCREEN KB_NOT_USED
#endif

#if !defined(KB_SCAN_CODE_APPS)
#define KB_SCAN_CODE_APPS 0x2F
#endif

#if !defined(KB_SCAN_CODE_PAUSE)
#define KB_SCAN_CODE_PAUSE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_POWER)
#define KB_SCAN_CODE_POWER 0x37
#endif

#if !defined(KB_SCAN_CODE_SLEEP)
#define KB_SCAN_CODE_SLEEP 0x3F
#endif

#if !defined(KB_SCAN_CODE_WAKE)
#define KB_SCAN_CODE_WAKE 0x5E
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_NEXT_TRACK)
#define KB_SCAN_CODE_NEXT_TRACK 0x4D
#endif

#if !defined(KB_SCAN_CODE_PREVIOUS_TRACK)
#define KB_SCAN_CODE_PREVIOUS_TRACK 0x15
#endif

#if !defined(KB_SCAN_CODE_STOP)
#define KB_SCAN_CODE_STOP 0x3B
#endif

#if !defined(KB_SCAN_CODE_PLAY_OR_PAUSE)
#define KB_SCAN_CODE_PLAY_OR_PAUSE 0x34
#endif

#if !defined(KB_SCAN_CODE_MUTE)
#define KB_SCAN_CODE_MUTE 0x23
#endif

#if !defined(KB_SCAN_CODE_VOLUME_UP)
#define KB_SCAN_CODE_VOLUME_UP 0x32
#endif

#if !defined(KB_SCAN_CODE_VOLUME_DOWN)
#define KB_SCAN_CODE_VOLUME_DOWN 0x31
#endif

#if !defined(KB_SCAN_CODE_MEDIA_SELECT)
#define KB_SCAN_CODE_MEDIA_SELECT 0x50
#endif

#if !defined(KB_SCAN_CODE_E_MAIL)
#define KB_SCAN_CODE_E_MAIL 0x48
#endif

#if !defined(KB_SCAN_CODE_CALCULATOR)
#define KB_SCAN_CODE_CALCULATOR 0x2B
#endif

#if !defined(KB_SCAN_CODE_COMPUTER)
#define KB_SCAN_CODE_COMPUTER 0x40
#endif

#if !defined(KB_SCAN_CODE_WWW_SEARCH)
#define KB_SCAN_CODE_WWW_SEARCH 0x10
#endif

#if !defined(KB_SCAN_CODE_WWW_HOME)
#define KB_SCAN_CODE_WWW_HOME 0x3A
#endif

#if !defined(KB_SCAN_CODE_WWW_BACK)
#define KB_SCAN_CODE_WWW_BACK 0x38
#endif

#if !defined(KB_SCAN_CODE_WWW_FORWARD)
#define KB_SCAN_CODE_WWW_FORWARD 0x30
#endif

#if !defined(KB_SCAN_CODE_WWW_STOP)
#define KB_SCAN_CODE_WWW_STOP 0x28
#endif

#if !defined(KB_SCAN_CODE_WWW_REFRESH)
#define KB_SCAN_CODE_WWW_REFRESH 0x20
#endif

#if !defined(KB_SCAN_CODE_WWW_FAVORITES)
#define KB_SCAN_CODE_WWW_FAVORITES 0x18
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_LEFT_SHIFT)
#define KB_SCAN_CODE_LEFT_SHIFT 0x12
#endif

#if !defined(KB_SCAN_CODE_LEFT_CONTROL)
#define KB_SCAN_CODE_LEFT_CONTROL 0x14
#endif

#if !defined(KB_SCAN_CODE_LEFT_ALTERNATE)
#define KB_SCAN_CODE_LEFT_ALTERNATE 0x11
#endif

#if !defined(KB_SCAN_CODE_LEFT_GUI)
#define KB_SCAN_CODE_LEFT_GUI 0x1F
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_RIGHT_SHIFT)
#define KB_SCAN_CODE_RIGHT_SHIFT 0x59
#endif

#if !defined(KB_SCAN_CODE_RIGHT_CONTROL)
#define KB_SCAN_CODE_RIGHT_CONTROL 0x14
#endif

#if !defined(KB_SCAN_CODE_RIGHT_ALTERNATE)
#define KB_SCAN_CODE_RIGHT_ALTERNATE 0x11
#endif

#if !defined(KB_SCAN_CODE_RIGHT_GUI)
#define KB_SCAN_CODE_RIGHT_GUI 0x27
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_CAPS_LOCK)
#define KB_SCAN_CODE_CAPS_LOCK 0x58
#endif

#if !defined(KB_SCAN_CODE_NUMBER_LOCK)
#define KB_SCAN_CODE_NUMBER_LOCK 0x77
#endif

#if !defined(KB_SCAN_CODE_SCROLL_LOCK)
#define KB_SCAN_CODE_SCROLL_LOCK 0x7E
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_ARROW_UP)
#define KB_SCAN_CODE_ARROW_UP 0x75
#endif

#if !defined(KB_SCAN_CODE_ARROW_DOWN)
#define KB_SCAN_CODE_ARROW_DOWN 0x72
#endif

#if !defined(KB_SCAN_CODE_ARROW_LEFT)
#define KB_SCAN_CODE_ARROW_LEFT 0x6B
#endif

#if !defined(KB_SCAN_CODE_ARROW_RIGHT)
#define KB_SCAN_CODE_ARROW_RIGHT 0x74
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_0)
#define KB_SCAN_CODE_0 0x45
#endif

#if !defined(KB_SCAN_CODE_1)
#define KB_SCAN_CODE_1 0x16
#endif

#if !defined(KB_SCAN_CODE_2)
#define KB_SCAN_CODE_2 0x1E
#endif

#if !defined(KB_SCAN_CODE_3)
#define KB_SCAN_CODE_3 0x26
#endif

#if !defined(KB_SCAN_CODE_4)
#define KB_SCAN_CODE_4 0x25
#endif

#if !defined(KB_SCAN_CODE_5)
#define KB_SCAN_CODE_5 0x2E
#endif

#if !defined(KB_SCAN_CODE_6)
#define KB_SCAN_CODE_6 0x36
#endif

#if !defined(KB_SCAN_CODE_7)
#define KB_SCAN_CODE_7 0x3D
#endif

#if !defined(KB_SCAN_CODE_8)
#define KB_SCAN_CODE_8 0x3E
#endif

#if !defined(KB_SCAN_CODE_9)
#define KB_SCAN_CODE_9 0x46
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_A)
#define KB_SCAN_CODE_A 0x1C
#endif

#if !defined(KB_SCAN_CODE_B)
#define KB_SCAN_CODE_B 0x32
#endif

#if !defined(KB_SCAN_CODE_C)
#define KB_SCAN_CODE_C 0x21
#endif

#if !defined(KB_SCAN_CODE_D)
#define KB_SCAN_CODE_D 0x23
#endif

#if !defined(KB_SCAN_CODE_E)
#define KB_SCAN_CODE_E 0x24
#endif

#if !defined(KB_SCAN_CODE_F)
#define KB_SCAN_CODE_F 0x2B
#endif

#if !defined(KB_SCAN_CODE_G)
#define KB_SCAN_CODE_G 0x34
#endif

#if !defined(KB_SCAN_CODE_H)
#define KB_SCAN_CODE_H 0x33
#endif

#if !defined(KB_SCAN_CODE_I)
#define KB_SCAN_CODE_I 0x43
#endif

#if !defined(KB_SCAN_CODE_J)
#define KB_SCAN_CODE_J 0x3B
#endif

#if !defined(KB_SCAN_CODE_K)
#define KB_SCAN_CODE_K 0x42
#endif

#if !defined(KB_SCAN_CODE_L)
#define KB_SCAN_CODE_L 0x4B
#endif

#if !defined(KB_SCAN_CODE_M)
#define KB_SCAN_CODE_M 0x3A
#endif

#if !defined(KB_SCAN_CODE_N)
#define KB_SCAN_CODE_N 0x31
#endif

#if !defined(KB_SCAN_CODE_O)
#define KB_SCAN_CODE_O 0x44
#endif

#if !defined(KB_SCAN_CODE_P)
#define KB_SCAN_CODE_P 0x4D
#endif

#if !defined(KB_SCAN_CODE_Q)
#define KB_SCAN_CODE_Q 0x15
#endif

#if !defined(KB_SCAN_CODE_R)
#define KB_SCAN_CODE_R 0x2D
#endif

#if !defined(KB_SCAN_CODE_S)
#define KB_SCAN_CODE_S 0x1B
#endif

#if !defined(KB_SCAN_CODE_T)
#define KB_SCAN_CODE_T 0x2C
#endif

#if !defined(KB_SCAN_CODE_U)
#define KB_SCAN_CODE_U 0x3C
#endif

#if !defined(KB_SCAN_CODE_V)
#define KB_SCAN_CODE_V 0x2A
#endif

#if !defined(KB_SCAN_CODE_W)
#define KB_SCAN_CODE_W 0x1D
#endif

#if !defined(KB_SCAN_CODE_X)
#define KB_SCAN_CODE_X 0x22
#endif

#if !defined(KB_SCAN_CODE_Y)
#define KB_SCAN_CODE_Y 0x35
#endif

#if !defined(KB_SCAN_CODE_Z)
#define KB_SCAN_CODE_Z 0x1A
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_APOSTROPHE)
#define KB_SCAN_CODE_APOSTROPHE 0x0E
#endif

#if !defined(KB_SCAN_CODE_MINUS)
#define KB_SCAN_CODE_MINUS 0x4E
#endif

#if !defined(KB_SCAN_CODE_EQUAL_TO)
#define KB_SCAN_CODE_EQUAL_TO 0x55
#endif

#if !defined(KB_SCAN_CODE_LEFT_BRACKET)
#define KB_SCAN_CODE_LEFT_BRACKET 0x54
#endif

#if !defined(KB_SCAN_CODE_RIGHT_BRACKET)
#define KB_SCAN_CODE_RIGHT_BRACKET 0x5B
#endif

#if !defined(KB_SCAN_CODE_COMMA)
#define KB_SCAN_CODE_COMMA 0x41
#endif

#if !defined(KB_SCAN_CODE_FULL_STOP)
#define KB_SCAN_CODE_FULL_STOP 0x49
#endif

#if !defined(KB_SCAN_CODE_SEMI_COLON)
#define KB_SCAN_CODE_SEMI_COLON 0x4C
#endif

#if !defined(KB_SCAN_CODE_BACK_SLASH)
#define KB_SCAN_CODE_BACK_SLASH 0x4A
#endif

#if !defined(KB_SCAN_CODE_SINGLE_QUOTES)
#define KB_SCAN_CODE_SINGLE_QUOTES 0x52
#endif

#if !defined(KB_SCAN_CODE_FORWARD_SLASH)
#define KB_SCAN_CODE_FORWARD_SLASH 0x5D
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_F1)
#define KB_SCAN_CODE_F1 0x05
#endif

#if !defined(KB_SCAN_CODE_F2)
#define KB_SCAN_CODE_F2 0x06
#endif

#if !defined(KB_SCAN_CODE_F3)
#define KB_SCAN_CODE_F3 0x04
#endif

#if !defined(KB_SCAN_CODE_F4)
#define KB_SCAN_CODE_F4 0x0C
#endif

#if !defined(KB_SCAN_CODE_F5)
#define KB_SCAN_CODE_F5 0x03
#endif

#if !defined(KB_SCAN_CODE_F6)
#define KB_SCAN_CODE_F6 0x0B
#endif

#if !defined(KB_SCAN_CODE_F7)
#define KB_SCAN_CODE_F7 0x83
#endif

#if !defined(KB_SCAN_CODE_F8)
#define KB_SCAN_CODE_F8 0x0A
#endif

#if !defined(KB_SCAN_CODE_F9)
#define KB_SCAN_CODE_F9 0x01
#endif

#if !defined(KB_SCAN_CODE_F10)
#define KB_SCAN_CODE_F10 0x09
#endif

#if !defined(KB_SCAN_CODE_F11)
#define KB_SCAN_CODE_F11 0x78
#endif

#if !defined(KB_SCAN_CODE_F12)
#define KB_SCAN_CODE_F12 0x07
#endif

/******************************************************************************************************/

#if !defined(KB_SCAN_CODE_KEYPAD_0)
#define KB_SCAN_CODE_KEYPAD_0 0x70
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_1)
#define KB_SCAN_CODE_KEYPAD_1 0x69
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_2)
#define KB_SCAN_CODE_KEYPAD_2 0x72
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_3)
#define KB_SCAN_CODE_KEYPAD_3 0x7A
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_4)
#define KB_SCAN_CODE_KEYPAD_4 0x6B
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_5)
#define KB_SCAN_CODE_KEYPAD_5 0x73
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_6)
#define KB_SCAN_CODE_KEYPAD_6 0x74
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_7)
#define KB_SCAN_CODE_KEYPAD_7 0x6C
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_8)
#define KB_SCAN_CODE_KEYPAD_8 0x75
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_9)
#define KB_SCAN_CODE_KEYPAD_9 0x7D
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_DOT)
#define KB_SCAN_CODE_KEYPAD_DOT 0x71
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_BACKSLASH)
#define KB_SCAN_CODE_KEYPAD_BACKSLASH 0x4A
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_ASTERIK)
#define KB_SCAN_CODE_KEYPAD_ASTERIK 0x7C
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_MINUS)
#define KB_SCAN_CODE_KEYPAD_MINUS 0x7B
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_PLUS)
#define KB_SCAN_CODE_KEYPAD_PLUS 0x79
#endif

#if !defined(KB_SCAN_CODE_KEYPAD_ENTER)
#define KB_SCAN_CODE_KEYPAD_ENTER 0x5A
#endif

/******************************************************************************************************/
//KEYBOARD SINGLE KEY PRESS
/******************************************************************************************************/

#if !defined(KB_SPACE)
#define KB_SPACE ASCII_VALUE_OF_SPACE
#endif

#if !defined(KB_ENTER)
#define KB_ENTER ASCII_VALUE_OF_ENTER
#endif

#if !defined(KB_BACKSPACE)
#define KB_BACKSPACE ASCII_VALUE_OF_BACKSPACE
#endif

#if !defined(KB_INSERT)
#define KB_INSERT 0x80
#endif

#if !defined(KB_DELETE)
#define KB_DELETE ASCII_VALUE_OF_DELETE
#endif

#if !defined(KB_ESCAPE)
#define KB_ESCAPE ASCII_VALUE_OF_ESCAPE
#endif

#if !defined(KB_HOME)
#define KB_HOME 0x81
#endif

#if !defined(KB_END)
#define KB_END 0x9F
#endif

#if !defined(KB_PAGE_DOWN)
#define KB_PAGE_DOWN 0xA0
#endif

#if !defined(KB_PAGE_UP)
#define KB_PAGE_UP 0x82
#endif

#if !defined(KB_PRINT_SCREEN)
#define KB_PRINT_SCREEN 0x83
#endif

#if !defined(KB_TAB)
#define KB_TAB ASCII_VALUE_OF_TAB
#endif

#if !defined(KB_APPS)
#define KB_APPS KB_NOT_USED
#endif

#if !defined(KB_PAUSE)
#define KB_PAUSE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_POWER)
#define KB_POWER KB_NOT_USED
#endif

#if !defined(KB_SLEEP)
#define KB_SLEEP KB_NOT_USED
#endif

#if !defined(KB_WAKE)
#define KB_WAKE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_NEXT_TRACK)
#define KB_NEXT_TRACK KB_NOT_USED
#endif

#if !defined(KB_PREVIOUS_TRACK)
#define KB_PREVIOUS_TRACK KB_NOT_USED
#endif

#if !defined(KB_STOP)
#define KB_STOP KB_NOT_USED
#endif

#if !defined(KB_PLAY_OR_PAUSE)
#define KB_PLAY_OR_PAUSE KB_NOT_USED
#endif

#if !defined(KB_MUTE)
#define KB_MUTE KB_NOT_USED
#endif

#if !defined(KB_VOLUME_UP)
#define KB_VOLUME_UP KB_NOT_USED
#endif

#if !defined(KB_VOLUME_DOWN)
#define KB_VOLUME_DOWN KB_NOT_USED
#endif

#if !defined(KB_MEDIA_SELECT)
#define KB_MEDIA_SELECT KB_NOT_USED
#endif

#if !defined(KB_E_MAIL)
#define KB_E_MAIL KB_NOT_USED
#endif

#if !defined(KB_CALCULATOR)
#define KB_CALCULATOR KB_NOT_USED
#endif

#if !defined(KB_COMPUTER)
#define KB_COMPUTER KB_NOT_USED
#endif

#if !defined(KB_WWW_SEARCH)
#define KB_WWW_SEARCH KB_NOT_USED
#endif

#if !defined(KB_WWW_HOME)
#define KB_WWW_HOME KB_NOT_USED
#endif

#if !defined(KB_WWW_BACK)
#define KB_WWW_BACK KB_NOT_USED
#endif

#if !defined(KB_WWW_FORWARD)
#define KB_WWW_FORWARD KB_NOT_USED
#endif

#if !defined(KB_WWW_STOP)
#define KB_WWW_STOP KB_NOT_USED
#endif

#if !defined(KB_WWW_REFRESH)
#define KB_WWW_REFRESH KB_NOT_USED
#endif

#if !defined(KB_WWW_FAVORITES)
#define KB_WWW_FAVORITES KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_LEFT_SHIFT)
#define KB_LEFT_SHIFT 0x84
#endif

#if !defined(KB_LEFT_CONTROL)
#define KB_LEFT_CONTROL 0x85
#endif

#if !defined(KB_LEFT_ALTERNATE)
#define KB_LEFT_ALTERNATE 0x86
#endif

#if !defined(KB_LEFT_GUI)
#define KB_LEFT_GUI 0x00
#endif

/******************************************************************************************************/

#if !defined(KB_RIGHT_SHIFT)
#define KB_RIGHT_SHIFT 0x88
#endif

#if !defined(KB_RIGHT_CONTROL)
#define KB_RIGHT_CONTROL 0x89
#endif

#if !defined(KB_RIGHT_ALTERNATE)
#define KB_RIGHT_ALTERNATE 0x8A
#endif

#if !defined(KB_RIGHT_GUI)
#define KB_RIGHT_GUI 0x8B
#endif

/******************************************************************************************************/

#if !defined(KB_CAPS_LOCK)
#define KB_CAPS_LOCK 0x8C
#endif

#if !defined(KB_NUMBER_LOCK)
#define KB_NUMBER_LOCK 0x8D
#endif

#if !defined(KB_SCROLL_LOCK)
#define KB_SCROLL_LOCK 0x8E
#endif

/******************************************************************************************************/

#if !defined(KB_ARROW_UP)
#define KB_ARROW_UP 0x8F
#endif

#if !defined(KB_ARROW_DOWN)
#define KB_ARROW_DOWN 0x90
#endif

#if !defined(KB_ARROW_LEFT)
#define KB_ARROW_LEFT 0x91
#endif

#if !defined(KB_ARROW_RIGHT)
#define KB_ARROW_RIGHT 0x92
#endif

/******************************************************************************************************/

#if !defined(KB_0)
#define KB_0 ASCII_VALUE_OF_0
#endif

#if !defined(KB_1)
#define KB_1 ASCII_VALUE_OF_1
#endif

#if !defined(KB_2)
#define KB_2 ASCII_VALUE_OF_2
#endif

#if !defined(KB_3)
#define KB_3 ASCII_VALUE_OF_3
#endif

#if !defined(KB_4)
#define KB_4 ASCII_VALUE_OF_4
#endif

#if !defined(KB_5)
#define KB_5 ASCII_VALUE_OF_5
#endif

#if !defined(KB_6)
#define KB_6 ASCII_VALUE_OF_6
#endif

#if !defined(KB_7)
#define KB_7 ASCII_VALUE_OF_7
#endif

#if !defined(KB_8)
#define KB_8 ASCII_VALUE_OF_8
#endif

#if !defined(KB_9)
#define KB_9 ASCII_VALUE_OF_9
#endif

/******************************************************************************************************/

#if !defined(KB_A)
#define KB_A ASCII_VALUE_OF_LOWER_CASE_A
#endif

#if !defined(KB_B)
#define KB_B ASCII_VALUE_OF_LOWER_CASE_B
#endif

#if !defined(KB_C)
#define KB_C ASCII_VALUE_OF_LOWER_CASE_C
#endif

#if !defined(KB_D)
#define KB_D ASCII_VALUE_OF_LOWER_CASE_D
#endif

#if !defined(KB_E)
#define KB_E ASCII_VALUE_OF_LOWER_CASE_E
#endif

#if !defined(KB_F)
#define KB_F ASCII_VALUE_OF_LOWER_CASE_F
#endif

#if !defined(KB_G)
#define KB_G ASCII_VALUE_OF_LOWER_CASE_G
#endif

#if !defined(KB_H)
#define KB_H ASCII_VALUE_OF_LOWER_CASE_H
#endif

#if !defined(KB_I)
#define KB_I ASCII_VALUE_OF_LOWER_CASE_I
#endif

#if !defined(KB_J)
#define KB_J ASCII_VALUE_OF_LOWER_CASE_J
#endif

#if !defined(KB_K)
#define KB_K ASCII_VALUE_OF_LOWER_CASE_K
#endif

#if !defined(KB_L)
#define KB_L ASCII_VALUE_OF_LOWER_CASE_L
#endif

#if !defined(KB_M)
#define KB_M ASCII_VALUE_OF_LOWER_CASE_M
#endif

#if !defined(KB_N)
#define KB_N ASCII_VALUE_OF_LOWER_CASE_N
#endif

#if !defined(KB_O)
#define KB_O ASCII_VALUE_OF_LOWER_CASE_O
#endif

#if !defined(KB_P)
#define KB_P ASCII_VALUE_OF_LOWER_CASE_P
#endif

#if !defined(KB_Q)
#define KB_Q ASCII_VALUE_OF_LOWER_CASE_Q
#endif

#if !defined(KB_R)
#define KB_R ASCII_VALUE_OF_LOWER_CASE_R
#endif

#if !defined(KB_S)
#define KB_S ASCII_VALUE_OF_LOWER_CASE_S
#endif

#if !defined(KB_T)
#define KB_T ASCII_VALUE_OF_LOWER_CASE_T
#endif

#if !defined(KB_U)
#define KB_U ASCII_VALUE_OF_LOWER_CASE_U
#endif

#if !defined(KB_V)
#define KB_V ASCII_VALUE_OF_LOWER_CASE_V
#endif

#if !defined(KB_W)
#define KB_W ASCII_VALUE_OF_LOWER_CASE_W
#endif

#if !defined(KB_X)
#define KB_X ASCII_VALUE_OF_LOWER_CASE_X
#endif

#if !defined(KB_Y)
#define KB_Y ASCII_VALUE_OF_LOWER_CASE_Y
#endif

#if !defined(KB_Z)
#define KB_Z ASCII_VALUE_OF_LOWER_CASE_Z
#endif

/******************************************************************************************************/

#if !defined(KB_APOSTROPHE)
#define KB_APOSTROPHE ASCII_VALUE_OF_APOSTROPHE
#endif

#if !defined(KB_MINUS)
#define KB_MINUS ASCII_VALUE_OF_MINUS
#endif

#if !defined(KB_EQUAL_TO)
#define KB_EQUAL_TO ASCII_VALUE_OF_EQUAL_TO
#endif

#if !defined(KB_LEFT_BRACKET)
#define KB_LEFT_BRACKET ASCII_VALUE_OF_LEFT_BRACKET
#endif

#if !defined(KB_RIGHT_BRACKET)
#define KB_RIGHT_BRACKET ASCII_VALUE_OF_RIGHT_BRACKET
#endif

#if !defined(KB_COMMA)
#define KB_COMMA ASCII_VALUE_OF_COMMA
#endif

#if !defined(KB_FULL_STOP)
#define KB_FULL_STOP ASCII_VALUE_OF_FULL_STOP
#endif

#if !defined(KB_SEMI_COLON)
#define KB_SEMI_COLON ASCII_VALUE_OF_SEMI_COLON
#endif

#if !defined(KB_BACK_SLASH)
#define KB_BACK_SLASH ASCII_VALUE_OF_BACKSLASH
#endif

#if !defined(KB_SINGLE_QUOTES)
#define KB_SINGLE_QUOTES ASCII_VALUE_OF_SINGLE_QUOTES
#endif

#if !defined(KB_FORWARD_SLASH)
#define KB_FORWARD_SLASH ASCII_VALUE_OF_FORWARDSLASH
#endif

/******************************************************************************************************/

#if !defined(KB_F1)
#define KB_F1 0x93
#endif

#if !defined(KB_F2)
#define KB_F2 0x94
#endif

#if !defined(KB_F3)
#define KB_F3 0x95
#endif

#if !defined(KB_F4)
#define KB_F4 0x96
#endif

#if !defined(KB_F5)
#define KB_F5 0x97
#endif

#if !defined(KB_F6)
#define KB_F6 0x98
#endif

#if !defined(KB_F7)
#define KB_F7 0x99
#endif

#if !defined(KB_F8)
#define KB_F8 0x9A
#endif

#if !defined(KB_F9)
#define KB_F9 0x9B
#endif

#if !defined(KB_F10)
#define KB_F10 0x9C
#endif

#if !defined(KB_F11)
#define KB_F11 0x9D
#endif

#if !defined(KB_F12)
#define KB_F12 0x9E
#endif

/******************************************************************************************************/

#if !defined(KB_KEYPAD_0)
#define KB_KEYPAD_0 ASCII_VALUE_OF_0
#endif

#if !defined(KB_KEYPAD_1)
#define KB_KEYPAD_1 ASCII_VALUE_OF_1
#endif

#if !defined(KB_KEYPAD_2)
#define KB_KEYPAD_2 ASCII_VALUE_OF_2
#endif

#if !defined(KB_KEYPAD_3)
#define KB_KEYPAD_3 ASCII_VALUE_OF_3
#endif

#if !defined(KB_KEYPAD_4)
#define KB_KEYPAD_4 ASCII_VALUE_OF_4
#endif

#if !defined(KB_KEYPAD_5)
#define KB_KEYPAD_5 ASCII_VALUE_OF_5
#endif

#if !defined(KB_KEYPAD_6)
#define KB_KEYPAD_6 ASCII_VALUE_OF_6
#endif

#if !defined(KB_KEYPAD_7)
#define KB_KEYPAD_7 ASCII_VALUE_OF_7
#endif

#if !defined(KB_KEYPAD_8)
#define KB_KEYPAD_8 ASCII_VALUE_OF_8
#endif

#if !defined(KB_KEYPAD_9)
#define KB_KEYPAD_9 ASCII_VALUE_OF_9
#endif

#if !defined(KB_KEYPAD_DOT)
#define KB_KEYPAD_DOT ASCII_VALUE_OF_FULL_STOP
#endif

#if !defined(KB_KEYPAD_BACKSLASH)
#define KB_KEYPAD_BACKSLASH ASCII_VALUE_OF_BACKSLASH
#endif

#if !defined(KB_KEYPAD_ASTERIK)
#define KB_KEYPAD_ASTERIK ASCII_VALUE_OF_ASTERIK
#endif

#if !defined(KB_KEYPAD_MINUS)
#define KB_KEYPAD_MINUS ASCII_VALUE_OF_MINUS
#endif

#if !defined(KB_KEYPAD_PLUS)
#define KB_KEYPAD_PLUS ASCII_VALUE_OF_PLUS
#endif

#if !defined(KB_KEYPAD_ENTER)
#define KB_KEYPAD_ENTER ASCII_VALUE_OF_ENTER
#endif

/******************************************************************************************************/
//SHIFT+KEY COMBINATIONS
/******************************************************************************************************/

#if !defined(KB_SHIFT_SPACE)
#define KB_SHIFT_SPACE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_ENTER)
#define KB_SHIFT_ENTER KB_NOT_USED
#endif

#if !defined(KB_SHIFT_BACKSPACE)
#define KB_SHIFT_BACKSPACE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_INSERT)
#define KB_SHIFT_INSERT KB_NOT_USED
#endif

#if !defined(KB_SHIFT_DELETE)
#define KB_SHIFT_DELETE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_ESCAPE)
#define KB_SHIFT_ESCAPE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_HOME)
#define KB_SHIFT_HOME KB_NOT_USED
#endif

#if !defined(KB_SHIFT_END)
#define KB_SHIFT_END KB_NOT_USED
#endif

#if !defined(KB_SHIFT_PAGE_DOWN)
#define KB_SHIFT_PAGE_DOWN KB_NOT_USED
#endif

#if !defined(KB_SHIFT_PAGE_UP)
#define KB_SHIFT_PAGE_UP KB_NOT_USED
#endif

#if !defined(KB_SHIFT_PRINT_SCREEN)
#define KB_SHIFT_PRINT_SCREEN KB_NOT_USED
#endif

#if !defined(KB_SHIFT_TAB)
#define KB_SHIFT_TAB KB_NOT_USED
#endif

#if !defined(KB_SHIFT_APPS)
#define KB_SHIFT_APPS KB_NOT_USED
#endif

#if !defined(KB_SHIFT_PAUSE)
#define KB_SHIFT_PAUSE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_POWER)
#define KB_SHIFT_POWER KB_NOT_USED
#endif

#if !defined(KB_SHIFT_SLEEP)
#define KB_SHIFT_SLEEP KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WAKE)
#define KB_SHIFT_WAKE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_NEXT_TRACK)
#define KB_SHIFT_NEXT_TRACK KB_NOT_USED
#endif

#if !defined(KB_SHIFT_PREVIOUS_TRACK)
#define KB_SHIFT_PREVIOUS_TRACK KB_NOT_USED
#endif

#if !defined(KB_SHIFT_STOP)
#define KB_SHIFT_STOP KB_NOT_USED
#endif

#if !defined(KB_SHIFT_PLAY_OR_PAUSE)
#define KB_SHIFT_PLAY_OR_PAUSE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_MUTE)
#define KB_SHIFT_MUTE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_VOLUME_UP)
#define KB_SHIFT_VOLUME_UP KB_NOT_USED
#endif

#if !defined(KB_SHIFT_VOLUME_DOWN)
#define KB_SHIFT_VOLUME_DOWN KB_NOT_USED
#endif

#if !defined(KB_SHIFT_MEDIA_SELECT)
#define KB_SHIFT_MEDIA_SELECT KB_NOT_USED
#endif

#if !defined(KB_SHIFT_E_MAIL)
#define KB_SHIFT_E_MAIL KB_NOT_USED
#endif

#if !defined(KB_SHIFT_CALCULATOR)
#define KB_SHIFT_CALCULATOR KB_NOT_USED
#endif

#if !defined(KB_SHIFT_COMPUTER)
#define KB_SHIFT_COMPUTER KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_SEARCH)
#define KB_SHIFT_WWW_SEARCH KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_HOME)
#define KB_SHIFT_WWW_HOME KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_BACK)
#define KB_SHIFT_WWW_BACK KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_FORWARD)
#define KB_SHIFT_WWW_FORWARD KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_STOP)
#define KB_SHIFT_WWW_STOP KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_REFRESH)
#define KB_SHIFT_WWW_REFRESH KB_NOT_USED
#endif

#if !defined(KB_SHIFT_WWW_FAVORITES)
#define KB_SHIFT_WWW_FAVORITES KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_LEFT_SHIFT)
#define KB_SHIFT_LEFT_SHIFT KB_NOT_USED
#endif

#if !defined(KB_SHIFT_LEFT_CONTROL)
#define KB_SHIFT_LEFT_CONTROL KB_NOT_USED
#endif

#if !defined(KB_SHIFT_LEFT_ALTERNATE)
#define KB_SHIFT_LEFT_ALTERNATE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_LEFT_GUI)
#define KB_SHIFT_LEFT_GUI KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_RIGHT_SHIFT)
#define KB_SHIFT_RIGHT_SHIFT KB_NOT_USED
#endif

#if !defined(KB_SHIFT_RIGHT_CONTROL)
#define KB_SHIFT_RIGHT_CONTROL KB_NOT_USED
#endif

#if !defined(KB_SHIFT_RIGHT_ALTERNATE)
#define KB_SHIFT_RIGHT_ALTERNATE KB_NOT_USED
#endif

#if !defined(KB_SHIFT_RIGHT_GUI)
#define KB_SHIFT_RIGHT_GUI KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_CAPS_LOCK)
#define KB_SHIFT_CAPS_LOCK KB_NOT_USED
#endif

#if !defined(KB_SHIFT_NUMBER_LOCK)
#define KB_SHIFT_NUMBER_LOCK KB_NOT_USED
#endif

#if !defined(KB_SHIFT_SCROLL_LOCK)
#define KB_SHIFT_SCROLL_LOCK KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_ARROW_UP)
#define KB_SHIFT_ARROW_UP KB_NOT_USED
#endif

#if !defined(KB_SHIFT_ARROW_DOWN)
#define KB_SHIFT_ARROW_DOWN KB_NOT_USED
#endif

#if !defined(KB_SHIFT_ARROW_LEFT)
#define KB_SHIFT_ARROW_LEFT KB_NOT_USED
#endif

#if !defined(KB_SHIFT_ARROW_RIGHT)
#define KB_SHIFT_ARROW_RIGHT KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_0)
#define KB_SHIFT_0 ASCII_VALUE_OF_RIGHT_PARENTHESIS
#endif

#if !defined(KB_SHIFT_1)
#define KB_SHIFT_1 ASCII_VALUE_OF_EXCLAIMATION_MARK
#endif

#if !defined(KB_SHIFT_2)
#define KB_SHIFT_2 ASCII_VALUE_OF_AT_THE_RATE
#endif

#if !defined(KB_SHIFT_3)
#define KB_SHIFT_3 ASCII_VALUE_OF_HASH
#endif

#if !defined(KB_SHIFT_4)
#define KB_SHIFT_4 ASCII_VALUE_OF_DOLLAR
#endif

#if !defined(KB_SHIFT_5)
#define KB_SHIFT_5 ASCII_VALUE_OF_PERCENTAGE
#endif

#if !defined(KB_SHIFT_6)
#define KB_SHIFT_6 ASCII_VALUE_OF_RAISED_TO
#endif

#if !defined(KB_SHIFT_7)
#define KB_SHIFT_7 ASCII_VALUE_OF_APPRESAND
#endif

#if !defined(KB_SHIFT_8)
#define KB_SHIFT_8 ASCII_VALUE_OF_ASTERIK
#endif

#if !defined(KB_SHIFT_9)
#define KB_SHIFT_9 ASCII_VALUE_OF_LEFT_PARENTHESIS
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_A)
#define KB_SHIFT_A ASCII_VALUE_OF_UPPER_CASE_A
#endif

#if !defined(KB_SHIFT_B)
#define KB_SHIFT_B ASCII_VALUE_OF_UPPER_CASE_B
#endif

#if !defined(KB_SHIFT_C)
#define KB_SHIFT_C ASCII_VALUE_OF_UPPER_CASE_C
#endif

#if !defined(KB_SHIFT_D)
#define KB_SHIFT_D ASCII_VALUE_OF_UPPER_CASE_D
#endif

#if !defined(KB_SHIFT_E)
#define KB_SHIFT_E ASCII_VALUE_OF_UPPER_CASE_E
#endif

#if !defined(KB_SHIFT_F)
#define KB_SHIFT_F ASCII_VALUE_OF_UPPER_CASE_F
#endif

#if !defined(KB_SHIFT_G)
#define KB_SHIFT_G ASCII_VALUE_OF_UPPER_CASE_G
#endif

#if !defined(KB_SHIFT_H)
#define KB_SHIFT_H ASCII_VALUE_OF_UPPER_CASE_H
#endif

#if !defined(KB_SHIFT_I)
#define KB_SHIFT_I ASCII_VALUE_OF_UPPER_CASE_I
#endif

#if !defined(KB_SHIFT_J)
#define KB_SHIFT_J ASCII_VALUE_OF_UPPER_CASE_J
#endif

#if !defined(KB_SHIFT_K)
#define KB_SHIFT_K ASCII_VALUE_OF_UPPER_CASE_K
#endif

#if !defined(KB_SHIFT_L)
#define KB_SHIFT_L ASCII_VALUE_OF_UPPER_CASE_L
#endif

#if !defined(KB_SHIFT_M)
#define KB_SHIFT_M ASCII_VALUE_OF_UPPER_CASE_M
#endif

#if !defined(KB_SHIFT_N)
#define KB_SHIFT_N ASCII_VALUE_OF_UPPER_CASE_N
#endif

#if !defined(KB_SHIFT_O)
#define KB_SHIFT_O ASCII_VALUE_OF_UPPER_CASE_O
#endif

#if !defined(KB_SHIFT_P)
#define KB_SHIFT_P ASCII_VALUE_OF_UPPER_CASE_P
#endif

#if !defined(KB_SHIFT_Q)
#define KB_SHIFT_Q ASCII_VALUE_OF_UPPER_CASE_Q
#endif

#if !defined(KB_SHIFT_R)
#define KB_SHIFT_R ASCII_VALUE_OF_UPPER_CASE_R
#endif

#if !defined(KB_SHIFT_S)
#define KB_SHIFT_S ASCII_VALUE_OF_UPPER_CASE_S
#endif

#if !defined(KB_SHIFT_T)
#define KB_SHIFT_T ASCII_VALUE_OF_UPPER_CASE_T
#endif

#if !defined(KB_SHIFT_U)
#define KB_SHIFT_U ASCII_VALUE_OF_UPPER_CASE_U
#endif

#if !defined(KB_SHIFT_V)
#define KB_SHIFT_V ASCII_VALUE_OF_UPPER_CASE_V
#endif

#if !defined(KB_SHIFT_W)
#define KB_SHIFT_W ASCII_VALUE_OF_UPPER_CASE_W
#endif

#if !defined(KB_SHIFT_X)
#define KB_SHIFT_X ASCII_VALUE_OF_UPPER_CASE_X
#endif

#if !defined(KB_SHIFT_Y)
#define KB_SHIFT_Y ASCII_VALUE_OF_UPPER_CASE_Y
#endif

#if !defined(KB_SHIFT_Z)
#define KB_SHIFT_Z ASCII_VALUE_OF_UPPER_CASE_Z
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_APOSTROPHE)
#define KB_SHIFT_APOSTROPHE ASCII_VALUE_OF_TILTDA
#endif

#if !defined(KB_SHIFT_MINUS)
#define KB_SHIFT_MINUS ASCII_VALUE_OF_UNDERSCORE
#endif

#if !defined(KB_SHIFT_EQUAL_TO)
#define KB_SHIFT_EQUAL_TO ASCII_VALUE_OF_PLUS
#endif

#if !defined(KB_SHIFT_LEFT_BRACKET)
#define KB_SHIFT_LEFT_BRACKET ASCII_VALUE_OF_LEFT_BRACE
#endif

#if !defined(KB_SHIFT_RIGHT_BRACKET)
#define KB_SHIFT_RIGHT_BRACKET ASCII_VALUE_OF_RIGHT_BRACE
#endif

#if !defined(KB_SHIFT_COMMA)
#define KB_SHIFT_COMMA ASCII_VALUE_OF_LESS_THAN
#endif

#if !defined(KB_SHIFT_FULL_STOP)
#define KB_SHIFT_FULL_STOP ASCII_VALUE_OF_GREATER_THAN
#endif

#if !defined(KB_SHIFT_SEMI_COLON)
#define KB_SHIFT_SEMI_COLON ASCII_VALUE_OF_COLON
#endif

#if !defined(KB_SHIFT_BACK_SLASH)
#define KB_SHIFT_BACK_SLASH ASCII_VALUE_OF_QUESTION_MARK
#endif

#if !defined(KB_SHIFT_SINGLE_QUOTES)
#define KB_SHIFT_SINGLE_QUOTES ASCII_VALUE_OF_DOUBLE_QUOTES
#endif

#if !defined(KB_SHIFT_FORWARD_SLASH)
#define KB_SHIFT_FORWARD_SLASH ASCII_VALUE_OF_OR
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_F1)
#define KB_SHIFT_F1 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F2)
#define KB_SHIFT_F2 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F3)
#define KB_SHIFT_F3 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F4)
#define KB_SHIFT_F4 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F5)
#define KB_SHIFT_F5 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F6)
#define KB_SHIFT_F6 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F7)
#define KB_SHIFT_F7 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F8)
#define KB_SHIFT_F8 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F9)
#define KB_SHIFT_F9 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F10)
#define KB_SHIFT_F10 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F11)
#define KB_SHIFT_F11 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_F12)
#define KB_SHIFT_F12 KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_SHIFT_KEYPAD_0)
#define KB_SHIFT_KEYPAD_0 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_KEYPAD_1)
#define KB_SHIFT_KEYPAD_1 KB_END
#endif

#if !defined(KB_SHIFT_KEYPAD_2)
#define KB_SHIFT_KEYPAD_2 KB_ARROW_DOWN
#endif

#if !defined(KB_SHIFT_KEYPAD_3)
#define KB_SHIFT_KEYPAD_3 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_KEYPAD_4)
#define KB_SHIFT_KEYPAD_4 KB_ARROW_LEFT
#endif

#if !defined(KB_SHIFT_KEYPAD_5)
#define KB_SHIFT_KEYPAD_5 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_KEYPAD_6)
#define KB_SHIFT_KEYPAD_6 KB_ARROW_RIGHT
#endif

#if !defined(KB_SHIFT_KEYPAD_7)
#define KB_SHIFT_KEYPAD_7 KB_HOME
#endif

#if !defined(KB_SHIFT_KEYPAD_8)
#define KB_SHIFT_KEYPAD_8 KB_ARROW_UP
#endif

#if !defined(KB_SHIFT_KEYPAD_9)
#define KB_SHIFT_KEYPAD_9 KB_NOT_USED
#endif

#if !defined(KB_SHIFT_KEYPAD_DOT)
#define KB_SHIFT_KEYPAD_DOT ASCII_VALUE_OF_DELETE
#endif

#if !defined(KB_SHIFT_KEYPAD_BACKSLASH)
#define KB_SHIFT_KEYPAD_BACKSLASH ASCII_VALUE_OF_BACKSLASH
#endif

#if !defined(KB_SHIFT_KEYPAD_ASTERIK)
#define KB_SHIFT_KEYPAD_ASTERIK ASCII_VALUE_OF_ASTERIK
#endif

#if !defined(KB_SHIFT_KEYPAD_MINUS)
#define KB_SHIFT_KEYPAD_MINUS ASCII_VALUE_OF_MINUS
#endif

#if !defined(KB_SHIFT_KEYPAD_PLUS)
#define KB_SHIFT_KEYPAD_PLUS ASCII_VALUE_OF_PLUS
#endif

#if !defined(KB_SHIFT_KEYPAD_ENTER)
#define KB_SHIFT_KEYPAD_ENTER ASCII_VALUE_OF_ENTER
#endif

/******************************************************************************************************/
//CONTROL+KEY COMBINATIONS
/******************************************************************************************************/

#if !defined(KB_CONTROL_SPACE)
#define KB_CONTROL_SPACE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_ENTER)
#define KB_CONTROL_ENTER KB_NOT_USED
#endif

#if !defined(KB_CONTROL_BACKSPACE)
#define KB_CONTROL_BACKSPACE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_INSERT)
#define KB_CONTROL_INSERT KB_NOT_USED
#endif

#if !defined(KB_CONTROL_DELETE)
#define KB_CONTROL_DELETE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_ESCAPE)
#define KB_CONTROL_ESCAPE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_HOME)
#define KB_CONTROL_HOME KB_NOT_USED
#endif

#if !defined(KB_CONTROL_END)
#define KB_CONTROL_END KB_NOT_USED
#endif

#if !defined(KB_CONTROL_PAGE_DOWN)
#define KB_CONTROL_PAGE_DOWN KB_NOT_USED
#endif

#if !defined(KB_CONTROL_PAGE_UP)
#define KB_CONTROL_PAGE_UP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_PRINT_SCREEN)
#define KB_CONTROL_PRINT_SCREEN KB_NOT_USED
#endif

#if !defined(KB_CONTROL_TAB)
#define KB_CONTROL_TAB KB_NOT_USED
#endif

#if !defined(KB_CONTROL_APPS)
#define KB_CONTROL_APPS KB_NOT_USED
#endif

#if !defined(KB_CONTROL_PAUSE)
#define KB_CONTROL_PAUSE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_POWER)
#define KB_CONTROL_POWER KB_NOT_USED
#endif

#if !defined(KB_CONTROL_SLEEP)
#define KB_CONTROL_SLEEP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WAKE)
#define KB_CONTROL_WAKE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_NEXT_TRACK)
#define KB_CONTROL_NEXT_TRACK KB_NOT_USED
#endif

#if !defined(KB_CONTROL_PREVIOUS_TRACK)
#define KB_CONTROL_PREVIOUS_TRACK KB_NOT_USED
#endif

#if !defined(KB_CONTROL_STOP)
#define KB_CONTROL_STOP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_PLAY_OR_PAUSE)
#define KB_CONTROL_PLAY_OR_PAUSE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_MUTE)
#define KB_CONTROL_MUTE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_VOLUME_UP)
#define KB_CONTROL_VOLUME_UP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_VOLUME_DOWN)
#define KB_CONTROL_VOLUME_DOWN KB_NOT_USED
#endif

#if !defined(KB_CONTROL_MEDIA_SELECT)
#define KB_CONTROL_MEDIA_SELECT KB_NOT_USED
#endif

#if !defined(KB_CONTROL_E_MAIL)
#define KB_CONTROL_E_MAIL KB_NOT_USED
#endif

#if !defined(KB_CONTROL_CALCULATOR)
#define KB_CONTROL_CALCULATOR KB_NOT_USED
#endif

#if !defined(KB_CONTROL_COMPUTER)
#define KB_CONTROL_COMPUTER KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_SEARCH)
#define KB_CONTROL_WWW_SEARCH KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_HOME)
#define KB_CONTROL_WWW_HOME KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_BACK)
#define KB_CONTROL_WWW_BACK KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_FORWARD)
#define KB_CONTROL_WWW_FORWARD KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_STOP)
#define KB_CONTROL_WWW_STOP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_REFRESH)
#define KB_CONTROL_WWW_REFRESH KB_NOT_USED
#endif

#if !defined(KB_CONTROL_WWW_FAVORITES)
#define KB_CONTROL_WWW_FAVORITES KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_LEFT_SHIFT)
#define KB_CONTROL_LEFT_SHIFT KB_NOT_USED
#endif

#if !defined(KB_CONTROL_LEFT_CONTROL)
#define KB_CONTROL_LEFT_CONTROL KB_NOT_USED
#endif

#if !defined(KB_CONTROL_LEFT_ALTERNATE)
#define KB_CONTROL_LEFT_ALTERNATE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_LEFT_GUI)
#define KB_CONTROL_LEFT_GUI KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_RIGHT_SHIFT)
#define KB_CONTROL_RIGHT_SHIFT KB_NOT_USED
#endif

#if !defined(KB_CONTROL_RIGHT_CONTROL)
#define KB_CONTROL_RIGHT_CONTROL KB_NOT_USED
#endif

#if !defined(KB_CONTROL_RIGHT_ALTERNATE)
#define KB_CONTROL_RIGHT_ALTERNATE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_RIGHT_GUI)
#define KB_CONTROL_RIGHT_GUI KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_CAPS_LOCK)
#define KB_CONTROL_CAPS_LOCK KB_NOT_USED
#endif

#if !defined(KB_CONTROL_NUMBER_LOCK)
#define KB_CONTROL_NUMBER_LOCK KB_NOT_USED
#endif

#if !defined(KB_CONTROL_SCROLL_LOCK)
#define KB_CONTROL_SCROLL_LOCK KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_ARROW_UP)
#define KB_CONTROL_ARROW_UP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_ARROW_DOWN)
#define KB_CONTROL_ARROW_DOWN KB_NOT_USED
#endif

#if !defined(KB_CONTROL_ARROW_LEFT)
#define KB_CONTROL_ARROW_LEFT KB_NOT_USED
#endif

#if !defined(KB_CONTROL_ARROW_RIGHT)
#define KB_CONTROL_ARROW_RIGHT KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_0)
#define KB_CONTROL_0 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_1)
#define KB_CONTROL_1 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_2)
#define KB_CONTROL_2 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_3)
#define KB_CONTROL_3 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_4)
#define KB_CONTROL_4 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_5)
#define KB_CONTROL_5 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_6)
#define KB_CONTROL_6 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_7)
#define KB_CONTROL_7 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_8)
#define KB_CONTROL_8 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_9)
#define KB_CONTROL_9 KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_A)
#define KB_CONTROL_A KB_NOT_USED
#endif

#if !defined(KB_CONTROL_B)
#define KB_CONTROL_B KB_NOT_USED
#endif

#if !defined(KB_CONTROL_C)
#define KB_CONTROL_C KB_NOT_USED
#endif

#if !defined(KB_CONTROL_D)
#define KB_CONTROL_D KB_NOT_USED
#endif

#if !defined(KB_CONTROL_E)
#define KB_CONTROL_E KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F)
#define KB_CONTROL_F KB_NOT_USED
#endif

#if !defined(KB_CONTROL_G)
#define KB_CONTROL_G KB_NOT_USED
#endif

#if !defined(KB_CONTROL_H)
#define KB_CONTROL_H KB_NOT_USED
#endif

#if !defined(KB_CONTROL_I)
#define KB_CONTROL_I KB_NOT_USED
#endif

#if !defined(KB_CONTROL_J)
#define KB_CONTROL_J KB_NOT_USED
#endif

#if !defined(KB_CONTROL_K)
#define KB_CONTROL_K KB_NOT_USED
#endif

#if !defined(KB_CONTROL_L)
#define KB_CONTROL_L KB_NOT_USED
#endif

#if !defined(KB_CONTROL_M)
#define KB_CONTROL_M KB_NOT_USED
#endif

#if !defined(KB_CONTROL_N)
#define KB_CONTROL_N KB_NOT_USED
#endif

#if !defined(KB_CONTROL_O)
#define KB_CONTROL_O KB_NOT_USED
#endif

#if !defined(KB_CONTROL_P)
#define KB_CONTROL_P KB_NOT_USED
#endif

#if !defined(KB_CONTROL_Q)
#define KB_CONTROL_Q KB_NOT_USED
#endif

#if !defined(KB_CONTROL_R)
#define KB_CONTROL_R KB_NOT_USED
#endif

#if !defined(KB_CONTROL_S)
#define KB_CONTROL_S KB_NOT_USED
#endif

#if !defined(KB_CONTROL_T)
#define KB_CONTROL_T KB_NOT_USED
#endif

#if !defined(KB_CONTROL_U)
#define KB_CONTROL_U KB_NOT_USED
#endif

#if !defined(KB_CONTROL_V)
#define KB_CONTROL_V KB_NOT_USED
#endif

#if !defined(KB_CONTROL_W)
#define KB_CONTROL_W KB_NOT_USED
#endif

#if !defined(KB_CONTROL_X)
#define KB_CONTROL_X KB_NOT_USED
#endif

#if !defined(KB_CONTROL_Y)
#define KB_CONTROL_Y KB_NOT_USED
#endif

#if !defined(KB_CONTROL_Z)
#define KB_CONTROL_Z KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_APOSTROPHE)
#define KB_CONTROL_APOSTROPHE KB_NOT_USED
#endif

#if !defined(KB_CONTROL_MINUS)
#define KB_CONTROL_MINUS KB_NOT_USED
#endif

#if !defined(KB_CONTROL_EQUAL_TO)
#define KB_CONTROL_EQUAL_TO KB_NOT_USED
#endif

#if !defined(KB_CONTROL_LEFT_BRACKET)
#define KB_CONTROL_LEFT_BRACKET KB_NOT_USED
#endif

#if !defined(KB_CONTROL_RIGHT_BRACKET)
#define KB_CONTROL_RIGHT_BRACKET KB_NOT_USED
#endif

#if !defined(KB_CONTROL_COMMA)
#define KB_CONTROL_COMMA KB_NOT_USED
#endif

#if !defined(KB_CONTROL_FULL_STOP)
#define KB_CONTROL_FULL_STOP KB_NOT_USED
#endif

#if !defined(KB_CONTROL_SEMI_COLON)
#define KB_CONTROL_SEMI_COLON KB_NOT_USED
#endif

#if !defined(KB_CONTROL_BACK_SLASH)
#define KB_CONTROL_BACK_SLASH KB_NOT_USED
#endif

#if !defined(KB_CONTROL_SINGLE_QUOTES)
#define KB_CONTROL_SINGLE_QUOTES KB_NOT_USED
#endif

#if !defined(KB_CONTROL_FORWARD_SLASH)
#define KB_CONTROL_FORWARD_SLASH KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_F1)
#define KB_CONTROL_F1 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F2)
#define KB_CONTROL_F2 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F3)
#define KB_CONTROL_F3 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F4)
#define KB_CONTROL_F4 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F5)
#define KB_CONTROL_F5 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F6)
#define KB_CONTROL_F6 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F7)
#define KB_CONTROL_F7 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F8)
#define KB_CONTROL_F8 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F9)
#define KB_CONTROL_F9 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F10)
#define KB_CONTROL_F10 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F11)
#define KB_CONTROL_F11 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_F12)
#define KB_CONTROL_F12 KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_CONTROL_KEYPAD_0)
#define KB_CONTROL_KEYPAD_0 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_1)
#define KB_CONTROL_KEYPAD_1 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_2)
#define KB_CONTROL_KEYPAD_2 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_3)
#define KB_CONTROL_KEYPAD_3 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_4)
#define KB_CONTROL_KEYPAD_4 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_5)
#define KB_CONTROL_KEYPAD_5 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_6)
#define KB_CONTROL_KEYPAD_6 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_7)
#define KB_CONTROL_KEYPAD_7 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_8)
#define KB_CONTROL_KEYPAD_8 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_9)
#define KB_CONTROL_KEYPAD_9 KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_DOT)
#define KB_CONTROL_KEYPAD_DOT KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_BACKSLASH)
#define KB_CONTROL_KEYPAD_BACKSLASH KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_ASTERIK)
#define KB_CONTROL_KEYPAD_ASTERIK KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_MINUS)
#define KB_CONTROL_KEYPAD_MINUS KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_PLUS)
#define KB_CONTROL_KEYPAD_PLUS KB_NOT_USED
#endif

#if !defined(KB_CONTROL_KEYPAD_ENTER)
#define KB_CONTROL_KEYPAD_ENTER KB_NOT_USED
#endif

/******************************************************************************************************/
//ALT+KEY COMBINATIONS
/******************************************************************************************************/

#if !defined(KB_ALTERNATE_SPACE)
#define KB_ALTERNATE_SPACE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_ENTER)
#define KB_ALTERNATE_ENTER KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_BACKSPACE)
#define KB_ALTERNATE_BACKSPACE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_INSERT)
#define KB_ALTERNATE_INSERT KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_DELETE)
#define KB_ALTERNATE_DELETE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_ESCAPE)
#define KB_ALTERNATE_ESCAPE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_HOME)
#define KB_ALTERNATE_HOME KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_END)
#define KB_ALTERNATE_END KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_PAGE_DOWN)
#define KB_ALTERNATE_PAGE_DOWN KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_PAGE_UP)
#define KB_ALTERNATE_PAGE_UP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_PRINT_SCREEN)
#define KB_ALTERNATE_PRINT_SCREEN KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_TAB)
#define KB_ALTERNATE_TAB KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_APPS)
#define KB_ALTERNATE_APPS KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_PAUSE)
#define KB_ALTERNATE_PAUSE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_POWER)
#define KB_ALTERNATE_POWER KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_SLEEP)
#define KB_ALTERNATE_SLEEP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WAKE)
#define KB_ALTERNATE_WAKE KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_NEXT_TRACK)
#define KB_ALTERNATE_NEXT_TRACK KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_PREVIOUS_TRACK)
#define KB_ALTERNATE_PREVIOUS_TRACK KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_STOP)
#define KB_ALTERNATE_STOP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_PLAY_OR_PAUSE)
#define KB_ALTERNATE_PLAY_OR_PAUSE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_MUTE)
#define KB_ALTERNATE_MUTE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_VOLUME_UP)
#define KB_ALTERNATE_VOLUME_UP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_VOLUME_DOWN)
#define KB_ALTERNATE_VOLUME_DOWN KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_MEDIA_SELECT)
#define KB_ALTERNATE_MEDIA_SELECT KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_E_MAIL)
#define KB_ALTERNATE_E_MAIL KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_CALCULATOR)
#define KB_ALTERNATE_CALCULATOR KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_COMPUTER)
#define KB_ALTERNATE_COMPUTER KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_SEARCH)
#define KB_ALTERNATE_WWW_SEARCH KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_HOME)
#define KB_ALTERNATE_WWW_HOME KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_BACK)
#define KB_ALTERNATE_WWW_BACK KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_FORWARD)
#define KB_ALTERNATE_WWW_FORWARD KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_STOP)
#define KB_ALTERNATE_WWW_STOP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_REFRESH)
#define KB_ALTERNATE_WWW_REFRESH KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_WWW_FAVORITES)
#define KB_ALTERNATE_WWW_FAVORITES KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_LEFT_SHIFT)
#define KB_ALTERNATE_LEFT_SHIFT KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_LEFT_CONTROL)
#define KB_ALTERNATE_LEFT_CONTROL KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_LEFT_ALTERNATE)
#define KB_ALTERNATE_LEFT_ALTERNATE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_LEFT_GUI)
#define KB_ALTERNATE_LEFT_GUI KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_RIGHT_SHIFT)
#define KB_ALTERNATE_RIGHT_SHIFT KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_RIGHT_CONTROL)
#define KB_ALTERNATE_RIGHT_CONTROL KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_RIGHT_ALTERNATE)
#define KB_ALTERNATE_RIGHT_ALTERNATE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_RIGHT_GUI)
#define KB_ALTERNATE_RIGHT_GUI KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_CAPS_LOCK)
#define KB_ALTERNATE_CAPS_LOCK KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_NUMBER_LOCK)
#define KB_ALTERNATE_NUMBER_LOCK KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_SCROLL_LOCK)
#define KB_ALTERNATE_SCROLL_LOCK KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_ARROW_UP)
#define KB_ALTERNATE_ARROW_UP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_ARROW_DOWN)
#define KB_ALTERNATE_ARROW_DOWN KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_ARROW_LEFT)
#define KB_ALTERNATE_ARROW_LEFT KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_ARROW_RIGHT)
#define KB_ALTERNATE_ARROW_RIGHT KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_0)
#define KB_ALTERNATE_0 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_1)
#define KB_ALTERNATE_1 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_2)
#define KB_ALTERNATE_2 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_3)
#define KB_ALTERNATE_3 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_4)
#define KB_ALTERNATE_4 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_5)
#define KB_ALTERNATE_5 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_6)
#define KB_ALTERNATE_6 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_7)
#define KB_ALTERNATE_7 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_8)
#define KB_ALTERNATE_8 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_9)
#define KB_ALTERNATE_9 KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_A)
#define KB_ALTERNATE_A KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_B)
#define KB_ALTERNATE_B KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_C)
#define KB_ALTERNATE_C KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_D)
#define KB_ALTERNATE_D KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_E)
#define KB_ALTERNATE_E KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F)
#define KB_ALTERNATE_F KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_G)
#define KB_ALTERNATE_G KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_H)
#define KB_ALTERNATE_H KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_I)
#define KB_ALTERNATE_I KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_J)
#define KB_ALTERNATE_J KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_K)
#define KB_ALTERNATE_K KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_L)
#define KB_ALTERNATE_L KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_M)
#define KB_ALTERNATE_M KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_N)
#define KB_ALTERNATE_N KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_O)
#define KB_ALTERNATE_O KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_P)
#define KB_ALTERNATE_P KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_Q)
#define KB_ALTERNATE_Q KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_R)
#define KB_ALTERNATE_R KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_S)
#define KB_ALTERNATE_S KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_T)
#define KB_ALTERNATE_T KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_U)
#define KB_ALTERNATE_U KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_V)
#define KB_ALTERNATE_V KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_W)
#define KB_ALTERNATE_W KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_X)
#define KB_ALTERNATE_X KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_Y)
#define KB_ALTERNATE_Y KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_Z)
#define KB_ALTERNATE_Z KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_APOSTROPHE)
#define KB_ALTERNATE_APOSTROPHE KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_MINUS)
#define KB_ALTERNATE_MINUS KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_EQUAL_TO)
#define KB_ALTERNATE_EQUAL_TO KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_LEFT_BRACKET)
#define KB_ALTERNATE_LEFT_BRACKET KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_RIGHT_BRACKET)
#define KB_ALTERNATE_RIGHT_BRACKET KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_COMMA)
#define KB_ALTERNATE_COMMA KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_FULL_STOP)
#define KB_ALTERNATE_FULL_STOP KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_SEMI_COLON)
#define KB_ALTERNATE_SEMI_COLON KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_BACK_SLASH)
#define KB_ALTERNATE_BACK_SLASH KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_SINGLE_QUOTES)
#define KB_ALTERNATE_SINGLE_QUOTES KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_FORWARD_SLASH)
#define KB_ALTERNATE_FORWARD_SLASH KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_F1)
#define KB_ALTERNATE_F1 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F2)
#define KB_ALTERNATE_F2 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F3)
#define KB_ALTERNATE_F3 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F4)
#define KB_ALTERNATE_F4 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F5)
#define KB_ALTERNATE_F5 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F6)
#define KB_ALTERNATE_F6 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F7)
#define KB_ALTERNATE_F7 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F8)
#define KB_ALTERNATE_F8 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F9)
#define KB_ALTERNATE_F9 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F10)
#define KB_ALTERNATE_F10 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F11)
#define KB_ALTERNATE_F11 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_F12)
#define KB_ALTERNATE_F12 KB_NOT_USED
#endif

/******************************************************************************************************/

#if !defined(KB_ALTERNATE_KEYPAD_0)
#define KB_ALTERNATE_KEYPAD_0 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_1)
#define KB_ALTERNATE_KEYPAD_1 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_2)
#define KB_ALTERNATE_KEYPAD_2 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_3)
#define KB_ALTERNATE_KEYPAD_3 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_4)
#define KB_ALTERNATE_KEYPAD_4 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_5)
#define KB_ALTERNATE_KEYPAD_5 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_6)
#define KB_ALTERNATE_KEYPAD_6 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_7)
#define KB_ALTERNATE_KEYPAD_7 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_8)
#define KB_ALTERNATE_KEYPAD_8 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_9)
#define KB_ALTERNATE_KEYPAD_9 KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_DOT)
#define KB_ALTERNATE_KEYPAD_DOT KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_BACKSLASH)
#define KB_ALTERNATE_KEYPAD_BACKSLASH KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_ASTERIK)
#define KB_ALTERNATE_KEYPAD_ASTERIK KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_MINUS)
#define KB_ALTERNATE_KEYPAD_MINUS KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_PLUS)
#define KB_ALTERNATE_KEYPAD_PLUS KB_NOT_USED
#endif

#if !defined(KB_ALTERNATE_KEYPAD_ENTER)
#define KB_ALTERNATE_KEYPAD_ENTER KB_NOT_USED
#endif

/******************************************************************************************************/

#if ((!(KB_USE_CONTROL_COMBINATIONS))&&(!(KB_USE_ALTERNATE_COMBINATIONS)))

const unsigned char kb_LUT[][3] PROGMEM =
{
    {KB_SCAN_CODE_SPACE,	        KB_SPACE,	        KB_SHIFT_SPACE},
    {KB_SCAN_CODE_ENTER,	        KB_ENTER,	        KB_SHIFT_ENTER},
    {KB_SCAN_CODE_BACKSPACE,	    KB_BACKSPACE,   	KB_SHIFT_BACKSPACE},
    {KB_SCAN_CODE_ESCAPE,	        KB_ESCAPE,      	KB_SHIFT_ESCAPE},
    {KB_SCAN_CODE_TAB,          	KB_TAB,	            KB_SHIFT_TAB},
    {KB_SCAN_CODE_LEFT_SHIFT,	    KB_LEFT_SHIFT,	    KB_SHIFT_LEFT_SHIFT},
    {KB_SCAN_CODE_LEFT_CONTROL,	    KB_LEFT_CONTROL,	KB_SHIFT_LEFT_CONTROL},
    {KB_SCAN_CODE_LEFT_ALTERNATE,	KB_LEFT_ALTERNATE,	KB_SHIFT_LEFT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_SHIFT,	    KB_RIGHT_SHIFT,	    KB_SHIFT_RIGHT_SHIFT},
    {KB_SCAN_CODE_CAPS_LOCK,	    KB_CAPS_LOCK,	    KB_SHIFT_CAPS_LOCK},
    {KB_SCAN_CODE_NUMBER_LOCK,	    KB_NUMBER_LOCK,	    KB_SHIFT_NUMBER_LOCK},
    {KB_SCAN_CODE_SCROLL_LOCK,	    KB_SCROLL_LOCK,	    KB_SHIFT_SCROLL_LOCK},
    {KB_SCAN_CODE_0,	            KB_0,            	KB_SHIFT_0},
    {KB_SCAN_CODE_1,            	KB_1,            	KB_SHIFT_1},
    {KB_SCAN_CODE_2,	            KB_2,            	KB_SHIFT_2},
    {KB_SCAN_CODE_3,	            KB_3,	            KB_SHIFT_3},
    {KB_SCAN_CODE_4,	            KB_4,	            KB_SHIFT_4},
    {KB_SCAN_CODE_5,	            KB_5,            	KB_SHIFT_5},
    {KB_SCAN_CODE_6,	            KB_6,            	KB_SHIFT_6},
    {KB_SCAN_CODE_7,            	KB_7,	            KB_SHIFT_7},
    {KB_SCAN_CODE_8,	            KB_8,	            KB_SHIFT_8},
    {KB_SCAN_CODE_9,            	KB_9,            	KB_SHIFT_9},
    {KB_SCAN_CODE_A,	            KB_A,	            KB_SHIFT_A},
    {KB_SCAN_CODE_B,	            KB_B,	            KB_SHIFT_B},
    {KB_SCAN_CODE_C,            	KB_C,            	KB_SHIFT_C},
    {KB_SCAN_CODE_D,	            KB_D,	            KB_SHIFT_D},
    {KB_SCAN_CODE_E,	            KB_E,	            KB_SHIFT_E},
    {KB_SCAN_CODE_F,	            KB_F,	            KB_SHIFT_F},
    {KB_SCAN_CODE_G,	            KB_G,	            KB_SHIFT_G},
    {KB_SCAN_CODE_H,	            KB_H,            	KB_SHIFT_H},
    {KB_SCAN_CODE_I,	            KB_I,	            KB_SHIFT_I},
    {KB_SCAN_CODE_J,            	KB_J,	            KB_SHIFT_J},
    {KB_SCAN_CODE_K,	            KB_K,	            KB_SHIFT_K},
    {KB_SCAN_CODE_L,	            KB_L,	            KB_SHIFT_L},
    {KB_SCAN_CODE_M,	            KB_M,            	KB_SHIFT_M},
    {KB_SCAN_CODE_N,	            KB_N,	            KB_SHIFT_N},
    {KB_SCAN_CODE_O,	            KB_O,            	KB_SHIFT_O},
    {KB_SCAN_CODE_P,	            KB_P,	            KB_SHIFT_P},
    {KB_SCAN_CODE_Q,	            KB_Q,	            KB_SHIFT_Q},
    {KB_SCAN_CODE_R,	            KB_R,	            KB_SHIFT_R},
    {KB_SCAN_CODE_S,	            KB_S,            	KB_SHIFT_S},
    {KB_SCAN_CODE_T,	            KB_T,	            KB_SHIFT_T},
    {KB_SCAN_CODE_U,            	KB_U,	            KB_SHIFT_U},
    {KB_SCAN_CODE_V,	            KB_V,	            KB_SHIFT_V},
    {KB_SCAN_CODE_W,	            KB_W,            	KB_SHIFT_W},
    {KB_SCAN_CODE_X,	            KB_X,	            KB_SHIFT_X},
    {KB_SCAN_CODE_Y,	            KB_Y,	            KB_SHIFT_Y},
    {KB_SCAN_CODE_Z,	            KB_Z,	            KB_SHIFT_Z},
    {KB_SCAN_CODE_APOSTROPHE,	    KB_APOSTROPHE,	    KB_SHIFT_APOSTROPHE},
    {KB_SCAN_CODE_MINUS,        	KB_MINUS,	        KB_SHIFT_MINUS},
    {KB_SCAN_CODE_EQUAL_TO,	        KB_EQUAL_TO,	    KB_SHIFT_EQUAL_TO},
    {KB_SCAN_CODE_LEFT_BRACKET, 	KB_LEFT_BRACKET,	KB_SHIFT_LEFT_BRACKET},
    {KB_SCAN_CODE_RIGHT_BRACKET,	KB_RIGHT_BRACKET,	KB_SHIFT_RIGHT_BRACKET},
    {KB_SCAN_CODE_COMMA,	        KB_COMMA,	        KB_SHIFT_COMMA},
    {KB_SCAN_CODE_FULL_STOP,	    KB_FULL_STOP,	    KB_SHIFT_FULL_STOP},
    {KB_SCAN_CODE_SEMI_COLON,	    KB_SEMI_COLON,	    KB_SHIFT_SEMI_COLON},
    {KB_SCAN_CODE_BACK_SLASH,	    KB_BACK_SLASH,	    KB_SHIFT_BACK_SLASH},
    {KB_SCAN_CODE_SINGLE_QUOTES,	KB_SINGLE_QUOTES,	KB_SHIFT_SINGLE_QUOTES},
    {KB_SCAN_CODE_FORWARD_SLASH,	KB_FORWARD_SLASH,	KB_SHIFT_FORWARD_SLASH},
    {KB_SCAN_CODE_F1,	            KB_F1,	            KB_SHIFT_F1},
    {KB_SCAN_CODE_F2,	            KB_F2,	            KB_SHIFT_F2},
    {KB_SCAN_CODE_F3,	            KB_F3,	            KB_SHIFT_F3},
    {KB_SCAN_CODE_F4,	            KB_F4,	            KB_SHIFT_F4},
    {KB_SCAN_CODE_F5,	            KB_F5,	            KB_SHIFT_F5},
    {KB_SCAN_CODE_F6,	            KB_F6,	            KB_SHIFT_F6},
    {KB_SCAN_CODE_F7,	            KB_F7,	            KB_SHIFT_F7},
    {KB_SCAN_CODE_F8,	            KB_F8,	            KB_SHIFT_F8},
    {KB_SCAN_CODE_F9,	            KB_F9,	            KB_SHIFT_F9},
    {KB_SCAN_CODE_F10,	            KB_F10,         	KB_SHIFT_F10},
    {KB_SCAN_CODE_F11,	            KB_F11,	            KB_SHIFT_F11},
    {KB_SCAN_CODE_F12,	            KB_F12,	            KB_SHIFT_F12},
    {KB_SCAN_CODE_KEYPAD_0,	        KB_KEYPAD_0,    	KB_SHIFT_KEYPAD_0},
    {KB_SCAN_CODE_KEYPAD_1,	        KB_KEYPAD_1,	    KB_SHIFT_KEYPAD_1},
    {KB_SCAN_CODE_KEYPAD_2,	        KB_KEYPAD_2,	    KB_SHIFT_KEYPAD_2},
    {KB_SCAN_CODE_KEYPAD_3,	        KB_KEYPAD_3,    	KB_SHIFT_KEYPAD_3},
    {KB_SCAN_CODE_KEYPAD_4,         KB_KEYPAD_4,	    KB_SHIFT_KEYPAD_4},
    {KB_SCAN_CODE_KEYPAD_5,	        KB_KEYPAD_5,    	KB_SHIFT_KEYPAD_5},
    {KB_SCAN_CODE_KEYPAD_6,	        KB_KEYPAD_6,	    KB_SHIFT_KEYPAD_6},
    {KB_SCAN_CODE_KEYPAD_7,	        KB_KEYPAD_7,    	KB_SHIFT_KEYPAD_7},
    {KB_SCAN_CODE_KEYPAD_8,        	KB_KEYPAD_8,	    KB_SHIFT_KEYPAD_8},
    {KB_SCAN_CODE_KEYPAD_9,        	KB_KEYPAD_9,    	KB_SHIFT_KEYPAD_9},
    {KB_SCAN_CODE_KEYPAD_DOT,	    KB_KEYPAD_DOT,	    KB_SHIFT_KEYPAD_DOT},
    {KB_SCAN_CODE_KEYPAD_ASTERIK,	KB_KEYPAD_ASTERIK,	KB_SHIFT_KEYPAD_ASTERIK},
    {KB_SCAN_CODE_KEYPAD_MINUS,	    KB_KEYPAD_MINUS,	KB_SHIFT_KEYPAD_MINUS},
    {KB_SCAN_CODE_KEYPAD_PLUS,	    KB_KEYPAD_PLUS,	    KB_SHIFT_KEYPAD_PLUS},
    {KB_SCAN_CODE_PRINT_SCREEN,	    KB_PRINT_SCREEN,	KB_SHIFT_PRINT_SCREEN},
    {KB_SCAN_CODE_PAUSE,            KB_PAUSE,           KB_SHIFT_PAUSE},

    {KB_SCAN_CODE_LEFT_GUI,	        KB_LEFT_GUI,	    KB_SHIFT_LEFT_GUI},
    {KB_SCAN_CODE_RIGHT_CONTROL,	KB_RIGHT_CONTROL,	KB_SHIFT_RIGHT_CONTROL},
    {KB_SCAN_CODE_RIGHT_ALTERNATE,	KB_RIGHT_ALTERNATE,	KB_SHIFT_RIGHT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_GUI,	    KB_RIGHT_GUI,	    KB_SHIFT_RIGHT_GUI},
    {KB_SCAN_CODE_INSERT,	        KB_INSERT,	        KB_SHIFT_INSERT},
    {KB_SCAN_CODE_DELETE,	        KB_DELETE,      	KB_SHIFT_DELETE},
    {KB_SCAN_CODE_ARROW_UP,	        KB_ARROW_UP,	    KB_SHIFT_ARROW_UP},
    {KB_SCAN_CODE_ARROW_DOWN,	    KB_ARROW_DOWN,	    KB_SHIFT_ARROW_DOWN},
    {KB_SCAN_CODE_ARROW_LEFT,	    KB_ARROW_LEFT,	    KB_SHIFT_ARROW_LEFT},
    {KB_SCAN_CODE_ARROW_RIGHT,	    KB_ARROW_RIGHT,	    KB_SHIFT_ARROW_RIGHT},
    {KB_SCAN_CODE_HOME,	            KB_HOME,	        KB_SHIFT_HOME},
    {KB_SCAN_CODE_END,	            KB_END,	            KB_SHIFT_END},
    {KB_SCAN_CODE_PAGE_DOWN,	    KB_PAGE_DOWN,	    KB_SHIFT_PAGE_DOWN},
    {KB_SCAN_CODE_PAGE_UP,	        KB_PAGE_UP,	        KB_SHIFT_PAGE_UP},
    {KB_SCAN_CODE_KEYPAD_ENTER,	    KB_KEYPAD_ENTER,	KB_SHIFT_KEYPAD_ENTER},
    {KB_SCAN_CODE_KEYPAD_BACKSLASH,	KB_KEYPAD_BACKSLASH,KB_SHIFT_KEYPAD_BACKSLASH},
    {KB_SCAN_CODE_APPS,             KB_APPS,            KB_SHIFT_APPS}

    #if (KB_USE_ACPI_KEYS)

    ,{KB_SCAN_CODE_POWER,            KB_POWER,           KB_SHIFT_POWER},
    {KB_SCAN_CODE_SLEEP,            KB_SLEEP,           KB_SHIFT_SLEEP},
    {KB_SCAN_CODE_WAKE,             KB_WAKE,            KB_SHIFT_WAKE}

    #endif

    #if (KB_USE_WINDOWS_MULTIMEDIA_KEYS)

    ,{KB_SCAN_CODE_NEXT_TRACK,       KB_NEXT_TRACK,      KB_SHIFT_NEXT_TRACK},
    {KB_SCAN_CODE_PREVIOUS_TRACK,   KB_PREVIOUS_TRACK,  KB_SHIFT_PREVIOUS_TRACK},
    {KB_SCAN_CODE_STOP,             KB_STOP,            KB_SHIFT_STOP},
    {KB_SCAN_CODE_PLAY_OR_PAUSE,    KB_PLAY_OR_PAUSE,   KB_SHIFT_PLAY_OR_PAUSE},
    {KB_SCAN_CODE_MUTE,             KB_MUTE,            KB_SHIFT_MUTE},
    {KB_SCAN_CODE_VOLUME_UP,        KB_VOLUME_UP,       KB_SHIFT_VOLUME_UP},
    {KB_SCAN_CODE_VOLUME_DOWN,      KB_VOLUME_DOWN,     KB_SHIFT_VOLUME_DOWN},
    {KB_SCAN_CODE_MEDIA_SELECT,     KB_MEDIA_SELECT,    KB_SHIFT_MEDIA_SELECT},
    {KB_SCAN_CODE_E_MAIL,           KB_E_MAIL,          KB_SHIFT_E_MAIL},
    {KB_SCAN_CODE_CALCULATOR,       KB_CALCULATOR,      KB_SHIFT_CALCULATOR},
    {KB_SCAN_CODE_COMPUTER,         KB_COMPUTER,        KB_SHIFT_COMPUTER},
    {KB_SCAN_CODE_WWW_SEARCH,       KB_WWW_SEARCH,      KB_SHIFT_WWW_SEARCH},
    {KB_SCAN_CODE_WWW_HOME,         KB_WWW_HOME,        KB_SHIFT_WWW_HOME},
    {KB_SCAN_CODE_WWW_BACK,         KB_WWW_BACK,        KB_SHIFT_WWW_BACK},
    {KB_SCAN_CODE_WWW_FORWARD,      KB_WWW_FORWARD,     KB_SHIFT_WWW_FORWARD},
    {KB_SCAN_CODE_WWW_STOP,         KB_WWW_STOP,        KB_SHIFT_WWW_STOP},
    {KB_SCAN_CODE_WWW_REFRESH,      KB_WWW_REFRESH,     KB_SHIFT_WWW_REFRESH},
    {KB_SCAN_CODE_WWW_FAVORITES,    KB_WWW_FAVORITES,   KB_SHIFT_WWW_FAVORITES}

    #endif

};

#endif

#if (KB_USE_CONTROL_COMBINATIONS)

const unsigned char kb_LUT[][4] PROGMEM =
{
    {KB_SCAN_CODE_SPACE,	        KB_SPACE,	        KB_SHIFT_SPACE,	            KB_CONTROL_SPACE},
    {KB_SCAN_CODE_ENTER,	        KB_ENTER,	        KB_SHIFT_ENTER,	            KB_CONTROL_ENTER},
    {KB_SCAN_CODE_BACKSPACE,	    KB_BACKSPACE,   	KB_SHIFT_BACKSPACE,	        KB_CONTROL_BACKSPACE},
    {KB_SCAN_CODE_ESCAPE,	        KB_ESCAPE,      	KB_SHIFT_ESCAPE,	        KB_CONTROL_ESCAPE},
    {KB_SCAN_CODE_TAB,          	KB_TAB,	            KB_SHIFT_TAB,	            KB_CONTROL_TAB},
    {KB_SCAN_CODE_LEFT_SHIFT,	    KB_LEFT_SHIFT,	    KB_SHIFT_LEFT_SHIFT,	    KB_CONTROL_LEFT_SHIFT},
    {KB_SCAN_CODE_LEFT_CONTROL,	    KB_LEFT_CONTROL,	KB_SHIFT_LEFT_CONTROL,	    KB_CONTROL_LEFT_CONTROL},
    {KB_SCAN_CODE_LEFT_ALTERNATE,	KB_LEFT_ALTERNATE,	KB_SHIFT_LEFT_ALTERNATE,    KB_CONTROL_LEFT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_SHIFT,	    KB_RIGHT_SHIFT,	    KB_SHIFT_RIGHT_SHIFT,	    KB_CONTROL_RIGHT_SHIFT},
    {KB_SCAN_CODE_CAPS_LOCK,	    KB_CAPS_LOCK,	    KB_SHIFT_CAPS_LOCK,	        KB_CONTROL_CAPS_LOCK},
    {KB_SCAN_CODE_NUMBER_LOCK,	    KB_NUMBER_LOCK,	    KB_SHIFT_NUMBER_LOCK,	    KB_CONTROL_NUMBER_LOCK},
    {KB_SCAN_CODE_SCROLL_LOCK,	    KB_SCROLL_LOCK,	    KB_SHIFT_SCROLL_LOCK,	    KB_CONTROL_SCROLL_LOCK},
    {KB_SCAN_CODE_0,	            KB_0,            	KB_SHIFT_0,	                KB_CONTROL_0},
    {KB_SCAN_CODE_1,            	KB_1,            	KB_SHIFT_1,	                KB_CONTROL_1},
    {KB_SCAN_CODE_2,	            KB_2,            	KB_SHIFT_2,	                KB_CONTROL_2},
    {KB_SCAN_CODE_3,	            KB_3,	            KB_SHIFT_3, 	            KB_CONTROL_3},
    {KB_SCAN_CODE_4,	            KB_4,	            KB_SHIFT_4,	                KB_CONTROL_4},
    {KB_SCAN_CODE_5,	            KB_5,            	KB_SHIFT_5,	                KB_CONTROL_5},
    {KB_SCAN_CODE_6,	            KB_6,            	KB_SHIFT_6,	                KB_CONTROL_6},
    {KB_SCAN_CODE_7,            	KB_7,	            KB_SHIFT_7,	                KB_CONTROL_7},
    {KB_SCAN_CODE_8,	            KB_8,	            KB_SHIFT_8, 	            KB_CONTROL_8},
    {KB_SCAN_CODE_9,            	KB_9,            	KB_SHIFT_9,	                KB_CONTROL_9},
    {KB_SCAN_CODE_A,	            KB_A,	            KB_SHIFT_A,	                KB_CONTROL_A},
    {KB_SCAN_CODE_B,	            KB_B,	            KB_SHIFT_B,	                KB_CONTROL_B},
    {KB_SCAN_CODE_C,            	KB_C,            	KB_SHIFT_C,	                KB_CONTROL_C},
    {KB_SCAN_CODE_D,	            KB_D,	            KB_SHIFT_D, 	            KB_CONTROL_D},
    {KB_SCAN_CODE_E,	            KB_E,	            KB_SHIFT_E,	                KB_CONTROL_E},
    {KB_SCAN_CODE_F,	            KB_F,	            KB_SHIFT_F,	                KB_CONTROL_F},
    {KB_SCAN_CODE_G,	            KB_G,	            KB_SHIFT_G,	                KB_CONTROL_G},
    {KB_SCAN_CODE_H,	            KB_H,            	KB_SHIFT_H,	                KB_CONTROL_H},
    {KB_SCAN_CODE_I,	            KB_I,	            KB_SHIFT_I, 	            KB_CONTROL_I},
    {KB_SCAN_CODE_J,            	KB_J,	            KB_SHIFT_J,	                KB_CONTROL_J},
    {KB_SCAN_CODE_K,	            KB_K,	            KB_SHIFT_K,	                KB_CONTROL_K},
    {KB_SCAN_CODE_L,	            KB_L,	            KB_SHIFT_L,	                KB_CONTROL_L},
    {KB_SCAN_CODE_M,	            KB_M,            	KB_SHIFT_M,	                KB_CONTROL_M},
    {KB_SCAN_CODE_N,	            KB_N,	            KB_SHIFT_N, 	            KB_CONTROL_N},
    {KB_SCAN_CODE_O,	            KB_O,            	KB_SHIFT_O,	                KB_CONTROL_O},
    {KB_SCAN_CODE_P,	            KB_P,	            KB_SHIFT_P,	                KB_CONTROL_P},
    {KB_SCAN_CODE_Q,	            KB_Q,	            KB_SHIFT_Q,	                KB_CONTROL_Q},
    {KB_SCAN_CODE_R,	            KB_R,	            KB_SHIFT_R,	                KB_CONTROL_R},
    {KB_SCAN_CODE_S,	            KB_S,            	KB_SHIFT_S, 	            KB_CONTROL_S},
    {KB_SCAN_CODE_T,	            KB_T,	            KB_SHIFT_T,	                KB_CONTROL_T},
    {KB_SCAN_CODE_U,            	KB_U,	            KB_SHIFT_U,	                KB_CONTROL_U},
    {KB_SCAN_CODE_V,	            KB_V,	            KB_SHIFT_V,	                KB_CONTROL_V},
    {KB_SCAN_CODE_W,	            KB_W,            	KB_SHIFT_W,	                KB_CONTROL_W},
    {KB_SCAN_CODE_X,	            KB_X,	            KB_SHIFT_X, 	            KB_CONTROL_X},
    {KB_SCAN_CODE_Y,	            KB_Y,	            KB_SHIFT_Y,	                KB_CONTROL_Y},
    {KB_SCAN_CODE_Z,	            KB_Z,	            KB_SHIFT_Z,	                KB_CONTROL_Z},
    {KB_SCAN_CODE_APOSTROPHE,	    KB_APOSTROPHE,	    KB_SHIFT_APOSTROPHE,	    KB_CONTROL_APOSTROPHE},
    {KB_SCAN_CODE_MINUS,        	KB_MINUS,	        KB_SHIFT_MINUS,	            KB_CONTROL_MINUS},
    {KB_SCAN_CODE_EQUAL_TO,	        KB_EQUAL_TO,	    KB_SHIFT_EQUAL_TO,	        KB_CONTROL_EQUAL_TO},
    {KB_SCAN_CODE_LEFT_BRACKET, 	KB_LEFT_BRACKET,	KB_SHIFT_LEFT_BRACKET,	    KB_CONTROL_LEFT_BRACKET},
    {KB_SCAN_CODE_RIGHT_BRACKET,	KB_RIGHT_BRACKET,	KB_SHIFT_RIGHT_BRACKET,	    KB_CONTROL_RIGHT_BRACKET},
    {KB_SCAN_CODE_COMMA,	        KB_COMMA,	        KB_SHIFT_COMMA,	            KB_CONTROL_COMMA},
    {KB_SCAN_CODE_FULL_STOP,	    KB_FULL_STOP,	    KB_SHIFT_FULL_STOP,	        KB_CONTROL_FULL_STOP},
    {KB_SCAN_CODE_SEMI_COLON,	    KB_SEMI_COLON,	    KB_SHIFT_SEMI_COLON,	    KB_CONTROL_SEMI_COLON},
    {KB_SCAN_CODE_BACK_SLASH,	    KB_BACK_SLASH,	    KB_SHIFT_BACK_SLASH,	    KB_CONTROL_BACK_SLASH},
    {KB_SCAN_CODE_SINGLE_QUOTES,	KB_SINGLE_QUOTES,	KB_SHIFT_SINGLE_QUOTES, 	KB_CONTROL_SINGLE_QUOTES},
    {KB_SCAN_CODE_FORWARD_SLASH,	KB_FORWARD_SLASH,	KB_SHIFT_FORWARD_SLASH, 	KB_CONTROL_FORWARD_SLASH},
    {KB_SCAN_CODE_F1,	            KB_F1,	            KB_SHIFT_F1,	            KB_CONTROL_F1},
    {KB_SCAN_CODE_F2,	            KB_F2,	            KB_SHIFT_F2,                KB_CONTROL_F2},
    {KB_SCAN_CODE_F3,	            KB_F3,	            KB_SHIFT_F3,	            KB_CONTROL_F3},
    {KB_SCAN_CODE_F4,	            KB_F4,	            KB_SHIFT_F4,    	        KB_CONTROL_F4},
    {KB_SCAN_CODE_F5,	            KB_F5,	            KB_SHIFT_F5,	            KB_CONTROL_F5},
    {KB_SCAN_CODE_F6,	            KB_F6,	            KB_SHIFT_F6,	            KB_CONTROL_F6},
    {KB_SCAN_CODE_F7,	            KB_F7,	            KB_SHIFT_F7,	            KB_CONTROL_F7},
    {KB_SCAN_CODE_F8,	            KB_F8,	            KB_SHIFT_F8,	            KB_CONTROL_F8},
    {KB_SCAN_CODE_F9,	            KB_F9,	            KB_SHIFT_F9,	            KB_CONTROL_F9},
    {KB_SCAN_CODE_F10,	            KB_F10,         	KB_SHIFT_F10,	            KB_CONTROL_F10},
    {KB_SCAN_CODE_F11,	            KB_F11,	            KB_SHIFT_F11,	            KB_CONTROL_F11},
    {KB_SCAN_CODE_F12,	            KB_F12,	            KB_SHIFT_F12,	            KB_CONTROL_F12},
    {KB_SCAN_CODE_KEYPAD_0,	        KB_KEYPAD_0,    	KB_SHIFT_KEYPAD_0,	        KB_CONTROL_KEYPAD_0},
    {KB_SCAN_CODE_KEYPAD_1,	        KB_KEYPAD_1,	    KB_SHIFT_KEYPAD_1,	        KB_CONTROL_KEYPAD_1},
    {KB_SCAN_CODE_KEYPAD_2,	        KB_KEYPAD_2,	    KB_SHIFT_KEYPAD_2,	        KB_CONTROL_KEYPAD_2},
    {KB_SCAN_CODE_KEYPAD_3,	        KB_KEYPAD_3,    	KB_SHIFT_KEYPAD_3,	        KB_CONTROL_KEYPAD_3},
    {KB_SCAN_CODE_KEYPAD_4,	        KB_KEYPAD_4,	    KB_SHIFT_KEYPAD_4,	        KB_CONTROL_KEYPAD_4},
    {KB_SCAN_CODE_KEYPAD_5,	        KB_KEYPAD_5,    	KB_SHIFT_KEYPAD_5,	        KB_CONTROL_KEYPAD_5},
    {KB_SCAN_CODE_KEYPAD_6,	        KB_KEYPAD_6,	    KB_SHIFT_KEYPAD_6,	        KB_CONTROL_KEYPAD_6},
    {KB_SCAN_CODE_KEYPAD_7,	        KB_KEYPAD_7,    	KB_SHIFT_KEYPAD_7,	        KB_CONTROL_KEYPAD_7},
    {KB_SCAN_CODE_KEYPAD_8,        	KB_KEYPAD_8,	    KB_SHIFT_KEYPAD_8,	        KB_CONTROL_KEYPAD_8},
    {KB_SCAN_CODE_KEYPAD_9,        	KB_KEYPAD_9,    	KB_SHIFT_KEYPAD_9,	        KB_CONTROL_KEYPAD_9},
    {KB_SCAN_CODE_KEYPAD_DOT,	    KB_KEYPAD_DOT,	    KB_SHIFT_KEYPAD_DOT,	    KB_CONTROL_KEYPAD_DOT},
    {KB_SCAN_CODE_KEYPAD_ASTERIK,	KB_KEYPAD_ASTERIK,	KB_SHIFT_KEYPAD_ASTERIK,    KB_CONTROL_KEYPAD_ASTERIK},
    {KB_SCAN_CODE_KEYPAD_MINUS,	    KB_KEYPAD_MINUS,	KB_SHIFT_KEYPAD_MINUS,	    KB_CONTROL_KEYPAD_MINUS},
    {KB_SCAN_CODE_KEYPAD_PLUS,	    KB_KEYPAD_PLUS,	    KB_SHIFT_KEYPAD_PLUS,   	KB_CONTROL_KEYPAD_PLUS},
	{KB_SCAN_CODE_PRINT_SCREEN,	    KB_PRINT_SCREEN,	KB_SHIFT_PRINT_SCREEN,	    KB_CONTROL_PRINT_SCREEN},
    {KB_SCAN_CODE_PAUSE,        	KB_PAUSE,	        KB_SHIFT_PAUSE,	            KB_CONTROL_PAUSE},

    {KB_SCAN_CODE_LEFT_GUI,	        KB_LEFT_GUI,	    KB_SHIFT_LEFT_GUI,	        KB_CONTROL_LEFT_GUI},
    {KB_SCAN_CODE_RIGHT_CONTROL,	KB_RIGHT_CONTROL,	KB_SHIFT_RIGHT_CONTROL,	    KB_CONTROL_RIGHT_CONTROL},
    {KB_SCAN_CODE_RIGHT_ALTERNATE,	KB_RIGHT_ALTERNATE,	KB_SHIFT_RIGHT_ALTERNATE,	KB_CONTROL_RIGHT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_GUI,	    KB_RIGHT_GUI,	    KB_SHIFT_RIGHT_GUI,	        KB_CONTROL_RIGHT_GUI},
    {KB_SCAN_CODE_INSERT,	        KB_INSERT,	        KB_SHIFT_INSERT,	        KB_CONTROL_INSERT},
    {KB_SCAN_CODE_DELETE,	        KB_DELETE,      	KB_SHIFT_DELETE,	        KB_CONTROL_DELETE},
    {KB_SCAN_CODE_ARROW_UP,	        KB_ARROW_UP,	    KB_SHIFT_ARROW_UP,	        KB_CONTROL_ARROW_UP},
    {KB_SCAN_CODE_ARROW_DOWN,	    KB_ARROW_DOWN,	    KB_SHIFT_ARROW_DOWN,	    KB_CONTROL_ARROW_DOWN},
    {KB_SCAN_CODE_ARROW_LEFT,	    KB_ARROW_LEFT,	    KB_SHIFT_ARROW_LEFT,	    KB_CONTROL_ARROW_LEFT},
    {KB_SCAN_CODE_ARROW_RIGHT,	    KB_ARROW_RIGHT,	    KB_SHIFT_ARROW_RIGHT,	    KB_CONTROL_ARROW_RIGHT},
    {KB_SCAN_CODE_HOME,	            KB_HOME,	        KB_SHIFT_HOME,	            KB_CONTROL_HOME},
    {KB_SCAN_CODE_END,	            KB_END,	            KB_SHIFT_END,	            KB_CONTROL_END},
    {KB_SCAN_CODE_PAGE_DOWN,	    KB_PAGE_DOWN,	    KB_SHIFT_PAGE_DOWN,	        KB_CONTROL_PAGE_DOWN},
    {KB_SCAN_CODE_PAGE_UP,	        KB_PAGE_UP,	        KB_SHIFT_PAGE_UP,	        KB_CONTROL_PAGE_UP},
    {KB_SCAN_CODE_KEYPAD_ENTER,	    KB_KEYPAD_ENTER,	KB_SHIFT_KEYPAD_ENTER,	    KB_CONTROL_KEYPAD_ENTER},
    {KB_SCAN_CODE_KEYPAD_BACKSLASH,	KB_KEYPAD_BACKSLASH,KB_SHIFT_KEYPAD_BACKSLASH,	KB_CONTROL_KEYPAD_BACKSLASH},
    {KB_SCAN_CODE_APPS,           	KB_APPS, 	        KB_SHIFT_APPS,          	KB_CONTROL_APPS}

    #if (KB_USE_ACPI_KEYS)

    ,{KB_SCAN_CODE_POWER,         	KB_POWER,  	        KB_SHIFT_POWER,	            KB_CONTROL_POWER},
    {KB_SCAN_CODE_SLEEP,            KB_SLEEP,    	    KB_SHIFT_SLEEP,	            KB_CONTROL_SLEEP},
    {KB_SCAN_CODE_WAKE,           	KB_WAKE,          	KB_SHIFT_WAKE,	            KB_CONTROL_WAKE}

    #endif

    #if (KB_USE_WINDOWS_MULTIMEDIA_KEYS)

    ,{KB_SCAN_CODE_NEXT_TRACK,    	KB_NEXT_TRACK,  	KB_SHIFT_NEXT_TRACK,	    KB_CONTROL_NEXT_TRACK},
    {KB_SCAN_CODE_PREVIOUS_TRACK,   KB_PREVIOUS_TRACK,  KB_SHIFT_PREVIOUS_TRACK,	KB_CONTROL_PREVIOUS_TRACK},
    {KB_SCAN_CODE_STOP,      	    KB_STOP,          	KB_SHIFT_STOP,	            KB_CONTROL_STOP},
    {KB_SCAN_CODE_PLAY_OR_PAUSE,  	KB_PLAY_OR_PAUSE,  	KB_SHIFT_PLAY_OR_PAUSE,	    KB_CONTROL_PLAY_OR_PAUSE},
    {KB_SCAN_CODE_MUTE,        	    KB_MUTE,            KB_SHIFT_MUTE,	            KB_CONTROL_MUTE},
    {KB_SCAN_CODE_VOLUME_UP,  	    KB_VOLUME_UP,       KB_SHIFT_VOLUME_UP,	        KB_CONTROL_VOLUME_UP},
    {KB_SCAN_CODE_VOLUME_DOWN, 	    KB_VOLUME_DOWN,  	KB_SHIFT_VOLUME_DOWN,	    KB_CONTROL_VOLUME_DOWN},
    {KB_SCAN_CODE_MEDIA_SELECT,   	KB_MEDIA_SELECT, 	KB_SHIFT_MEDIA_SELECT,	    KB_CONTROL_MEDIA_SELECT},
    {KB_SCAN_CODE_E_MAIL,        	KB_E_MAIL,       	KB_SHIFT_E_MAIL,	        KB_CONTROL_E_MAIL},
    {KB_SCAN_CODE_CALCULATOR, 	    KB_CALCULATOR, 	    KB_SHIFT_CALCULATOR,	    KB_CONTROL_CALCULATOR},
    {KB_SCAN_CODE_COMPUTER,       	KB_COMPUTER,   	    KB_SHIFT_COMPUTER,	        KB_CONTROL_COMPUTER},
    {KB_SCAN_CODE_WWW_SEARCH, 	    KB_WWW_SEARCH,  	KB_SHIFT_WWW_SEARCH,	    KB_CONTROL_WWW_SEARCH},
    {KB_SCAN_CODE_WWW_HOME,    	    KB_WWW_HOME,  	    KB_SHIFT_WWW_HOME,	        KB_CONTROL_WWW_HOME},
    {KB_SCAN_CODE_WWW_BACK,    	    KB_WWW_BACK,     	KB_SHIFT_WWW_BACK,	        KB_CONTROL_WWW_BACK},
    {KB_SCAN_CODE_WWW_FORWARD,    	KB_WWW_FORWARD, 	KB_SHIFT_WWW_FORWARD,	    KB_CONTROL_WWW_FORWARD},
    {KB_SCAN_CODE_WWW_STOP,       	KB_WWW_STOP,     	KB_SHIFT_WWW_STOP,	        KB_CONTROL_WWW_STOP},
    {KB_SCAN_CODE_WWW_REFRESH,   	KB_WWW_REFRESH,   	KB_SHIFT_WWW_REFRESH,	    KB_CONTROL_WWW_REFRESH},
    {KB_SCAN_CODE_WWW_FAVORITES,	KB_WWW_FAVORITES,	KB_SHIFT_WWW_FAVORITES,	    KB_CONTROL_WWW_FAVORITES}

	#endif
};

#endif

#if (KB_USE_ALTERNATE_COMBINATIONS)

const unsigned char kb_LUT[][4] PROGMEM =
{
    {KB_SCAN_CODE_SPACE,	        KB_SPACE,	        KB_SHIFT_SPACE,	            KB_ALTERNATE_SPACE},
    {KB_SCAN_CODE_ENTER,	        KB_ENTER,	        KB_SHIFT_ENTER,	            KB_ALTERNATE_ENTER},
    {KB_SCAN_CODE_BACKSPACE,	    KB_BACKSPACE,   	KB_SHIFT_BACKSPACE,	        KB_ALTERNATE_BACKSPACE},
    {KB_SCAN_CODE_ESCAPE,	        KB_ESCAPE,      	KB_SHIFT_ESCAPE,	        KB_ALTERNATE_ESCAPE},
    {KB_SCAN_CODE_TAB,          	KB_TAB,	            KB_SHIFT_TAB,	            KB_ALTERNATE_TAB},
    {KB_SCAN_CODE_LEFT_SHIFT,	    KB_LEFT_SHIFT,	    KB_SHIFT_LEFT_SHIFT,	    KB_ALTERNATE_LEFT_SHIFT},
    {KB_SCAN_CODE_LEFT_CONTROL,	    KB_LEFT_CONTROL,	KB_SHIFT_LEFT_CONTROL,	    KB_ALTERNATE_LEFT_CONTROL},
    {KB_SCAN_CODE_LEFT_ALTERNATE,	KB_LEFT_ALTERNATE,	KB_SHIFT_LEFT_ALTERNATE,    KB_ALTERNATE_LEFT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_SHIFT,	    KB_RIGHT_SHIFT,	    KB_SHIFT_RIGHT_SHIFT,	    KB_ALTERNATE_RIGHT_SHIFT},
    {KB_SCAN_CODE_CAPS_LOCK,	    KB_CAPS_LOCK,	    KB_SHIFT_CAPS_LOCK,	        KB_ALTERNATE_CAPS_LOCK},
    {KB_SCAN_CODE_NUMBER_LOCK,	    KB_NUMBER_LOCK,	    KB_SHIFT_NUMBER_LOCK,	    KB_ALTERNATE_NUMBER_LOCK},
    {KB_SCAN_CODE_SCROLL_LOCK,	    KB_SCROLL_LOCK,	    KB_SHIFT_SCROLL_LOCK,	    KB_ALTERNATE_SCROLL_LOCK},
    {KB_SCAN_CODE_0,	            KB_0,            	KB_SHIFT_0,	                KB_ALTERNATE_0},
    {KB_SCAN_CODE_1,            	KB_1,            	KB_SHIFT_1,	                KB_ALTERNATE_1},
    {KB_SCAN_CODE_2,	            KB_2,            	KB_SHIFT_2,	                KB_ALTERNATE_2},
    {KB_SCAN_CODE_3,	            KB_3,	            KB_SHIFT_3, 	            KB_ALTERNATE_3},
    {KB_SCAN_CODE_4,	            KB_4,	            KB_SHIFT_4,	                KB_ALTERNATE_4},
    {KB_SCAN_CODE_5,	            KB_5,            	KB_SHIFT_5,	                KB_ALTERNATE_5},
    {KB_SCAN_CODE_6,	            KB_6,            	KB_SHIFT_6,	                KB_ALTERNATE_6},
    {KB_SCAN_CODE_7,            	KB_7,	            KB_SHIFT_7,	                KB_ALTERNATE_7},
    {KB_SCAN_CODE_8,	            KB_8,	            KB_SHIFT_8, 	            KB_ALTERNATE_8},
    {KB_SCAN_CODE_9,            	KB_9,            	KB_SHIFT_9,	                KB_ALTERNATE_9},
    {KB_SCAN_CODE_A,	            KB_A,	            KB_SHIFT_A,	                KB_ALTERNATE_A},
    {KB_SCAN_CODE_B,	            KB_B,	            KB_SHIFT_B,	                KB_ALTERNATE_B},
    {KB_SCAN_CODE_C,            	KB_C,            	KB_SHIFT_C,	                KB_ALTERNATE_C},
    {KB_SCAN_CODE_D,	            KB_D,	            KB_SHIFT_D, 	            KB_ALTERNATE_D},
    {KB_SCAN_CODE_E,	            KB_E,	            KB_SHIFT_E,	                KB_ALTERNATE_E},
    {KB_SCAN_CODE_F,	            KB_F,	            KB_SHIFT_F,	                KB_ALTERNATE_F},
    {KB_SCAN_CODE_G,	            KB_G,	            KB_SHIFT_G,	                KB_ALTERNATE_G},
    {KB_SCAN_CODE_H,	            KB_H,            	KB_SHIFT_H,	                KB_ALTERNATE_H},
    {KB_SCAN_CODE_I,	            KB_I,	            KB_SHIFT_I, 	            KB_ALTERNATE_I},
    {KB_SCAN_CODE_J,            	KB_J,	            KB_SHIFT_J,	                KB_ALTERNATE_J},
    {KB_SCAN_CODE_K,	            KB_K,	            KB_SHIFT_K,	                KB_ALTERNATE_K},
    {KB_SCAN_CODE_L,	            KB_L,	            KB_SHIFT_L,	                KB_ALTERNATE_L},
    {KB_SCAN_CODE_M,	            KB_M,            	KB_SHIFT_M,	                KB_ALTERNATE_M},
    {KB_SCAN_CODE_N,	            KB_N,	            KB_SHIFT_N, 	            KB_ALTERNATE_N},
    {KB_SCAN_CODE_O,	            KB_O,            	KB_SHIFT_O,	                KB_ALTERNATE_O},
    {KB_SCAN_CODE_P,	            KB_P,	            KB_SHIFT_P,	                KB_ALTERNATE_P},
    {KB_SCAN_CODE_Q,	            KB_Q,	            KB_SHIFT_Q,	                KB_ALTERNATE_Q},
    {KB_SCAN_CODE_R,	            KB_R,	            KB_SHIFT_R,	                KB_ALTERNATE_R},
    {KB_SCAN_CODE_S,	            KB_S,            	KB_SHIFT_S, 	            KB_ALTERNATE_S},
    {KB_SCAN_CODE_T,	            KB_T,	            KB_SHIFT_T,	                KB_ALTERNATE_T},
    {KB_SCAN_CODE_U,            	KB_U,	            KB_SHIFT_U,	                KB_ALTERNATE_U},
    {KB_SCAN_CODE_V,	            KB_V,	            KB_SHIFT_V,	                KB_ALTERNATE_V},
    {KB_SCAN_CODE_W,	            KB_W,            	KB_SHIFT_W,	                KB_ALTERNATE_W},
    {KB_SCAN_CODE_X,	            KB_X,	            KB_SHIFT_X, 	            KB_ALTERNATE_X},
    {KB_SCAN_CODE_Y,	            KB_Y,	            KB_SHIFT_Y,	                KB_ALTERNATE_Y},
    {KB_SCAN_CODE_Z,	            KB_Z,	            KB_SHIFT_Z,	                KB_ALTERNATE_Z},
    {KB_SCAN_CODE_APOSTROPHE,	    KB_APOSTROPHE,	    KB_SHIFT_APOSTROPHE,	    KB_ALTERNATE_APOSTROPHE},
    {KB_SCAN_CODE_MINUS,        	KB_MINUS,	        KB_SHIFT_MINUS,	            KB_ALTERNATE_MINUS},
    {KB_SCAN_CODE_EQUAL_TO,	        KB_EQUAL_TO,	    KB_SHIFT_EQUAL_TO,	        KB_ALTERNATE_EQUAL_TO},
    {KB_SCAN_CODE_LEFT_BRACKET, 	KB_LEFT_BRACKET,	KB_SHIFT_LEFT_BRACKET,	    KB_ALTERNATE_LEFT_BRACKET},
    {KB_SCAN_CODE_RIGHT_BRACKET,	KB_RIGHT_BRACKET,	KB_SHIFT_RIGHT_BRACKET,	    KB_ALTERNATE_RIGHT_BRACKET},
    {KB_SCAN_CODE_COMMA,	        KB_COMMA,	        KB_SHIFT_COMMA,	            KB_ALTERNATE_COMMA},
    {KB_SCAN_CODE_FULL_STOP,	    KB_FULL_STOP,	    KB_SHIFT_FULL_STOP,	        KB_ALTERNATE_FULL_STOP},
    {KB_SCAN_CODE_SEMI_COLON,	    KB_SEMI_COLON,	    KB_SHIFT_SEMI_COLON,	    KB_ALTERNATE_SEMI_COLON},
    {KB_SCAN_CODE_BACK_SLASH,	    KB_BACK_SLASH,	    KB_SHIFT_BACK_SLASH,	    KB_ALTERNATE_BACK_SLASH},
    {KB_SCAN_CODE_SINGLE_QUOTES,	KB_SINGLE_QUOTES,	KB_SHIFT_SINGLE_QUOTES, 	KB_ALTERNATE_SINGLE_QUOTES},
    {KB_SCAN_CODE_FORWARD_SLASH,	KB_FORWARD_SLASH,	KB_SHIFT_FORWARD_SLASH, 	KB_ALTERNATE_FORWARD_SLASH},
    {KB_SCAN_CODE_F1,	            KB_F1,	            KB_SHIFT_F1,	            KB_ALTERNATE_F1},
    {KB_SCAN_CODE_F2,	            KB_F2,	            KB_SHIFT_F2,                KB_ALTERNATE_F2},
    {KB_SCAN_CODE_F3,	            KB_F3,	            KB_SHIFT_F3,	            KB_ALTERNATE_F3},
    {KB_SCAN_CODE_F4,	            KB_F4,	            KB_SHIFT_F4,    	        KB_ALTERNATE_F4},
    {KB_SCAN_CODE_F5,	            KB_F5,	            KB_SHIFT_F5,	            KB_ALTERNATE_F5},
    {KB_SCAN_CODE_F6,	            KB_F6,	            KB_SHIFT_F6,	            KB_ALTERNATE_F6},
    {KB_SCAN_CODE_F7,	            KB_F7,	            KB_SHIFT_F7,	            KB_ALTERNATE_F7},
    {KB_SCAN_CODE_F8,	            KB_F8,	            KB_SHIFT_F8,	            KB_ALTERNATE_F8},
    {KB_SCAN_CODE_F9,	            KB_F9,	            KB_SHIFT_F9,	            KB_ALTERNATE_F9},
    {KB_SCAN_CODE_F10,	            KB_F10,         	KB_SHIFT_F10,	            KB_ALTERNATE_F10},
    {KB_SCAN_CODE_F11,	            KB_F11,	            KB_SHIFT_F11,	            KB_ALTERNATE_F11},
    {KB_SCAN_CODE_F12,	            KB_F12,	            KB_SHIFT_F12,	            KB_ALTERNATE_F12},
    {KB_SCAN_CODE_KEYPAD_0,	        KB_KEYPAD_0,    	KB_SHIFT_KEYPAD_0,	        KB_ALTERNATE_KEYPAD_0},
    {KB_SCAN_CODE_KEYPAD_1,	        KB_KEYPAD_1,	    KB_SHIFT_KEYPAD_1,	        KB_ALTERNATE_KEYPAD_1},
    {KB_SCAN_CODE_KEYPAD_2,	        KB_KEYPAD_2,	    KB_SHIFT_KEYPAD_2,	        KB_ALTERNATE_KEYPAD_2},
    {KB_SCAN_CODE_KEYPAD_3,	        KB_KEYPAD_3,    	KB_SHIFT_KEYPAD_3,	        KB_ALTERNATE_KEYPAD_3},
    {KB_SCAN_CODE_KEYPAD_4,	        KB_KEYPAD_4,	    KB_SHIFT_KEYPAD_4,	        KB_ALTERNATE_KEYPAD_4},
    {KB_SCAN_CODE_KEYPAD_5,	        KB_KEYPAD_5,    	KB_SHIFT_KEYPAD_5,	        KB_ALTERNATE_KEYPAD_5},
    {KB_SCAN_CODE_KEYPAD_6,	        KB_KEYPAD_6,	    KB_SHIFT_KEYPAD_6,	        KB_ALTERNATE_KEYPAD_6},
    {KB_SCAN_CODE_KEYPAD_7,	        KB_KEYPAD_7,    	KB_SHIFT_KEYPAD_7,	        KB_ALTERNATE_KEYPAD_7},
    {KB_SCAN_CODE_KEYPAD_8,        	KB_KEYPAD_8,	    KB_SHIFT_KEYPAD_8,	        KB_ALTERNATE_KEYPAD_8},
    {KB_SCAN_CODE_KEYPAD_9,        	KB_KEYPAD_9,    	KB_SHIFT_KEYPAD_9,	        KB_ALTERNATE_KEYPAD_9},
    {KB_SCAN_CODE_KEYPAD_DOT,	    KB_KEYPAD_DOT,	    KB_SHIFT_KEYPAD_DOT,	    KB_ALTERNATE_KEYPAD_DOT},
    {KB_SCAN_CODE_KEYPAD_ASTERIK,	KB_KEYPAD_ASTERIK,	KB_SHIFT_KEYPAD_ASTERIK,    KB_ALTERNATE_KEYPAD_ASTERIK},
    {KB_SCAN_CODE_KEYPAD_MINUS,	    KB_KEYPAD_MINUS,	KB_SHIFT_KEYPAD_MINUS,	    KB_ALTERNATE_KEYPAD_MINUS},
    {KB_SCAN_CODE_KEYPAD_PLUS,	    KB_KEYPAD_PLUS,	    KB_SHIFT_KEYPAD_PLUS,   	KB_ALTERNATE_KEYPAD_PLUS},
	{KB_SCAN_CODE_PRINT_SCREEN,	    KB_PRINT_SCREEN,	KB_SHIFT_PRINT_SCREEN,	    KB_ALTERNATE_PRINT_SCREEN},
    {KB_SCAN_CODE_PAUSE,        	KB_PAUSE,	        KB_SHIFT_PAUSE,	            KB_ALTERNATE_PAUSE},

    {KB_SCAN_CODE_LEFT_GUI,	        KB_LEFT_GUI,	    KB_SHIFT_LEFT_GUI,	        KB_ALTERNATE_LEFT_GUI},
    {KB_SCAN_CODE_RIGHT_CONTROL,	KB_RIGHT_CONTROL,	KB_SHIFT_RIGHT_CONTROL,	    KB_ALTERNATE_RIGHT_CONTROL},
    {KB_SCAN_CODE_RIGHT_ALTERNATE,	KB_RIGHT_ALTERNATE,	KB_SHIFT_RIGHT_ALTERNATE,	KB_ALTERNATE_RIGHT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_GUI,	    KB_RIGHT_GUI,	    KB_SHIFT_RIGHT_GUI,	        KB_ALTERNATE_RIGHT_GUI},
    {KB_SCAN_CODE_INSERT,	        KB_INSERT,	        KB_SHIFT_INSERT,	        KB_ALTERNATE_INSERT},
    {KB_SCAN_CODE_DELETE,	        KB_DELETE,      	KB_SHIFT_DELETE,	        KB_ALTERNATE_DELETE},
    {KB_SCAN_CODE_ARROW_UP,	        KB_ARROW_UP,	    KB_SHIFT_ARROW_UP,	        KB_ALTERNATE_ARROW_UP},
    {KB_SCAN_CODE_ARROW_DOWN,	    KB_ARROW_DOWN,	    KB_SHIFT_ARROW_DOWN,	    KB_ALTERNATE_ARROW_DOWN},
    {KB_SCAN_CODE_ARROW_LEFT,	    KB_ARROW_LEFT,	    KB_SHIFT_ARROW_LEFT,	    KB_ALTERNATE_ARROW_LEFT},
    {KB_SCAN_CODE_ARROW_RIGHT,	    KB_ARROW_RIGHT,	    KB_SHIFT_ARROW_RIGHT,	    KB_ALTERNATE_ARROW_RIGHT},
    {KB_SCAN_CODE_HOME,	            KB_HOME,	        KB_SHIFT_HOME,	            KB_ALTERNATE_HOME},
    {KB_SCAN_CODE_END,	            KB_END,	            KB_SHIFT_END,	            KB_ALTERNATE_END},
    {KB_SCAN_CODE_PAGE_DOWN,	    KB_PAGE_DOWN,	    KB_SHIFT_PAGE_DOWN,	        KB_ALTERNATE_PAGE_DOWN},
    {KB_SCAN_CODE_PAGE_UP,	        KB_PAGE_UP,	        KB_SHIFT_PAGE_UP,	        KB_ALTERNATE_PAGE_UP},
    {KB_SCAN_CODE_KEYPAD_ENTER,	    KB_KEYPAD_ENTER,	KB_SHIFT_KEYPAD_ENTER,	    KB_ALTERNATE_KEYPAD_ENTER},
    {KB_SCAN_CODE_KEYPAD_BACKSLASH,	KB_KEYPAD_BACKSLASH,KB_SHIFT_KEYPAD_BACKSLASH,	KB_ALTERNATE_KEYPAD_BACKSLASH},
    {KB_SCAN_CODE_APPS,           	KB_APPS, 	        KB_SHIFT_APPS,          	KB_ALTERNATE_APPS}

    #if (KB_USE_ACPI_KEYS)

    ,{KB_SCAN_CODE_POWER,         	KB_POWER,  	        KB_SHIFT_POWER,	            KB_ALTERNATE_POWER},
    {KB_SCAN_CODE_SLEEP,            KB_SLEEP,    	    KB_SHIFT_SLEEP,	            KB_ALTERNATE_SLEEP},
    {KB_SCAN_CODE_WAKE,           	KB_WAKE,          	KB_SHIFT_WAKE,	            KB_ALTERNATE_WAKE}

    #endif

    #if (KB_USE_WINDOWS_MULTIMEDIA_KEYS)

    ,{KB_SCAN_CODE_NEXT_TRACK,    	KB_NEXT_TRACK,  	KB_SHIFT_NEXT_TRACK,	    KB_ALTERNATE_NEXT_TRACK},
    {KB_SCAN_CODE_PREVIOUS_TRACK,   KB_PREVIOUS_TRACK,  KB_SHIFT_PREVIOUS_TRACK,	KB_ALTERNATE_PREVIOUS_TRACK},
    {KB_SCAN_CODE_STOP,      	    KB_STOP,          	KB_SHIFT_STOP,	            KB_ALTERNATE_STOP},
    {KB_SCAN_CODE_PLAY_OR_PAUSE,  	KB_PLAY_OR_PAUSE,  	KB_SHIFT_PLAY_OR_PAUSE,	    KB_ALTERNATE_PLAY_OR_PAUSE},
    {KB_SCAN_CODE_MUTE,        	    KB_MUTE,            KB_SHIFT_MUTE,	            KB_ALTERNATE_MUTE},
    {KB_SCAN_CODE_VOLUME_UP,  	    KB_VOLUME_UP,       KB_SHIFT_VOLUME_UP,	        KB_ALTERNATE_VOLUME_UP},
    {KB_SCAN_CODE_VOLUME_DOWN, 	    KB_VOLUME_DOWN,  	KB_SHIFT_VOLUME_DOWN,	    KB_ALTERNATE_VOLUME_DOWN},
    {KB_SCAN_CODE_MEDIA_SELECT,   	KB_MEDIA_SELECT, 	KB_SHIFT_MEDIA_SELECT,	    KB_ALTERNATE_MEDIA_SELECT},
    {KB_SCAN_CODE_E_MAIL,        	KB_E_MAIL,       	KB_SHIFT_E_MAIL,	        KB_ALTERNATE_E_MAIL},
    {KB_SCAN_CODE_CALCULATOR, 	    KB_CALCULATOR, 	    KB_SHIFT_CALCULATOR,	    KB_ALTERNATE_CALCULATOR},
    {KB_SCAN_CODE_COMPUTER,       	KB_COMPUTER,   	    KB_SHIFT_COMPUTER,	        KB_ALTERNATE_COMPUTER},
    {KB_SCAN_CODE_WWW_SEARCH, 	    KB_WWW_SEARCH,  	KB_SHIFT_WWW_SEARCH,	    KB_ALTERNATE_WWW_SEARCH},
    {KB_SCAN_CODE_WWW_HOME,    	    KB_WWW_HOME,  	    KB_SHIFT_WWW_HOME,	        KB_ALTERNATE_WWW_HOME},
    {KB_SCAN_CODE_WWW_BACK,    	    KB_WWW_BACK,     	KB_SHIFT_WWW_BACK,	        KB_ALTERNATE_WWW_BACK},
    {KB_SCAN_CODE_WWW_FORWARD,    	KB_WWW_FORWARD, 	KB_SHIFT_WWW_FORWARD,	    KB_ALTERNATE_WWW_FORWARD},
    {KB_SCAN_CODE_WWW_STOP,       	KB_WWW_STOP,     	KB_SHIFT_WWW_STOP,	        KB_ALTERNATE_WWW_STOP},
    {KB_SCAN_CODE_WWW_REFRESH,   	KB_WWW_REFRESH,   	KB_SHIFT_WWW_REFRESH,	    KB_ALTERNATE_WWW_REFRESH},
    {KB_SCAN_CODE_WWW_FAVORITES,	KB_WWW_FAVORITES,	KB_SHIFT_WWW_FAVORITES,	    KB_ALTERNATE_WWW_FAVORITES}

	#endif
};

#endif

#if ((KB_USE_CONTROL_COMBINATIONS)&&(KB_USE_ALTERNATE_COMBINATIONS))

const unsigned char kb_LUT[][5] PROGMEM =
{
    {KB_SCAN_CODE_SPACE,	        KB_SPACE,	        KB_SHIFT_SPACE,	            KB_CONTROL_SPACE,	        KB_ALTERNATE_SPACE},
    {KB_SCAN_CODE_ENTER,	        KB_ENTER,	        KB_SHIFT_ENTER,             KB_CONTROL_ENTER,	        KB_ALTERNATE_ENTER},
    {KB_SCAN_CODE_BACKSPACE,	    KB_BACKSPACE,   	KB_SHIFT_BACKSPACE,	        KB_CONTROL_BACKSPACE,	    KB_ALTERNATE_BACKSPACE},
    {KB_SCAN_CODE_ESCAPE,	        KB_ESCAPE,      	KB_SHIFT_ESCAPE,	        KB_CONTROL_ESCAPE,	        KB_ALTERNATE_ESCAPE},
    {KB_SCAN_CODE_TAB,          	KB_TAB,	            KB_SHIFT_TAB,	            KB_CONTROL_TAB,	            KB_ALTERNATE_TAB},
    {KB_SCAN_CODE_LEFT_SHIFT,	    KB_LEFT_SHIFT,	    KB_SHIFT_LEFT_SHIFT,	    KB_CONTROL_LEFT_SHIFT,	    KB_ALTERNATE_LEFT_SHIFT},
    {KB_SCAN_CODE_LEFT_CONTROL,	    KB_LEFT_CONTROL,	KB_SHIFT_LEFT_CONTROL,	    KB_CONTROL_LEFT_CONTROL,	KB_ALTERNATE_LEFT_CONTROL},
    {KB_SCAN_CODE_LEFT_ALTERNATE,	KB_LEFT_ALTERNATE,	KB_SHIFT_LEFT_ALTERNATE,	KB_CONTROL_LEFT_ALTERNATE,	KB_ALTERNATE_LEFT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_SHIFT,	    KB_RIGHT_SHIFT,	    KB_SHIFT_RIGHT_SHIFT,	    KB_CONTROL_RIGHT_SHIFT,	    KB_ALTERNATE_RIGHT_SHIFT},
    {KB_SCAN_CODE_CAPS_LOCK,	    KB_CAPS_LOCK,	    KB_SHIFT_CAPS_LOCK,	        KB_CONTROL_CAPS_LOCK,	    KB_ALTERNATE_CAPS_LOCK},
    {KB_SCAN_CODE_NUMBER_LOCK,	    KB_NUMBER_LOCK,	    KB_SHIFT_NUMBER_LOCK,	    KB_CONTROL_NUMBER_LOCK,	    KB_ALTERNATE_NUMBER_LOCK},
    {KB_SCAN_CODE_SCROLL_LOCK,	    KB_SCROLL_LOCK,	    KB_SHIFT_SCROLL_LOCK,	    KB_CONTROL_SCROLL_LOCK,	    KB_ALTERNATE_SCROLL_LOCK},
    {KB_SCAN_CODE_0,	            KB_0,            	KB_SHIFT_0,             	KB_CONTROL_0,            	KB_ALTERNATE_0},
    {KB_SCAN_CODE_1,            	KB_1,            	KB_SHIFT_1,             	KB_CONTROL_1,	         	KB_ALTERNATE_1},
    {KB_SCAN_CODE_2,	            KB_2,            	KB_SHIFT_2,	            	KB_CONTROL_2,	         	KB_ALTERNATE_2},
    {KB_SCAN_CODE_3,	            KB_3,	            KB_SHIFT_3,	            	KB_CONTROL_3,	         	KB_ALTERNATE_3},
    {KB_SCAN_CODE_4,	            KB_4,	            KB_SHIFT_4,	            	KB_CONTROL_4,         		KB_ALTERNATE_4},
    {KB_SCAN_CODE_5,	            KB_5,            	KB_SHIFT_5,	            	KB_CONTROL_5,	         	KB_ALTERNATE_5},
    {KB_SCAN_CODE_6,	            KB_6,            	KB_SHIFT_6,	            	KB_CONTROL_6,	         	KB_ALTERNATE_6},
    {KB_SCAN_CODE_7,            	KB_7,	            KB_SHIFT_7,	            	KB_CONTROL_7,	         	KB_ALTERNATE_7},
    {KB_SCAN_CODE_8,	            KB_8,	            KB_SHIFT_8,	            	KB_CONTROL_8,	         	KB_ALTERNATE_8},
    {KB_SCAN_CODE_9,            	KB_9,            	KB_SHIFT_9,	            	KB_CONTROL_9,	         	KB_ALTERNATE_9},
    {KB_SCAN_CODE_A,	            KB_A,	            KB_SHIFT_A,	            	KB_CONTROL_A,	         	KB_ALTERNATE_A},
    {KB_SCAN_CODE_B,	            KB_B,	            KB_SHIFT_B,	            	KB_CONTROL_B,         		KB_ALTERNATE_B},
    {KB_SCAN_CODE_C,            	KB_C,            	KB_SHIFT_C,	            	KB_CONTROL_C,	         	KB_ALTERNATE_C},
    {KB_SCAN_CODE_D,	            KB_D,	            KB_SHIFT_D,	            	KB_CONTROL_D,         		KB_ALTERNATE_D},
    {KB_SCAN_CODE_E,	            KB_E,	            KB_SHIFT_E,	            	KB_CONTROL_E,	         	KB_ALTERNATE_E},
    {KB_SCAN_CODE_F,	            KB_F,	            KB_SHIFT_F,            		KB_CONTROL_F,	         	KB_ALTERNATE_F},
    {KB_SCAN_CODE_G,	            KB_G,	            KB_SHIFT_G,            		KB_CONTROL_G,	         	KB_ALTERNATE_G},
    {KB_SCAN_CODE_H,	            KB_H,            	KB_SHIFT_H,            		KB_CONTROL_H,	         	KB_ALTERNATE_H},
    {KB_SCAN_CODE_I,	            KB_I,	            KB_SHIFT_I,            		KB_CONTROL_I,         		KB_ALTERNATE_I},
    {KB_SCAN_CODE_J,            	KB_J,	            KB_SHIFT_J,            		KB_CONTROL_J,	         	KB_ALTERNATE_J},
    {KB_SCAN_CODE_K,	            KB_K,	            KB_SHIFT_K,            		KB_CONTROL_K,         		KB_ALTERNATE_K},
    {KB_SCAN_CODE_L,	            KB_L,	            KB_SHIFT_L,	            	KB_CONTROL_L,	         	KB_ALTERNATE_L},
    {KB_SCAN_CODE_M,	            KB_M,            	KB_SHIFT_M,	            	KB_CONTROL_M,	         	KB_ALTERNATE_M},
    {KB_SCAN_CODE_N,	            KB_N,	            KB_SHIFT_N,             	KB_CONTROL_N,	         	KB_ALTERNATE_N},
    {KB_SCAN_CODE_O,	            KB_O,            	KB_SHIFT_O,	            	KB_CONTROL_O,	         	KB_ALTERNATE_O},
    {KB_SCAN_CODE_P,	            KB_P,	            KB_SHIFT_P,	            	KB_CONTROL_P,	         	KB_ALTERNATE_P},
    {KB_SCAN_CODE_Q,	            KB_Q,	            KB_SHIFT_Q,	            	KB_CONTROL_Q,	         	KB_ALTERNATE_Q},
    {KB_SCAN_CODE_R,	            KB_R,	            KB_SHIFT_R,	            	KB_CONTROL_R,	         	KB_ALTERNATE_R},
    {KB_SCAN_CODE_S,	            KB_S,            	KB_SHIFT_S,	            	KB_CONTROL_S,	         	KB_ALTERNATE_S},
    {KB_SCAN_CODE_T,	            KB_T,	            KB_SHIFT_T,	            	KB_CONTROL_T,	         	KB_ALTERNATE_T},
    {KB_SCAN_CODE_U,            	KB_U,	            KB_SHIFT_U,	            	KB_CONTROL_U,	         	KB_ALTERNATE_U},
    {KB_SCAN_CODE_V,	            KB_V,	            KB_SHIFT_V,            		KB_CONTROL_V,	         	KB_ALTERNATE_V},
    {KB_SCAN_CODE_W,	            KB_W,            	KB_SHIFT_W,            		KB_CONTROL_W,	         	KB_ALTERNATE_W},
    {KB_SCAN_CODE_X,	            KB_X,	            KB_SHIFT_X,            		KB_CONTROL_X,         		KB_ALTERNATE_X},
    {KB_SCAN_CODE_Y,	            KB_Y,	            KB_SHIFT_Y,	            	KB_CONTROL_Y,         		KB_ALTERNATE_Y},
    {KB_SCAN_CODE_Z,	            KB_Z,	            KB_SHIFT_Z,	            	KB_CONTROL_Z,	         	KB_ALTERNATE_Z},
    {KB_SCAN_CODE_APOSTROPHE,	    KB_APOSTROPHE,	    KB_SHIFT_APOSTROPHE,	    KB_CONTROL_APOSTROPHE,  	KB_ALTERNATE_APOSTROPHE},
    {KB_SCAN_CODE_MINUS,        	KB_MINUS,	        KB_SHIFT_MINUS,	            KB_CONTROL_MINUS,       	KB_ALTERNATE_MINUS},
    {KB_SCAN_CODE_EQUAL_TO,	        KB_EQUAL_TO,	    KB_SHIFT_EQUAL_TO,	        KB_CONTROL_EQUAL_TO,	    KB_ALTERNATE_EQUAL_TO},
    {KB_SCAN_CODE_LEFT_BRACKET, 	KB_LEFT_BRACKET,	KB_SHIFT_LEFT_BRACKET,	    KB_CONTROL_LEFT_BRACKET,	KB_ALTERNATE_LEFT_BRACKET},
    {KB_SCAN_CODE_RIGHT_BRACKET,	KB_RIGHT_BRACKET,	KB_SHIFT_RIGHT_BRACKET, 	KB_CONTROL_RIGHT_BRACKET,	KB_ALTERNATE_RIGHT_BRACKET},
    {KB_SCAN_CODE_COMMA,	        KB_COMMA,	        KB_SHIFT_COMMA,	            KB_CONTROL_COMMA,       	KB_ALTERNATE_COMMA},
    {KB_SCAN_CODE_FULL_STOP,	    KB_FULL_STOP,	    KB_SHIFT_FULL_STOP,	        KB_CONTROL_FULL_STOP,	    KB_ALTERNATE_FULL_STOP},
    {KB_SCAN_CODE_SEMI_COLON,	    KB_SEMI_COLON,	    KB_SHIFT_SEMI_COLON,	    KB_CONTROL_SEMI_COLON,	    KB_ALTERNATE_SEMI_COLON},
    {KB_SCAN_CODE_BACK_SLASH,	    KB_BACK_SLASH,	    KB_SHIFT_BACK_SLASH,	    KB_CONTROL_BACK_SLASH,	    KB_ALTERNATE_BACK_SLASH},
    {KB_SCAN_CODE_SINGLE_QUOTES,	KB_SINGLE_QUOTES,	KB_SHIFT_SINGLE_QUOTES,	    KB_CONTROL_SINGLE_QUOTES,	KB_ALTERNATE_SINGLE_QUOTES},
    {KB_SCAN_CODE_FORWARD_SLASH,	KB_FORWARD_SLASH,	KB_SHIFT_FORWARD_SLASH,	    KB_CONTROL_FORWARD_SLASH,	KB_ALTERNATE_FORWARD_SLASH},
    {KB_SCAN_CODE_F1,	            KB_F1,	            KB_SHIFT_F1,    	        KB_CONTROL_F1,          	KB_ALTERNATE_F1},
    {KB_SCAN_CODE_F2,	            KB_F2,	            KB_SHIFT_F2,	            KB_CONTROL_F2,	            KB_ALTERNATE_F2},
    {KB_SCAN_CODE_F3,	            KB_F3,	            KB_SHIFT_F3,		        KB_CONTROL_F3,          	KB_ALTERNATE_F3},
    {KB_SCAN_CODE_F4,	            KB_F4,	            KB_SHIFT_F4,		        KB_CONTROL_F4,	            KB_ALTERNATE_F4},
    {KB_SCAN_CODE_F5,	            KB_F5,	            KB_SHIFT_F5,	        	KB_CONTROL_F5,	            KB_ALTERNATE_F5},
    {KB_SCAN_CODE_F6,	            KB_F6,	            KB_SHIFT_F6,	        	KB_CONTROL_F6,	            KB_ALTERNATE_F6},
    {KB_SCAN_CODE_F7,	            KB_F7,	            KB_SHIFT_F7,	        	KB_CONTROL_F7,	            KB_ALTERNATE_F7},
    {KB_SCAN_CODE_F8,	            KB_F8,	            KB_SHIFT_F8,		        KB_CONTROL_F8,	            KB_ALTERNATE_F8},
    {KB_SCAN_CODE_F9,	            KB_F9,	            KB_SHIFT_F9,		        KB_CONTROL_F9,	            KB_ALTERNATE_F9},
    {KB_SCAN_CODE_F10,	            KB_F10,         	KB_SHIFT_F10,		        KB_CONTROL_F10,	            KB_ALTERNATE_F10},
    {KB_SCAN_CODE_F11,	            KB_F11,	            KB_SHIFT_F11,		        KB_CONTROL_F11,             KB_ALTERNATE_F11},
    {KB_SCAN_CODE_F12,	            KB_F12,	            KB_SHIFT_F12,		        KB_CONTROL_F12,	            KB_ALTERNATE_F12},
    {KB_SCAN_CODE_KEYPAD_0,	        KB_KEYPAD_0,    	KB_SHIFT_KEYPAD_0,		    KB_CONTROL_KEYPAD_0,    	KB_ALTERNATE_KEYPAD_0},
    {KB_SCAN_CODE_KEYPAD_1,	        KB_KEYPAD_1,	    KB_SHIFT_KEYPAD_1,	        KB_CONTROL_KEYPAD_1,    	KB_ALTERNATE_KEYPAD_1},
    {KB_SCAN_CODE_KEYPAD_2,	        KB_KEYPAD_2,	    KB_SHIFT_KEYPAD_2,	        KB_CONTROL_KEYPAD_2,	    KB_ALTERNATE_KEYPAD_2},
    {KB_SCAN_CODE_KEYPAD_3,	        KB_KEYPAD_3,    	KB_SHIFT_KEYPAD_3,	        KB_CONTROL_KEYPAD_3,    	KB_ALTERNATE_KEYPAD_3},
    {KB_SCAN_CODE_KEYPAD_4,         KB_KEYPAD_4,	    KB_SHIFT_KEYPAD_4,	        KB_CONTROL_KEYPAD_4,	    KB_ALTERNATE_KEYPAD_4},
    {KB_SCAN_CODE_KEYPAD_5,	        KB_KEYPAD_5,    	KB_SHIFT_KEYPAD_5,	        KB_CONTROL_KEYPAD_5,    	KB_ALTERNATE_KEYPAD_5},
    {KB_SCAN_CODE_KEYPAD_6,	        KB_KEYPAD_6,	    KB_SHIFT_KEYPAD_6,	        KB_CONTROL_KEYPAD_6,	    KB_ALTERNATE_KEYPAD_6},
    {KB_SCAN_CODE_KEYPAD_7,	        KB_KEYPAD_7,    	KB_SHIFT_KEYPAD_7,	        KB_CONTROL_KEYPAD_7,	    KB_ALTERNATE_KEYPAD_7},
    {KB_SCAN_CODE_KEYPAD_8,        	KB_KEYPAD_8,	    KB_SHIFT_KEYPAD_8,	        KB_CONTROL_KEYPAD_8,	    KB_ALTERNATE_KEYPAD_8},
    {KB_SCAN_CODE_KEYPAD_9,        	KB_KEYPAD_9,    	KB_SHIFT_KEYPAD_9,	        KB_CONTROL_KEYPAD_9,    	KB_ALTERNATE_KEYPAD_9},
    {KB_SCAN_CODE_KEYPAD_DOT,	    KB_KEYPAD_DOT,	    KB_SHIFT_KEYPAD_DOT,	    KB_CONTROL_KEYPAD_DOT,	    KB_ALTERNATE_KEYPAD_DOT},
    {KB_SCAN_CODE_KEYPAD_ASTERIK,	KB_KEYPAD_ASTERIK,	KB_SHIFT_KEYPAD_ASTERIK,	KB_CONTROL_KEYPAD_ASTERIK,	KB_ALTERNATE_KEYPAD_ASTERIK},
    {KB_SCAN_CODE_KEYPAD_MINUS,	    KB_KEYPAD_MINUS,	KB_SHIFT_KEYPAD_MINUS,	    KB_CONTROL_KEYPAD_MINUS,	KB_ALTERNATE_KEYPAD_MINUS},
    {KB_SCAN_CODE_KEYPAD_PLUS,	    KB_KEYPAD_PLUS,	    KB_SHIFT_KEYPAD_PLUS,	    KB_CONTROL_KEYPAD_PLUS,	    KB_ALTERNATE_KEYPAD_PLUS},
    {KB_SCAN_CODE_PRINT_SCREEN,	    KB_PRINT_SCREEN,	KB_SHIFT_PRINT_SCREEN,	    KB_CONTROL_PRINT_SCREEN,	KB_ALTERNATE_PRINT_SCREEN},
    {KB_SCAN_CODE_PAUSE,            KB_PAUSE,           KB_SHIFT_PAUSE,             KB_CONTROL_PAUSE,           KB_ALTERNATE_PAUSE},


    {KB_SCAN_CODE_LEFT_GUI,	        KB_LEFT_GUI,	    KB_SHIFT_LEFT_GUI,	        KB_CONTROL_LEFT_GUI,	    KB_ALTERNATE_LEFT_GUI},
    {KB_SCAN_CODE_RIGHT_CONTROL,	KB_RIGHT_CONTROL,	KB_SHIFT_RIGHT_CONTROL,	    KB_CONTROL_RIGHT_CONTROL,	KB_ALTERNATE_RIGHT_CONTROL},
    {KB_SCAN_CODE_RIGHT_ALTERNATE,	KB_RIGHT_ALTERNATE,	KB_SHIFT_RIGHT_ALTERNATE,	KB_CONTROL_RIGHT_ALTERNATE,	KB_ALTERNATE_RIGHT_ALTERNATE},
    {KB_SCAN_CODE_RIGHT_GUI,	    KB_RIGHT_GUI,	    KB_SHIFT_RIGHT_GUI,	        KB_CONTROL_RIGHT_GUI,	    KB_ALTERNATE_RIGHT_GUI},
    {KB_SCAN_CODE_INSERT,	        KB_INSERT,	        KB_SHIFT_INSERT,	        KB_CONTROL_INSERT,	        KB_ALTERNATE_INSERT},
    {KB_SCAN_CODE_DELETE,	        KB_DELETE,      	KB_SHIFT_DELETE,        	KB_CONTROL_DELETE,	        KB_ALTERNATE_DELETE},
    {KB_SCAN_CODE_ARROW_UP,	        KB_ARROW_UP,	    KB_SHIFT_ARROW_UP,	        KB_CONTROL_ARROW_UP,	    KB_ALTERNATE_ARROW_UP},
    {KB_SCAN_CODE_ARROW_DOWN,	    KB_ARROW_DOWN,	    KB_SHIFT_ARROW_DOWN,	    KB_CONTROL_ARROW_DOWN,	    KB_ALTERNATE_ARROW_DOWN},
    {KB_SCAN_CODE_ARROW_LEFT,	    KB_ARROW_LEFT,	    KB_SHIFT_ARROW_LEFT,	    KB_CONTROL_ARROW_LEFT,	    KB_ALTERNATE_ARROW_LEFT},
    {KB_SCAN_CODE_ARROW_RIGHT,	    KB_ARROW_RIGHT,	    KB_SHIFT_ARROW_RIGHT,	    KB_CONTROL_ARROW_RIGHT, 	KB_ALTERNATE_ARROW_RIGHT},
    {KB_SCAN_CODE_HOME,	            KB_HOME,	        KB_SHIFT_HOME,	            KB_CONTROL_HOME,        	KB_ALTERNATE_HOME},
    {KB_SCAN_CODE_END,	            KB_END,	            KB_SHIFT_END,           	KB_CONTROL_END,	            KB_ALTERNATE_END},
    {KB_SCAN_CODE_PAGE_DOWN,	    KB_PAGE_DOWN,	    KB_SHIFT_PAGE_DOWN,	        KB_CONTROL_PAGE_DOWN,	    KB_ALTERNATE_PAGE_DOWN},
    {KB_SCAN_CODE_PAGE_UP,	        KB_PAGE_UP,	        KB_SHIFT_PAGE_UP,	        KB_CONTROL_PAGE_UP,     	KB_ALTERNATE_PAGE_UP},
    {KB_SCAN_CODE_KEYPAD_ENTER,	    KB_KEYPAD_ENTER,	KB_SHIFT_KEYPAD_ENTER,	    KB_CONTROL_KEYPAD_ENTER,	KB_ALTERNATE_KEYPAD_ENTER},
    //102
    {KB_SCAN_CODE_KEYPAD_BACKSLASH,	KB_KEYPAD_BACKSLASH,KB_SHIFT_KEYPAD_BACKSLASH,	KB_CONTROL_KEYPAD_BACKSLASH,KB_ALTERNATE_KEYPAD_BACKSLASH},
    {KB_SCAN_CODE_APPS,             KB_APPS,            KB_SHIFT_APPS,              KB_CONTROL_APPS,            KB_ALTERNATE_APPS}

    #if (KB_USE_ACPI_KEYS)

    ,{KB_SCAN_CODE_POWER,            KB_POWER,           KB_SHIFT_POWER,             KB_CONTROL_POWER,           KB_ALTERNATE_POWER},
    {KB_SCAN_CODE_SLEEP,            KB_SLEEP,           KB_SHIFT_SLEEP,             KB_CONTROL_SLEEP,           KB_ALTERNATE_SLEEP},
    {KB_SCAN_CODE_WAKE,             KB_WAKE,            KB_SHIFT_WAKE,              KB_CONTROL_WAKE,            KB_ALTERNATE_WAKE}

    #endif

    #if (KB_USE_WINDOWS_MULTIMEDIA_KEYS)

    ,{KB_SCAN_CODE_NEXT_TRACK,       KB_NEXT_TRACK,      KB_SHIFT_NEXT_TRACK,        KB_CONTROL_NEXT_TRACK,      KB_ALTERNATE_NEXT_TRACK},
    {KB_SCAN_CODE_PREVIOUS_TRACK,   KB_PREVIOUS_TRACK,  KB_SHIFT_PREVIOUS_TRACK,    KB_CONTROL_PREVIOUS_TRACK,  KB_ALTERNATE_PREVIOUS_TRACK},
    {KB_SCAN_CODE_STOP,             KB_STOP,            KB_SHIFT_STOP,              KB_CONTROL_STOP,            KB_ALTERNATE_STOP},
    {KB_SCAN_CODE_PLAY_OR_PAUSE,    KB_PLAY_OR_PAUSE,   KB_SHIFT_PLAY_OR_PAUSE,     KB_CONTROL_PLAY_OR_PAUSE,   KB_ALTERNATE_PLAY_OR_PAUSE},
    {KB_SCAN_CODE_MUTE,             KB_MUTE,            KB_SHIFT_MUTE,              KB_CONTROL_MUTE,            KB_ALTERNATE_MUTE},
    {KB_SCAN_CODE_VOLUME_UP,        KB_VOLUME_UP,       KB_SHIFT_VOLUME_UP,         KB_CONTROL_VOLUME_UP,       KB_ALTERNATE_VOLUME_UP},
    {KB_SCAN_CODE_VOLUME_DOWN,      KB_VOLUME_DOWN,     KB_SHIFT_VOLUME_DOWN,       KB_CONTROL_VOLUME_DOWN,     KB_ALTERNATE_VOLUME_DOWN},
    {KB_SCAN_CODE_MEDIA_SELECT,     KB_MEDIA_SELECT,    KB_SHIFT_MEDIA_SELECT,      KB_CONTROL_MEDIA_SELECT,    KB_ALTERNATE_MEDIA_SELECT},
    {KB_SCAN_CODE_E_MAIL,           KB_E_MAIL,          KB_SHIFT_E_MAIL,            KB_CONTROL_E_MAIL,          KB_ALTERNATE_E_MAIL},
    {KB_SCAN_CODE_CALCULATOR,       KB_CALCULATOR,      KB_SHIFT_CALCULATOR,        KB_CONTROL_CALCULATOR,      KB_ALTERNATE_CALCULATOR},
    {KB_SCAN_CODE_COMPUTER,         KB_COMPUTER,        KB_SHIFT_COMPUTER,          KB_CONTROL_COMPUTER,        KB_ALTERNATE_COMPUTER},
    {KB_SCAN_CODE_WWW_SEARCH,       KB_WWW_SEARCH,      KB_SHIFT_WWW_SEARCH,        KB_CONTROL_WWW_SEARCH,      KB_ALTERNATE_WWW_SEARCH},
    {KB_SCAN_CODE_WWW_HOME,         KB_WWW_HOME,        KB_SHIFT_WWW_HOME,          KB_CONTROL_WWW_HOME,        KB_ALTERNATE_WWW_HOME},
    {KB_SCAN_CODE_WWW_BACK,         KB_WWW_BACK,        KB_SHIFT_WWW_BACK,          KB_CONTROL_WWW_BACK,        KB_ALTERNATE_WWW_BACK},
    {KB_SCAN_CODE_WWW_FORWARD,      KB_WWW_FORWARD,     KB_SHIFT_WWW_FORWARD,       KB_CONTROL_WWW_FORWARD,     KB_ALTERNATE_WWW_FORWARD},
    {KB_SCAN_CODE_WWW_STOP,         KB_WWW_STOP,        KB_SHIFT_WWW_STOP,          KB_CONTROL_WWW_STOP,        KB_ALTERNATE_WWW_STOP},
    {KB_SCAN_CODE_WWW_REFRESH,      KB_WWW_REFRESH,     KB_SHIFT_WWW_REFRESH,       KB_CONTROL_WWW_REFRESH,     KB_ALTERNATE_WWW_REFRESH},
    {KB_SCAN_CODE_WWW_FAVORITES,    KB_WWW_FAVORITES,   KB_SHIFT_WWW_FAVORITES,     KB_CONTROL_WWW_FAVORITES,   KB_ALTERNATE_WWW_FAVORITES}

    #endif
};

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/


