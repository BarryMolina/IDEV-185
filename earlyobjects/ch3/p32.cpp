#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    unsigned seed;

    seed = time(0);
    srand(seed);

    cout << static_cast<bool>(rand() % 2) << "\t";
    cout << static_cast<bool>(rand() % 2) << "\t";
    cout << static_cast<bool>(rand() % 2) << endl;
    cout << true << endl;
    
    bool test = 5;
    
    cout << test << endl;
    
    return 0;
}
