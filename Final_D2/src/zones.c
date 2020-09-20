#include "zones.h"
#include "leds_setup.h"
#include "PWM.h"

#define DELAY_TRIGGER 7 //delay between samples

status_t zone(zones_t zone){
	switch(zone){

	case ZONE_1:
		LED_high(L0G);
		LED_high(L1);
		LED_high(L2);
		LED_high(L3);
		 /* frec 10kHz => 100us*/
		 PWM_pulse(10, 3,DELAY_TRIGGER);
		break;

	case ZONE_2:
		LED_high(L0G);
		LED_high(L1);
		LED_high(L2);
		LED_low(L3);
		 /* frec 10kHz => 100us*/
		 PWM_pulse(10, 2,DELAY_TRIGGER);
		break;

	case ZONE_3:
		LED_high(L0G);
		LED_high(L1);
		LED_low(L2);
		LED_low(L3);
		 /* frec 10kHz => 100us*/
		 PWM_pulse(10, 1,DELAY_TRIGGER);
		break;

	case ZONE_OUT:
		LED_high(L0G);
		LED_low(L1);
		LED_low(L2);
		LED_low(L3);
		delay_us(TIMER0, DELAY_TRIGGER);
		break;
	}
	return OK_ZONE;
}

