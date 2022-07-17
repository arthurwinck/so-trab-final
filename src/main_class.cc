#include "main_class.h"

__BEGIN_API

Thread *Main::ghost_thread[4];
Thread *Main::pacman_thread;
Thread *Main::input_thread;
Thread *Main::tela_thread;

Semaphore *Main::sem;

__END_API
