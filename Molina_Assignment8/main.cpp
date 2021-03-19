// Barry Molina
// ITDEV-185-900
// Assignment 8
// 3/15/21
#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedList.h"
#include "PersonNode.h";

using namespace std;

void mainMenu();
void addPerson();
void displayList();
void removePerson();

LinkedList directory;

int main() {
    return 0;
}

void mainMenu() {
    bool quit = false;
    int selection;
    while (!quit) {
        cout << "Main Menu" << endl;
        cout << "\nPlease select one of the following\n" << endl;
        cout << "1. Add to Directory" << endl;
        cout << "2. Display Directory" << endl;
        cout << "3. Remove from Directory" << endl;
        cout << "4. Exit" << endl;
        cout << "\n>>> ";
        cin >> selection;

        while (selection < 1 || selection > 3) {
            cout << "\nPlease select a valid option" << endl;
            cout << "\n>>> ";
            cin >> selection;
        }

        switch (selection) {
            case 1:
                addPerson();
                break;
            case 2:
                displayList();
                break;
            case 3:
                removePerson();
                break;
            case 4:
                quit = true;
                break;
        }
    }
}
void addPerson() {
    int promptw = 30;
    string fName, lName, addressNum,
           streetName, streetType, phoneNum;

    cout << setw(promptw) << "First Name:" << endl;
    cin >> fName;
    cout << setw(promptw) << "Last Name:" << endl;
    cin >> lName;
    cout << setw(promptw) << "Address Number:" << endl;
    cin >> addressNum;
    cout << setw(promptw) << "Address Street Name:" << endl;
    cin >> streetName;
    cout << setw(promptw) << "Address Street Type (Str, Circle):" << endl;
    cin >> streetType;
    cout << setw(promptw) << "Phone Number:" << endl;
    cin >> phoneNum;


}
void displayList() {

}
void removePerson() {

}
