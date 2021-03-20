//
// Created by Barry Molina on 3/15/21.
//

#include "PersonNode.h"

// Getters and setters
const string &PersonNode::getAddress() const {
    return address;
}

void PersonNode::setAddress(const string &address) {
    PersonNode::address = address;
}

const string &PersonNode::getFName() const {
    return fName;
}

void PersonNode::setFName(const string &fName) {
    PersonNode::fName = fName;
}

const string &PersonNode::getLName() const {
    return lName;
}

void PersonNode::setLName(const string &lName) {
    PersonNode::lName = lName;
}

const string &PersonNode::getPhone() const {
    return phone;
}

void PersonNode::setPhone(const string &phone) {
    PersonNode::phone = phone;
}

PersonNode *PersonNode::getNext() const {
    return next;
}

void PersonNode::setNext(PersonNode *next) {
    PersonNode::next = next;
}

string PersonNode::getFullName() {
    return lName + ", " + fName;
}

// Constructors
PersonNode::PersonNode() {
    next = nullptr;
}

PersonNode::PersonNode(const string &fName, const string &lName, const string &address, const string &phone) : fName(
        fName), lName(lName), address(address), phone(phone) {
    next = nullptr;
}
