#include <iostream>
#include <string>
#include <iomanip>
#include "Deduction.h"
#include "StandardDeduction.h"
#include "ItemizedDeduction.h"
#include "FilingStatus.h"
#include "TaxReturn.h"
using namespace std;

// Menu function prototypes
void mainMenu();
TaxReturn *createReturn();
Deduction *createDeduction(FilingStatus filingStatus);
void taxReturnSummary(TaxReturn *taxReturn);

// Utility functions
void clearScreen();

// Current tax year
const int year = 2020;

int main() {
    mainMenu();

    return 0;
}


// User selects to create new tax return or exit
void mainMenu() {
    TaxReturn *taxReturn = nullptr;
    Deduction *deduction = nullptr;
    int ans;
    clearScreen();
    cout << "Main Menu" << endl;
    cout << "1. Create New Tax Return" << endl;
    cout << "2. Exit" << endl;
    cout << "\n>>> ";
    cin >> ans;

    while (ans < 1 || ans > 2) {
        cout << "\nPlease select a valid option" << endl;
        cout << "\n>>> ";
        cin >> ans;
    }
    if (ans == 1) {
        taxReturn = createReturn();
        deduction = createDeduction(taxReturn->getFilingStatus());
        taxReturn->setDeduction(deduction);
        taxReturnSummary(taxReturn);

        // deduction deleted in TaxReturn destructor
        delete taxReturn;
        taxReturn = nullptr;
        deduction = nullptr;
    }
}

// User selects filing status and enters gross income
TaxReturn *createReturn() {
    FilingStatus status;
    double income;
    int ans;
    clearScreen();
    cout << "How will you be filing this year?" << endl;
    cout << "1. Singly" << endl;
    cout << "2. Jointly" << endl;
    cout << "3. As head of household" << endl;
    cout << "\n>>> ";
    cin >> ans;

    while (ans < 1 || ans > 3) {
        cout << "\nPlease select a valid option" << endl;
        cout << "\n>>> ";
        cin >> ans;
    }

    // cast ans to FilingStatus enum
    status = static_cast<FilingStatus>(ans - 1);

    clearScreen();
    cout << "Enter gross income: ";
    cin >> income;

    return new TaxReturn(income, status);
}

// User selects standard or itemized deduction
Deduction *createDeduction(FilingStatus filingStatus) {
    Deduction *deduction = nullptr;
    int ans;
    clearScreen();
    cout << "Would you like to take the standard deduction" << endl;
    cout << "or itemize you deductions?\n" << endl;
    cout << "1. Standard" << endl;
    cout << "2. Itemize" << endl;
    cout << "\n>>> ";
    cin >> ans;

    while (ans < 1 || ans > 2) {
        cout << "\nPlease select a valid option" << endl;
        cout << "\n>>> ";
        cin >> ans;
    }
    if (ans == 1) {
        deduction = new StandardDeduction(filingStatus);
    }
    else {
        double homeMortgageInterest, incomeTaxes, investmentInterest,
                medicalExpenses, charitableContributions, miscDeductions;

        clearScreen();
        cout << "\nEnter your home mortgage interest: ";
        cin >> homeMortgageInterest;
        cout << "\nEnter income taxes: ";
        cin >> incomeTaxes;
        cout << "\nEnter investment interest: ";
        cin >> investmentInterest;
        cout << "\nEnter medical expenses: ";
        cin >> medicalExpenses;
        cout << "\nEnter charitable contributions: ";
        cin >> charitableContributions;
        cout << "\nEnter any other miscellaneous deductions: ";
        cin >> miscDeductions;

        deduction = new ItemizedDeduction(homeMortgageInterest, incomeTaxes, investmentInterest,
                                          medicalExpenses, charitableContributions, miscDeductions);
    }
    return deduction;
}

// Display tax return summary
void taxReturnSummary(TaxReturn *taxReturn) {
    cout << fixed << setprecision(2);
    cout << "Filing Status: " << status_str[int(taxReturn->getFilingStatus())] << endl;
    cout << "Gross Income: $" << taxReturn->getGrossIncome() << endl;
    cout << "Deduction Type: " << taxReturn->getDeduction()->getDeductionType() << endl;
    cout << "Deduction Amount: $" << taxReturn->getDeduction()->calcDeduction() << endl;
    cout << "Taxable Income: $" << taxReturn->calcTaxableIncome() << endl;
    cout << "Tax Rate: " << taxReturn->calcTaxRate() << "%" << endl;
    cout << "Tax Owed for " << year << ": $" << taxReturn->calcTaxOwed();
}

void clearScreen() {
    string newScreen;
    newScreen.assign( 40, '\n');
    cout << newScreen;
}