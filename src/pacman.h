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
    void set_step(int step);
    int get_step();
    void inc_step();
    void dec_step();
    void update(int dir, char* tilemap);
    void changetile();
    void move(char* tilemap);
    void set_pontos(int pontos);
    void inc_pontos();
    int get_pontos();
    void check_points(char* tilemap, int pos);

private:
    int dir;
    int vida;
    int pos_x;
    int pos_y;
    int step;
    int pontos;
};

__END_API

#endif