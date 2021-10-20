../../drivers/ledmat.h: 

../../drivers/display.h: 

../../drivers/display.c: ../../drivers/ledmat.h ../../drivers/display.h

../../drivers/display.o: ../../drivers/display.c

../../drivers/navswitch.h: 

../../utils/pacer.h: 

../../utils/font.h: 

../../utils/tinygl.h: ../../drivers/display.h ../../utils/font.h

../../drivers/button.h: 

movement.c: ../../drivers/navswitch.h ../../utils/pacer.h ../../utils/tinygl.h ../../drivers/button.h

movement.o: movement.c

../../drivers/avr/timer.h: 

../../utils/task.h: ../../drivers/avr/timer.h

../../utils/task.c: ../../utils/task.h ../../drivers/avr/timer.h

../../utils/task.o: ../../utils/task.c

../../drivers/avr/timer.c: ../../drivers/avr/timer.h

../../drivers/avr/timer.o: ../../drivers/avr/timer.c

movement.h: 

obstacle.h: 

game.c: ../../utils/tinygl.h movement.h ../../utils/task.h ../../drivers/navswitch.h ../../drivers/button.h obstacle.h

game.o: game.c

../../utils/font.c: ../../utils/font.h

../../utils/font.o: ../../utils/font.c

obstacle.c: obstacle.h

obstacle.o: obstacle.c

../../drivers/avr/delay.h: 

../../drivers/avr/pio.h: 

../../drivers/navswitch.c: ../../drivers/navswitch.h ../../drivers/avr/delay.h ../../drivers/avr/pio.h

../../drivers/navswitch.o: ../../drivers/navswitch.c

../../drivers/ledmat.c: ../../drivers/avr/pio.h ../../drivers/ledmat.h

../../drivers/ledmat.o: ../../drivers/ledmat.c

../../drivers/avr/system.c: 

../../drivers/avr/system.o: ../../drivers/avr/system.c

../../drivers/avr/pio.c: ../../drivers/avr/pio.h

../../drivers/avr/pio.o: ../../drivers/avr/pio.c

../../drivers/button.c: ../../drivers/button.h ../../drivers/avr/pio.h

../../drivers/button.o: ../../drivers/button.c

../../utils/tinygl.c: ../../utils/tinygl.h ../../drivers/display.h ../../utils/font.h

../../utils/tinygl.o: ../../utils/tinygl.c

../../utils/pacer.c: ../../drivers/avr/timer.h ../../utils/pacer.h

../../utils/pacer.o: ../../utils/pacer.c

game.out: ../../drivers/display.o movement.o ../../utils/task.o ../../drivers/avr/timer.o game.o ../../utils/font.o obstacle.o ../../drivers/navswitch.o ../../drivers/ledmat.o ../../drivers/avr/system.o ../../drivers/avr/pio.o ../../drivers/button.o ../../utils/tinygl.o ../../utils/pacer.o

