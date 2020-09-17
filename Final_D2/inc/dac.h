#ifndef _DAC_H_
#define _DAC_H_

#include "struct_base.h"
#include <stdbool.h>

#define VDDA 3.3 //volts

extern bool flag_T1;
extern bool flag_T2;
extern bool flag_T3;
extern bool flag_T4;
void Enable_DAC();
void Values_DAC(int volts);
//unused
void Enable_DMA();
void cfg_DAC();
#endif
