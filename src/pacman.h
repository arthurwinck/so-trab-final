class Pacman
{
    enum Direction {
        UP,
        LEFT,
        RIGHT,
        DOWN
    };

public:
    Pacman();
    ~Pacman();
private:
    float pos_x;
    float pos_y;
    Direction dir;
};