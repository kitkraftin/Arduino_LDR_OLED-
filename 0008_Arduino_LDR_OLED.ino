#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128 // OLED display width,  in pixels
#define OLED_HEIGHT 64 // OLED display height, in pixels

const int LDR_Pin=2; 

int ldr;

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LDR_Pin, INPUT);
  
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display
  oled.println("LDR Sensor"); // text to display
  oled.display();
  oled.clearDisplay(); // clear display
}

void loop() {
  ldr = digitalRead(LDR_Pin);
  if (ldr){
    oled.clearDisplay(); // clear display
    oled.setTextSize(2); 
    oled.setCursor(0, 20);
    oled.print("Light: ON"); // text to display
    oled.display();
  } else {
    oled.clearDisplay(); // clear display
    oled.setTextSize(2); 
    oled.setCursor(0, 20);
    oled.print("Light: OFF"); // text to display
    oled.display();
  }
  delay(1000);
}
