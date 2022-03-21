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
/** \file demo_timer.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_timer.h"

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
 ** \brief	TMR1_Period_Count_Config
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void TMR1_Period_Count_Config(void)
{
	/*
	(1)设置Timer1 的时钟
	*/
	SYS_EnablePeripheralClk(SYS_CLK_TIMER01_MSK);			/*打开Timer0/1的时钟*/
	TMR_ConfigClk(TMR1,TMR_CLK_SEL_APB,TMR_CLK_DIV_256);		/*Timer1 的时钟源选择APB时钟,设置时钟分频为 1分频*/
	/*
	(2)设置Timer1 运行模式
	*/	
	TMR_ConfigRunMode(TMR1,TMR_COUNT_PERIOD_MODE, TMR_BIT_32_MODE);		/*设置Timer1为32位周期计数模式*/
	TMR_DisableOneShotMode(TMR1);							/*关闭单次模式*/
	/*
	(3)设置Timer1 运行周期
	*/		
	TMR_SetPeriod(TMR1,18);				/* 18*Fclk = 100us*/
	/*
	(4)设置Timer1 中断
	*/	
	TMR_EnableOverflowInt(TMR1);
	NVIC_EnableIRQ(TMR1_IRQn);	
	/*
	(5)设置Timer1 中断优先级
	*/	
	NVIC_SetPriority(TMR1_IRQn,3);	
	/*
	(5)开启Timer1
	*/	
	TMR_Start(TMR1);
	
	/*
	(6)P12设置为推挽输出模式
	*/
	
}





























