/*
********************************************************************************************************
文件名：bsp_timer3.c
功  能：adc的配置
备  注：电机控制pwm,用到了timer3的ch3和ch4，即 PB0-PB1连接电机驱动的使能端INB（右电机） 和 INA（左电机）
淘  宝：https://shop60670850.taobao.com
作  者：lilianhe
日  期: 2017-2-6
*********************************************************************************************************
*/


#include "bsp_timer3.h"

//***************************定时器初始化***************************//
// TIM_Period / Auto Reload Register(ARR) = 1000   TIM_Prescaler--71 
//arr：自动重装寄存器，psc分频系数
//PWM的频率 = 72MHz/ARR/PCS 例如  20K = 72M/3600/1 =  20K
 
void Timer3_Init(u32 arr,int psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Period = arr-1;//自动重新装载寄存器周期的值澹ㄥ计数值澹)
	TIM_TimeBaseStructure.TIM_Prescaler = psc;//时钟分频系数
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//对外部时钟进行采样的时钟分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);//参数初始化

	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	//TIM_Cmd(TIM4, ENABLE);//启动定时器 
	
}



//***************************PWM频率及占空比初始化***************************//
//=====初始化PWM 20KHZ 高频可以防止电机低频时的尖叫声
// ARR= 3599 时频率为20Khz
//PB8控制PWMA--right moto，PB9控制PWMB--left moto。STBY直接拉高?
//arr：自动重装寄存器，psc分频系数
//PWM的频率 = 72MHz/ARR/PCS 例如  20K = 72M/3600/1 =  20K
void MOTO_PWM_Init(u32 arr, int psc)
{
	TIM_OCInitTypeDef TIM_OCInitSructure;
	GPIO_InitTypeDef    GPIO_InitStructure;
	//配置pwm输出端口
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0| GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // 复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	//初始化定时器
	Timer3_Init(arr,psc);//Init timer3
	//设置通道3 pwm参数
	TIM_OCInitSructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSructure.TIM_OutputState= TIM_OutputState_Enable;
	TIM_OCInitSructure.TIM_Pulse = 0;//占空比= 50/100
	TIM_OCInitSructure.TIM_OCPolarity = TIM_OCPolarity_High;//当定时器计数值小于CCR1_Val时为高电平
	TIM_OC3Init(TIM3, &TIM_OCInitSructure);//参数初始化
	TIM_OC3PolarityConfig(TIM3, TIM_OCPreload_Enable);//开始输出pwm

	//设置通道4 pwm参数
	TIM_OCInitSructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSructure.TIM_OutputState= TIM_OutputState_Enable;
	TIM_OCInitSructure.TIM_Pulse = 0;//占空比= 50/100
	TIM_OCInitSructure.TIM_OCPolarity = TIM_OCPolarity_High;//当定时器计数值小于CCR1_Val时为高电平
	TIM_OC4Init(TIM3, &TIM_OCInitSructure);//参数初始化
	TIM_OC4PolarityConfig(TIM3, TIM_OCPreload_Enable);//开始输出pwm

	TIM_ARRPreloadConfig(TIM3, ENABLE);//启动自动重装
	TIM_Cmd(TIM3, ENABLE);//启动定时	
}

//***************************占空比调节***************************//
//占空比 = TIMx_CCRx / TIMx_ARR
//moto_r：右轮电机，moto_l：左轮电机.   数值 0-100
void MOTO_PWM_Out(u16 moto_l, u16 moto_r)
{
	
	TIM_OCInitTypeDef TIM_OCInitSructure;
	
	TIM_OCInitSructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSructure.TIM_OutputState= TIM_OutputState_Enable;
	//CH3 左电机
	TIM_OCInitSructure.TIM_Pulse = moto_l;//占空比= ccr/100
	TIM_OC3Init(TIM3, &TIM_OCInitSructure);//参数初始化
	TIM_OC3PolarityConfig(TIM3, TIM_OCPreload_Enable);//开始输出pwm
	
	//CH4 右电机
	TIM_OCInitSructure.TIM_Pulse = moto_r;//占空比= ccr /100
	TIM_OC4Init(TIM3, &TIM_OCInitSructure);//参数初始化
	TIM_OC4PolarityConfig(TIM3, TIM_OCPreload_Enable);//开始输出pwm
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);//启动自动重装
	 
}	



