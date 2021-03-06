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
/** \file epwm.h
**
** History:
** 
*****************************************************************************/
#ifndef __EPWM_H_
#define __EPWM_H_

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
 **EPWM ͨ??
-----------------------------------------------------------------------------*/
#define	EPWM0 			(0x00UL)
#define	EPWM1 			(0x01UL)
#define	EPWM2 			(0x02UL)
#define	EPWM3 			(0x03UL)
#define	EPWM4 			(0x04UL)
#define	EPWM5 			(0x05UL)

#define	EPWM_CH_0_MSK 		(0x01UL)
#define	EPWM_CH_1_MSK 		(0x02UL)
#define	EPWM_CH_2_MSK 		(0x04UL)
#define	EPWM_CH_3_MSK 		(0x08UL)
#define EPWM_CH_4_MSK 		(0x10UL)
#define	EPWM_CH_5_MSK		(0x20UL)

/*----------------------------------------------------------------------------
 **EPWM ??ӳ??
-----------------------------------------------------------------------------*/
#define	IPG0			(0x00UL)
#define	IPG1			(0x01UL)
#define	IPG2			(0x02UL)
#define	IPG3			(0x03UL)
#define	IPG4			(0x04UL)
#define	IPG5			(0x05UL)
#define EPWM_REMAP_ENABLE	(0xAAUL)
/*----------------------------------------------------------------------------
 **EPWM ģʽ
-----------------------------------------------------------------------------*/
/*------EPWM????ģʽ---------------------------------------------------------*/
#define EPWM_COUNT_UP_DOWN			(0x01UL<<EPWM_CON_CNTTYPE_Pos)  	/*EPWM??????COUNT??ģʽ?????¼????????Ķ??룩ģʽ*/
#define EPWM_COUNT_DOWN				(0x00UL)  							/*EPWM??????COUNT??ģʽ?????¼????????ض??룩ģʽ*/
/*------EPWM?????Ƚϵ?Ԫ(OCU)ģʽ--------------------------------------------*/
#define EPWM_OCU_ASYMMETRIC			(0x01UL<<EPWM_CON_ASYMEN_Pos)  		/*EPWM?????Ƚϵ?Ԫ??OCU??ģʽ?? ?ǶԳ?ģʽ*/
#define EPWM_OCU_SYMMETRIC			(0x00UL) 					 		/*EPWM?????Ƚϵ?Ԫ??OCU??ģʽ?? ?Գ?ģʽ*/
/*------EPWM???η???????Ԫ(WFG)ģʽ------------------------------------------*/
#define EPWM_WFG_INDEPENDENT		(0x0UL)  							/*EPWM???η???????WFG??ģʽ??????????????ģʽ*/
#define EPWM_WFG_COMPLEMENTARYK 	(0x1UL<<EPWM_CON_MODE_Pos) 			/*EPWM???η???????WFG??ģʽ??????ģʽ*/
#define EPWM_WFG_SYNCHRONIZED		(0x2UL<<EPWM_CON_MODE_Pos) 			/*EPWM???η???????WFG??ģʽ??ͬ??ģʽ*/
/*------EPWM???????Ƶ?Ԫ(OC)ģʽ---------------------------------------------*/
#define EPWM_OC_GROUP				(0x01UL<<EPWM_CON_GROUNPEN_Pos)  	/*EPWM???????ƣ?OC??ģʽ?? ????ģʽ*/
#define EPWM_OC_INDEPENDENT			(0x00UL) 						 	/*EPWM???????ƣ?OC??ģʽ?? ͨ?????Զ???????*/

/*----------------------------------------------------------------------------
 **EPWM ʱ??
-----------------------------------------------------------------------------*/
#define 	EPWM_CLK_DIV_1				(0x5UL)		
#define 	EPWM_CLK_DIV_2				(0x4UL)		
#define	 	EPWM_CLK_DIV_4				(0x0UL)		
#define	 	EPWM_CLK_DIV_8				(0x1UL)		
#define 	EPWM_CLK_DIV_16				(0x2UL)		
#define 	EPWM_CLK_DIV_32				(0x3UL)		

