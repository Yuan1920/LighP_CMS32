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
/** \file system.h
**
** History:
** 
*****************************************************************************/
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

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
 **System 芯片Flash大小
-----------------------------------------------------------------------------*/
#define		SYS_FLASH_SIZE_28K		(0x1CUL)		/*Flash 为 28K*/	
#define		SYS_FLASH_SIZE_32K		(0xFFUL)		/*Flash 为 32K*/
/*----------------------------------------------------------------------------
 **System  时钟源
-----------------------------------------------------------------------------*/
#define		SYS_CLK_HSI_64M			(0x00UL)			/*HSI(高速时钟)选择内振64Mhz*/
#define		SYS_CLK_HSI_48M			(0x3UL)				/*HSI(高速时钟)选择内振48Mhz*/
#define		SYS_CLK_SEL_HSI			(0x00UL)			/*AHP时钟选择高速时钟*/
#define		SYS_CLK_SEL_LSI			(0x2UL)				/*AHP时钟选择低速时钟*/
#define		SYS_CLKSEL_WRITE_KEY	(0x5A690000UL)		/*时钟选择写保护*/		
/*----------------------------------------------------------------------------
 **System  时钟常用分频
-----------------------------------------------------------------------------*/
#define 	SYS_CLK_DIV_1			(0x0UL)			/*时钟 1分频*/
#define 	SYS_CLK_DIV_2			(0x1UL)			/*时钟 2分频*/
#define 	SYS_CLK_DIV_4			(0x2UL)			/*时钟 4分频*/
#define 	SYS_CLK_DIV_6			(0x3UL)			/*时钟 6分频*/
#define 	SYS_CLK_DIV_8			(0x4UL)			/*时钟 8分频*/
#define 	SYS_CLK_DIV_10			(0x5UL)			/*时钟 10分频*/

#define 	AHB_CLK_DIV_1			(0x0UL)			/*时钟 1分频*/
#define 	AHB_CLK_DIV_2			(0x1UL)			/*时钟 2分频*/
#define 	AHB_CLK_DIV_4			(0x2UL)			/*时钟 4分频*/
#define 	AHB_CLK_DIV_6			(0x3UL)			/*时钟 6分频*/
#define 	AHB_CLK_DIV_8			(0x4UL)			/*时钟 8分频*/
#define 	AHB_CLK_DIV_10			(0x5UL)			/*时钟 10分频*/
#define 	AHB_CLK_DIV_12			(0x6UL)			/*时钟 12分频*/
#define 	AHB_CLK_DIV_14			(0x7UL)			/*时钟 14分频*/
#define 	AHB_CLK_DIV_16			(0x8UL)			/*时钟 16分频*/
#define 	AHB_CLK_DIV_18			(0x9UL)			/*时钟 18分频*/
#define 	AHB_CLK_DIV_20			(0xAUL)			/*时钟 20分频*/


/*----------------------------------------------------------------------------
 **System  外设时钟
-----------------------------------------------------------------------------*/
#define 	SYS_CLK_ADC1_MSK		(SYS_AHBCKEN_ADC1CE_Msk)	/*ADC1时钟使能位*/
#define 	SYS_CLK_ACMP_MSK		(SYS_AHBCKEN_ACMPCE_Msk)	/*模拟比较器时钟使能位*/
#define 	SYS_CLK_OPA_PGA_MSK		(SYS_AHBCKEN_OPACE_Msk)		/*运放/GPA时钟使能位*/
#define 	SYS_CLK_EPWM_MSK		(SYS_AHBCKEN_EPWMCE_Msk)	/*EPWM时钟使能位*/
#define 	SYS_CLK_CRC_MSK			(SYS_AHBCKEN_CRCCE_Msk)		/*CRC时钟使能位*/
#define 	SYS_CLK_WWDT_MSK		(SYS_AHBCKEN_WWDTCE_Msk)	/*WWDT时钟使能位*/
#define 	SYS_CLK_CCP_MSK			(SYS_AHBCKEN_CCPCE_Msk)		/*捕获/PWM时钟使能位*/
#define 	SYS_CLK_ADC0_MSK		(SYS_AHBCKEN_ADC0CE_Msk)	/*ADC0时钟使能位*/
#define 	SYS_CLK_SSP_MSK			(SYS_AHBCKEN_SPPCE_Msk)		/*SSP时钟使能位*/
#define 	SYS_CLK_I2C_MSK			(SYS_AHBCKEN_I2CCE_Msk)		/*I2C时钟使能位*/
#define 	SYS_CLK_UART1_MSK		(SYS_AHBCKEN_UART1CE_Msk)	/*UART1时钟使能位*/
#define 	SYS_CLK_UART0_MSK		(SYS_AHBCKEN_UART0CE_Msk)	/*UART0时钟使能位*/
#define 	SYS_CLK_HWDIVCE_MSK		(SYS_AHBCKEN_HWDIVCE_Msk)	/*硬件除法器时钟使能位*/
#define 	SYS_CLK_TIMER01_MSK		(SYS_AHBCKEN_TIMER01CE_Msk)	/*定时器时钟使能位*/
#define 	SYS_CLK_WDT_MSK			(SYS_AHBCKEN_WDTCE_Msk)		/*WDT时钟使能位*/

/*----------------------------------------------------------------------------
 **System  时钟输出选择
-----------------------------------------------------------------------------*/
#define		SYS_CLK_OUT_SEL_AHB		(0x0UL<<SYS_CLKODIV_CLKSEL_Pos)	/*时钟输出选择AHP时钟*/
#define		SYS_CLK_OUT_SEL_HSI		(0x1UL<<SYS_CLKODIV_CLKSEL_Pos)	/*时钟输出选择HSI时钟*/

