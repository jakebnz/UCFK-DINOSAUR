#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "movement.h"


int main (void)
{
    system_init ();

    //Initiliase navswitch
    navswitch_init();

    //Initiliase pacer
    pacer_init(1000);

    //Initiliase tiny gl with a polling rate of 100hz
    tinygl_init(1000);
    
    //Draw line across bottom row of pixels. This is the 'floor'.
    tinygl_draw_line(tinygl_point(4,0), tinygl_point (4, 6), 1);

    //Create the tuple used for the coordinates of the player. Set it to 3,6 by default.
    uint16_t player_position[] = {3, 6};
    uint16_t prev_player_position[2];
    tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);

    while (1)
    {
        prev_player_position[0] = player_position[0];
        prev_player_position[1] = player_position[1];
        update_movement(player_position);
        tinygl_draw_point(tinygl_point(prev_player_position[0], prev_player_position[1]), 0);
        tinygl_draw_point(tinygl_point(player_position[0], player_position[1]), 1);
        tinygl_update();

        pacer_wait();
        continue;
    }
}
