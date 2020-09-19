#include "distance_sensor.h"

#define TIME_TRIGGER 10 //micro sec

extern bool GPIO_FLAG;

void Distance_interrupt(int interrupt){
	SelectEdge_PIN_INT(interrupt);
	Enable_FallingEdge(interrupt);
	Enable_RisingEdge(interrupt);
}
void distance_sensor_trigger(){
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, HIGH);
	delay_us(TIMER0, TIME_TRIGGER);
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, LOW);
	return;
}

uint32_t distance_sensor_listen_echo(){
	uint32_t start_echo=0;
	uint32_t distance_echo=6000;
	uint32_t time_echo=0;

	TIMER_reset(TIMER0);
	TIMER_enable(TIMER0);

	while(TIMER_ReadCount(TIMER0) < MAX_ECHO_TIME){ // loopea hasta que timer llega al maximo sin recibir nada
	//Waits echo rise edge

		if(GPIO_FLAG==1){

			start_echo=TIMER_ReadCount(TIMER0);

			while(GPIO_FLAG != 0){
				//Waits for GPIO interrupt falling edge

				if(TIMER_ReadCount(TIMER0) > MAX_ECHO_TIME){
					break;
				}

			}
			time_echo=0;
			time_echo=TIMER_ReadCount(TIMER0)-start_echo;
			distance_echo = distance_cm(time_echo);
			break;
		}

	}

	return distance_echo;
}

uint32_t distance_cm(uint32_t time_echo){
  return (unsigned int) (time_echo/58);		//us to cm
}

