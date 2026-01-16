# Arduino FSM – Button Controlled LED

This project demonstrates a **Finite State Machine (FSM)** implementation using Arduino.

A single push button is used to control multiple LED behaviors using **short press**, **long press**, and **non-blocking timing**.

---

## Features
- Short press toggles LED ON/OFF
- Long press switches to blinking mode
- Long press again exits blinking mode
- Button debouncing without delay()
- Non-blocking timing using millis()

---

## FSM States
- **OFF** – LED is OFF  
- **ON** – LED is ON  
- **MODE** – LED blinks continuously  

---

## Concepts Used
- Finite State Machine (FSM)
- enum for state management
- Button debouncing
- Short vs long press detection
- millis() based non-blocking timing

---

## Hardware Required
- Arduino Uno / Nano
- Push button
- LED
- 220Ω resistor
- Breadboard & jumper wires

---

## Wiring
- Button → Pin 9 (INPUT_PULLUP)
- LED → Pin 7 (through resistor to GND)

---

## How It Works
The button press duration is measured:
- **< 500 ms** → short press
- **> 500 ms** → long press

Based on the press type, the FSM transitions between states and controls the LED behavior.

---

## Future Improvements
- Add multiple LEDs
- Add serial debugging
- Extend FSM with sensors
