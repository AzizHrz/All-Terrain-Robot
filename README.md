# NINJA All Terrain Robot Control

This repository contains the Arduino code to control the "NINJA" All Terrain robot, a high-performance all-terrain robot designed with precisely selected motor RPM and torque for optimal mobility. The code leverages the Psx library to read input from a PSX controller and drives two DC motors on each side using two BTS7960 (BTS) motor drivers.

## Features
- Controls the robot's movement (forward, backward, left, right) using a PSX controller.
- Supports various speed levels based on button inputs.
- Uses PWM for motor speed control.
- Compatible with PS1/PS2 controllers via the Psx library.
- Utilizes two BTS7960 motor drivers, each controlling two motors on the same side.

## Hardware Requirements
- Arduino board (e.g., Arduino Uno)
- PSX controller
- Two BTS7960 motor drivers
- Four DC motors
- Jumper wires and breadboard
- Power supply (Lipo 4s) for motors

## Pin Configuration
- **PSX Controller Pins:**
  - `dataPin`: 4
  - `cmndPin`: 3
  - `attPin`: 2
  - `clockPin`: 5
- **Motor Driver 1 (Left Side, Two Motors):**
  - `RPWM1`: 6 (Right PWM for left side motors)
  - `REN1`: 8 (Right Enable for left side motors)
  - `LPWM1`: 9 (Left PWM for left side motors)
  - `LEN1`: 7 (Left Enable for left side motors)
- **Motor Driver 2 (Right Side, Two Motors):**
  - `RPWM2`: 10 (Right PWM for right side motors)
  - `REN2`: A1 (Right Enable for right side motors)
  - `LPWM2`: 11 (Left PWM for right side motors)
  - `LEN2`: A2 (Left Enable for right side motors)

## Installation
1. Install the Arduino IDE.
2. Download and install the `Psx` library via the Arduino Library Manager or manually.
3. Connect the hardware as per the pin configuration above.
4. Upload the code to your Arduino board.

## Usage
- Connect the PSX controller to the Arduino using the specified pins.
- Power the motors via the BTS7960 drivers.
- Use the following PSX controller inputs to control the robot:
  - **D-Pad Up**: Move forward (both sides move forward)
  - **D-Pad Down**: Move backward (both sides move backward)
  - **D-Pad Left**: Turn left (differential speed between sides)
  - **D-Pad Right**: Turn right (differential speed between sides)
  - **R1 + Buttons (Square, X, Circle, Triangle)**: Adjust right side motor speed
  - **L1 + Buttons (Square, X, Circle, Triangle)**: Adjust left side motor speed
- The robot stops when no buttons are pressed.

## Dependencies
- `Psx.h` library for PSX controller communication
- `SPI.h`

