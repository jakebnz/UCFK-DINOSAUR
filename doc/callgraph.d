system_clock_init@system.c: 

system_watchdog_timer_init@system.c: 

system_init@system.c: system_clock_init system_watchdog_timer_init

navswitch_init@navswitch.c: 

pio_config_set@pio.c: 

ledmat_init@ledmat.c: pio_config_set pio_config_set

display_clear@display.c: 

display_init@display.c: ledmat_init display_clear

tinygl_text_speed_set@tinygl.c: 

tinygl_clear@tinygl.c: display_clear

tinygl_init@tinygl.c: display_init tinygl_text_speed_set tinygl_clear

tinygl_point@obstacle.c: 

display_pixel_set@display.c: 

tinygl_draw_point@tinygl.c: display_pixel_set

tinygl_draw_line@tinygl.c: tinygl_draw_point tinygl_draw_point tinygl_draw_point

timer_init@timer.c: 

timer_get@timer.c: 

timer_wait_until@timer.c: timer_get

task_schedule@task.c: timer_init timer_get timer_wait_until timer_get

pio_config_get@pio.c: 

_delay_loop_1@navswitch.c: 

pio_input_get@pio.c: 

navswitch_update@navswitch.c: pio_config_get pio_config_set pio_config_set _delay_loop_1 pio_input_get pio_config_set

navswitch_down_p@navswitch.c: 

button_update@button.c: pio_input_get

button_push_event_p@button.c: 

update_movement@movement.c: navswitch_update navswitch_down_p navswitch_down_p button_update button_push_event_p

task_update_player@game.c: update_movement

draw_player@movement.c: tinygl_point tinygl_draw_point

draw_obstacles@obstacle.c: tinygl_point tinygl_point tinygl_draw_line tinygl_point tinygl_point tinygl_draw_line

font_pixel_get@font.c: 

tinygl_font_pixel_get@tinygl.c: font_pixel_get

tinygl_draw_char@tinygl.c: tinygl_font_pixel_get tinygl_point tinygl_draw_point tinygl_point tinygl_draw_point tinygl_font_pixel_get tinygl_point tinygl_draw_point tinygl_point tinygl_draw_point

tinygl_draw_string@tinygl.c: tinygl_draw_char

tinygl_text_advance@tinygl.c: tinygl_draw_string tinygl_draw_string

pio_output_high@pio.c: 

pio_output_low@pio.c: 

ledmat_display_column@ledmat.c: pio_output_high pio_output_low pio_output_high pio_output_low

display_update@display.c: ledmat_display_column

tinygl_update@tinygl.c: tinygl_text_advance display_update

task_draw_screen@game.c: tinygl_clear tinygl_point tinygl_point tinygl_draw_line draw_player draw_obstacles tinygl_update

main@game.c: system_init navswitch_init tinygl_init tinygl_point tinygl_point tinygl_draw_line task_schedule @task_update_player @task_draw_screen

