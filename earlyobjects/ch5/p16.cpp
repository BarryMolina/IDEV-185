#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outputFile;
    string name;

    outputFile.open("friends.txt");

    cout << "Enter the names of three friends.\n";

    for (int count = 1; count <= 3; count++)
    {
        cout << "Friend #" << count << ": ";
        cin >> name;
        outputFile << name << endl;
    }

    outputFile.close();

    cout << "The names were saved to a file.\n";
    return 0;
}
