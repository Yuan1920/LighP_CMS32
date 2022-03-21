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
/** \file adc1.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "adc1.h"
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
 ** \brief	ADC1_ConfigRunMode
 **			设置ADC运行模式
 ** \param [in] ConvertMode:(1)ADC1_CONVERT_SINGLE			
 **							(2)ADC1_CONVERT_CONTINUOUS
 **				ClkDiv :(1)ADC1_CLK_DIV_1
 **						(2)ADC1_CLK_DIV_2
 **						(3)ADC1_CLK_DIV_4
 **						(4)ADC1_CLK_DIV_8
 **						(5)ADC1_CLK_DIV_16
 **						(6)ADC1_CLK_DIV_32
 **						(7)ADC1_CLK_DIV_64
 **						(8)ADC1_CLK_DIV_128
 **				HoldTime:(1)ADC1_HOLD_3P5_CLK
 **						 (2)ADC1_HOLD_4P5_CLK
 **						 (3)ADC1_HOLD_6P5_CLK
 **						 (4)ADC1_HOLD_10P5_CLK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ConfigRunMode(uint32_t ConvertMode, uint32_t ClkDiv,uint32_t HoldTime)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CON &= ~(ADC1_CON_ADCMS_Msk|ADC1_CON_ADCDIV_Msk|ADC1_CON_ADCSHT_Msk);
	ADC1->CON |= ConvertMode |  ClkDiv | HoldTime;	
	ADC1->LOCK = 0x00;
}

/*****************************************************************************
 ** \brief	ADC1_EnableScanChannel
 **			开启ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableScanChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->SCAN |= ChannelMask;
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableScanChannel
 **			关闭ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableScanChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->SCAN &= ~(ChannelMask);
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_SetAN30Channel
 **			设置AN30内部模拟源
 ** \param [in] AN30Channel: (1)ADC1_CH_30_BG 
 **							 (2)ADC1_CH_30_OP0O
 **							 (3)ADC1_CH_30_OP1O
 **							 (4)ADC1_CH_30_PGA0O
 **							 (5)ADC1_CH_30_PGA1O
 **							 (6)ADC1_CH_30_VREF_VSS
 **							 (7)ADC1_CH_30_VREF_VDD
 **							 (8)ADC1_CH_30_VSS
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_SetAN30Channel(uint32_t AN30Channel)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON &= ~(ADC1_CON_ADCICHS_Msk);
	ADC1->CON |= AN30Channel;		
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_GetResult
 **			获取ADC1转换结果
 ** \param [in] Channel: ADC1_CH_0 ~ ADC1_CH_30
 ** \return  12 bits Value
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetResult(uint32_t Channel)
{
	return(ADC1->DATA[Channel]);
}

/*****************************************************************************
 ** \brief	ADC1_EnableHardwareTrigger
 **			开启硬件触发ADC1转换功能
 ** \param [in] TriggerSource: (1)ADC1_TG_EXT_FALLING
 **							(2)ADC1_TG_EXT_RISING
 **							(3)ADC1_TG_INTNEL_ADC0
 **							(4)ADC1_TG_INTNEL_ADC1
 **							(5)ADC1_TG_INTNEL_ACMP0
 **							(6)ADC1_TG_INTNEL_ACMP1
 **							(7)ADC1_TG_INTNEL_TMR0
 **							(8)ADC1_TG_INTNEL_TMR1
 **							(9)ADC1_TG_EPWM_CMP0
 **							(10)ADC1_TG_EPWM_CMP1
 **							(11)ADC1_TG_EPWM0_RISING
 **							(12)ADC1_TG_EPWM0_FALLING
 **							(13)ADC1_TG_EPWM0_PERIOD
 **							(14)ADC1_TG_EPWM0_ZERO
 **							(15)ADC1_TG_EPWM1_RISING
 **							(16)ADC1_TG_EPWM1_FALLING
 **							(17)ADC1_TG_EPWM1_PERIOD
 **							(18)ADC1_TG_EPWM1_ZERRO
 **							(19)ADC1_TG_EPWM2_RISING
 **							(20)ADC1_TG_EPWM2_FALLING
 **							(21)ADC1_TG_EPWM2_PERIOD
 **							(22)ADC1_TG_EPWM2_ZERRO
 **							(23)ADC1_TG_EPWM3_RISING
 **							(24)ADC1_TG_EPWM3_FALLING
 **							(25)ADC1_TG_EPWM3_PERIOD
 **							(26)ADC1_TG_EPWM3_ZERRO
 **							(27)ADC1_TG_EPWM4_RISING
 **							(28)ADC1_TG_EPWM4_FALLING
 **							(29)ADC1_TG_EPWM4_PERIOD
 **							(30)ADC1_TG_EPWM4_ZERRO
 **							(31)ADC1_TG_EPWM5_RISING
 **							(32)ADC1_TG_EPWM5_FALLING
 **							(33)ADC1_TG_EPWM5_PERIOD
 **							(34)ADC1_TG_EPWM5_ZERRO 
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableHardwareTrigger(uint32_t TriggerSource)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	switch(TriggerSource)
	{
		case ADC1_TG_EXT_FALLING:
		case ADC1_TG_EXT_RISING:
			ADC1->HWTG |= TriggerSource;
			break;
		case ADC1_TG_INTNEL_ADC0:
		case ADC1_TG_INTNEL_ADC1:
		case ADC1_TG_INTNEL_ACMP0:
		case ADC1_TG_INTNEL_ACMP1:
		case ADC1_TG_INTNEL_TMR0:
		case ADC1_TG_INTNEL_TMR1:
			ADC1->HWTG &= ~(ADC1_HWTG_ADCINTTGSS_Msk);
			ADC1->HWTG |= TriggerSource;
			break;
		case ADC1_TG_EPWM_CMP0:
		case ADC1_TG_EPWM_CMP1:
			ADC1->HWTG |= TriggerSource;
			break;
		case ADC1_TG_EPWM0_RISING:
		case ADC1_TG_EPWM0_FALLING:
		case ADC1_TG_EPWM0_PERIOD:
		case ADC1_TG_EPWM0_ZERO:
		case ADC1_TG_EPWM1_RISING:
		case ADC1_TG_EPWM1_FALLING:
		case ADC1_TG_EPWM1_PERIOD:
		case ADC1_TG_EPWM1_ZERO:			
		case ADC1_TG_EPWM2_RISING:
		case ADC1_TG_EPWM2_FALLING:
		case ADC1_TG_EPWM2_PERIOD:
		case ADC1_TG_EPWM2_ZERO:		
		case ADC1_TG_EPWM3_RISING:
		case ADC1_TG_EPWM3_FALLING:
		case ADC1_TG_EPWM3_PERIOD:
		case ADC1_TG_EPWM3_ZERO:		
		case ADC1_TG_EPWM4_RISING:
		case ADC1_TG_EPWM4_FALLING:
		case ADC1_TG_EPWM4_PERIOD:
		case ADC1_TG_EPWM4_ZERO:		
		case ADC1_TG_EPWM5_RISING:
		case ADC1_TG_EPWM5_FALLING:
		case ADC1_TG_EPWM5_PERIOD:
		case ADC1_TG_EPWM5_ZERO:			
			ADC1->HWTG &= ~(ADC1_HWTG_ADCEPWMTSS_Msk | ADC1_HWTG_ADCPEWMTPS_Msk);
			ADC1->HWTG |= TriggerSource;		
			break;		
		default:
			break;
	}	
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableHardwareTrigger
 **			关闭硬件触发ADC1转换功能
 ** \param [in] TriggerSource: (1)ADC1_TG_EXT_FALLING
 **							(2)ADC1_TG_EXT_RISING
 **							(3)ADC1_TG_INTNEL_ADC0
 **							(4)ADC1_TG_INTNEL_ADC1
 **							(5)ADC1_TG_INTNEL_ACMP0
 **							(6)ADC1_TG_INTNEL_ACMP1
 **							(7)ADC1_TG_INTNEL_TMR0
 **							(8)ADC1_TG_INTNEL_TMR1
 **							(9)ADC1_TG_EPWM_CMP0
 **							(10)ADC1_TG_EPWM_CMP1
 **							(11)ADC1_TG_EPWM0_RISING
 **							(12)ADC1_TG_EPWM0_FALLING
 **							(13)ADC1_TG_EPWM0_PERIOD
 **							(14)ADC1_TG_EPWM0_ZERRO
 **							(15)ADC1_TG_EPWM1_RISING
 **							(16)ADC1_TG_EPWM1_FALLING
 **							(17)ADC1_TG_EPWM1_PERIOD
 **							(18)ADC1_TG_EPWM1_ZERRO
 **							(19)ADC1_TG_EPWM2_RISING
 **							(20)ADC1_TG_EPWM2_FALLING
 **							(21)ADC1_TG_EPWM2_PERIOD
 **							(22)ADC1_TG_EPWM2_ZERRO
 **							(23)ADC1_TG_EPWM3_RISING
 **							(24)ADC1_TG_EPWM3_FALLING
 **							(25)ADC1_TG_EPWM3_PERIOD
 **							(26)ADC1_TG_EPWM3_ZERRO
 **							(27)ADC1_TG_EPWM4_RISING
 **							(28)ADC1_TG_EPWM4_FALLING
 **							(29)ADC1_TG_EPWM4_PERIOD
 **							(30)ADC1_TG_EPWM4_ZERRO
 **							(31)ADC1_TG_EPWM5_RISING
 **							(32)ADC1_TG_EPWM5_FALLING
 **							(33)ADC1_TG_EPWM5_PERIOD
 **							(34)ADC1_TG_EPWM5_ZERRO 
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableHardwareTrigger(uint32_t TriggerSource)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	switch(TriggerSource)
	{
		case ADC1_TG_EXT_FALLING:
		case ADC1_TG_EXT_RISING:
			ADC1->HWTG &= ~(ADC1_HWTG_ADCEXTEN_Msk);
			break;
		case ADC1_TG_INTNEL_ADC0:
		case ADC1_TG_INTNEL_ADC1:
		case ADC1_TG_INTNEL_ACMP0:
		case ADC1_TG_INTNEL_ACMP1:
		case ADC1_TG_INTNEL_TMR0:
		case ADC1_TG_INTNEL_TMR1:
			ADC1->HWTG &= ~(ADC1_HWTG_ADCINTTGEN_Msk);
			break;
		case ADC1_TG_EPWM_CMP0:
			ADC1->HWTG &= ~(ADC1_HWTG_ADCPTG0EN_Msk);
			break;			
		case ADC1_TG_EPWM_CMP1:
			ADC1->HWTG &= ~(ADC1_HWTG_ADCPTG1EN_Msk);
			break;
		case ADC1_TG_EPWM0_RISING:
		case ADC1_TG_EPWM0_FALLING:
		case ADC1_TG_EPWM0_PERIOD:
		case ADC1_TG_EPWM0_ZERO:
		case ADC1_TG_EPWM1_RISING:
		case ADC1_TG_EPWM1_FALLING:
		case ADC1_TG_EPWM1_PERIOD:
		case ADC1_TG_EPWM1_ZERO:			
		case ADC1_TG_EPWM2_RISING:
		case ADC1_TG_EPWM2_FALLING:
		case ADC1_TG_EPWM2_PERIOD:
		case ADC1_TG_EPWM2_ZERO:		
		case ADC1_TG_EPWM3_RISING:
		case ADC1_TG_EPWM3_FALLING:
		case ADC1_TG_EPWM3_PERIOD:
		case ADC1_TG_EPWM3_ZERO:		
		case ADC1_TG_EPWM4_RISING:
		case ADC1_TG_EPWM4_FALLING:
		case ADC1_TG_EPWM4_PERIOD:
		case ADC1_TG_EPWM4_ZERO:		
		case ADC1_TG_EPWM5_RISING:
		case ADC1_TG_EPWM5_FALLING:
		case ADC1_TG_EPWM5_PERIOD:
		case ADC1_TG_EPWM5_ZERO:			
			ADC1->HWTG &= ~(ADC1_HWTG_ADCEPWMTEN_Msk);	
			break;		
		default:
			break;
	}	
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_SetTriggerDelayTime
 **			设置ADC1 EPWM触发的延时时间
 ** \param [in] DelayTime: 0x00~ 0x3ff;
 ** \return  none
 ** \note  Time = (DelayTime+2)*PCLK
*****************************************************************************/
void ADC1_SetTriggerDelayTime(uint32_t DelayTime)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->EPWMTGDLY = (0x3ff & DelayTime);	
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_EnableEPWMTriggerChannel
 **			使能 EPWM 输出触发的ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC1_EnableEPWMTriggerChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CHEPWM |= ChannelMask;	
	ADC1->LOCK = 0x00;			
}
/*****************************************************************************
 ** \brief	ADC1_DisableEPWMTriggerChannel
 **			关闭 EPWM 输出触发的ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC1_DisableEPWMTriggerChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CHEPWM &= ~(ChannelMask);	
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_EnableEPWMCmp0TriggerChannel
 **			使能 EPWM 比较器0 触发的ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC1_EnableEPWMCmp0TriggerChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CHPTG0 |=(ChannelMask);	
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_DisableEPWMCmp0TriggerChannel
 **			关闭 EPWM 比较器0 触发的ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC1_DisableEPWMCmp0TriggerChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CHPTG0 &=~(ChannelMask);	
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_EnableEPWMCmp1TriggerChannel
 **			使能 EPWM 比较器1 触发的ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC1_EnableEPWMCmp1TriggerChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CHPTG1 |=(ChannelMask);	
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableEPWMCmp1TriggerChannel
 **			关闭 EPWM 比较器1 触发的ADC1转换通道
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC1_DisableEPWMCmp1TriggerChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CHPTG1 &= ~(ChannelMask);	
	ADC1->LOCK = 0x00;	
}


/*****************************************************************************
 ** \brief	ADC1_EnableCompare
 **			开启ADC1比较功能
 ** \param [in] Compare : ADC1_CMP0 、ADC1_CMP1
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableCompare(uint32_t Compare)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CMP[Compare]	|= ADC1_CMP_ADCCMPEN_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_DisableCompare
 **			关闭ADC1比较功能
 ** \param [in] Compare : ADC1_CMP0 、ADC1_CMP1
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableCompare(uint32_t Compare)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CMP[Compare]	&= ~(ADC1_CMP_ADCCMPEN_Msk);
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_ConfigCompare
 **			配置ADC1比较功能
 ** \param [in] Compare : ADC1_CMP0 、ADC1_CMP1
 **				 CmpMode:(1)ADC1_CMP_LESS_THAN_RESULT
 **						(2)ADC1_CMP_NOT_LESS_THAN_RESULT
 **				 CmpCount: 0x00~0xf  预设比较次数
 **				 CmpChannel: ADC1_CH_0 ~ ADC1_CH_30
 **				 CmpData : 12 bit 比较值
 ** \return  none
 ** \note	当内部计数器等于ADCCMPxMCNT+1的值时产生ADC比较事件。
*****************************************************************************/
void ADC1_ConfigCompare(uint32_t Compare, uint32_t CmpMode, uint32_t CmpCount,  
						uint32_t CmpChannel, uint32_t CmpData)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CMP[Compare]	&= ~(ADC1_CMP_ADCCMPCOND_Msk | ADC1_CMP_ADCCMPMCNT_Msk|
							 ADC1_CMP_ADCCMPCHS_Msk | ADC1_CMP_ADCCMPDATA_Msk);
	ADC1->CMP[Compare]	|= CmpMode | ((0xf & CmpCount)<<ADC1_CMP_ADCCMPMCNT_Pos) | ((0x1f& CmpChannel)<<ADC1_CMP_ADCCMPCHS_Pos)|
							(0xfff & CmpData) ;
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_GetCompareResult
 **			获取ADC1比较器结果
 ** \param [in] Compare : ADC1_CMP0 、ADC1_CMP1
 ** \return  1 /0
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetCompareResult(uint32_t Compare)
{
	return((ADC1->CMP[Compare] & ADC1_CMP_ADCCMPO_Msk)? 1:0);
}


