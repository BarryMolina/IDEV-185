//
// Created by Barry Molina on 2/14/21.
//

#ifndef REEL_H
#define REEL_H
#include <string>
using namespace std;


class Reel {
private:
    static const int NUM_FACES = 20;
    int faceIdx;
    string face;
    string faces[NUM_FACES] = {
            "lemon", "cherry", "banana", "seven", "diamond", "bell", "heart", "star", "strawberry", "grape",
            "bell", "horseshoe", "heart", "pear", "orange", "10", "king", "queen", "jack", "joker"
    };

public:
    Reel();
    void spin();
    string getFace();
    int getFaceIdx();
};


#endif //REEL_H
