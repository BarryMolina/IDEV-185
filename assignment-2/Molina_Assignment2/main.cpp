#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    int numStudents;
    int ans;

    string name;
    string firstStudent;
    string lastStudent;
    string filename;
    string newScreen;
    string stars;

    bool quit = false;

    newScreen.assign(20, '\n');
    stars.assign(40, '*');

    cout << "\n\nWelcome to the StudentLineUp app." <<
            "\n\nThis app allows you to enter a list of student" <<
            "\nnames using either the keyboard or a text file" <<
            "\nand then reports who would be at the front of an" <<
            "\nalphabetical student line up and who is at the end.";
    cout << "\n\nPress <enter> to begin";
    cin.get();

    while (!quit)
    {
        cout << newScreen << endl;
        cout << stars << "\n\t\t\t\tMain Menu\n" << stars << endl;
        cout << "\nPlease choose one of the following options:" << endl;
        cout << "\n1. Input student names via keyboard" << endl;
        cout << "2. Input student names via text file" << endl;
        cout << "3. Quit this application" << endl;
        cout << "\n>>> ";

        cin >> ans;
        cout << newScreen << endl;

        switch (ans)
        {
            case 1:
                cout << "How many students are in the class?" << endl;
                cout << "\nEnter a number between 1 and 20: ";
                cin >> numStudents;

                while (numStudents < 1 || numStudents > 20)
                {
                    cout << newScreen;
                    cout << "Invalid number of students." << endl;
                    cout << "\nHow many students are in the class?" << endl;
                    cout << "\nEnter a number between 1 and 20: ";
                    cin >> numStudents;
                }

                cout << newScreen;
                cout << "Enter student 1: ";
                cin >> firstStudent;
                lastStudent = firstStudent;
                for (int x = 1; x < numStudents; x++)
                {
                    cout << "\nEnter student " << x + 1 << ": ";
                    cin >> name;
                    if (name < firstStudent)
                    {
                        firstStudent = name;
                    }
                    else if (name > lastStudent)
                    {
                        lastStudent = name;
                    }
                }
                cout << newScreen;
                cout << "The student at the front of the line is: " << firstStudent << endl;
                cout << "The student at the end of the line is: " << lastStudent << endl;
                break;
            case 2:
                cout << "You've selected to input a list of names via text file" << endl;
                cout << "\nEnter filename: ";
                cin >> filename;

                inputFile.open(filename);

                // Test that the file exists and contains at least one name
                if (inputFile && inputFile >> firstStudent)
                {
                    lastStudent = firstStudent;

                    while (inputFile >> name)
                    {
                        if (name < firstStudent)
                        {
                            firstStudent = name;
                        }
                        else if (name > lastStudent)
                        {
                            lastStudent = name;
                        }
                    }
                    inputFile.close();

                    cout << newScreen;
                    cout << "The student at the front of the line is: " << firstStudent << endl;
                    cout << "The student at the end of the line is: " << lastStudent << endl;
                }
                else
                {
                    cout << newScreen;
                    cout << "\nError reading file \"" << filename << "\". File does not exist or is empty." << endl;
                }
                break;
            case 3:
                quit = true;
                break;
        }

        if (!quit)
        {
            cout << "\nPress <enter> to return to the Main Menu";
            cin.ignore();
            cin.get();
        }
    }

    cout << "\n\nThank you for using the StudentLineUp app. Goodbye." << endl;

    return 0;
}
