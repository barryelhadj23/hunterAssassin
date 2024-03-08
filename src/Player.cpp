
#include "Player.h"
#include "config_Variable.h"

Player::Player() :health(100){
    source = {0,0,PLAYER_WIDTH,PLAYER_HEIGHT};
    dest = {100,100,PLAYER_WIDTH*2,PLAYER_HEIGHT*2};
    spriteIMG = "../data/bardo.bmp";
}

Player::~Player() {
    health=0;
    source={0,0,0,0};
    dest={0,0,0,0};
    spriteIMG="";
}

void Player::testRegression() {
    //Constructeur par defaut du player
    Player playerTest;
    //Test des données du rectangle source
    assert(playerTest.source.x==0 && playerTest.source.y==0 && playerTest.source.w==PLAYER_WIDTH && playerTest.source.w==PLAYER_WIDTH);

    //Test des données du rectangle dest
    assert(playerTest.dest.x==100 && playerTest.dest.y==100 && playerTest.dest.w==PLAYER_WIDTH*2 && playerTest.dest.w==PLAYER_WIDTH*2);

    //chemin Image_Bmp
    assert(playerTest.spriteIMG=="../data/bardo.bmp");

    //Santé du joueur
    assert(playerTest.health == 100);

    std::cout<<"Teste de regression Nickel ;)";
}


