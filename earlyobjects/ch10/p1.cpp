#include <iostream>
using namespace std;

char letter;
short number;
float amount;
double profit;
char ch;

int main()
{
    cout << "Address of letter is :    "
         << long(&letter) << endl;
    cout << "Address of number is :    "
         << long(&number) << endl;
    cout << "Address of amount is :    "
         << long(&amount) << endl;
    cout << "Address of profit is :    "
         << long(&profit) << endl;
    cout << "Address of ch is :    "
         << long(&ch) << endl;

    return 0;
}
