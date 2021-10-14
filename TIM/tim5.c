#include "main.h"
extern TASK_COUNTER Task_Counter;

/*TIM5��ʼ������*/
void TIM5_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Prescaler = 16800 - 1;	//10KHz����Ƶ��
	TIM_TimeBaseStructure.TIM_Period = 10 - 1;			//������10Ϊ1ms
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE );			//ʹ���ж�
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			 //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM5, ENABLE);		//ʹ��TIM6
}


extern TASK_COUNTER Task_Counter;
/*TIM5�жϷ�����*/
void TIM5_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)//���TIM6�����ж��Ƿ���
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);	//����жϱ�־
        Task_Counter.task_counter_60000ms++;
	}
}



