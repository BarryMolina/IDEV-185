//
// Created by Barry Molina on 3/15/21.
//

#include "LinkedList.h"

// Default constructor
LinkedList::LinkedList() {
    headPtr = nullptr;
    tailPtr = nullptr;
}

// Getters
PersonNode* LinkedList::getHeadPtr() {
    return headPtr;
}

PersonNode* LinkedList::getTailPtr() {
    return tailPtr;
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
            if (tailPtr == node) {
                // update tailPtr
                tailPtr = person;
            }
        }
    }
}

// Find location to insert new node
// Returns a pointer to the node preceding the new insertion spot
// Returns nullptr if inserting at the start of the list
PersonNode* LinkedList::findInsertSpot(string lName) {
    // new node must be inserted at beginning of list
    if (lName < headPtr->getLName()) {
        return nullptr;
    }
    // new node must be inserted at end of list
    else if (lName > tailPtr->getLName()) {
        return tailPtr;
    }
    else {
        // find insert spot
        PersonNode *node = headPtr, *prevNode;

        while (node && lName > node->getLName()) {
            prevNode = node;
            node = node->getNext();
        }
        return prevNode;
    }
}


// Finds node by last name and removes it if found.
bool LinkedList::removePerson(string lName) {
    PersonNode *node, *prevNode;
    bool foundIt = false;

    node = headPtr;

    // check to see if removing first item in list
    if (node->getLName() == lName) {
        // remove first link in list
        foundIt = true;
        headPtr = headPtr->getNext();
        // check to see if removing only item in list
        if (node == tailPtr) {
            // reset tailPtr
            tailPtr = nullptr;
        }
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
            // check to see if removing last item in list
            if (node == tailPtr) {
                // update tailPtr
                tailPtr = prevNode;
            }
            delete node;
        }
    }
    return foundIt;
}
