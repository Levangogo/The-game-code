#include "main.h"

void MOTOR_GPIO_Init(void)//ǰ�����ҵķ������ų�ʼ��
{		
    //����ab���ʼ��
   	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(Left_Head_MotorA_RCC, ENABLE); //ǰ�����ҵ����ʼ��
    RCC_AHB1PeriphClockCmd(Left_Head_MotorB_RCC, ENABLE); 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); //������ab��ʱ��  

    //�ĸ�����
    GPIO_InitStructure.GPIO_Pin=Left_Head_MotoA_Pin;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT; //����ģʽΪ���ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed= GPIO_Speed_100MHz;
	GPIO_Init(Left_Head_MotorA_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    GPIO_InitStructure.GPIO_Pin=Left_Head_MotoB_Pin;
	GPIO_Init(Left_Head_MotorB_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������

    GPIO_InitStructure.GPIO_Pin=Right_Head_MotoA_Pin;  
	GPIO_Init(Right_Head_MotorA_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    GPIO_InitStructure.GPIO_Pin=Right_Head_MotoB_Pin;      
	GPIO_Init(Right_Head_MotorB_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    GPIO_InitStructure.GPIO_Pin=Left_Back_MotoA_Pin;      
	GPIO_Init(Left_Back_MotorA_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    GPIO_InitStructure.GPIO_Pin=Left_Back_MotoB_Pin;      
	GPIO_Init(Left_Back_MotorB_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
  
    GPIO_InitStructure.GPIO_Pin=Right_Back_MotoA_Pin;      
	GPIO_Init(Right_Back_MotorA_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    GPIO_InitStructure.GPIO_Pin=Right_Back_MotoB_Pin;      
	GPIO_Init(Right_Back_MotorB_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    GPIO_ResetBits(Left_Head_MotorA_Port,Left_Head_MotoA_Pin);
    GPIO_ResetBits(Left_Head_MotorB_Port,Left_Head_MotoB_Pin);
    GPIO_ResetBits(Right_Head_MotorA_Port,Right_Head_MotoA_Pin);
    GPIO_ResetBits(Right_Head_MotorB_Port,Right_Head_MotoB_Pin);
    
    GPIO_ResetBits(Left_Back_MotorA_Port,Left_Back_MotoA_Pin);
    GPIO_ResetBits(Left_Back_MotorB_Port,Left_Back_MotoB_Pin);
    GPIO_ResetBits(Right_Back_MotorA_Port,Right_Back_MotoA_Pin);
    GPIO_ResetBits(Right_Back_MotorB_Port,Right_Back_MotoB_Pin);
    
    
    
}


void Motor_PWM_Init(u32 arr,u32 psc)//ǰ������
{  
   	GPIO_InitTypeDef GPIO_InitStructure; //����һ�����ų�ʼ���Ľṹ��
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //����һ����ʱ�жϵĽṹ��  ʱ��
	TIM_OCInitTypeDef TIM_OCInitTypeStrue; //����һ�� PWM ����Ľṹ��
    RCC_AHB1PeriphClockCmd(Head_Motor_PWM_RCC,ENABLE);//���ҵĵ����ʱ����һ����
    RCC_AHB1PeriphClockCmd(Back_Motor_PWM_RCC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE); //ʹ��ͨ�ö�ʱ�� 9 ʱ�� ǰ�ֶ�ʱ��ͨ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE); //ʹ��ͨ�ö�ʱ�� 12 ʱ�� ���ֶ�ʱ��ͨ��
//	GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM8);

    GPIO_PinAFConfig(Head_Motor_PWM_Port,GPIO_PinSource5,GPIO_AF_TIM9);
    GPIO_PinAFConfig(Head_Motor_PWM_Port,GPIO_PinSource6,GPIO_AF_TIM9);

    GPIO_PinAFConfig(Back_Motor_PWM_Port,GPIO_PinSource14,GPIO_AF_TIM12);
    GPIO_PinAFConfig(Back_Motor_PWM_Port,GPIO_PinSource15,GPIO_AF_TIM12);

    GPIO_InitStructure.GPIO_Pin=Left_Head_Motor_PWM_Pin|Right_Head_Motor_PWM_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF; //����ģʽΪ���ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_100MHz; 
	GPIO_Init(Head_Motor_PWM_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������

    GPIO_InitStructure.GPIO_Pin=Left_Back_Motor_PWM_Pin|Right_Back_Motor_PWM_Pin;
	GPIO_Init(Back_Motor_PWM_Port, &GPIO_InitStructure); //�����������úõ� GPIO_InitStructure��������ʼ������
    
    TIM_TimeBaseInitStrue.TIM_Period=arr; //����ģʽΪ���ϼ���ʱ�� ��ʱ���� 0 ��ʼ������ ���������� arr ʱ������ʱ�жϷ�����
    TIM_TimeBaseInitStrue.TIM_Prescaler=psc; //Ԥ��Ƶϵ���� ����ÿһ��������ʱ��
    TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; //����ģʽ�� ���ϼ���
    TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1; //һ�㲻ʹ�ã� Ĭ��TIM_CKD_DIV1
    TIM_TimeBaseInit(TIM9, &TIM_TimeBaseInitStrue); //���� TIM_TimeBaseInitStrue  ֱ�Ӹ���·pwmͨ��ͬһ��arr��psc
    TIM_TimeBaseInit(TIM12,&TIM_TimeBaseInitStrue);
    
    TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1; //PWM ģʽ 1�� ����ʱ������С
    TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; //�����Ч��ƽΪ���� TIM_Pulse ʱ�� ��ʱ����Ӧ IO �����Ч��ƽ
    TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; //ʹ�� PWM ���
    TIM_OCInitTypeStrue.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
    TIM_OC1Init(TIM9, &TIM_OCInitTypeStrue);
    TIM_OC2Init(TIM9, &TIM_OCInitTypeStrue);
    TIM_OC1Init(TIM12, &TIM_OCInitTypeStrue);
    TIM_OC2Init(TIM12, &TIM_OCInitTypeStrue);
    TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable); //CH2 Ԥװ��ʹ�ܣ� ʹ�ܺ�ı� TIM_Pulse(�� PWM)��ֵ������Ч�� ��ʹ�����¸�������Ч
    TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable); //CH2 Ԥװ��ʹ�ܣ� ʹ�ܺ�ı� TIM_Pulse(�� PWM)��ֵ������Ч�� ��ʹ�����¸�������Ч
    TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable); //CH2 Ԥװ��ʹ�ܣ� ʹ�ܺ�ı� TIM_Pulse(�� PWM)��ֵ������Ч�� ��ʹ�����¸�������Ч
    TIM_OC2PreloadConfig(TIM12, TIM_OCPreload_Enable); //CH2 Ԥװ��ʹ�ܣ� ʹ�ܺ�ı� TIM_Pulse(�� PWM)��ֵ������Ч�� ��ʹ�����¸�������Ч
    TIM_ARRPreloadConfig(TIM9, ENABLE); //TIM12 Ԥװ��ʹ��
    TIM_ARRPreloadConfig(TIM12, ENABLE); //TIM12 Ԥװ��ʹ��
    TIM_Cmd(TIM9, ENABLE); //ʹ�ܶ�ʱ�� TIM12  ��ʱ���ǵø�
    TIM_Cmd(TIM12, ENABLE); //ʹ�ܶ�ʱ�� TIM12  ��ʱ���ǵø�
}


