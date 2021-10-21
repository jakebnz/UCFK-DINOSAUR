#include "game_start_end.h"
#include <stdbool.h>

void restart_game (game_data_t* game_data) {
    game_data->player_position[0] = 3; //default player positon is 3,6
    game_data->player_position[1] = 6;
    game_data->player_jumping = false;
    game_data->jump_array_pos = 0;
    game_data->obstacle_amount = 0;
    game_data->obstacle_creation_gap = -5; //starts as negative to give a few moments before obstacles start appearing
    game_data->game_over = false;
    game_data->game_over_initialised = false;
    (game_data->obstacle_array[0]).isActive = false;
    (game_data->obstacle_array[1]).isActive = false;
    (game_data->obstacle_array[2]).isActive = false;
    (game_data->obstacle_array[3]).isActive = false;
}