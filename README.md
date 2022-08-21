[RS-485 Framework Expansion Card](https://medo64.com/rs485framecard/)
=====================================================================

This Framework laptop expansion card will show up on your system as a serial
device and allow for a non-isolated RS-485 communication up to 115,200 baud
rate at 5V.

Please note that this card is using automatic transmit control.


## Pinout

| # | Ref | Description                                     |
|--:|-----|-------------------------------------------------|
| 1 | GND | Ground connection                               |
| 2 | A   | Negative (Low for logic 1 and high for logic 0) |
| 3 | B   | Positive (high for logic 1 and low for logic 0) |
| 4 | NC  | Not connected                                   |


## Wiring

To connect to this board, one has to use a 4-pin JST XH connector. Pin 1 being
on the left as looking into the expansion card.

As power consumption is way below 100 mA, I would recommend using 24 AWG wires
(0.25 mm²) as they allow for wide compatibility with other connectors.

---
*You can check my blog and other projects at [www.medo64.com](https://www.medo64.com/electronics/).*
