#include "bsp_sys.h"
#include "stdio.h"
#include "string.h"

int main(void)
{	
u8 BLE_TX[]={'1'};//����������������
u8 BLE_RX[1];//���������������ݻ�����
	System_Init();//����ϵͳ������������������	
	TIM_SetCompare1(TIM1,105);
	Duoji_Control(ON);
	Delay_ms(10);//	
	printf("��ʼ����");//���뻻��
	while (1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		BLE_RX[0]=USART_ReceiveData(USART1);//�ȴ�����
		if(BLE_RX[0]=='B')//�ֶ�̧��
		{
				while(1)//�ȴ�����			
				{
					TIM_SetCompare1(TIM1,50);	
					BLE_RX[0]='0';//��������
					BLE_RX[0]=USART_ReceiveData(USART1);//�ȴ�����
					if(BLE_RX[0]=='C')
					{
						TIM_SetCompare1(TIM1,105);//�������
						BLE_RX[0]='0';//��������
						break;//��ʼ��һ�μ��	
					}
				}
			}
		
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)==0)
		{
			
			USART1_Send(BLE_TX,1);//���ڷ���1
			while(1)
			{
				BLE_RX[0]='0';//��������
				BLE_RX[0]=USART_ReceiveData(USART1);//�ȴ�����A
				if(BLE_RX[0]=='A')//���յ�A
					TIM_SetCompare1(TIM1,50);				
				Delay_ms(100);	
				while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)==1)//�ȴ�����	
					{
						Delay_ms(1000);//��ʱһ��ȴ�����
						TIM_SetCompare1(TIM1,105);//�������	
					}			
					break;//��ʼ��һ�μ��	
				}			
			}		
		}
}
