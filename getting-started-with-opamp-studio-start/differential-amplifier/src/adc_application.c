/*
 * \file adc_application.c
 *
 * \brief ADC Application source file.
 *
 *  (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 *  Subject to your compliance with these terms,you may use this software and
 *  any derivatives exclusively with Microchip products.It is your responsibility
 *  to comply with third party license terms applicable to your use of third party
 *  software (including open source software) that may accompany Microchip software.
 *
 *  THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 *  EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 *  WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 *  PARTICULAR PURPOSE.
 *
 *  IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 *  INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 *  WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 *  BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 *  FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 *  ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 *  THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 */

#include "adc_application.h"

extern data_visualizer data_stream;


void ADC_cb()
{
    data_stream.data_available = 1;
    data_stream.diff_output = ((int16_t)ADC0.RES >> ADC_SAMPLES)*(ADC_MILI_VOLTAGE_REF/1000)*2; // divide by sample to get result, then multiply by ADC voltage ref and 2 to get the same scale as the DAC 
    DS_start_data_transmit();
}

void ADC0_SampleTimer_enable(void)
{
    ADC_SAMPLE_TIMER.CTRLA |= TCB_ENABLE_bm;
}

ISR(ADC_SAMPLE_TIMER_vect)
{
    if(!(USART3.CTRLA & USART_DREIE_bm)) {
        ADC_0_start_diff_conversion(ADC_MUXPOS_AIN5_gc,ADC_MUXNEG_AIN6_gc);
    }
    
    /* Clear interrupt flag */
    ADC_SAMPLE_TIMER.INTFLAGS = TCB_CAPT_bm;
}