/*----------------------------------------------------------------------------
 **System  电源控制
-----------------------------------------------------------------------------*/
#define		SYS_STOP_MODE			(0x1UL<<SYS_PCON_STOP_Pos)		/*系统进入停止模式*/
#define		SYS_SLEEP_MODE			(0x1UL<<SYS_PCON_SLEEP_Pos)		/*系统进入睡眠模式*/	
#define		SYS_DEEP_SLEEP_MODE		(0x1UL<<SYS_PCON_DEEPSLEEP_Pos)	/*系统进入深度睡眠模式*/	
#define		SYS_PCON_WRITE_KEY		(0x5A690000UL)					/*寄存器写保护*/
/*----------------------------------------------------------------------------
 **System  系统复位
-----------------------------------------------------------------------------*/
#define		SYS_RESET_CPU_MODE		(0x55AA669AUL)		/*产生CPU复位,不加载启动配置*/
#define		SYS_RESET_MCU_MODE		(0x55AA6699UL)		/*产生MCU复位,重新加载启动配置*/
#define 	SYS_RESET_IO_CLOSE		(0x3UL<<SYS_IOMUX_RESETPORT_Pos)	/*外部复位禁止*/
#define 	SYS_RESET_IO_P10		(0x2UL<<SYS_IOMUX_RESETPORT_Pos)	/*P10作外部复位引脚*/
#define 	SYS_RESET_IO_P44		(0x1UL<<SYS_IOMUX_RESETPORT_Pos)	/*P44作外部复位引脚*/
#define 	SYS_RESET_IO_P43		(0x0UL<<SYS_IOMUX_RESETPORT_Pos)	/*P43作外部复位引脚*/

/*----------------------------------------------------------------------------
 **System  LVD系统监测
-----------------------------------------------------------------------------*/
#define		SYS_LVD_2V				(0x00UL)			/*LVD监测电压选择2V*/
#define		SYS_LVD_2P2V			(0x01UL)			/*LVD监测电压选择2.2V*/
#define		SYS_LVD_2P4V			(0x02UL)			/*LVD监测电压选择2.4V*/
#define		SYS_LVD_2P7V			(0x03UL)			/*LVD监测电压选择2.7V*/
#define		SYS_LVD_3V				(0x04UL)			/*LVD监测电压选择3V*/
#define		SYS_LVD_3P7V			(0x05UL)			/*LVD监测电压选择3.0V*/
#define		SYS_LVD_4V				(0x06UL)			/*LVD监测电压选择4V*/
#define		SYS_LVD_4P3V			(0x07UL)			/*LVD监测电压选择4.3V*/

/*----------------------------------------------------------------------------
 **System  SRAM写保护
-----------------------------------------------------------------------------*/
#define 	SYS_SRAM_PORTECT_2K_4K_MSK	(0x2UL)			/*SRAM对2K~4K地址范围写保护*/	
#define 	SYS_SRAM_PORTECT_4K_6K_MSK	(0x4UL)			/*SRAM对4K~6K地址范围写保护*/	
#define 	SYS_SRAM_PORTECT_6K_8K_MSK	(0x8UL)			/*SRAM对6K~8K地址范围写保护*/	
#define		SYS_SRAMLOCK_WRITE_KEY		(0x55AA0000UL)	/*寄存器SRAMLOCK写保护位*/

