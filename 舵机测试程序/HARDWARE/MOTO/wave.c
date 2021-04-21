//超声波例程
//PB9----Echo  接收回波
//PB8----Trig  超声波发射

#include "wave.h"
#include "delay.h"
#include "bsp_timer2.h"

u16 Distance=0;
u8 OB_L =0,OB_M=0,OB_R=0;//障碍物位置标记
//超声波端口初始化
void Wave_IO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	       
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);//PB3，PB4复用
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); //关闭JTAG功能，
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					       //PB8接TRIG
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		     //设为推挽输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
	GPIO_Init(GPIOB, &GPIO_InitStructure);	                 //初始化外设GPIO 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				         //PB9接ECH0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		 //设为输入
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM2_NVIC_Configuration();//定时器初始化
	TIM2_Configuration();			
}



//测距
//开始测距，发送一个>10us的脉冲，然后测量返回的高电平时间
u16 Wave_Start(void)
{
	u16  Distance;
  Wave_ON();  		  //送>10US的高电平
  Delay_us(20);		                      //延时20US
  Wave_OFF();
  
  while(!Wave_State());	             //等待高电平
  TIM_Cmd(TIM2, ENABLE);             //开启时钟
  while(Wave_State());	             //等待低电平
  TIM_Cmd(TIM2, DISABLE);			                             //定时器2失能
  Distance=TIM_GetCounter(TIM2)*5*34/2000;								 //计算距离	厘米cm
  TIM_SetCounter(TIM2,0);	
  return Distance;
}

//设定避障距离25cm
void Wave_BZ(void)
{
 Distance = Wave_Start(); 
	   if((Distance < 25) && (Distance != 0))
	   {
			Car_Stop();//停车
			OB_M=1;//标记中间有障碍物
			TIM_SetCompare1(TIM1,50);//舵机转到右端
			Duoji_Control(ON);
			Delay_ms(500);//
			Duoji_Control(OFF);

			Distance = Wave_Start();//测量右端是否有障碍物


			if((Distance < 25) && (Distance != 0))//如果有
			{
				Car_Stop();//停车
				OB_R=1;//标记右端有障碍物
			}
			else
			{
				OB_R=0;//标记右端没有障碍物
			}

			TIM_SetCompare1(TIM1,105);//舵机转到左端
			Duoji_Control(ON);
			Delay_ms(500);//
			Duoji_Control(OFF);

			Distance = Wave_Start();//测量右端是否有障碍物


			if((Distance < 25) && (Distance != 0))//如果有
			{
				Car_Stop();//停车
				OB_L=1;//标记右端有障碍物

			}
			else
			{
				OB_L=0;//标记右端没有障碍物
			}


			TIM_SetCompare1(TIM1,75);;//舵机转到中间
			Duoji_Control(ON);
			Delay_ms(500);//
			Duoji_Control  (OFF);



	   }
	   else 
	   {
	   	Car_Go();
	   }
	   
	   if((OB_L==0)&&(OB_M==0)&&(OB_R==0))//没有障碍物
	   {
	   		Car_Go();OB_L=0; OB_M=0; OB_R=0;

	   }
	   if((OB_L==0)&&(OB_M==1)&&(OB_R==0))//中间障碍物
	   {	
	   		OB_L=0; OB_M=0; OB_R=0;
				Car_Back();
			Delay_ms(500);//转180度粗略计算
	   		Car_Turn_Right();
			Delay_ms(200);//右转
		//	Delay_ms(500);//右转
			Car_Go();
	   }
	   if((OB_L==0)&&(OB_M==1)&&(OB_R==1))//中间和右边障碍物
	   {
	   		OB_L=0; OB_M=0; OB_R=0;
			Car_Back();
			Delay_ms(500);//转180度粗略计算
	   		Car_Turn_Left();
			Delay_ms(200);//左转
			//Delay_ms(500);//转
			Car_Go();
	   }
	   if((OB_L==1)&&(OB_M==1)&&(OB_R==0))//中间和左边障碍物
	   {
	   		OB_L=0; OB_M=0; OB_R=0;
				Car_Back();
			Delay_ms(500);//转180度，粗略计算
	   		Car_Turn_Right();
			Delay_ms(200);//右转
		//	Delay_ms(500);//右转
			Car_Go();
	   }
	   if((OB_L==1)&&(OB_M==1)&&(OB_R==1))//中间和左边右边都有障碍物
	   {
	   		OB_L=0; OB_M=0; OB_R=0;
			Car_Back();
			Delay_ms(500);//转180度
	   		Car_Turn_Right();
			Delay_ms(800);//转180度
			//Delay_ms(800);//转180度
			Car_Go();
	   }

	 }
