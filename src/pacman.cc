#include "pacman.h"
#include <iostream>
__BEGIN_API

Pacman::Pacman(int pos_x, int pos_y) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    dir = -1;
}

void Pacman::set_pos(unsigned int pos_x, unsigned int pos_y) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

int Pacman::get_pos_x() {
    return this->pos_x;
}

int Pacman::get_pos_y() {
    return this->pos_y;
}

void Pacman::set_dir(int dir) {
    this->dir = dir;
}
int Pacman::get_dir() {
    return this->dir;
}

void Pacman::update(int newdir, char* tilemap) {
    
    this->set_dir(newdir);
    

    // Atualização em TILES (?)

    //Left
    if (dir == 0) {
        std::cout << "Vou ir para a esquerda!";
        if (tilemap[pos_x*28 + pos_y - 1] != 'W') {
            this->set_pos(this->get_pos_x() - 1, this->get_pos_y());
        }
        std::cout << "Fui para a esquerda!";

    //Right
    } else if (dir == 1) {
        std::cout << "Vou ir para a direita!";
        if (tilemap[pos_x*28 + pos_y + 1] != 'W') {
            this->set_pos(this->get_pos_x() + 1, this->get_pos_y());
        }
        std::cout << "Fui para a direita!";

    //Down
    } else if (dir == 2) {
        std::cout << "Vou ir para abaixo!";

        if (tilemap[(pos_x + 1)*28 + pos_y] != 'W') {
            this->set_pos(this->get_pos_x(), this->get_pos_y() + 1);
        }
        std::cout << "Fui para abaixo!";

    //Up
    } else if (dir == 3) {
        std::cout << "Vou ir para cima!";

        if (tilemap[(pos_x-1)*28 + pos_y] != 'W') {
            this->set_pos(this->get_pos_x(), this->get_pos_y() - 1);
        }
        std::cout << "Fui para abaixo!";
    }


    //If dir == -1, do nothing

}

__END_API