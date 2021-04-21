/*
********************************************************************************************************
�ļ�����bsp_timer1.c
��  �ܣ��������
��  ע��20ms��������Ƶ��50Hz
��  ����https://shop60670850.taobao.com
��  �ߣ�lilianhe
��  ��: 2017-2-6
*********************************************************************************************************
*/
#include "bsp_timer1.h"

//��ʼ��PA8
//PWM_duoji(1000, 1440, 75);//2.5ms---90��
void TIM1_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  //ʹ��GPIO����ʱ��ʹ��
	                                                                     	

   //���ø�����Ϊ�����������,���TIM1 CH1��PWM���岨��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //TIM_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	
	TIM_TimeBaseStructure.TIM_Period = (arr-1); //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1); //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Disable);

	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE �����ʹ��	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	//TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM1
 
   
}

//�������
//Duoji_Control(OFF);		
//TIM_SetCompare1(TIM1,30);//ռ�ձ�3%,���ұߣ�0��
//Duoji_Control(ON);	
//	
//Duoji_Control(OFF);		
//TIM_SetCompare1(TIM1,50);//ռ�ձ�5%��45��
//Duoji_Control(ON);	

//Duoji_Control(OFF);		
//TIM_SetCompare1(TIM1,75);//ռ�ձ�5%��90��
//Duoji_Control(ON);

//Duoji_Control(OFF);		
//TIM_SetCompare1(TIM1,100);//ռ�ձ�5%��135��
//Duoji_Control(ON);

//Duoji_Control(OFF);		
//TIM_SetCompare1(TIM1,125);//ռ�ձ�12.5%�������180��
//Duoji_Control(ON);	
void Duoji_Control(char state)
{
	if(state == ON)
	{
		 TIM_Cmd(TIM1, ENABLE);  

	}
	else 
	{
		 TIM_Cmd(TIM1, DISABLE);  
	}
}
























