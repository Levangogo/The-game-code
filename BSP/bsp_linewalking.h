
/*

	从车身后面往前看： 左侧到右边巡线传感器顺序为  L1 L2 |黑线| R1  R2	  

*/

#ifndef __BSP_LINEWALKING_H__
#define __BSP_LINEWALKING_H__	

#define USE_LINE_L1
#define USE_LINE_L2
#define USE_LINE_R1
#define USE_LINE_R2

#define LineWalk_L1_RCC		RCC_AHB1Periph_GPIOF
#define LineWalk_L2_RCC		RCC_AHB1Periph_GPIOF
#define LineWalk_R1_RCC    	RCC_AHB1Periph_GPIOC
#define LineWalk_R2_RCC		RCC_AHB1Periph_GPIOA

#define LineWalk_L1_PIN		GPIO_Pin_9
#define LineWalk_L2_PIN		GPIO_Pin_8
#define LineWalk_R1_PIN		GPIO_Pin_8
#define LineWalk_R2_PIN		GPIO_Pin_1

#define LineWalk_L1_PORT	GPIOF
#define LineWalk_L2_PORT	GPIOF
#define LineWalk_R1_PORT	GPIOC
#define LineWalk_R2_PORT	GPIOA


void bsp_GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2);



#endif
