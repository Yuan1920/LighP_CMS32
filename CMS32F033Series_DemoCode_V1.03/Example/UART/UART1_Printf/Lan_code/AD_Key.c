#include "AD_Key.h"
#include "demo_uart.h"
#include "SMG.h"
#include "TX1812_5050.h"
//#include "Operation.h"

#include "CXN4016.h"
/**********************************/
/**********************************/
_KEY_xx _Key[Key_Number];
unsigned int Key_ms = 0;
//unsigned char code Get_Input_IO[Key_Number] = {0};
unsigned int AD_Key_Val = 0;
/***********************************************/
//extern _GAME_DEF _Game;
/***********************************************/
extern u8 Test_flag;
void Key_Init_IO(void)
{
	SYS_SET_IOCFG(IOP21CFG,SYS_IOCFG_P21_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_1,GPIO_MODE_INPUT_WITH_PULL_UP);
	
	SYS_SET_IOCFG(IOP22CFG,SYS_IOCFG_P22_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_2,GPIO_MODE_INPUT_WITH_PULL_UP);	

	SYS_SET_IOCFG(IOP23CFG,SYS_IOCFG_P23_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_3,GPIO_MODE_INPUT_WITH_PULL_UP);		
	
	SYS_SET_IOCFG(IOP24CFG,SYS_IOCFG_P24_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_4,GPIO_MODE_INPUT_WITH_PULL_UP);		
	
	SYS_SET_IOCFG(IOP14CFG,SYS_IOCFG_P14_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_4,GPIO_MODE_INPUT_WITH_PULL_UP);	

	SYS_SET_IOCFG(IOP13CFG,SYS_IOCFG_P13_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_3,GPIO_MODE_INPUT_WITH_PULL_UP);	

	SYS_SET_IOCFG(IOP12CFG,SYS_IOCFG_P12_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_2,GPIO_MODE_INPUT_WITH_PULL_UP);	

	SYS_SET_IOCFG(IOP10CFG,SYS_IOCFG_P10_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO1,GPIO_PIN_0,GPIO_MODE_INPUT_WITH_PULL_UP);	

}

