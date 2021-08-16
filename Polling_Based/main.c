#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t
#include <stdio.h>
#include <util/delay.h>

#include "polserial.h"

int main(){
   //Initialize for USART
   USART_init();

    while(1){
        //Send Char one by one with single quote
        USART_send('H',0);
	USART_send('e',0);
	USART_send('l',0);
	USART_send('l',0);
	USART_send('o',0);

	USART_send(' ',0);

	USART_send('T',0);
	USART_send('i',0);
	USART_send('e',0);
	USART_send('n',0);
	USART_send('!',0);

	USART_send('\n',0);

	//Send String with double quotes
	USART_putstring("I am a Polling man\n",0);

	//Delay time: 3s
	_delay_ms(3000);

}
return 0;
}
