//
// Created by Barry Molina on 4/4/21.
//

#ifndef MOLINA_ASSIGNMENT10_CONTACT_H
#define MOLINA_ASSIGNMENT10_CONTACT_H
#include <string>


class Contact {
private:
    char firstName [20];
    char fullName [40] ;
    char lastName [20];
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
