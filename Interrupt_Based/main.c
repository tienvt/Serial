#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"


volatile int USART_ReceiveBuffer; // Global Buffer

int main()
{
    USART_Init();
    uart_string("10");
    UCSR0B |= (1<<RXCIE0);
    while (1)
    {
    }
    return 0;

}


ISR(USART_RX_vect)
{
    USART_ReceiveBuffer = UDR0;
    UDR0 = USART_ReceiveBuffer;
}
