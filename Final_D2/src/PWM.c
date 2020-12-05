#include "PWM.h"

#define PWM_PORT 3
#define PWM_PIN	3
#define DELAY_1SEG 1000000
#define PWM_BLOCKING_TIME_MS 100 //tiempo de bloqueo de la funcion de PWM_pulse en milisegundos
//#define MAX_PWM_TIME 10000000 //10 *10e(6) us = 10 segs

//DutyCicle=PulseWidth/Period
/*
 * Con una tension de GPIO de 3.3v para 2 V necesito
 * DC=37% y para 1V necesito 9% redondeo a 10%
 */

/* frec 10kHz => 100us*/

void PWM_pulse(unsigned int T /*us*/, unsigned int voltage){
	float Ton=0;
	float Toff=0;
	int i;

	switch(voltage){
	case(1):
		Ton=T;
		Toff=0;
		break;
	case(2):
		Ton=T*0.5;
		Toff=T*0.5;
		break;
	case(3):
		Ton=T*0.3;
		Toff=T*0.7;
		break;
	}

	for(i=0;i<((1000/T)*(PWM_BLOCKING_TIME_MS));i++){
	GPIO_SetPin(GPIO, PWM_PORT, PWM_PIN, LOW);
	GPIO_TogglePin(GPIO,PWM_PORT, PWM_PIN);
	delay_us(TIMER1, Ton);
	GPIO_TogglePin(GPIO,PWM_PORT, PWM_PIN);
	delay_us(TIMER1, Toff);
	}

}
void PWM_pulse_off(){

	GPIO_SetPin(GPIO, PWM_PORT, PWM_PIN, LOW);
	delay_us(TIMER0, PWM_BLOCKING_TIME_MS*1000);
}

//void PWM_time(unsigned int freq, unsigned int total_time){
//
//	unsigned int var=0;
//	unsigned int T = (1/1000000)*freq;
//
//	if(T <= MAX_PWM_TIME){
//
//		for (var = 0; var < total_time/T; ++var) {
//			PWM_pulse(T,2);
//		}
//
//	}
//
//
//}
//
//void PWM_variable(unsigned int freq /*Hz*/,
//		unsigned int percentaje_up,  unsigned int percentaje_down){
//
//	unsigned int T = (1/freq)*1000000;
//
//	if(percentaje_up<=1 && percentaje_down <=1){
//
//		GPIO_SetPin(GPIO,PWM_PORT, PWM_PIN,HIGH);
//		//delay_us(T*percentaje_up);
//		GPIO_TogglePin(GPIO,PWM_PORT, PWM_PIN);
//		//delay_us(T*percentaje_up);
//
//	}
//
//
//}
