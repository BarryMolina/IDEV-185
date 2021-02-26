#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double *sales = nullptr,
            total = 0.0,
            average;

    int numDays;

    cout << "How many days of sales figures do you wish ";
    cout << "to process? ";
    cin >> numDays;

    sales = new double[numDays];

    cout << "Enter the sales figures below.\n";
    for (int count = 0; count < numDays; count++)
    {
        cout << "Day " << (count + 1) << ": ";
        cin >> sales[count];
    }

    for (int count = 0; count < numDays; count++)
    {
        total += sales[count];
    }

    average = total / numDays;

    cout << setprecision(2) << fixed << showpoint;
    cout << "\n\nTotal Sales: $" << total << endl;
    cout << "\n\nAverage Sales: $" << average << endl;

    delete [] sales;
    sales = nullptr;
    return 0;
}
