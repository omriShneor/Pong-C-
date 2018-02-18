#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"


int main(){
    GameManager game(40,20);
    game.Run();
    return 0;
};


