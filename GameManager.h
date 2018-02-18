//
// Created by Admin on 17/02/2018.
//
#include <time.h>
#include <conio.h>

#ifndef UNTITLED_GAMEMANAGER_H
#define UNTITLED_GAMEMANAGER_H

class GameManager{
private:
    int width,height;
    int score1,score2;
    bool quit;
    Ball* ball;
    Paddle* p1;
    Paddle* p2;
    void processKey(char key);
public:
    GameManager(int width, int height);
    ~GameManager();
    void ScoreUp(Paddle* player);
    void Draw();
    void Input();
    void Logic();
    void Run();
};
GameManager::GameManager(int width, int height) : width(width), height(height),quit(false) {
    srand(time(NULL));
    score1 = score2 = 0;
    ball = new Ball(width/2,height/2);
    p1 = new Paddle(1,(height/2)-3,'w','s');
    p2 = new Paddle(width-3,(height/2)-3,'i','k');
}

GameManager::~GameManager(){
    delete ball,p1,p2;
}

void GameManager::ScoreUp(Paddle *player) {
    if(player==p1){
        score1++;
    }else if(player == p2){
        score2++;
    }
    ball->Reset();
    p1->Reset();
    p2->Reset();
}

void GameManager::Draw() {
    system("cls");
    for(int i = 0; i < width+1;i++){
        std::cout << "\xB2";
    }
    std::cout<<std::endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j==0 || j == width -1){
                std::cout << "\xB2";
            }
            if(ball->getX() == j && ball->getY() == i){
                std::cout << "O"; //Ball
            }else if(p1->getX() == j && (i>=p1->getY() && i<=p1->getY()+3)){
                std::cout << "\xDB"; //Player1
            }else if(p2->getX() == j && (i>=p2->getY() && i<=p2->getY()+3)) {
                std::cout << "\xDB"; // Player2
            }else{
                std::cout <<  " ";
            }
        }
        std::cout<<std::endl;
    }

    for(int i = 0; i < width+1;i++){
        std::cout << "\xDB";
    }
    std::cout<<std::endl;
    std::cout<<"Score 1: " << score1 << std::endl << "Score 2: " << score2 << std::endl;
}

void GameManager::Input() {
    ball->Move();
    if(_kbhit()){
        char current = _getch();
        processKey(current);
        if(ball->getDirection() == STOP){
            ball->randomDirection();
        }
    }
}

void GameManager::processKey(char key) {
    /*
        each key checked we check if the key moves one of the paddels
        refactor this later this is not so good twice the time if's are checked each run not so smart.
    */
    Paddle* p = KeyToPaddleMatching(p1,p2,key);
    p->tryMove(key,height);
    if(key == 'q'){
        quit = true;
    }
}

void GameManager::Logic() {
    if(p1->isCollision(ball,true)) { //Left paddle collision with ball
        ball->changeDiretion((eDir) ((rand() % 3) + 4));
    }
    if(p2->isCollision(ball, false)){ //right paddle collision with ball
        ball->changeDiretion((eDir)((rand()%3)+1));
    }
    //Ball hitting buttom wall;
    if(ball->getY()==height-1){
        ball->changeDiretion(ball->getDirection()==DOWN_RIGHT ? UP_RIGHT : UP_LEFT);
    }
    //Ball hitting top wall;
    if(ball->getY()==0){
        ball->changeDiretion(ball->getDirection()==UP_RIGHT ? DOWN_RIGHT: DOWN_LEFT);
    }
    //Ball hitting right wall
    if(ball->getX() == width-1){
        ScoreUp(p1);
    }
    //Ball hitting left wall;
    if(ball->getX() == 0){
        ScoreUp(p2);
    }
}

void GameManager::Run() {
    while(!quit){
        Draw();
        Input();
        Logic();
    }
}

Paddle* GameManager::KeyToPaddleMatching(Paddle** paddles,char key){
    for(Paddle* paddle : paddles){
        
    }
}

#endif //UNTITLED_GAMEMANAGER_H
