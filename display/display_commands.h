#ifndef DISPLAY_COMMANDS_H
#define DISPLAY_COMMANDS_H

// LCD Commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// Flags for display entry mode
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYLEFT 0x02

// Flags for display and cursor control
#define LCD_BLINKON 0x01
#define LCD_CURSORON 0x02
#define LCD_DISPLAYON 0x04

// Flags for display and cursor shift
#define LCD_MOVERIGHT 0x04
#define LCD_DISPLAYMOVE 0x08

// Flags for function set
#define LCD_5x10DOTS 0x04
#define LCD_2LINE 0x08
#define LCD_8BITMODE 0x10

// Flag for backlight control
#define LCD_BACKLIGHT 0x08

#define LCD_ENABLE_BIT 0x04

// Modes for lcd_send_byte
#define LCD_CHARACTER  1
#define LCD_COMMAND    0

#endif // DISPLAY_COMMANDS_H