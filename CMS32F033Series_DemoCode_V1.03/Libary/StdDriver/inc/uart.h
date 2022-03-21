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

/*****************************************************************************/
/** \file uart.h
**
** History:
** 
*****************************************************************************/
#ifndef __UART_H_
#define __UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms_m0.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **UART �ֳ�
-----------------------------------------------------------------------------*/
#define		UART_WLS_5			(0x00UL)		/*5λ�ֳ�*/
#define		UART_WLS_6			(0x01UL)		/*6λ�ֳ�*/
#define		UART_WLS_7			(0x02UL)		/*7λ�ֳ�*/		
#define		UART_WLS_8			(0x03UL)		/*8λ�ֳ�*/
/*----------------------------------------------------------------------------
 **UART ֹͣλ
-----------------------------------------------------------------------------*/
#define		UART_STOP_BIT_1			(0x00UL)		/*1λֹͣλ*/
#define		UART_STOP_BIT_2			(0x01UL<<UART_LCR_SBS_Pos)		/*2λֹͣλ*/
/*----------------------------------------------------------------------------
 **UART ��żУ��
-----------------------------------------------------------------------------*/
#define		UART_PARITY_NONE		(0x00UL)		/*����żУ��*/
#define		UART_PARITY_ODD			(0x00UL|(0x1<<UART_LCR_PEN_Pos))	/*��żУ��*/
#define		UART_PARITY_EVEN		((0x01UL<<UART_LCR_PSEL_Pos)|(0x1<<UART_LCR_PEN_Pos))	/*żżУ��*/
#define		UART_PARITY_FORCE_1		((0x02UL<<UART_LCR_PSEL_Pos)|(0x1<<UART_LCR_PEN_Pos))		/*У��λǿ��Ϊ1*/
#define		UART_PARITY_FORCE_0		((0x03UL<<UART_LCR_PSEL_Pos)|(0x1<<UART_LCR_PEN_Pos))		/*У��λǿ��Ϊ0*/


/*****************************************************************************
 ** \brief	
 **			
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/

							
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************
 ** \brief	UART_ConfigRunMode
 **			�����첽��������ģʽ
 ** \param [in] uart: UART0��UART1
 **				Baudrate:������
 **				WordLength:(1)UART_WLS_5
 **							(2)UART_WLS_6
 **							(3)UART_WLS_7
 **							(4)UART_WLS_8
 **				Parity:	(1)UART_PARITY_NONE
 **						(2)UART_PARITY_ODD
 **						(3)UART_PARITY_EVEN
 **						(4)UART_PARITY_FORCE_1
 **					 	(5)UART_PARITY_FORCE_0
 **				StopBit:(1)UART_STOP_BIT_1
 **						(2)UART_STOP_BIT_2
 ** \return  none
 ** \note	
*****************************************************************************/
void UART_ConfigRunMode(UART_T* uart,uint32_t Baudrate,uint32_t WordLength, 
						uint32_t Parity, uint32_t StopBit);


#ifdef __cplusplus
}
#endif

#endif /* __UART_H_ */

