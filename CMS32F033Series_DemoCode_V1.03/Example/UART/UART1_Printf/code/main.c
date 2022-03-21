/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/****************************************************************************/
/** \file main.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/

#include "public.h"

#include "SMG.h"
#include "AD_Key.h"
#include "TX1812_5050.h"

#include "CXN4016.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/
/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/


/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	 main
 **
 ** \param [in]  none   
 **
 ** \return 0
*****************************************************************************/
extern  _SMG_DEF _SMG[2];
u8 Test_flag = 0;
int main(void)
{		 
	_SMG[0].Flag = 1;
	_SMG[0].OnlyOne = 1;	
	SYS_DisableIOCFGProtect();			/*�ر�IOCONFIGд����*/
	SYS_DisableGPIO0Protect();			/*�ر�GPIO0����ؼĴ���д����*/
	SYS_DisableGPIO1Protect();			/*�ر�GPIO1����ؼĴ���д����*/
	SYS_DisableGPIO2Protect();			/*�ر�GPIO2����ؼĴ���д����*/
	SYS_DisableGPIO3Protect();			/*�ر�GPIO3����ؼĴ���д����*/
	SYS_DisableGPIO4Protect();			/*�ر�GPIO4����ؼĴ���д����*/
	
	SYS_ConfigHSI(SYS_CLK_HSI_48M);		/*�����ڲ�����ʱ��Ϊ48Mhz*/
	SYS_EnableHSI();					/*��������ʱ��*/
	SYS_ConfigAHBClock(SYS_CLK_SEL_HSI,SYS_CLK_DIV_1);	/*����AHBʱ��Ϊ����ʱ�ӵ�1��Ƶ*/
	SYS_ConfigAPBClock(AHB_CLK_DIV_1);					/*����APBʱ��ΪAHBʱ�ӵ�1��Ƶ*/

SYS_SET_IOCFG(IOP04CFG,SYS_IOCFG_P04_GPIO);	
GPIO_CONFIG_IO_MODE(GPIO0,GPIO_PIN_4,GPIO_MODE_OUTPUT);	
T4_TEST_IO = 1;		
	
	SYS_SET_IOCFG(IOP06CFG,SYS_IOCFG_P06_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO0,GPIO_PIN_6,GPIO_MODE_OUTPUT);	
	PWEN_IO = 1;	//P06 1=Open	0=Close			// �ܵ�Դ���ƿ���
	
	UART_UART1_Config();		// ����ʹ��
	TMR1_Period_Count_Config();
	LED_IO_INIT();			// �����
	Key_Init_IO();
	TX1812_5050_Init();		// RGB
	CXN4016_INIT();		// ����IC
	printf("CMS32F033_LightPong_Init\n\r");	
	while(1)
	{	
		SMG_Show_AA(1);
		AD_GetKey();
		if(Test_flag)
		{
			Test_flag = 0;
				All_Bright_RGB();

		}
	}
}



















