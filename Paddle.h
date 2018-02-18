//
// Created by Admin on 16/02/2018.
//

#ifndef UNTITLED_PADDLE_H
#define UNTITLED_PADDLE_H


#include <iostream>

class Paddle {
private:
    int x,y;
    int originalX,originalY;
    char up,down;
    bool isValidMove(char key,int boardHeight);
public:
    Paddle():x(0),y(0),up('w'),down('s'){};
    Paddle(int posX,int posY,char up,char down):originalX(posX),originalY(posY),x(posX),y(posY),up(up),down(down){};
    inline void Reset();
    inline int getX(){return this->x;}
    inline int getY(){return this->y;}
    inline void moveUp(){ y--;}
    inline void moveDown(){ y++;}
    inline char downKey(){return this->down;}
    inline char upKey(){return this->up;}
    friend std::ostream& operator<<(std::ostream& o, const Paddle& paddle);
    void tryMove(char key,int boardHeight);
    bool isCollision(Ball *ball,bool LeftPlayer);
};

void Paddle::Reset() {
    x = originalX;
    y = originalY;

}

std::ostream &operator<<(std::ostream &o, const Paddle &paddle) {
    o << "Paddle [" << paddle.x << "," <<  paddle.y << "]";
    return o;
}

bool Paddle::isValidMove(char key,int boardHeight) {
    return ((key == up && y > 0) || key == down && y+4 < boardHeight);
}

void Paddle::tryMove(char key,int boardHeight) {
    if(!isValidMove(key,boardHeight)) return;
    if(key == upKey()){
        moveUp();
    } else if(key == downKey()){
        moveDown();
    }
    return;
}

bool Paddle::isCollision(Ball *ball,bool LeftPlayer) {
    if(!ball) return false;
    //Collision logic for left player
    if(LeftPlayer && (ball->getY()<=y+3&&ball->getY()>=y)&&(ball->getX()==x+1)){
        return true;
    //Collision logic for right player
    }else if(!LeftPlayer && (ball->getY()<=y+3&&ball->getY()>=y)&&(ball->getX()==x-1)){
        return true;
    }
    return false;
}


#endif //UNTITLED_PADDLE_H
