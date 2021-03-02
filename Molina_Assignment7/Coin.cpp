//
// Created by Barry Molina on 3/2/21.
//

#include <cstdlib>
#include <ctime>
#include "Coin.h"

double Coin::balance = 0;

Coin::Coin(double val)
{
    value = val;

    srand(time(0));
    toss();
}

bool Coin::getHeads()
{
    return heads;
}

double Coin::getValue()
{
    return value;
}

string Coin::getSideUp()
{
    return sideUp;
}

double Coin::getBalance()
{
    return balance;
}

void Coin::resetBalance()
{
    balance = 0.00;
}

void Coin::toss()
{
    heads = rand() % 2;

    sideUp = (heads ? "HEADS" : "tails");
}

void Coin::addBalance()
{
    balance += value;
}
