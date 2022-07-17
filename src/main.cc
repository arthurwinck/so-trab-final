//#include "window.h"
#include "system.h"
#include "main_class.h"
#include "traits.h"

__USING_API

int main(void)
{

    // Iniciar pelo método main
    System::init(&Main::run);


    // Iniciar window direto a partir do main     
    // Window window;
    // window.run();
    // return 0;
}
