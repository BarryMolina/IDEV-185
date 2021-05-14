//
// Created by Barry Molina on 3/11/21.
//

#include "Item.h"

// Define static variables
double Item::delivery = 0;
double Item::tip = 0;

// Default constructor
Item::Item() { }

// Initialize item name and price
Item::Item(string name, double price) {
    this->name = name;
    this->price = price;
}

// Getters & Setters
double Item::getDelivery() {
    return delivery;
}

double Item::getTip() {
    return tip;
}

string Item::getName() {
    return name;
}

double Item::getPrice() {
    return price;
}

void Item::setDelivery(double delivery) {
    Item::delivery = delivery;
}

void Item::setTip(double tip) {
    Item::tip = tip;
}

void Item::setName(string name) {
    this->name = name;
}

void Item::setPrice(double price) {
    this->price = price;
}

// Virtual destructor must have definition body even if empty
Item::~Item() { }

