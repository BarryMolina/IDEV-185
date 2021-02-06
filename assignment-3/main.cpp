/*
 * Barry Molina
 * ITDEV-185-900
 * Assignment 3
 */

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

void inputData(int &ordered, int &inStock, double &extra);
void displayOrder(int ordered, int inStock, double costPerSpool, double shippingRate = 10.00);

const double SPOOL_COST = 100.00;

int main()
{
    int spoolsOrdered, spoolsInStock;
    double extraShipping;

    inputData(spoolsOrdered, spoolsInStock, extraShipping);
    if (extraShipping > 0)
    {
        displayOrder(spoolsOrdered, spoolsInStock, SPOOL_COST, 10.00 + extraShipping );
    }
    else
    {
        displayOrder(spoolsOrdered, spoolsInStock, SPOOL_COST);
    }

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

void displayOrder(int ordered, int inStock, double costPerSpool, double shippingRate)
{
    int maxWidth, thisShipment, backOrdered = 0;
    double spoolCharges, shippingCharges, total;
    stringstream stream;

    if (ordered > inStock)
    {
        thisShipment = inStock;
        backOrdered = ordered - inStock;
    }
    else
    {
        thisShipment = ordered;
    }

    spoolCharges = thisShipment * costPerSpool;
    shippingCharges = thisShipment * shippingRate;
    total = spoolCharges + shippingCharges;

    // get max width of numeric portion of report
    stream << fixed << setprecision(2) << total;
    maxWidth = stream.str().length();

    cout << "      *** Order Summary ***" << endl << endl;
    cout << left << setw(24) << "Spools ordered:" << right << setw(maxWidth) << ordered << endl;
    cout << left << setw(24) << "Spools in this shipment:" << right << setw(maxWidth) << thisShipment << endl;
    if (backOrdered > 0)
        cout << left << setw(24) << "Spools back ordered:" << right << setw(maxWidth) << backOrdered << endl;

    cout << fixed << setprecision(2);
    cout << "\n   Charges for this shipment" << endl;
    cout << "   -------------------------" << endl;
    cout << left << setw(22) << "Spool charges:" << "$ " << right << setw(maxWidth) << spoolCharges << endl;
    cout << left << setw(22) << "Shipping charges:" << "$ " << right << setw(maxWidth) << shippingCharges << endl;
    cout << left << setw(22) << "Total this shipment:" << "$ " << right << setw(maxWidth) << total << endl;
}
