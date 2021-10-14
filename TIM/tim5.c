#include "main.h"
extern TASK_COUNTER Task_Counter;

/*TIM5初始化函数*/
void TIM5_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Prescaler = 16800 - 1;	//10KHz计数频率
	TIM_TimeBaseStructure.TIM_Period = 10 - 1;			//计数到10为1ms
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE );			//使能中断
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			 //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM5, ENABLE);		//使能TIM6
}


extern TASK_COUNTER Task_Counter;
/*TIM5中断服务函数*/
void TIM5_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)//检查TIM6更新中断是否发生
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);	//清除中断标志
        Task_Counter.task_counter_60000ms++;
	}
}



