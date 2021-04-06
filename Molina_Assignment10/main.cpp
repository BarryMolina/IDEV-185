#include <iostream>
#include <fstream>
#include <string>
#include "Contact.h"
using namespace std;

const string sample_file = "contacts.txt";
const int max_contacts = 20;
int numContacts = 0;

void readFromFile(Contact[]);
void searchContacts(Contact[], char[]);
void displayEntry(Contact);

int main() {
    Contact contacts[max_contacts];
    readFromFile(contacts);
    for (int x = 0; x < numContacts; x++) {
        displayEntry(contacts[x]);
    }
    return 0;
}

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
            contacts[i].setFullName(fName + " " + lName);
            contacts[i].setPhone(phone);
//            cout << lName << ", " << fName << " " << phone << endl;
            numContacts++;
        }
    }
    inFile.close();
}

void searchContacts(Contact contacts[], char lName[]){

}

void displayEntry(Contact contact){
    cout << contact.getFirstName() << ", " << contact.getLastName() << " " << contact.getPhone() << endl;
}
