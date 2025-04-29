# Car Parking Sensor Using ATmega32

![image](https://github.com/user-attachments/assets/32775f20-146a-4058-bd6e-8a91fa48ff88)


## Objectives

The aim of this project is to design a simple car parking sensor system that helps drivers detect obstacles and avoid collisions while parking. The system measures the distance between the car and an obstacle using an ultrasonic sensor and displays the distance on an LCD screen. LEDs and a buzzer provide visual and auditory warnings based on the proximity of the object.

## Features

- **Ultrasonic Distance Measurement**  
  The system uses an ultrasonic sensor to measure the distance between the car and nearby objects.

- **LCD Display**  
  Displays the measured distance in centimeters and shows `"Stop"` if the object is too close (≤ 5 cm).

- **LED Indicators**  
  Three LEDs (Red, Green, and Blue) light up progressively based on how close the object is:
  - Distance ≤ 5 cm: All LEDs flashing
  - 6–10 cm: All LEDs ON
  - 11–15 cm: Red & Green ON
  - 16–20 cm: Red ON
  - > 20 cm: All LEDs OFF

- **Buzzer Alert**  
  The buzzer activates when the object is within 5 cm range as a collision warning.

## Hardware Components

- **Microcontroller**: ATmega32 @ 16 MHz
- **Sensors**:
  - HC-SR04 Ultrasonic Sensor (Trigger: PD7, Echo: PD6)
- **Display**:
  - 16x2 LCD (4-bit mode)
    - RS: PA1
    - E: PA2
    - D4–D7: PA3–PA6
- **Output Devices**:
  - LEDs: Red (PC0), Green (PC1), Blue (PC2)
  - Buzzer: PC5 (via transistor control)

## Drivers Overview

- **GPIO Driver**: Used for general-purpose digital input/output pin configuration.

- **ICU Driver**: Measures the echo pulse width for ultrasonic distance calculation  
  - Configuration: Edge-select mode, F_CPU/8  
  - Functions used inside `Ultrasonic_init()`: `ICU_init()`, `ICU_setCallBack()`

- **Buzzer Driver**: Controls the warning buzzer  
  Functions:
  - `Buzzer_init()`
  - `Buzzer_on()`
  - `Buzzer_off()`

- **LCD Driver**: Displays distance or "Stop" using 4-bit data mode  
  - RS: PA1, E: PA2, D4–D7: PA3–PA6  
  - Functionality: Distance display and alert messages

- **Ultrasonic Driver**: Handles sensor triggering and pulse time measurement  
  Functions:
  - `Ultrasonic_init()`
  - `Ultrasonic_Trigger()`
  - `Ultrasonic_readDistance()`
  - `Ultrasonic_edgeProcessing()`

## Conclusion

This car parking sensor project demonstrates effective integration of the HC-SR04 ultrasonic module with visual and audio indicators to assist with safe parking. Using layered driver architecture and real-time feedback via the LCD, it provides a compact and practical embedded system solution for vehicle safety.

