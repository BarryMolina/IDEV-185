#include <iostream>
#include <string>
using namespace std;

int main() {
    int numStudents;
    string firstStudent;
    string lastStudent;
    string newScreen;

    cout << "\n\nWelcome to the StudentLineUp app." <<
            "\n\nThis app accepts between 1 and 20 student names" <<
            "\nand then reports who would be at the front of an" <<
            "\nalphabetical student line up and who is at the end.";
    cout << "\n\nPress <enter> to begin";
    cin.get();
    newScreen.assign(20, '\n');
    cout << newScreen << endl;
    cout << "How many students are in the class?" << endl;
    cout << "Enter a number between 1 and 20: ";
    cin >> numStudents;

    while (numStudents < 1 || numStudents > 20)
    {
        cout << newScreen;
        cout << "Invalid number of students." << endl;
        cout << "\nHow many students are in the class?" << endl;
        cout << "Enter a number between 1 and 20: ";
        cin >> numStudents;
    }

    for (int x = 0; x < numStudents; x++)
    {
        cout << "Enter a student name: ";


    }

    return 0;
}
