../../drivers/avr/pio.h: 

../../drivers/ledmat.h: 

../../drivers/ledmat.c: ../../drivers/avr/pio.h ../../drivers/ledmat.h

../../drivers/ledmat.o: ../../drivers/ledmat.c

../../utils/font.h: 

../../utils/font.c: ../../utils/font.h

../../utils/font.o: ../../utils/font.c

../../drivers/navswitch.h: 

movement.c: ../../drivers/navswitch.h

movement.o: movement.c

../../drivers/display.h: 

../../utils/tinygl.h: ../../drivers/display.h ../../utils/font.h

../../utils/pacer.h: 

movement.h: 

game.c: ../../utils/tinygl.h ../../utils/pacer.h movement.h

game.o: game.c

../../utils/tinygl.c: ../../utils/tinygl.h ../../drivers/display.h ../../utils/font.h

../../utils/tinygl.o: ../../utils/tinygl.c

../../drivers/avr/system.c: 

../../drivers/avr/system.o: ../../drivers/avr/system.c

../../drivers/avr/timer.h: 

../../drivers/avr/timer.c: ../../drivers/avr/timer.h

../../drivers/avr/timer.o: ../../drivers/avr/timer.c

../../drivers/display.c: ../../drivers/ledmat.h ../../drivers/display.h

../../drivers/display.o: ../../drivers/display.c

../../drivers/avr/pio.c: ../../drivers/avr/pio.h

../../drivers/avr/pio.o: ../../drivers/avr/pio.c

../../utils/pacer.c: ../../drivers/avr/timer.h ../../utils/pacer.h

../../utils/pacer.o: ../../utils/pacer.c

../../drivers/avr/delay.h: 

../../drivers/navswitch.c: ../../drivers/navswitch.h ../../drivers/avr/delay.h ../../drivers/avr/pio.h

../../drivers/navswitch.o: ../../drivers/navswitch.c

game.out: ../../drivers/ledmat.o ../../utils/font.o movement.o game.o ../../utils/tinygl.o ../../drivers/avr/system.o ../../drivers/avr/timer.o ../../drivers/display.o ../../drivers/avr/pio.o ../../utils/pacer.o ../../drivers/navswitch.o

