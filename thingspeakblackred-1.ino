//This is based on my "black and red" program.
//libraries
#include <M5StickCPlus.h>
#include <WiFi.h>
#include "ThingSpeak.h"

// ThingSpeak credentials and settings
//the settings for thingspeak and the settings for wifi so that the m5stickC can actually connect
//the channel number
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER;
//the write API key so that information can be recived
const char *myWriteAPIKey = "YOUR_WRITE_API_KEY"; 
//wifi SSID
char ssid[] = "YOUR_WIFI_SSID"; 
//wifi PASSWORD
char pass[] = "YOUR_WIFI_PASSWORD"; 
WiFiClient client;

// M5StickC specific variables
//start by setting the screen to black
bool isRed = false; 
void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(2);
  //the starting background color
  M5.Lcd.fillScreen(BLACK); 
  //the starting text color
  M5.Lcd.setTextColor(WHITE, BLACK);  
  //other settings
  //sets the cursor for the BTN test line
  M5.Lcd.setCursor(10, 10);
  //actually prints it
  M5.Lcd.println("Btn test");
  //sets the cursor for my name
  M5.Lcd.setCursor(10, 30);
  //actually prints my name
  M5.Lcd.println("Amari");

  //start the serial and wifi connection for thingspeak
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  M5.update();

  //checks button A and toggles the color of the screen
  if (M5.BtnA.wasPressed()) {
    //toggles the isred state
    isRed = !isRed;  
    //changing the text for compatibility
    if (isRed) {
      M5.Lcd.fillScreen(RED);
      M5.Lcd.setTextColor(WHITE, RED);
    } else {
      M5.Lcd.fillScreen(BLACK);
      M5.Lcd.setTextColor(WHITE, BLACK);
    }

    //reprint the text for compatibility with the change in background color
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Btn test");
    M5.Lcd.setCursor(10, 30);
    M5.Lcd.println("Amari");

    //send the color status to thingspeak
    //1 if for red and 0 is for black
    int colorStatus = isRed ? 1 : 0; 
    ThingSpeak.writeField(myChannelNumber, 1, colorStatus, myWriteAPIKey);
  }

  //makes sure the device stays connected to wifi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  //delay to avoid overloading the wifi stack
  delay(200);
  //END
}

