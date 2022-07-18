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
    std::cout << "access tilemap index: " << pos_y*28+pos_x-1 << "\n"; 
    if (tilemap[pos_y*28 + pos_x - 1] != 'W'){ //tile a esquerda não é parede
        arr[0] = sqrt(pow(((pos_x-1) -pac_pos_x),2) + pow((pos_y-pac_pos_y),2)); 
    } 
    if (tilemap[pos_y*28 + pos_x + 1] != 'W') { //tile a direita não parede
        arr[1] = sqrt(pow(((pos_x+1) -pac_pos_x),2) + pow((pos_y-pac_pos_y),2));
    }
    if (tilemap[(pos_y + 1)*28 + pos_x] != 'W') { //tile abaixo não parede
        arr[2] = sqrt(pow(((pos_x) -pac_pos_x),2) + pow(((pos_y+1)-pac_pos_y),2));
    }
    if (tilemap[(pos_y-1)*28 + pos_x] != 'W'){ //tile acima não parede
        arr[3] = sqrt(pow(((pos_x) -pac_pos_x),2) + pow(((pos_y-1)-pac_pos_y),2));
    }
    int path= arr[0]; //path vai ser o menor caminho
    for ( int i = 1; i < 4; i++ ) {
        if ( path > arr[i] ) {
            path = arr[i];
        }
    }
    for ( int i = 1; i < 4; i++ ) {
        if ( path = arr[i] ) {
            return i; //achar posição/direção com menor caminho
        }

    }
    return 0;


}

void Ghost::inc_step(){
    this->step+=2;
}

void Ghost::dec_step(){
    this->step-=2;
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

void Ghost::changetile(){
    if (this->step<=0){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->pos_x)-1,this->pos_y);
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->pos_x,(this->pos_y)-1);
        }
        this->set_step(7);
    } else if (this->step>=8){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->pos_x)+1,this->pos_y);
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->pos_x,(this->pos_y)+1);
        }
        this->set_step(4);
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