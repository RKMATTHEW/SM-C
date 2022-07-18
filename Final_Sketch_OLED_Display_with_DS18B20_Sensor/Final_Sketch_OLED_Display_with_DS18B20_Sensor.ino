#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int SensorDataPin = 2;     

OneWire oneWire(SensorDataPin);
DallasTemperature sensors(&oneWire);

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, & Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { 
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
}
  delay(2000);
display.clearDisplay();
display.setTextColor(WHITE);

}

void loop() {
  delay(1000);
  display.setCursor(0,0);
   display.setTextSize(1);
  display.clearDisplay();

  sensors.requestTemperatures(); 
  float temperature_Celsius = sensors.getTempCByIndex(0);
  float temperature_F = sensors.getTempFByIndex(0);
  Serial.print("Temperature = "); Serial.print(temperature_Celsius); Serial.println(" *C");
  //display.print("Temperature: "); display.print(temperature_Celsius); display.println(" *C");
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(temperature_Celsius); //investigate how many decimal places the sensor can display. 
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

  Serial.println();
  display.display();
  delay(1000);
}
