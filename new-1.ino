//new program that is a counter up until 10 then counts down until one. Each button press is an increment
//libraries
#include <M5StickCPlus.h>
#include <WiFi.h>
#include "ThingSpeak.h"

//settings for wifi and thingspeak
//the channel number
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER; 
//the channel write api key
const char *myWriteAPIKey = "YOUR_WRITE_API_KEY"; 
//SSID
char ssid[] = "YOUR_WIFI_SSID";  
//PASSWORD
char pass[] = "YOUR_WIFI_PASSWORD"; 
WiFiClient client;

int counter = 0;
bool countingUp = true;
//start
void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(2);

  //starts the wifi connection for thingspeak
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);

  Serial.println("Setup complete. Press button A to count.");
}

void loop() {
  M5.update();

  //checks button a and updates the counter
  if (M5.BtnA.wasPressed()) {
    //toggles the counting direction at bounds
    if (countingUp) {
      counter++;
      if (counter == 10) {
        countingUp = false;
      }
    } else {
      counter--;
      if (counter == 0) {
        countingUp = true;
      }
    }

    //sends the counter value to thingspeak
    ThingSpeak.writeField(myChannelNumber, 1, counter, myWriteAPIKey);

    //displays the current counter on the LCD
    //screen settings
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("Counter: %d", counter);

    //wifi connection
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Attempting to connect to WiFi...");
      while (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, pass);
        Serial.print(".");
        delay(5000);
      }
      Serial.println("\nWiFi Connected.");
    }
    //delay for reliability
    delay(100); 
    //END!
  }
}


