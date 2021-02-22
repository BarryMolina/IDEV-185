//
// Created by Barry Molina on 2/22/21.
//

#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die() {
    srand(time(0));
    roll();
}

int Die::getValue() {

    return dieValue;
}

int Die::roll() {

    dieValue = rand() % 6 + 1;
}
