# Lab 5.1 - Using ThingSpeak API to Collect and Visualize Data

This project demonstrates how to use an **M5StickC Plus** microcontroller to send data to **ThingSpeak**, an IoT analytics platform, for real-time data collection and visualization.

## Overview

The repository contains two Arduino sketch files that showcase different ways to interact with ThingSpeak:

1. **Counter Program** (`new-1.ino`) - Sends counter values to ThingSpeak
2. **Color Toggle Program** (`thingspeakblackred-1.ino`) - Sends screen color state to ThingSpeak

## Hardware Requirements

- **M5StickC Plus** - ESP32-based development board with built-in LCD display and buttons
- WiFi network access

## Software Requirements

- Arduino IDE
- Required Libraries:
  - `M5StickCPlus` - For M5StickC Plus hardware control
  - `WiFi` - For WiFi connectivity
  - `ThingSpeak` - For ThingSpeak API integration

## Project Files

### 1. Counter Program (`new-1.ino`)

This program implements a button-controlled counter that:

- **Counts up** from 0 to 10 when Button A is pressed
- **Counts down** from 10 to 0 once the upper limit is reached
- **Displays** the current counter value on the LCD screen
- **Sends** each counter value to ThingSpeak Field 1

#### How It Works:
1. Press Button A to increment/decrement the counter
2. The counter value is displayed on the M5StickC Plus screen
3. Each button press sends the current counter value to ThingSpeak
4. The counting direction toggles automatically at boundaries (0 and 10)

### 2. Color Toggle Program (`thingspeakblackred-1.ino`)

This program implements a button-controlled screen color toggle that:

- **Toggles** the screen background between black and red
- **Displays** author name ("Amari") and test label on screen
- **Sends** the color state to ThingSpeak (0 = Black, 1 = Red)

#### How It Works:
1. Press Button A to toggle between black and red screen backgrounds
2. The color state is sent to ThingSpeak Field 1
3. Text remains visible with appropriate color contrast

## ThingSpeak Configuration

Both programs use the following ThingSpeak settings:

| Setting | Value |
|---------|-------|
| Channel Number | YOUR_CHANNEL_NUMBER |
| Write API Key | YOUR_WRITE_API_KEY |
| Data Field | Field 1 |

## WiFi Configuration

Update the following variables in the code with your network credentials:

```cpp
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";
```

## Setup Instructions

1. **Install Arduino IDE** and required libraries
2. **Connect** your M5StickC Plus via USB
3. **Select** the correct board (`M5StickC Plus`) and port in Arduino IDE
4. **Update** WiFi credentials in the code
5. **Upload** the desired sketch to the device
6. **Open** the Serial Monitor (115200 baud) to view connection status
7. **View** your data on [ThingSpeak](https://thingspeak.com) dashboard

## Usage

1. Power on the M5StickC Plus
2. Wait for WiFi connection (check Serial Monitor)
3. Press **Button A** to interact:
   - `new-1.ino`: Increment/decrement the counter
   - `thingspeakblackred-1.ino`: Toggle screen color
4. View the data visualization on your ThingSpeak channel

## ThingSpeak Data Visualization

Log into ThingSpeak to:
- View real-time data graphs
- Create custom visualizations
- Analyze historical data trends
- Set up alerts and notifications

## Author

**Amari**

## License

This project is for educational purposes as part of Lab 5.1.
