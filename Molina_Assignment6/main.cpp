/*
 * Barry Molina
 * ITDEV-185-900
 * Assignment 6
 */

#include <iostream>
#include "Player.h"
#include <iomanip>
using namespace std;

void setPlayerNum(Player players[], int numPlayers);
Player *findHighestTotal(Player players[], int numPlayers);
void displayPlayer(Player *pPlayer);

int main() {

    const int NUM_PLAYERS = 100;
    Player players[NUM_PLAYERS];
    Player *pPtr = nullptr;

    setPlayerNum(players, NUM_PLAYERS);

    for (Player &player : players)
    {
        player.play();
    }
//    for (Player &player : players)
//    {
//        cout << player.getPlayerNumber() << ":\t" << player.getSumOfDice() << endl;
//    }
    pPtr = findHighestTotal(players, NUM_PLAYERS);

    displayPlayer(pPtr);

    return 0;
}

void setPlayerNum(Player players[], int numPlayers)
{
    for (int x = 0; x < numPlayers; x++)
    {
        players[x].setPlayerNumber(x);
    }
}

Player *findHighestTotal(Player players[], int numPlayers)
{
    // pPtr will reference the address of the first element in array
    Player *pPtr = players;

    for (int x = 1; x < numPlayers; x++)
    {
        if (players[x].getSumOfDice() > pPtr->getSumOfDice())
        {
            // update pPtr to point to the player with the higher sum
            pPtr = &players[x];
        }
    }

    return pPtr;
}

void displayPlayer(Player *pPlayer)
{
    const int NUM_COLS = 5;
    int numRows;
    int numDice;
    int currDie;

    cout << "The winning player is player" << pPlayer->getPlayerNumber() << " amount = "
         << pPlayer->getSumOfDice() << endl << endl;


    numDice = pPlayer->getNumberOfDice();

    // find ceiling of integer division to get number of rows;
    numRows = numDice / NUM_COLS + (numDice % NUM_COLS != 0);

    currDie = 0;
    cout << left;

    for (int x = 0; x < numRows; x++)
    {
        for (int i = 0; i < NUM_COLS && currDie < numDice; i++)
        {
            cout << setw(8) << "dice" + to_string(currDie) + ":"
                 << pPlayer->getSingleDieValue(currDie) << "\t\t";

            currDie++;
        }
        cout << endl;
    }
}
