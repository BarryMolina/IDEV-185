//
// Created by Barry Molina on 4/21/21.
//

#ifndef MOLINA_ASSIGNMENT12_ACCOUNT_H
#define MOLINA_ASSIGNMENT12_ACCOUNT_H
#include <string>
#include <exception>

// Custom exception class
class validationException : public std::exception {
private:
    // Store message as string to avoid memory leaks
    std::string errMessage;
public:
    // Constructor takes error message as parameter
    explicit validationException(const std::string &errMessage) : errMessage(errMessage) {}
    // overridden function can be called through reference to exception superclass
    const char* what() const noexcept override {
        return errMessage.c_str();
    }
};

class Account {
private:
    std::string username;
    std::string password;
public:
    Account(const std::string &username, const std::string &password);
    bool checkSpecialChars(std::string password);
    bool checkNumbers(std::string password);
    bool checkCapitalized(std::string password);
};


#endif //MOLINA_ASSIGNMENT12_ACCOUNT_H
