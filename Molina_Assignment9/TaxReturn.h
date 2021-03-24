//
// Created by Barry Molina on 3/23/21.
//

#ifndef MOLINA_ASSIGNMENT9_TAXRETURN_H
#define MOLINA_ASSIGNMENT9_TAXRETURN_H

#include "Deduction.h"
#include "FilingStatus.h"

class TaxReturn {
private:
    static const int num_brackets;
    static const int tax_rates [];
    static const double single_brackets [];
    static const double head_of_h_brackets [];
    static const double joint_brackets [];
    // pointer to the appropriate bracket based on filing status;
    const double *taxBrackets = nullptr;
    Deduction *deduction = nullptr;
    FilingStatus filingStatus;
    double grossIncome;
public:
    TaxReturn(double grossIncome, FilingStatus filingStatus);
    int calcTaxRate();
    double calcTaxableIncome();
    double calcTaxOwed();


};


#endif //MOLINA_ASSIGNMENT9_TAXRETURN_H
