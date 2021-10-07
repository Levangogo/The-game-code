#include "main.h"

void MOTOR_GPIO_Init(void)//前面左右的方向引脚初始化
{		
    //左电机ab相初始化
   	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(Left_Head_MotorA_RCC, ENABLE); //前面左右电机初始化
    RCC_AHB1PeriphClockCmd(Left_Head_MotorB_RCC, ENABLE); 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); //后面电机ab相时钟  

    //四个引脚
    GPIO_InitStructure.GPIO_Pin=Left_Head_MotoA_Pin;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT; //引脚模式为输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed= GPIO_Speed_100MHz;
	GPIO_Init(Left_Head_MotorA_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    GPIO_InitStructure.GPIO_Pin=Left_Head_MotoB_Pin;
	GPIO_Init(Left_Head_MotorB_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚

    GPIO_InitStructure.GPIO_Pin=Right_Head_MotoA_Pin;  
	GPIO_Init(Right_Head_MotorA_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    GPIO_InitStructure.GPIO_Pin=Right_Head_MotoB_Pin;      
	GPIO_Init(Right_Head_MotorB_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    GPIO_InitStructure.GPIO_Pin=Left_Back_MotoA_Pin;      
	GPIO_Init(Left_Back_MotorA_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    GPIO_InitStructure.GPIO_Pin=Left_Back_MotoB_Pin;      
	GPIO_Init(Left_Back_MotorB_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
  
    GPIO_InitStructure.GPIO_Pin=Right_Back_MotoA_Pin;      
	GPIO_Init(Right_Back_MotorA_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    GPIO_InitStructure.GPIO_Pin=Right_Back_MotoB_Pin;      
	GPIO_Init(Right_Back_MotorB_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    GPIO_ResetBits(Left_Head_MotorA_Port,Left_Head_MotoA_Pin);
    GPIO_ResetBits(Left_Head_MotorB_Port,Left_Head_MotoB_Pin);
    GPIO_ResetBits(Right_Head_MotorA_Port,Right_Head_MotoA_Pin);
    GPIO_ResetBits(Right_Head_MotorB_Port,Right_Head_MotoB_Pin);
    
    GPIO_ResetBits(Left_Back_MotorA_Port,Left_Back_MotoA_Pin);
    GPIO_ResetBits(Left_Back_MotorB_Port,Left_Back_MotoB_Pin);
    GPIO_ResetBits(Right_Back_MotorA_Port,Right_Back_MotoA_Pin);
    GPIO_ResetBits(Right_Back_MotorB_Port,Right_Back_MotoB_Pin);
    
    
    
}


void Motor_PWM_Init(u32 arr,u32 psc)//前后两轮
{  
   	GPIO_InitTypeDef GPIO_InitStructure; //定义一个引脚初始化的结构体
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //定义一个定时中断的结构体  时基
	TIM_OCInitTypeDef TIM_OCInitTypeStrue; //定义一个 PWM 输出的结构体
    RCC_AHB1PeriphClockCmd(Head_Motor_PWM_RCC,ENABLE);//左右的电机的时钟是一样的
    RCC_AHB1PeriphClockCmd(Back_Motor_PWM_RCC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE); //使能通用定时器 9 时钟 前轮定时器通道
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE); //使能通用定时器 12 时钟 后轮定时器通道
//	GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM8);

    GPIO_PinAFConfig(Head_Motor_PWM_Port,GPIO_PinSource5,GPIO_AF_TIM9);
    GPIO_PinAFConfig(Head_Motor_PWM_Port,GPIO_PinSource6,GPIO_AF_TIM9);

    GPIO_PinAFConfig(Back_Motor_PWM_Port,GPIO_PinSource14,GPIO_AF_TIM12);
    GPIO_PinAFConfig(Back_Motor_PWM_Port,GPIO_PinSource15,GPIO_AF_TIM12);

    GPIO_InitStructure.GPIO_Pin=Left_Head_Motor_PWM_Pin|Right_Head_Motor_PWM_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF; //引脚模式为输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_100MHz; 
	GPIO_Init(Head_Motor_PWM_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚

    GPIO_InitStructure.GPIO_Pin=Left_Back_Motor_PWM_Pin|Right_Back_Motor_PWM_Pin;
	GPIO_Init(Back_Motor_PWM_Port, &GPIO_InitStructure); //根据上面设置好的 GPIO_InitStructure参数，初始化引脚
    
    TIM_TimeBaseInitStrue.TIM_Period=arr; //计数模式为向上计数时， 定时器从 0 开始计数， 计数超过到 arr 时触发定时中断服务函数
    TIM_TimeBaseInitStrue.TIM_Prescaler=psc; //预分频系数， 决定每一个计数的时长
    TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; //计数模式： 向上计数
    TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1; //一般不使用， 默认TIM_CKD_DIV1
    TIM_TimeBaseInit(TIM9, &TIM_TimeBaseInitStrue); //根据 TIM_TimeBaseInitStrue  直接给两路pwm通道同一个arr和psc
    TIM_TimeBaseInit(TIM12,&TIM_TimeBaseInitStrue);
    
    TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1; //PWM 模式 1， 当定时器计数小
    TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; //输出有效电平为高于 TIM_Pulse 时， 定时器对应 IO 输出有效电平
    TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; //使能 PWM 输出
    TIM_OCInitTypeStrue.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
    TIM_OC1Init(TIM9, &TIM_OCInitTypeStrue);
    TIM_OC2Init(TIM9, &TIM_OCInitTypeStrue);
    TIM_OC1Init(TIM12, &TIM_OCInitTypeStrue);
    TIM_OC2Init(TIM12, &TIM_OCInitTypeStrue);
    TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable); //CH2 预装载使能， 使能后改变 TIM_Pulse(即 PWM)的值立刻生效， 不使能则下个周期生效
    TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable); //CH2 预装载使能， 使能后改变 TIM_Pulse(即 PWM)的值立刻生效， 不使能则下个周期生效
    TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable); //CH2 预装载使能， 使能后改变 TIM_Pulse(即 PWM)的值立刻生效， 不使能则下个周期生效
    TIM_OC2PreloadConfig(TIM12, TIM_OCPreload_Enable); //CH2 预装载使能， 使能后改变 TIM_Pulse(即 PWM)的值立刻生效， 不使能则下个周期生效
    TIM_ARRPreloadConfig(TIM9, ENABLE); //TIM12 预装载使能
    TIM_ARRPreloadConfig(TIM12, ENABLE); //TIM12 预装载使能
    TIM_Cmd(TIM9, ENABLE); //使能定时器 TIM12  定时器记得改
    TIM_Cmd(TIM12, ENABLE); //使能定时器 TIM12  定时器记得改
}


