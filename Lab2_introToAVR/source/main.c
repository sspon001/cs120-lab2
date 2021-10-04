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
	unsigned char cntavail = 0x04 ;
    while (1) {
        cntavail = 0x04 ;
	if(PINA & 0x01) cntavail -= 0x01 ;
	if(PINA & 0x02) cntavail -= 0x01 ;
	if(PINA & 0x04) cntavail -= 0x01 ;
	if(PINA & 0x08) cntavail -= 0x01 ;
	PORTC = cntavail ;
    }
    return 0 ;
}
