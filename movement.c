#include "navswitch.h"
#include "pacer.h"
#include "tinygl.h"
#include <stdbool.h>


void update_movement (uint16_t* player_position) {
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

    
}


void draw_player (uint16_t* player_position, uint16_t* prev_player_position) {
    tinygl_draw_point(tinygl_point(prev_player_position[0], prev_player_position[1]), 0);
    tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);
}