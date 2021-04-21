#ifndef __BSP_TIMER3_H
#define __BSP_TIMER3_H


#include "stm32f10x.h"
void Timer3_Init(u32 arr,int psc);
void MOTO_PWM_Init(u32 arr, int psc);
void MOTO_PWM_Out(u16 moto_r, u16 moto_l);




#endif

