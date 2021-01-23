/*
 * Barry Molina
 * ITDEV-185-900
 * Assignment 1
 */
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {

    const double STATE_TAX = 0.04;
    const double COUNTY_TAX = 0.02;

    stringstream stream;
    string month, dashes, amountAsString;
    int year, amountLength;
    double amountCollected, sales, stateTax, countyTax, totalTax;

    cout << "Enter the month: ";
    cin >> month;

    cout << "Enter the year: ";
    cin >> year;

    cout << "Enter the total amount collected: ";
    cin >> amountCollected;

    // Convert amount to string with correct precision
    stream << fixed << setprecision(2) << amountCollected;
    amountAsString = stream.str();

    // Get number of characters in amount for formatting
    amountLength = amountAsString.length();

    sales = amountCollected / (1 + STATE_TAX + COUNTY_TAX);

    totalTax = amountCollected - sales;

    stateTax = sales * STATE_TAX;
    countyTax = sales * COUNTY_TAX;

    // calculate and assign appropriate number of dashes
    dashes.assign((22 + amountLength), '-');

    cout << "\n\nMonth:\t" << month << " " << year << endl;
    cout << dashes << endl;
    cout << setprecision(2) << fixed;
    cout << left << setw(20) << "Total Collected:" << "$ "
        << right << setw(amountLength) << amountCollected << endl;
    cout << left << setw(20) << "Sales:" << "$ "
        << right << setw(amountLength) << sales << endl;
    cout << left << setw(20) << "County Sales Tax:" << "$ "
        << right << setw(amountLength) << countyTax << endl;
    cout << left << setw(20) << "State Sales Tax:" << "$ "
        << right << setw(amountLength) << stateTax << endl;
    cout << left << setw(20) << "Total Sales Tax:" << "$ "
        << right << setw(amountLength) << totalTax << endl;

    return 0;
}
