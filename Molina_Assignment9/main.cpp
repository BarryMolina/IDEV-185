#include <iostream>
#include <string>
#include <iomanip>
#include "Deduction.h"
#include "StandardDeduction.h"
#include "ItemizedDeduction.h"
#include "FilingStatus.h"
#include "TaxReturn.h"
using namespace std;

int main() {
    StandardDeduction standard(FilingStatus::Single);
    ItemizedDeduction itemized(300, 0, 188,
                               50, 500, 200);
    Deduction *deduction = nullptr;

    cout << fixed << setprecision(2);

    deduction = &standard;
    cout << "Standard Deduction: $" << deduction->calcDeduction() << endl;
    deduction = &itemized;
    cout << "Itemized Deduction: $" << deduction->calcDeduction() << endl;


    return 0;
}
