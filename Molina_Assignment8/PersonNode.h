//
// Created by Barry Molina on 3/15/21.
//

#ifndef MOLINA_ASSIGNMENT8_PERSONNODE_H
#define MOLINA_ASSIGNMENT8_PERSONNODE_H

#include <string>
using namespace std;

// This class is used to create node objects for a linked list.
// It represents a person in a contact directory.
class PersonNode {
private:
    string fName;
    string lName;
    string address;
    string phone;
    PersonNode *next;
public:
    PersonNode();
    PersonNode(const string &fName, const string &lName, const string &address, const string &phone);
    const string &getAddress() const;
    const string &getFName() const;
    const string &getLName() const;
    const string &getPhone() const;
    PersonNode *getNext() const;
    string getFullName();
    void setAddress(const string &address);
    void setFName(const string &fName);
    void setLName(const string &lName);
    void setPhone(const string &phone);
    void setNext(PersonNode *next);
};


#endif //MOLINA_ASSIGNMENT8_PERSONNODE_H
