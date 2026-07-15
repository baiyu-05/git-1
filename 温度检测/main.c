#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"

int16_t AX, AY, AZ, GX, GY, GZ, Tm;
uint8_t ID;
int16_t WenDu;


int main(void)
{
	OLED_Init();
	
	MPU6050_Init();
	
//	MPU6050_WriteReg(0x6B, 0x00);
//	MPU6050_WriteReg(0x19, 0xBB);
//	uint8_t ID;
//	ID = MPU6050_ReadReg(0x19);
//	OLED_ShowHexNum(1, 1,ID ,2);
	OLED_ShowString(1, 1, "ID:");
	ID = MPU6050_GetID();
	OLED_ShowHexNum(1, 4, ID,2);
	
	
	while (1)
	{
//		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
//		OLED_ShowSignedNum(2, 1, AX, 5);
//		OLED_ShowSignedNum(3, 1, AY, 5);
//		OLED_ShowSignedNum(4, 1, AZ, 5);
//		OLED_ShowSignedNum(2, 8, GX, 5);
//		OLED_ShowSignedNum(3, 8, GX, 5);
//		OLED_ShowSignedNum(4, 8, GX, 5);
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ, &Tm);
		OLED_ShowSignedNum(3, 1, Tm, 5);
		OLED_ShowString(2, 1, "WenDu:");
		OLED_ShowString(2, 13, "'C");
		float WenDu =  (float)Tm / 340.0f + 36.5f;
		OLED_ShowFloat(2, 7, WenDu, 2, 2);
	}
}