int Get_Key_val (void) 
{
	unsigned char AD_VAL;
	if(IO_KEY_1 == 0)	AD_VAL = 5;
	else if(IO_KEY_2 == 0)	AD_VAL = 6;
	else if(IO_KEY_3 == 0)	AD_VAL = 7;
	else if(IO_KEY_4 == 0)	AD_VAL = 8;
	else if(IO_KEY_5 == 0)	AD_VAL = 1;
	else if(IO_KEY_6 == 0)	AD_VAL = 2;
	else if(IO_KEY_7 == 0)	AD_VAL = 3;
	else if(IO_KEY_8 == 0)	AD_VAL = 4;
	return AD_VAL;
		
}
void AD_GetKey(void)
{
	static unsigned char i;
	unsigned char IO_Key_valid_val[Key_Number] = {1,2,3,4,5,6,7,8};  
	unsigned int AD_Key_Val = 0;

	if((Key_ms >= 10))  // 每10ms扫描一次 或者 8ms
	{
		Key_ms = 0;
		AD_Key_Val = Get_Key_val();
		for(i = 0; i < Key_Number; i++)
		{
/*************** Read and operation AD_KEY_VAL ************************/
				if(AD_Key_Val == IO_Key_valid_val[i])
           _Key[i].Buf = 1;
				else _Key[i].Buf = 0;
/**********************************************************************/
				if(_Key[i].Buf != _Key[i].Pre_Buf)
				{
					_Key[i].Time++;
					if( _Key[i].Time > 5)
					{
						_Key[i].Time = 0;
						if((_Key[i].Buf == 0) && (_Key[i].Mode != LongPre))
						{
							#if(Key_Double_EN)
							_Key[i].Value++;
							#else
							_Key[i].Value = 0;
							_Key[i].Flag = 1;
							#endif
						}
						_Key[i].Pre_Buf = _Key[i].Buf;
					}
				}
				else
				{
					#if(Key_Double_EN)
					/************* Double_Click *********************/
						if(	_Key[i].Value >= 1)
							_Key[i].Doub_clk_time++;
						else _Key[i].Doub_clk_time = 0;

						if((_Key[i].Doub_clk_time > Key_Double_Time_Interval))
						{
							_Key[i].Doub_clk_time = 0;

								if(_Key[i].Value == 2)
								{
									_Key[i].Value = 0;
									_Key[i].Flag = Double_Click;
								}
								else if(_Key[i].Value == 1)
								{
									_Key[i].Value = 0;
									_Key[i].Flag = Click;
								}
								else	_Key[i].Value = 0;
						}
					#endif
					#if(Key_LongPre_EN)
						/********** Long_Pre **************************/
						_Key[i].Time = 0;
						if(_Key[i].Buf == 1)
						{
							if(_Key[i].Delay <= Key_Long_Tim_Val)	// 3s
							{
								_Key[i].Delay++;
////	if((_Game.Status == 1))
//	{
////		if((_Game.Ball < 16) /*&& (AD_Key_Val > 4000)*/)
//		{
//			//_Game.Speed = (4000 - (_Key[3].Delay)*50);
//			_Game.Speed = 1000;
//			printf("_Key[3] = %d\n",_Key[3].Delay);
//		}
////		 if((_Game.Ball > 16) /*&& (AD_Key_Val > 4000)*/)
//		{
//			//_Game.Speed = (4000 - (_Key[2].Delay)*50);
//				_Game.Speed = 1000;
//			printf("_Key[2] = %d\n",_Key[2].Delay);
//		}
//		if(_Game.Speed < 500)	_Game.Speed  = 500;
//		//printf("_Game.Speed = %d\n",_Game.Speed);
//	}
								if(_Key[i].Delay == Key_Long_Tim_Val)
								{
									_Key[i].Mode = LongPre;
									_Key[i].Value = 0;
									_Key[i].Flag = LongPre;
								}
							}
						}
						else
						{
							_Key[i].Delay = 0;
							_Key[i].Mode = 0;
						}
					#endif
				}
	/*********************** Key_function_test ************************************/
				if(_Key[0].Flag == 1)		// 单击
				{
					_Key[0].Flag = 0;
//					printf("K_1\n");
				Test_flag = 1;
//			Line_1A_CXN4(0xE1);
//			Line_1A_CXN4(0xF2);
//			Line_1A_CXN4(0x04);
				}
				else if(_Key[0].Flag == 2)
				{
					_Key[0].Flag = 0;

				}
				else if(_Key[0].Flag == 3)	// 长按
				{
					_Key[0].Flag = 0;
					printf("K_1_Long\n");
					
				}
/********************* 强度“+” ************************************/
				if(_Key[1].Flag == 1)				
				{
					_Key[1].Flag = 0;
					printf("K_2\n");
					Line_1A_CXN4(0xFE);
				}
				else if(_Key[1].Flag == 2)
				{
					_Key[1].Flag = 0;
				}
				else if(_Key[1].Flag == 3)
				{
					_Key[1].Flag = 0;
				}
/******************** 乒乓——B***************************************/
				if(_Key[2].Flag == 1)
				{
					_Key[2].Flag = 0;
				
					printf("K_3\n");
//					if(_Game.Status == 0)
//					{
//						_Game.Status = 1;
//						_Game.Direction = 1;
//						_Game.Ball = 30;
//					}
//					else if((_Game.Status == 1)&&(_Game.Ball > 16))
//					{
//						_Game.Direction = 1;
//					}
//					else if(_Game.Status == 2)
//					{
//						_Game.Status = 1;
//						_Game.Direction = 1;
//						_Game.Ball = 30;
//						_Game.Speed = 1000;
//						_Game.Result = 0;
//					}
				}
				else if(_Key[2].Flag == 2)
				{
					_Key[2].Flag = 0;
				}
				else if(_Key[2].Flag == 3)
				{
					_Key[2].Flag = 0;

				}
				/******************** 乒乓——A ***************************************/
				if(_Key[3].Flag == 1)
				{
					_Key[3].Flag = 0;
					
						printf("K_4\n");
					
//					if(_Game.Status == 0)
//					{
//						_Game.Status = 1;
//						_Game.Direction = 0;
//						_Game.Ball = 1;
//						_Game.Speed = 1000;
//					}
//					else if((_Game.Status == 1)&&(_Game.Ball < 16))
//					{
//						_Game.Direction = 0;
//					}
//					else if(_Game.Status == 2)
//					{
//						_Game.Status = 1;
//						_Game.Direction = 0;
//						_Game.Ball = 0;		
//						_Game.Speed = 1000;
//						_Game.Result = 0;
//					}
				}
				else if(_Key[3].Flag == 2)
				{
					_Key[3].Flag = 0;
				}
				else if(_Key[3].Flag == 3)
				{
					_Key[3].Flag = 0;
					LED4_IO = ~LED4_IO;
				}
				/*********************************************************/
				if(_Key[4].Flag == 1)				
				{
					_Key[4].Flag = 0;
					printf("K_5\n");
					
				}
				else if(_Key[4].Flag == 2)
				{
					_Key[4].Flag = 0;
				}
				else if(_Key[4].Flag == 3)
				{
					_Key[4].Flag = 0;
					printf("K_5_Long\n");
				}
				/*********************************************************/
				if(_Key[5].Flag == 1)				
				{
					_Key[5].Flag = 0;
					printf("K_6\n");
					
				}
				else if(_Key[5].Flag == 2)
				{
					_Key[5].Flag = 0;
				}
				else if(_Key[5].Flag == 3)
				{
					_Key[5].Flag = 0;
					
				}	
				/*********************************************************/
				if(_Key[6].Flag == 1)				
				{
					_Key[6].Flag = 0;
					printf("K_7\n");
					
				}
				else if(_Key[6].Flag == 2)
				{
					_Key[6].Flag = 0;
				}
				else if(_Key[6].Flag == 3)
				{
					_Key[6].Flag = 0;
				}				
				/*********************************************************/
				if(_Key[7].Flag == 1)				
				{
					_Key[7].Flag = 0;
					printf("K_8\n");
					
				}
				else if(_Key[7].Flag == 2)
				{
					_Key[7].Flag = 0;
				}
				else if(_Key[7].Flag == 3)
				{
					_Key[7].Flag = 0;
				}					
			}
	}
}







