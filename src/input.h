#ifndef input_h
#define input_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "traits.h"

__BEGIN_API

class Input
{
public:
    Input() {dir = 0;};
    ~Input();

    enum Command {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        RESET,
        PAUSE,
        NONE
    };

    void get_command() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            std::cout << "Keyboard esquerda!" << std::endl;
            set_dir(0);
            //return Command::LEFT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "Keyboard direita!" << std::endl;
            set_dir(1);
            //return Command::RIGHT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            std::cout << "Keyboard para baixo!" << std::endl;
            set_dir(2);
            //return Command::DOWN;            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            std::cout << "Keyboard para cima!" << std::endl;
            set_dir(3);
            //return Command::UP;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){} ;  
            while (!sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {};
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){} ;
        }
        else {
            set_dir(-1);
            //return Command::NONE;
        }

    }

    int get_dir() {
        return dir;
    }

    void set_dir(int dir) {
        this->dir = dir;
    }
private:
    int dir;
};

__END_API

#endif