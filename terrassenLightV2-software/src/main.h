#pragma once

#define LED1 D1
#define LED2 D2
#define LED3 D3

#define BUTTON1 D5
#define BUTTON2 D6
#define BUTTON3 D7

void led1ISR();
void led2ISR();
void led3ISR();

/*! \mainpage Mainpage
 *
 * \section Overview
 *
 * Creates 3 Led Objects and corresponding ISR.
 *
 * Logging is handled by Logger
 *
 *
 */