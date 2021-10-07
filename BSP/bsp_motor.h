#ifndef _BSP_MOTOR_H
#define _BSP_MOTOR_H
//时钟 数字 abc
#include "stm32f4xx.h" 
//前电机pwm  时钟 
#define Head_Motor_PWM_RCC		 RCC_AHB1Periph_GPIOE

//后电机pwm 时钟
#define Back_Motor_PWM_RCC		 RCC_AHB1Periph_GPIOB
//-----------------------------------------------------------


//前电机pwm  引脚
#define Head_Motor_PWM_Port		GPIOE


//后电机pwm 引脚
#define Back_Motor_PWM_Port		GPIOB
//-----------------------------------------------------------


//左右前电机pwm  数字
		 
#define Left_Head_Motor_PWM_Pin		    GPIO_Pin_5
#define Right_Head_Motor_PWM_Pin        GPIO_Pin_6

//左右后电机pwm  数字
		 
#define Left_Back_Motor_PWM_Pin		    GPIO_Pin_14
#define Right_Back_Motor_PWM_Pin        GPIO_Pin_15
//-----------------------------------------------------------
//-----------------------------------------------------------







//左前电机ab相时钟
#define Left_Head_MotorA_RCC        RCC_AHB1Periph_GPIOC
#define Left_Head_MotorB_RCC        RCC_AHB1Periph_GPIOE


//右前电机ab相时钟
#define Rigth_Head_MotorA_RCC       RCC_AHB1Periph_GPIOC
#define Rigth_Head_MotorB_RCC       RCC_AHB1Periph_GPIOC


//左前电机ab相数字 控制方向
#define Left_Head_MotoA_Pin 	 GPIO_Pin_13
#define Left_Head_MotoB_Pin 	 GPIO_Pin_4

//右前电机ab相数字 控制方向
#define Right_Head_MotoA_Pin	 GPIO_Pin_14
#define Right_Head_MotoB_Pin     GPIO_Pin_15

//左后电机ab相数字 控制方向 
#define Left_Back_MotoA_Pin	 GPIO_Pin_8
#define Left_Back_MotoB_Pin	 GPIO_Pin_10

//右后电机ab相数字 控制方向
#define Right_Back_MotoA_Pin	 GPIO_Pin_11
#define Right_Back_MotoB_Pin	 GPIO_Pin_9

//-----------------------------------------
//左前电机ab相 引脚
#define Left_Head_MotorA_Port		GPIOC
#define Left_Head_MotorB_Port		GPIOE

//右前电机ab相 引脚
#define Right_Head_MotorA_Port		GPIOC
#define Right_Head_MotorB_Port		GPIOC

//左后电机ab相 引脚
#define Left_Back_MotorA_Port		GPIOD
#define Left_Back_MotorB_Port		GPIOD

//右后电机ab相 引脚
#define Right_Back_MotorA_Port		GPIOD
#define Right_Back_MotorB_Port		GPIOD

void MOTOR_GPIO_Init(void);
void Motor_PWM_Init(u32 arr,u32 psc);
;




#endif
