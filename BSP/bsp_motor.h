#ifndef _BSP_MOTOR_H
#define _BSP_MOTOR_H
//ʱ�� ���� abc
#include "stm32f4xx.h" 
//ǰ���pwm  ʱ�� 
#define Head_Motor_PWM_RCC		 RCC_AHB1Periph_GPIOE

//����pwm ʱ��
#define Back_Motor_PWM_RCC		 RCC_AHB1Periph_GPIOB
//-----------------------------------------------------------


//ǰ���pwm  ����
#define Head_Motor_PWM_Port		GPIOE


//����pwm ����
#define Back_Motor_PWM_Port		GPIOB
//-----------------------------------------------------------


//����ǰ���pwm  ����
		 
#define Left_Head_Motor_PWM_Pin		    GPIO_Pin_5
#define Right_Head_Motor_PWM_Pin        GPIO_Pin_6

//���Һ���pwm  ����
		 
#define Left_Back_Motor_PWM_Pin		    GPIO_Pin_14
#define Right_Back_Motor_PWM_Pin        GPIO_Pin_15
//-----------------------------------------------------------
//-----------------------------------------------------------







//��ǰ���ab��ʱ��
#define Left_Head_MotorA_RCC        RCC_AHB1Periph_GPIOC
#define Left_Head_MotorB_RCC        RCC_AHB1Periph_GPIOE


//��ǰ���ab��ʱ��
#define Rigth_Head_MotorA_RCC       RCC_AHB1Periph_GPIOC
#define Rigth_Head_MotorB_RCC       RCC_AHB1Periph_GPIOC


//��ǰ���ab������ ���Ʒ���
#define Left_Head_MotoA_Pin 	 GPIO_Pin_13
#define Left_Head_MotoB_Pin 	 GPIO_Pin_4

//��ǰ���ab������ ���Ʒ���
#define Right_Head_MotoA_Pin	 GPIO_Pin_14
#define Right_Head_MotoB_Pin     GPIO_Pin_15

//�����ab������ ���Ʒ��� 
#define Left_Back_MotoA_Pin	 GPIO_Pin_8
#define Left_Back_MotoB_Pin	 GPIO_Pin_10

//�Һ���ab������ ���Ʒ���
#define Right_Back_MotoA_Pin	 GPIO_Pin_11
#define Right_Back_MotoB_Pin	 GPIO_Pin_9

//-----------------------------------------
//��ǰ���ab�� ����
#define Left_Head_MotorA_Port		GPIOC
#define Left_Head_MotorB_Port		GPIOE

//��ǰ���ab�� ����
#define Right_Head_MotorA_Port		GPIOC
#define Right_Head_MotorB_Port		GPIOC

//�����ab�� ����
#define Left_Back_MotorA_Port		GPIOD
#define Left_Back_MotorB_Port		GPIOD

//�Һ���ab�� ����
#define Right_Back_MotorA_Port		GPIOD
#define Right_Back_MotorB_Port		GPIOD

void MOTOR_GPIO_Init(void);
void Motor_PWM_Init(u32 arr,u32 psc);
;




#endif
