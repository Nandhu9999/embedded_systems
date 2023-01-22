# LPC C code

```c
    #include <lpc214x.h>
```

```c
#define LED1_4_ON() IO1SET=(1<<16_19)
#define LED1_4_OFF() IO1CLR=(1<<16_19)

#define BUZZER_ON() IO0CLR=(1<<11)
#define BUZZER_OFF() IO0SET=(1<<11)
```