/*----------------------------------------------------------------------------
 **System  IO写保护
-----------------------------------------------------------------------------*/
#define 	SYS_GPIOLOCK_WRETE_KEY		(0x99UL)		/*IO操作保护*/
/*----------------------------------------------------------------------------
 **System  IO配置
-----------------------------------------------------------------------------*/
/*----------GPIO_P0_0--------------------------------------------------------*/
#define 	SYS_IOCFG_P00_GPIO		(0x00UL)
#define		SYS_IOCFG_P00_AN0		(0x01UL)
#define 	SYS_IOCFG_P00_TXD0		(0x02UL)
#define		SYS_IOCFG_P00_CTS0		(0x03UL)
#define 	SYS_IOCFG_P00_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P00_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P00_EPWM2		(0x06UL)
#define		SYS_IOCFG_P00_SWDCLK2	(0x07UL)
#define		SYS_IOCFG_P00_TXD1		(0x08UL)
#define		SYS_IOCFG_P00_RXD1		(0x09UL)
/*----------GPIO_P0_1--------------------------------------------------------*/
#define 	SYS_IOCFG_P01_GPIO		(0x00UL)
#define		SYS_IOCFG_P01_AN1		(0x01UL)
#define 	SYS_IOCFG_P01_TXD0		(0x02UL)
#define		SYS_IOCFG_P01_RTS0		(0x03UL)
#define 	SYS_IOCFG_P01_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P01_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P01_EPWM0		(0x06UL)
#define		SYS_IOCFG_P01_ADET		(0x07UL)
#define		SYS_IOCFG_P01_TXD1		(0x08UL)
#define		SYS_IOCFG_P01_RXD1		(0x09UL)
/*----------GPIO_P0_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P04_GPIO		(0x00UL)
#define		SYS_IOCFG_P04_AN2		(0x01UL)
#define		SYS_IOCFG_P04_CTS1		(0x03UL)
#define 	SYS_IOCFG_P04_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P04_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P04_EPWM1		(0x06UL)
#define		SYS_IOCFG_P04_SPI0CLK	(0x07UL)
#define		SYS_IOCFG_P04_TXD1		(0x08UL)
#define		SYS_IOCFG_P04_RXD1		(0x09UL)
/*----------GPIO_P0_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P05_GPIO		(0x00UL)
#define		SYS_IOCFG_P05_AN3		(0x01UL)
#define		SYS_IOCFG_P05_RTS1		(0x03UL)
#define 	SYS_IOCFG_P05_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P05_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P05_EPWM2		(0x06UL)
#define		SYS_IOCFG_P05_ADET		(0x07UL)
#define		SYS_IOCFG_P05_TXD1		(0x08UL)
#define		SYS_IOCFG_P05_RXD1		(0x09UL)
/*----------GPIO_P0_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P06_GPIO		(0x00UL)
#define		SYS_IOCFG_P06_AN4		(0x01UL)
#define		SYS_IOCFG_P06_SDA0		(0x03UL)
#define 	SYS_IOCFG_P06_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P06_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P06_EPWM3		(0x06UL)
#define		SYS_IOCFG_P06_CTS1		(0x07UL)
#define		SYS_IOCFG_P06_TXD1		(0x08UL)
#define		SYS_IOCFG_P06_RXD1		(0x09UL)
/*----------GPIO_P0_7-------------------------------------------------------*/
#define 	SYS_IOCFG_P07_GPIO		(0x00UL)
#define		SYS_IOCFG_P07_AN5		(0x01UL)
#define		SYS_IOCFG_P07_SCL0		(0x03UL)
#define 	SYS_IOCFG_P07_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P07_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P07_EPWM4		(0x06UL)
#define		SYS_IOCFG_P07_TXD1		(0x08UL)
#define		SYS_IOCFG_P07_RXD1		(0x09UL)
/*----------GPIO_P1_0-------------------------------------------------------*/
#define 	SYS_IOCFG_P10_GPIO		(0x00UL)
#define 	SYS_IOCFG_P10_ECAP05	(0x00UL)
#define		SYS_IOCFG_P10_AN6		(0x01UL)
#define		SYS_IOCFG_P10_C0P5		(0x01UL)
#define		SYS_IOCFG_P10_TXD0		(0x02UL)
#define		SYS_IOCFG_P10_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P10_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P10_CTS1		(0x07UL)
#define		SYS_IOCFG_P10_TXD1		(0x08UL)
#define		SYS_IOCFG_P10_RXD1		(0x09UL)
/*----------GPIO_P1_2-------------------------------------------------------*/
#define 	SYS_IOCFG_P12_GPIO		(0x00UL)
#define		SYS_IOCFG_P12_AN7		(0x01UL)
#define		SYS_IOCFG_P12_A1P0		(0x01UL)
#define		SYS_IOCFG_P12_RXD0		(0x02UL)
#define		SYS_IOCFG_P12_SDA0		(0x03UL)
#define		SYS_IOCFG_P12_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P12_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P12_EPWM0		(0x06UL)
#define 	SYS_IOCFG_P12_RTS1		(0x07UL)
#define		SYS_IOCFG_P12_TXD1		(0x08UL)
#define		SYS_IOCFG_P12_RXD1		(0x09UL)
/*----------GPIO_P1_3-------------------------------------------------------*/
#define 	SYS_IOCFG_P13_GPIO		(0x00UL)
#define 	SYS_IOCFG_P13_ECAP00	(0x00UL)
#define		SYS_IOCFG_P13_AN8		(0x01UL)
#define		SYS_IOCFG_P13_C0P0		(0x01UL)
#define		SYS_IOCFG_P13_TXD0		(0x02UL)
#define		SYS_IOCFG_P13_SCL0		(0x03UL)
#define		SYS_IOCFG_P13_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P13_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P13_EPWM1		(0x06UL)
#define		SYS_IOCFG_P13_TXD1		(0x08UL)
#define		SYS_IOCFG_P13_RXD1		(0x09UL)
/*----------GPIO_P1_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P14_GPIO		(0x00UL)
#define 	SYS_IOCFG_P14_ECAP01	(0x00UL)
#define		SYS_IOCFG_P14_AN9		(0x01UL)
#define		SYS_IOCFG_P14_C0P1		(0x01UL)
#define		SYS_IOCFG_P14_SDA0		(0x03UL)
#define		SYS_IOCFG_P14_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P14_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P14_EPWM4		(0x06UL)
#define		SYS_IOCFG_P14_TXD1		(0x08UL)
#define		SYS_IOCFG_P14_RXD1		(0x09UL)
/*----------GPIO_P1_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P15_GPIO		(0x00UL)
#define 	SYS_IOCFG_P15_ECAP02	(0x00UL)
#define		SYS_IOCFG_P15_AN10		(0x01UL)
#define		SYS_IOCFG_P15_C0P2		(0x01UL)
#define		SYS_IOCFG_P15_A1P1		(0x01UL)
#define		SYS_IOCFG_P15_SCL0		(0x03UL)
#define		SYS_IOCFG_P15_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P15_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P15_EPWM5		(0x06UL)
#define		SYS_IOCFG_P15_TXD1		(0x08UL)
#define		SYS_IOCFG_P15_RXD1		(0x09UL)
/*----------GPIO_P1_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P16_GPIO		(0x00UL)
#define 	SYS_IOCFG_P16_ECAP04	(0x00UL)
#define		SYS_IOCFG_P16_AN11		(0x07UL)
#define		SYS_IOCFG_P16_C0P4		(0x07UL)
#define		SYS_IOCFG_P16_OP1O		(0x07UL)
#define		SYS_IOCFG_P16_RXD0		(0x02UL)
#define		SYS_IOCFG_P16_SCL0		(0x03UL)
#define		SYS_IOCFG_P16_CTS0		(0x04UL)
#define		SYS_IOCFG_P16_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P16_EPWM2		(0x06UL)
#define		SYS_IOCFG_P16_TXD1		(0x08UL)
#define		SYS_IOCFG_P16_RXD1		(0x09UL)
/*----------GPIO_P1_7-------------------------------------------------------*/
#define 	SYS_IOCFG_P17_GPIO		(0x00UL)
#define		SYS_IOCFG_P17_AN12		(0x01UL)
#define		SYS_IOCFG_P17_OP1N		(0x01UL)
#define		SYS_IOCFG_P17_TXD0		(0x02UL)
#define		SYS_IOCFG_P17_SDA0		(0x03UL)
#define		SYS_IOCFG_P17_RTS0		(0x04UL)
#define		SYS_IOCFG_P17_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P17_EPWM4		(0x06UL)
#define		SYS_IOCFG_P17_TXD1		(0x08UL)
#define		SYS_IOCFG_P17_RXD1		(0x09UL)
/*----------GPIO_P2_1-------------------------------------------------------*/
#define 	SYS_IOCFG_P21_GPIO		(0x00UL)
#define		SYS_IOCFG_P21_AN13		(0x01UL)
#define		SYS_IOCFG_P21_OP1P		(0x01UL)
#define		SYS_IOCFG_P21_RXD0		(0x02UL)
#define		SYS_IOCFG_P21_SCL0		(0x03UL)
#define		SYS_IOCFG_P21_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P21_EPWM5		(0x06UL)
#define 	SYS_IOCFG_P21_BKIN		(0x07UL)
#define		SYS_IOCFG_P21_TXD1		(0x08UL)
#define		SYS_IOCFG_P21_RXD1		(0x09UL)
/*----------GPIO_P2_2-------------------------------------------------------*/
#define 	SYS_IOCFG_P22_GPIO		(0x00UL)
#define 	SYS_IOCFG_P22_ECAP14	(0x00UL)
#define		SYS_IOCFG_P22_AN14		(0x01UL)
#define		SYS_IOCFG_P22_C1P4		(0x01UL)
#define		SYS_IOCFG_P22_TXD0		(0x02UL)
#define		SYS_IOCFG_P22_SCL0		(0x03UL)
#define		SYS_IOCFG_P22_CTS1		(0x04UL)
#define		SYS_IOCFG_P22_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P22_EPWM0		(0x06UL)
#define 	SYS_IOCFG_P22_SDA0		(0x07UL)
#define		SYS_IOCFG_P22_TXD1		(0x08UL)
#define		SYS_IOCFG_P22_RXD1		(0x09UL)
/*----------GPIO_P2_3-------------------------------------------------------*/
#define 	SYS_IOCFG_P23_GPIO		(0x00UL)
#define 	SYS_IOCFG_P23_ECAP15	(0x00UL)
#define		SYS_IOCFG_P23_AN15		(0x01UL)
#define		SYS_IOCFG_P23_C1P5		(0x01UL)
#define		SYS_IOCFG_P23_OP0O		(0x01UL)
#define		SYS_IOCFG_P23_SDA0		(0x03UL)
#define		SYS_IOCFG_P23_RTS1		(0x04UL)
#define		SYS_IOCFG_P23_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P23_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P23_SWDDAT1	(0x07UL)
#define		SYS_IOCFG_P23_TXD1		(0x08UL)
#define		SYS_IOCFG_P23_RXD1		(0x09UL)
/*----------GPIO_P2_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P24_GPIO		(0x00UL)
#define		SYS_IOCFG_P24_AN16		(0x01UL)
#define		SYS_IOCFG_P24_OP0N		(0x01UL)
#define		SYS_IOCFG_P24_SDA0		(0x03UL)
#define		SYS_IOCFG_P24_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P24_EPWM2		(0x06UL)
#define 	SYS_IOCFG_P24_SWDCLK13	(0x07UL)
#define		SYS_IOCFG_P24_TXD1		(0x08UL)
#define		SYS_IOCFG_P24_RXD1		(0x09UL)
/*----------GPIO_P2_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P25_GPIO		(0x00UL)
#define		SYS_IOCFG_P25_AN17		(0x01UL)
#define		SYS_IOCFG_P25_OP0P		(0x01UL)
#define		SYS_IOCFG_P25_SCL0		(0x03UL)
#define		SYS_IOCFG_P25_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P25_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P25_EPWM3		(0x06UL)
#define 	SYS_IOCFG_P25_C1O		(0x07UL)
#define		SYS_IOCFG_P25_TXD1		(0x08UL)
#define		SYS_IOCFG_P25_RXD1		(0x09UL)
/*----------GPIO_P2_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P26_GPIO		(0x00UL)
#define		SYS_IOCFG_P26_AN18		(0x01UL)
#define		SYS_IOCFG_P26_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P26_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P26_EPWM4		(0x06UL)
#define 	SYS_IOCFG_P26_C0O		(0x07UL)
#define		SYS_IOCFG_P26_TXD1		(0x08UL)
#define		SYS_IOCFG_P26_RXD1		(0x09UL)
/*----------GPIO_P3_0-------------------------------------------------------*/
#define 	SYS_IOCFG_P30_GPIO		(0x00UL)
#define 	SYS_IOCFG_P30_ECAP13	(0x00UL)
#define		SYS_IOCFG_P30_AN19		(0x01UL)
#define		SYS_IOCFG_P30_C1P3		(0x01UL)
#define		SYS_IOCFG_P30_A1P2		(0x01UL)
#define		SYS_IOCFG_P30_RXD0		(0x02UL)
#define		SYS_IOCFG_P30_CCP0A		(0x03UL)
#define		SYS_IOCFG_P30_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P30_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P30_EPWM0		(0x06UL)
#define 	SYS_IOCFG_P30_ADET		(0x07UL)
#define		SYS_IOCFG_P30_TXD1		(0x08UL)
#define		SYS_IOCFG_P30_RXD1		(0x09UL)
/*----------GPIO_P3_1-------------------------------------------------------*/
#define 	SYS_IOCFG_P31_GPIO		(0x00UL)
#define 	SYS_IOCFG_P31_ECAP10	(0x00UL)
#define		SYS_IOCFG_P31_AN20		(0x01UL)
#define		SYS_IOCFG_P31_C1P0		(0x01UL)
#define		SYS_IOCFG_P31_A0P2		(0x01UL)
#define		SYS_IOCFG_P31_CTS0		(0x02UL)
#define		SYS_IOCFG_P31_SCL0		(0x03UL)
#define		SYS_IOCFG_P31_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P31_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P31_EPWM4		(0x06UL)
#define 	SYS_IOCFG_P31_BKIN		(0x07UL)
#define		SYS_IOCFG_P31_TXD1		(0x08UL)
#define		SYS_IOCFG_P31_RXD1		(0x09UL)
/*----------GPIO_P3_2-------------------------------------------------------*/
#define 	SYS_IOCFG_P32_GPIO		(0x00UL)
#define 	SYS_IOCFG_P32_ECAP11	(0x00UL)
#define		SYS_IOCFG_P32_AN21		(0x01UL)
#define		SYS_IOCFG_P32_C1P1		(0x01UL)
#define		SYS_IOCFG_P32_A0P1		(0x01UL)
#define		SYS_IOCFG_P32_RXD0		(0x02UL)
#define		SYS_IOCFG_P32_SDA0		(0x03UL)
#define		SYS_IOCFG_P32_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P32_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P32_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P32_BKIN		(0x07UL)
#define		SYS_IOCFG_P32_TXD1		(0x08UL)
#define		SYS_IOCFG_P32_RXD1		(0x09UL)
/*----------GPIO_P3_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P34_GPIO		(0x00UL)
#define 	SYS_IOCFG_P34_ECAP12	(0x00UL)
#define		SYS_IOCFG_P34_AN22		(0x01UL)
#define		SYS_IOCFG_P34_C1P2		(0x01UL)
#define		SYS_IOCFG_P34_A0O		(0x01UL)
#define		SYS_IOCFG_P34_TXD0		(0x02UL)
#define		SYS_IOCFG_P34_SDA0		(0x03UL)
#define		SYS_IOCFG_P34_SPI0CLK	(0x04UL)
#define		SYS_IOCFG_P34_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P34_EPWM3		(0x06UL)
#define 	SYS_IOCFG_P34_BKIN		(0x07UL)
#define		SYS_IOCFG_P34_TXD1		(0x08UL)
#define		SYS_IOCFG_P34_RXD1		(0x09UL)
/*----------GPIO_P3_5-------------------------------------------------------*/
#define 	SYS_IOCFG_P35_GPIO		(0x00UL)
#define 	SYS_IOCFG_P35_ECAP13	(0x00UL)
#define		SYS_IOCFG_P35_AN23		(0x01UL)
#define		SYS_IOCFG_P35_C1N		(0x01UL)
#define		SYS_IOCFG_P35_A1O		(0x01UL)
#define		SYS_IOCFG_P35_RTS0		(0x02UL)
#define		SYS_IOCFG_P35_SCL0		(0x03UL)
#define		SYS_IOCFG_P35_SPI0SS	(0x04UL)
#define		SYS_IOCFG_P35_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P35_EPWM5 	(0x06UL)
#define 	SYS_IOCFG_P35_CLKO		(0x07UL)
#define		SYS_IOCFG_P35_TXD1		(0x08UL)
#define		SYS_IOCFG_P35_RXD1		(0x09UL)
/*----------GPIO_P3_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P36_GPIO		(0x00UL)
#define 	SYS_IOCFG_P36_ECAP03	(0x00UL)
#define		SYS_IOCFG_P36_AN24		(0x01UL)
#define		SYS_IOCFG_P36_C0P3		(0x01UL)
#define		SYS_IOCFG_P36_A0P0		(0x01UL)
#define		SYS_IOCFG_P36_CLKO		(0x04UL)
#define		SYS_IOCFG_P36_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P36_EPWM0 	(0x06UL)
#define 	SYS_IOCFG_P36_SWDDAT3	(0x07UL)
#define		SYS_IOCFG_P36_TXD1		(0x08UL)
#define		SYS_IOCFG_P36_RXD1		(0x09UL)
/*----------GPIO_P4_0-------------------------------------------------------*/
#define 	SYS_IOCFG_P40_GPIO		(0x00UL)
#define		SYS_IOCFG_P40_AN25		(0x01UL)
#define		SYS_IOCFG_P40_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P40_EPWM1		(0x06UL)
#define 	SYS_IOCFG_P40_SWDDAT2	(0x07UL)
#define		SYS_IOCFG_P40_TXD1		(0x08UL)
#define		SYS_IOCFG_P40_RXD1		(0x09UL)
/*----------GPIO_P4_3-------------------------------------------------------*/
#define 	SYS_IOCFG_P43_GPIO		(0x00UL)
#define		SYS_IOCFG_P43_AN26		(0x01UL)
#define		SYS_IOCFG_P43_C0N		(0x01UL)
#define		SYS_IOCFG_P43_A0P3		(0x01UL)
#define		SYS_IOCFG_P43_CCP0A		(0x05UL)
#define 	SYS_IOCFG_P43_EPWM2		(0x06UL)
#define		SYS_IOCFG_P43_TXD1		(0x08UL)
#define		SYS_IOCFG_P43_RXD1		(0x09UL)
/*----------GPIO_P4_4-------------------------------------------------------*/
#define 	SYS_IOCFG_P44_GPIO		(0x00UL)
#define		SYS_IOCFG_P44_AN27		(0x01UL)
#define		SYS_IOCFG_P44_A1P3		(0x01UL)
#define		SYS_IOCFG_P44_TXD0		(0x02UL)
#define		SYS_IOCFG_P44_CCP0B		(0x05UL)
#define 	SYS_IOCFG_P44_EPWM1		(0x06UL)
#define		SYS_IOCFG_P44_TXD1		(0x08UL)
#define		SYS_IOCFG_P44_RXD1		(0x09UL)
/*----------GPIO_P4_6-------------------------------------------------------*/
#define 	SYS_IOCFG_P46_GPIO		(0x00UL)
#define		SYS_IOCFG_P46_AN28		(0x01UL)
#define		SYS_IOCFG_P46_BKIN		(0x02UL)
#define		SYS_IOCFG_P46_SPI0MISO	(0x04UL)
#define		SYS_IOCFG_P46_CCP1A		(0x05UL)
#define 	SYS_IOCFG_P46_EPWM2		(0x06UL)
#define 	SYS_IOCFG_P46_SWDCLK0	(0x07UL)
#define		SYS_IOCFG_P46_TXD1		(0x08UL)
#define		SYS_IOCFG_P46_RXD1		(0x09UL)
/*----------GPIO_P4_7-------------------------------------------------------*/
#define 	SYS_IOCFG_P47_GPIO		(0x00UL)
#define		SYS_IOCFG_P47_AN29		(0x01UL)
#define		SYS_IOCFG_P47_RTS1		(0x03UL)
#define		SYS_IOCFG_P47_SPI0MOSI	(0x04UL)
#define		SYS_IOCFG_P47_CCP1B		(0x05UL)
#define 	SYS_IOCFG_P47_EPWM5		(0x06UL)
#define 	SYS_IOCFG_P47_SWDDAT0	(0x07UL)
#define		SYS_IOCFG_P47_TXD1		(0x08UL)
#define		SYS_IOCFG_P47_RXD1		(0x09UL)

