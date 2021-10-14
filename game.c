#include "system.h"
#include "tinygl.h"
#include "movement.h"
#include "task.h"
#include "navswitch.h"

static uint16_t player_position[] = {3, 6};
static uint16_t prev_player_position[2];

static void task_update_player (void) {
    prev_player_position[0] = player_position[0];
    prev_player_position[1] = player_position[1];
    update_movement(player_position);
}

static void task_draw_screen (void) {
    draw_player(player_position, prev_player_position);
    tinygl_update();
}


int main (void)
{
    system_init ();

    //Initiliase navswitch
    navswitch_init();

    //Initiliase tiny gl with a polling rate of 100hz
    tinygl_init(1000);
    
    //Draw line across bottom row of pixels. This is the 'floor'.
    tinygl_draw_line(tinygl_point(4,0), tinygl_point (4, 6), 1);

    //Create the tuple used for the coordinates of the player. Set it to 3,6 by default.
    
    tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);

    task_t tasks[] =
    {
        {.func = task_update_player, .period = TASK_RATE / 5.},
        {.func = task_draw_screen, .period = TASK_RATE / 1000.},
    };

    task_schedule(tasks, 2);
    return 0;
}
