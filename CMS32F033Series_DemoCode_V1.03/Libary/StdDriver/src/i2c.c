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
/** \file i2c.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "i2c.h"
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
 ** \brief	I2C_ConfigClk
 **			????I2C????????
 ** \param [in] CLK_M: 0x00~0x7;
 **				CLK_N: 0x00~0xf;
 ** \return  none
 ** \note	????????= PCLK/2M  ?? SCL????= PCLK/??2M????N+1????10??
*****************************************************************************/
void I2C_ConfigClk(uint32_t CLK_M, uint32_t CLK_N)
{
	I2C->CLK = ((0x7 & CLK_M) <<4) | (0xf & CLK_N);
}

/*****************************************************************************
 ** \brief	I2C_EnableOutput
 **			????I2C????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void	I2C_EnableOutput(void)
{
	I2C->CONSET |= I2C_CONSSET_I2CEN_Msk;
}

/*****************************************************************************
 ** \brief	I2C_DisableOutput
 **			????I2C????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_DisableOutput(void)
{
	I2C->CONCLR |= I2C_CONSCLR_I2CEMC_Msk;
}
/*****************************************************************************
 ** \brief	I2C_EnableInt
 **			????I2C????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_EnableInt(void)
{
	I2C->CONSET |= I2C_CONSSET_I2CIE_Msk;
}
/*****************************************************************************
 ** \brief	I2C_DisableInt
 **			????I2C????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_DisableInt(void)
{
	I2C->CONCLR |= (I2C_CONSCLR_I2CIEC_Msk);
}

/*****************************************************************************
 ** \brief	I2C_GetIntFlag
 **			??????????????
 ** \param [in] none
 ** \return  0??I2C??????????????????  1??I2C????????????????
 ** \note	
*****************************************************************************/
uint32_t I2C_GetIntFlag(void)
{
	return((I2C->CONSET & I2C_CONSSET_SI_Msk)? 1:0);
}

/*****************************************************************************
 ** \brief	I2C_ClearIntFlag
 **			??I2C????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_ClearIntFlag(void)
{
	I2C->CONCLR |= I2C_CONSCLR_SIC_Msk;
}

/*****************************************************************************
 ** \brief	I2C_ClearStartFlag
 **			??I2C????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_ClearStartFlag(void)
{
	I2C->CONCLR |= I2C_CONSCLR_STAC_Msk;	
}
/*****************************************************************************
 ** \brief	I2C_ClearACKFlag
 **			??I2C????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_ClearACKFlag(void)
{
	I2C->CONCLR |= I2C_CONSCLR_AAC_Msk;		
}

/*****************************************************************************
 ** \brief	I2C_GetStatus
 **			????I2C????
 ** \param [in] none
 ** \return  Status
 ** \note	
*****************************************************************************/
uint32_t I2C_GetStatus(void)
{
	return((I2C->STAT));
}

/*****************************************************************************
 ** \brief	I2C_ConfigSlaveAddr
 **			????????????????
 ** \param [in] Slave: I2C_S_7BIT_ADDR0~I2C_S_10BIT_ADDR0
 **				addr: 7?????? ????10??????
 **				Broadcast: I2C_S_BROADCAST_EN ??I2C_S_BROADCAST_DIS
 **				AddrMask: 7??????????8??????
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_ConfigSlaveModeAddr(uint32_t Slave, uint32_t Addr, uint32_t Broadcast ,uint32_t AddrMask )
{
	switch(Slave)
	{
		case I2C_S_7BIT_ADDR0:
			I2C->ADR0 = (Addr<<1)| Broadcast;
			I2C->ADM0 = AddrMask;	
		break;
		case I2C_S_7BIT_ADDR1:
			I2C->ADR1 = (Addr<<1)| Broadcast;
			I2C->ADM1 = AddrMask;	
		break;	
		case I2C_S_7BIT_ADDR2:
			I2C->ADR2 = (Addr<<1)| Broadcast;
			I2C->ADM2 = AddrMask;	
		break;	
		case I2C_S_7BIT_ADDR3:
			I2C->ADR3 = (Addr<<1)| Broadcast;
			I2C->ADM3 = AddrMask;	
		break;	
		case I2C_S_10BIT_ADDR0:
			I2C->XADR0 = (Addr<<1)| Broadcast;
			I2C->XADM0 = AddrMask;	
		break;	
		default:
		break;
	}

}
/*****************************************************************************
 ** \brief	I2C_GetSlave10BitAddrFlag
 **			????I2C ????10????????????
 ** \param [in] none
 ** \return 0:I2C??????????   1: 12C 10??????????
 ** \note	
*****************************************************************************/
uint32_t I2C_GetSlave10BitAddrFlag(void)
{
	return((I2C->CONSET & I2C_CONSSET_XADRF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	I2C_GetSlave7BitAddrFlag
 **			????I2C ????7????????????
 ** \param [in] none
 ** \return 0:I2C??????????   1: 12C 10??????????
 ** \note	
*****************************************************************************/
uint32_t I2C_GetSlave7BitAddrFlag(void)
{
	return((I2C->CONSET & I2C_CONSSET_ADRF_Msk)? 1:0);
}

/*****************************************************************************
 ** \brief	I2C_Reset
 **			????I2C????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_Reset(void)
{
	I2C->RST = 0x07;
}

/*****************************************************************************
 ** \brief	I2C_SendData
 **			????????
 ** \param [in] I2CData
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_SendData(uint32_t I2CData)
{		
	I2C->DAT = I2CData;
}
/*****************************************************************************
 ** \brief	I2C_SendACK
 **			??????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_SendACK(void)
{
	I2C->CONSET |= I2C_CONSSET_AA_Msk;
}
/*****************************************************************************
 ** \brief	I2C_NotSendACK
 **			????????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_NotSendACK(void)
{
	I2C->CONCLR |= I2C_CONSCLR_AAC_Msk;	
}
/*****************************************************************************
 ** \brief	I2C_SendStart
 **			??????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_SendStart(void)
{
	I2C->CONSET |= I2C_CONSSET_STA_Msk;	
}
/*****************************************************************************
 ** \brief	I2C_SendRestart
 **			??????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_SendRestart(void)
{
	I2C->CONSET |= I2C_CONSSET_STA_Msk;	
}
/*****************************************************************************
 ** \brief	I2C_SendStop
 **			??????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_SendStop(void)
{
	I2C->CONSET |= I2C_CONSSET_STO_Msk;	
}
/*****************************************************************************
 ** \brief	I2C_SendStopBeforeStart
 **			??????????????????????????????????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void I2C_SendStopBeforeStart(void)
{
	I2C->CONSET |= I2C_CONSSET_STA_Msk | I2C_CONSSET_STO_Msk;	
}

/*****************************************************************************
 ** \brief	I2C_GetData
 **			????????
 ** \param [in] none
 ** \return  Data
 ** \note	
*****************************************************************************/
uint32_t I2C_GetData(void)
{
	return (0xff & I2C->DAT);
}
