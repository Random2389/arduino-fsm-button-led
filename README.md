# Arduino FSM Projects – ATmega328P

A collection of **Finite State Machine (FSM)** implementations on Arduino,
built using direct register manipulation and non-blocking timing.

---

## Projects

### 1. Button Controlled LED (`button-led-fsm/`)
A single push button controls multiple LED behaviors using short and long press detection.

**Features**
- Short press toggles LED ON/OFF
- Long press switches to blinking mode
- Long press again exits blinking mode
- Button debouncing without delay()
- Non-blocking timing using millis()

**FSM States**
- **OFF** – LED is OFF
- **ON** – LED is ON
- **MODE** – LED blinks continuously

**Wiring**
- Button → Pin 9 (INPUT_PULLUP)
- LED → Pin 7 (through 220Ω resistor to GND)

---

### 2. Traffic Light Controller (`pedestrian-button/`)
A traffic light FSM with a pedestrian request button using hardware interrupts.

**Features**
- Full traffic light sequencing (RED → RED+YELLOW → GREEN → YELLOW)
- Pedestrian button triggers early green-to-yellow transition
- INT0 hardware interrupt for button handling
- Direct port manipulation (PORTB/DDRD/EICRA)
- Non-blocking timing using millis()

**FSM States**
- **RED** – Stop
- **RED+YELLOW** – Prepare to go
- **GREEN** – Go (shortened if pedestrian waiting)
- **YELLOW** – Prepare to stop

**Wiring**
- Red LED → PB3
- Yellow LED → PB4
- Green LED → PB5
- Pedestrian Button → PD2 (INT0, INPUT_PULLUP)

---

## Concepts Used
- Finite State Machine (FSM)
- enum for state management
- Hardware interrupts (INT0)
- Direct register manipulation
- Button debouncing
- millis() based non-blocking timing

---

## Hardware Required
- Arduino Uno / Nano (ATmega328P)
- Push buttons
- LEDs (Red, Yellow, Green)
- 220Ω resistors
- Breadboard & jumper wires
