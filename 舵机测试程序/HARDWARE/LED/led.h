#ifndef __LED_H
#define __LED_H

#define LED_D3_OFF GPIO_SetBits(GPIOC, GPIO_Pin_13)
#define LED_D3_ON GPIO_ResetBits(GPIOC, GPIO_Pin_13)
#define LED_D3_STATUS GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13)
#define LED_STATUS_ON 0
#define LED_STATUS_OFF 1


void LED_Init(void);


#endif

