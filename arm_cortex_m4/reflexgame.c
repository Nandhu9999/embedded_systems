#include "TM4C123GH6PM.h"

void delayMs(int n);    /* function prototype for delay */

int main(void)
{
	unsigned int num;
	int isOn = 0;
        unsigned int value;
    SYSCTL->RCGCGPIO |= 0x21;   /* enable clock to GPIOF */

    GPIOF->DIR = 0x0E;          /* set PORTF1 pin as output (LED) pin */
                           /* and PORTF0 as input, SW2 is on PORTF0 */
    GPIOA->DIR=0xFF;
    GPIOA->DEN=0xFF;

    GPIOF->DEN = 0x1E;          /* set PORTF pins 1-0 as digital pins */
    GPIOF->PUR = 0x10;          /* enable pull up for pin 0 */


    while(1)
    {   
	isOn =0;
	num = rand() % 1000 + 500;
        value = GPIOF->DATA;    /* read data from PORTF */
       // value = ~value;         /* switch is low active; LED is high active */
       // value = value >> 1;     /* shift it right to display on green LED */
       // GPIOF->DATA = value;    /* put it on the green LED */

		GPIOF->DATA = 0x0E;

		if(!value)
		{
		    isOn = 1;
		    GPIOA->DATA = 0xFF;
		    delayMs(1000);
		}

		delayMs(200);
		GPIOA->DATA = 0x00;
		GPIOF->DATA = 0x00;


/*
		if( isOn == 1){
			GPIOA->DATA = 0xFF;
			delayMs(1000);
		}
		else
		{
			GPIOF->DATA = 0x00;
		}
*/
		GPIOF->DATA = 0x00;
		delayMs(num);
    }
}


/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++)
            {}  /* do nothing for 1 ms */
}


/* This function is called by the startup assembly code to perform system specific initialization tasks. */


void SystemInit(void)
{
    /* Grant coprocessor access */
    /* This is required since TM4C123G has a floating point coprocessor */
    SCB->CPACR |= 0x00F00000;
} 
