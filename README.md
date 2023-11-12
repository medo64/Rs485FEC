[RS-485 Framework Expansion Card](https://medo64.com/rs485framecard/)
=====================================================================

This Framework laptop expansion card will show up on your system as a serial
device and allow for isolated RS-485 communication up to 3,000,800 baud rate.

Please note that this card is using automatic transmit control and it is
fail-safe biased (equivalent to 120Ω termination).


## Pinout

To connect to this board, one has to use a 4-pin JST XH connector. The following
table represents the pinout, pin 1 being on the left as looking into the
expansion card.

| # | Ref | Description                                     |
|--:|-----|-------------------------------------------------|
| 1 | GND | Ground connection                               |
| 2 | A   | Negative (low for logic 1 and high for logic 0) |
| 3 | B   | Positive (high for logic 1 and low for logic 0) |
| 4 | NC  | Not connected                                   |

As power consumption is low, wires can be almost any AWG. I would recommend
using 24 AWG wire 0.25 mm² as they allow for greater compatibility with other
connectors.


## Supported Speeds

This board employs the FT232R as its UART chip, and consequently, it supports
all the baud rates this chip [can handle](https://ftdichip.com/Documents/AppNotes/AN232B-05_BaudRates.pdf)
up to 500,000 baud which is the limit of isolator chip used. The table below
lists the standard baud rates.

| Baud rate |    Actual | Error |    Divisor |
|----------:|----------:|------:|-----------:|
|       300 |       300 | 0.00% |  10000.000 |
|       600 |       600 | 0.00% |   5000.000 |
|     1,200 |     1,200 | 0.00% |   2500.000 |
|     1,800 |     1,800 | 0.00% |   1666.625 |
|     2,400 |     2,400 | 0.00% |   1250.000 |
|     4,800 |     4,800 | 0.00% |    625.000 |
|     7,200 |     7,201 | 0.01% |    416.625 |
|     9,600 |     9,600 | 0.00% |    312.500 |
|    14,400 |    14,406 | 0.04% |    208.250 |
|    19,200 |    19,200 | 0.00% |    156.250 |
|    28,800 |    28,812 | 0.04% |    104.125 |
|    38,400 |    38,400 | 0.00% |     78.125 |
|    57,600 |    57,692 | 0.16% |     52.000 |
|   115,200 |   115,385 | 0.16% |     26.000 |
|   230,400 |   230,769 | 0.16% |     13.000 |
|   460,800 |   461,538 | 0.16% |      6.500 |
|   921,600 |   923,077 | 0.16% |      3.250 |
| 1,000,000 | 1,000,000 | 0.00% |      3.000 |
| 2,000,000 | 2,000,000 | 0.00% |      2.000 |
| 3,000,000 | 3,000,000 | 0.00% |      0.000 |

While rates above this can be set, they are not guaranteed to work.


---
*You can check my blog and other projects at [www.medo64.com](https://www.medo64.com/electronics/).*
