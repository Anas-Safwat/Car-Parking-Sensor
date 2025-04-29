/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.c
 *
 * Description: Source file for the LED driver
 *
 ******************************************************************************/

#include "led.h"
#include "../GPIO/gpio.h" /* To control GPIO pins */
#include "../COMMON_MACROS/common_macros.h" /* To use macros like BIT manipulation */
#include "avr/io.h" /* To access AVR registers */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Initializes the LED pins as output and ensures they are turned off initially.
 */
void LEDS_init(void)
{
	/* Set LED pins as output */
	GPIO_setupPinDirection(PORTC_ID, RED, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, GREEN, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, BLUE, PIN_OUTPUT);

	/* Turn off all LEDs initially */
	LED_off(RED);
	LED_off(GREEN);
	LED_off(BLUE);
}

/*
 * Description:
 * Turns on the specified LED by writing HIGH to the corresponding GPIO pin.
 *
 * Parameters:
 *    - id: The ID of the LED to turn on (RED_LED, GREEN_LED, or BLUE_LED).
 */
void LED_on(LED_ID id)
{
	GPIO_writePin(PORTC_ID, id, LOGIC_HIGH);
}

/*
 * Description:
 * Turns off the specified LED by writing LOW to the corresponding GPIO pin.
 *
 * Parameters:
 *    - id: The ID of the LED to turn off (RED_LED, GREEN_LED, or BLUE_LED).
 */
void LED_off(LED_ID id)
{
	GPIO_writePin(PORTC_ID, id, LOGIC_LOW);
}
