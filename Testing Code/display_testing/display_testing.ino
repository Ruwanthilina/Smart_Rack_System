#include <Arduino_GFX_Library.h>

// Technical Comment: Define standard RGB565 color codes
#define BLACK   0x0000
#define WHITE   0xFFFF
#define GREEN   0x07E0
#define RED     0xF800
#define BLUE    0x001F

// Technical Comment: Bus configuration using your specific pins
Arduino_DataBus *bus = new Arduino_ESP32LCD8(
    1  /* DC/RS */, 
    20 /* CS */, 
    2  /* WR */, 
    21 /* RD */,
    39 /* D0 */, 40 /* D1 */, 41 /* D2 */, 42 /* D3 */, 
    45 /* D4 */, 47 /* D5 */, 48 /* D6 */, 38 /* D7 */
);

// Technical Comment: Initialize driver (ILI9488 is common for these shields)
Arduino_GFX *gfx = new Arduino_ILI9488(bus, 35 /* RST */, 1 /* Rotation */, false /* IPS */);

void setup() {
    Serial.begin(115200);

    // Technical Comment: Start the display
    if (!gfx->begin()) {
        Serial.println("gfx->begin() failed!");
    }
    
    // Clear screen with Black color
    gfx->fillScreen(BLACK);
    
    // Header Text
    gfx->setCursor(20, 50);
    gfx->setTextColor(WHITE);
    gfx->setTextSize(3);
    gfx->println("SMART RACK SYSTEM");
    
    // Status Text
    gfx->setCursor(20, 100);
    gfx->setTextColor(GREEN);
    gfx->setTextSize(2);
    gfx->println("Display: ONLINE");

    // Technical Comment: Draw a border for testing
    gfx->drawRect(10, 10, 460, 300, GREEN);
}

void loop() {
    // Logic later...
}