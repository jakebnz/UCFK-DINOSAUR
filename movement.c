#include "navswitch.h"
#include "pacer.h"
#include "tinygl.h"
#include "button.h"
#include <stdbool.h>


void update_movement (uint16_t* player_position, bool *player_jumping, int8_t* jump_array, uint16_t *jump_array_length, uint16_t *jump_array_pos) {
    navswitch_update();
    //if navswitch being pushed right
    if (navswitch_down_p(NAVSWITCH_NORTH)) {
        //If player is on right edge of screen, their x position is 0, and if 1 is subtracting form it it will underflow.
        //Therfore, check if the number will be smaller than the highest x value possible
        if (player_position[1] - 1 <= 6) {
            player_position[1] = player_position[1] - 1;
        }
    //if navswitch being pushed left
    } else if (navswitch_down_p(NAVSWITCH_SOUTH)) {
        if (player_position[1] + 1 <= 6) {
            player_position[1] = player_position[1] + 1;
        }
    }

    button_update();
    if (!(*player_jumping)) {
        if (button_push_event_p(0)) {
            *player_jumping = true;
        }
    }
    if (*player_jumping) {
        player_position[0] = player_position[0] - jump_array[*jump_array_pos];
        (*jump_array_pos)++;
        if (*jump_array_pos == *jump_array_length) {
            *jump_array_pos = 0;
            *player_jumping = false;
        }
    }
}


void draw_player (uint16_t* player_position) {
    tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);
}