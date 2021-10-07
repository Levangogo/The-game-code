#ifndef __APP_LINEWALKING_H__
#define __APP_LINEWALKING_H__	
void app_LineWalking(void);
void Left_Head_SetPWM(int pwm);
void Right_Head_SetPWM(int pwm);
void Left_Back_SetPWM(int pwm);
void Right_Back_SetPWM(int pwm);
void car_go(int pwm1,int pwm2,int pwm3,int pwm4);

#define LIGHT		(0)
#define DARK	(1)

#endif

