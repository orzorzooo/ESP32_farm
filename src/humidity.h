// #include "WiFi.h";
#include <HTTPClient.h>
#include <ArduinoJson.h>

// pinMode(13, INPUT);
float humidity = .000;


// String baseURL = "http://192.168.50.164:3000/api/iot";
String baseURL = "https://api.orzorzooo.com/api/iot";

// for json
StaticJsonDocument<200> requestData;
StaticJsonDocument<200> datas;
char json_output[100];

String response = "";
DynamicJsonDocument doc(2048);




float getHumidity() {
  humidity = analogRead(13);
  float dust_humidity = (6619.136 / humidity) - 2.203;
  Serial.println(humidity);
  Serial.println(dust_humidity);
  return humidity;
}

void postIOT(int delayTime) {

  HTTPClient http;
  getHumidity();
  requestData["name"] = "humidity";
  datas["humidity"] = humidity;
  requestData["datas"] = datas;
  serializeJson(requestData, json_output);

  http.begin(baseURL);
  Serial.println("POST:");
  Serial.println(json_output);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(json_output);
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  http.end();
  delay(delayTime);
}
// void initWiFi() {
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi ..");
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print('.');
//     delay(1000);
//   }
//   Serial.println(WiFi.localIP());
// }

// void scanWifi() {
//   Serial.println("scan start");

//   // WiFi.scanNetworks will return the number of networks found
//   int n = WiFi.scanNetworks();
//   Serial.println("scan done");
//   if (n == 0) {
//     Serial.println("no networks found");
//   } else {
//     Serial.print(n);
//     Serial.println(" networks found");
//     for (int i = 0; i < n; ++i) {
//       // Print SSID and RSSI for each network found
//       Serial.print(i + 1);
//       Serial.print(": ");
//       Serial.print(WiFi.SSID(i));
//       Serial.print(" (");
//       Serial.print(WiFi.RSSI(i));
//       Serial.print(")");
//       Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
//       delay(10);
//     }
//   }
//   Serial.println("");

//   // Wait a bit before scanning again
//   delay(5000);
// }



// void setup() {
//   Serial.begin(115200);
//   initWiFi();
//   Serial.print("RRSI: ");
//   Serial.println(WiFi.RSSI());

//   // Set WiFi to station mode and disconnect from an AP if it was previously connected
//   // WiFi.mode(WIFI_STA);
//   // WiFi.disconnect();
//   // delay(100);

//   // Serial.println("Setup done");
// }

// void loop() {
//   postIOT(2000);
// }