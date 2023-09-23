#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <eye.h>
#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  Wire.begin(5, 4);
  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(3);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 10);       // set position to display
  oled.println("Hello"); // set text
  oled.display();              // display on OLED
  delay(3000);
}
int currentTime;
void normalEyes(void){
  currentTime = millis();
  while((millis()-currentTime)<5000){
    for(int i=0;i<=28;i++){
      oled.clearDisplay();
      oled.drawBitmap(0,0,fallArray[i],128,64,1);
      oled.display();
      delay(60);
    }
    delay(500);
    for(int i=28;i>=18;i--){
      oled.clearDisplay();
      oled.drawBitmap(0,0,fallArray[i],128,64,1);
      oled.display();
      delay(60);
    }
    delay(3000);
  }
}
void worriedEyes(void){
    for(int i=18;i<=116;i++){
      oled.clearDisplay();
      oled.drawBitmap(0,0,fallArray[i],128,64,1);
      oled.display();
      delay(45);
    }
    delay(3000);
}
void angryEyes(void){
  for(int i=117;i<=165;i++){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(40);
  }
  delay(3000);
}
void angrySearching(void){
  for(int i=166;i<=268;i++){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(40);
  }
  delay(3000);
}

void loop() {

  worriedEyes();
  normalEyes();
  angrySearching();
  angryEyes();

}
