# File:   Makefile
# Author: Mengyan Huang (mhu69) and Jacob Brown (jtb68)
# Date:   22 October 2021
# Descr:  Make file for dinosaur game

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../drivers -I../../fonts -I../../drivers/avr -I../../utils
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: dinosaur.out


# Compile: create object files from C source files.
dinosaur.o: dinosaur.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../drivers/button.h ../../drivers/display.h ../../drivers/navswitch.h ../../fonts/font3x5_1.h ../../utils/font.h ../../utils/task.h ../../utils/tinygl.h game_start_end.h movement.h obstacle.h
	$(CC) -c $(CFLAGS) $< -o $@

game_start_end.o: game_start_end.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../drivers/button.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h game_start_end.h
	$(CC) -c $(CFLAGS) $< -o $@

movement.o: movement.c ../../drivers/avr/system.h ../../drivers/button.h ../../drivers/display.h ../../drivers/navswitch.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h movement.h
	$(CC) -c $(CFLAGS) $< -o $@

obstacle.o: obstacle.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h obstacle.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

button.o: ../../drivers/button.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/button.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/avr/delay.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

task.o: ../../utils/task.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/task.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@




# Link: create output file (executable) from object files.
dinosaur.out: dinosaur.o game_start_end.o movement.o obstacle.o pio.o system.o timer.o button.o display.o ledmat.o navswitch.o font.o pacer.o task.o tinygl.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Create hex file for programming from executable file.
dinosaur.hex: dinosaur.out
	$(OBJCOPY) -O ihex dinosaur.out dinosaur.hex


# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: dinosaur.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash dinosaur.hex; dfu-programmer atmega32u2 start


