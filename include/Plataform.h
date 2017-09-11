#ifndef PLATAFORM_H
#define PLATAFORM_H

#include "../include/MainHeader.h"
#include "../include/MySystem.h"

class Plataform
{
    public:
        Plataform(MySystem *);

        virtual ~Plataform();


        void run();
    protected:
    private:
        void update();
        void move();

        MySystem *system;
        ALLEGRO_BITMAP *background ;
        bool exit, redraw ;

        ALLEGRO_BITMAP *image ;
        int x, y;
        int sprite_num;/// 0 ~ 3
        bool direction;///false = left, true = right
};

#endif // PLATAFORM_H
