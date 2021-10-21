timer: 

task: timer

pio: 

ledmat: pio

display: ledmat

font: 

tinygl: display font

navswitch: pio

button: pio

pacer: timer

movement: navswitch pacer tinygl button

obstacle: tinygl

game_start_end: timer button tinygl

dinosaur: task tinygl navswitch button movement obstacle game_start_end

