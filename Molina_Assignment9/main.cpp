#include <iostream>
#include <string>
#include <iomanip>
#include "Deduction.h"
#include "StandardDeduction.h"
#include "ItemizedDeduction.h"
#include "FilingStatus.h"
#include "TaxReturn.h"
using namespace std;

void mainMenu();
void createReturn();
void createDeduction();
void itemizeDeductions();
void taxReturnSummary(TaxReturn *taxReturn);

void clearScreen();

const int year = 2020;
TaxReturn *taxReturn = nullptr;

int main() {
    mainMenu();


//    StandardDeduction standard(FilingStatus::Single);
//    ItemizedDeduction itemized(300, 0, 188,
//                               50, 500, 200);
//    Deduction *deduction = nullptr;
//    TaxReturn taxReturn(120000, FilingStatus::Single);
//
//    cout << fixed << setprecision(2);

//    deduction = &standard;
//    cout << "Standard Deduction: $" << deduction->calcDeduction() << endl;
//    deduction = &itemized;
//    cout << "Itemized Deduction: $" << deduction->calcDeduction() << endl;

//    cout << status_str[int(standard.getFilingStatus())] << endl;

//    taxReturn.setDeduction(&standard);
//    taxReturnSummary(&taxReturn);


    return 0;
}


void mainMenu() {
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
        createReturn();
        createDeduction();
    }

}

void createReturn() {
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

    taxReturn = new TaxReturn(income, status);
}
void createDeduction() {
    Deduction *deduction;
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
        deduction = new StandardDeduction(taxReturn->getFilingStatus());
    }
    else {
        clearScreen();
        cout << "\nEnter your home mortgage interest: ";
        cout << "\nEnter income taxes: ";
        cout << "\nEnter investment interest: ";
        cout << "\nEnter medical expenses: ";
        cout << "\nEnter charitable contributions: ";
        cout << "\nEnter any other miscellaneous deductions: ";

    }
    taxReturn->setDeduction(deduction);


}
void itemizeDeductions();

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