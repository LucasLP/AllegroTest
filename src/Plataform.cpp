#include "../include/Plataform.h"

Plataform::Plataform(MySystem *system)
{
    this->system = system;
    exit = false; //quando for true sai do loop principal
    redraw = true; // sempre que for true fara o update da tela
    background = al_load_bitmap("Game/Images/background.png");

    ///Criamos a imagem do boneco, e (x, y)
    image = al_load_bitmap("Game/Images/hueWarrior.png");
    x = al_get_display_width(   system->display ) / 2;
    y = al_get_display_height( system->display  )  * 0.9;
    sprite_num = 0;
    direction = true;


    update();
}




Plataform::~Plataform()
{
    ///Sempre dar o destroy qndo não tiver mais necessidade
    al_destroy_bitmap(image);
    al_destroy_bitmap(background);
}





void Plataform::run(){
    ///vamos utilizar para ler da fila de eventos
    ALLEGRO_EVENT event;

    update();
    ///Loop principal
    while(!exit){
        ///Esperando por eventos de teclado/mouse/joystick
        al_wait_for_event(system->event_queue, &event);


        ///Se apertar ESC sai do jogo  ou  botao fechar
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit = true;
        }

        ///Seta Direita  ou D
        else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT  ||  event.keyboard.keycode == ALLEGRO_KEY_D){
            direction = true;
            move();
        }

        ///Seta Esquerda  ou A
        else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT  ||  event.keyboard.keycode == ALLEGRO_KEY_A){
            direction = false;
            move();
        }

        if(redraw)update();
    }
}








///O desenho da tela ocorrerá sempre aqui
void Plataform::update(){
    ///Limpamos a tela para preto
    al_clear_to_color(system->black);

    ///desenhando imagem de fundo
    al_draw_scaled_bitmap(background,
        0,0,al_get_bitmap_width(background),al_get_bitmap_height(background),
        0,0,al_get_display_width(system->display),al_get_display_height(system->display),0 );


    //image inteira
    //al_draw_bitmap(image, x, y, 0);///ultimo parametro eh uma flag caso queira espelhar a imagem

    ///Cada Sprite tem 32x48
    if(direction){  ///RIGHT  img       x1,y1               x2,y2       pos. do display que
                    ///                                                 sera desenhado a regiao (x1,y1) (x2,y2)
        al_draw_bitmap_region(image,    sprite_num*32,0    ,32,48,     x,y,0);

    }else{          ///LEFT
                    ///                               eh *2 pois as sprites left estao na segunda linha da imagem
        al_draw_bitmap_region(image,    sprite_num*32,48   ,32,48,    x,y,0);
    }

    ///Fará a tela ser reimpressa
    al_flip_display();
    redraw = false;
}





void Plataform::move(){
    redraw=true;
    if(direction){///RIGHT
        x+=2;
    }else{        ///LEFT
        x-=2;
    }
    ///troca de sprite para criar o movimento, e verifica max de sprite
    sprite_num++;
    if(sprite_num==4){
        sprite_num=0;
                        //sound        gain  pan  speed
        //al_play_sample(system->foot, 1.0 , 0.0,  1.0 , ALLEGRO_PLAYMODE_ONCE,NULL);
    }
}
