#include "system.h"
#include "tinygl.h"
#include "movement.h"
#include "task.h"
#include "navswitch.h"
#include "button.h"
#include "obstacle.h"
#include <stdbool.h>
#include "../fonts/font3x5_1.h"
#include <stdio.h>

typedef struct  {
    uint8_t player_position[2];
    bool player_jumping;
    int8_t jump_array[8];
    uint8_t jump_array_length;
    uint8_t jump_array_pos;
    obstacle_t obstacle_array[4];
    uint8_t obstacle_amount;
    int8_t obstacle_creation_gap;
    bool game_over;
    bool game_over_initialised; //true if the game_over screen has been initliased
    bool game_not_started;
    bool game_not_started_initialised; //true if the game_not_started screen has been initialised
    uint16_t score;
} game_data_t;

static void task_update_game_active(void *data) {

    game_data_t* game_data = data;

    if (game_data->game_not_started == true && game_data->game_not_started_initialised == false) { //If the game hasn't started, and if the startup screen text hasn't initilised.
        game_data->game_not_started_initialised = true;
        tinygl_clear();
        tinygl_text("  DINOSAUR ");
    } else if (game_data->game_not_started == true && game_data->game_not_started_initialised == true) { //if the game hasn't started, and if the startup screen text has initilised.
        button_update();
        if (button_push_event_p(0)) { //if button gets pushed start game
            game_data->game_not_started = false;
        }
    } else if (game_data->game_over == true && game_data->game_over_initialised == false) { //If the game is over, and if the game over screen text hasn't initialised.
        game_data->game_over_initialised = true;
        tinygl_clear();
        char score_str[25]; //A string length of 25 allows a max score of 9,999,999 which would take just under 16 days of constant playing to achieve, so I think it's high enough.
        int16_t j = snprintf(score_str, 25, " GAME OVER  SCORE:%d", game_data->score);
        tinygl_text(score_str);
    } else if (game_data->game_over == true && game_data->game_over_initialised == true) { //If the game is over, and if the game over screen text has initialised.
        button_update();
        if (button_push_event_p(0)) { //if button gets pushed restart game
            game_data->player_position[0] = 3; //default player positon is 3,6
            game_data->player_position[1] = 6;
            game_data->player_jumping = false;
            game_data->jump_array_pos = 0;
            game_data->obstacle_amount = 0;
            game_data->obstacle_creation_gap = -5; //starts as negative to give a few moments before obstacles start appearing
            game_data->game_over = false;
            game_data->game_over_initialised = false;
            (game_data->obstacle_array[0]).isActive = false;
            (game_data->obstacle_array[1]).isActive = false;
            (game_data->obstacle_array[2]).isActive = false;
            (game_data->obstacle_array[3]).isActive = false;
            game_data->score = 0;
        }
    }

    //tinygl_update();

}

static void task_update_player (void *data) {
    
    game_data_t* game_data = data;

    if (game_data->game_over == false && game_data->game_not_started == false) { //Check if game is active.
        //Collision has to be checked before AND after player position is updated.
        //If this is not done, it's possible for the player to phase through obstacles, as the player and the obstacles move at different speeds.
        check_collision(game_data->obstacle_array, game_data->player_position, &game_data->game_over);
        update_movement(game_data->player_position, &game_data->player_jumping, game_data->jump_array, &game_data->jump_array_length, &game_data->jump_array_pos);
        check_collision(game_data->obstacle_array, game_data->player_position, &game_data->game_over);
    }
    
}

static void task_update_obstacles (void *data) {
    
    game_data_t* game_data = data;

    if (game_data->game_over == false && game_data->game_not_started == false) { //If game is active, update obstacle positions.
        update_obstacles(game_data->obstacle_array, &game_data->obstacle_amount, &game_data->obstacle_creation_gap);
    }
}

static void task_draw_screen (void *data) {

    game_data_t* game_data = data;

    if (game_data->game_over == false && game_data->game_not_started == false) { //If game is active, draw game objects.
        tinygl_clear(); //clear screen
        tinygl_draw_line(tinygl_point(4,0), tinygl_point (4, 6), 1); //draw floor
        draw_player(game_data->player_position); //draw player
        draw_obstacles(game_data->obstacle_array); //draw obstacles
    }

    tinygl_update(); //Update the screen. This is always done whether the game is active or not to draw the pre-game and post-game screens.
}

static void increase_score (void *data) {

    game_data_t* game_data = data;

    if (game_data->game_over == false && game_data->game_not_started == false) {
        game_data->score++;
    }
}

int main (void)
{
    system_init ();

    //Initiliase navswitch
    navswitch_init();

    //Initiliase tiny gl with a polling rate of 100hz
    tinygl_init(1000);

    //Set tinygl text settings
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set(30);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);

    //Create game data struct and fill with default values.
    static game_data_t game_data = {
        .player_position[0] = 3, //default player positon is 3,6
        .player_position[1] = 6,
        .player_jumping = false,
        .jump_array = {1, 1, 1, 0,  0, -1, -1, -1},
        .jump_array_length = 8,
        .jump_array_pos = 0,
        .obstacle_amount = 0,
        .obstacle_creation_gap = -5, //starts as negative to give a few moments before obstacles start appearing
        .game_over = false,
        .game_over_initialised = false,
        .game_not_started = true,
        .game_not_started_initialised = false,
        .score = 0,
    };

    task_t tasks[] =
    {
        {.func = task_update_game_active, .period = TASK_RATE / 12., .data = &game_data},
        {.func = task_update_player, .period = TASK_RATE / 12., .data = &game_data},
        {.func = task_update_obstacles, .period = TASK_RATE / 8., .data = &game_data},
        {.func = task_draw_screen, .period = TASK_RATE / 1000., .data = &game_data},
        {.func = increase_score, .period = TASK_RATE / 1, .data = &game_data},
    };

    task_schedule(tasks, 5);
    return 0;
}
