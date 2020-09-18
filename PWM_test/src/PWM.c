#include "PWM.h"

#define PWM_PORT 1//CAMBIAR
#define PWM_PIN	1 //CAMBIAR
#define MAX_PWM_TIME 10000000 //10 *106 us = 10 segs

void PWM_period(unsigned int T /*us*/){

	GPIO_TogglePin(GPIO,PWM_PORT, PWM_PIN);
	delay_us(T/2);
	GPIO_TogglePin(GPIO,PWM_PORT, PWM_PIN);
	delay_us(T/2);

}

void PWM_time(unsigned int freq, unsigned int total_time){

	unsigned int var=0;
	unsigned int T = (1/freq)*1000000;

	if(T <= MAX_PWM_TIME){

		for (var = 0; var < total_time/T; ++var) {
			PWM_delay_pulse(T);
		}

	}


}

void PWM_variable(unsigned int freq /*Hz*/,
		unsigned int percentaje_up,  unsigned int percentaje_down){

	unsigned int var=0;
	unsigned int T = (1/freq)*1000000;

	if(percentaje_up<=1 && percentaje_udown <=1){

		GPIO_SetPin(GPIO,PWM_PORT, PWM_PIN,HIGH);
		delay_us(T*percentaje_up);
		GPIO_TogglePin(GPIO,PWM_PORT, PWM_PIN,LOW);
		delay_us(T*percentaje_up);

	}


}
