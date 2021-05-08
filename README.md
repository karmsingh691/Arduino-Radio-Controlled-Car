# Arduino Radio-Controlled Car

Personal project aiming to build a remote controlled car with Arduinos and RF modules. 

## Objectives and Motivation

The goal for this project is to use RF technology to control an Arduino powered car wirelessly. Ideally, this system could be placed into any hobby RC car and be able to control the vehicle with the same components.

# Table of Contents

- [Parts List](#parts-list)
- [Current Build](#current-build)
     * [Transmitting End](#transmitting-end)
     * [Receiving End](#receiving-end)
- [Youtube Playlist](#youtube-playlist)
- [Future Plans](#future-plans)




## Parts List

The following is the up-to-date parts list for the project. Links are provided when applicable.

1. PiCar-V Chassis, Motors, and Wheels  -->  https://www.sunfounder.com/products/smart-video-car
2. 2 Lithium Polymer batteries rated at 3.7V 2000 mAh --> https://www.sparkfun.com/products/13855
3. L293D Motor Shield for Arduino --> https://www.sunfounder.com/products/l293d-motor-drive-shield?_pos=1&_sid=4cbf1d2a0&_ss=r
5. Half-Size Breadboard
6. 2 NRF24L01 Transciever Modules
7. Arduino Mega 2560
8. Arduino Nano
9. PS2 Joystick
10. 1 Servo Motor
11. Soldering Equipment (Necessary for 1 pin)

## Current Build 

The images shown below is the first iteration of the arduino car, including the joystick that is connected to the transmitting Arduino Nano. Future plans include converting the transmitter into a PCB board so the controller can be more handheld. 

There are currently two parts of the project that controls the arduino car wirelessly: the transmitting and receiving end.

NOTE: The NRF24L01 connects to different ports for various types of Arduinos. Research port connections based on the Arduino you want to use.



### Transmitting End

The transmitting Arduino Nano is respnsible for sending the joystick data concerning X and Y axis positions to the Arduino Mega. This data is being sent and received by a pair of NRF24L01 radio modules that are connected to the Nano and Mega. 

The X and Y axis data is based on the coordinate system that the joystick is designed with, The image below shows the coordinate system I am referencing. I used this data to set the directions of the RC car based on the transmitted data. 

<div align="center">Joystick Coordinate System</div>

![PS2-Joystick-Module-Movement-Analog-Values-on-Arduino](https://user-images.githubusercontent.com/55263663/117518698-a7f71180-af55-11eb-89fc-68e55c005ada.png)

The joystick's X and Y pins are connected to 2 Analog In ports on the Nano which are converted into digital data via the internal A/D converter. I used an array to store the data which can be transmitted to the RF receiver on the Arduino Mega on top of the car.

### Receiving End

The Arduino Mega that is receiving the X and Y axis data is programmed to interpret the data and use conditional statements to mobilize the car based on the joystick's current position. The L293D shield is used to connect the 2 DC motors and a servo motor that came with the PiCar-V chassis. 

## Youtube Playlist

I will be making videos to explain my process in more depth and include live demos

## Future Plans

1. Design a PCB board for the joystick controller for better handheld control
2. 18650 Battery integration
3. Simple camera attached to servos that can be controlled with a 2nd joystick
