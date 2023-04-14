#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string> 

#define WIFI_AP "Your wifi SSID"
#define WIFI_PASSWORD "Your wifi password"
#define SCRIPT_URL "http://your.server.com/weather_script.php"

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16


#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup() {

  Serial.begin(9000);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)

  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("hello");
  display.display();


  Serial.println("BOOT");
}

int hitung = 0;

int getNumber() {
  hitung++;
  delay(500);
  return hitung;
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(std::to_string(getNumber()).c_str());
  display.display();
  delay(1);
}
