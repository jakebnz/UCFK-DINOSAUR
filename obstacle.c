#include <stdbool.h>
#include <stdlib.h>

void update_obstacles () {
    if (obstacle_amount < 4) {
        obstacle_array[3] = obstacle_t {
            .isVertical = rand() % 2 //generate random number either 0 or 1
            .player_position = -1
            .player_position[0] = (rand() % 3) + 1 //generate randum number from 1 to 3

        } 
    }
}