/*----------------------------------------------------------------------------
 **EPWM ???ڡ?ռ?ձȼ??ط?ʽ???????жϡ??????жϲ?????ʽ
-----------------------------------------------------------------------------*/
#define		EPWM_EACH_PERIOD_ZERO		(0x0UL)		/*ÿ???????????ڵ?*/
#define		EPWM_EACH_ZERO				(0x1UL)		/*ÿ??????*/
#define		EPWM_FIRST_ZERO_NEXT_PERIOD	(0x2UL)		/*??һ??????????һ?????ڵ?*/
#define		EPWM_EVERY_TWO_ZERO			(0x3UL)		/*ÿ????????*/
/*----------------------------------------------------------------------------
 **EPWM ?¼?????????
-----------------------------------------------------------------------------*/
#define		EPWM_EVENT_ACMP0		(0x00UL)		/*ACMP0 ?¼?????????LOADENn=1*/
#define		EPWM_EVENT_ACMP1		(0x01UL)		/*ACMP1 ?¼?????????LOADENn=1*/
#define		EPWM_EVENT_HALL			(0x02UL)		/*HALL ״̬?仯????LOADENn=1*/ 

/*----------------------------------------------------------------------------
 **EPWM ????????
-----------------------------------------------------------------------------*/
#define		EPWM_MASK_LOAD_EPWM0	(0x0UL<<EPWM_POEN_MASKLS_Pos)		/*??EPWM0 ?ļ??ص?????????????*/
#define		EPWM_MASK_LOAD_EPWM1	(0x1UL<<EPWM_POEN_MASKLS_Pos)		/*??EPWM1 ?ļ??ص?????????????*/
#define		EPWM_MASK_LOAD_EPWM2	(0x2UL<<EPWM_POEN_MASKLS_Pos)		/*??EPWM2 ?ļ??ص?????????????*/
#define		EPWM_MASK_LOAD_EPWM3	(0x3UL<<EPWM_POEN_MASKLS_Pos)		/*??EPWM3 ?ļ??ص?????????????*/
#define		EPWM_MASK_LOAD_EPWM4	(0x4UL<<EPWM_POEN_MASKLS_Pos)		/*??EPWM4 ?ļ??ص?????????????*/		
#define		EPWM_MASK_LOAD_EPWM5	(0x5UL<<EPWM_POEN_MASKLS_Pos)		/*??EPWM5 ?ļ??ص?????????????*/
/*----------------------------------------------------------------------------
 **EPWM ????????Ԥ????
-----------------------------------------------------------------------------*/
#define		EPWM_MASK_BUF0			(0x0UL)		
#define		EPWM_MASK_BUF1			(0x1UL)	
#define		EPWM_MASK_BUF2			(0x2UL)	
#define		EPWM_MASK_BUF3			(0x3UL)	
#define		EPWM_MASK_BUF4			(0x4UL)	
#define		EPWM_MASK_BUF5			(0x5UL)	
#define		EPWM_MASK_BUF6			(0x6UL)	
#define		EPWM_MASK_BUF7			(0x7UL)	

/*----------------------------------------------------------------------------
 **EPWM ?????Ƚϴ???ADC????
-----------------------------------------------------------------------------*/
#define		EPWM_CMPTG_FALLING		(0x00UL)		/*???ĶԳƼ???ʱ?????¼???????*/
#define		EPWM_CMPTG_RISING		(0x01UL)		/*???ĶԳƼ???ʱ?????ϼ???????*/

#define		EPWM_CMPTG_0			(0x00UL)		/*?????Ƚ?ͨ??0 */
#define		EPWM_CMPTG_1			(0x01UL)		/*?????Ƚ?ͨ??1 */

#define		EPWM_CMPTG_EPWM0		(0x00UL)		/*?Ƚ???ѡ??EPWM0?ļ?????*/
#define		EPWM_CMPTG_EPWM1		(0x01UL)		/*?Ƚ???ѡ??EPWM1?ļ?????*/
#define		EPWM_CMPTG_EPWM2		(0x02UL)		/*?Ƚ???ѡ??EPWM2?ļ?????*/
#define		EPWM_CMPTG_EPWM3		(0x03UL)		/*?Ƚ???ѡ??EPWM3?ļ?????*/
#define		EPWM_CMPTG_EPWM4		(0x04UL)		/*?Ƚ???ѡ??EPWM4?ļ?????*/
#define		EPWM_CMPTG_EPWM5		(0x05UL)		/*?Ƚ???ѡ??EPWM5?ļ?????*/



