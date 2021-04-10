#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Contact.h"
using namespace std;

// sample contact file
const string sample_file = "contacts.txt";
// maximum number of contacts
const int max_contacts = 20;
// current number of contacts loaded into the program
int numContacts = 0;

void readFromFile(Contact[]);
void searchContacts(Contact[], char[]);
void displayEntry(Contact);

// Application start. Contains the main menu
int main() {
    // Main contact array
    Contact contacts[max_contacts];
    // Quit flag
    bool quit = false;
        // Menu selection
    int input,
        // Max size of user inputted name
        name_size = 20;
    // char array to hold search name
    char name[name_size];

    // Load contacts from file
    readFromFile(contacts);

    // Main menu
    while (!quit) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "MAIN MENU" << endl;
        cout << "\nPlease select one of the following\n" << endl;
        cout << "(1) Display all contacts" << endl;
        cout << "(2) Search contacts by last name" << endl;
        cout << "(3) Quit" << endl;
        cout << "\n>>> ";
        cin >> input;

        switch (input) {
            // User selects to display all contacts
            case 1:
                for (int x = 0; x < numContacts; x++) {
                    displayEntry(contacts[x]);
                }
                cout << "Press <enter> to continue";
                cin.ignore();
                cin.get();
                break;
            // User selects to search contacts by last name
            case 2:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << "Enter last name of contact to search for: ";
                cin.ignore();
                cin.getline(name, name_size);
                cout << endl;
                searchContacts(contacts, name);
                cout << "Press <enter> to continue";
                cin.get();
                break;
            // User selects to quit
            case 3:
                quit = true;
        }
    }
    cout << "\nHave a nice day!" << endl;

    return 0;
}

// Load contact information from sample_file into Contact array
// and set numContacts accordingly.
void readFromFile(Contact contacts[]) {
//    ofstream myfile;
//    myfile.open(sample_file);
//    myfile.close();
    string lName, fName, phone;
    ifstream inFile;
    inFile.open(sample_file);
    if (inFile) {
        for (int i = 0; (inFile >> lName) && i < max_contacts; i++) {
            inFile >> fName;
            inFile >> phone;
            contacts[i].setFirstName(fName);
            contacts[i].setLastName(lName);
            contacts[i].setFullName(lName + ", " + fName);
            contacts[i].setPhone(phone);
            numContacts++;
        }
    }
    inFile.close();
}

// Search contacts given a last name.
// Calls displayEntry for each contact found.
void searchContacts(Contact contacts[], char lName[]){
    for (int x = 0; x < numContacts; x++) {
        if (strcmp(contacts[x].getLastName(), lName) == 0) {
            displayEntry(contacts[x]);
        }
    }
}

// Nicely format information given a single contact
void displayEntry(Contact contact){
    cout << contact.getFullName() << endl << contact.getPhone() << endl << endl;
}
