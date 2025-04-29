/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: Header file for the LED driver
 *
 ******************************************************************************/

#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                                Types & Definitions                          *
 *******************************************************************************/

/* Enum to define LED IDs */
typedef enum
{
	RED = 0, /* Red LED connected to pin 0 */
	GREEN,   /* Green LED connected to pin 1 */
	BLUE     /* Blue LED connected to pin 2 */
} LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initializes the LED pins as output and turns them off initially.
 */
void LEDS_init(void);

/*
 * Description:
 * Turns on the specified LED by setting the corresponding pin to HIGH.
 *
 * Parameters:
 *    - id: The ID of the LED to turn on (RED_LED, GREEN_LED, or BLUE_LED).
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Turns off the specified LED by setting the corresponding pin to LOW.
 *
 * Parameters:
 *    - id: The ID of the LED to turn off (RED_LED, GREEN_LED, or BLUE_LED).
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
