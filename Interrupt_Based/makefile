all:main.hex main
main.hex:serial_func.o main.c
	avr-gcc -Wall -mmcu=atmega328p -o main.hex serial_func.o main.c
main:serial_func.o main.c
	avr-gcc -Wall -mmcu=atmega328p -o main serial_func.o main.c
serial_func.o:serial_func.c 
	avr-gcc -os -DF_CPU=16000000UL -mmcu=atmega328p -c -o serial_func.o serial_func.c
burn:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
clean:
	rm  main.hex serial_func.o main
