#include <SoftwareSerial.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>


SoftwareSerial mySerial(2, 0); //TX, RX


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)

String network, battery;


void setup()
{
  Serial.begin(115200);
  
  mySerial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
 display.clearDisplay();
  display.display();
 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,3);
  display.setCursor(5,5); 
   display.print("Initializing...");
      display.display();
  
 

  Serial.println("Initializing..."); 
  delay(5000);

 display.clearDisplay();
  display.display();

  mySerial.println("AT"); 
   mySerial.println("AT+SNFS=1");
  updateSerial();
  
  mySerial.println("ATD+91xxxxxxxxxx;"); 
  
  updateSerial();

    display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5,5); 
   display.print("Calling...");

   display.setCursor(5,15); 
   display.print("+91-xxxxxxxxxx");
      display.display();
  
  delay(10000);               //Wait for 10 seconds
  
   display.clearDisplay();
  display.display();
  
  mySerial.println("ATH"); //hang up
  updateSerial();
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5,5); 
   display.print("Call Ended");
      display.display();
}

void loop()
{

}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
