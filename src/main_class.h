#ifndef main_class_h
#define main_class_h

#include <iostream>
#include "cpu.h"
#include "traits.h"
#include "thread.h"
#include "semaphore.h"
#include "pacman.h"
#include "ghost.h"
#include "tela.h"
#include "input.h"

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
        
        Pacman* pacman_obj = new Pacman;
        Ghost* red_ghost_obj = new Ghost;
        Ghost* pink_ghost_obj = new Ghost;
        Ghost* orange_ghost_obj = new Ghost;
        Ghost* blue_ghost_obj = new Ghost;
        Tela* tela_obj = new Tela;
        Input* input_obj = new Input;


        std::string ghost_name_1 = "   ghost_1";
        std::string ghost_name_2 = "       ghost_2";
        std::string ghost_name_3 = "           ghost_3";
        std::string ghost_name_4 = "               ghost_4";
        std::string pacman = "                         pacman";
        std::string input = "                             input";
        std::string tela = "                                 tela";

        ghost_thread[0] = new Thread(body_ghost, (char *) ghost_name_1.data(), 0, red_ghost_obj);
        ghost_thread[1] = new Thread(body_ghost, (char *) ghost_name_2.data(), 1, pink_ghost_obj);
        ghost_thread[2] = new Thread(body_ghost, (char *) ghost_name_3.data(), 2, orange_ghost_obj);
        ghost_thread[3] = new Thread(body_ghost, (char *) ghost_name_4.data(), 3, blue_ghost_obj);

        pacman_thread = new Thread(body_pacman, (char *) pacman.data(), 5, pacman_obj);
        input_thread = new Thread(body_input, (char *) input.data(), 6, input_obj);
        tela_thread = new Thread(body_tela, (char *) tela.data(), 7, tela_obj);

        sem = new Semaphore();

        for (int i = 0; i < 2; i++) {
            std::cout << "main: " << i << "\n";
            Main::do_work(WORKLOAD);
        }

        int ec;
        std::cout << "main: esperando ghost_1...\n";
        ec = ghost_thread[0]->join();
        std::cout << "main: ghost_1 acabou com exit code " << ec << "\n";

        std::cout << "main: esperando ghost_2...\n";
        ec = ghost_thread[1]->join();
        std::cout << "main: ghost_2 acabou com exit code " << ec << "\n";

        std::cout << "main: esperando ghost_3...\n";
        ec = ghost_thread[2]->join();
        std::cout << "main: ghost_3 acabou com exit code " << ec << "\n";

        std::cout << "main: esperando ghost_4...\n";
        ec = ghost_thread[3]->join();
        std::cout << "main: ghost_4 acabou com exit code " << ec << "\n";

        std::cout << "main: esperando pacman...\n";
        ec = pacman_thread->join();
        std::cout << "main: pacman acabou com exit code " << ec << "\n";

        std::cout << "main: esperando input...\n";
        ec = input_thread->join();
        std::cout << "main: input acabou com exit code " << ec << "\n";

        std::cout << "main: esperando tela...\n";
        ec = tela_thread->join();
        std::cout << "main: tela acabou com exit code " << ec << "\n";



        std::cout << (char *) name << ": fim\n";
        
        delete sem;

        delete ghost_thread[0];
        delete ghost_thread[1];
        delete ghost_thread[2];
        delete ghost_thread[3];
        delete pacman_thread;
        delete input_thread;
        delete tela_thread;

        
    }

    ~Main() {}

private:

    static const int ITERATIONS = 10;

    static void body_ghost(char *name, int id, Ghost* ghost)
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


        ghost_thread[id]->thread_exit(id);
    }

    static void body_pacman(char *name, int id, Pacman* pacman) {
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


        pacman_thread->thread_exit(id);
    }

    static void body_input(char *name, int id, Input* input) {
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


        input_thread->thread_exit(id);
    }

    static void body_tela(char *name, int id, Tela* tela) {
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


        tela_thread->thread_exit(id);
    }

    private:
        static Thread *ghost_thread[4];
        static Thread *pacman_thread;
        static Thread *input_thread;
        static Thread *tela_thread;
        static Semaphore *sem;

        // Objects
        static Pacman* pacman_obj;
        static Ghost* red_ghost_obj;
        static Ghost* pink_ghost_obj;
        static Ghost* orange_ghost_obj;
        static Ghost* blue_ghost_obj;
        static Tela* tela_obj;
        static Input* input_obj;
        

};

__END_API

#endif
