#ifndef _STRUCT_BASE_H_
#define _STRUCT_BASE_H_

#define SCU_BASE			0X40086000 
#define SCU 				((SCU_T *) SCU_BASE) 
#define GPIO_PORT_BASE		0x400F4000 
#define GPIO 				((GPIO_T *) GPIO_PORT_BASE) 
#define PIN_INT_BASE		0x40087000
#define PIN_INT 			((PIN_INT_T *) PIN_INT_BASE)
#define NVIC_BASE			0xE000E100
#define NVIC 				((_NVIC_T *) NVIC_BASE)
#define DAC_BASE			0x400E1000
#define DAC 				((DAC_T *) DAC_BASE) 


typedef struct {
	unsigned int  SFSP[16][32];
	unsigned int  RESERVED0[256];
	unsigned int  SFSCLK[4];
	unsigned int  RESERVED16[28];
	unsigned int  SFSUSB;	
	unsigned int  SFSI2C0;
	unsigned int  ENAIO[3];
	unsigned int  RESERVED17[27];
	unsigned int  EMCDELAYCLK;
	unsigned int  RESERVED18[63];
	unsigned int  PINTSEL[2];
} SCU_T;

typedef struct {			
	unsigned char B[128][32];
	unsigned int W[32][32];
	unsigned int DIR[32];
	unsigned int MASK[32];
	unsigned int PIN[32];
	unsigned int MPIN[32];
	unsigned int SET[32];
	unsigned int CLR[32];	
	unsigned int NOT[32];	
} GPIO_T;

typedef struct{
	int ISEL; //0 = Edge sensitive ||1 = Level sensitive || bits del 0 al 7.
	int IENR;
	int SIENR;
	int CIENR;
	int IENF;
	int SIENF;
	int CIENF;
	int RISE;
	int FALL;
	int IST;
} PIN_INT_T;
//pag 452 (de pdf) user manual

typedef struct{
	int ISER[8];
	int RESERVED0[24];
	int ICER[8];
	int RESERVED1[24];
	int ISPR[8];
	int RESERVED2[24];
	int ICPR[8];
	int RESERVED3[24];
	int IABR[8];
	int RESERVED4[56];
	unsigned int IP[240];
	int RESERVED5[644];
	int STIR;
} _NVIC_T;
//pag 253 Definitive guide


typedef struct{
	unsigned int CR; 		//DAC register (tiene el dato convertido)
	unsigned int CTRL; 		//DAC control register
	unsigned int CNTVAL;	//DAC counter value register
}DAC_T;
//pag 1350 User Manual
#endif
