#include "main.h"
void bsp_init(void)//延时 pwm 
{
	delay_init(168);
	MOTOR_GPIO_Init();  				/*电机GPIO初始化 pwm*/  
	Motor_PWM_Init(16800-1,0);	/*不分频。PWM频率 168000000/16800=10khz	  */
	LineWalking_GPIO_Init();			/*巡线传感器初始化*/


}


