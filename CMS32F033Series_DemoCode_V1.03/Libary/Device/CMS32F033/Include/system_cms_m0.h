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
/** \file system_cms_m0.h
**
** History:
** 
*****************************************************************************/
#ifndef __SYSTEM_CMS_M0_H_
#define __SYSTEM_CMS_M0_H_

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include  "stdint.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 ** System 系统时钟
------------------------------------------------------------------------------*/
#define __HIRC_64M			(64000000ul)  			/*内部高速64M 时钟*/
#define __HIRC_48M    	    (48000000ul)    	  	/*内部高速48M时钟*/
#define __LIRC   			(40000ul)    	 	    /*内部低速48M时钟*/

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/
extern uint32_t SystemCoreClock;  			/*系统时钟或AHB时钟*/
extern uint32_t SystemAPBClock;    			/*系统的APB时钟*/
extern uint32_t CyclesPerUs;     				/*系统时钟周期*/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************
 ** \brief	 SystemInit
 **			 		
 ** \param [in] none
 ** \return  none
 ** \note		not use
*****************************************************************************/ 
extern void SystemInit(void);
/*****************************************************************************
 ** \brief	 SystemCoreClockUpdate
 **			 		 加载SystemCoreClock值
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_CMS_M0_H_*/


