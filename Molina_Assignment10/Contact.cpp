//
// Created by Barry Molina on 4/4/21.
//

#include "Contact.h"

Contact::Contact() { }

char *Contact::getFirstName() {
    return firstName;
}

char *Contact::getLastName() {
    return lastName;
}

char *Contact::getFullName() {
    return fullName;
}

char *Contact::getPhone() {
    return phone;
}

void Contact::setFirstName(std::string fName) {
    std::strcpy(firstName, fName.c_str());
}

void Contact::setLastName(std::string lName) {
    std::strcpy(lastName, lName.c_str());
}

void Contact::setFullName(std::string name) {
    std::strcpy(fullName, name.c_str());
}

void Contact::setPhone(std::string phoneNum) {
    std::strcpy(phone, phoneNum.c_str());
}

