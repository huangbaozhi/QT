#ifndef __MOTO_H
#define __MOTO_H

#include "stm32f10x.h"

#define GO    0//定义电机状态 前进
#define BACK  1//后退
#define STOP  2//停车

//配置电机驱动的四个引脚
#define MOTO_CLK  RCC_APB2Periph_GPIOB
#define MOTO_PORT GPIOB
#define MOTO_Pin1  GPIO_Pin_12
#define MOTO_Pin2  GPIO_Pin_13
#define MOTO_Pin3  GPIO_Pin_14
#define MOTO_Pin4  GPIO_Pin_15

/* 带参宏，可以像内联函数一样使用 */
#define IN1(a)	if (a)	\
					GPIO_SetBits(MOTO_PORT,MOTO_Pin1);\
					else		\
					GPIO_ResetBits(MOTO_PORT,MOTO_Pin1)
					
#define IN2(a)	if (a)	\
					GPIO_SetBits(MOTO_PORT,MOTO_Pin2);\
					else		\
					GPIO_ResetBits(MOTO_PORT,MOTO_Pin2)
					
#define IN3(a)	if (a)	\
					GPIO_SetBits(MOTO_PORT,MOTO_Pin3);\
					else		\
					GPIO_ResetBits(MOTO_PORT,MOTO_Pin3)
					
#define IN4(a)	if (a)	\
					GPIO_SetBits(MOTO_PORT,MOTO_Pin4);\
					else		\
					GPIO_ResetBits(MOTO_PORT,MOTO_Pin4)

void MOTO_GPIO_Config(void);
					
void MOTO_Z(char state);
void MOTO_Y(char state);					
void Car_Go(void);
void Car_Back(void);
void Car_Turn_Right(void);
void Car_Turn_Left(void);
void Car_Stop(void);
					
#endif
