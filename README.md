# Finalproject_heartbeat_monitoring

## Background
Pulse sensor is an electronic device that is used to measure the heart rate, like the speed of the heartbeat. Monitoring body temperature, heart rate and blood pressure are the basic things that we can do in order to keep us healthy. Heart rate can be monitored in two ways: one way is to check the pulse either at wrist or the other way is to use a pulse sensor.

## General info
In this project, I designed a heart rate monitor system using Arduino and pulse sensor. Heartbeat is measured in beats per minute or bpm, which indicates the number of times the heart is contracting or expanding in a minute. The principle behind the working of the pulse sensor is photoplethysmography. According to this principle, the changes in the volume of blood in an organ is measured by the changes in the intensity of the light passing through that organ. Then, I will use OLED to display the ECG and display the bpm.
	
## Components Required
* Arduino UNO x1
* Connecting wires
* Pulse sensor module x1
* Breadboard x1
* OLED x1

## Setup
1. According to the wiring.jpg, wiring the project.
2. To run this project, install Arduino IDE in the lastest version.
3. You need to add two files into your Arduino library which are Adafruit-GFX... and Adafruit_SSD1306...( Those two libraries are for the OLED. The Adafruit_SSD1306 is the library for the OLED, and Adafruit-GTX... is the core of OLED graphic. ) Here is my library of the Arduino, just copy and paste those two files:
![lib](https://user-images.githubusercontent.com/50026415/115553095-979d3080-a2df-11eb-9373-cd9a6823bc4a.PNG)

4. Then, compile and upload the pulse_sensor.ino.

## Possible difficulties
There might be some difficulties when we are building our project. For example, When you wiring the project, be carful with the pin connection or not it will not working.     One thing you might get confused, after you upload the program and you didn't put your finger on the pulse sensor, but there are some waves on the OLED. That is because the pulse sensor essentially a light sensor, this is very important, don't think there are some problems when the OLED have some waves. The way to solve that is to cover the sensor with a black obstruction to prevent outside light from entering. 

## Demo link
