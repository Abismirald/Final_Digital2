#include "dac.h"
#include "struct_base.h"
#include "interruptions.h"
#include <math.h>

#define PI	3.141516
#define MAX_FREQ 8000 //8kHz
#define MIN_FREQ 1000 //1kHz
#define SAMPLE_FREQ 400000 //400kHz
#define CLK_FREQ 204000000 //204MHz

int SAMPLES_NUM = SAMPLE_FREQ/MIN_FREQ;

void Enable_DAC(){
	(SCU->ENAIO)[2]|=1;
}
//ENAIO[2] corresponde al DAC, en 1 hago que la salida del pin funcione como analogica (que tenga un rango de 0 a 3,3V) 
//y en 0 funciona como un pin digital donde solo tiene 0 y 1 (3,3V) como valores posibles

void Enable_DMA(){
	(DAC->CTRL)|=(1<<3) | (1<<2) | (1<<1) | (1<<0);
}
//DMA_ENA(posicion 3) en 1: Habilitación del DAC y la entrada 15 (DMA Burst Request).

//Set a DAC output Value in volts
void Values_DAC(int volts){
//	como int tiene 32 bit hago una mascara con una AND en los primeros 10 bits (3FF) para asegurarme que los primeros bits sean 0
//	Once this field is written with a new VALUE, the voltage on the
//	DAC pin (with respect to VSSA) is VALUE/1024 x VDDA. The
//	value of the DAC output pin is valid after the selected
	int value=(volts/VDDA)*1024;
	(DAC->CR)= ((value & 0x3FF)<< 6) | (1<<16); //lower power consuption
	return;
}
//VALUE son los bits de 5 a 16 y BIAS es el bit 16 el cual mejor







