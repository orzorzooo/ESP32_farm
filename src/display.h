#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/21); // ESP32 Thing, HW I2C with pin remapping

void displayInit(){
	 // 顯示
  u8g2.begin();
  u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
  u8g2.setFont(u8g2_font_unifont_t_chinese2); // use chinese2
}

// void draw(char* text[]){
// 	int size = sizeof(text);
// 	u8g2.firstPage();
// 	do
// 	{
// 		for(int i = 0; i < size; i++){
// 			u8g2.setCursor(0, i+12);
// 			u8g2.print(text[i]); 
// 		}
// 	} while (u8g2.nextPage());
	
// }
