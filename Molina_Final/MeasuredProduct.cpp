//
// Created by Barry Molina on 3/11/21.
//

#include "MeasuredProduct.h"

// Calls the Item superclass constructor with given values
MeasuredProduct::MeasuredProduct(string name, double price, int quantity) : Item(name, price) {
    this->quantity = quantity;
}

// Returns the total calculated price
double MeasuredProduct::calcFullPrice() {
    return getPrice() * quantity;
}

// Returns quantity
int MeasuredProduct::getQuantity() {
    return quantity;
}

// Set quantity
void MeasuredProduct::setQuantity(int quantity) {
    this->quantity = quantity;
}

// return product quantity amount
int MeasuredProduct::amount() {
    return quantity;
}

