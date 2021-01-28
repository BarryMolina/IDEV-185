#include <iostream>
#include <string>
using namespace std;

int main() {
    int numStudents;
    string student;
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

    cout << newScreen;
    cout << "Enter student 1: ";
    cin >> firstStudent;
    lastStudent = firstStudent;
    for (int x = 1; x < numStudents; x++)
    {
        cout << "\nEnter student " << x + 1 << ": ";
        cin >> student;
        if (student < firstStudent)
        {
            firstStudent = student;
        }
        else if (student > lastStudent)
        {
            lastStudent = student;
        }
    }

    cout << newScreen;
    cout << "The student at the front of the line is: " << firstStudent << endl;
    cout << "The student at the end of the line is: " << lastStudent << endl;
    cout << "\n\nThank you for using the StudentLineUp app. Goodbye." << endl;

    return 0;
}
