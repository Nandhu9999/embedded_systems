# ARM CORTEX(Core + Texas) M4

- 32bit Microcontroller (4gb memory)
- Cost Sensitive 
- Great trade-off between Performance, Cost, Efficiency

# TM4C123**GH**6PM

```c
  SYSCTL->RCGCGPIO |= 0x21
```
- microcontroller's "SYSTEM CONTROL" sets the RCGC *Runmode Clock Gating Control*) GPIO
    - this enables a specific port { portA: 0x01, portB: 0x02, portC: 0x04, portD: 0x08, portE: 0x10, portF: 0x20 } 
    - to enable multple ports, we add the port numbers 
    - => PORT A + PORT F = 0x01 + 0x20 = 0x21
```c
  GPIOF->DIR = 0x0E;
```
- DIR register is used to set the direction for that particular Port
- **PORT F** has **8 PINS**, which needs to be identified if its taking input or giving output
    - 0x0E is 0000 1110 so
    - 1 = OUTPUT, 0 = INPUT
    - 0 1 2 3 4 5 6 7 | PINS
    - 0 0 0 0 **1 1 1 0**  | PORT
    

```c
  GPIOA->DIR=0xFF;
  GPIOA->DEN=0xFF;
```
- ...

```c
    GPIOF->DEN = 0x1E;
    GPIOF->PUR = 0x10;
```
- ...

