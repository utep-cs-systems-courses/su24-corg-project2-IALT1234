COMMON_OBJECTS  =

CPU 		= msp430g2553

CFLAGS 		= -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: buzzer.elf

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o 
	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

buzzer.o: ../demos/11-buzzer/buzzer.c ../demos/11-buzzer/buzzer.h ../demos/timerLib/libTimer.h

main.o: main.c ../demos/11-buzzer/buzzer.h ../demos/timerLib/libTimer.h

	${CC} ${CFLAGS} -c -o main.o main.c
	${CC} ${CFLAGS} -c -o buzzer.o ../demos/11-buzzer/buzzer.c
