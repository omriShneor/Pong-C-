#include <iostream>

enum eDir{STOP = 0,LEFT = 1,UP_LEFT = 2,DOWN_LEFT = 3, RIGHT = 4,UP_RIGHT = 5,DOWN_RIGHT = 6};
class Ball{
private:
    int originalX,originalY;
    int x,y;
    eDir direction;

public:
    Ball(int posX,int posY):originalX(posX),originalY(posY),x(posX),y(posY),direction(STOP){};
    void Reset();
    void changeDiretion(const eDir direction);
    inline int getX(){return this->x;};
    inline int getY(){return this->y;};
    inline eDir getDirection(){return this->direction;}
    const eDir randomDirection();
    void Move();
    friend std::ostream& operator<<(std::ostream& o,const Ball& c);

};

void Ball::Reset() {
    x = originalX;
    y = originalY;
    direction = STOP;
}

void Ball::changeDiretion(const eDir direction) {
    this->direction = direction;
}

const eDir Ball::randomDirection() {
    //Generate numbers for 1-6 to avoid direction = STOP
    this->direction = (eDir)(rand()%6+1);
}

void Ball::Move(){
    switch (direction){
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP_LEFT:
            x--,y--;
            break;
        case DOWN_LEFT:
            x--,y++;
            break;
        case UP_RIGHT:
            x++,y--;
            break;
        case DOWN_RIGHT:
            x++,y++;
            break;
        default:
            break;
    }
}

std::ostream &operator<<(std::ostream &o, const Ball &c) {
    o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
    return o;
}
