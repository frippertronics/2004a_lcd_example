#include "kabeltester/interrupt.h"
#include "kabeltester/display.h"

#include <util/delay.h>

static void init(void)
{
    // Initialsie TWI (I2C) and the display
    DISPLAY_Setup();
}

int main(void)
{
    init();
    DISPLAY_PrintWelcomeMessage();
}