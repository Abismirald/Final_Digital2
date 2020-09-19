#include "timers.h"

void Clock_enable(timer_t timer_number){

	switch(timer_number){
	case(TIMER0):
		(CCU1_TIMER0->CFG)|=1;
		break;
	case(TIMER1):
		(CCU1_TIMER1->CFG)|=1;
		break;
	case(TIMER2):
		(CCU1_TIMER2->CFG)|=1;
		break;
	case(TIMER3):
		(CCU1_TIMER3->CFG)|=1;
		break;
	}
	return;
}
TIMER_T* TIMER_getPTR(timer_t timer_number){

	TIMER_T* TIMERn;

	switch(timer_number){
		case(TIMER0):
			TIMERn=TIMER_0;
			break;
		case(TIMER1):
			TIMERn=TIMER_1;
			break;
		case(TIMER2):
			TIMERn=TIMER_2;
			break;
		case(TIMER3):
			TIMERn=TIMER_3;
			break;
		}
	return TIMERn;
}

void TIMER_init(timer_t timer_number){

	TIMER_T* TIMERn;
	TIMERn=TIMER_getPTR(timer_number);

	Clock_enable(timer_number);

	(TIMERn->CTCR) &= ~(0x07); //All zeros to Timer Mode.
}

void TIMER_enable(timer_t timer_number){
	TIMER_T* TIMERn;
	TIMERn=TIMER_getPTR(timer_number);
	(TIMERn->TCR) |= 0x01; //1 in CEN the TC and PC are enabled for counting
}

void TIMER_disable(timer_t timer_number){
	TIMER_T* TIMERn;
	TIMERn=TIMER_getPTR(timer_number);
	(TIMERn->TCR) &= ~(0x01); //0 in CEN the TC and PC are disabled for counting
}

//Returns the current timer terminal count
uint32_t TIMER_ReadCount(timer_t timer_number){
	TIMER_T* TIMERn;
	TIMERn=TIMER_getPTR(timer_number);
	return TIMERn->TC;
}

void TIMER_reset(timer_t timer_number){
	TIMER_T* TIMERn;
	uint32_t aux;
	TIMERn=TIMER_getPTR(timer_number);

	aux = (TIMERn->TCR);	//save cfg of TCR
	(TIMERn->TCR) = 0; 		//stop timer
	(TIMERn->TC) = 1;		//Value of timer non-0

	(TIMERn->TCR) = (0x02); //Reset TC and PC in next edge of clk

	/* Wait for terminal count to clear */
	while ((TIMERn->TC) != 0) {}

	/* Restore timer state */
	(TIMERn->TCR) = aux;

	return;
}

//set frequency on a timer.
//The maths are: PPCLK * (PR+1) = P /* para mi aca es el +1 */
//Where: PCLK = 1/PCLK_MAX_FREQ , P = 1/frequency, PR = value of PR register

//PR=(MAX_FREQ/frequency) -1
void TIMER_SetFrequency(timer_t timer_number , int frequency){
	TIMER_T* TIMERn;
	TIMERn=TIMER_getPTR(timer_number);

	(TIMERn->PR) = ( (int) MAX_FREQ/frequency - 1 );
}

void delay_us(timer_t timer_number, uint32_t time){
	TIMER_T* TIMERn;
	TIMERn=TIMER_getPTR(timer_number);

	TIMER_reset(timer_number);
	TIMER_enable(timer_number);
	while(TIMER_ReadCount(timer_number) != time){
	}
	TIMER_disable(timer_number);
	return;
}

