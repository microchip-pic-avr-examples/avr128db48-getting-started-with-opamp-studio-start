#include <atmel_start.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "adc.h"
#include "rtc.h"
#include "dac.h"
#include "usart.h"
#include "rtc_application.h"




int main(void)
{
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();
    
    /* Sets up the ADC result ready callback */
    ADC_0_register_callback(&ADC_cb);
    
    /* Creates a table with values for the DAC to create a sin wave, see dac.h for sin wave spesifications */
    sin_wave_table_init();
    
    /* Adds the start and end token to the data streamer struct*/
    set_up_data_stream();
    
    /* Enable the timer used to create the sin wave */
    DAC0_SineWaveTimer_enable();
    
    /* Enable the timer used to trigger a new ADC measurement */
    ADC0_SampleTimer_enable();
    
    /* RTC is used to Blink LED at 0.5s = PER (511) / (32768 / 32) */
    RTC_enable();
    
    /* Enables global interrupts */
    sei();
    
    /* Replace with your application code */
    while (1) {
    }
}