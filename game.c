#include "system.h"
#include "tinygl.h"
#include "movement.h"
#include "task.h"
#include "navswitch.h"
#include "button.h"
#include "obstacle.h"
#include <stdbool.h>

typedef struct  {
    uint16_t player_position[2];
    uint16_t prev_player_position[2];
    bool player_jumping;
    int8_t jump_array[8];
    uint16_t jump_array_length;
    uint16_t jump_array_pos;
    obstacle_t obstacle_array[4];
} game_data_t;

static void task_update_player (void *data) {
    
    game_data_t* game_data = data;

    game_data->prev_player_position[0] = game_data->player_position[0];
    game_data->prev_player_position[1] = game_data->player_position[1];
    update_movement(game_data->player_position, &game_data->player_jumping, game_data->jump_array, &game_data->jump_array_length, &game_data->jump_array_pos);
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

    //Create game data struct and fill with default values.
    static game_data_t game_data = {
        .player_position[0] = 3, //default player positon is 3,6
        .player_position[1] = 6,
        .player_jumping = false,
        .jump_array = {1, 1, 1, 0,  0, -1, -1, -1},
        .jump_array_length = 8,
        .jump_array_pos = 0,
    };

    task_t tasks[] =
    {
        {.func = task_update_player, .period = TASK_RATE / 12., .data = &game_data},
        {.func = task_draw_screen, .period = TASK_RATE / 1000., .data = &game_data},
    };

    task_schedule(tasks, 2);
    return 0;
}
