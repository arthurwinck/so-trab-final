#include "ghost.h"

class Blinky: private Ghost{
    void changefile(int pac_pos_x, int pac_pos_y, char * tilemap){
        this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,0,0));
    }
};


class Pinky: private Ghost{
    void changetile(int pac_pos_x, int pac_pos_y,int pac_dir, char* tilemap){
    if (this->get_step()<=0){
        if ((this->get_dir()==0) or (this->get_dir()==1)){
            this->set_pos((this->get_pos_x())-1,this->get_pos_y());
        } else if ((this->get_dir()==2) or (this->get_dir()==3)){
            this->set_pos(this->get_pos_x(),(this->get_pos_y())-1);
        }
        this->set_step(4);
        this->set_target(pac_pos_x, pac_pos_y,pac_dir, tilemap);
    } else if (this->get_step()>=8){
        if ((this->get_dir()==0) or (this->get_dir()==1)){
            this->set_pos((this->get_pos_x())+1,this->get_pos_y());
        } else if ((this->get_dir()==2) or (this->get_dir()==3)){
            this->set_pos(this->get_pos_x(),(this->get_pos_y())+1);
        }
        this->set_step(4);
        this->set_target(pac_pos_x, pac_pos_y,pac_dir, tilemap);
    }
    }

    void set_target(int pac_pos_x, int pac_pos_y,int pac_dir, char* tilemap){
    switch (pac_dir){
        case 0:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,-4,0));
        case 1:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,4,0));
        case 2:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,0,4));
        case 3: this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,-1,-4));
    }
    //this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap));

}
    
};
class Inky: private Ghost{
    void changetile(int pac_pos_x, int pac_pos_y,int blinky_x, int blinky_y,int pac_dir, char* tilemap){
    if (this->get_step()<=0){
        if ((this->get_dir()==0) or (this->get_dir()==1)){
            this->set_pos((this->get_pos_x())-1,this->get_pos_y());
        } else if ((this->get_dir()==2) or (this->get_dir()==3)){
            this->set_pos(this->get_pos_x(),(this->get_pos_y())-1);
        }
        this->set_step(4);
        this->set_target(pac_pos_x, pac_pos_y,pac_dir, tilemap);
    } else if (this->get_step()>=8){
        if ((this->get_dir()==0) or (this->get_dir()==1)){
            this->set_pos((this->get_pos_x())+1,this->get_pos_y());
        } else if ((this->get_dir()==2) or (this->get_dir()==3)){
            this->set_pos(this->get_pos_x(),(this->get_pos_y())+1);
        }
        this->set_step(4);
        int target_x= 
        this->set_target(pac_pos_x, pac_pos_y,blinky_x, blinky_y, tilemap);
    }
    }

    void set_target(int pac_pos_x, int pac_pos_y,int blinky_x,int blinky_y, int pac_dir, char* tilemap){
    switch (pac_dir){

        case 0:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,-2 + (pac_pos_x-blinky_x),0 +  (pac_pos_y-blinky_y)));
        case 1:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,2+ (pac_pos_x-blinky_x),0+  (pac_pos_y-blinky_y)));
        case 2:this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,0+ (pac_pos_x-blinky_x),2+  (pac_pos_y-blinky_y)));
        case 3: this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,-1+ (pac_pos_x-blinky_x),-2+  (pac_pos_y-blinky_y)));
    }
    //this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap));

};
    
};
class Clyde: private Ghost{
    void set_target(int pac_pos_x, int pac_pos_y,int pac_dir, char* tilemap){
        if  (abs(this->get_pos_y()-1 - pac_pos_y) + abs(this->get_pos_x() - pac_pos_x) < 8){
            this->set_dir(this->shortest_distance_path(0, 31, tilemap,0,0));
        } else {
            this->set_dir(this->shortest_distance_path(pac_pos_x, pac_pos_y, tilemap,0,0));
        }
    
};

__END_API