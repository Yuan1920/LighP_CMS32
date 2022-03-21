#ifndef _OPERATION_H_
#define _OPERATION_H_
#include "cms8s6990.h"
#include "demo_uart.h"
#include "stdio.h"

#include "public.h"
#include "demo_timer.h"

#include "SMG.h"
#include "AD_Key.h"
#include "TX1812_5050.h"


typedef struct
{
	u8 Mode;
	u8 OnlyOne;
	u8 Centre_onlyOne;
	u8 Direction;
	u8 Ball;
	u16 Speed;
	u8 Status;
	u8 Result;		// 1 = AӮ   2 = BӮ
	u16 Result_Ms;
	u8 Shiny_Flag;
	u8 WinCnt_A;
}_GAME_DEF;

void BingBang_Init_Show(void);
void BingBang_Show(void);
void Game_Mode(void);



#endif