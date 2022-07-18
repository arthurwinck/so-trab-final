#include "ghost.h"


__BEGIN_API

void Ghost::set_pos(unsigned int pos_x, unsigned int pos_y) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void Ghost::set_dir(int dir) {
    this->dir = dir;
}
int Ghost::get_dir() {
    return this->dir;
}

__END_API