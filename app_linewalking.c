#include "main.h"
void Left_Head_SetPWM(int pwm)//��ǰ��  -16799<pwm<16799  ��ֵ�Ļ�  ��ʱ�� ǰ
{
   if(pwm>=0)
	{
	PCout(13)=0; //BIN1=0
	PEout(4)=1; //BIN2=1
	TIM9->CCR1=pwm;
	TIM_SetCompare1(TIM9, pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) ��ת ˳ʱ��
	{
	PCout(13)=1; //BIN1=1   //���żǵø�
	PEout(4)=0; //BIN2=0
	TIM9->CCR1=-pwm;
	TIM_SetCompare1(TIM9, -pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	}

}


void Right_Head_SetPWM(int pwm)//��ǰ��  -16799<pwm<16799 ��ֵ�Ļ���ǰ��  ˳ʱ�� 
{
   if(pwm>=0)//pwm>=0 (BIN1, BIN2)=(0, 1) ��ת ��ʱ��
	{
	PCout(14)=0; //BIN1=0
	PCout(15)=1; //BIN2=1
	TIM9->CCR2=pwm;
	TIM_SetCompare2(TIM9, pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) ��ת ˳ʱ��
	{
	PCout(14)=1; //BIN1=1   //���żǵø�
	PCout(15)=0; //BIN2=0
	TIM9->CCR2=-pwm;
	TIM_SetCompare2(TIM9, -pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	}

}

void Left_Back_SetPWM(int pwm)//�����  -16799<pwm<16799 ��ֵ�Ļ���ǰ��
{
   if(pwm>=0)//pwm>=0 (BIN1, BIN2)=(0, 1) ��ת ��ʱ��
	{
	PDout(8)=0; //BIN1=0
	PDout(10)=1; //BIN2=1
	TIM12->CCR1=pwm;
	TIM_SetCompare1(TIM12, pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) ��ת ˳ʱ��
	{
	PDout(8)=1; //BIN1=0
	PDout(10)=0; //BIN2=1
	TIM12->CCR1=-pwm;
	TIM_SetCompare1(TIM12, -pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	}

}

void Right_Back_SetPWM(int pwm)//�Һ���  -16799<pwm<16799 ��ֵ�Ļ���ǰ��
{
   if(pwm>=0)//pwm>=0 (BIN1, BIN2)=(0, 1) ��ת ��ʱ��
	{
	PDout(11)=0; //BIN1=0
	PDout(9)=1; //BIN2=1
	TIM12->CCR2=pwm;
	TIM_SetCompare2(TIM12, pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	} 
	else if(pwm<0)//pwm<0 (BIN1, BIN2)=(1, 0) ��ת ˳ʱ��
	{
	PDout(11)=1; //BIN1=0
	PDout(9)=0; //BIN2=1
	TIM12->CCR2=-pwm;
	TIM_SetCompare2(TIM12, -pwm);  //�ɸı�TIM_OCInitTypeStrue.TIM_Pulse
	}

}


void car_go(int pwm1,int pwm2,int pwm3,int pwm4)//����Ӹ�����ʹ������ǰ��
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
	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	//��ȡ���߼��״̬	 ��⵽����ʱΪ��
    //��� ��һ��ʶ�𵽣�ֱ��
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

    if(LineL2==DARK&&LineR1==LIGHT)//���
    {
       car_go(-5000,6000,-5000,6000);
       delay_ms(20);
    
    }	
    if(LineL2==LIGHT&&LineR1==DARK)//�ҹ�
    {
       car_go(6000,-5000,6000,-5000);
       delay_ms(20);

    }	
        
}

