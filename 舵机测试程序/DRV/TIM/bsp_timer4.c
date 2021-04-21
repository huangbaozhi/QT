/*
********************************************************************************************************
ÎÄ¼þÃû£ºbsp_timer4.c
¹¦  ÄÜ£ºadcµÄÅäÖÃ
±¸  ×¢£ºµç»ú¿ØÖÆpwm,ÓÃµ½ÁËtimer4µÄch3ºÍch4
ÌÔ  ±¦£ºhttps://shop60670850.taobao.com
×÷  Õß£ºlilianhe
ÈÕ  ÆÚ: 2017-2-6
*********************************************************************************************************
*/


#include "bsp_timer4.h"

//***************************¶¨Ê±Æ÷³õÊ¼»¯***************************//
// TIM_Period / Auto Reload Register(ARR) = 1000   TIM_Prescaler--71 
//arr£º×Ô¶¯ÖØ×°¼Ä´æÆ÷£¬psc·ÖÆµÏµÊý
//PWMµÄÆµÂÊ = 72MHz/ARR/PCS ÀýÈç  20K = 72M/3600/1 =  20K
 
void Timer4_Init(u32 arr,int psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Period = arr-1;//×Ô¶¯ÖØÐÂ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµå£¨å¼ÆÊýÖµå£)
	TIM_TimeBaseStructure.TIM_Prescaler = psc;//Ê±ÖÓ·ÖÆµÏµÊý
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//¶ÔÍâ²¿Ê±ÖÓ½øÐÐ²ÉÑùµÄÊ±ÖÓ·ÖÆµ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//ÏòÉÏ¼ÆÊý
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);//²ÎÊý³õÊ¼»¯

	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

	//TIM_Cmd(TIM4, ENABLE);//Æô¶¯¶¨Ê±Æ÷ 
	
}



//***************************PWMÆµÂÊ¼°Õ¼¿Õ±È³õÊ¼»¯***************************//
//=====³õÊ¼»¯PWM 20KHZ ¸ßÆµ¿ÉÒÔ·ÀÖ¹µç»úµÍÆµÊ±µÄ¼â½ÐÉù
// ARR= 3599 Ê±ÆµÂÊÎª20Khz
//PB8¿ØÖÆPWMA--right moto£¬PB9¿ØÖÆPWMB--left moto¡£STBYÖ±½ÓÀ­¸ß¡
//arr£º×Ô¶¯ÖØ×°¼Ä´æÆ÷£¬psc·ÖÆµÏµÊý
//PWMµÄÆµÂÊ = 72MHz/ARR/PCS ÀýÈç  20K = 72M/3600/1 =  20K
void MOTO_PWM_Init(u32 arr, int psc)
{
	TIM_OCInitTypeDef TIM_OCInitSructure;
	GPIO_InitTypeDef    GPIO_InitStructure;
	//ÅäÖÃpwmÊä³ö¶Ë¿Ú
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8| GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // ¸´ÓÃÍÆÍìÊä³ö
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	//³õÊ¼»¯¶¨Ê±Æ÷
	Timer4_Init(arr,psc);//Init timer4
	//ÉèÖÃÍ¨µÀ3 pwm²ÎÊý
	TIM_OCInitSructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSructure.TIM_OutputState= TIM_OutputState_Enable;
	TIM_OCInitSructure.TIM_Pulse = 50;//Õ¼¿Õ±È= 50/100
	TIM_OCInitSructure.TIM_OCPolarity = TIM_OCPolarity_High;//µ±¶¨Ê±Æ÷¼ÆÊýÖµÐ¡ÓÚCCR1_ValÊ±Îª¸ßµçÆ½
	TIM_OC3Init(TIM4, &TIM_OCInitSructure);//²ÎÊý³õÊ¼»¯
	TIM_OC3PolarityConfig(TIM4, TIM_OCPreload_Enable);//¿ªÊ¼Êä³öpwm

	//ÉèÖÃÍ¨µÀ4 pwm²ÎÊý
	TIM_OCInitSructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSructure.TIM_OutputState= TIM_OutputState_Enable;
	TIM_OCInitSructure.TIM_Pulse = 50;//Õ¼¿Õ±È= 50/100
	TIM_OCInitSructure.TIM_OCPolarity = TIM_OCPolarity_High;//µ±¶¨Ê±Æ÷¼ÆÊýÖµÐ¡ÓÚCCR1_ValÊ±Îª¸ßµçÆ½
	TIM_OC4Init(TIM4, &TIM_OCInitSructure);//²ÎÊý³õÊ¼»¯
	TIM_OC4PolarityConfig(TIM4, TIM_OCPreload_Enable);//¿ªÊ¼Êä³öpwm

	TIM_ARRPreloadConfig(TIM4, ENABLE);//Æô¶¯×Ô¶¯ÖØ×°
	TIM_Cmd(TIM4, ENABLE);//Æô¶¯¶¨Ê±	
}

//***************************Õ¼¿Õ±Èµ÷½Ú***************************//
//Õ¼¿Õ±È = TIMx_CCRx / TIMx_ARR
//moto_r£ºÓÒÂÖµç»ú£¬moto_l£º×óÂÖµç»ú.   ÊýÖµ 0-100
void MOTO_PWM_Out(u16 moto_r, u16 moto_l)
{
	TIM_OCInitTypeDef TIM_OCInitSructure;
	TIM_OCInitSructure.TIM_Pulse = moto_r;//Õ¼¿Õ±È= ccr/100
	TIM_OC3Init(TIM4, &TIM_OCInitSructure);//²ÎÊý³õÊ¼»¯
	TIM_OC3PolarityConfig(TIM4, TIM_OCPreload_Enable);//¿ªÊ¼Êä³öpwm
	
	TIM_OCInitSructure.TIM_Pulse = moto_l;//Õ¼¿Õ±È= ccr /100
	TIM_OCInitSructure.TIM_OCPolarity = TIM_OCPolarity_High;//µ±¶¨Ê±Æ÷¼ÆÊýÖµÐ¡ÓÚCCR1_ValÊ±Îª¸ßµçÆ½
	TIM_OC4Init(TIM4, &TIM_OCInitSructure);//²ÎÊý³õÊ¼»¯
	TIM_OC4PolarityConfig(TIM4, TIM_OCPreload_Enable);//¿ªÊ¼Êä³öpwm
	 
}	




