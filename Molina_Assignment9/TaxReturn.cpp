//
// Created by Barry Molina on 3/23/21.
//

#include "TaxReturn.h"

const int TaxReturn::num_brackets = 6;
// Parallel arrays holding tax information for 2020
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

// Constructor points taxBrackets to static bracket array based on filing status
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

// Getters and setters
Deduction *TaxReturn::getDeduction() const {
    return deduction;
}

FilingStatus TaxReturn::getFilingStatus() const {
    return filingStatus;
}

double TaxReturn::getGrossIncome() const {
    return grossIncome;
}

void TaxReturn::setDeduction(Deduction *deduction) {
    TaxReturn::deduction = deduction;
}

void TaxReturn::setFilingStatus(FilingStatus filingStatus) {
    TaxReturn::filingStatus = filingStatus;
}

void TaxReturn::setGrossIncome(double grossIncome) {
    TaxReturn::grossIncome = grossIncome;
}

// Calculate tax rate based on the amount of taxable income
int TaxReturn::calcTaxRate() {
    double income = calcTaxableIncome();
    int rate;
    bool foundIt = false;
    for (int x = 0; x < num_brackets && !foundIt; x++) {
        if (income < taxBrackets[x]) {
            rate = tax_rates[x];
            foundIt = true;
        }
    }
    if (!foundIt) {
        rate = tax_rates[num_brackets];
    }
    return rate;
}

// Calculate taxable income
double TaxReturn::calcTaxableIncome() {
    double taxableIncome = grossIncome - (deduction ? deduction->calcDeduction() : 0);
    return (taxableIncome > 0 ? taxableIncome : 0);
}

// Calculate the amount of tax owed
double TaxReturn::calcTaxOwed() {
    return calcTaxableIncome() * calcTaxRate() / 100;
}

TaxReturn::~TaxReturn() {
    delete deduction;
}
