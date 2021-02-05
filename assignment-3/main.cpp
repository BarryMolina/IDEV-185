#include <iostream>
#include <iomanip>
using namespace std;

void inputData(int &ordered, int &inStock, double &extra);
void displayOrder();

int main()
{
    int spoolsOrdered, spoolsInStock;
    double extraShipping;

//    inputData(spoolsOrdered, spoolsInStock, extraShipping);
    displayOrder();

    return 0;
}

void inputData(int &ordered, int &inStock, double &extra)
{
    cout << "How many spools were ordered? ";
    cin >> ordered;
    cout << "How many spools are in stock? ";
    cin >> inStock;
    cout << "\nAmount of any special shipping charges (per spool)" << endl;
    cout << "above the regular $10.00 per spool rate (0 for none): ";
    cin >> extra;
}

void displayOrder()
{
    cout << left;
    cout << "      *** Order Summary ***" << endl << endl;
    cout << setw(29) << "Spools ordered:" << 500 << endl;
    cout << setw(29) << "Spools in this shipment:" << 500 << endl;

    cout << fixed << setprecision(2);
    cout << "\n   Charges for this shipment" << endl;
    cout << "   -------------------------" << endl;
    cout << setw(22) << "Spool charges:" << "$ " << 50000.000 << endl;
    cout << setw(22) << "Shipping charges:" << "$ " << 5000.0000 << endl;
    cout << setw(22) << "Total this shipment:" << "$ " << 55000.0000 << endl;
}