/*----------------------------------------------------------------------------
 **EPWM  ɲ??
-----------------------------------------------------------------------------*/
#define 	EPWM_BRK_SOFT			(0x00)			/*????ɲ??*/
#define 	EPWM_BRK_EXT			(EPWM_BRKCTL_EXTBRKLE_Msk|EPWM_BRKCTL_EXTBRKEE_Msk)			/*?ⲿӲ??ɲ??*/
#define 	EPWM_BRK_ADC1CMP0		(EPWM_BRKCTL_ADC1PM0BKEN_Msk)		/*ADC1?Ƚ???0ɲ??*/
#define 	EPWM_BRK_ADC1CMP1		(EPWM_BRKCTL_ADC1PM1BKEN_Msk)		/*ADC1?Ƚ???1ɲ??*/	
#define 	EPWM_BRK_ADC0CMP0		(EPWM_BRKCTL_ADC0PM0BKEN_Msk)		/*ADC0?Ƚ???0ɲ??*/
#define 	EPWM_BRK_ACMP0			(EPWM_BRKCTL_ACMP0BKEN_Msk)			/*ģ???Ƚ???0?¼?ɲ??*/
#define 	EPWM_BRK_ACMP1			(EPWM_BRKCTL_ACMP1BKEN_Msk)			/*ģ???Ƚ???1?¼?ɲ??*/	
/*----------------------------------------------------------------------------
 **EPWM  ?ⲿӲ??ɲ??
-----------------------------------------------------------------------------*/
#define		EPWM_EXTBK_EDGE_FALLING		(EPWM_BRKCTL_EXTBRKEE_Msk)
#define		EPWM_EXTBK_EDGE_RISING		(EPWM_BRKCTL_EXTBRKEE_Msk|EPWM_BRKCTL_EXTBRKES_Msk)
#define		EPWM_EXTBK_LEVEL_HIGH		(EPWM_BRKCTL_EXTBRKLE_Msk|EPWM_BRKCTL_EXTBRKLS_Msk)
#define		EPWM_EXTBK_LEVEL_LOW		(EPWM_BRKCTL_EXTBRKLE_Msk)

/*----------------------------------------------------------------------------
 **EPWM д????
-----------------------------------------------------------------------------*/
#define		EPWM_LOCK_P1A_WRITE_KEY		(0xAAUL)
#define		EPWM_LOCK_P1B_WRITE_KEY		(0x55UL)

/*****************************************************************************
 ** \brief	EPWM_GET_BRAKE_RIS_FLAG
 **			??ȡɲ???ж?Դ??־
 ** \param [in] none
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_BRAKE_RIS_FLAG()		(((EPWM->RIS&EPWM_RIS_BRKIF_Msk)? 1:0))

/*****************************************************************************
 ** \brief	EPWM_GET_HALLERROR_RIS_FLAG
 **			??ȡHall״̬?????ж?Դ??־
 ** \param [in] none
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_HALLERROR_RIS_FLAG()		(((EPWM->RIS&EPWM_RIS_HALLIF_Msk)? 1:0))

/*****************************************************************************
 ** \brief	EPWM_GET_UPCMP_RIS_FLAG
 **			??ȡ???ϱȽ??ж?Դ??־
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_UPCMP_RIS_FLAG(EPWMn)		(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_UIFn_Pos))? 1:0)))
		
/*****************************************************************************
 ** \brief	EPWM_GET_DOWNCMP_RIS_FLAG
 **			??ȡ???±Ƚ??ж?Դ??־
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_DOWNCMP_RIS_FLAG(EPWMn)		(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_DIFn_Pos)))? 1:0))


/*****************************************************************************
 ** \brief	EPWM_GET_PERIOD_RIS_FLAG
 **			??ȡ?????ж?Դ??־
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_PERIOD_RIS_FLAG(EPWMn)		(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_PIFn_Pos)))? 1:0))
		
/*****************************************************************************
 ** \brief	EPWM_GET_ZERO_RIS_FLAG
 **			??ȡ?????ж?Դ??־
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_ZERO_RIS_FLAG(EPWMn)	(((EPWM->RIS&(0x1<<(EPWMn+EPWM_RIS_ZIFn_Pos)))? 1:0))

/*****************************************************************************
 ** \brief	EPWM_GET_COUNTCMP0_RIS_FLAG
 **			??ȡ?????Ƚ???0?ж?Դ??־
 ** \param [in]none
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_COUNTCMP0_RIS_FLAG(EPWMn)	(((EPWM->RIS&(EPWM_RIS_DC0IF_Msk)))? 1:0)

/*****************************************************************************
 ** \brief	EPWM_GET_COUNTCMP1_RIS_FLAG
 **			??ȡ?????Ƚ???1?ж?Դ??־
 ** \param [in]none
 ** \return  1???????ж?  0:???ж?
 ** \note	 
*****************************************************************************/
#define 	EPWM_GET_COUNTCMP1_RIS_FLAG(EPWMn)	(((EPWM->RIS&(EPWM_RIS_DC1IF_Msk))? 1:0))




