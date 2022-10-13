#include <Arduino.h>
#include "display.h"
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "humidity.h"
#include "humidity_air.h"


WiFiManager wm;
char* apName = "IOTWifi";
char* apPwd = "password";

void setup() {
  
  Serial.begin(115200);
  Serial.println("Welcome!");

  // // 顯示
  // u8g2.begin();
  // u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
  // u8g2.setFont(u8g2_font_unifont_t_chinese2); // use chinese2
  displayInit();

 

  u8g2.firstPage();
  do
  {
    u8g2.setCursor(0, 10);
    u8g2.print("IP: 192.168.0.4"); 
    u8g2.setCursor(0, 25);
    u8g2.print(apName); 
    u8g2.setCursor(0, 40);
    u8g2.print(apPwd); 
  } while (u8g2.nextPage());

  SetHumidityAir();
  bool res;
  res = wm.autoConnect(apName,apPwd);
  pinMode(13, INPUT);
  Serial.print("go");
  if(!res) {
      Serial.println("連線失敗");
      // ESP.restart();
  } 
  else {
      //if you get here you have connected to the WiFi    
      Serial.println("連線成功");
  }
}

void loop() {
  // postIOT(10000);
  HumidityAir();
}