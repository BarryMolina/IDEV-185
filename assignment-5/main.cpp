#include <iostream>
#include <string>
#include "SlotMachine.h"
using namespace std;

int main() {
    SlotMachine slotMachine;
    int timesPlayed;
    bool quit = false;
    string again;

    cout << "\nFeelin' lucky? Welcome to SlotMachine, the" <<
            "\napp that will fulfill all your gambling needs." <<
            "\nThe goal is simple: spin the three reels on the" <<
            "\nslot machine until they all match." << endl;

    cout << "\nLets get started!" << endl;
    cout << "\nPress <enter> to begin" << endl;
    cin.get();

    while (!quit) {
        timesPlayed = 1;

        while (!slotMachine.play()) {
            timesPlayed++;
        }

        cout << timesPlayed << " tries to win." << endl;
        cout << "\nPlay again? y/n: ";
        cin >> again;

        if (tolower(again[0]) != 'y')
            quit = true;
    }

    cout << "\n\nThanks for playing!. Goodbye." << endl;

    return 0;
}
