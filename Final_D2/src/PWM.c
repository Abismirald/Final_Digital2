#include "PWM.h"

#define PWM_PORT 3
#define PWM_PIN	3
#define DELAY_1SEG 1000000
#define PWM_BLOCKING_TIME_MS 100 //tiempo de bloqueo de la funcion de PWM_pulse en milisegundos

void PWM_pulse(unsigned int T /*us*/, unsigned int zone){
	float Ton=0;
	float Toff=0;
	int i;

	switch(zone){
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
