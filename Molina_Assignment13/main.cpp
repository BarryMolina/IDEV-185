#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;
    string filename;
    string line;
    string page;
    int lineCount = 1;

    cout << "Enter the name of one of the following pre-loaded files" << endl;
    cout << "or any other file that may exist in the application directory\n" << endl;
    cout << "Hamlet.txt" << endl;
    cout << "JuliusCaesar.txt" << endl;
    cout << "RomeoAndJuliet.txt" << endl;
    cout << "HistoryOfCpp.txt" << endl;
    cout << "\n>>> ";
    cin >> filename;
    cin.ignore();

    infile.open(filename);

    if (infile) {
        while (infile) {
            page.clear();
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            for (int x = 0; x < 20 && getline(infile, line); x++) {
                page.append(line + "\n");
            }
            cout << page;
            if (infile) {
                cout << "\nPress <enter> to read in the next 20 lines.";
            }
            else {
                cout << "\nEnd of file reached. Press <enter> to exit this application.";
            }

            cin.get();
        }
    }
    else {
        cout << "\nFile does not exist. Goodbye" << endl;
    }

    return 0;
}