/*****************************************************************************
 ** \brief	SYS_SET_IOCFG
 **			设置 IOCFG值(设置IO口的复用功能)
 ** \param [in] PinCFG:	P00CFG ~ P47CFG寄存器
 **				MuxMode:
 ** \return none
 ** \note	 
*****************************************************************************/	
#define SYS_SET_IOCFG(PinCFG, MuxMode)	do{\
											SYS->PinCFG = MuxMode;\
											}while(0)
/*****************************************************************************
 ** \brief	SYS_FLASH_SIZE
 **			返回芯片Flash大小
 ** \param [in] none
 ** \return  0x1C: 	 SYS_FLASH_SIZE_28K  	 Flash 为28K
 **			 其他:   SYS_FLASH_SIZE_32K 	 Flash 为32K	
 ** \note	 
*****************************************************************************/	
#define 	SYS_FLASH_SIZE()		((SYS->DID & (SYS_DID_DSF_Msk)))

/*****************************************************************************
 ** \brief	SYS_RESET_IO_STATE
 **			返回复位引脚的状态
 ** \param [in] none
 ** \return  0: 	 SYS_RESET_IO_P43  		 P43作外部复位引脚
 **			 0x200:  SYS_RESET_IO_P44 		 P44作外部复位引脚
 **			 0x400:	 SYS_RESET_IO_P10		 P10作外部复位引脚
 **			 0x600:	 SYS_RESET_IO_CLOSE      外部复位禁止
 ** \note	 
*****************************************************************************/	
#define 	SYS_GET_RESET_IO_STATE()		((SYS->IOMUX & (SYS_IOMUX_RESETPORT_Msk)))

