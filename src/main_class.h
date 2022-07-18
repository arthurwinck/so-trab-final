#ifndef main_class_h
#define main_class_h

#include <iostream>
#include "cpu.h"
#include "traits.h"
#include "thread.h"
#include "semaphore.h"
#include "pacman.h"
#include "ghost.h"
#include "input.h"
#include "window.h"

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
        
        Pacman* pacman_obj = new Pacman(14, 23);
        Ghost* red_ghost_obj = new Ghost(10, 20);
        Ghost* pink_ghost_obj = new Ghost(16, 20);
        Ghost* orange_ghost_obj = new Ghost(19, 20);
        Ghost* blue_ghost_obj = new Ghost(20, 20);
        Window* tela_obj = new Window;
        Input* input_obj = new Input;


        std::string ghost_name_1 = "   ghost_1";
        std::string ghost_name_2 = "       ghost_2";
        std::string ghost_name_3 = "           ghost_3";
        std::string ghost_name_4 = "               ghost_4";
        std::string pacman = "                         pacman";
        std::string input = "                             input";
        std::string tela = "                                 tela";

        ghost_thread[0] = new Thread(body_ghost, (char *) ghost_name_1.data(), 0, red_ghost_obj,pacman_obj,tela_obj);
        ghost_thread[1] = new Thread(body_ghost, (char *) ghost_name_2.data(), 1, pink_ghost_obj,pacman_obj,tela_obj);
        ghost_thread[2] = new Thread(body_ghost, (char *) ghost_name_3.data(), 2, orange_ghost_obj,pacman_obj, tela_obj);
        ghost_thread[3] = new Thread(body_ghost, (char *) ghost_name_4.data(), 3, blue_ghost_obj,pacman_obj,tela_obj);

        pacman_thread = new Thread(body_pacman, (char *) pacman.data(), 5, pacman_obj, input_obj, tela_obj);
        input_thread = new Thread(body_input, (char *) input.data(), 6, input_obj, tela_obj);
        tela_thread = new Thread(body_tela, (char *) tela.data(), 7, tela_obj, pacman_obj, red_ghost_obj);

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

    // Trocar
    static void body_ghost(char *name, int id, Ghost* ghost, Pacman* pacman, Window* tela)
    {
        int i ;
        int pac_x;
        int pac_y;
        std::cout << name << ": inicio\n";

        //sem->p();
        //pac_x = pacman->get_pos_x();
        //pac_y = pacman->get_pos_y();
        //for (i = 0; i < ITERATIONS; i++)
        while (tela->running()==1)
        {
//            ghost->set_target(pacman->get_pos_x(),pacman->get_pos_y(), Window::get_maze());
            ghost->move();
            ghost->changetile(pacman->get_pos_x(),pacman->get_pos_y(), Window::get_maze());
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        //sem->v();
        std::cout << name << ": fim\n";


        ghost_thread[id]->thread_exit(id);
    }

    static void body_pacman(char *name, int id, Pacman* pacman, Input* input, Window* tela) {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        sem->v();
        
        //for (i = 0; i < ITERATIONS; i++)
        while (tela->running()==1)
        {
            //Proteger sessão crítica
            pacman->update(input->get_dir(), Window::get_maze());
            pacman->move(Window::get_maze());
            pacman->changetile();

            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        std::cout << name << ": fim\n";


        pacman_thread->thread_exit(id);
    }

    static void body_input(char *name, int id, Input* input, Window* tela) {
        int i ;
        Input::Command command;

        std::cout << name << ": inicio\n";

        sem->p();
        sem->v();
        //for (i = 0; i < ITERATIONS; i++)
        while (tela->running()==1)
        {
            input->get_command();
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }

        std::cout << name << ": fim\n";


        input_thread->thread_exit(id);
    }

    //Usar const e & no ponteiro --
    static void body_tela(char *name, int id, Window* tela, Pacman* pacman, Ghost* ghost) {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        sem->v();
        //for (i = 0; i < ITERATIONS; i++)
        while (tela->running()==1)
        {
                
            tela->run(pacman->get_pos_x(), pacman->get_pos_y(),pacman->get_step() ,pacman->get_dir(), ghost->get_pos_x(),
            ghost->get_pos_y(), ghost->get_step(), ghost->get_dir());
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }

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
        static Window* tela_obj;
        static Input* input_obj;
        

};

__END_API

#endif
