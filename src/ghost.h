//Criar super classe personagem para englobar ghost e pacman
#include "traits.h"
__BEGIN_API

class Ghost
{
public:
    Ghost() {};
    ~Ghost();
    
    int get_dir();
    void set_dir(int dir);
    
    int get_pos();
    void set_pos(unsigned int pos_x, unsigned int pos_y);

private:
    int dir;
    int vida;
    int pos_x;
    int pos_y;
};

__END_API