/*****************************************************************************
 ** \brief	SYS_SET_LVD_LEVERL
 **			设置LVD电压
 ** \param [in] LVDLevel：(1)SYS_LVD_2V		LVD监测电压选择2V
 **						  (2)SYS_LVD_2P2V	LVD监测电压选择2.2V
 **						  (3)SYS_LVD_2P4V	LVD监测电压选择2.4V
 **						  (4)SYS_LVD_2P7V	LVD监测电压选择2.7
 **						  (5)SYS_LVD_3V		LVD监测电压选择3V
 **						  (6)SYS_LVD_3P7V	LVD监测电压选择3.0
 **						  (7)SYS_LVD_4V		LVD监测电压选择4V
 **						  (8)SYS_LVD_4P3V	LVD监测电压选择4.3
 ** \return  none
 ** \note	 
*****************************************************************************/
#define		SYS_SET_LVD_LEVERL(LVDLevel)	do{\
												SYS->LVDCON  = LVDLevel;\
											  }while(1)
/*****************************************************************************
 ** \brief	SYS_IS_LVD_LESS_VDD
 **			LVD电压大于VDD电压
 ** \param [in] none
 ** \return  0：LVD电压小于LVD电压  1:LVD电压大于VDD电压
 ** \note	 
*****************************************************************************/	
#define		SYS_IS_LVD_GREATER_VDD()		((SYS->RIS & SYS_RIS_LVDRIS_Msk)? 1:0)

