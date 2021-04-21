//
// Created by Barry Molina on 4/21/21.
//

#include "Account.h"

Account::Account(const std::string &username, const std::string &password) {
    this->username = username;

    if (!checkSpecialChars(password))
        throw validationException("No special characters found");
    else if (!checkNumbers(password))
        throw validationException("No numbers found");
    else if (!checkCapitalized(password))
        throw validationException("No capitalized characters found");
    else
        this->password = password;
}

bool Account::checkSpecialChars(std::string password) {
    return false;
}

bool Account::checkNumbers(std::string password) {
    return false;
}

bool Account::checkCapitalized(std::string password) {
    return false;
}
