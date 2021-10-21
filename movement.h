#ifndef MOVEMENT_H
#define MOVEMENT_H

/* Check navswitch and button and update player positon */
void update_movement (uint8_t* player_position, bool *player_jumping, int8_t* jump_array, uint8_t *jump_array_length, uint8_t *jump_array_pos);
void draw_player (uint8_t* player_position);


#endif //MOVEMENT_H
