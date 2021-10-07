#include "main.h"

void LineWalking_GPIO_Init(void)
{
    //时钟 引脚宏定义
    #ifdef USE_LINE_L1
    /*定义一个GPIO_InitTypeDef类型的结构体*///pa1 
	GPIO_InitTypeDef GPIO_InitStructure;
    /*开启外设时钟*/
	RCC_AHB1PeriphClockCmd(LineWalk_L1_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_L1_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	/*调用库函数，初始化PORT*/
  	GPIO_Init(LineWalk_L1_PORT, &GPIO_InitStructure);		
#endif

    #ifdef USE_LINE_L2
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(LineWalk_L2_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_L2_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	/*调用库函数，初始化PORT*/
  	GPIO_Init(LineWalk_L2_PORT, &GPIO_InitStructure);	
#endif

#ifdef USE_LINE_R1
	/*开启外设时钟*/
	RCC_AHB1PeriphClockCmd(LineWalk_R1_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_R1_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	/*调用库函数，初始化PORT*/
  	GPIO_Init(LineWalk_R1_PORT, &GPIO_InitStructure);	
#endif
	
#ifdef USE_LINE_R2
	/*开启外设时钟*/
	RCC_AHB1PeriphClockCmd(LineWalk_R2_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_R2_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	/*调用库函数，初始化PORT*/
  	GPIO_Init(LineWalk_R2_PORT, &GPIO_InitStructure);	
#endif

}

