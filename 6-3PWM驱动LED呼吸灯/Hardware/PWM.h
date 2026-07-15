#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetCompare2(uint16_t Compare);
void PWM_SetCompare3(uint16_t Compare);
void PWM_SetCompare4(uint16_t Compare);
void PWM_SetCompare5(uint16_t Compare);
void PWM_SetCompare6(uint16_t Compare);
void PWM_SetCompare7(uint16_t Compare);
void PWM_SetCompare8(uint16_t Compare);
void PWM_1(void);
void PWM_2(void);
void PWM_3(void);
void PWM_4(void);
void PWM_5(void);
void PWM_6(void);
void PWM_0(void);
void PWM1_SetMode(uint8_t Mode);
void PWM_Tick(void);
#endif
