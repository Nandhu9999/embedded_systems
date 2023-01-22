# ARM CORTEX(Core + Texas) M4

- 32bit Microcontroller (4gb memory)
- Cost Sensitive 
- Great trade-off between Performance, Cost, Efficiency

# TM4C123**GH**6PM

```c
  SYSCTL->RCGCGPIO |= 0x21
```
- ...

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

