/*
===============================================================================
 Name        : MuMa Project
 Author      : Mancini - Muscio
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "main.h"

#define GPIO_TRIGGER_PORT 3 //TRIGGER => GPIO0
#define GPIO_TRIGGER_PIN 0
#define GPIO_ECHO_PORT 3	//ECHO => GPIO2
#define GPIO_ECHO_PIN 4
#define	SCU_TRIGGER_GROUP 6
#define	SCU_TRIGGER_PIN 1
#define	SCU_ECHO_GROUP 6
#define	SCU_ECHO_PIN 5
#define DELAY_TRIGGER 7 //delay between samples

#define Z1		80		//cm 80 9
#define Z2		150		//cm 150 19
#define Z3		250		//cm 250 30

bool GPIO_FLAG=0;

/* Init of the peripherics (TIMERS, GPIO, NVIC, DAC) */
status_t PERIPHERAL_init(){

	LED_ALL();
	DAC_init();
	SCU_init();
	GPIO_init();
	TIMERS_init();
	NVIC_init();

	return OK_ZONE;
}

void DAC_init(){
	Enable_DAC();
	Values_DAC(0);
}

void SCU_init(){
	SCU_SetPin(SCU, SCU_TRIGGER_GROUP, SCU_TRIGGER_PIN, 0);
	SCU_SetPin(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN, 0);
	SCU_EnableBuffer(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN);
	SCU_enablePD_disablePU(SCU,SCU_ECHO_GROUP, SCU_ECHO_PIN);

}

void GPIO_init(){
	GPIO_SetPinDIR(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, OUTPUT);
	GPIO_SetPinDIR(GPIO, GPIO_ECHO_PORT, GPIO_ECHO_PIN, INPUT);
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, LOW);
	return;
}

void TIMERS_init(){

	TIMER_init(TIMER0);
	TIMER_SetFrequency(TIMER0, US_FREQ); //set timer to us
	TIMER_reset(TIMER0);

	return;
}

void NVIC_init(){
	Distance_interrupt(0);
	Select_GPIO_interrupt(GPIO_ECHO_PORT, GPIO_ECHO_PIN, 0);
	Enable_NVIC(PIN_INT0_IRQn);

	return;
}

//if an echo signal interrupts
void GPIO0_IRQHandler(void){

	/* Clear interruption pin */
	(PIN_INT->IST)|=(1<<0);

	GPIO_FLAG =! GPIO_FLAG; //not
}

int main(void) {

    uint32_t distance=0; //esto generaria que esta pegado al sensor la logica tendria que ser infinito
    status_t status=OK_INIT;


    //Inicialization
    status = PERIPHERAL_init(); //GPIO, TIMERS, UART en alto nivel

    if(status != OK_ZONE){
    	//SAFE MODE
    	while(1){
    		LED_toggle(L1);
    		delay_us(500000);
    	}
    }

    //Loop principal
    while(1){

    	// ULTRASONIC SENSOR --> get actual distance
    	distance_sensor_trigger();
    	distance = distance_sensor_listen_echo();

    	//ZONES OF ACTION
    	/* The distance determinates the zone of action */
    	if(0<distance && distance<Z1){
    		zone(ZONE_1);
    		vibrator_ON(ZONE_1);
    	}
    	if(Z1<distance && distance<Z2){
    		zone(ZONE_2);
    		vibrator_ON(ZONE_2);
    	}
    	if(Z2<distance && distance<Z3){
    		zone(ZONE_3);
    		vibrator_ON(ZONE_3);
    	}
    	if(Z3<distance){
    		zone(ZONE_OUT);
    		vibrator_OFF();
    	}

    	/* delay between sensing */
    	delay_us(DELAY_TRIGGER);

    }
    return 0;
}


