/******************************************************************************
 *
 * Module: Ultrasonic Sensor
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the Ultrasonic sensor driver.
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../STD_TYPES/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the echo and trigger pins and their port */
#define ULTRASONIC_TRIG_PORT_ID   PORTD_ID
#define ULTRASONIC_TRIG_PIN_ID    PIN7_ID

#define ULTRASONIC_ECHO_PORT_ID   PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID    PIN6_ID

/* Speed of sound in air (in cm/s) */
#define SOUND_SPEED  34000

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initialize the ultrasonic sensor by setting up the ICU driver,
 * and configuring the trigger pin as output.
 */
void Ultrasonic_init(void);

/*
 * Description:
 * Sends a trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void);

/*
 * Description:
 * Initiates the measurement process by sending a trigger pulse and reading
 * the distance via the ICU driver.
 * Returns the measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description:
 * This is the callback function that is called by the ICU driver.
 * It calculates the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
