#ifndef OBSTACLE_H
#define OBSTACLE_H

//Obstacle struct. If y position (position[2]) == -1, then the obstacle is presumed to not exist (i.e. be null)
typedef struct {
    int8_t position[2];
    bool isVertical;
    bool isActive;
} obstacle_t;

void update_obstacles (obstacle_t* obstacle_array, uint8_t obstacle_amount);


#endif //OBSTACLE_H
