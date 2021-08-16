#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"

#define USART_BAUDRATE 9600
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0<<UMSEL00) // USART Mode Selection

#define DISABLED (0<<UPM00)
#define EVEN_PARITY (2<<UPM00)
#define ODD_PARITY (3<<UPM00)
#define PARITY_MODE DISABLED  // USART Partity Bit Selection

#define ONE_BIT (0<<USBS0)
#define TWO_BIT (1<<USBS0)
#define STOP_BIT ONE_BIT // USART Stop Bit Selection

#define FIVE_BIT (0<<UCSZ00)
#define SIX_BIT (1<<UCSZ00)
#define SEVEN_BIT (2<<UCSZ00)
#define EIGHT_BIT (3<<UCSZ00)
#define DATA_BIT EIGHT_BIT //USART Data Bit Selection

void uart_transmit(int data)
{
     while(!(UCSR0A & (1<<UDRE0))); 
     UDR0 = data;
}


void uart_string(char *s)
{
     int i=0;
     while(s[i]!='\0')
     {
        uart_transmit(s[i]);
        i++;
     }
}

void USART_Init()
{
      // Set Baud Rate
      UBRR0H = BAUD_PRESCALER >> 8;
      UBRR0L = BAUD_PRESCALER;

      // Set Frame Format
      UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;

      // Enable Receiver and Transmitter
      UCSR0B = (1<<RXEN0) | (1<<TXEN0);

      // Enable Global Interrupts
      sei();
}

