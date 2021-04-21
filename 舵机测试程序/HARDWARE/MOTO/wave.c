//����������
//PB9----Echo  ���ջز�
//PB8----Trig  ����������

#include "wave.h"
#include "delay.h"
#include "bsp_timer2.h"

u16 Distance=0;
u8 OB_L =0,OB_M=0,OB_R=0;//�ϰ���λ�ñ��
//�������˿ڳ�ʼ��
void Wave_IO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	       
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);//PB3��PB4����
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); //�ر�JTAG���ܣ�
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					       //PB8��TRIG
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		     //��Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
	GPIO_Init(GPIOB, &GPIO_InitStructure);	                 //��ʼ������GPIO 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				         //PB9��ECH0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		 //��Ϊ����
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM2_NVIC_Configuration();//��ʱ����ʼ��
	TIM2_Configuration();			
}



//���
//��ʼ��࣬����һ��>10us�����壬Ȼ��������صĸߵ�ƽʱ��
u16 Wave_Start(void)
{
	u16  Distance;
  Wave_ON();  		  //��>10US�ĸߵ�ƽ
  Delay_us(20);		                      //��ʱ20US
  Wave_OFF();
  
  while(!Wave_State());	             //�ȴ��ߵ�ƽ
  TIM_Cmd(TIM2, ENABLE);             //����ʱ��
  while(Wave_State());	             //�ȴ��͵�ƽ
  TIM_Cmd(TIM2, DISABLE);			                             //��ʱ��2ʧ��
  Distance=TIM_GetCounter(TIM2)*5*34/2000;								 //�������	����cm
  TIM_SetCounter(TIM2,0);	
  return Distance;
}

//�趨���Ͼ���25cm
void Wave_BZ(void)
{
 Distance = Wave_Start(); 
	   if((Distance < 25) && (Distance != 0))
	   {
			Car_Stop();//ͣ��
			OB_M=1;//����м����ϰ���
			TIM_SetCompare1(TIM1,50);//���ת���Ҷ�
			Duoji_Control(ON);
			Delay_ms(500);//
			Duoji_Control(OFF);

			Distance = Wave_Start();//�����Ҷ��Ƿ����ϰ���


			if((Distance < 25) && (Distance != 0))//�����
			{
				Car_Stop();//ͣ��
				OB_R=1;//����Ҷ����ϰ���
			}
			else
			{
				OB_R=0;//����Ҷ�û���ϰ���
			}

			TIM_SetCompare1(TIM1,105);//���ת�����
			Duoji_Control(ON);
			Delay_ms(500);//
			Duoji_Control(OFF);

			Distance = Wave_Start();//�����Ҷ��Ƿ����ϰ���


			if((Distance < 25) && (Distance != 0))//�����
			{
				Car_Stop();//ͣ��
				OB_L=1;//����Ҷ����ϰ���

			}
			else
			{
				OB_L=0;//����Ҷ�û���ϰ���
			}


			TIM_SetCompare1(TIM1,75);;//���ת���м�
			Duoji_Control(ON);
			Delay_ms(500);//
			Duoji_Control  (OFF);



	   }
	   else 
	   {
	   	Car_Go();
	   }
	   
	   if((OB_L==0)&&(OB_M==0)&&(OB_R==0))//û���ϰ���
	   {
	   		Car_Go();OB_L=0; OB_M=0; OB_R=0;

	   }
	   if((OB_L==0)&&(OB_M==1)&&(OB_R==0))//�м��ϰ���
	   {	
	   		OB_L=0; OB_M=0; OB_R=0;
				Car_Back();
			Delay_ms(500);//ת180�ȴ��Լ���
	   		Car_Turn_Right();
			Delay_ms(200);//��ת
		//	Delay_ms(500);//��ת
			Car_Go();
	   }
	   if((OB_L==0)&&(OB_M==1)&&(OB_R==1))//�м���ұ��ϰ���
	   {
	   		OB_L=0; OB_M=0; OB_R=0;
			Car_Back();
			Delay_ms(500);//ת180�ȴ��Լ���
	   		Car_Turn_Left();
			Delay_ms(200);//��ת
			//Delay_ms(500);//ת
			Car_Go();
	   }
	   if((OB_L==1)&&(OB_M==1)&&(OB_R==0))//�м������ϰ���
	   {
	   		OB_L=0; OB_M=0; OB_R=0;
				Car_Back();
			Delay_ms(500);//ת180�ȣ����Լ���
	   		Car_Turn_Right();
			Delay_ms(200);//��ת
		//	Delay_ms(500);//��ת
			Car_Go();
	   }
	   if((OB_L==1)&&(OB_M==1)&&(OB_R==1))//�м������ұ߶����ϰ���
	   {
	   		OB_L=0; OB_M=0; OB_R=0;
			Car_Back();
			Delay_ms(500);//ת180��
	   		Car_Turn_Right();
			Delay_ms(800);//ת180��
			//Delay_ms(800);//ת180��
			Car_Go();
	   }

	 }
