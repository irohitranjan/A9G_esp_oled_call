
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)

void setup() {  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.clearDisplay();
  display.display();

}

void loop() {
   display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(15,0); 
   display.print("Kya kar rahi re");

    display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,10); 
     display.print("Bogli");
      display.display();

}
