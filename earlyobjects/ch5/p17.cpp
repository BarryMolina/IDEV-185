#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inputFile;
    string name;

    inputFile.open("friends.txt");

    cout << "Here are the names stored in the friend.txt file.\n";

    for (int count = 1; count <= 3; count++)
    {
        inputFile >> name;
        cout << name << endl;
    }

    inputFile.close();

    return 0;
}
