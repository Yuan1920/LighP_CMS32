#ifndef __AD_KEY_H
#define __AD_KEY_H

#include "public.h"

#define AD_KEY_NUMBER  3
#define AD_KEY_ERROR_VAL   190			// AD按键容错值

#define AD_KEY_AA    0			// 按键名
#define AD_KEY_BB    1
#define AD_KEY_CC    2

#define IO_KEY_1		GPIO2->DI_f.P1
#define IO_KEY_2		GPIO2->DI_f.P2
#define IO_KEY_3		GPIO2->DI_f.P3
#define IO_KEY_4		GPIO2->DI_f.P4

#define IO_KEY_5		GPIO1->DI_f.P4
#define IO_KEY_6		GPIO1->DI_f.P3
#define IO_KEY_7		GPIO1->DI_f.P2
#define IO_KEY_8		GPIO1->DI_f.P0

typedef struct
{
	unsigned char Buf;
	unsigned char Pre_Buf;
	unsigned char Time;
	unsigned char Mode;		
	unsigned char Value;
	unsigned int Delay;	
	unsigned char Flag;
	unsigned char LongPre_Cut;
	/************************/		
	unsigned int Doub_clk_time;
	unsigned char Have;   // 有按键按下标志位
	
}_KEY_xx;

/****************** 定时器10ms *******************************/
#define Click     1
#define Double_Click	2
#define LongPre		3
/*********************** Key_Config **************************/
#define Key_Number   8				
#define Key_Trigger_Level			0			// ** 设置Key的有效电平 0:1
#define Key_Double_EN    0			//  1:打开双击 0：关闭双击
#define Key_Double_Time_Interval   30		// 双击时间
#define Key_LongPre_EN	1		//  ** 设置  1：长按使能		
#define Key_Long_Tim_Val  100  //  长按的时间   			

void Key_Init_IO(void);
void AD_GetKey(void);

#endif


