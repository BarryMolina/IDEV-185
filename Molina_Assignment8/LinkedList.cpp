//
// Created by Barry Molina on 3/15/21.
//

#include "LinkedList.h"

// Default constructor
LinkedList::LinkedList() {
    headPtr = nullptr;
    tailPtr = nullptr;
}

// Add a new link to list
void LinkedList::addLink(PersonNode *person) {
    // list is empty
    if (!headPtr) {
        headPtr = tailPtr = person;
    }
    // insert in list
    else {
        PersonNode *node = findInsertSpot(person->getLName());
        if (!node) {
            // insert at start of list
            person->setNext(headPtr);
            headPtr = person;
        }
        else {
            // insert after node
            person->setNext(node->getNext());
            node->setNext(person);
        }
    }
}

// Find location to insert new node
PersonNode* LinkedList::findInsertSpot(string lName) {
    PersonNode *node = headPtr,
               *prevNode = nullptr;

    while (node && lName > node->getLName()) {
        prevNode = node;
        node = node->getNext();
    }
    return prevNode;
}

PersonNode* LinkedList::getHeadPtr() {
    return headPtr;
}

// Finds node by last name and removes it if found.
bool LinkedList::removePerson(string lName) {
    PersonNode *node = headPtr,
            *prevNode = nullptr;
    bool foundIt = false;

    if (node->getLName() == lName) {
        // remove first link in list
        foundIt = true;
        headPtr = headPtr->getNext();
        delete node;
    }
    else {
        // find node to remove
        while (node && lName != node->getLName()) {
            prevNode = node;
            node = node->getNext();
        }
        if (node) {
            // Node was found. Remove it.
            foundIt = true;
            prevNode->setNext(node->getNext());
            delete node;
        }
    }
    return foundIt;
}