/*****************************************************************************
 ** \brief	SYS_ENABLE_APBCLK
 **			开启外设时钟
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1时钟使能位
 **						  (2)SYS_CLK_ACMP_MSK:		模拟比较器时钟使能位				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	运放/PGA时钟使能位	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWM时钟使能位	
 **						  (5)SYS_CLK_CRC_MSK:		CRC时钟使能位	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDT时钟使能位	
 **						  (7)SYS_CLK_CCP_MSK:		捕获/PWM时钟使能位	
 **						  (8)SYS_CLK_ADC0_MSK:		ADC0时钟使能位	
 **						  (9)SYS_CLK_SSP_MSK:		SSP时钟使能位	
 **						  (10)SYS_CLK_I2C_MSK:		I2C时钟使能位	
 **						  (11)SYS_CLK_UART1_MSK:	UART1时钟使能位	
 **						  (12)SYS_CLK_UART0_MSK:	UART0时钟使能位	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	硬件除法器时钟使能位	
 **						  (14)SYS_CLK_TIMER01_MSK:	定时器时钟使能位	
 **						  (15)SYS_CLK_WDT_MSK:		WDT时钟使能位	
 ** \return  none
 ** \note	 
*****************************************************************************/	
#define		SYS_ENABLE_APBCLK(ModuleMask)	do{\
												SYS->APBCKEN |= ModuleMask;\
												}while(0)
