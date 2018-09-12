#include "HAL.h"
#include "SysTick.h"

static __IO u32 TimingDelay;
volatile u32 systick = 0;

uint16_t g_run_cnt       = 0;
uint8_t  g_second        = 0;
uint8_t  g_key_ld        = 0;
uint8_t  g_key_ld_cnt    = 0;
uint8_t  g_key_ru        = 0;
uint8_t  g_key_ru_cnt    = 0;
uint8_t  g_key_zero      = 0;
uint8_t  g_key_zero_cnt  = 0;

#define  KEY_V_ZERO GPIO_Pin_13
#define  KEY_V_LD   GPIO_Pin_14
#define  KEY_V_RU   GPIO_Pin_15

#define KEY_SHORT_PRESS   10   //10*2ms=20ms
#define KEY_LONG_PRESS    750  //750*2ms=1.5S

uint8_t vInKeyStatic = 0;

void __attribute__ ((interrupt)) SysTick_Handler(void);

void SysTick_Handler(void)
{
	systick_task();
}

void systick_init(void)
{
    /* SystemFrequency / 1000    1ms�ж�һ��
     * SystemFrequency / 100000  10us�ж�һ��
     * SystemFrequency / 1000000 1us�ж�һ��
     */
    if (SysTick_Config(SystemCoreClock / 500))   // ST3.5.0��汾,2ms����һ�εδ��ж�
    { 
        /* Capture error */ 
        while (1);
    }
    // �رյδ�ʱ��  
//    SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;

}

u32 systick_getTick()
{
	return systick;
}

void delay_ms(uint32 delay)
{
#ifdef __EBOS__
  	TimingDelay = delay;
	
  	while(TimingDelay > 0)
    {
		    ;
	}
#endif
    uint32 startTick = systick;
	while((systick-startTick) <= delay) {}
}

void key_scan(void)
{
    if ((GPIOC->IDR&KEY_V_ZERO) == 0)  //KEY_V_ZERO����
    {
        if (g_key_zero == 0) //���������Ϊ0
        {	
            if (g_key_zero_cnt >= KEY_SHORT_PRESS) //����ֵ�ﵽһ��ֵ�����Ϊ��������(������е����)
            {
                    g_key_zero = 1;//�������±�־
                    vInKeyStatic |= KEY_ZERO;//����ֵ,�Զ���
            }
            else 
            {
                    g_key_zero_cnt++;	//�δ�ʱ������
            }
        }
    }
    else   //KEY_V_ZERO�ɿ�
    {
            g_key_zero = 0;
            g_key_zero_cnt  = 0;
    }
    
    if ((GPIOC->IDR&KEY_LD) == 0)  //KEY_LD����
    {
        if (g_key_ld == 0) //���������Ϊ0
        {	
            if (g_key_ld_cnt >= KEY_SHORT_PRESS) //����ֵ�ﵽһ��ֵ�����Ϊ��������(������е����)
            {
                    g_key_ld = 1;//�������±�־
                    vInKeyStatic |= KEY_LD;//����ֵ,�Զ���
            }
            else 
            {
                    g_key_ld_cnt++;	//�δ�ʱ������
            }
        }
    }
    else   //KEY_V_ZERO�ɿ�
    {
            g_key_ld = 0;
            g_key_ld_cnt  = 0;
    }

    if ((GPIOC->IDR&KEY_RU) == 0)  //KEY_RU����
    {
        if (g_key_ru == 0) //���������Ϊ0
        {	
            if (g_key_ru_cnt >= KEY_SHORT_PRESS) //����ֵ�ﵽһ��ֵ�����Ϊ��������(������е����)
            {
                    g_key_ru = 1;//�������±�־
                    vInKeyStatic |= KEY_RU;//����ֵ,�Զ���
            }
            else 
            {
                    g_key_ru_cnt++;	//�δ�ʱ������
            }
        }
    }
    else   //KEY_V_ZERO�ɿ�
    {
            g_key_ru = 0;
            g_key_ru_cnt  = 0;
    }
}

void systick_task(void)
{	
#ifdef __EBOS__
    if (TimingDelay > 0) 
    {
        TimingDelay--;		
    }
#endif
    systick++;

    g_run_cnt++;
    if(g_run_cnt == 250) 
    { 
        //GPIOC->ODR ^= GPIO_Pin_4;
        g_second = 1;
        g_run_cnt = 0;
    }
     
    key_scan();	

    WWDG_SetCounter(127);  // Update WWDG counter
}
