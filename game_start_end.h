/** @file   game_start_end.c
    @author Mengyan Huang (mhu69) and Jacob Brown (jtb68)
    @date   22 October 2021
    @brief  Implements logic for when a game is over, hasn't started yet, or is restarted.
*/

#ifndef GAME_START_END_H
#define GAME_START_END_H

void start_end_screen (bool *game_not_started, bool *game_not_started_initialised, bool *game_over, bool *game_over_initialised, uint16_t *score, bool *restart_game);

#endif //GAME_START_END_H
