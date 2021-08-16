all:main.hex main
main.hex:Serial.o main.c
	avr-gcc -Wall -mmcu=atmega328p -o main.hex Serial.o main.c
main:Serial.o main.c
	avr-gcc -Wall -mmcu=atmega328p -o main Serial.o main.c
Serial.o:Serial.c 
	avr-gcc -os -DF_CPU=16000000UL -mmcu=atmega328p -c -o Serial.o Serial.c
burn:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
clean:
	rm  main.hex Serial.o main
