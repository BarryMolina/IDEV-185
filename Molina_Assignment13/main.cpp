#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Application start
int main() {
    // Object to read in file stream
    ifstream infile;
    // string to capture filename
    string filename;
    // string to hold one line of file input
    string line;

    // Application prompt
    cout << "Enter the name of one of the following pre-loaded files" << endl;
    cout << "or any other file that may exist in the application directory\n" << endl;
    cout << "Hamlet.txt" << endl;
    cout << "JuliusCaesar.txt" << endl;
    cout << "RomeoAndJuliet.txt" << endl;
    cout << "HistoryOfCpp.txt" << endl;
    cout << "\n>>> ";
    cin >> filename;
    cin.ignore();

    // Attempt to open file
    infile.open(filename);

    // If file exists, read in 20 lines at a time.
    if (infile) {
        while (infile) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            for (int x = 0; x < 20 && getline(infile, line); x++) {
                cout << line << endl;
            }
            if (infile) {
                cout << "\nPress <enter> to read in the next 20 lines.";
            }
            else {
                cout << "\nEnd of file reached. Press <enter> to exit this application.";
            }
            cin.get();
        }
    }
    // File not found. Exit application
    else {
        cout << "\nFile does not exist. Goodbye" << endl;
    }

    return 0;
}
