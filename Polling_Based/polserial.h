/*
 * Library of Serial: polserial.h
 *  This is use for Polling Serial
 *  Created on: May 29, 2021
 *      Author: Tien vuong
 */

#ifndef POLSERIAL_H_
#define POLSERIAL_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// CPU Freq
//#define F_CPU 11059200UL
#define F_CPU 16000000UL

// Enable USART
#define ENABLE_USART0 1

// choose USART Mode (=0 is polling; =1 is interrupt)
#define USART_INT_MODE 0

// Baurate
#define BAUDRATE 9600

// Macro to determine the baud prescale rate
// See table 22.1 in the Mega datasheet
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE * 16UL))) - 1)

// function prototype
extern void USART_init(void);

/*Send a char using UART with usart_num = 0 or 1 */
extern void USART_send(  char data, uint8_t usart_num);

/*Send a string using UART with usart_num = 0 or 1 */
extern void USART_putstring(char *StringPtr, uint8_t usart_num);

/*Send a string using UART with usart_num = 0 or 1 and string from data mem */
extern void USART_putstring_P(const char *StringPtr, uint8_t usart_num);

static inline void
_inline_USART_init (void){
#if ENABLE_USART0
    // Set the baud rate prescale rate register
    UBRR0H = BAUD_PRESCALER >> 8;
    UBRR0L = BAUD_PRESCALER;

    // Enable receiver and transmitter
    UCSR0B = ((1<<RXEN0)|(1<<TXEN0));
    #if USART_INT_MODE
    UCSR0B = ((1<<RXEN0)|(1<<TXEN0)|(1 << RXCIE0));
    #endif
    // Set frame format: 8data, 1 stop bit.
    UCSR0C = 0x06; //word size 8 bits, async mode
    sei();
#endif
}
 
static inline void
_inline_USART_send( volatile char data, uint8_t usart_num){
#if ENABLE_USART0
    if (usart_num == 0){
        //while the transmit buffer is not empty loop
        while((!(UCSR0A & (1<<UDRE0))) );
        // when the buffer is empty write data to the transmitted
        // and there is no timeout
        UDR0 = data;
    }
#endif
}

static inline void
_inline_USART_putstring(char *StringPtr, uint8_t usart_num){
    while(*StringPtr != 0x00)
    {
        USART_send(*StringPtr,usart_num);
        StringPtr++;
    }
}
#endif /*POLSERIAL_H_ */

