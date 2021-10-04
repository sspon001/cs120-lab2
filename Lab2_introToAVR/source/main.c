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
	DDRB = 0x00 ; PORTB = 0xFF ;
	DDRC = 0x00 ; PORTC = 0xFF ;
	DDRD = 0xFF ; PORTD = 0x00 ;
	unsigned char temp = 0x00 ;
	unsigned char temp2 = 0x00 ;
	unsigned char temp3 = 0x00 ;
	unsigned char a = 0x00 ;
	unsigned char b = 0x00 ;
	unsigned char c = 0x00 ;
	unsigned short totalWeight = 0x0000 ;
    while (1) {
	a = PINA ;
	b = PINB ;
	c = PINC ;
	if(a > c){
		if((a - c) > 0x50) temp2 = 0x02 ;
	}
	else{
		if((c - a) > 0x50) temp2 = 0x02 ;
	}
	totalWeight = a + b + c ;
	if(totalWeight > 0x008C) temp = 0x01 ;	
	else temp = 0x00 ;
	temp3 = (totalWeight & 0x00FC) | temp | temp2 ;
	PORTD = temp3 ;	
    }
    return 0 ;
}
