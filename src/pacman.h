#ifndef pacman_h
#define pacman_h

#include "traits.h"
__BEGIN_API
class Pacman
{
public:
    Pacman() {};
    Pacman(int pos_x, int pos_y);

    ~Pacman();
    
    int get_dir();
    void set_dir(int dir);
    
    int get_pos_x();
    int get_pos_y();
    void set_pos(unsigned int pos_x, unsigned int pos_y);

    void update(int dir, char* tilemap);

private:
    int dir;
    int vida;
    int pos_x;
    int pos_y;
};

__END_API

#endif