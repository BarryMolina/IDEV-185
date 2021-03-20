// Barry Molina
// ITDEV-185-900
// Assignment 8
// 3/15/21
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "PersonNode.h";
using namespace std;

// UI functions
void mainMenu();
void addContact();
void displayDirectory();
void displayContact(PersonNode*);
void deleteContact();

// Utility functions
void clearScreen();

// Global linked list object
LinkedList directory;

int main() {
    mainMenu();
    return 0;
}

// User chooses linked list operation
void mainMenu() {
    bool quit = false;
    int selection;
    while (!quit) {
        clearScreen();
        cout << "Main Menu" << endl;
        cout << "\nPlease select one of the following options\n" << endl;
        cout << "1. Add to Directory" << endl;
        cout << "2. Display Directory" << endl;
        cout << "3. Remove from Directory" << endl;
        cout << "4. Exit" << endl;
        cout << "\n>>> ";
        cin >> selection;

        while (selection < 1 || selection > 4) {
            cout << "\nPlease select a valid option" << endl;
            cout << "\n>>> ";
            cin >> selection;
        }

        switch (selection) {
            case 1:
                addContact();
                break;
            case 2:
                displayDirectory();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                quit = true;
                break;
        }
    }
}

// User enters new contact info
void addContact() {
    string fName, lName, addressNum, streetName,
            streetType, phoneNum, address;
    PersonNode *newPerson;

    clearScreen();
    cout << "First Name: ";
    cin >> fName;
    cout << "Last Name: ";
    cin >> lName;
    cout << "Address Number: ";
    cin >> addressNum;
    cout << "Address Street Name: ";
    cin >> streetName;
    cout << "Address Street Type (Str, Circle): ";
    cin >> streetType;
    cout << "Phone Number: ";
    cin >> phoneNum;
    address = addressNum + " " + streetName + " " + streetType;

    newPerson = new PersonNode(fName, lName, address, phoneNum);
    directory.addLink(newPerson);

    clearScreen();
    cout << "\nNew directory entry: \n" << endl;
    displayContact(newPerson);
    cout << "\nPress <enter> to continue";
    cin.ignore();
    cin.get();
}

// Display the directory
void displayDirectory() {
    clearScreen();
    if (!directory.getHeadPtr()) {
        cout << "The directory is empty.\n" << endl;
    }
    else {
        PersonNode *node = directory.getHeadPtr();
        cout << "Contacts\n" << endl;
        while (node) {
            displayContact(node);
            cout << endl;
            node = node->getNext();
        }
        cout << "Tail: " << directory.getTailPtr()->getLName() << endl << endl;
    }
    cout << "Press <enter> to continue";
    cin.ignore();
    cin.get();
}

// Format info for a single contact
void displayContact(PersonNode* p) {
    cout << p->getFullName() << endl;
    cout << p->getAddress() << endl;
    cout << p->getPhone() << endl;
}

// Remove entry from the directory
void deleteContact() {
    string lName;
    bool success;

    clearScreen();
    if (!directory.getHeadPtr()) {
        cout << "The directory is empty." << endl;
    }
    else {
        cout << "Enter last name of contact to be removed: ";
        cin >> lName;
        success = directory.removePerson(lName);

        clearScreen();
        if (success) {
            cout << "Removed contact with last name \"" << lName << "\"" << endl;
        }
        else {
            cout << "Contact with last name \"" << lName << "\" not found." << endl;
            cout << "No entries were removed." << endl;
        }
    }

    cout << "\nPress <enter> to continue";
    cin.ignore();
    cin.get();
}

void clearScreen() {
    string newScreen;
    newScreen.assign(20, '\n');
    cout << newScreen;
}
