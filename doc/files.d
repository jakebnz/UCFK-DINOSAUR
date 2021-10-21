../../drivers/avr/pio.h: 

../../drivers/ledmat.h: 

../../drivers/ledmat.c: ../../drivers/avr/pio.h ../../drivers/ledmat.h

../../drivers/ledmat.o: ../../drivers/ledmat.c

../../utils/font.h: 

../../utils/font.c: ../../utils/font.h

../../utils/font.o: ../../utils/font.c

movement.h: 

../../drivers/navswitch.h: 

../../utils/pacer.h: 

../../drivers/display.h: 

../../utils/tinygl.h: ../../drivers/display.h ../../utils/font.h

../../drivers/button.h: 

movement.c: movement.h ../../drivers/navswitch.h ../../utils/pacer.h ../../utils/tinygl.h ../../drivers/button.h

movement.o: movement.c

../../drivers/button.c: ../../drivers/button.h ../../drivers/avr/pio.h

../../drivers/button.o: ../../drivers/button.c

../../utils/tinygl.c: ../../utils/tinygl.h ../../drivers/display.h ../../utils/font.h

../../utils/tinygl.o: ../../utils/tinygl.c

../../drivers/avr/timer.h: 

../../utils/task.h: ../../drivers/avr/timer.h

../../utils/task.c: ../../utils/task.h ../../drivers/avr/timer.h

../../utils/task.o: ../../utils/task.c

../../drivers/avr/timer.c: ../../drivers/avr/timer.h

../../drivers/avr/timer.o: ../../drivers/avr/timer.c

../../drivers/display.c: ../../drivers/ledmat.h ../../drivers/display.h

../../drivers/display.o: ../../drivers/display.c

../../drivers/avr/system.c: 

../../drivers/avr/system.o: ../../drivers/avr/system.c

obstacle.h: 

obstacle.c: obstacle.h ../../utils/tinygl.h

obstacle.o: obstacle.c

../../drivers/avr/pio.c: ../../drivers/avr/pio.h

../../drivers/avr/pio.o: ../../drivers/avr/pio.c

../../fonts/font3x5_1.h: ../../utils/font.h

game_start_end.h: 

dinosaur.c: ../../utils/task.h ../../utils/tinygl.h ../../drivers/navswitch.h ../../drivers/button.h ../../fonts/font3x5_1.h movement.h obstacle.h game_start_end.h

dinosaur.o: dinosaur.c

../../utils/pacer.c: ../../drivers/avr/timer.h ../../utils/pacer.h

../../utils/pacer.o: ../../utils/pacer.c

game_start_end.c: game_start_end.h ../../drivers/avr/timer.h ../../drivers/button.h ../../utils/tinygl.h

game_start_end.o: game_start_end.c

../../drivers/avr/delay.h: 

../../drivers/navswitch.c: ../../drivers/navswitch.h ../../drivers/avr/delay.h ../../drivers/avr/pio.h

../../drivers/navswitch.o: ../../drivers/navswitch.c

dinosaur.out: ../../drivers/ledmat.o ../../utils/font.o movement.o ../../drivers/button.o ../../utils/tinygl.o ../../utils/task.o ../../drivers/avr/timer.o ../../drivers/display.o ../../drivers/avr/system.o obstacle.o ../../drivers/avr/pio.o dinosaur.o ../../utils/pacer.o game_start_end.o ../../drivers/navswitch.o

