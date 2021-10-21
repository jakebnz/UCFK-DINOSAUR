../../drivers/avr/pio.h: 

../../drivers/ledmat.h: 

../../drivers/ledmat.c: ../../drivers/avr/pio.h ../../drivers/ledmat.h

../../drivers/ledmat.o: ../../drivers/ledmat.c

../../utils/font.h: 

../../utils/font.c: ../../utils/font.h

../../utils/font.o: ../../utils/font.c

../../drivers/navswitch.h: 

../../utils/pacer.h: 

../../drivers/display.h: 

../../utils/tinygl.h: ../../drivers/display.h ../../utils/font.h

../../drivers/button.h: 

movement.c: ../../drivers/navswitch.h ../../utils/pacer.h ../../utils/tinygl.h ../../drivers/button.h

movement.o: movement.c

../../drivers/button.c: ../../drivers/button.h ../../drivers/avr/pio.h

../../drivers/button.o: ../../drivers/button.c

movement.h: 

../../drivers/avr/timer.h: 

../../utils/task.h: ../../drivers/avr/timer.h

obstacle.h: 

../../fonts/font3x5_1.h: ../../utils/font.h

game.c: ../../utils/tinygl.h movement.h ../../utils/task.h ../../drivers/navswitch.h ../../drivers/button.h obstacle.h ../../fonts/font3x5_1.h

game.o: game.c

../../utils/tinygl.c: ../../utils/tinygl.h ../../drivers/display.h ../../utils/font.h

../../utils/tinygl.o: ../../utils/tinygl.c

../../utils/task.c: ../../utils/task.h ../../drivers/avr/timer.h

../../utils/task.o: ../../utils/task.c

../../drivers/avr/timer.c: ../../drivers/avr/timer.h

../../drivers/avr/timer.o: ../../drivers/avr/timer.c

../../drivers/display.c: ../../drivers/ledmat.h ../../drivers/display.h

../../drivers/display.o: ../../drivers/display.c

obstacle.c: obstacle.h ../../utils/tinygl.h

obstacle.o: obstacle.c

../../drivers/avr/pio.c: ../../drivers/avr/pio.h

../../drivers/avr/pio.o: ../../drivers/avr/pio.c

../../drivers/avr/system.c: 

../../drivers/avr/system.o: ../../drivers/avr/system.c

../../utils/pacer.c: ../../drivers/avr/timer.h ../../utils/pacer.h

../../utils/pacer.o: ../../utils/pacer.c

../../drivers/avr/delay.h: 

../../drivers/navswitch.c: ../../drivers/navswitch.h ../../drivers/avr/delay.h ../../drivers/avr/pio.h

../../drivers/navswitch.o: ../../drivers/navswitch.c

game.out: ../../drivers/ledmat.o ../../utils/font.o movement.o ../../drivers/button.o game.o ../../utils/tinygl.o ../../utils/task.o ../../drivers/avr/timer.o ../../drivers/display.o obstacle.o ../../drivers/avr/pio.o ../../drivers/avr/system.o ../../utils/pacer.o ../../drivers/navswitch.o

