#include <Arduino.h>
#include <U8g2lib.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>


#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,/*clock=*/14,/*data=*/12,U8X8_PIN_NONE);

float temperature, humidity, pressure, altitude;

void setup(void) {
  Serial.begin(115200);
  u8g2.begin();
  bme.begin(0x76);
}


void loop(void) {
  char temp[32];
  char humidity[32];
  dtostrf(bme.readTemperature(), 3, 1, temp);
  dtostrf(bme.readHumidity(), 3, 1, humidity);
  
//TEMPERATURE
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_tenstamps_mf);  // choose a suitable font
  u8g2.drawStr(0, 13, "Temp");  // write something to the internal memory
  u8g2.setFont(u8g2_font_inb24_mr );  // choose a suitable font
  u8g2.drawStr(0, 50, temp);
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(2000);

  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_tenstamps_mf);  // choose a suitable font
  u8g2.drawStr(0, 13, "Humidity");
  u8g2.setFont(u8g2_font_inb24_mr );  // choose a suitable font
  u8g2.drawStr(0, 50, humidity);
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(2000);
  

}
