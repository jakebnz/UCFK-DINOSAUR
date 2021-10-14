#include "navswitch.h"

void update_movement (uint16_t* player_position) {

    navswitch_update();

    if (navswitch_push_event_p (NAVSWITCH_NORTH)) { //push right
        player_position[1] = player_position[1] - 1;

    } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        player_position[1] = player_position[1] + 1;
    }
}