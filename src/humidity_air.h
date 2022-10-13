
#include "Wire.h"
#include "SHT2x.h"

uint32_t start;
uint32_t stop;

SHT2x sht;
uint32_t connectionFails = 0;


void SetHumidityAir()
{
  // Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("SHT2x_LIB_VERSION: \t");
  Serial.println(SHT2x_LIB_VERSION);

  sht.begin();

  uint8_t stat = sht.getStatus();
  Serial.print(stat, HEX);
  Serial.println();
}


void HumidityAir()
{
  if ( sht.isConnected()  )
  {
    start = micros();
    bool b = sht.read();
    stop = micros();

    int error = sht.getError();
    uint8_t stat = sht.getStatus();

		u8g2.firstPage();
		do
		{
			u8g2.setCursor(0, 10);
			u8g2.print(sht.getTemperature()); 
			u8g2.setCursor(0, 25);
			u8g2.print(sht.getHumidity()); 
		} while (u8g2.nextPage());
    Serial.print(sht.getTemperature(), 1);
    Serial.print("\t");
    Serial.print(sht.getHumidity(), 1);
  }
  else
  {
    connectionFails++;
    Serial.print(millis());
    Serial.print("\tNot connected:\t");
    Serial.print(connectionFails);

	
    // sht.reset();
  }
  Serial.println();
  delay(10000);
}


// -- END OF FILE --