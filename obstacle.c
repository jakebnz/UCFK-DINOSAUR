#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "obstacle.h"

obstacle_t obstacle_array[4];

void update_obstacles (obstacle_t* obstacle_array, uint8_t obstacle_amount) {
    if (obstacle_amount < 4) { //if there are less than 4 obstacles active add a new one
        obstacle_array[obstacle_amount].isVertical = rand() % 2; //generate random number either 0 or 1
        obstacle_array[obstacle_amount].position[0] = -1; //x pos starts as -1, has 1 added to it later
        obstacle_array[obstacle_amount].position[1] = (rand() % 3) + 1; //generate randum number from 1 to 3. this is the y position of the obstacle
        obstacle_array[obstacle_amount].isActive = true;
        //below: my first attempt at getting it working. i think above is the proper way. keeping here in case i need later
        /*obstacle_array[obstacle_amount] = obstacle_t {
            .isVertical = rand() % 2, //generate random number either 0 or 1
            .position[0] = -1, //x pos starts as -1, has 1 added to it later
            .position[1] = (rand() % 3) + 1 //generate randum number from 1 to 3. this is the y position of the obstacle
            .isActive = true,
        };
        obstacle_amount++;*/
    }
    for (uint8_t i = 0; i < 4; i++) { //iterate through every obstacle
        if ((obstacle_array[i]).isActive == true) { //if its active move it to the left by 1
            (obstacle_array[i]).position[0] = (obstacle_array[i]).position[0] + 1; //increase x position by one
        }
        if ((obstacle_array[i]).position[0] > 6) { //if it goes off left edge of screen deactivate it
            (obstacle_array[i]).isActive = false;
            //after deactivating it move every obstacle in the list to the left
            //might want to change this implementation later.
            obstacle_array[0] = obstacle_array[1];
            obstacle_array[1] = obstacle_array[2];
            obstacle_array[2] = obstacle_array[3];
            (obstacle_array[3]).isActive = false;
            obstacle_amount--;
            i--; //since we move everything in the list to the left
        }
    }
}

//void draw_obstacles (obstacle_t* obstacle_array) {

//}