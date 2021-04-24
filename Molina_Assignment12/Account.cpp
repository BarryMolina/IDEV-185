//
// Created by Barry Molina on 4/21/21.
//

#include "Account.h"
#include <regex>

// Create an account object given username and password.
// Calls setPassword() for password validation.
// May throw validationError
Account::Account(const std::string &username, const std::string &password) {
    Account::username = username;
    setPassword(password);
}

const std::string &Account::getUsername() const {
    return username;
}

const std::string &Account::getPassword() const {
    return password;
}

void Account::setUsername(const std::string &username) {
    Account::username = username;
}

// Set this account's password if all validation checks are passed.
// Throws validationException.
void Account::setPassword(const std::string &password) {
    if (!checkLength(password))
        throw validationException("Password must be at least 8 characters in length");
    else if (!checkSpecialChars(password))
        throw validationException("No special characters found");
    else if (!checkNumbers(password))
        throw validationException("No numbers found");
    else if (!checkCapitals(password))
        throw validationException("No capitalized characters found");
    else
        Account::password = password;
}

// Ensure password is of sufficient length
bool Account::checkLength(std::string password) {
    return password.size() >= 8;
}

// Ensure password contains at least one non-alphanumeric character
bool Account::checkSpecialChars(std::string password) {
    std::regex e("[^a-zA-Z0-9]");
    return std::regex_search(password, e);
}

// Ensure password contains at least one digit
bool Account::checkNumbers(std::string password) {
    std::regex e("[0-9]");
    return std::regex_search(password, e);
}

// Ensure password contains at least one capital letter
bool Account::checkCapitals(std::string password) {
    std::regex e("[A-Z]");
    return std::regex_search(password, e);
}

// Return true if username and password match credentials on this account
bool Account::logIn(std::string user, std::string password) {
    return Account::username == username && Account::password == password;
}

