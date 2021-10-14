#include "system.h"
#include "tinygl.h"
#include "movement.h"
#include "task.h"
#include "navswitch.h"

typedef struct  {
    uint16_t player_position[2];
    uint16_t prev_player_position[2];
} game_data_t;

static void task_update_player (void *data) {
    
    game_data_t* game_data = data;

    game_data->prev_player_position[0] = game_data->player_position[0];
    game_data->prev_player_position[1] = game_data->player_position[1];
    update_movement(game_data->player_position);
}

static void task_draw_screen (void *data) {

    game_data_t* game_data = data;

    draw_player(game_data->player_position, game_data->prev_player_position);
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
    static game_data_t game_data;
    game_data.player_position[0] = 3;
    game_data.player_position[1] = 6;

    task_t tasks[] =
    {
        {.func = task_update_player, .period = TASK_RATE / 5., .data = &game_data},
        {.func = task_draw_screen, .period = TASK_RATE / 1000., .data = &game_data},
    };

    task_schedule(tasks, 2);
    return 0;
}
