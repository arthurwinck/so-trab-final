#include <SFML/Graphics.hpp>
#include <iostream>

class Input
{
public:
    Input() {};
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

    int getinputdir() {
        switch (dir){
            case Command::LEFT:
                return 1;
            case Command::RIGHT:
                return 3;
            case Command::UP:
                return 4;
            case Command::DOWN:
                return 2;
        }
        return 0;
    }

    Command getcommand() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            std::cout << "Keyboard esquerda!" << std::endl;
            dir= Command::LEFT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "Keyboard direita!" << std::endl;
            dir= Command::RIGHT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            std::cout << "Keyboard para baixo!" << std::endl;
            dir= Command::DOWN;            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            std::cout << "Keyboard para cima!" << std::endl;
            dir= Command::UP;
        } else {
            dir= Command::NONE;
        }
        return dir;

    }
private:
    int vida;
    Command dir;
};