#ifndef game_state_h
#define game_state_h

//Criar super classe personagem para englobar ghost e pacman
#include "traits.h"
#include "pacman.h"
#include "ghost.h"
#include "ghosttypes.h"
#include "input.h"
#include "window.h"
#include "semaphore.h"

#include <cmath>
__BEGIN_API

class Game_State
{
public:
    Game_State() {};
    Game_State(Pacman* pacman, Blinky* blinky, Pinky* pinky,
                Inky* inky, Clyde* clyde, Input* input, Window* window) {
                        this->pacman = pacman;
                        this->blinky = blinky;
                        this->pinky = pinky;
                        this->inky = inky;
                        this->clyde = clyde;
                        this->input = input;
                        this->window = window;
                };
    ~Game_State() {};
    
private:
    Pacman* pacman;
    Blinky* blinky;
    Pinky* pinky;
    Inky* inky;
    Clyde* clyde;
    Input* input;
    Window* window;

    Semaphore* sem_pacman;
    Semaphore* sem_blinky;
    Semaphore* sem_pinky;
    Semaphore* sem_inky;
    Semaphore* sem_clyde;
    Semaphore* sem_input;
    Semaphore* sem_window;
    
public:
    Pacman* get_pacman() {return pacman;};

    int get_pacman_pos_x() {
        sem_pacman->p();
        int pos_x = get_pacman()->get_pos_x();
        sem_pacman->v();
        return pos_x;       
    };

    int get_pacman_pos_y() {
        sem_pacman->p();
        int pos_y = get_pacman()->get_pos_y();
        sem_pacman->v();
        return pos_y;
    };

    int set_pacman_pos_y() {
        sem_pacman->p();
        int pos_y = get_pacman()->get_pos_y();
        sem_pacman->v();
        return pos_y;
    };

    int set_pacman_pos(int x, int y) {
        sem_pacman->p();
        get_pacman()->set_pos(x, y);
        sem_pacman->v();
    };
    



    Blinky* get_blinky() {return blinky;};
    Pinky* get_pinky() {return pinky;};
    Inky* get_inky() {return inky;};
    Clyde* get_clyde() {return clyde;};
    Input* get_input() {return input;};
    Window* get_window() {return window;};
};



__END_API

#endif