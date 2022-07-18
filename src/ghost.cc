#include "ghost.h"
#include <cmath>
#include <iostream>

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

void Ghost::set_target(int pac_pos_x, int pac_pos_y, char* tilemap){
    this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap));

}


int Ghost::shortest_distance_path(int pac_pos_x, int pac_pos_y, char* tilemap){
    int arr[]={999,999,999,999};
    std::cout<< "teste10";
    std::cout << "access tilemap index: " << pos_y*28+pos_x-1 << "\n"; 
    if ((tilemap[pos_y*28 + pos_x - 1] != 'W') && (this->get_dir()!=1)){ //tile a esquerda não é parede
        arr[0] = abs(pos_y - pac_pos_y) + abs(pos_x-1 - pac_pos_x); 
    } 
    if ((tilemap[pos_y*28 + pos_x + 1] != 'W') && (this->get_dir()!=0)) { //tile a direita não parede
        arr[1] = abs(pos_y - pac_pos_y) + abs(pos_x+1 - pac_pos_x); 
    }
    if ((tilemap[(pos_y + 1)*28 + pos_x] != 'W') && (this->get_dir()!=3)) { //tile abaixo não parede
        arr[2] = abs(pos_y+1 - pac_pos_y) + abs(pos_x - pac_pos_x); 
    }
    if ((tilemap[(pos_y-1)*28 + pos_x] != 'W') && (this->get_dir()!=2)){ //tile acima não parede
        arr[3] = abs(pos_y-1 - pac_pos_y) + abs(pos_x - pac_pos_x); 
    }
    int dist= arr[0]; //path vai ser o menor caminho
    int path= 0;
    for ( int i = 1; i < 4; i++ ) {
        if ( dist > arr[i] ) {
            dist = arr[i];
            path=i;
        }
    };
    return path;

    };



void Ghost::inc_step(){
    this->step+=1;
}

void Ghost::dec_step(){
    this->step-=1;
}

void Ghost::move(){
    std::cout<<dir;
    switch (dir){
        case 0:
            this->dec_step();
            break;
        case 1:
            this->inc_step();
            break;
        case 2:
            this->inc_step();
            break;
        case 3:
            this->dec_step();
            break;
    }
}

void Ghost::changetile(int pac_pos_x, int pac_pos_y, char* tilemap){
    if (this->step<=0){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->pos_x)-1,this->pos_y);
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->pos_x,(this->pos_y)-1);
        }
        this->set_step(7);
        this->set_target(pac_pos_x, pac_pos_y, tilemap);
    } else if (this->step>=8){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->pos_x)+1,this->pos_y);
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->pos_x,(this->pos_y)+1);
        }
        this->set_step(4);
        this->set_target(pac_pos_x, pac_pos_y, tilemap);
    }
}

void Ghost::set_step(int step){
    this->step=step;
}

int Ghost::get_step(){
    return this->step;
}

int Ghost::get_pos_x() {
    return this->pos_x;
}

int Ghost::get_pos_y() {
    return this->pos_y;
}


__END_API