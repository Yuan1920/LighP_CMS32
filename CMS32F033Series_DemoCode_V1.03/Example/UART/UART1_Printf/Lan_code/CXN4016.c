#include "CXN4016.h"
#include "public.h"

// ÿ����ַָ���ʱ��������� 10ms
#define UC8 unsigned char

void CXN4016_INIT(void)
{
	SYS_SET_IOCFG(IOP26CFG,SYS_IOCFG_P26_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_6,GPIO_MODE_OUTPUT);	
	CXN4016_DATA_IO = 0;
	
	SYS_SET_IOCFG(IOP25CFG,SYS_IOCFG_P25_GPIO);	
	GPIO_CONFIG_IO_MODE(GPIO2,GPIO_PIN_5,GPIO_MODE_INPUT_WITH_PULL_DOWN);	
	// �ݶ���������
	
}

void Delay_N10us(u16 ms) // ��ʱ 1.2ms
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
; ģ������:Line_1A_CXN4(UC8 SB_DATA)
; �� ��: ʵ �� һ �� �� �� ͨ �� �� ��
; �� ��: SB_DATA  Ϊ��������
; �� ��:
;P_DATA  Ϊ���ݿ�
;-------------------------------------*/
void Line_1A_CXN4( unsigned char SB_DATA)
{
	u8 S_DATA;
	u8 B_DATA;
	u8 j = 0;
	S_DATA= SB_DATA;
	CXN4016_DATA_IO = 0;
	//T4_TEST_IO = 0;
	Delay_1ms(); // ****** Э����Ҫ��ʱ 5ms
	Delay_1ms(); // ****** Э����Ҫ��ʱ 5ms
	Delay_1ms(); // ****** Э����Ҫ��ʱ 5ms
	Delay_1ms(); // ****** Э����Ҫ��ʱ 5ms
	Delay_1ms(); // ****** Э����Ҫ��ʱ 5ms
	B_DATA = S_DATA&0X01;
	for(j=0;j<8;j++)
	{
			if(B_DATA == 1)
			{
				CXN4016_DATA_IO= 1;
				Delay_N10us(120); // ��ʱ 1.2ms
				CXN4016_DATA_IO= 0;
				Delay_N10us(40); // ��ʱ 400us
			}
			else
			{
				CXN4016_DATA_IO= 1;
				Delay_N10us(40); // ��ʱ 400us
				CXN4016_DATA_IO= 0;
				Delay_N10us(120); // ��ʱ 1.2ms				
			}
			S_DATA = S_DATA>>1;
			B_DATA = S_DATA&0X01;
		
		
//			if(B_DATA == 1)
//			{
//				T4_TEST_IO= 1;
//				Delay_N10us(120); // ��ʱ 1.2ms
//				T4_TEST_IO= 0;
//				Delay_N10us(40); // ��ʱ 400us
//			}
//			else
//			{
//				T4_TEST_IO= 1;
//				Delay_N10us(40); // ��ʱ 400us
//				T4_TEST_IO= 0;
//				Delay_N10us(120); // ��ʱ 1.2ms				
//			}
//			S_DATA = S_DATA>>1;
//			B_DATA = S_DATA&0X01;
	}
	CXN4016_DATA_IO = 1;
	Delay_N10us(40); // ��ʱ 400us
}