/*****************************************************************************
 ** \brief	EPWM_SET_COMPARE
 **			????EPWMn?Ƚ?ֵ
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **			   CMR : 16λ?Ƚ???ֵ	
 ** \return  
 ** \note	 
*****************************************************************************/
#define 	EPWM_SET_COMPARE(EPWMn,CMR)	 do{\
											EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;\
											EPWM->CMPADT[EPWMn] &= 0xffff0000;\
											EPWM->CMPADT[EPWMn] |= 0xffff & CMR;\
											EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos ));\
											EPWM->LOCK = 0x0;\
										  }while(0)
/*****************************************************************************
 ** \brief	EPWM_SET_PERIOD
 **			????EPWMn????ֵ
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **			   period : 16λ????ֵ	
 ** \return  
 ** \note	 
*****************************************************************************/
#define 	EPWM_SET_PERIOD(EPWMn,period)	do{\
												EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;\
												EPWM->PERIOD[EPWMn] = 0xffff & Period;\
												EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos ));\
												EPWM->LOCK = 0x0;\
											}while(0)

/*****************************************************************************
 ** \brief	EPWM_SET_COMPARE_D
 **			????EPWMn???±Ƚ?ֵ
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **			   CMRD : 16λ???±Ƚ???ֵ	
 ** \return  
 ** \note	 
*****************************************************************************/
#define 	EPWM_SET_COMPARE_D(EPWMn,CMRD)	do{\
													EPWM->LOCK = EPWM_LOCK_P1B_WRITE_KEY;\
													EPWM->CMPADT[EPWMn] &= 0xffff;\
													EPWM->CMPADT[EPWMn] |= ((0xffff & CMRD)<< 16);\
													EPWM->CON3 |= (0x1UL <<(EPWMn +EPWM_CON3_LOADEN0_Pos ));\
													EPWM->LOCK = 0x0;\
											 }while(0)
	
											 
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
 ** \brief	 EPWM_ConfigRunMode
 **			 ????EPWM??????ģʽ
 ** \param [in] EpwmRunMode:   (1)EPWM_COUNT_UP_DOWN
							   (2)EPWM_COUNT_DOWN
							   (3)EPWM_OCU_ASYMMETRIC
							   (4)EPWM_OCU_SYMMETRIC
							   (5)EPWM_WFG_INDEPENDENT
							   (6)EPWM_WFG_COMPLEMENTARY
							   (7)EPWM_WFG_SYNCHRONIZED
							   (8)EPWM_OC_MODE_GROUP
							   (9)EPWM_OC_INDEPENDENT
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_ConfigRunMode(uint32_t EpwmRunMode);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelClk	
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **				ClkDiv: (1)EPWM_CLK_DIV_1 
 **						(2)EPWM_CLK_DIV_2
 **						(2)EPWM_CLK_DIV_4
 **						(2)EPWM_CLK_DIV_8
 **						(2)EPWM_CLK_DIV_16
 **						(2)EPWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)????ΪCLKPSC01??ͬ????PWM0??PWM1ͨ?? ?????Դ˺???ͳһ????CLKPSC01=0x01
 **     ????Ҫ?????ķ?Ƶ?????????ԼĴ?????ֵ.
 **	(2)EPWM ??Ƶ??Ϊ??????CLKPSC CLKDIV
 **		??һ????Ƶ(CLKPSC)??0x00 Ԥ??Ƶֹͣ???Ҽ?????ֹͣ ????????ϵͳʱ?ӷ?Ƶϵ?? CLKPSC+1
 **		?ڶ?????Ƶ??CLKDIV): 0x00 FEPWMPSC/2; 0x01 FEPWMPSC/4??0x02:FEPWMPSC/8??0x3 FEPWMPSC/16 0x04 FEPWMPSC ; ???? Fsys 
 ** 	??Ƶ??????1~4096????Fsys=8M??EPWM??Ƶ?ʷ?Χ??1.95k ~ 8M	   
*****************************************************************************/
void EPWM_ConfigChannelClk(uint32_t EPWMn,uint32_t ClkDiv);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelPeriod	
 **			 ????EPWMͨ????????
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **				Period: 16λ????ֵ
 ** \return none
 ** \note    
*****************************************************************************/
void EPWM_ConfigChannelPeriod(uint32_t EPWMn, uint32_t Period);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelSymDuty	
 **			 ???öԳ?ģʽ?µ?EPWMͨ????ռ?ձ?
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **			    Duty  : 16λ?Ƚ?ֵ
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelSymDuty(uint32_t EPWMn,uint32_t Duty);

