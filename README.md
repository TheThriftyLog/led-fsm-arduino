# LED Finite State Machine - Arduino Uno

## Overview
A finite state machine (FSM) implemented on an Arduino Uno that cycles an LED through three states using a momentary pushbutton. This project demonstrates core embedded systems concepts including edge detection, software debouncing, and non-blocking timing.

## FSM State Diagram
| State | Value | LED Behavior |
|-------|-------|--------------|
| OFF   | 0     | LED off      |
| ON    | 1     | LED on       |
| BLINK | 2     | LED toggles every 500ms |

Each button press advances to the next state, cycling 0 → 1 → 2 → 0.

## Hardware
- Arduino Uno R3
- Momentary tactile pushbutton
- 5mm LED
- 220Ω current limiting resistor (LED)
- 10kΩ pull-down resistor (pushbutton)
- Breadboard and jumper wires

## Schematic
*(Insert TinkerCAD schematic image here)*

## Demo Video
*(Insert YouTube link here)*

## Design Decisions
- **Edge detection** is used instead of raw pin reading so each press registers exactly once regardless of how long the button is held.
- **Software debouncing** via a 50ms delay after a rising edge prevents mechanical contact bounce from triggering multiple state transitions.
- **millis()** is used for LED blinking instead of delay() so the microcontroller remains responsive to button input while in the BLINK state.
- **State 2 re-entry reset** ensures ledState and lastBlinkTime are reinitialized each time the BLINK state is entered, guaranteeing predictable behavior.

## Author
Logan | [GitHub](https://github.com/TheThriftyLog)
