#include <iostream>
using namespace std;

int main() {
    char *mystr;
    int numchars;
    cout << "Enter number of chars: ";
    cin >> numchars;
    mystr = new char[numchars];
    cout << "Enter chars up to " << numchars - 1 << ": ";
    cin.ignore();
    cin.getline(mystr, numchars);
    cout << mystr << endl;

    return 0;
}
