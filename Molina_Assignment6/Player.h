//
// Created by Barry Molina on 2/22/21.
//

#ifndef MOLINA_ASSIGNMENT6_PLAYER_H
#define MOLINA_ASSIGNMENT6_PLAYER_H

#include "Die.h"

class Player {

private:
    static const int NUM_DICE = 20;
    Die dice[NUM_DICE];
    int playerNumber;
    int sumOfDice = 0;

public:
    Player();
    Player(int);
    void play();
    int getNumberOfDice();
    int getPlayerNumber();
    int getSingleDieValue(int);
    int getSumOfDice();
    void setPlayerNumber(int);
};


#endif //MOLINA_ASSIGNMENT6_PLAYER_H
