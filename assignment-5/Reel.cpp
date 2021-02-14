//
// Created by Barry Molina on 2/14/21.
//

#include "Reel.h"
#include <ctime>;
#include <cstdlib>;

Reel::Reel() {
    srand(time(0));
    spin();
}

void Reel::spin() {
    faceIdx = rand() % NUM_FACES;
    face = faces[faceIdx];
}

string Reel::getFace() {
    return face;
}

int Reel::getFaceIdx() {
    return faceIdx;
}
