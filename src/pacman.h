class Pacman
{
public:
    Pacman() {
        vida=3;
        dir= Direction::LEFT;
        tileposx=14;
        tileposy=23;
        step=5;

    };
    ~Pacman();
    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    int getdir(){
        switch (dir){
            case Direction::LEFT:
                return 1;
            case Direction::UP:
                return 4;
            case Direction::DOWN:
                return 2;
            case Direction::RIGHT:
                return 3;
        }
        return 1;
    }

    int getgrid(){
        return (28*tileposy + tileposx);
    }

    int getstep(){
        return step;
    }

    void updatepacman(int newdir){
        if (newdir!=getdir()){
            switch (newdir){
                case 1:
                    if (maze[tileposy*28 + tileposx -1]!='W') {
                        dir= Direction::LEFT;
                        step= 6;
                    }
                case 2:
                    if (maze[(tileposy+1)*28 + tileposx ]!='W') {
                        dir= Direction::DOWN;
                        step= 8;
                    }
                case 3:
                    if (maze[tileposy*28 + tileposx +1]!='W') {
                        dir= Direction::RIGHT;
                        step= 8;
                    }
                case 4:
                    if (maze[(tileposy-1)*28 + tileposx]!='W') {
                        dir= Direction::UP;
                        step= 6;
                    }
                    
            }
        } else {
            switch (dir) {
                case Direction::LEFT:
                    step-=1;
                    if ((maze[tileposy*28 + tileposx -1]=='W') && ( step<=6)) {
                        step=6;
                    } else if (step<=0) {
                        tileposx-=1;
                        step=15;
                    }
                case Direction::DOWN:
                    step+=1;
                    if ((maze[(tileposy+1)*28 + tileposx ]=='W') && (step>=8)) {
                        step=8;
                    } else if (step>=15) {
                        tileposy+=1;
                        step=0;
                    }
                case Direction::RIGHT:
                    step+=1;
                    if ((maze[tileposy*28 + tileposx +1]=='W') && (step>=8)){
                        step=8;
                    } else if (step>=15) {
                        tileposx+=1;
                        step=0;
                    }
                case Direction::UP:
                    step-=1;
                    if ((maze[(tileposy-1)*28 + tileposx]!='W') && (step<=6)){
                        step=6;
                    } else if (step<=0) {
                        tileposy-=1;
                        step=15;
                    }
            };
        }
        };


    char maze[868] = {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W',
'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'O', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'O', 'W',
'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'G', 'G', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'u', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'u', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
'P', 'u', 'u', 'u', 'u', 'u', 'o', 'u', 'u', 'u', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'u', 'u', 'u', 'o', 'u', 'u', 'u', 'u', 'u', 'P',
'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'u', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'u', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'O', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'O', 'W',
'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W',
'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W',
'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W',
'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'};




private:
    int vida;
    int tileposx;
    int tileposy;
    int step;
    Direction dir;
};