/** @file   movement.c
    @author Mengyan Huang (mhu69) and Jacob Brown (jtb68)
    @date   22 October 2021
    @brief  Implements movement logic for a player, as well as drawing them on screen.
*/

#ifndef MOVEMENT_H
#define MOVEMENT_H

/* Check navswitch and button and update player positon */
void update_movement (uint8_t* player_position, bool *player_jumping, int8_t* jump_array, uint8_t *jump_array_length, uint8_t *jump_array_pos);
void draw_player (uint8_t* player_position);


#endif //MOVEMENT_H
