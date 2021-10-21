#include "navswitch.h"
#include "pacer.h"
#include "tinygl.h"
#include "button.h"
#include <stdbool.h>

void update_movement (uint8_t* player_position, bool *player_jumping, int8_t* jump_array, uint8_t *jump_array_length, uint8_t *jump_array_pos) {
    navswitch_update();
    //if navswitch being pushed right
    if (navswitch_down_p(NAVSWITCH_NORTH)) {
        //Check that moving the player to the left won't send them off the edge of the screen.
        //If player is on right edge of screen, their x position is 0. If we subtract 1 from 0 in that case, the integer will underflow.
        //Therefore, in order to check if the player has gone off the edge of the screen, we check if the subtracting 1 from player_position[1] will cause it to be greater than the max value.
        if (player_position[1] - 1 <= 6) {
            player_position[1] = player_position[1] - 1;
        }
    //if navswitch being pushed left
    } else if (navswitch_down_p(NAVSWITCH_SOUTH)) {
        //Check that moving the player to the left won't send them off the edge of the screen.
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


void draw_player (uint8_t* player_position) {
    tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);
}