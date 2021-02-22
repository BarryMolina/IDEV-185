//
// Created by Barry Molina on 2/22/21.
//

#ifndef MOLINA_ASSIGNMENT6_PLAYER_H
#define MOLINA_ASSIGNMENT6_PLAYER_H

#include "Die.h"

class Player {

private:
    Die dice[20];
    int playerNumber;
    int sumOfDice;

public:
    Player();
    void play();
    int getNumberOfDice();
    int getPlayerNumber();
    int getSingleDieValue();
    int getSumOfDice();
    void setPlayerNumber(int);
};


#endif //MOLINA_ASSIGNMENT6_PLAYER_H
