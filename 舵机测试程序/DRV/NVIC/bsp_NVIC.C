/*
********************************************************************************************************
文件名：bsp_NVIC.c
功  能：中断配置
备  注：
淘  宝：https://shop60670850.taobao.com
作  者：lilianhe
日  期: 2017-2-6
*********************************************************************************************************
*/

/*
********************************************************************************************************
更新日志：
1.2017-2-6,编写uart和time中断


*********************************************************************************************************
*/

#include "bsp_nvic.h"

/*
********************************************************************************************************
函数名称：void NVIC_Config(void)
函数功能：配置各个中断的优先级
硬件连接：
备    注：
日    期: 2017-2-6
*********************************************************************************************************
*/
void NVIC_Config(void)
{
	//NVIC_uart1_Config();
	//NVIC_TIM3_Config();
}

/*
********************************************************************************************************
函数名称：void NVIC_uart1_Config(void)
函数功能： 配置USART1接收中断
硬件连接：
备    注：
日    期: 2017-2-6
*********************************************************************************************************
*/
void NVIC_uart1_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/*
********************************************************************************************************
函数名称：void NVIC_TIM3_Config(void)
函数功能： 配置timer3的中断配置
硬件连接：
备    注：
日    期: 2017-2-6
*********************************************************************************************************
*/
void NVIC_TIM3_Config(void)
{
//	NVIC_InitTypeDef NVIC_InitStructure;

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
//	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}
//------------------End of File----------------------------