/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelAsymDuty	
 **			 ???÷ǶԳ?ģʽ?µ? EPWMͨ????ռ?ձ?
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **			    UpCmp 	  : 16λ???ϱȽ?ֵ
 **			    DownCmp   : 16λ???±Ƚ?ֵ
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelAsymDuty(uint32_t EPWMn,uint32_t UpCmp, uint32_t DownCmp);

/*****************************************************************************
 ** \brief	 EPWM_EnableOneShotMode	
 **			 ʹ?ܵ???ģʽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableOneShotMode(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_EnableAutoLoadMode	
 **			 ʹ??????????ģʽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableAutoLoadMode(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_EnableReverseOutput	
 **			 ????????????
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableReverseOutput(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_DisableReverseOutput	
 **			 ?رշ???????
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableReverseOutput(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_EnableDeadZone	
 **			 ????????
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 **				DeadZone : 0x00 ~ 0x3FF;
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableDeadZone(uint32_t EPWMnMask, uint32_t DeadZone);

/*****************************************************************************
 ** \brief	 EPWM_DisableDeadZone	
 **			 ?ر?????
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableDeadZone(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_EnableChannelRemap	
 **			 ????ͨ????ӳ??
 ** \param [in]  EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 
 **				 IPGn  : IPG0 ??IPG1 ??IPG2 ??IPG3 ??IPG4 ??IPG5 
 ** \return none
 ** \note   IPGxָ?ڲ?ͨ????EPWMxָ?ⲿ????ͨ??
*****************************************************************************/
void EPWM_EnableChannelRemap(uint32_t EPWMn, uint32_t IPGn);

/*****************************************************************************
 ** \brief	 EPWM_DisableChannelRemap	
 **			 ?ر?ͨ????ӳ??
 ** \param [in]  none
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableChannelRemap(void);

/*****************************************************************************
 ** \brief	 EPWM_Start	
 **			 ????EPWM
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_Start(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_Stop	
 **			 ?ر?EPWM
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_Stop(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_ForceStop	
 **			 ǿ?ƹر?EPWM
 ** \param [in]  none
 ** \return none
 ** \note   ʹ??????????EPWM
*****************************************************************************/
void EPWM_ForceStop(void);

/*****************************************************************************
 ** \brief	 EPWM_EnableOutput
 **			 ????EPWMͨ??????
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void EPWM_EnableOutput(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableOutput
 **			 ?ر?EPWMͨ??????
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableOutput(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_ConfigLoadAndIntMode
 **			 ???ü??ط?ʽ?Լ??жϷ?ʽ
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 **				 Mode: (1)EPWM_EACH_PERIOD_ZERO
 **					   (2)EPWM_EACH_ZERO
 **					   (3)EPWM_FIRST_ZERO_NEXT_PERIOD
 **					   (4)EPWM_EVERY_TWO_ZERO
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigLoadAndIntMode(uint32_t EPWMnMask, uint32_t Mode);

/*****************************************************************************
 ** \brief	 EPWM_EnableEventLoad
 **			 ʹ???¼?????????
 ** \param [in]  Event :(1)EPWM_EVENT_HALL
 **						(2)EPWM_EVENT_ACMP1
 **						(3)EPWM_EVENT_ACMP0
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableEventLoad(uint32_t Event);

/*****************************************************************************
 ** \brief	 EPWM_EnableMaskPreload
 **			 ʹ??????Ԥ????
 ** \param [in] LoadMode: (1)EPWM_MASK_LOAD_EPWM0	??EPWM0 ?ļ??ص?????????????
 **					  	  (2)EPWM_MASK_LOAD_EPWM1	??EPWM1 ?ļ??ص?????????????
 **					  	  (3)EPWM_MASK_LOAD_EPWM2	??EPWM2 ?ļ??ص?????????????
 **					  	  (4)EPWM_MASK_LOAD_EPWM3	??EPWM3 ?ļ??ص?????????????
 **					  	  (5)EPWM_MASK_LOAD_EPWM4	??EPWM4 ?ļ??ص?????????????
 **					  	  (5)EPWM_MASK_LOAD_EPWM5	??EPWM5 ?ļ??ص?????????????
 ** \return none
 ** \note   ???? MASKNXT ?Ĵ????????ݼ??ص?MASK ?Ĵ????У?ͬʱ??ֹд MASK ?Ĵ???
*****************************************************************************/
void EPWM_EnableMaskPreload(uint32_t LoadMode);

