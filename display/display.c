#include "i2cmaster.h"
#include "kabeltester/display.h"

#include "display_commands.h"

#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#define DISPLAY_TWI_ADDRESS (0x27U)
#define SHIFTED_DISPLAY_ADDRESS (DISPLAY_TWI_ADDRESS << 1U)

// A small delay between LCD commands to allow the display to update.
// 600 us seems like a stable value.
#define DELAY_US (600U)

// Line- and character limits for the 2004a LCD display. Unsure what happens
// if you write outside of these regions.
#define MAX_LINES      4
#define MAX_CHARS      20

static const int line_offsets[] = { 0x00, 0x40, 0x14, 0x54 };

/* Quick helper function for single byte transfers */
static void i2c_WriteByte(uint8_t val) {
    (void) i2c_start(SHIFTED_DISPLAY_ADDRESS + I2C_WRITE);
    (void) i2c_write(val);
    i2c_stop();
    // Small write delay to prevent garbage data on the display
    _delay_us(DELAY_US);
}

static void LCD_ToggleEnable(uint8_t val) {
    // Toggle enable pin on LCD display
    // We cannot do this too quickly or things don't work
    _delay_us(DELAY_US);
    i2c_WriteByte(val | LCD_ENABLE_BIT);
    _delay_us(DELAY_US);
    i2c_WriteByte(val & ~LCD_ENABLE_BIT);
    _delay_us(DELAY_US);
}

// The display is sent a byte as two separate nibble transfers
static void LCD_SendByte(uint8_t val, int mode) {
    uint8_t high = mode | (val & 0xF0) | LCD_BACKLIGHT;
    uint8_t low = mode | ((val << 4) & 0xF0) | LCD_BACKLIGHT;

    i2c_WriteByte(high);
    LCD_ToggleEnable(high);
    i2c_WriteByte(low);
    LCD_ToggleEnable(low);
}

static void LCD_SetCursor(int line, int position) {
    int val = 0x80 + line_offsets[line] + position;
    LCD_SendByte(val, LCD_COMMAND);
}

static void inline LCD_SendChar(char val) {
    LCD_SendByte(val, LCD_CHARACTER);
}

static void LCD_SendString(const char *s) {
    while (*s) {
        LCD_SendChar(*s++);
    }
}

static void LCD_Init(void) {
    LCD_SendByte(LCD_DISPLAYCONTROL, LCD_COMMAND);
    LCD_SendByte(LCD_RETURNHOME, LCD_COMMAND);

    LCD_SendByte(LCD_ENTRYMODESET | LCD_ENTRYLEFT, LCD_COMMAND);
    LCD_SendByte(LCD_FUNCTIONSET | LCD_2LINE, LCD_COMMAND);
    LCD_SendByte(LCD_DISPLAYCONTROL | LCD_DISPLAYON, LCD_COMMAND);
    DISPLAY_Clear();
}

void DISPLAY_Setup(void)
{
    i2c_init();
    LCD_Init();
}

void DISPLAY_Clear(void) 
{
    LCD_SendByte(LCD_CLEARDISPLAY, LCD_COMMAND);
}

void DISPLAY_PrintMessage(char* message, uint8_t line, uint8_t offset)
{
    LCD_SetCursor(line, offset);
    LCD_SendString(message);
}

void DISPLAY_PrintWelcomeMessage(void)
{
    LCD_SetCursor(1, 2);
    LCD_SendString("2004A LCD Example");
    LCD_SetCursor(3, 0);
    LCD_SendString("-Frippertronics 2022");
    _delay_ms(2000U);
    DISPLAY_Clear();
}
