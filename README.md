# Smart Door Monitoring System (DMS)

The Smart Door Monitoring System (DMS) is an intelligent solution designed to enhance both security and convenience by monitoring the open or closed status of multiple doors and automatically controlling interior lighting based on the door conditions. Using simple door sensors such as magnetic reed switches, the system detects when doors are opened or closed and communicates this information via the I2C protocol to other devices or microcontrollers, enabling seamless integration with broader home automation or security setups.

This project implements three main modes of operation controlled by a roof switch: Off mode, where the interior lighting remains off regardless of door status; Door mode, which turns the interior lights on automatically whenever any door is open, enhancing visibility and safety; and On mode, which keeps the interior lighting constantly on, regardless of door activity. This flexibility allows users to customize the system behavior to fit their needs or preferences.

Visual feedback is provided through red and green LEDs—when any door is open, the red LED lights up to alert users; when all doors are closed, the green LED signals that the system is secure. The combination of sensor data, lighting control, and status indication creates a user-friendly experience that promotes awareness of door activity and helps prevent security lapses.

The system is designed to run on microcontrollers such as Arduino, utilizing built-in libraries like Wire for I2C communication and relying on standard digital and analog I/O pins for sensor input and light output. This makes it easy to build, modify, and integrate with other systems. The door sensors are connected via digital inputs with pull-up resistors to detect active-low signals when doors open.

In addition to increasing home or office security, this project adds convenience by automating lighting based on actual usage conditions, reducing energy waste, and ensuring lights are on only when needed. The design supports multiple doors and can be expanded or adapted as required.

Overall, the Smart Door Monitoring System is a practical, cost-effective, and scalable solution suitable for anyone interested in smart home automation, security enhancement, or embedded system design.

---

## Features

- Detects multiple door states with sensors
- Sends door status via I2C communication
- Automatically controls interior lighting
- Provides LED visual indicators for door status
- Supports different operating modes (Off, Door-triggered, Always On)

## Hardware Requirements

- Microcontroller board (e.g., Arduino Uno)
- Door sensors (e.g., magnetic reed switches)
- LEDs (green and red)
- Interior light (relay or LED)
- Roof mode switch (analog input)
- Connecting wires and breadboard or PCB

## Software Requirements

- Arduino IDE (or compatible)
- Wire library for I2C communication (built-in Arduino)

## Installation and Usage

1. Clone this repository:

   ```bash
   git clone https://github.com/SaiAswen/SmartDoorMonitor.git
