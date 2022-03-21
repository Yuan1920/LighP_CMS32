#ifndef __AD_KEY_H
#define __AD_KEY_H

#include "public.h"

#define AD_KEY_NUMBER  3
#define AD_KEY_ERROR_VAL   190			// AD�����ݴ�ֵ

#define AD_KEY_AA    0			// ������
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
	unsigned char Have;   // �а������±�־λ
	
}_KEY_xx;

/****************** ��ʱ��10ms *******************************/
#define Click     1
#define Double_Click	2
#define LongPre		3
/*********************** Key_Config **************************/
#define Key_Number   8				
#define Key_Trigger_Level			0			// ** ����Key����Ч��ƽ 0:1
#define Key_Double_EN    0			//  1:��˫�� 0���ر�˫��
#define Key_Double_Time_Interval   30		// ˫��ʱ��
#define Key_LongPre_EN	1		//  ** ����  1������ʹ��		
#define Key_Long_Tim_Val  100  //  ������ʱ��   			

void Key_Init_IO(void);
void AD_GetKey(void);

#endif


