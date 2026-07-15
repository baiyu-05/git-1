#include "stm32f10x.h"                  // Device header

void LED_Init(void)//LED初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//选择推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_7;//选中1号或2号口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//选择50M速度
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA外设
	
	GPIO_InitTypeDef GPIO_InitStruture;//定义结构体
	GPIO_InitStruture.GPIO_Mode = GPIO_Mode_AF_PP;//选择复用推挽输出
	GPIO_InitStruture.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 ;
	GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;//选择50M速度
	GPIO_Init(GPIOB, &GPIO_InitStruture);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_7);//让LED灯初始状态为关
	GPIO_SetBits(GPIOB, GPIO_Pin_0 |GPIO_Pin_1);
}

void LED_Mode1(void) //点亮LED灯
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_7);
	GPIO_ResetBits(GPIOB, GPIO_Pin_0 |GPIO_Pin_1);
}

void LED_Mode2(void)//关闭LED灯
{
	GPIO_SetBits(GPIOA, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_7);
	GPIO_SetBits(GPIOB, GPIO_Pin_0 |GPIO_Pin_1);
}
