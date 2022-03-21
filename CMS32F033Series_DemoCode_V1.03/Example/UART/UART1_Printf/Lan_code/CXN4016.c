#include "CXN4016.h"
#include "public.h"

// 每条地址指令的时间间隔需大于 10ms
#define UC8 unsigned char

void CXN4016_INIT(void)
{
	SYS_SET_IOCFG(IOP26CFG,SYS_IOCFG_P26_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_6,GPIO_MODE_OUTPUT);	
	CXN4016_DATA_IO = 0;
	
	SYS_SET_IOCFG(IOP25CFG,SYS_IOCFG_P25_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_5,GPIO_MODE_INPUT_WITH_PULL_DOWN);	
	// 暂定下拉输入
	
}

void Delay_N10us(u16 ms) // 延时 1.2ms
{
	uint16_t x = 0;
	uint16_t y = 0;
	for(y = 0; y < ms; y++)
	{
		x = 20;
		while(x--)
		{
			Delay_300ns();
			Delay_300ns();
			Delay_300ns();	
		}	
	}
}



/*--------------------------------------
; 模块名称:Line_1A_CXN4(UC8 SB_DATA)
; 功 能: 实 现 一 线 串 口 通 信 函 数
; 入 参: SB_DATA  为发送数据
; 出 参:
;P_DATA  为数据口
;-------------------------------------*/
void Line_1A_CXN4( unsigned char SB_DATA)
{
	u8 S_DATA;
	u8 B_DATA;
	u8 j = 0;
	S_DATA= SB_DATA;
	CXN4016_DATA_IO = 0;
	//T4_TEST_IO = 0;
	Delay_1ms(); // ****** 协议需要延时 5ms
	Delay_1ms(); // ****** 协议需要延时 5ms
	Delay_1ms(); // ****** 协议需要延时 5ms
	Delay_1ms(); // ****** 协议需要延时 5ms
	Delay_1ms(); // ****** 协议需要延时 5ms
	B_DATA = S_DATA&0X01;
	for(j=0;j<8;j++)
	{
			if(B_DATA == 1)
			{
				CXN4016_DATA_IO= 1;
				Delay_N10us(120); // 延时 1.2ms
				CXN4016_DATA_IO= 0;
				Delay_N10us(40); // 延时 400us
			}
			else
			{
				CXN4016_DATA_IO= 1;
				Delay_N10us(40); // 延时 400us
				CXN4016_DATA_IO= 0;
				Delay_N10us(120); // 延时 1.2ms				
			}
			S_DATA = S_DATA>>1;
			B_DATA = S_DATA&0X01;
		
		
//			if(B_DATA == 1)
//			{
//				T4_TEST_IO= 1;
//				Delay_N10us(120); // 延时 1.2ms
//				T4_TEST_IO= 0;
//				Delay_N10us(40); // 延时 400us
//			}
//			else
//			{
//				T4_TEST_IO= 1;
//				Delay_N10us(40); // 延时 400us
//				T4_TEST_IO= 0;
//				Delay_N10us(120); // 延时 1.2ms				
//			}
//			S_DATA = S_DATA>>1;
//			B_DATA = S_DATA&0X01;
	}
	CXN4016_DATA_IO = 1;
	Delay_N10us(40); // 延时 400us
}







