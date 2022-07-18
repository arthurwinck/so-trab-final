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

    Command getcommand() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            std::cout << "Keyboard esquerda!" << std::endl;
            return Command::LEFT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "Keyboard direita!" << std::endl;
            return Command::RIGHT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            std::cout << "Keyboard para baixo!" << std::endl;
            return Command::DOWN;            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            std::cout << "Keyboard para cima!" << std::endl;
            return Command::UP;
        } else {
            return Command::NONE;
        }

    }
private:
    int vida;
    int dir;
};