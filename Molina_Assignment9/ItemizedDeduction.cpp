//
// Created by Barry Molina on 3/22/21.
//

#include "ItemizedDeduction.h"

// Constructors
ItemizedDeduction::ItemizedDeduction() {}

ItemizedDeduction::ItemizedDeduction(double homeMortgageInterest, double incomeTaxes, double investmentInterest,
                                     double medicalExpenses, double charitableContributions, double miscDeductions)
        : homeMortgageInterest(homeMortgageInterest), incomeTaxes(incomeTaxes), investmentInterest(investmentInterest),
          medicalExpenses(medicalExpenses), charitableContributions(charitableContributions),
          miscDeductions(miscDeductions) {
}

// Getters and setters
double ItemizedDeduction::getHomeMortgageInterest() const {
    return homeMortgageInterest;
}

void ItemizedDeduction::setHomeMortgageInterest(double homeMortgageInterest) {
    ItemizedDeduction::homeMortgageInterest = homeMortgageInterest;
}

double ItemizedDeduction::getIncomeTaxes() const {
    return incomeTaxes;
}

void ItemizedDeduction::setIncomeTaxes(double incomeTaxes) {
    ItemizedDeduction::incomeTaxes = incomeTaxes;
}

double ItemizedDeduction::getInvestmentInterest() const {
    return investmentInterest;
}

void ItemizedDeduction::setInvestmentInterest(double investmentInterest) {
    ItemizedDeduction::investmentInterest = investmentInterest;
}

double ItemizedDeduction::getMedicalExpenses() const {
    return medicalExpenses;
}

void ItemizedDeduction::setMedicalExpenses(double medicalExpenses) {
    ItemizedDeduction::medicalExpenses = medicalExpenses;
}

double ItemizedDeduction::getCharitableContributions() const {
    return charitableContributions;
}

void ItemizedDeduction::setCharitableContributions(double charitableContributions) {
    ItemizedDeduction::charitableContributions = charitableContributions;
}

double ItemizedDeduction::getMiscDeductions() const {
    return miscDeductions;
}

void ItemizedDeduction::setMiscDeductions(double miscDeductions) {
    ItemizedDeduction::miscDeductions = miscDeductions;
}

// Overridden base class function
std::string ItemizedDeduction::getDeductionType() {
    return "Itemized";
}

// Overridden base class function
// Calculate deduction by adding up all expense categories
double ItemizedDeduction::calcDeduction() {
    return homeMortgageInterest + incomeTaxes + investmentInterest +
           medicalExpenses + charitableContributions + miscDeductions;
}

