#ifndef MYSYSTEM_H
#define MYSYSTEM_H

#include "MainHeader.h"

class MySystem
{
    public:
        MySystem();
        virtual ~MySystem();

        //main
        ALLEGRO_DISPLAY *display = NULL;
        ALLEGRO_MONITOR_INFO aminfo;

        //fonts
        ALLEGRO_FONT *bigfont = NULL;
        ALLEGRO_FONT *font = NULL;
        ALLEGRO_FONT *smallfont = NULL;

        //controllers
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;

        //colors
        ALLEGRO_COLOR blue, black , red , yellow, white, green;

        //sounds
        ALLEGRO_SAMPLE *sound_button=NULL;
    protected:

    private:
};

#endif // MYSYSTEM_H
