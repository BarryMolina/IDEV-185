//
// Created by Barry Molina on 3/15/21.
//

#include "PersonNode.h"

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

PersonNode::PersonNode(const string &address, const string &fName, const string &lName, const string &phone) : address(
        address), fName(fName), lName(lName), phone(phone) {
    next = nullptr;
}

PersonNode::PersonNode() {
    next = nullptr;
}
