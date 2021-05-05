// (1):get the temperature ,humidity from the dth sensor


#include "DHT.h"
#define DHTPIN 4  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}
void loop() {
   delay(2000);
 float h = dht.readHumidity();
  float t = dht.readTemperature();
 float f = dht.readTemperature(true);
 if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 float hif = dht.computeHeatIndex(f, h);
 float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}


------------------------------------------------------------------

// (2):get the light intensity form the LDR
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldrval=analogRead(15);
Serial.print("the LDR value is:");
Serial.println(ldrval);
delay(1000);
}

------------------------------------------------------------------

//(3):display the light intensity,temperature and humidity in oled display

#include "DHT.h"
#define DHTPIN 4    
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
 dht.begin();
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
}
void loop() {
delay(6000);
int ldrval=analogRead(15);
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  else
  {
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("%  Temperature: ");
  Serial.println(t);
  Serial.print("°C ");
  Serial.println(f);
  Serial.print("the LDR intensity is:");
  Serial.println(ldrval);
  display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println(" ");
    display.print("the ldr intensity is ");
    display.println(ldrval);
    display.print("Humidity: ");
    display.print(h);
    display.println("%");
    display.print("Temparature: ");
    display.print(t);
    display.println("°C ");
    display.print(f)
    display.display();
}
}

---------------------------------------------------------------

//(4):control the lights based on light intensity (control the led's as an indication of light)

void setup() {
  // put your setup code here, to run once:
 pinMode(4,OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(21,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrval=analogRead(15);
Serial.print("the LDR intensity is:");
Serial.println(ldrval);
delay(1000);
if(ldrval<3000)
{
digitalWrite(4, HIGH);  
  delay(1000);                      
  digitalWrite(5, HIGH);   
  delay(1000);  
   digitalWrite(21, HIGH);   
  delay(1000); 
} 
  else if(ldrval>3000)
  {                    
  digitalWrite(4, LOW);    
  delay(1000);                       
  digitalWrite(5, LOW);   
  delay(1000); 
   digitalWrite(21, LOW);   
  delay(1000);
}                       
}

--------------------------------------------------------------

// (5):control the fans based on the temperature and humidity parameters (control led's as an indication of fan)


#include "DHT.h"
#define DHTPIN 4  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
const int ledPin = 16;  
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 dht.begin();
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin, ledChannel);
 }

void loop() {
  delay(2000);
  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
 
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
   float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  if (t>=31&&humidity>50)
  {
     for(int fanspeed = 50; fanspeed <= 255; fanspeed++){   
    ledcWrite(ledChannel, fanspeed);
    delay(15);
     }
  }
     else if(t<31&&himidity<50)
     {
       for(int fanspeed = 255; fanspeed >= 50; fanspeed--){
    
    ledcWrite(ledChannel, fanspeed);   
    delay(15);
     }
     }
}
