/** @file   obstacle.c
    @author Mengyan Huang (mhu69) and Jacob Brown (jtb68)
    @date   22 October 2021
    @brief  Implements logic for creating obstacles, moving obstacles, drawing them on screen,
            and checking if they collide with a player.
*/


#ifndef OBSTACLE_H
#define OBSTACLE_H

//Obstacle struct. If y position (position[2]) == -1, then the obstacle is presumed to not exist (i.e. be null)
typedef struct {
    int8_t position[2]; //the position of an obstacle is represented by its top-right most point. that means a vertical obtsacle will also have a point below it, and a horizontal obstacle will have a point to the left of it
    bool isVertical;
    bool isActive;
} obstacle_t;

void update_obstacles (obstacle_t* obstacle_array, uint8_t *obstacle_amount, int8_t *obstacle_creation_gap);
void draw_obstacles (obstacle_t* obstacle_array);
void check_collision (obstacle_t* obstacle_array, uint8_t* player_position, bool *game_over);

#endif //OBSTACLE_H
