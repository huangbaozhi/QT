#include "bsp_sys.h"
#include "stdio.h"
#include "string.h"

int main(void)
{	
u8 BLE_TX[]={'1'};//定义蓝牙发送数据
u8 BLE_RX[1];//定义蓝牙接收数据缓存区
	System_Init();//所有系统配置在这个函数里完成	
	TIM_SetCompare1(TIM1,105);
	Duoji_Control(ON);
	Delay_ms(10);//	
	printf("开始发送");//插入换行
	while (1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		BLE_RX[0]=USART_ReceiveData(USART1);//等待接收
		if(BLE_RX[0]=='B')//手动抬杆
		{
				while(1)//等待车过			
				{
					TIM_SetCompare1(TIM1,50);	
					BLE_RX[0]='0';//接收清零
					BLE_RX[0]=USART_ReceiveData(USART1);//等待接收
					if(BLE_RX[0]=='C')
					{
						TIM_SetCompare1(TIM1,105);//舵机降杆
						BLE_RX[0]='0';//接收清零
						break;//开始下一次检测	
					}
				}
			}
		
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)==0)
		{
			
			USART1_Send(BLE_TX,1);//串口发送1
			while(1)
			{
				BLE_RX[0]='0';//接收清零
				BLE_RX[0]=USART_ReceiveData(USART1);//等待接收A
				if(BLE_RX[0]=='A')//接收到A
					TIM_SetCompare1(TIM1,50);				
				Delay_ms(100);	
				while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)==1)//等待车过	
					{
						Delay_ms(1000);//延时一秒等待车过
						TIM_SetCompare1(TIM1,105);//舵机降杆	
					}			
					break;//开始下一次检测	
				}			
			}		
		}
}
