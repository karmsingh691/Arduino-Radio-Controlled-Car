// Karmdeep Singh
// Arduino Controlled Robot Car
// Receiver Program


// Summary: This program receives the digital data of the X and Y Axis position of the PS2 Joystick
// from the transmitting RF module and mobilizies the car based on the data. 

// Declare Libraries used
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <AFMotor.h>
#include <Servo.h> 

// Servo Motor setup with L293D Shield
Servo myServo; 
int  pos = 0;

// DC Motors setup with L293D Shield
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
#define Speed 200

// NRF24L01 Setup
RF24 radio(35, 34); // CE and CSN port declaration respectively. Can use any digital pin on the Arduino
const byte address[6] = "00001"; // Byte Address for the RF Module. Must be the same on the transmitting end

int X,Y; // Initialize the X and Y variables to store the received data
int joystick[2]; // // Joystick Array for X and Y axis data

void setup() {

Serial.begin(9600);

// DC Motors and Servo Initialization
motor1.setSpeed(Speed);
motor2.setSpeed(Speed);
myServo.attach(10);

// Receiving RF Module Initialization
radio.begin(); // Start RF Module Comms
radio.openReadingPipe(0, address); // Set which channel (address) to communicate with 
radio.setPALevel(RF24_PA_MAX);     // Set power level for RF Module (Min for low power, short distance; Max for high power, long distance).
radio.startListening();            // Start Recieving
}
void loop() {
if (radio.available()) {           // Searching for incoming data

radio.read(&joystick, sizeof(joystick)); // Read incoming data

X = joystick[0]; // Store index 0 in the incoming array into X axis variable
Y = joystick[1]; // Store index 1 in the incoming array into Y axis variable

int valX = map(X, 0, 1023, 10, 170); // Scale X axis data for precise servo movement(beta)

Serial.println(X); // For testing purpose; ensure correct incoming data

// These series of conditional statements are based on the X and Y coordinate system of the PS2 Joystick
// X ranges from 0 to 1023 (Left to Right)
// Y ranges from 0 to 2023 (Up to Down)

if(Y >= 530){         // Backwards Condition
  
motor1.run(BACKWARD);
motor2.run(BACKWARD);
}
else if (Y <= 495){   // Forward Condition

motor1.run(FORWARD);
motor2.run(FORWARD);
}
else if (X < 30) {    // Left Turn Condition
  
myServo.write(0);
motor1.run(FORWARD);
motor2.run(FORWARD);
} 

else if (X > 1000) {  // Right Condition 
  
myServo.write(180);
motor1.run(FORWARD);
motor2.run(FORWARD);
} 

else {                // If joytick is in neutral position, Motors are stopped and servo points straight
  
myServo.write(90);
motor1.run(RELEASE);
motor2.run(RELEASE);
}
}
}
