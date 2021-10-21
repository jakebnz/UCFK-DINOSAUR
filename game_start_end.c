/** @file   game_start_end.c
    @author Mengyan Huang (mhu69) and Jacob Brown (jtb68)
    @date   22 October 2021
    @brief  Implements logic for when a game is over, hasn't started yet, or is restarted.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "game_start_end.h"
#include "timer.h"
#include "button.h"
#include "tinygl.h"


//Creation and logic for start and end screens.
void start_end_screen (bool *game_not_started, bool *game_not_started_initialised, bool *game_over, bool *game_over_initialised, uint16_t *score, bool *restart_game) {
    if (*game_not_started == true && *game_not_started_initialised == false) { //If the game hasn't started, and if the startup screen text hasn't initilised.
        *game_not_started_initialised = true;
        tinygl_clear();
        tinygl_text("  DINOSAUR ");
    } else if (*game_not_started == true && *game_not_started_initialised == true) { //if the game hasn't started, and if the startup screen text has initilised.
        button_update();
        if (button_push_event_p(0)) { //if button gets pushed start game
            *game_not_started = false;

            //Set random seed using timer.
            srand(timer_get());

        }
    } else if (*game_over == true && *game_over_initialised == false) { //If the game is over, and if the game over screen text hasn't initialised.
        *game_over_initialised = true;
        tinygl_clear();
        char score_str[25]; //A string length of 25 allows a max score of 9,999,999 which would take just under 16 days of constant playing to achieve, so I think it's high enough.
        snprintf(score_str, 25, " GAME OVER  SCORE:%d", *score);
        tinygl_text(score_str);
    } else if (*game_over == true && *game_over_initialised == true) { //If the game is over, and if the game over screen text has initialised.
        button_update();
        if (button_push_event_p(0)) { 
            *restart_game = true;
        }
    }
}