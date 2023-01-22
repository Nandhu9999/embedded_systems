# ARM CORTEX(Core + Texas) M4

- 32bit Microcontroller (4gb memory)
- Cost Sensitive 
- Great trade-off between Performance, Cost, Efficiency

# TM4C123**GH**6PM

```c
  SYSCTL->RCGCGPIO |= 0x21
```
- microcontroller's "SYSTEM CONTROL" sets the RCGC *Runmode Clock Gating Control* GPIO
    - this enables a specific port { portA: 0x01, portB: 0x02, portC: 0x04, portD: 0x08, portE: 0x10, portF: 0x20 } 

```c
  GPIOF->DIR = 0x0E;
```
- ...

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

