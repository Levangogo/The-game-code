#include "main.h"
int main(void)
 {		
 		bsp_init();
     while (1)
	{
//        Left_Head_SetPWM(-10000);
//        Right_Head_SetPWM(-10000);
//        Left_Back_SetPWM(-10000);
//        Right_Back_SetPWM(-10000);
        //Car_Run(3000);
         //car_go(10000,-10000,10000,10000);//负后，前正
		app_LineWalking();	
        delay_ms(50);
	}
     

 }

