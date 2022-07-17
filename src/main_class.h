// #ifndef main_class_h
// #define main_class_h

// #include <iostream>
// #include "cpu.h"
// #include "traits.h"
// #include "thread.h"
// #include "semaphore.h"

// __BEGIN_API

// class Main
// {
// public:
//     Main() {
//     }

//     static const int WORKLOAD = 20000;

//     static int do_work(int n){
//         int i, j, soma;

//         soma = 0 ;
//         for (i = 0; i < n; i++)
//             for (j = 0; j < n; j++)
//                 soma += j * i;
//         return soma;
//     }

//     static void run(void * name) {

//         std::cout << (char *) name << ": inicio\n";


//         //pacman_thread = new Thread(body, (char *) pang_name.data(), 0);
        
//         ghost_threads[0] = new Thread(body_ghost, (char *) "Ghost1 ", 1);
//         ghost_threads[1] = new Thread(body_ghost, (char *) "Ghost2 ", 2);
//         ghost_threads[2] = new Thread(body_ghost, (char *) "Ghost3 ", 3);
//         ghost_threads[3] = new Thread(body_ghost, (char *) "Ghost4 ", 4);


//         //input_thread = new Thread(body, (char *) ping_name.data(), 3);
//         //window_thread = new Thread(body, (char *) pong_name.data(), 4);

//         sem_tilemap = new Semaphore();
//         // Implementar collision_thread
        
        

//         // std::string pang_name = "   Pang";
//         // std::string peng_name = "       Peng";
//         // std::string ping_name = "           Ping";
//         // std::string pong_name = "               Pong";
//         // std::string pung_name = "                   Pung";

//         // ghost_threads[0] = new Thread(body, (char *) pang_name.data(), 0);
//         // ghost_threads[1] = new Thread(body, (char *) peng_name.data(), 1);
//         // ghost_threads[2] = new Thread(body, (char *) ping_name.data(), 2);
//         // ghost_threads[3] = new Thread(body, (char *) pong_name.data(), 3);
//         // ghost_threads[4] = new Thread(body, (char *) pung_name.data(), 4);


//         for (int i = 0; i < 2; i++) {
//             std::cout << "main: " << i << "\n";
//             Main::do_work(WORKLOAD);
//         }

//         int ec;

//         ec = ghost_threads[0]->join();
//         std::cout << "main: ghost acabou com exit code " << ec << "\n";
//         ec = ghost_threads[1]->join();
//         std::cout << "main: ghost acabou com exit code " << ec << "\n";
//         ec = ghost_threads[2]->join();
//         std::cout << "main: ghost acabou com exit code " << ec << "\n";
//         ec = ghost_threads[3]->join();
//         std::cout << "main: ghost acabou com exit code " << ec << "\n";


//         std::cout << (char *) name << ": fim\n";
        
//         delete ghost_threads[0];
//         delete ghost_threads[1];
//         delete ghost_threads[2];
//         delete ghost_threads[3];     
//     }

//     ~Main() {}

// private:

//     static const int ITERATIONS = 10;

//     static void body_ghost(char *name, int id)
//     {
//         int i ;

//         std::cout << name << "thread: inicio\n";

//         sem_tilemap->p();
//         for (i = 0; i < ITERATIONS; i++)
//         {
//             std::cout << name << "thread: " << i << "\n" ;
//             Thread::yield();
//         }
//         sem_tilemap->v();
//         std::cout << name << "thread: fim\n";


//         ghost_threads[id]->thread_exit(id);
//     }

//     private:
//         //static Thread *ghost_threads[5];
//         static Thread *ghost_threads[4];
//         static Thread *pacman_thread;
//         static Thread *input_thread;
//         static Thread *window_thread;
//         static Semaphore *sem_tilemap;
// };

// __END_API

// #endif

#ifndef main_class_h
#define main_class_h

#include <iostream>
#include "cpu.h"
#include "traits.h"
#include "thread.h"
#include "semaphore.h"

__BEGIN_API

class Main
{
public:
    Main() {
    }

    static const int WORKLOAD = 20000;

    static int do_work(int n){
        int i, j, soma;

        soma = 0 ;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                soma += j * i;
        return soma;
    }

