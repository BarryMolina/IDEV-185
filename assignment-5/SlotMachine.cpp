//
// Created by Barry Molina on 2/14/21.
//

#include <iostream>
#include <iomanip>
#include "SlotMachine.h"

using namespace std;

bool SlotMachine::play() {
    int reelFace;
    bool winner = true;

    for (Reel &reel : reels) {
        reel.spin();
        cout << left << setw(14) << reel.getFace();
    }
    cout << endl;

    reelFace = reels[0].getFaceIdx();

    // Match first reel with subsequent reels to determine win
    for (int x = 1; winner && x < NUM_REELS; x++) {
        if (reelFace != reels[x].getFaceIdx()) {
            winner = false;
        }
    }

    if (winner) {
        cout << "\nWinner!!!!" << endl;
    }

    return winner;
}
