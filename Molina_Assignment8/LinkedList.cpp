//
// Created by Barry Molina on 3/15/21.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    headPtr = nullptr;
    tailPtr = nullptr;

}

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

PersonNode* LinkedList::findInsertSpot(string lName) {
    PersonNode *node = headPtr,
               *prevNode = nullptr;

    while (node &&  lName > node->getLName()) {
        prevNode = node;
        node = node->getNext();
    }
    return prevNode;
}

PersonNode* LinkedList::getHeadPtr() {
    return headPtr;
}

void LinkedList::removePerson(string lName) {

}