/*****************************************************************************
 ** \brief	ADC1_Start
 **			开启ADC1
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_Start(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCEN_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_Stop
 **			关闭ADC1
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_Stop(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON &= ~(ADC1_CON_ADCEN_Msk);
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_StartAdjust
 **			开启ADC1校准
 ** \param [in] none
** \return  none
 ** \note	
*****************************************************************************/
void ADC1_StartAdjust(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON2 |= (ADC1_CON2_ADCCALEN_Msk);
	ADC1->LOCK = 0x00;	
	while(ADC1->CON2 & ADC1_CON2_ADCCALEN_Msk);
}

/*****************************************************************************
 ** \brief	ADC1_EnableAdjust
 **			开启ADC1带有校准数据的ADC转换
 ** \param [in] none
 ** \return   none
 ** \note	
*****************************************************************************/
void ADC1_EnableAdjust(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON2 &= ~(ADC1_CON2_ADCCALCONV_Msk);
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableAdjust
 **			关闭ADC1带有校准数据的ADC转换
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableAdjust(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON2 |= (ADC1_CON2_ADCCALCONV_Msk);
	ADC1->LOCK = 0x00;
}

/*****************************************************************************
 ** \brief	ADC1_EnableReset
 **			复位ADC1
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableReset(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCRST_Msk;
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_GetConvertErrorFlag
 **			获取ADC1 转换错误标志位
 ** \param [in] none
 ** \return  1 ：转换出现错误	0：无错误
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetConvertErrorFlag(void)
{
	return((ADC1->CON & ADC1_CON_ADCCONVER_Msk)? 1:0);	
}
/*****************************************************************************
 ** \brief	ADC1_GetAdjustErrorFlag
 **			获取ADC1 校准错误标志位
 ** \param [in] none
 ** \return  1 ：校准出现错误	0：无错误
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetAdjustErrorFlag(void)
{
	return((ADC1->CON & ADC1_CON_ADCCALERR_Msk)? 1:0);	
}

/*****************************************************************************
 ** \brief	ADC1_ClearConvertErrorFlag
 **			清除ADC1 转换错误标志位
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearConvertErrorFlag(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCCONVERRCLR_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_ClearAdjustErrorFlag
 **			清除ADC1 校准错误标志位
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearAdjustErrorFlag(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCCALERRCLR_Msk;
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_EnableCompareInt
 **			开启ADC1比较中断
 ** \param [in] none
 ** \return  none
 ** \note	只支持比较器 0 
*****************************************************************************/
void ADC1_EnableCompareInt(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC |= ADC1_IMSC_IMSC31_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_DisableCompareInt
 **			关闭ADC1比较中断
 ** \param [in] none
 ** \return  none
 ** \note	只支持比较器 0 
*****************************************************************************/
void ADC1_DisableCompareInt(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC &= ~(ADC1_IMSC_IMSC31_Msk);
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_GetCompareIntFlag
 **			获取ADC1比较中断使能并且产生中断标志位
 ** \param [in] none
 ** \return  1:中断使能并且产生中断 0：无中断
 ** \note	只支持比较器 0 
*****************************************************************************/
uint32_t ADC1_GetCompareIntFlag(void)
{
	return((ADC1->MIS & ADC1_MIS_MIS31_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	ADC1_ClearCompareIntFlag
 **			清除ADC1比较中断标志位
 ** \param [in] none
 ** \return  none
 ** \note	只支持比较器 0 
*****************************************************************************/
void ADC1_ClearCompareIntFlag(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->ICLR |= (ADC1_ICLR_ICLR31_Msk);
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_EnableChannelInt
 **			开启ADC1通道n中断
 ** \param [in]ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableChannelInt(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC |= ChannelMask ;
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableChannelInt
 **			关闭ADC1通道n中断
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableChannelInt(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC &= ~(ChannelMask);
	ADC1->LOCK = 0x00;
}
/*****************************************************************************
 ** \brief	ADC1_GetChannelIntFlag
 **			获取ADC1通道n中断使能并且产生中断标志位
 ** \param [in] Channel:ADC1_CH_0 ~ ADC1_CH_30
 ** \return  1:中断使能并且产生中断 0：无中断
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetChannelIntFlag(uint32_t Channel)
{
	return((ADC1->MIS & (0x1UL<<Channel))? 1:0);	
}
/*****************************************************************************
 ** \brief	ADC1_ClearChannelIntFlag
 **			清除ADC1通道n中断标志位
 ** \param [in] Channel:ADC1_CH_0 ~ ADC1_CH_30
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearChannelIntFlag(uint32_t Channel)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->ICLR |= (0x01UL<< Channel);
	ADC1->LOCK = 0x00;			
}
