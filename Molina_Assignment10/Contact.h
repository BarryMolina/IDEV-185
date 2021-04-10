//
// Created by Barry Molina on 4/4/21.
//

#ifndef MOLINA_ASSIGNMENT10_CONTACT_H
#define MOLINA_ASSIGNMENT10_CONTACT_H
#include <string>


// This class represents a single entry in a contact book.
// It contains attributes to store the contact's information
// and the methods to manage those attribute
class Contact {
private:
    // Contact first name
    char firstName [20];
    // Contact full name
    char fullName [40] ;
    // Contact last name
    char lastName [20];
    // Contact phone number
    char phone [14];
public:
    Contact();
    char* getFirstName();
    char* getLastName();
    char* getFullName();
    char* getPhone();
    void setFirstName(std::string);
    void setLastName(std::string);
    void setFullName(std::string);
    void setPhone(std::string);
};


#endif //MOLINA_ASSIGNMENT10_CONTACT_H
