// #include "main_class.h"

// __BEGIN_API

// // Instanciação de atributos

// Thread *Main::ghost_threads[4];
// Semaphore *Main::sem_tilemap;
// Thread * Main::pacman_thread;
// Thread * Main::input_thread;
// Thread * Main::window_thread;

// __END_API

#include "main_class.h"

__BEGIN_API

Thread *Main::ghost_threads[4];
Semaphore *Main::sem;
Thread *Main::pacman_thread;
Thread *Main::input_thread;
Thread *Main::tela_thread;



__END_API