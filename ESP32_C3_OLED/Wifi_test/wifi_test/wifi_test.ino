#include <Arduino.h>
#include <U8g2lib.h>

#include "WiFi.h"


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
#define SDA_PIN 5
#define SCL_PIN 6
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const char* ssid = "_______________";//ur ssid
const char* password = "_________________";//ur wifi


void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  u8g2.begin();

    Serial.begin(115200); // Инициализация последовательного порта
    WiFi.begin(ssid, password); // Начало подключения к Wi-Fi

    // Проверка статуса подключения
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Соединяемся к WiFi-сети...");
    }
    Serial.println("Соединение с WiFi установлено");
    Serial.print("IP-адрес: ");
    Serial.println(WiFi.localIP()); // Вывод IP-адреса устройства
  
}

void loop(void) {
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(4,10,"Hello World!");	// write something to the internal memory
  u8g2.drawStr(4,20,"SKNNT");	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  
}