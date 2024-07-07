COMMON_OBJECTS  =
CPU 		= msp430g2553
CFLAGS 		= -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: buzzer.elf

../../s24-corg-buzzy-blinky-toy-IALT1234/demos/11-buzzer/buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o ../../s24-corg-buzzy-blinky-toy-IALT1234/demos/lib/libTimer.a

	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh $^

clean: $^
	rm -f *.o *.elf

buzzer.c: ../demos/11-buzzer/buzzer.h 

main.c: ../demos/11-buzzer/buzzer.h 
