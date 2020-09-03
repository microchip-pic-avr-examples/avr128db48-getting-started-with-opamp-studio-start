/*
 * usart.h
 *
 * Created: 16-Jun-20 11:28:46
 *  Author: M52422
 */ 


#ifndef USART_H_
#define USART_H_

#include "usart_basic.h"

#define START_TOKEN     0x55

typedef struct __attribute__((__packed__)) {
    uint8_t start_token;   /* Start token for the data streamer protocol */
    int16_t diff_input;    /* Differential signal between DAC and VDDDIV2 used as input to OPAMPs */
    int16_t opampVal;      /* Output from the Instrumentation Amplifier */
    uint8_t end_token;     /* End token for the data streamer protocol */
    uint8_t data_available; /*Flag indicating if data is ready to be streamed to data visualizer */
}data_visualizer;

data_visualizer data_stream;

void DS_start_data_transmit(void);
void set_up_data_stream(void);



#endif /* USART_H_ */