/*****************************************************************************
 ** \brief	 EPWM_DisableMaskPreload
 **			 ?ر?????Ԥ????
 ** \param [in] none
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableMaskPreload(void);
/*****************************************************************************
 ** \brief	 EPWM_WriteMaskBuffer
 **			 д????Ԥ???ػ???
 ** \param [in] MaskBuffer:  EPWM_MASK_BUF0 ??EPWM_MASK_BUF1??EPWM_MASK_BUF2??EPWM_MASK_BUF3
 **							 EPWM_MASK_BUF4??EPWM_MASK_BUF5??EPWM_MASK_BUF6??EPWM_MASK_BUF7
 **				BufferValue: 16bit
 ** \return none
 ** \note   HALLEN=0 ʱ??Ĭ?ϼ???????Ԥ?軺??0?е????ݡ?
*****************************************************************************/
void EPWM_WriteMaskBuffer(uint32_t MaskBuffer, uint32_t BufferValue);

/*****************************************************************************
 ** \brief	 EPWM_EnableMaskOutPut
 **			 ʹ??????????
 ** \param [in]EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 **				MaskLevel:  0???͵?ƽ  1???ߵ?ƽ
 ** \return none
 ** \note   ?????˺???ʱ???ر?????Ԥ????
*****************************************************************************/
void EPWM_EnableMaskOutPut(uint32_t EPWMnMask, uint32_t MaskLevel);
/*****************************************************************************
 ** \brief	 EPWM_DisableMaskOutPut
 **			 ?ر?????????
 ** \param [in]EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note   ?????˺???ʱ???ر?????Ԥ????
*****************************************************************************/
void EPWM_DisableMaskOutPut(uint32_t EPWMnMask);

/*****************************************************************************
 ** \brief	 EPWM_ConfigCompareTriger
 **			 ???ô????Ƚ???
 ** \param [in]CmpTgn: EPWM_CMPTG_0??EPWM_CMPTG_1
 **			   CmpTgMode: (1)EPWM_CMPTG_FALLING
 **						  (2)EPWM_CMPTG_RISING
 **			   CmpTgCounter: (1)EPWM_CMPTG_EPWM0
 **							 (2)EPWM_CMPTG_EPWM1
 **							 (3)EPWM_CMPTG_EPWM2
 **							 (4)EPWM_CMPTG_EPWM3
 **							 (5)EPWM_CMPTG_EPWM4
 **							 (6)EPWM_CMPTG_EPWM5
 **			   CmpTgData: 0x00~ 0xffff;
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_ConfigCompareTriger(uint32_t CmpTgn, uint32_t CmpTgMode,uint32_t CmpTgCounter, uint32_t CmpTgData);

/*****************************************************************************
 ** \brief	 EPWM_EnableHall
 **			 ????Hallģʽ????
 ** \param [in] none
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_EnableHall(void);
/*****************************************************************************
 ** \brief	 EPWM_DisableHall
 **			 ?ر?Hallģʽ????
 ** \param [in] none
 ** \return none
 ** \note   
*****************************************************************************/
void EPWM_DisableHall(void);
/*****************************************************************************
 ** \brief	 EPWM_GetHallState
 **			 ??ȡHall?ӿ?״̬
 ** \param [in] none
 ** \return Hall State
 ** \note   
*****************************************************************************/
uint32_t  EPWM_GetHallState(void);
/*****************************************************************************
 ** \brief	 EPWM_ClearHallErrorState
 **			 ????Hall?ӿڴ???״̬
 ** \param [in] none
 ** \return none
 ** \note  ???????ֵĴ?????״̬????????ʱ??HALLST=111??HALL ???⹦??ֹͣ??
 **			?ٴμ??⿪?? HALL ״̬ʱ????Ҫ??????????״̬?? 
*****************************************************************************/
void  EPWM_ClearHallErrorState(void);


