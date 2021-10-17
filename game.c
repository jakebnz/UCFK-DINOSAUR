#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "ledmat.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10

void initial(void) {

    system_init ();
    navswitch_init ();
    ledmat_init ();
    pacer_init(PACER_RATE);
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

}

void display_start(void)
{

    tinygl_text("DINOSAUR");
    tinygl_update();
}


int main (void)
{
    initial();

    display_start();


    while (1)
    {

        pacer_wait();
        tinygl_update();

    }
}

