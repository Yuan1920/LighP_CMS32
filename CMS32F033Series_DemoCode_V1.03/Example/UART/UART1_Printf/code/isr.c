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
/** \file isr.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms_m0.h"
#include "demo_uart.h"
#include "stdio.h"

#include "public.h"
#include "TX1812_5050.h"
#include "AD_Key.h"
#include "Game_Operation.h"
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
     
/****************************************************************************
 ** \brief	NMI_Handler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void NMI_Handler(void)
{
	
}
/****************************************************************************
 ** \brief	HardFault_Handler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void HardFault_Handler(void)
{
	
}

/****************************************************************************
 ** \brief	SVC_Handler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void SVC_Handler(void)
{
	
}

/****************************************************************************
 ** \brief	PendSV_Handler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void PendSV_Handler(void)
{
	
}
/****************************************************************************
 ** \brief	SysTick_Handler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void SysTick_Handler(void)
{
	
}
           
/****************************************************************************
 ** \brief	GPIO0_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void GPIO0_IRQHandler(void)
{

}

/****************************************************************************
 ** \brief	GPIO1_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void GPIO1_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	GPIO2_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void GPIO2_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	GPIO3_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void GPIO3_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	GPIO4_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void GPIO4_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	CCP_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void CCP_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	ADC0_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void ADC0_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	WWDT_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void WWDT_IRQHandler(void)
{
		
}
/****************************************************************************
 ** \brief	EPWM_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void EPWM_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	ADC1_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void ADC1_IRQHandler(void)
{
	;
}
/****************************************************************************
 ** \brief	ACMP_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void ACMP_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	UART0_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void UART0_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	UART1_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void UART1_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	TMR0_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void TMR0_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	TMR1_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
uint16_t Tim_Test = 0;
extern unsigned int Key_ms;
u16 Tim_1ms = 0;
extern u8 Test_flag;
u16 Auto_ShutDown_Tim = 0;
u16 cl_Key_cut = 0;
void TMR1_IRQHandler(void)
{
	
	/************* 100us *********************/
   if(TMR_GetOverflowIntFlag(TMR1))
	{
		TMR_ClearOverflowIntFlag(TMR1);
		
		if(_Device.Power_Flag)
		{
			Auto_ShutDown_Tim = 0;
			if(_Game.key_CutMode >= 1)		
			{// 清理两个按键切换模式
				if(cl_Key_cut > 4000)
				{
					cl_Key_cut = 0;
					_Game.key_CutMode = 0;
				}
				else cl_Key_cut++;
			}
			else cl_Key_cut = 0;
		}
		else
		{
			if((Auto_ShutDown_Tim >= 35000)&(IO_KEY_5 == 1))
			{// 初始化时无按键长按3.5s后自动关机
				Auto_ShutDown_Tim = 0;
				_Device.Power_Flag = 0;
				PWEN_IO = 0;						
				printf("已关机\n");
			}
			else if(IO_KEY_5 == 0)
			{
				Auto_ShutDown_Tim = 0;
			}
			else Auto_ShutDown_Tim++;
			
			cl_Key_cut = 0;		// 
		}
		
		if(Tim_Test > 5000)
		{
			Tim_Test = 0;
			//T4_TEST_IO = !T4_TEST_IO;
			//printf("Timer_1 Test\n");
			//Test_flag = 1;
		}
		else Tim_Test++;
		
		if(Tim_1ms > 10)
		{
			Tim_1ms = 0;
			Key_ms++;
			
		}
		else Tim_1ms++;
				
	}	                         
}
/****************************************************************************
 ** \brief	WDT_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void WDT_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	I2C_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void I2C_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	SPI_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void SPI_IRQHandler(void)
{
	
}
/****************************************************************************
 ** \brief	GPIO0_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void LVD_IRQHandler(void)
{	

}



