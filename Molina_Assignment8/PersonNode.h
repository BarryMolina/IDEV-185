//
// Created by Barry Molina on 3/15/21.
//

#ifndef MOLINA_ASSIGNMENT8_PERSONNODE_H
#define MOLINA_ASSIGNMENT8_PERSONNODE_H

#include <string>
using namespace std;


class PersonNode {
private:
    string address;
    string fName;
    string lName;
    string phone;
    PersonNode *next;
public:
    PersonNode();
    PersonNode(const string &address, const string &fName, const string &lName, const string &phone);
    const string &getAddress() const;
    void setAddress(const string &address);
    const string &getFName() const;
    void setFName(const string &fName);
    const string &getLName() const;
    void setLName(const string &lName);
    const string &getPhone() const;
    void setPhone(const string &phone);
    PersonNode *getNext() const;
    void setNext(PersonNode *next);
    string getFullName();


};


#endif //MOLINA_ASSIGNMENT8_PERSONNODE_H
