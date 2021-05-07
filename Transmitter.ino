// Karmdeep Singh
// Arduino Controlled Robot Car
// Transmitter Program

// Summary: This program transmits the digital data of the X and Y Axis position of the PS2 Joystick
// receieved from the Arduino's Analog In port
 
// Declare Libraries used 
#include <printf.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NRF24L01 Setup
RF24 radio(7, 8); // CE and CSN port declaration respectively. Can use any digital pin on the Arduino       
const byte address[6] = "00001"; // Byte Address for the RF Module. Must be the same on the recieving end

int joystick[2]; // Joystick Array for X and Y axis data

void setup() {
  
Serial.begin(9600);

// Transmitting RF Module Initialization
radio.begin();                  // Start RF Module Comms
radio.openWritingPipe(address); // Set which channel (address) to communicate with 
radio.setPALevel(RF24_PA_MAX);  // Set power level for RF Module (Min for low power, short distance; Max for high power, long distance)
radio.stopListening();          // Start transmission

}

void loop() {

joystick[0] = analogRead(A6); // Store X axis data received from jotstick into array index 0 
joystick[1] = analogRead(A7); // Store Y axis data received from joystick into array index 2
radio.write(&joystick, sizeof(joystick)); // Transmit joystick to receiver module

}
