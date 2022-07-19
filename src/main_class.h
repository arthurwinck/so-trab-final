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
#include "ghosttypes.h"
#include "window.h"
#include "game_state.h"

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
        Blinky* red_ghost_obj = new Blinky(10, 20,0);
        Pinky* pink_ghost_obj = new Pinky(16, 20,1);
        Inky* blue_ghost_obj = new Inky(20, 20,3);
        Clyde* orange_ghost_obj = new Clyde(19, 20,3);
        Window* tela_obj = new Window;
        Input* input_obj = new Input;

        Game_State* gamestate = new Game_State(pacman_obj, red_ghost_obj, pink_ghost_obj,
        blue_ghost_obj, orange_ghost_obj, input_obj, tela_obj);

        std::string ghost_name_1 = "   ghost_1";
        std::string ghost_name_2 = "       ghost_2";
        std::string ghost_name_3 = "           ghost_3";
        std::string ghost_name_4 = "               ghost_4";
        std::string pacman = "                         pacman";
        std::string input = "                             input";
        std::string tela = "                                 tela";

        ghost_thread[0] = new Thread(body_blinky, (char *) ghost_name_1.data(), 0, gamestate);
        ghost_thread[1] = new Thread(body_pinky, (char *) ghost_name_2.data(), 1, gamestate);
        ghost_thread[2] = new Thread(body_inky, (char *) ghost_name_3.data(), 2, gamestate);
        ghost_thread[3] = new Thread(body_clyde, (char *) ghost_name_4.data(), 3, gamestate);

        pacman_thread = new Thread(body_pacman, (char *) pacman.data(), 5, gamestate);
        input_thread = new Thread(body_input, (char *) input.data(), 6, gamestate);
        tela_thread = new Thread(body_tela, (char *) tela.data(), 7, gamestate);

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
        delete gamestate;

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
    static void body_blinky(char* name, int id, Game_State* gamestate)
    {
        int i ;
        int pac_x;
        int pac_y;
        std::cout << name << ": inicio\n";

        //sem->p();
        //pac_x = pacman->get_pos_x();
        //pac_y = pacman->get_pos_y();
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
//            ghost->set_target(pacman->get_pos_x(),pacman->get_pos_y(), Window::get_maze());
            gamestate->get_blinky()->move(gamestate->get_pacman()->energized());
            gamestate->get_blinky()->state_update();
            gamestate->get_blinky()->changetile(gamestate->get_pacman()->get_pos_x(),gamestate->get_pacman()->get_pos_y(),gamestate->get_pacman()->get_dir(), Window::get_maze());
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        //sem->v();
        std::cout << name << ": fim\n";


        ghost_thread[id]->thread_exit(id);
    }

    static void body_pinky(char* name, int id, Game_State* gamestate)
    {
        int i ;
        int pac_x;
        int pac_y;
        std::cout << name << ": inicio\n";

        //sem->p();
        //pac_x = pacman->get_pos_x();
        //pac_y = pacman->get_pos_y();
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
//            gamestate->get_pinky->set_target(pacman->get_pos_x(),pacman->get_pos_y(), Window::get_maze());
            gamestate->get_pinky()->move(gamestate->get_pacman()->energized());
            gamestate->get_pinky()->state_update();
            gamestate->get_pinky()->changetile(gamestate->get_pacman()->get_pos_x(),gamestate->get_pacman()->get_pos_y(),gamestate->get_pacman()->get_dir(), Window::get_maze());
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        //sem->v();
        std::cout << name << ": fim\n";


        ghost_thread[id]->thread_exit(id);
    }

    static void body_clyde(char* name, int id, Game_State* gamestate)
    {
        int i ;
        int pac_x;
        int pac_y;
        std::cout << name << ": inicio\n";

        //sem->p();
        //pac_x = gamestate->get_pacman()->get_pos_x();
        //pac_y = gamestate->get_pacman()->get_pos_y();
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
//            gamestate->get_clyde->set_target(gamestate->get_pacman()->get_pos_x(),gamestate->get_pacman()->get_pos_y(), Window::get_maze());
            gamestate->get_clyde()->move(gamestate->get_pacman()->energized());
            gamestate->get_clyde()->state_update();
            gamestate->get_clyde()->changetile(gamestate->get_pacman()->get_pos_x(),gamestate->get_pacman()->get_pos_y(),gamestate->get_pacman()->get_dir(), Window::get_maze());
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        //sem->v();
        std::cout << name << ": fim\n";


        ghost_thread[id]->thread_exit(id);
    }

    static void body_inky(char* name, int id, Game_State* gamestate)
    {
        int i ;
        int pac_x;
        int pac_y;
        std::cout << name << ": inicio\n";

        //sem->p();
        //pac_x = gamestate->get_pacman()->get_pos_x();
        //pac_y = gamestate->get_pacman()->get_pos_y();
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
//            gamestate->get_inky->set_target(gamestate->get_pacman()->get_pos_x(),gamestate->get_pacman()->get_pos_y(), Window::get_maze());
            gamestate->get_inky()->move(gamestate->get_pacman()->energized());
            gamestate->get_inky()->state_update();
            gamestate->get_inky()->changetile(gamestate->get_pacman()->get_pos_x(),gamestate->get_pacman()->get_pos_y(), gamestate->get_blinky()->get_pos_x(), gamestate->get_blinky()->get_pos_y(), gamestate->get_pacman()->get_dir(), Window::get_maze());
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        //sem->v();
        std::cout << name << ": fim\n";


        ghost_thread[id]->thread_exit(id);
    }

    static void body_pacman(char* name, int id, Game_State* gamestate) {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        sem->v();
        
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
            //Proteger sessão crítica
            gamestate->get_pacman()->update(gamestate->get_input()->get_dir(), Window::get_maze());
            gamestate->get_pacman()->move(Window::get_maze());
            gamestate->get_pacman()->changetile();

            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        std::cout << name << ": fim\n";


        pacman_thread->thread_exit(id);
    }

    static void body_input(char* name, int id, Game_State* gamestate) {
        int i ;
        Input::Command command;

        std::cout << name << ": inicio\n";

        sem->p();
        sem->v();
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
            gamestate->get_input()->get_command();
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }

        std::cout << name << ": fim\n";


        input_thread->thread_exit(id);
    }

    //Usar const e & no ponteiro --
    static void body_tela(char* name, int id, Game_State* gamestate) {
        int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        sem->v();
        //for (i = 0; i < ITERATIONS; i++)
        while (gamestate->get_window()->running()==1)
        {
                
            gamestate->get_window()->run(gamestate->get_pacman()->get_pos_x(), gamestate->get_pacman()->get_pos_y(),gamestate->get_pacman()->get_step() ,gamestate->get_pacman()->get_dir(),
            gamestate->get_blinky()->get_pos_x(),gamestate->get_blinky()->get_pos_y(), gamestate->get_blinky()->get_step(), gamestate->get_blinky()->get_dir(), gamestate->get_blinky()->get_state(),
            gamestate->get_pinky()->get_pos_x(),gamestate->get_pinky()->get_pos_y(), gamestate->get_pinky()->get_step(), gamestate->get_pinky()->get_dir(), gamestate->get_pinky()->get_state(),
            gamestate->get_inky()->get_pos_x(),gamestate->get_inky()->get_pos_y(), gamestate->get_inky()->get_step(), gamestate->get_inky()->get_dir(), gamestate->get_inky()->get_state(),
            gamestate->get_clyde()->get_pos_x(),gamestate->get_clyde()->get_pos_y(), gamestate->get_clyde()->get_step(), gamestate->get_clyde()->get_dir(), gamestate->get_clyde()->get_state());
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
