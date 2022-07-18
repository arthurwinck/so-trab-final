#include "pacman.h"
#include <iostream>
__BEGIN_API

Pacman::Pacman(int pos_x, int pos_y) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    dir = 0;
    step=5;
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

void Pacman::inc_step(){
    this->step+=2;
}

void Pacman::dec_step(){
    this->step-=2;
}

void Pacman::move(char* tilemap){
    std::cout<<dir;
    switch (dir){
        case 0:
            if (tilemap[pos_y*28 + pos_x - 1] != 'W') {this->dec_step();;};
            break;
        case 1:
            if (tilemap[pos_y*28 + pos_x + 1] != 'W') {this->inc_step();};
            break;
        case 2:
            if (tilemap[(pos_y + 1)*28 + pos_x] != 'W') {this->inc_step();};
            break;
        case 3:
            if (tilemap[(pos_y-1)*28 + pos_x] != 'W') {this->dec_step();};
            break;
    }
}

void Pacman::changetile(){
    if (this->step<=0){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->get_pos_x())-1,this->get_pos_y());
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->get_pos_x(),(this->get_pos_y())-1);
        }
        this->set_step(7);
    } else if (this->step>=8){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->get_pos_x())+1,this->get_pos_y());
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->get_pos_x(),(this->get_pos_y())+1);
        }
        this->set_step(4);
    }
}

void Pacman::set_step(int step){
    this->step=step;
}

int Pacman::get_step(){
    return this->step;
}

void Pacman::update(int newdir, char* tilemap) {
    
    //this->set_dir(newdir);
    

    // Atualização em TILES (?)

    //Left
    if (newdir == 0) {
        std::cout << "Vou ir para a esquerda!";
        if (tilemap[pos_y*28 + pos_x - 1] != 'W') {
            this->set_dir(newdir);
        }
        std::cout << "Fui para a esquerda!";

    //Right
    } else if (newdir == 1) {
        std::cout << "Vou ir para a direita!";
        if (tilemap[pos_y*28 + pos_x + 1] != 'W') {
            this->set_dir(newdir);
        }
        std::cout << "Fui para a direita!";

    //Down
    } else if (newdir == 2) {
        std::cout << "Vou ir para abaixo!";

        if (tilemap[(pos_y + 1)*28 + pos_x] != 'W') {
            this->set_dir(newdir);
        }
        std::cout << "Fui para abaixo!";

    //Up
    } else if (newdir == 3) {
        std::cout << "Vou ir para cima!";

        if (tilemap[(pos_y-1)*28 + pos_x] != 'W') {
            this->set_dir(newdir);
        }
        std::cout << "Fui para abaixo!";
    }


    //If dir == -1, do nothing

}

__END_API