/*****************************************************************************
 ** \brief	 EPWM_AllBrakeEnable
 **			 ????ɲ????ʹ??
 ** \param [in] none
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_AllBrakeEnable(void);

/*****************************************************************************
 ** \brief	 EPWM_AllBrakeDisable
 **			?ر?ɲ????ʹ??
 ** \param [in] none
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_AllBrakeDisable(void);

/*****************************************************************************
 ** \brief	 EPWM_EnableFaultBrake
 **			 ????ɲ??
 ** \param [in] BrakeSource:(1)EPWM_BRK_SOFT:????ɲ??
 **							(2)EPWM_BRK_EXT :?ⲿӲ??ɲ??
 **							(3)EPWM_BRK_ADC1CMP0 :ADC1?Ƚ???0ɲ??
 **							(4)EPWM_BRK_ADC1CMP1 :ADC1?Ƚ???1ɲ??
 **							(5)EPWM_BRK_ACMP0 :ģ???Ƚ???0?¼?ɲ??
 **							(6)EPWM_BRK_ACMP1 :ģ???Ƚ???1?¼?ɲ??
 **							(7)EPWM_BRK_ADC0MP0 :ADC0?Ƚ???0ɲ??	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableFaultBrake(uint32_t BrakeSource);
/*****************************************************************************
 ** \brief	 EPWM_DisableFaultBrake
 **			 ?ر?ɲ??
 ** \param [in] BrakeSource:(1)EPWM_BRK_SOFT:????ɲ??
 **							(2)EPWM_BRK_EXT :?ⲿӲ??ɲ??
 **							(3)EPWM_BRK_ADC1CMP0 :ADC1?Ƚ???0ɲ??
 **							(4)EPWM_BRK_ADC1CMP1 :ADC1?Ƚ???1ɲ??
 **							(5)EPWM_BRK_ACMP0 :ģ???Ƚ???0?¼?ɲ??
 **							(6)EPWM_BRK_ACMP1 :ģ???Ƚ???1?¼?ɲ??
 **							(7)EPWM_BRK_ADC0MP0 :ADC0?Ƚ???0ɲ??					
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableFaultBrake(uint32_t BrakeSource);
/*****************************************************************************
 ** \brief	 EPWM_ConfigFaultBrakeLevel
 **			 ????EPWMnɲ????ƽ
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 **				BrakeLevel:  0???͵?ƽ  1???ߵ?ƽ			
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ConfigFaultBrakeLevel(uint32_t EPWMnMask, uint32_t BrakeLevel);


/*****************************************************************************
 ** \brief	 EPWM_EnableEXTBrake
 **			 ?????ⲿӲ??ɲ??ģʽ
 ** \param [in] BrakeMode??	(1)	EPWM_EXTBK_EDGE_FALLING 	?½???ɲ??
 **					   		(2) EPWM_EXTBK_EDGE_RISING		??????ɲ??
 **					   		(3) EPWM_EXTBK_LEVEL_HIGH		?ߵ?ƽɲ??
 **					   		(4)	EPWM_EXTBK_LEVEL_LOW		?͵?ƽɲ??
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableEXTBrake(uint32_t BrakeMode);

/*****************************************************************************
 ** \brief	 EPWM_EnableSoftwareBrake
 **			 ʹ??????ɲ??
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableSoftwareBrake(void);

/*****************************************************************************
 ** \brief	 EPWM_DisableSoftwareBrake
 **			 ?ر?????ɲ??
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableSoftwareBrake(void);



/*****************************************************************************
 ** \brief	 EPWM_EnableBrakeInt
 **			 ????ɲ???ж?
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableBrakeInt(void);
/*****************************************************************************
 ** \brief	 EPWM_DisableBrakeInt
 **			 ?ر?ɲ???ж?
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableBrakeInt(void);
/*****************************************************************************
 ** \brief	 EPWM_GetBrakeIntFlag
 **			??ȡɲ???ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] none	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetBrakeIntFlag(void);
/*****************************************************************************
 ** \brief	 EPWM_ClearBrakeIntFlag
 **			????ɲ???жϱ?־λ
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearBrakeIntFlag(void);


/*****************************************************************************
 ** \brief	 EPWM_EnableHallErrorInt
 **			 ????Hall״̬?????ж?
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableHallErrorInt(void);
/*****************************************************************************
 ** \brief	 EPWM_DisableHallErrorInt
 **			 ?ر?Hall״̬?????ж?
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableHallErrorInt(void);
/*****************************************************************************
 ** \brief	 EPWM_GetHallErrorIntFlag
 **			??ȡHall״̬?????ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] none	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetHallErrorIntFlag(void);
/*****************************************************************************
 ** \brief	 EPWM_ClearHallErrorIntFlag
 **			????Hall״̬?????жϱ?־λ
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearHallErrorIntFlag(void);

/*****************************************************************************
 ** \brief	 EPWM_EnableUpCmpInt
 **			 ???????ϱȽ??ж?
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableUpCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableUpCmpInt
 **			 ?ر????ϱȽ??ж?
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableUpCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			??ȡ???ϱȽ??ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetUpCmpIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			???????ϱȽ??жϱ?־λ
 ** \param [in]EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearUpCmpIntFlag(uint32_t EPWMn);

/*****************************************************************************
 ** \brief	 EPWM_EnableDownCmpInt
 **			 ???????±Ƚ??ж?
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableDownCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableDownCmpInt
 **			 ?ر????±Ƚ??ж?
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableDownCmpInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetDownCmpIntFlag
 **			??ȡ???±Ƚ??ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetDownCmpIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearDownCmpIntFlag
 **			???????±Ƚ??жϱ?־λ
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearDownCmpIntFlag(uint32_t EPWMn);


/*****************************************************************************
 ** \brief	 EPWM_EnablePeriodInt
 **			 ?????????ж?
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnablePeriodInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisablePeriodInt
 **			 ?ر??????ж?
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisablePeriodInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetPeriodIntFlag
 **			??ȡ?????ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetPeriodIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			?????????жϱ?־λ
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearPeriodIntFlag(uint32_t EPWMn);

/*****************************************************************************
 ** \brief	 EPWM_EnableZeroInt
 **			 ?????????ж?
 ** \param [in]  EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableZeroInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableZeroInt
 **			 ?ر??????ж?
 ** \param [in] EPWMnMask : EPWM_CH_0_MSK ??EPWM_CH_1_MSK ??EPWM_CH_2_MSK ??
 **							 EPWM_CH_3_MSK ??EPWM_CH_4_MSK ??EPWM_CH_5_MSK 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableZeroInt(uint32_t EPWMnMask);
/*****************************************************************************
 ** \brief	 EPWM_GetZeroIntFlag
 **			??ȡ?????ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetZeroIntFlag(uint32_t EPWMn);
/*****************************************************************************
 ** \brief	 EPWM_ClearZeroIntFlag
 **			?????????жϱ?־λ
 ** \param [in] EPWMn : EPWM0 ??EPWM1 ??EPWM2 ??EPWM3 ??EPWM4 ??EPWM5 	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearZeroIntFlag(uint32_t EPWMn);

/*****************************************************************************
 ** \brief	 EPWM_EnableCountCmpInt
 **			 ?????????Ƚ????ж?
 ** \param [in] EPWMCmp: EPWM_CMPTG_0 EPWM_CMPTG_1
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableCountCmpInt(uint32_t EPWMCmp);
/*****************************************************************************
 ** \brief	 EPWM_DisableCountCmp0Int
 **			 ?رռ????Ƚ????ж?
 ** \param [in] EPWMCmp: EPWM_CMPTG_0 EPWM_CMPTG_1	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableCountCmpInt(uint32_t EPWMCmp);
/*****************************************************************************
 ** \brief	 EPWM_GetCountCmpIntFlag
 **			??ȡ?????Ƚ????ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] EPWMCmp: EPWM_CMPTG_0 EPWM_CMPTG_1	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetCountCmpIntFlag(uint32_t EPWMCmp);
/*****************************************************************************
 ** \brief	 EPWM_ClearCountCmp0IntFlag
 **			?????????Ƚ????жϱ?־λ
 ** \param [in] EPWMCmp: EPWM_CMPTG_0 EPWM_CMPTG_1	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearCountCmpIntFlag(uint32_t EPWMCmp);




/*****************************************************************************
 ** \brief	 EPWM_EnableCountCmp1Int
 **			 ?????????Ƚ???1?ж?
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_EnableCountCmp1Int(void);
/*****************************************************************************
 ** \brief	 EPWM_DisableCountCmp1Int
 **			 ?رռ????Ƚ???1?ж?
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_DisableCountCmp1Int(void);
/*****************************************************************************
 ** \brief	 EPWM_GetCountCmp1IntFlag
 **			??ȡ?????Ƚ???1?ж?ʹ?ܲ??????жϱ?־λ
 ** \param [in] none	
 ** \return 1???ж?ʹ?ܲ??Ҳ????ж?  0?????ж?
 ** \note  
*****************************************************************************/
uint32_t  EPWM_GetCountCmp1IntFlag(void);
/*****************************************************************************
 ** \brief	 EPWM_ClearCountCmp1IntFlag
 **			?????????Ƚ???1?жϱ?־λ
 ** \param [in] none	
 ** \return none
 ** \note  
*****************************************************************************/
void  EPWM_ClearCountCmp1IntFlag(void);





#ifdef __cplusplus
}
#endif

#endif /*__EPWM_H_ */

