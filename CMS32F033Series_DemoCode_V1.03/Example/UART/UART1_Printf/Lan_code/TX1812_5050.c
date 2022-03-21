#include "TX1812_5050.h"
#include "public.h"
//#include "intrins.h"
void TX1812_5050_Init(void)
{
	SYS_SET_IOCFG(IOP07CFG,SYS_IOCFG_P07_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO0,GPIO_PIN_7,GPIO_MODE_OUTPUT);	
	RGB_IO = 0;	
	Delay_1ms();
//	Delay_500ms();
	TMR_DisableOverflowInt(TMR0);
	RGB_Rest();
	Delay_1ms();
	RGB_All_OFF();
	Delay_1ms();
	RGB_All_OFF();
	Delay_1ms();
	TMR_EnableOverflowInt(TMR0);
}

void Delay_500ms(void)
{
	uint16_t x = 500;
	while(x--)
	{
		Delay_1ms();
	}
}

void Delay_1ms(void)
{
	uint16_t x = 5000;
	while(x--)
	{
		Delay_300ns();
	}
}

//void Delay_100us(void)
//{
//	uint16_t i = 50;
//	while(i--)
//	{
//		Delay_900ns();
//	}	
//}

void Delay_900ns(void)
{
	uint8_t i = 1;
	while(i--)
	{
		Delay_300ns();
	}
}

//void Delay_300ns(void)
//{
////	uint8_t i = 1;
////	while(i--)
////	{
//		//__ASM volatile ("nop");
//				//__ASM volatile ("nop");
////				__ASM volatile ("nop");
////				__ASM volatile ("nop");
////				__ASM volatile ("nop");
////				__ASM volatile ("nop");
////			__NOP;			
////	}
////	__NOP();
////	__NOP();
////		__NOP();
////	__NOP();
//		__NOP();
//}

void RGB_Rest(void)
{	
	RGB_IO = 1;
	RGB_IO = 0;
	Delay_1ms();
	RGB_IO = 1;
	RGB_IO = 0;
	Delay_1ms();
	
}

void RGB_All_OFF(void)
{
	u8 x = 30;
	TMR_DisableOverflowInt(TMR0);	
	while(x--)
	{
		RGB_Send_Dat(0,0,0);
	}
	TMR_EnableOverflowInt(TMR0);
	Delay_1ms();
}

void RGB_Send_Dat(uint8_t G_dat,uint8_t R_dat,uint8_t B_dat)
{
//	uint8_t i = 0;
//	uint8_t x = 0;
//	uint8_t Send_data = 0;
//	uint8_t rgb_dat = 0;
//	TMR_DisableOverflowInt(TMR0);		
//	for(x = 0; x < 3; x++)
//	{
//		if(x == 0)	Send_data = B_dat;
//		else if(x == 1)	Send_data = R_dat;
//		else if(x == 2)	Send_data = G_dat;
//	
//		for(i = 0; i < 8; i++)
//		{
//			rgb_dat = Send_data & 0x80;
//			if(rgb_dat)
//			{
//				RGB_IO = 1;
//				Delay_900ns();				
//				RGB_IO = 0;
//				Delay_300ns();
//			}
//			else 
//			{
//				RGB_IO = 1;
//				Delay_300ns();
//				RGB_IO = 0;
//				Delay_900ns();		
//			}
//			Send_data = Send_data << 1;
//		}
//	}
//	Delay_1ms();
//	TMR_EnableOverflowInt(TMR0);


	uint8_t i = 0;
	uint8_t x = 0;
	uint32_t Send_data = ((uint32_t)G_dat << 16) | ((uint32_t)R_dat << 8)|((uint32_t)B_dat);
	uint32_t rgb_dat = 0;
	TMR_DisableOverflowInt(TMR0);		
		for(i = 0; i < 24; i++)
		{			
			if(Send_data & 0x800000)
			{
				RGB_IO = 1;
				Delay_900ns();				
				RGB_IO = 0;
				Delay_300ns();
			}
			else 
			{
				RGB_IO = 1;
				Delay_300ns();
				RGB_IO = 0;
			}
			Send_data = Send_data << 1;			
		}
	TMR_EnableOverflowInt(TMR0);
}
u8 RGB_NUM = 1;
_RGB_DEF _RGB;

void RGB_TEST(void)
{
	 u8 Remb = RGB_NUM; 
//		_RGB.G_val = 0x00;
//		_RGB.R_val = 0x00;
//		_RGB.B_val = 0x00;	
	if(Remb != 0)
	{
		while(Remb--)
		{
			RGB_Send_Dat(0,10,0);
		}
	}
	else RGB_All_OFF();
	
	if(RGB_NUM < 30) 	RGB_NUM++;
	else RGB_NUM = 0;
}

void All_Bright_RGB(void)
{
	TMR_DisableOverflowInt(TMR0);	
	
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);		

			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);				
			
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);
			RGB_Send_Dat(0x00,0x80,0x00);
			RGB_Send_Dat(0x80,0x00,0x00);
			RGB_Send_Dat(0x00,0x00,0x80);	
			TMR_EnableOverflowInt(TMR0);
			Delay_1ms();	
}





