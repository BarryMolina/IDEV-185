// Barry Molina
// ITDEV-185-900
// Assignment 12
// 4/20/21

#include <iostream>
#include <vector>
#include "Account.h"
using namespace std;

vector<Account*> accounts;

void login();
void createAccount();
void manageAccount(Account *account);

// Application start. Contains Main Menu
int main() {
    bool quit = false;
    int ans;

    while (!quit) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "Main Menu\n" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Log in to existing account" << endl;
        cout << "3. Exit" << endl;
        cout << "\n>>> ";
        cin >> ans;

        switch (ans) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                quit = true;
        }
    }
    for (int x = 0; x < accounts.size(); x++) {
        delete accounts[x];
    }
    return 0;
}

// Ask for username and password and attempt to log user in
void login() {
    string username;
    string password;
    Account *account = nullptr;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (Account *a : accounts) {
        if (a->logIn(username, password)) {
            account = a;
            break;
        }
    }

    if (account) {
        manageAccount(account);
    }
    else {
        cout << "\nInvalid username or password" << endl;
        cout << "\nPress <enter> to continue";
        cin.ignore();
        cin.get();
    }
}

// Ask for username and password and attempt to create a new account
void createAccount() {
    string username;
    string password;
    Account *newAccount = nullptr;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    try {
        newAccount = new Account(username, password);
        accounts.push_back(newAccount);
        manageAccount(newAccount);
    }
    catch (validationException ex) {
        cout << "\nError creating account: " << ex.what() << endl;
        cout << "\nPress <enter> to continue";
        cin.ignore();
        cin.get();
    }
}

// User manages account
void manageAccount(Account *account) {
    int ans;
    bool quit = false;
    string username;
    string password;

    while (!quit) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "Hello, " << account->getUsername() << "!\n" << endl;
        cout << "1. Change username" << endl;
        cout << "2. Change password" << endl;
        cout << "3. Main Menu" << endl;
        cout << "\n>>> ";
        cin >> ans;

        switch (ans) {
            case 1:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << "Enter new username: ";
                cin >> username;
                account->setUsername(username);
                break;
            case 2:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << "Enter new password: ";
                cin >> password;
                try {
                    account->setPassword(password);
                }
                catch (validationException ex) {
                    cout << "\nError changing password: " << ex.what() << endl;
                    cout << "\nPress <enter> to continue";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 3:
                quit = true;
        }
    }
}
