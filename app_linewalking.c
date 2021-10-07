#include "main.h"
void Left_Head_SetPWM(int pwm)//左前轮  -16799<pwm<16799  负值的话  逆时针 前
{
   if(pwm>=0)
	{
	PCout(13)=0; //BIN1=0
	PEout(4)=1; //BIN2=1
	TIM9->CCR1=pwm;
	TIM_SetCompare1(TIM9, pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) 反转 顺时针
	{
	PCout(13)=1; //BIN1=1   //引脚记得改
	PEout(4)=0; //BIN2=0
	TIM9->CCR1=-pwm;
	TIM_SetCompare1(TIM9, -pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	}

}


void Right_Head_SetPWM(int pwm)//左前轮  -16799<pwm<16799 负值的话往前走  顺时针 
{
   if(pwm>=0)//pwm>=0 (BIN1, BIN2)=(0, 1) 正转 逆时针
	{
	PCout(14)=0; //BIN1=0
	PCout(15)=1; //BIN2=1
	TIM9->CCR2=pwm;
	TIM_SetCompare2(TIM9, pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) 反转 顺时针
	{
	PCout(14)=1; //BIN1=1   //引脚记得改
	PCout(15)=0; //BIN2=0
	TIM9->CCR2=-pwm;
	TIM_SetCompare2(TIM9, -pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	}

}

void Left_Back_SetPWM(int pwm)//左后轮  -16799<pwm<16799 负值的话往前走
{
   if(pwm>=0)//pwm>=0 (BIN1, BIN2)=(0, 1) 正转 逆时针
	{
	PDout(8)=0; //BIN1=0
	PDout(10)=1; //BIN2=1
	TIM12->CCR1=pwm;
	TIM_SetCompare1(TIM12, pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) 反转 顺时针
	{
	PDout(8)=1; //BIN1=0
	PDout(10)=0; //BIN2=1
	TIM12->CCR1=-pwm;
	TIM_SetCompare1(TIM12, -pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	}

}

void Right_Back_SetPWM(int pwm)//右后轮  -16799<pwm<16799 负值的话往前走
{
   if(pwm>=0)//pwm>=0 (BIN1, BIN2)=(0, 1) 正转 逆时针
	{
	PDout(11)=0; //BIN1=0
	PDout(9)=1; //BIN2=1
	TIM12->CCR2=pwm;
	TIM_SetCompare2(TIM12, pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) 反转 顺时针
	{
	PDout(11)=1; //BIN1=0
	PDout(9)=0; //BIN2=1
	TIM12->CCR2=-pwm;
	TIM_SetCompare2(TIM12, -pwm);  //可改变TIM_OCInitTypeStrue.TIM_Pulse
	}

}


void car_go(int pwm1,int pwm2,int pwm3,int pwm4)//里面加负号是使正号往前走
{
    Left_Head_SetPWM(-pwm1);
    Right_Head_SetPWM(-pwm2);
    Left_Back_SetPWM(-pwm3);
    Right_Back_SetPWM(-pwm4);

}


void app_LineWalking(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;
//GPIO_ReadInputDataBit
	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	//获取黑线检测状态	 检测到黑线时为低
    //左二 右一都识别到，直走
    if(LineL2==DARK&&LineR1==DARK)
    {
       car_go(8000,8000,8000,8000);
       
    }
    
    if((LineL1&&LineL2&&LineR1&&LineR2)==DARK)
    {
       car_go(10000,10000,10000,10000);   
    }
    if((LineL1&&LineL2&&LineR1&&LineR2)==LIGHT)
    {
       car_go(10000,10000,10000,10000);
    
    }

    if(LineL2==DARK&&LineR1==LIGHT)//左拐
    {
       car_go(-5000,6000,-5000,6000);
       delay_ms(20);
    
    }	
    if(LineL2==LIGHT&&LineR1==DARK)//右拐
    {
       car_go(6000,-5000,6000,-5000);
       delay_ms(20);

    }	
        
}

