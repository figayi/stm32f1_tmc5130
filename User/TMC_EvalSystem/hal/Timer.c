#include "HAL.h"
#include "Timer.h"

#define TIMER_MAX  10000

static void init(void);
static void deInit(void);
static void setDuty(uint16);
static uint16 getDuty(void);

TimerTypeDef Timer =
{
	.init     = init,
	.deInit   = deInit,
	.setDuty  = setDuty,
	.getDuty  = getDuty
};

static void init(void)
{
	TIM_DeInit(TIM1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	TIM1->CNT    = 0;

	TIM1->CR1    = 0;
	TIM1->CR1    |= TIM_CR1_ARPE;

	TIM1->DIER   = 1<<3; // no interrupt

	TIM1->CCMR2  = 0;
	TIM1->CCMR2  |= TIM_CCMR2_OC3PE;  // preload enable
	TIM1->CCMR2  |= TIM_OCMode_PWM1;  // ch3 PWM1

	TIM1->CCER   = 0;
	TIM1->CCER   |= TIM_CCER_CC3E;

	TIM1->ARR    = TIMER_MAX;       // period
	TIM1->CCR3   = TIMER_MAX >> 1;  // duty
	TIM1->PSC    = 0;

	TIM1->BDTR   = 0;
	TIM1->BDTR   |= TIM_BDTR_MOE;
	TIM1->BDTR   |= TIM_BDTR_AOE;

	TIM1->EGR    = 1;
	TIM1->CR1    |= TIM_CR1_CEN;
}

static void deInit(void)
{
	TIM_DeInit(TIM1);
}

static void setDuty(uint16 duty)
{
	 TIM1->CCR3 = (duty < TIMER_MAX) ? duty : TIMER_MAX;
}

static uint16 getDuty()
{
	 return TIM1->CCR3;
}
