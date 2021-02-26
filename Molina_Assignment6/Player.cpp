//
// Created by Barry Molina on 2/22/21.
//

#include "Player.h"

Player::Player() {}

void Player::play()
{
    sumOfDice = 0;
    for(Die &die : dice)
    {
        die.roll();
        sumOfDice += die.getValue();
    }
}

int Player::getNumberOfDice()
{
    return NUM_DICE;
}

int Player::getPlayerNumber()
{
    return playerNumber;
}

int Player::getSingleDieValue(int dieIndex)
{
    return dice[dieIndex].getValue();
}

int Player::getSumOfDice()
{
    return sumOfDice;
}

void Player::setPlayerNumber(int playerNum)
{
    playerNumber = playerNum;
}
