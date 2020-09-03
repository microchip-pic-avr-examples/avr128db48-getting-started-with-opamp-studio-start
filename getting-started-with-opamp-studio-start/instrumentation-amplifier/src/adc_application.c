/*
 * adc.c
 *
 * Created: 16-Jun-20 10:57:20
 *  Author: M52422
 */ 

#include "adc_application.h"

extern data_visualizer data_stream;


void ADC_cb()
{
    data_stream.data_available = 1;
    data_stream.opampVal = ((int16_t)ADC0.RES >> ADC_SAMPLES)*(ADC_MILI_VOLTAGE_REF/1000); // divide by sample to get result, then multiply by ADC voltage ref and 2 to get the same scale as the DAC 
    DS_start_data_transmit();
}

void ADC0_SampleTimer_enable(void)
{
    ADC_SAMPLE_TIMER.CTRLA |= TCB_ENABLE_bm;
}

ISR(ADC_SAMPLE_TIMER_vect)
{
    if(!(USART3.CTRLA & USART_DREIE_bm)) {
        ADC_0_start_conversion(ADC_MUXPOS_AIN10_gc);
    }
    
    /* Clear interrupt flag */
    ADC_SAMPLE_TIMER.INTFLAGS = TCB_CAPT_bm;
}