    static void run(void * name) {
        std::cout << (char *) name << ": inicio\n";

        std::string pang_name = "   Ghost1";
        std::string peng_name = "       Ghost2";
        std::string ping_name = "           Ghost3";
        std::string pong_name = "               Ghost4";
        std::string pung_name = "                   Pacman";
        std::string p1ng_name = "                       Input";
        std::string p2ng_name = "                           Tela";
        


        ghost_threads[0] = new Thread(body, (char *) pang_name.data(), 0);
        ghost_threads[1] = new Thread(body, (char *) peng_name.data(), 1);
        ghost_threads[2] = new Thread(body, (char *) ping_name.data(), 2);
        ghost_threads[3] = new Thread(body, (char *) pong_name.data(), 3);
        
        pacman_thread = new Thread(body_pacman, (char *) pung_name.data(), 4);
        input_thread = new Thread(body_input, (char *) p1ng_name.data(), 5);
        tela_thread = new Thread(body_tela, (char *) p2ng_name.data(), 6);

        sem = new Semaphore();

        for (int i = 0; i < 2; i++) {
            std::cout << "main: " << i << "\n";
            Main::do_work(WORKLOAD);
        }

        int ec;
        std::cout << "main: esperando ghost "<< ghost_threads[0]->id() << "...\n";
        ec = ghost_threads[0]->join();
        std::cout << "main: ghost " << ghost_threads[0]->id() << " acabou com exit code " << ec << "\n";

        std::cout << "main: esperando ghost "<< ghost_threads[1]->id() << "...\n";
        ec = ghost_threads[1]->join();
        std::cout << "main: ghost " << ghost_threads[1]->id() << " acabou com exit code " << ec << "\n";

        std::cout << "main: esperando ghost "<< ghost_threads[2]->id() << "...\n";
        ec = ghost_threads[2]->join();
        std::cout << "main: ghost " << ghost_threads[2]->id() << " acabou com exit code " << ec << "\n";

        std::cout << "main: esperando ghost "<< ghost_threads[3]->id() << "...\n";
        ec = ghost_threads[3]->join();
        std::cout << "main: ghost " << ghost_threads[3]->id() << " acabou com exit code " << ec << "\n";

        std::cout << "main: esperando pacman "<< pacman_thread->id() << "...\n";
        ec = pacman_thread->join();
        std::cout << "main: pacman acabou com exit code " << ec << "\n";

        std::cout << "main: esperando input "<< input_thread->id() << "...\n";
        ec = input_thread->join();
        std::cout << "main: input acabou com exit code " << ec << "\n";

        std::cout << "main: esperando tela "<< tela_thread->id() << "...\n";
        ec = tela_thread->join();
        std::cout << "main: tela acabou com exit code " << ec << "\n";


        std::cout << (char *) name << ": fim\n";
        
        delete sem;

        delete ghost_threads[0];
        delete ghost_threads[1];
        delete ghost_threads[2];
        delete ghost_threads[3];
        delete pacman_thread;
        delete input_thread;
        delete tela_thread;
    }

    ~Main() {}

private:

    static const int ITERATIONS = 10;

    static void body(char *name, int id)
    {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        for (i = 0; i < ITERATIONS; i++)
        {
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        sem->v();
        std::cout << name << ": fim\n";


        ghost_threads[id]->thread_exit(id);
    }

    static void body_pacman(char *name, int id)
    {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        for (i = 0; i < ITERATIONS; i++)
        {
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        sem->v();
        std::cout << name << ": fim\n";


        pacman_thread->thread_exit(0);
    }

    static void body_input(char *name, int id)
    {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        for (i = 0; i < ITERATIONS; i++)
        {
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        sem->v();
        std::cout << name << ": fim\n";


        input_thread->thread_exit(0);
    }

        static void body_tela(char *name, int id)
    {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        for (i = 0; i < ITERATIONS; i++)
        {
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        sem->v();
        std::cout << name << ": fim\n";


        tela_thread->thread_exit(0);
    }

    

    private:
        static Thread *ghost_threads[4];
        static Thread *pacman_thread;
        static Thread *input_thread;
        static Thread *tela_thread;
        static Semaphore *sem;
};

__END_API

#endif