#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Buzzer_2.h"
#include "LED.h"
#include "Timer.h"

uint16_t i = 0;
uint8_t Key;
uint16_t m = 0;
uint8_t a = 0;
uint16_t b = 0;

int main(void)
{
	OLED_Init();
	PWM_Init();
	Key_Init();
	Buzzer_Init();
	Timer_Init();
	
	OLED_ShowString(1,1,"Time:");
	OLED_ShowString(2,1,"Mode:");
	OLED_ShowString(3,1,"Alarm:");
	OLED_ShowString(4,1,"Cycle:");
	
	while (1)
	{
		if(i == 2)
		{
			PWM_0();//4s
			m = 1;
		}
		if(i == 7)
		{
			PWM_1();//18s
			m = 2;
		}
		if(i == 27)
		{
			PWM_2();//17s
			m = 3;
		}
		if(i == 46)
		{
			PWM_3();//17s
			m = 4;
		}
		if(i == 65)
		{
			PWM_4();//1s
			m = 5;
		}
		if(i == 67)
		{
			PWM_5();//3s
			m = 6;
		}
		if(i == 70)
		{
			i = 0;
			m = 0;
			TIM_Cmd(TIM4, DISABLE);
			b++;
		}
		if(Key_GetState() == 1)
		{
			TIM_Cmd(TIM4, ENABLE);
		}
		if(Key_GetState() == 2)
		{
			Buzzer_ON();
			Delay_ms(200);
			Buzzer_OFF();
			Buzzer_ON();
			Delay_ms(200);
			Buzzer_OFF();
			PWM_6();
			a++;
			if (a > 5)
				a = 0;
			TIM_Cmd(TIM4, DISABLE);
		}
		OLED_ShowNum(1,6,i,5);
		OLED_ShowNum(2,6,m,1);
		OLED_ShowNum(3,7,a,1);
		OLED_ShowNum(4,7,b,1);
	}
}
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		i++;
		Key_Tick();
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}	
