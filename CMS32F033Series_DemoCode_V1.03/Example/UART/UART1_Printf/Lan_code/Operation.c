#include "Operation.h"

_GAME_DEF _Game;

void BingBang_Init_Show(void)
{
		u8 AB_Color = 0;
		for(AB_Color = 0; AB_Color < 31; AB_Color++)	
		{	
				if(AB_Color < 15)
				{
						RGB_Send_Dat(0,0,0);
				}
				else if(AB_Color == 15)
				{
						RGB_Send_Dat(0,200,0);
				}
				else if(AB_Color > 15)
				{
						RGB_Send_Dat(0,0,0);
				}
		}
		Delay_1ms();
}

/****************** 来回流动*****************************/
//void BingBang_Show(void)	
//{
//	u8 Remb_Ball = _Game.Ball;
//	if(_Game.Direction == 0)
//	{
//			while(Remb_Ball--)
//			{
//					RGB_Send_Dat(0,0,0);
//			}
//				RGB_Send_Dat(10,10,10);
//				Delay_1ms();
//	}
//	else		// 球反向回来
//	{
//			while(Remb_Ball--)
//			{
//				RGB_Send_Dat(0,0,0);
//			}
//			if(Remb_Ball == 15)
//			{
//				RGB_Send_Dat(0,200,0);
//			}
//			else
//			{
//				RGB_Send_Dat(10,10,10);
//				RGB_Send_Dat(0,0,0);
//			}		
//	}
//}



//void BingBang_Show(void)
//{
//	u8 Cmd_Cnt = 0;
//	u8 Centre = 16;
//	u8 Centre_F = 29;
//	u8 Cmd_Cnt_F = 0;
//	u8 Remb_Ball = _Game.Ball;
//	
//	if(_Game.Direction == 0)
//	{
//		
//		if( _Game.Ball == 0)
//		{
//			RGB_Send_Dat(10,10,10);
//			while(Centre--)
//			{
//				if(Centre == 0)
//					RGB_Send_Dat(0,200,0);
//				else
//					RGB_Send_Dat(0,0,0);
//			}
//		}
//		else
//		{			
//			while(Cmd_Cnt < _Game.Ball)
//			{
//					RGB_Send_Dat(0,0,0);
//					Cmd_Cnt++;
//			}
//			
//			if(_Game.Ball == 16) 	RGB_Send_Dat(0,200,0);			
//			else RGB_Send_Dat(10,10,10);
//			
//			Centre -= _Game.Ball;
//			while(Centre--)
//			{
//				if(Centre == 0)
//					RGB_Send_Dat(0,200,0);
//				else
//					RGB_Send_Dat(0,0,0);
//			}
//		}
//	}
//	else		// 球反向回来
//	{
//		//_Game.Ball = 29;
//			if( _Game.Ball == 29)
//			{
//				
//				while(Centre_F--)
//				{
//					if(Cmd_Cnt_F == 12)
//						RGB_Send_Dat(0,200,0);
//					else
//						RGB_Send_Dat(0,0,0);
//				}
//				RGB_Send_Dat(10,10,10);
//			}			
//			
//	}
//}



void BingBang_Show(void)
{
	u8 Remb_Ball = _Game.Ball;
	u8 A_place = 0;
	u16 Cnt_A = 0;
	u8 Cnt_A_A = 16;
	u8 Cnt_B = 0;
	u8 Cnt_B_B = 30;	
//			while(Remb_Ball--)
//			{
//					RGB_Send_Dat(0,0,0);
//			}
//			RGB_Send_Dat(10,10,10);
//			Delay_1ms();
/*********************************/
				
			switch(_Game.Ball)
			{
				case 0:
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);		
Delay_1ms();					
					break;

				case 1:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);						
					break;
					
				case 2:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);	
Delay_1ms();					
					break;
					
				case 3:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);				
Delay_1ms();					
					break;
					
				case 4:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);	
Delay_1ms();					
					break;
					
				case 5:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);			
Delay_1ms();					
					break;
					
				case 6:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);				
Delay_1ms();					
					break;
					
				case 7:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);				
Delay_1ms();					
					break;
					
				case 8:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);		
Delay_1ms();					
					break;
					
				case 9:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);			
Delay_1ms();					
					break;
					
				case 10:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);					
Delay_1ms();
					break;
					
				case 11:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);	
Delay_1ms();					
					break;
					
				case 12:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);		
Delay_1ms();					
					break;
					
				case 13:
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);			
Delay_1ms();					
					break;
					
				case 14:
					RGB_Send_Dat(0,0,0);
				
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
				RGB_Send_Dat(10,10,10);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);					
Delay_1ms();				

					break;
					
				case 15:
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);		
Delay_1ms();					
					break;
					
				case 16:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);			
Delay_1ms();					

					break;
					
					
				case 17:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);					
Delay_1ms();					
					break;
					
				case 18:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);			
Delay_1ms();					
					break;	
					
				case 19:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);				
Delay_1ms();					
					break;
					
				case 20:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
Delay_1ms();					
					break;
					
					
				case 21:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);					
Delay_1ms();					
					break;

					
				case 22:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);						
Delay_1ms();					
					break;
					
										
				case 23:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);		
Delay_1ms();					
					break;
					
										
				case 24:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);				
Delay_1ms();					
					break;
					
										
				case 25:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);				
Delay_1ms();					
					break;
					
										
				case 26:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);						
Delay_1ms();					
					break;
					
										
				case 27:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);						
Delay_1ms();					
					break;
					
										
				case 28:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);
					RGB_Send_Dat(0,0,0);		
Delay_1ms();					
					break;
					
										
				case 29:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(0,0,0);
					RGB_Send_Dat(10,10,10);		
Delay_1ms();
					break;
			}
}

void Game_Result_Show(void)
{
	if(	_Game.Result_Ms >= 10)	
	{
		_Game.Result_Ms = 0;
		_Game.Shiny_Flag = !_Game.Shiny_Flag;
		
	}
			switch(_Game.Result)
			{
				case 0:
					
					break;
				
				case 1:
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					RGB_Send_Dat(10,0,0);
					
					RGB_Send_Dat(0,200,0);
					if(_Game.Shiny_Flag)
					{
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);							
					}
					else 
					{
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);								
					}
					Delay_1ms();					
					break;
				
				case 2:
					if(_Game.Shiny_Flag)
					{
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);
						RGB_Send_Dat(0,10,0);							
					}
					else 
					{
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);
						RGB_Send_Dat(0,0,0);								
					}					
					
					RGB_Send_Dat(0,200,0);
					
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);
					RGB_Send_Dat(0,0,10);

					Delay_1ms();						
					break;
			}
	

}



void Game_Mode(void)
{
	switch(_Game.Mode)
	{
		case 0:
			if(_Game.OnlyOne)
			{
				_Game.OnlyOne = 0;
				
			}		
			
			break;
		
		case 1:
			if(_Game.OnlyOne)
			{
				_Game.OnlyOne = 0;
				if(_Game.Status == 1)
				{
					BingBang_Show();					
				}
				else if(_Game.Status == 2)
				{
					Game_Result_Show();
				}
			}		
		break;
	}
}

