#include "stm32f10x.h"                  // Device header
#include "Delay.h"


uint8_t l;
uint8_t PWM1_Mode;
uint8_t PWM2_Mode;

uint16_t PWM1_Count;
extern int m;

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitTypeDef GPIO_InitStruture;
	GPIO_InitStruture.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruture.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 ;
	GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruture);
	
	
	TIM_InternalClockConfig(TIM2);
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;     //ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;   //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruture;
	TIM_TimeBaseInitStruture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruture.TIM_Period = 100 - 1;     //ARR
	TIM_TimeBaseInitStruture.TIM_Prescaler = 720 - 1;   //PSC
	TIM_TimeBaseInitStruture.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruture);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;    //CCR
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	TIM_Cmd(TIM3, ENABLE);

}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2, Compare);
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);
}
void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM2, Compare);
}

void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM2, Compare);
}

void PWM_SetCompare5(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare);
}

void PWM_SetCompare6(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare);
}

void PWM_SetCompare7(uint16_t Compare)
{
	TIM_SetCompare3(TIM3, Compare);
}

void PWM_SetCompare8(uint16_t Compare)
{
	TIM_SetCompare4(TIM3, Compare);
}


void PWM_1(void)
{
			Delay_ms(500);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare1(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare2(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare3(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare4(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare5(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare6(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare7(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare8(l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare8(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare7(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare6(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare5(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare4(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare3(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare2(100 - l);
				Delay_ms(10);
			}
			Delay_ms(100);
			for (l = 0;l <= 100; l++)
			{
				PWM_SetCompare1(100 - l);
				Delay_ms(10);
			}
			Delay_ms(500);
}

void PWM_2(void)
{
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare1(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare1(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare2(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare2(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare3(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare3(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare4(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare4(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare5(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare5(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare6(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare6(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare7(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare7(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare8(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare8(100 - l);
			Delay_ms(10);
		}
}

void PWM_0(void)
{
		PWM_SetCompare1(100);
		PWM_SetCompare3(100);
		PWM_SetCompare5(100);
		PWM_SetCompare7(100);
		Delay_ms(500);
		PWM_SetCompare1(0);
		PWM_SetCompare3(0);
		PWM_SetCompare5(0);
		PWM_SetCompare7(0);
		Delay_ms(500);
		PWM_SetCompare1(100);
		PWM_SetCompare3(100);
		PWM_SetCompare5(100);
		PWM_SetCompare7(100);
		Delay_ms(500);
		PWM_SetCompare1(0);
		PWM_SetCompare3(0);
		PWM_SetCompare5(0);
		PWM_SetCompare7(0);
		Delay_ms(500);
		PWM_SetCompare2(100);
		PWM_SetCompare4(100);
		PWM_SetCompare6(100);
		PWM_SetCompare8(100);
		Delay_ms(500);
		PWM_SetCompare2(0);
		PWM_SetCompare4(0);
		PWM_SetCompare6(0);
		PWM_SetCompare8(0);
		Delay_ms(500);
		PWM_SetCompare2(100);
		PWM_SetCompare4(100);
		PWM_SetCompare6(100);
		PWM_SetCompare8(100);
		Delay_ms(500);
		PWM_SetCompare2(0);
		PWM_SetCompare4(0);
		PWM_SetCompare6(0);
		PWM_SetCompare8(0);
		Delay_ms(500);
}

void PWM_3(void)
{
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare8(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare8(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare7(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare7(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare6(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare6(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare5(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare5(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare4(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare4(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare3(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare3(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare2(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare2(100 - l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare1(l);
			Delay_ms(10);
		}
		for (l = 0;l <= 100; l++)
		{
			PWM_SetCompare1(100 - l);
			Delay_ms(10);
		}
}

void PWM_4(void)
{
		PWM_SetCompare1(100);
		PWM_SetCompare2(100);
		PWM_SetCompare3(100);
		PWM_SetCompare4(100);
		PWM_SetCompare5(100);
		PWM_SetCompare6(100);
		PWM_SetCompare7(100);
		PWM_SetCompare8(100);
}
	
void PWM_5(void)
{
		PWM_SetCompare1(0);
		PWM_SetCompare2(0);
		PWM_SetCompare3(0);
		PWM_SetCompare4(0);
		PWM_SetCompare5(0);
		PWM_SetCompare6(0);
		PWM_SetCompare7(0);
		PWM_SetCompare8(0);
}

void PWM_6(void)
{
		PWM_SetCompare1(100);
		PWM_SetCompare2(100);
		PWM_SetCompare3(100);
		PWM_SetCompare4(100);
		PWM_SetCompare5(100);
		PWM_SetCompare6(100);
		PWM_SetCompare7(100);
		PWM_SetCompare8(100);
		Delay_ms(100);
		PWM_SetCompare1(0);
		PWM_SetCompare2(0);
		PWM_SetCompare3(0);
		PWM_SetCompare4(0);
		PWM_SetCompare5(0);
		PWM_SetCompare6(0);
		PWM_SetCompare7(0);
		PWM_SetCompare8(0);
		Delay_ms(100);
		PWM_SetCompare1(100);
		PWM_SetCompare2(100);
		PWM_SetCompare3(100);
		PWM_SetCompare4(100);
		PWM_SetCompare5(100);
		PWM_SetCompare6(100);
		PWM_SetCompare7(100);
		PWM_SetCompare8(100);
		Delay_ms(100);
		PWM_SetCompare1(0);
		PWM_SetCompare2(0);
		PWM_SetCompare3(0);
		PWM_SetCompare4(0);
		PWM_SetCompare5(0);
		PWM_SetCompare6(0);
		PWM_SetCompare7(0);
		PWM_SetCompare8(0);
}
