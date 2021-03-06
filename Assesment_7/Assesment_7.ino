
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() 
{
Serial.begin(115200);
  SerialBT.begin("ESP32"); 
  Serial.println("Device is started pair it with bluetooth");
Serial.println("OLED");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Hello");
  display.display(); 
}

void loop() 
{
  if (Serial.available()) 
  {
    SerialBT.write(Serial.read());
  }
   
  while(SerialBT.available()) 
  {
   char a =SerialBT.read();
  Serial.println(a);
  delay(10);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(a);
}

display.display();
}
