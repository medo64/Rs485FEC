### Rs485FEC

#### Parts

|  # | Part                                              | RefDes  | Preferred Part Number       |
|---:|---------------------------------------------------|---------|-----------------------------|
|  1 | C 10nF X7R 16V (0805)                             | C1      | 399-17617-1-ND              |
|  5 | C 100nF X7R 16V (0805)                            | C2-C6   | 478-5311-1-ND               |
|  3 | C 10uF X5R 16V (0805)                             | C7-C9   | 490-18664-1-ND              |
|  1 | D Schottky 30V 800mA [CUS08F30,H3F] (SOD323)      | D1      | CUS08F30H3FCT-ND            |
|  1 | D TVS SM712                                       | D2      | SM712-TPMSCT-ND             |
|  2 | DS LED (0805)                                     | DS1-DS2 | 475-1415-1-ND               |
|  1 | J USB C, plug, straddle 0.8mm                     | J1      | WM12855-ND                  |
|  1 | J JST XH Vertical (4w)                            | J2      | 455-B4B-XH-A-ND             |
|  1 | L Ferrite 600R@100Mhz                             | L1      | 240-2390-1-ND               |
|  1 | Q P-MOSFET DMP3099L-13 (SOT23)                    | Q1      | DMP3099L-13DICT-ND          |
|  1 | R 120 0.125W (0805)                               | R1      | RMCF0805FT120RCT-ND         |
|  2 | R 1K 0.125W (0805)                                | R2-R3   | RMCF0805FT1K00CT-ND         |
|  1 | R 5.1K 0.125W (0805)                              | R4      | RMCF0805FT5K10CT-ND         |
|  1 | R 10K 0.125W (0805)                               | R5      | RMCF0805FT10K0CT-ND         |
|  1 | R 75K 0.125W (0805)                               | R6      | RMCF0805FT75K0CT-ND         |
|  1 | U FT232R (SSOP-28)                                | U1      | 768-FT232RNL-TUBE-ND        |
|  1 | U SP485EEN (SOIC-8)                               | U2      | 1016-1171-5-ND              |
|  1 | U LoadSwitch Adjustable [AP22652W6-7] (SOT23-6)   | U3      | 31-AP22652W6-7CT-ND         |
|  2 | H Screw M2x3mm                                    | -       | -                           |


#### Specifications

| Property        | Value                          |
|-----------------|--------------------------------|
| PCB size        | 24.0 x 27.9 x 0.8 mm (1.1 in²) |
| Voltage (in)    | 5 V ±10%                       |
| Current (in)    | 500 mA (max)                   |
| Voltage (out)   | 5 V ±15%                       |
| Current (limit) | 400 mA ±10%                    |


#### FTDI Configuration

| Setting | Value  |
|---------|--------|
| CBUS0   | TXLED# |
| CBUS1   | RXLED# |
| CBUS2   | TXDEN  |
| CBUS3   | PWREN# |
| CBUS4   | SLEEP# |


#### Power

| Property | Value  |
|----------|-------:|
| Voltage  |    5 V |
| Current  | 100 mA |


#### Termination

To remove termination, desolder termination resistor on top of the board (marked
`TERM`).
