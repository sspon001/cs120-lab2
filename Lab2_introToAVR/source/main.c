/*	Author: sspon001
 *  Partner(s) Name: 
 *	Lab Section:001
 *	Assignment: Lab #2  Exercise #1
 *	
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00 ; PORTA = 0xFF ;
	DDRB = 0xFF ; PORTB = 0x00 ;
	unsigned char doorOpen = 0x00 ;
	unsigned char lightDetected = 0x00 ;
    while (1) {
	doorOpen = PINA & 0x01 ;
	lightDetected = PINA & 0x02 ;
	if(doorOpen & !lightDetected) PORTB = 0x01 ;
	else PORTB = 0x00 ;
    }
    return 0 ;
}
