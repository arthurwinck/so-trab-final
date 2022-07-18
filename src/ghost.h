//Criar super classe personagem para englobar ghost e pacman
#include "traits.h"
__BEGIN_API

class Ghost
{
public:
    Ghost(int pos_x, int pos_y, int type) {this->pos_x = pos_x; this->pos_y = pos_y; this->dir = 0; this->step = 4; this->type=type;};
    ~Ghost();
    
    int get_dir();
    void set_dir(int dir);
    
    int get_pos_x();
    int get_pos_y();

    void set_pos(unsigned int pos_x, unsigned int pos_y);

    void set_target(int pac_pos_x, int pac_pos_y, char* tilemap);
    int shortest_distance_path(int pac_pos_x, int pac_pos_y, char* tilemap, int offset_x, int offset_y);
    void set_step(int step);
    int get_step();
    void inc_step();
    void dec_step();
    void changetile(int pac_pos_x, int pac_pos_y, int pac_dir, char* tilemap);
    void move();
    int get_state();
private:
    int dir;
    int pos_x;
    int pos_y;
    int state; //1-Chase 2-Scatter 3-Frightened 4-Eaten 5-InJail
    int state_timer;
    int step;
    int type;
};

__END_API