COMMON_OBJECTS =
CPU = msp430g2553
LINKER_SCRIPT = /opt/ti/msp430_gcc/include/${CPU}.ld

CFLAGS = -mmcu=${CPU} -I../demos/timerLib -I../demos/11-buzzer
LDFLAGS = -L/opt/ti/msp430_gcc/include -T ${LINKER_SCRIPT}

CC = msp430-elf-gcc
AS = msp430-elf-as

all: buzzer.elf

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o ../../s24-corg-buzzy-blinky-toy-IALT1234/demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: buzzer.elf
	mspdebug rf2500 "prog buzzer.elf"
clean:
	rm -f *.o *.elf

buzzer.o: ../demos/11-buzzer/buzzer.c ../demos/11-buzzer/buzzer.h ../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -o buzzer.o ../demos/11-buzzer/buzzer.c
main.o: main.c ../demos/11-buzzer/buzzer.h ../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -o main.o main.c

../../s24-corg-buzzy-blinky-toy-IALT1234/demos/lib/libTimer.a:
	cd ../../s24-corg-buzzy-blinky-toy-IALT1234/demos/lib && make

