#include "SMG.h"

_SMG_DEF _SMG[2];

void LED_IO_INIT(void)
{
	/************* SMG_A ************************/
	SYS_SET_IOCFG(IOP35CFG,SYS_IOCFG_P35_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_5,GPIO_MODE_OUTPUT);	
	LED_A_IO = 0;		// P32  0=Open  1=Close 	AO3401

	SYS_SET_IOCFG(IOP36CFG,SYS_IOCFG_P36_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_6,GPIO_MODE_OUTPUT);	
	LED_B_IO = 1;		// P17  0=Open  1=Close 	AO3401
	
	SYS_SET_IOCFG(IOP34CFG,SYS_IOCFG_P34_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_4,GPIO_MODE_OUTPUT);	
	LED7_IO = 1;
	
	SYS_SET_IOCFG(IOP32CFG,SYS_IOCFG_P32_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_2,GPIO_MODE_OUTPUT);	
	LED6_IO = 1;
	
	SYS_SET_IOCFG(IOP31CFG,SYS_IOCFG_P31_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_1,GPIO_MODE_OUTPUT);	
	LED5_IO = 1;	
	
	SYS_SET_IOCFG(IOP44CFG,SYS_IOCFG_P44_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO4,GPIO_PIN_4,GPIO_MODE_OUTPUT);	
	LED4_IO = 1;	
	
	SYS_SET_IOCFG(IOP30CFG,SYS_IOCFG_P30_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO3,GPIO_PIN_0,GPIO_MODE_OUTPUT);	
	LED3_IO = 1;	
	
	SYS_SET_IOCFG(IOP43CFG,SYS_IOCFG_P43_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO4,GPIO_PIN_3,GPIO_MODE_OUTPUT);	
	LED2_IO = 1;	
	
	SYS_SET_IOCFG(IOP15CFG,SYS_IOCFG_P15_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_5,GPIO_MODE_OUTPUT);	
	LED1_IO = 1;	
	/************* SMG_B ************************/
}

void SMG_AA_ALL_OFF(void)
{
	LED1_IO = 1;
	LED2_IO = 1;
	LED3_IO = 1;
	LED4_IO = 1;
	LED5_IO = 1;
	LED6_IO = 1;
	LED7_IO = 1;	
}

void SMG_Show_AA(uint8_t dat)
{
		if(_SMG[0].Flag)
		{
			LED_A_IO = 0;			// open
			LED_B_IO = 1;			// close
			if(_SMG[0].OnlyOne)
			{
				//_SMG[0].OnlyOne = 0;
				
				switch(dat)
				{
					case 0:
						LED1_IO = 0;
						LED2_IO = 0;
						LED3_IO = 0;
						LED4_IO = 0;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 1;					
						break;
					
					case 1:
						LED1_IO = 1;
						LED2_IO = 1;
						LED3_IO = 1;
						LED4_IO = 1;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 1;											
						break;	
					
					case 2:
						LED1_IO = 0;
						LED2_IO = 0;
						LED3_IO = 1;
						LED4_IO = 0;
						LED5_IO = 0;
						LED6_IO = 1;
						LED7_IO = 0;					
						
						break;
					
					case 3:
						LED1_IO = 0;
						LED2_IO = 1;
						LED3_IO = 1;
						LED4_IO = 0;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 0;					
						
						break;

					case 4:
						LED1_IO = 1;
						LED2_IO = 1;
						LED3_IO = 0;
						LED4_IO = 1;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 0;					
						
						break;

					case 5:
						LED1_IO = 0;
						LED2_IO = 1;
						LED3_IO = 0;
						LED4_IO = 0;
						LED5_IO = 1;
						LED6_IO = 0;
						LED7_IO = 0;					
						
						break;
					
					case 6:
						LED1_IO = 0;
						LED2_IO = 0;
						LED3_IO = 0;
						LED4_IO = 0;
						LED5_IO = 1;
						LED6_IO = 0;
						LED7_IO = 0;					
						
						break;
					
					case 7:
						LED1_IO = 1;
						LED2_IO = 1;
						LED3_IO = 1;
						LED4_IO = 0;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 1;					
						
						break;
					
					case 8:
						LED1_IO = 0;
						LED2_IO = 0;
						LED3_IO = 0;
						LED4_IO = 0;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 0;					
						
						break;
					
					case 9:
						LED1_IO = 0;
						LED2_IO = 1;
						LED3_IO = 0;
						LED4_IO = 0;
						LED5_IO = 0;
						LED6_IO = 0;
						LED7_IO = 0;					
						
						break;
										
				}
			}
		}
		else 
		{
			LED_A_IO = 1;		//close
			LED_B_IO = 1;
			SMG_AA_ALL_OFF();
		}
}





