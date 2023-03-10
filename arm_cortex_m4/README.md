# ARM CORTEX(Core + Texas) M4

- 32bit Microcontroller (4gb memory)
- Cost Sensitive 
- Great trade-off between Performance, Cost, Efficiency

# TM4C123**GH**6PM
- 6 ports
    - A : 8pins
    - B : 8pins
    - C : 8pins
    - D : 8pins
    - E : 6pins
    - F : 5pins

```c
  SYSCTL->RCGCGPIO |= 0x21
```
- microcontroller's "SYSTEM CONTROL" sets the RCGC *Runmode Clock Gating Control*) GPIO
    - this enables a specific port { portA: 0x01, portB: 0x02, portC: 0x04, portD: 0x08, portE: 0x10, portF: 0x20 } 
    - to enable multple ports, we add the port numbers 
    - => PORT A + PORT F = 0x01 + 0x20 = 0x21
```c
  GPIOX->DIR = 0x0E;
```
- DIR register is used to set the direction for that particular Port
- **PORT X** has **8 PINS**, which needs to be identified if its taking input or giving output

    - 0x0E is 0000 1110 so
    - 7 6 5 4 3 2 1 0 | PINS
    - 0 0 0 0 1 1 1 0  | OU**1**PUT OR INP**0**T
    

```c
  GPIOA->DEN=0xFF;
```
- Digital ENable register used to enable or disable the digital functionality of the individual pins instead of analog fn.

    - 0xFF is 1111 1111 so
    - 7 6 5 4 3 2 1 0 | PINS
    - 1 1 1 1 1 1 1 1  | ENAB**1**E or DIS**0**BLE
- enabled = can be used for both input and output digital signals

```c
    GPIOF->PUR = 0x10;
```
- Pull Up Register is used to enable or disable the internal pull-up resistor of the pins
- *When the internal pull-up resistor is enabled, it causes the pin to be pulled to a high voltage level when no external force is applied. 
This can be useful in preventing floating inputs or debouncing switch inputs.*

    - 0x10 is 0001 0000 so
    - 7 6 5 4 3 2 1 0 | PINS
    - 0 0 0 1 0 0 0 0  | ENAB**1**E or DIS**0**BLE

```c
    value = GPIOF->DATA; 
    GPIOF->DATA = 0x0E; 
```
- Getting Input data from PORT F
- Setting Output data to PORT F
- Colors 🔴2 | 🟦4 | 💚8

