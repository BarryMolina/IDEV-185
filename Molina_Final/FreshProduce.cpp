//
// Created by Barry Molina on 3/11/21.
//

#include <sstream>
#include <iomanip>
#include "FreshProduce.h"

// Calls the Item superclass constructor with given values
FreshProduce::FreshProduce(string name, double price, double pounds) : Item(name, price) {
    this->pounds = pounds;
}

// Return the total calculated price
double FreshProduce::calcFullPrice() {
    return getPrice() * pounds;
}

// Return pounds
double FreshProduce::getPounds() {
    return pounds;
}

// Set pounds
void FreshProduce::setPounds(double p) {
    pounds = p;
}

// return amount of product as int
int FreshProduce::amount() {
    return pounds;
}
