#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <eyes.h>
#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

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
}
int currentTime;
void normalEyes(void){
  currentTime = millis();
  while((millis()-currentTime)<10000){
    for(int i=0;i<=2;i++){
      oled.clearDisplay();
      oled.drawBitmap(0,0,fallArray[i],128,64,1);
      oled.display();
      delay(0.07);
    }
    delay(200);
    for(int i=2;i>=0;i--){
      oled.clearDisplay();
      oled.drawBitmap(0,0,fallArray[i],128,64,1);
      oled.display();
      delay(0.07);
    }
  }
}
void wideningEyes(void){
  for(int i=0;i<=5;i++){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(0.07);
  }

}
void tighteningEyes(void){
  for(int i=5;i>=0;i--){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(0.07);
  }
}
void heartsEyes(void){
  for(int i=5;i<=53;i++){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(0.07);
  }
  delay(200);
  // for(int i=53;i>=5;i--){
  //   oled.clearDisplay();
  //   oled.drawBitmap(0,0,fallArray[i],128,64,1);
  //   oled.display();
  //   delay(0.07);
  // }  
  normalEyes();
}
void angryEyes(void){
  for(int i=53;i<=119;i++){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(0.07);
  }
  delay(200);
  // for(int i=99;i<=119;i++){
  //   oled.clearDisplay();
  //   oled.drawBitmap(0,0,fallArray[i],128,64,1);
  //   oled.display();
  //   delay(0.07);
  // }  
  normalEyes();
}
void excitedEyes(void){
  for(int i=119;i<=149;i++){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(0.07);
  }
  delay(200);
  for(int i=149;i>=119;i--){
    oled.clearDisplay();
    oled.drawBitmap(0,0,fallArray[i],128,64,1);
    oled.display();
    delay(0.07);
  }  
  normalEyes();
}
void loop() {
  // put your main code here, to run repeatedly:
  // for(int i=0;i<=(fallArray_LEN-1);i++){
  //   oled.clearDisplay();
  //   oled.drawBitmap(0,0,fallArray[i],128,64,1);
  //   oled.display();
  //   // delay(0.07);
  // }
normalEyes();
// delay(5000);
excitedEyes();
// delay(5000);
angryEyes();
// delay(5000);
heartsEyes();
}