/*****************************************************************************
 ** \brief	SYS_DISABLE_APBCLK
 **			关闭外设时钟
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1时钟使能位
 **						  (2)SYS_CLK_ACMP_MSK:		模拟比较器时钟使能位				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	运放/PGA时钟使能位	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWM时钟使能位	
 **						  (5)SYS_CLK_CRC_MSK:		CRC时钟使能位	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDT时钟使能位	
 **						  (7)SYS_CLK_CCP_MSK:		捕获/PWM时钟使能位	
 **						  (8)SYS_CLK_ADC0_MSK:		ADC0时钟使能位	
 **						  (9)SYS_CLK_SSP_MSK:		SSP时钟使能位	
 **						  (10)SYS_CLK_I2C_MSK:		I2C时钟使能位	
 **						  (11)SYS_CLK_UART1_MSK:	UART1时钟使能位	
 **						  (12)SYS_CLK_UART0_MSK:	UART0时钟使能位	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	硬件除法器时钟使能位	
 **						  (14)SYS_CLK_TIMER01_MSK:	定时器时钟使能位	
 **						  (15)SYS_CLK_WDT_MSK:		WDT时钟使能位	
 ** \return  none
 ** \note	 
*****************************************************************************/	
#define		SYS_DISABLE_APBCLK(ModuleMask)	do{\
												SYS->APBCKEN &= ~(ModuleMask);\
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
 ** \brief	SYS_EnterStop
 **			系统进入停止模式
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE  void SYS_EnterStop(void)
{
	SYS->PCON = SYS_PCON_WRITE_KEY | SYS_STOP_MODE;
	__ASM("WFI");	
}
/*****************************************************************************
 ** \brief	SYS_EnterSleep
 **			系统进入睡眠模式
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE  void SYS_EnterSleep(void)
{
	SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
	SYS->PCON = SYS_PCON_WRITE_KEY | SYS_SLEEP_MODE;
	__ASM("WFI");
}
/*****************************************************************************
 ** \brief	SYS_EnterDeepSleep
 **			系统进入深度睡眠模式
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE  void SYS_EnterDeepSleep(void)
{
	SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);
	SYS->PCON = SYS_PCON_WRITE_KEY | SYS_DEEP_SLEEP_MODE;
	__ASM("WFI");
}

/*****************************************************************************
 ** \brief	SYS_ResetMCU
 **			复位MCU
 ** \param [in] none
 ** \return  none
 ** \note   产生MCU复位,重新加载启动配置 
*****************************************************************************/
__STATIC_INLINE  void SYS_ResetMCU(void)
{
	SYS->RSTCON = SYS_RESET_MCU_MODE;
}
/*****************************************************************************
 ** \brief	SYS_ResetCPU
 **			复位CPU
 ** \param [in] none
 ** \return  none
 ** \note	产生CPU复位,不加载启动配置
*****************************************************************************/
__STATIC_INLINE  void SYS_ResetCPU(void)
{
	SYS->RSTCON = SYS_RESET_CPU_MODE;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO0Protect
 **			使能GPIO0保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO0Protect(void)
{
	SYS->GPIO0LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO0Protect
 **			关闭GPIO0保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO0Protect(void)
{
	SYS->GPIO0LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO1Protect
 **			使能GPIO1保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO1Protect(void)
{
	SYS->GPIO1LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO1Protect
 **			关闭GPIO1保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO1Protect(void)
{
	SYS->GPIO1LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO2Protect
 **			使能GPIO2保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO2Protect(void)
{
	SYS->GPIO2LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO2Protect
 **			关闭GPIO2保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO2Protect(void)
{
	SYS->GPIO2LOCK = SYS_GPIOLOCK_WRETE_KEY;
}

/*****************************************************************************
 ** \brief	SYS_EnableGPIO3Protect
 **			使能GPIO3保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO3Protect(void)
{
	SYS->GPIO3LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO3Protect
 **			关闭GPIO3保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO3Protect(void)
{
	SYS->GPIO3LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableGPIO4Protect
 **			使能GPIO4保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableGPIO4Protect(void)
{
	SYS->GPIO4LOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableGPIO4Protect
 **			关闭GPIO4保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableGPIO4Protect(void)
{
	SYS->GPIO4LOCK = SYS_GPIOLOCK_WRETE_KEY;
}
/*****************************************************************************
 ** \brief	SYS_EnableIOCFGProtect
 **			使能GPIO Config 保护
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_EnableIOCFGProtect(void)
{
	SYS->IOCFGLOCK = 0xff;
}
/*****************************************************************************
 ** \brief	SYS_DisableIOCFGProtect
 **			关闭GPIO Config 保护 
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/	
__STATIC_INLINE  void SYS_DisableIOCFGProtect(void)
{
	SYS->IOCFGLOCK = SYS_GPIOLOCK_WRETE_KEY;
}

/*****************************************************************************
 ** \brief	SYS_GetCPUResetFlag
 **			获取CPU复位标志
 ** \param [in] none			
 ** \return  0:未复位  1；复位
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetCPUResetFlag( void);
/*****************************************************************************
 ** \brief	SYS_GetMCUResetFlag
 **			获取MCU复位标志
 ** \param [in] none			
 ** \return  0:未复位  1；复位
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetMCUResetFlag( void);
/*****************************************************************************
 ** \brief	SYS_GetWDTResetFlag
 **			获取WDT复位系统标志
 ** \param [in] none			
 ** \return  0:WDT未复位系统  1；WDT复位系统
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetWDTResetFlag( void);

/*****************************************************************************
 ** \brief	WWDT_GetWWDTResetFlag
 **			获取WWDT复位系统标志
 ** \param [in] none			
 ** \return  0:WWDT未复位系统  1；WWDT复位系统
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetWWDTResetFlag( void);

/*****************************************************************************
 ** \brief	SYS_EnableClkOutput
 **			使能系统时钟输出
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_EnableClkOutput(void);
/*****************************************************************************
 ** \brief	SYS_DisableClkOutput
 **			关闭系统时钟输出
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_DisableClkOutput(void);
/*****************************************************************************
 ** \brief	SYS_ConfigClkOutput
 **			配置系统时钟输出
 ** \param [in] ClkSel : (1)SYS_CLK_OUT_SEL_AHB		
 **						 (2)SYS_CLK_OUT_SEL_HSI
 **				ClkDiv : 0~255   时钟输出分频
 ** \return  none
 ** \note	0: FCLKO=FSEL ；1~255: FCLKO=FSEL/(2×DIV)
*****************************************************************************/
void  SYS_ConfigClkOutput(uint32_t ClkSel , uint32_t ClkDiv);

/*****************************************************************************
 ** \brief	SYS_EnableHSI
 **			使能高速时钟
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_EnableHSI(void);
/*****************************************************************************
 ** \brief	SYS_DisableHSI
 **			关闭高速时钟
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_DisableHSI(void);
/*****************************************************************************
 ** \brief	SYS_ConfigHSI
 **			配置高速时钟
 ** \param [in] HSISel: (1)SYS_CLK_HSI_64M
 **						(2)SYS_CLK_HSI_48M
 ** \return  none
 ** \note 切换不同的HSI 频率时，需要约125us（4~5*TLSI）才能切换到所选的频率，
 **		  在此期间，CPU 暂停运行。
*****************************************************************************/
void  SYS_ConfigHSI(uint32_t HSISel);
/*****************************************************************************
 ** \brief	SYS_EnableTRIMAdjustHSI
 **			开启TRIM调节内振频率
 ** \param [in] AdjValue: 0~255
 ** \return  none
 ** \note  上电或改变CLKCON[0]位时，系统自动加载出厂时的修调值
*****************************************************************************/
void  SYS_EnableTRIMAdjustHSI(uint32_t AdjValue);
/*****************************************************************************
 ** \brief	SYS_ConfigAHBClock
 **			配置AHB时钟
 ** \param [in] ClkSel :(1)SYS_CLK_SEL_HSI
 **						(2)SYS_CLK_SEL_LSI
 **				ClkDiv ：0~ 255	
 ** \return  none
 ** \note	(1) 0: HCLK = FSYS ； 1~255: HCLK = FSYS/(2×DIV)
 **			(2) 此函数自动加载 SystemCoreClockUpdate(),刷新系统时钟值
*****************************************************************************/
void  SYS_ConfigAHBClock(uint32_t ClkSel, uint32_t ClkDiv);
/*****************************************************************************
 ** \brief	SYS_ConfigAPBClock
 **			配置APB时钟
 ** \param [in] ClkDiv ：0~255				
 ** \return  none
 ** \note	(1) 0: PCLK = HCLK； 1~255: PCLK = HCLK/(2×DIV)
 **			(2) 此函数自动加载 SystemCoreClockUpdate(),刷新系统时钟值
*****************************************************************************/
void  SYS_ConfigAPBClock( uint32_t ClkDiv);


/*****************************************************************************
 ** \brief	SYS_ConfigLVDLevel
 **			设置LVD电压
 ** \param [in] LVDLevel：(1)SYS_LVD_2V		LVD监测电压选择2V
 **						  (2)SYS_LVD_2P2V	LVD监测电压选择2.2V
 **						  (3)SYS_LVD_2P4V	LVD监测电压选择2.4V
 **						  (4)SYS_LVD_2P7V	LVD监测电压选择2.7
 **						  (5)SYS_LVD_3V		LVD监测电压选择3V
 **						  (6)SYS_LVD_3P7V	LVD监测电压选择3.0
 **						  (7)SYS_LVD_4V		LVD监测电压选择4V
 **						  (8)SYS_LVD_4P3V	LVD监测电压选择4.3		
 ** \return  none
 ** \note	LVD一直开启
*****************************************************************************/
void SYS_ConfigLVDLevel(uint32_t LVDLevel);

/*****************************************************************************
 ** \brief	SYS_EnableLVDInt
 **			使能LVD中断
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void SYS_EnableLVDInt(void);
/*****************************************************************************
 ** \brief	SYS_DisableLVDInt
 **			关闭LVD中断
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void SYS_DisableLVDInt(void);
/*****************************************************************************
 ** \brief	SYS_GetLVDIntFlag
 **			获取LVD中断状态标志
 ** \param [in] none			
 ** \return  0：未产生中断 1：使能并产生中断
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetLVDIntFlag(void);
/*****************************************************************************
 ** \brief	SYS_GetLVDStateFlag
 **			获取LVD状态标志
 ** \param [in] none			
 ** \return  1：LVD大于VDD 0：LVD小于VDD
 ** \note	
*****************************************************************************/
uint32_t  SYS_GetLVDStateFlag(void);

/*****************************************************************************
 ** \brief	SYS_ClearLVDIntFlag
 **			清除LVD中断状态标志
 ** \param [in] none			
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_ClearLVDIntFlag(void);

/*****************************************************************************
 ** \brief	SYS_EnableSARMProtect
 **			开启SRAM保护
 ** \param [in] SRAMAddrMask :(1) SYS_SRAM_PORTECT_2K_4K_MSK 	RAM对2K~4K地址范围写保护
 **							  (2) SYS_SRAM_PORTECT_4K_6K_MSK	SRAM对4K~6K地址范围写保护
 **							  (3) SYS_SRAM_PORTECT_6K_8K_MSK	SRAM对6K~8K地址范围写保护
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_EnableSARMProtect(uint32_t SRAMAddrMask);
/*****************************************************************************
 ** \brief	SYS_DisableSARMProtect
 **			关闭SRAM保护
 ** \param [in] SRAMAddrMask :(1) SYS_SRAM_PORTECT_2K_4K_MSK 	RAM对2K~4K地址范围写保护
 **							  (2) SYS_SRAM_PORTECT_4K_6K_MSK	SRAM对4K~6K地址范围写保护
 **							  (3) SYS_SRAM_PORTECT_6K_8K_MSK	SRAM对6K~8K地址范围写保护
 ** \return  none
 ** \note	
*****************************************************************************/
void  SYS_DisableSARMProtect(uint32_t SRAMAddrMask);

/*****************************************************************************
 ** \brief	SYS_DisablePeripheralClk
 **			关闭外设时钟
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1时钟使能位
 **						  (2)SYS_CLK_ACMP_MSK:		模拟比较器时钟使能位				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	运放/PGA时钟使能位	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWM时钟使能位	
 **						  (5)SYS_CLK_CRC_MSK:		CRC时钟使能位	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDT时钟使能位	
 **						  (7)SYS_CLK_CCP_MSK:		捕获/PWM时钟使能位	
 **						  (8)SYS_CLK_ADC0_MSK:		ADC0时钟使能位	
 **						  (9)SYS_CLK_SSP_MSK:		SSP时钟使能位	
 **						  (10)SYS_CLK_I2C_MSK:		I2C时钟使能位	
 **						  (11)SYS_CLK_UART1_MSK:	UART1时钟使能位	
 **						  (12)SYS_CLK_UART0_MSK:	UART0时钟使能位	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	硬件除法器时钟使能位	
 **						  (14)SYS_CLK_TIMER01_MSK:	定时器时钟使能位	
 **						  (15)SYS_CLK_WDT_MSK:		WDT时钟使能位	
 ** \return  none
 ** \note	 
*****************************************************************************/	
void 	SYS_DisablePeripheralClk(uint32_t ModuleMask);
/*****************************************************************************
 ** \brief	SYS_EnablePeripheralClk
 **			开启外设时钟
 ** \param [in] ModuleMask:(1)SYS_CLK_ADC1_MSK: 		 ADC1时钟使能位
 **						  (2)SYS_CLK_ACMP_MSK:		模拟比较器时钟使能位				  
 **						  (3)SYS_CLK_OPA_PGA_MSK:	运放/PGA时钟使能位	
 **						  (4)SYS_CLK_EPWM_MSK:		EPWM时钟使能位	
 **						  (5)SYS_CLK_CRC_MSK:		CRC时钟使能位	
 **						  (6)SYS_CLK_WWDT_MSK:		WWDT时钟使能位	
 **						  (7)SYS_CLK_CCP_MSK:		捕获/PWM时钟使能位	
 **						  (8)SYS_CLK_ADC0_MSK:		ADC0时钟使能位	
 **						  (9)SYS_CLK_SSP_MSK:		SSP时钟使能位	
 **						  (10)SYS_CLK_I2C_MSK:		I2C时钟使能位	
 **						  (11)SYS_CLK_UART1_MSK:	UART1时钟使能位	
 **						  (12)SYS_CLK_UART0_MSK:	UART0时钟使能位	
 **						  (13)SYS_CLK_HWDIVCE_MSK:	硬件除法器时钟使能位	
 **						  (14)SYS_CLK_TIMER01_MSK:	定时器时钟使能位	
 **						  (15)SYS_CLK_WDT_MSK:		WDT时钟使能位	
 ** \return  none
 ** \note	 
*****************************************************************************/	
void 	SYS_EnablePeripheralClk(uint32_t ModuleMask);





#ifdef __cplusplus
}
#endif
#endif /* __SYSTEM_H__ */

