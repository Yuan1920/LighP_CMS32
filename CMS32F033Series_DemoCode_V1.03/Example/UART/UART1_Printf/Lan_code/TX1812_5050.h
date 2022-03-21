#ifndef _TX1812_5050_H_
#define _TX1812_5050_H_
#include "public.h"


//#define RGB_IO  GPIO0->DO_f.P7
#define RGB_IO T4_TEST_IO
#define RGB_STRENGTH	5  


typedef struct
{
	unsigned int G_val;
	unsigned int R_val;
	unsigned int B_val;
}_RGB_DEF;



void TX1812_5050_Init(void);


void RGB_Send_Dat(uint8_t G_dat,uint8_t R_dat,uint8_t B_dat);
void RGB_Rest(void);
void RGB_TEST(void);		// Á÷Ë®µÆ
void RGB_All_OFF(void);
void All_Bright_RGB(void);

#endif






