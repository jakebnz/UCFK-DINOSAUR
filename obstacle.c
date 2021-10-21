#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "obstacle.h"
#include "tinygl.h"

void update_obstacles (obstacle_t* obstacle_array, uint8_t *obstacle_amount, int8_t *obstacle_creation_gap) {
    if (*obstacle_creation_gap >= 4) {//if its been more than three passes since last obstacle was created
        if (*obstacle_amount < 4) { //if there are less than 4 obstacles active add a new one
            obstacle_array[*obstacle_amount].isVertical = rand() % 2; //generate random number either 0 or 1
            obstacle_array[*obstacle_amount].position[1] = -1; //x pos starts as -1, has 1 added to it later
            obstacle_array[*obstacle_amount].position[0] = (rand() % 2) + 1; //generate randum number from 1 to 3. this is the y position of the obstacle
            obstacle_array[*obstacle_amount].isActive = true;
            (*obstacle_amount)++;
            (*obstacle_creation_gap) = 0;
        }
    } else { //if there hasn't been more than three passes since last obstacle was created
        (*obstacle_creation_gap)++;
    }
    for (uint8_t i = 0; i < 4; i++) { //iterate through every obstacle
        if ((obstacle_array[i]).isActive) { //if its active move it to the left by 1
            (obstacle_array[i]).position[1] = (obstacle_array[i]).position[1] + 1; //increase x position by one
        }
        if ((obstacle_array[i]).position[1] > 6) { //if it goes off left edge of screen deactivate it
            (obstacle_array[i]).isActive = false;
            //after deactivating it move every obstacle in the list to the left
            //might want to change this implementation later.
            obstacle_array[0] = obstacle_array[1];
            obstacle_array[1] = obstacle_array[2];
            obstacle_array[2] = obstacle_array[3];
            (obstacle_array[3]).isActive = false;
            (*obstacle_amount)--;
            i--; //since we move everything in the list to the left
        }
    }
}

void draw_obstacles (obstacle_t* obstacle_array) {
    for (uint8_t i = 0; i < 4; i++) { //iterate through every obstacle
        if ((obstacle_array[i]).isActive) { //if its active, draw it
            obstacle_t obstacle_to_draw = obstacle_array[i]; //assing current obstacle to variable so we dont have to index the array every time since that gets messy
            if (obstacle_to_draw.isVertical) {//if it's vertical, the obstacle consists of its position plus the dot below it.
                tinygl_draw_line(tinygl_point(obstacle_to_draw.position[0], obstacle_to_draw.position[1]), tinygl_point(obstacle_to_draw.position[0] + 1, obstacle_to_draw.position[1]), 1);
            } else { //if it's horizontal, the obstacle consists of its position and the dot to the left of it
                tinygl_draw_line(tinygl_point(obstacle_to_draw.position[0], obstacle_to_draw.position[1]), tinygl_point(obstacle_to_draw.position[0], obstacle_to_draw.position[1] + 1), 1);
            }
        }
    }
}

void check_collision (obstacle_t* obstacle_array, uint8_t* player_position, bool *game_over) {
    for (uint8_t i = 0; i < 4; i++) { //iterate through every obstacle
        obstacle_t obstacle_to_check = obstacle_array[i]; //assigning current obstacle to variable so we dont have to index the array every time
        if (obstacle_to_check.isActive) { //only check collision if obstacle is active
            if (obstacle_to_check.position[0] == player_position[0] && obstacle_to_check.position[1] == player_position[1]) { //if origin of obstacle is the same as the player position
                *game_over = true;
            } else if (obstacle_to_check.isVertical) { //if its vertical we also check the point below it
                if (obstacle_to_check.position[0] + 1 == player_position[0] && obstacle_to_check.position[1] == player_position[1]) {
                    *game_over = true;
                }
            } else { //if its horizontal we check the point to the left of it
                if (obstacle_to_check.position[0] == player_position[0] && obstacle_to_check.position[1] + 1 == player_position[1]) {
                    *game_over = true;
                }
            }
        }
    }
}