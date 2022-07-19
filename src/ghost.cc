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
    switch (this->type){
        case 0:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,0,0));

        case 3: 
            if  (abs(pos_y-1 - pac_pos_y) + abs(pos_x - pac_pos_x) < 8){
                this->set_dir(this->shortest_distance_path(0, 31, tilemap,0,0));
            } else {
                this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,0,0));
            }
    }
    //this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap));

}

int Ghost::get_state(){
    return this->state;
}

int Ghost::shortest_distance_path(int pac_pos_x, int pac_pos_y, char* tilemap, int offset_x, int offset_y){
    int arr[]={999,999,999,999};
    //std::cout << "access tilemap index: " << pos_y*28+pos_x-1 << "\n"; 
    if ((tilemap[pos_y*28 + pos_x - 1] != 'W') && (this->get_dir()!=1)){ //tile a esquerda não é parede
        arr[0] = abs(pos_y - pac_pos_y + offset_y) + abs(pos_x-1 - pac_pos_x+offset_x); 
    } 
    if ((tilemap[pos_y*28 + pos_x + 1] != 'W') && (this->get_dir()!=0)) { //tile a direita não parede
        arr[1] = abs(pos_y - pac_pos_y + offset_y) + abs(pos_x+1 - pac_pos_x + offset_x); 
    }
    if ((tilemap[(pos_y + 1)*28 + pos_x] != 'W' && (tilemap[(pos_y + 1)*28 + pos_x] != 'G')) && (this->get_dir()!=3)) { //tile abaixo não parede
        arr[2] = abs(pos_y+1 - pac_pos_y + offset_y) + abs(pos_x - pac_pos_x + offset_x); 
    }
    if ((tilemap[(pos_y-1)*28 + pos_x] != 'W') && (this->get_dir()!=2)){ //tile acima não parede
        arr[3] = abs(pos_y-1 - pac_pos_y + offset_y) + abs(pos_x - pac_pos_x + offset_x); 
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

void Ghost::state_update(int pac_x, int pac_y){
    this->state_timer= this->state_timer-1;
    switch (this->state){
        case 1:
            if (this->state_timer<0){
                this->state=2;
                this->state_timer=270;
            };
            break;
        case 2:
            if (this->state_timer<0){
                this->state=1;
                this->state_timer=270;
            };
            break;
        case 3:
            if (this->get_pos_x()==pac_x && this->get_pos_y()==pac_y){
                this->state=6;
                this->set_pos(13,13);
                this->state_timer=270;
                this->set_dir(0);
            } else if (this->state_timer<0){
                this->state=4;
                this->state_timer=32;
            };
            break;
        case 4:
            if (this->get_pos_x()==pac_x && this->get_pos_y()==pac_y){
                this->state=6;
                this->set_pos(13,13);
                this->state_timer=270;
                this->set_dir(0);
            } else if (this->state_timer<0){
                this->state=1;
                this->state_timer=270;
            };
            break;
        case 5:
            if (this->pos_x==13 && this->pos_y==17) {
                this->state = 6;
                this->state_timer=16* 7;
            };
            break;
        case 6:
            if (this->state_timer<0){
                this->state=1;
                this->set_pos(13,11);
                this->set_dir(0);
                this->state_timer=270;
             };
             break;
    };
}

void Ghost::move(int energized){
    if (energized>=1){
        this->state=3;
        this->state_timer=50;
    }
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



void Ghost::changetile(int pac_pos_x, int pac_pos_y, int pac_dir, char* tilemap){
    if (this->pos_x<1){
        this->set_pos(25,14);
        this->step=4;
        this->set_dir(0);
    }else if (this->pos_x>26){
        this->set_pos(1,14);
        this->step=4;
        this->set_dir(1);
    } else if (this->step<=0){
        if ((dir==0) or (dir==1)){
            this->set_pos((this->pos_x)-1,this->pos_y);
        } else if ((dir==2) or (dir==3)){
            this->set_pos(this->pos_x,(this->pos_y)-1);
        }
        this->set_step(4);
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