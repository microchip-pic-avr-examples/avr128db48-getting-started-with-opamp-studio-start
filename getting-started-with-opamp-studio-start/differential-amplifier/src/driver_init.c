/**
 * \file
 *
 * \brief Driver initialization.
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/*
 * Code generated by START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <system.h>

/* Configure pins and initialize registers */
void OPERATIONAL_AMPLIFIER_0_initialization(void)
{

	// Disable digital input buffer
	PD3_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD3_set_pull_mode(PORT_PULL_OFF);

	// Disable digital input buffer
	PD1_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD1_set_pull_mode(PORT_PULL_OFF);

	// Disable digital input buffer
	PD7_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD7_set_pull_mode(PORT_PULL_OFF);

	// Disable digital input buffer
	PD4_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD4_set_pull_mode(PORT_PULL_OFF);

	// Disable digital input buffer
	PD5_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD5_set_pull_mode(PORT_PULL_OFF);

	OPERATIONAL_AMPLIFIER_0_init();
}

/* configure the pins and initialize the registers */
void USART_0_initialization(void)
{

	// Set pin direction to input
	PB1_set_dir(PORT_DIR_IN);

	PB1_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_OFF);

	// Set pin direction to output
	PB0_set_dir(PORT_DIR_OUT);

	PB0_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	USART_0_init();
}

/* configure pins and initialize registers */
void DAC_0_initialization(void)
{

	// Disable digital input buffer
	PD6_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD6_set_pull_mode(PORT_PULL_OFF);

	DAC_0_init();
}

/* Configure pins and initialize registers */
void ADC_0_initialization(void)
{

	// Disable digital input buffer
	PD2_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD2_set_pull_mode(PORT_PULL_OFF);

	ADC_0_init();
}

void SINE_WAVE_TIMER_initialization(void)
{

	SINE_WAVE_TIMER_init();
}

void ADC_SAMPLE_TIMER_initialization(void)
{

	ADC_SAMPLE_TIMER_init();
}

/**
 * \brief System initialization
 */
void system_init()
{
	mcu_init();

	/* PORT setting on PB3 */

	// Set pin direction to output
	LED0_set_dir(PORT_DIR_OUT);

	LED0_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	OPERATIONAL_AMPLIFIER_0_initialization();

	CLKCTRL_init();

	USART_0_initialization();

	SLPCTRL_init();

	CPUINT_init();

	DAC_0_initialization();

	ADC_0_initialization();

	RTC_0_init();

	SINE_WAVE_TIMER_initialization();

	ADC_SAMPLE_TIMER_initialization();

	VREF_0_init();

	BOD_init();
}
