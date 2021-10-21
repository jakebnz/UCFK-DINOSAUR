/** @file   movement.c
    @author Mengyan Huang (mhu69) and Jacob Brown (jtb68)
    @date   22 October 2021
    @brief  Implements movement logic for a player, as well as drawing them on screen.
*/

#include <stdbool.h>
#include <stdint.h>

#include "movement.h"
#include "navswitch.h"
#include "pacer.h"
#include "tinygl.h"
#include "button.h"

//Updates player movement - left, right, and jumping.
void update_movement (uint8_t* player_position, bool *player_jumping, int8_t* jump_array, uint8_t *jump_array_length, uint8_t *jump_array_pos) {
    navswitch_update();
    //If navswitch is being pushed right.
    if (navswitch_down_p(NAVSWITCH_NORTH)) {
        //Check that moving the player to the left won't send them off the edge of the screen.
        //If player is on right edge of screen, their x position is 0. If we subtract 1 from 0 in that case, the integer will underflow.
        //Therefore, in order to check if the player has gone off the edge of the screen, we check if the subtracting 1 from player_position[1] will cause it to be greater than the max value.
        if (player_position[1] - 1 <= 6) {
            player_position[1] = player_position[1] - 1;
        }
    //If navswitch is being pushed left.
    } else if (navswitch_down_p(NAVSWITCH_SOUTH)) {
        //Check that moving the player to the left won't send them off the edge of the screen.
        if (player_position[1] + 1 <= 6) {
            player_position[1] = player_position[1] + 1;
        }
    }

    button_update();
    //If the player isn't already in the jumping animation, and if the player pushes the jump button, start the jump animation.
    if (!(*player_jumping)) {
        if (button_push_event_p(0)) {
            *player_jumping = true;
        }
    }
    //Jumping works by iterating through an array each movement update. The array integers adds or substracts from the player's y-position.
    //A positive number in the array will move the player up, a negative number will move them down.
    if (*player_jumping) { //If the player is currently jumping.
        player_position[0] = player_position[0] - jump_array[*jump_array_pos]; //Move the player by the amount set in the array.
        (*jump_array_pos)++; //Move forward through the array by one for the next movement update.
        if (*jump_array_pos == *jump_array_length) { //If we're at the end of the array, set the position in the array back to 0 and set player_jumping to false.
            *jump_array_pos = 0;
            *player_jumping = false;
        }
    }
}

//Draws the player on the screen at their current position when called.
void draw_player (uint8_t* player_position) {
    tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);
}