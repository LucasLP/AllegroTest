#include "../include/MainHeader.h"
#include "../include/MySystem.h"

#include "../include/Plataform.h"


int main()
{

    cout << "Hello world!" << endl;

    ///Criei esta classe para facilitar e não poluir
    ///Vai inciar componentes do allegro
    MySystem system;

    Plataform plataform(&system);
    // poderia ser tbm : Plataform *plataform = new Plataform(&system);

    plataform.run();

    return 0;
}



