#ifndef _SMG_H_
#define _SMG_H_

#include "public.h"

#define LED_A_IO  GPIO3->DO_f.P5
#define LED_B_IO  GPIO3->DO_f.P6 
#define LED7_IO  GPIO3->DO_f.P4
#define LED6_IO  GPIO3->DO_f.P2
#define LED5_IO  GPIO3->DO_f.P1
#define LED4_IO  GPIO4->DO_f.P4
#define LED3_IO  GPIO3->DO_f.P0
#define LED2_IO  GPIO4->DO_f.P3
#define LED1_IO  GPIO1->DO_f.P5

typedef struct
{
	uint8_t Flag;
	uint8_t Num;
	uint8_t OnlyOne;
}_SMG_DEF;

void LED_IO_INIT(void);
void SMG_AA_ALL_OFF(void);
void SMG_Show_AA(uint8_t dat);


#endif


