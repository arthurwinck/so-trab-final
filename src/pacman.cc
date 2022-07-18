#include "pacman.h"

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

void Pacman::update(int dir, char* tilemap) {
    
    this->set_dir(dir);
    

    // Atualização em TILES (?)

    //Left
    if (dir == 0) {
        this->set_pos(this->get_pos_x() - 1, this->get_pos_y());
    //Right
    } else if (dir == 1) {
        this->set_pos(this->get_pos_x() + 1, this->get_pos_y());
    //Down
    } else if (dir == 2) {
        this->set_pos(this->get_pos_x(), this->get_pos_y() + 1);
    //Up
    } else if (dir == 3) {
        this->set_pos(this->get_pos_x(), this->get_pos_y() - 1);
    }

    //If dir == -1, do nothing

}

__END_API