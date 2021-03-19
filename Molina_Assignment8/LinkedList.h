//
// Created by Barry Molina on 3/15/21.
//

#ifndef MOLINA_ASSIGNMENT8_LINKEDLIST_H
#define MOLINA_ASSIGNMENT8_LINKEDLIST_H

#include "PersonNode.h"
#include <string>
using namespace std;


class LinkedList {
private:
    PersonNode *headPtr;
    PersonNode *tailPtr;
public:
    LinkedList();
    void addLink(PersonNode *person);
    PersonNode* findInsertSpot(string lName);
    PersonNode* getHeadPtr();
    void removePerson(string lName);
};


#endif //MOLINA_ASSIGNMENT8_LINKEDLIST_H
