#include "main.h"
void bsp_init(void)//��ʱ pwm 
{
	delay_init(168);
	MOTOR_GPIO_Init();  				/*���GPIO��ʼ�� pwm*/  
	Motor_PWM_Init(16800-1,0);	/*����Ƶ��PWMƵ�� 168000000/16800=10khz	  */
	LineWalking_GPIO_Init();			/*Ѳ�ߴ�������ʼ��*/


}


