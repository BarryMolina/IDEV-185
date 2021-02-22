/*
 * Barry Molina
 * ITDEV-185-900
 * Assignment 6
 */

#include <iostream>
#include "Die.h"
using namespace std;

int main() {
    Die die;

    for (int x = 0; x < 10; x++) {
        die.roll();
        cout << die.getValue() << " ";
    }
    return 0;
}
