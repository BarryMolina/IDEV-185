//
// Created by Barry Molina on 3/23/21.
//

#include "TaxReturn.h"

const int TaxReturn::num_brackets = 7;
const int TaxReturn::tax_rates[] = { 10, 12, 22, 24, 32, 35, 37 };
const double TaxReturn::single_brackets [] = {
        9875.00,
        40125.00,
        85525.00,
        163300.00,
        207350.00,
        518400.00,
};
const double TaxReturn::head_of_h_brackets [] = {
        14100.00,
        53700.00,
        85500.00,
        163300.00,
        207350.00,
        518400.00,
};
const double TaxReturn::joint_brackets [] = {
        19750.00,
        80250.00,
        171050.00,
        326600.00,
        414700.00,
        622050.00,
};

TaxReturn::TaxReturn(double grossIncome, FilingStatus filingStatus) : grossIncome(grossIncome),
                                                                      filingStatus(filingStatus) {
    switch (filingStatus) {
        case FilingStatus::Single:
            taxBrackets = single_brackets;
            break;
        case FilingStatus::Jointly:
            taxBrackets = joint_brackets;
            break;
        case FilingStatus::HeadOfHousehold:
            taxBrackets = head_of_h_brackets;
            break;
    }
}

int TaxReturn::calcTaxRate() {

}

double TaxReturn::calcTaxableIncome() {
    return grossIncome - (deduction ? deduction->calcDeduction() : 0);
}

double TaxReturn::calcTaxOwed() {
    return calcTaxableIncome() * calcTaxRate() / 100;
}
