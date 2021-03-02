//
// Created by Barry Molina on 3/2/21.
//

#ifndef MOLINA_ASSIGNMENT7_COIN_H
#define MOLINA_ASSIGNMENT7_COIN_H

#include <string>
using namespace std;

class Coin {
private:
    static double balance;
    string sideUp;
    bool heads;
    double value;

public:
    Coin(double);
    bool getHeads();
    double getValue();
    string getSideUp();
    static double getBalance();
    static void resetBalance();
    void toss();
    void addBalance();
};

// Derived Class Definitions
// Each derived class calls the parameterized constructor of the Coin superclass with the appropriate value.
class Quarter : public Coin
{
public:
    Quarter() : Coin(0.25) {}
};

class Dime : public Coin
{
public:
    Dime() : Coin(0.10) {}
};

class Nickel : public Coin
{
public:
    Nickel() : Coin(0.05) {}
};

#endif //MOLINA_ASSIGNMENT7_COIN_H
