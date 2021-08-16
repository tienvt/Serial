#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "polserial.h"

// Initialize for USART
void USART_init(void)
{
    _inline_USART_init();
}

// Send Char one by one with single quote
void USART_send(char data, uint8_t usart_num){
    _inline_USART_send(data,usart_num);
}

void USART_putstring(char *StringPtr, uint8_t usart_num){
// sends the characters from the string one at a time to the USART
    _inline_USART_putstring(StringPtr,usart_num);
}

void USART_putstring_P(const char *StringPtr, uint8_t usart_num){
// sends the characters from the string one at a time to the USART
    while(pgm_read_byte(StringPtr) != 0x00)
        {
            USART_send(pgm_read_byte(StringPtr++),usart_num);
        }
}
