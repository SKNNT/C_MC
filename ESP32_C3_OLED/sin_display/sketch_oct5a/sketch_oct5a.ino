#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define SDA_PIN 5
#define SCL_PIN 6

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  u8g2.begin();
}

void loop(void) {
  static float x = 0;
  u8g2.clearBuffer(); 
  for (int i = 0; i < 128; i++) {
    int y = 35 + 15 * sin((x + i) * 0.1);
    u8g2.drawPixel(i, y);
  }
  u8g2.sendBuffer(); 
  x += 1; //animation effect
}
