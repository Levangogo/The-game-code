#include "main.h"
/**
* Function       bsp_GetLineWalking
* @author        liwenkang
* @date          2021/10/4    
* @brief         ��ȡѲ��״̬
* @param[in]     int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2  ��·Ѳ��λָ��
* @param[out]    void
* @retval        void
* @par History   ��
*/

void bsp_GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2)
{
	*p_iL1 = GPIO_ReadInputDataBit(LineWalk_L1_PORT, LineWalk_L1_PIN);
	*p_iL2 = GPIO_ReadInputDataBit(LineWalk_L2_PORT, LineWalk_L2_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(LineWalk_R1_PORT, LineWalk_R1_PIN);
	*p_iR2 = GPIO_ReadInputDataBit(LineWalk_R2_PORT, LineWalk_R2_PIN);		
}

