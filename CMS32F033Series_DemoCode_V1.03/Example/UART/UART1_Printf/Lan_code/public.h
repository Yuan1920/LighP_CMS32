#ifndef  __PUBLIC_H__
#define  __PUBLIC_H__

#include "cms_m0.h"
#include "demo_uart.h"
#include "stdio.h"
#include "demo_timer.h"


#define u8 unsigned char
#define u16 unsigned int

#define T6_IO  P31		
#define T5_IO  P22		//	Uart_0_Test--Rx
#define T4_TEST_IO  GPIO0->DO_f.P4		//	Test_IO
#define T3_IO  P24		// 	Reset_IO 
#define T2_IO  P25
#define T1_IO  P26		 

#define PWEN_IO GPIO0->DO_f.P6 

#define Delay_300ns();    __NOP();__NOP();__NOP();__NOP();__NOP();
#define Delay_300ns_L();    __NOP();__NOP();__NOP();
void Delay_1ms(void);
void Delay_900ns(void);
void Delay_500ms(void);

#endif


