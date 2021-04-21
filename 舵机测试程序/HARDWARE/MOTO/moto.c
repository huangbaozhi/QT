/*
********************************************************************************************************
�ļ�����moto.c
��  �ܣ�ֱ�����ٵ������
��  ע��	��������AB��
��  ����https://shop60670850.taobao.com
��  �ߣ�lilianhe
��  ��: 2017-2-6
*********************************************************************************************************
*/

#include "moto.h"


//***************************���õ������IO��***************************//
//��������뵥Ƭ���˿����ã�IN1-IN2 ����PB12-P13��
//							          IN3-IN4 ����PB14-PB15��

void MOTO_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( MOTO_CLK, ENABLE);                                	  /*����GPIO������ʱ��*/																   
		GPIO_InitStructure.GPIO_Pin = MOTO_Pin1 | MOTO_Pin2 | MOTO_Pin3 | MOTO_Pin4;	/*ѡ��Ҫ���Ƶ�GPIO����*/	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                              /*��������ģʽΪͨ���������*/   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                             /*������������Ϊ50MHz */ 
		GPIO_Init(MOTO_PORT, &GPIO_InitStructure);                                    /*���ÿ⺯������ʼ��GPIO*/	
}

//***************************���ҵ����ǰת��***************************//
//ֻҪ����INx()��״̬�Ϳ��Ըı���ת������
//��������
void MOTO_Z(char state)
{
	if(state == GO)//��ǰ���ǰ��
	{
		IN1(0);//  ����ǰ��
		IN2(1);
	}
	if(state == BACK)//��ǰ�������
	{
		IN1(1);//  ��������
		IN2(0);
	}
	if(state == STOP)//ͣת
	{
	  IN1(1);//  ����ɲ��
		IN2(1);
	}
}


//�ҵ������
void MOTO_Y(char state)
{
	if(state == GO)
	{
		IN3(0);//  �ҵ��ǰ��
		IN4(1);
	}
	if(state == BACK)
	{
		IN3(1);//  �ҵ������
		IN4(0);
	}
	if(state == STOP)//ͣת
	{
	  IN3(1);//  �ҵ��ɲ��
		IN4(1);
	}
}





void Car_Go(void)
{
	//����ǰ��     //�ҵ��ǰ��
	MOTO_Z(GO);     MOTO_Y(GO);
}

//***************************���ҵ�����ת��***************************//
void Car_Back(void)
{
	//��������     //�ҵ������
	MOTO_Z(BACK);     MOTO_Y(BACK);
}

//***************************С��ԭ����ת***************************//
void Car_Turn_Right(void)
{
	//��������     //�ҵ��ǰ��
	MOTO_Z(GO);     MOTO_Y(BACK);
}

//***************************С��ԭ����ת***************************//
void Car_Turn_Left(void)
{
	//����ǰ��     //�ҵ������
	MOTO_Z(BACK);     MOTO_Y(GO);
}

//***************************ͣ��***************************//
void Car_Stop(void)
{
		//����ǰ��     //�ҵ��ǰ��
	MOTO_Z(STOP);     MOTO_Y(STOP);
}


