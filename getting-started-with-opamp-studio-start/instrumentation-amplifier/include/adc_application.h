/*
 * adc.h
 *
 * Created: 16-Jun-20 10:57:45
 *  Author: M52422
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc_basic.h"
#include "tcb.h"
#include "usart_application.h"

#define ADC_SAMPLE_TIMER      TCB1

#define ADC_SAMPLE_TIMER_vect TCB1_INT_vect

#define ADC_SAMPLES           ADC_SAMPNUM_ACC8_gc

#define ADC_MILI_VOLTAGE_REF  (3300)

void ADC_cb();

void ADC0_SampleTimer_enable(void);

#endif /* ADC_H_ */