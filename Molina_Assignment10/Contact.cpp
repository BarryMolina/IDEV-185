//
// Created by Barry Molina on 4/4/21.
//

#include "Contact.h"

// Default Constructor
Contact::Contact() { }

// Gets this contact's first name
// returns -> a pointer to first name char array
char *Contact::getFirstName() {
    return firstName;
}

// Gets this contact's last name
// returns -> a pointer to last name char array
char *Contact::getLastName() {
    return lastName;
}

// Gets this contact's full name
// returns -> a pointer to full name char array
char *Contact::getFullName() {
    return fullName;
}

// Gets this contact's phone number
// returns -> a pointer to phone char array
char *Contact::getPhone() {
    return phone;
}

// Sets this contact's first name
// parameter: first name as a string
void Contact::setFirstName(std::string fName) {
    std::strcpy(firstName, fName.c_str());
}

// Sets this contact's last name
// parameter: last name as a string
void Contact::setLastName(std::string lName) {
    std::strcpy(lastName, lName.c_str());
}

// Sets this contact's full name
// parameter: full name as a string
void Contact::setFullName(std::string name) {
    std::strcpy(fullName, name.c_str());
}

// Sets this contact's phone number
// parameter: phone number as a string
void Contact::setPhone(std::string phoneNum) {
    std::strcpy(phone, phoneNum.c_str());
}

