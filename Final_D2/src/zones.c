#include "zones.h"
#include "leds_setup.h"
#include "PWM.h"

status_t zone(zones_t zone){
	switch(zone){

	case ZONE_1:
		LED_high(L0G);
		LED_high(L1);
		LED_high(L2);
		LED_high(L3);
		PWM_pulse(100, 1);
		break;

	case ZONE_2:
		LED_high(L0G);
		LED_high(L1);
		LED_high(L2);
		LED_low(L3);
		PWM_pulse(100, 2);
		break;

	case ZONE_3:
		LED_high(L0G);
		LED_high(L1);
		LED_low(L2);
		LED_low(L3);
		PWM_pulse(100, 3);
		break;

	case ZONE_OUT:
		LED_high(L0G);
		LED_low(L1);
		LED_low(L2);
		LED_low(L3);
		PWM_pulse_off();
		break;
	}
	return OK_ZONE;
}

