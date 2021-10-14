#ifndef MOVEMENT_H
#define MOVEMENT_H

/* Check navswitch and button and update player positon */
void update_movement (uint16_t* player_position, bool *player_jumping, int8_t* jump_array, uint16_t *jump_array_length, uint16_t *jump_array_pos);
void draw_player (uint16_t* player_position, uint16_t* prev_player_position);


#endif //MOVEMENT_H
