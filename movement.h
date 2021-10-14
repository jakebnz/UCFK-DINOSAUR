#ifndef MOVEMENT_H
#define MOVEMENT_H

/* Check navswitch and button and update player positon */
void update_movement (uint16_t* player_position);
void draw_player (uint16_t* player_position, uint16_t* prev_player_position);


#endif //MOVEMENT_H
