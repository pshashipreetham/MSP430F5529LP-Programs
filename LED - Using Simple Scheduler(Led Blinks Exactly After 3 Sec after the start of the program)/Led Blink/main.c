#include <msp430.h> 
#include "timer.h"
#include "led.h"
#include "scheduler.h"

unsigned char ledToggleFlag = 0;
unsigned char executeTaskFlag = 0;
struct Task ledTimingTask;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	timer_init();
	led_init();

	ledTimingTask.period = 3 * 8;
	ledTimingTask.elapsedTime = 0;

	while(1)
	{
	    if(ledToggleFlag == 1)
	    {
	        ledToggleFlag = 0;
	        led_toggle();
	    }
	    if(executeTaskFlag == 1)
	    {
	        executeTaskFlag = 0;
	        scheduler_execute_task();
	    }

	    //Go to Sleep
	    __bis_SR_register(LPM0_bits + GIE);
	}



}


