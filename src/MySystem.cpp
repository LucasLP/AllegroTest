#include "../include/MySystem.h"

MySystem::MySystem()
{
    ///Load Allegro components
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_acodec_addon();

    ///Create fonts
    bigfont     = al_load_ttf_font("Game/Fonts/pirulen.ttf", 24, 0);//data-latin
    font        = al_load_ttf_font("Game/Fonts/pirulen.ttf", 12, 0);//data-latin
    smallfont   = al_load_ttf_font("Game/Fonts/pirulen.ttf", 8, 0);//data-latin

    ///Create Display
    display = al_create_display(800, 600);



    /// Install mouse and keyboard and audio
    al_install_mouse();
    al_install_keyboard();
    al_install_joystick();
    al_install_audio();


    /// Atribui o cursor padrão do sistema para ser usado
    al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));

    /// Dizemos que vamos tratar os eventos vindos do mouse e teclado
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_joystick_event_source());


    ///display title
    al_set_window_title(display, "RPG Doidao");


    ///get monitor info
    al_get_monitor_info(0 , &aminfo);


    ///Get monitor size and resize our display
    int desktop_width = aminfo.x2 - aminfo.x1 + 1;
    int desktop_height = aminfo.y2 - aminfo.y1 + 1;
    al_resize_display(display, desktop_width,desktop_height);

    ///Setting Colors
    white       = al_map_rgb(255,255,255);
    black       = al_map_rgb(0,0,0);
    red         = al_map_rgb(255,0,0);
    green       = al_map_rgb(0,255,0);
    blue        = al_map_rgb(0,0,255);
    yellow      = al_map_rgb(255,255,0);

    ///Loading sounds
    al_reserve_samples(5);//set channel number
    sound_button = al_load_sample( "Game/Sounds/button.wav");



    cout<<"\n::Loading complete!::";
}







///destrutor
MySystem::~MySystem()
{
    if(display)     al_destroy_display(display);
    if(font)        al_destroy_font(font);
    if(event_queue) al_destroy_event_queue(event_queue);

    al_destroy_sample(sound_button);
}
