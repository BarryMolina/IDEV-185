#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ifstream inputFile;
    string fileName;
    int numValues = 0;
    double value,
           total = 0.0;

    cout << "This program reads and sums the values in a data file.\n";
    cout << "Enter the name of the file to read from: ";
    cin >> fileName;

    inputFile.open(fileName);

    while (inputFile >> value)
    {
        numValues++;
        total += value;
    }
    cout << "\nThe total of the " << numValues << " values is "
        << total << endl;

    inputFile.close();
    return 0;
}

