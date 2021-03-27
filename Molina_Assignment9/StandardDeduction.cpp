//
// Created by Barry Molina on 3/22/21.
//

#include "StandardDeduction.h"

// Deduction amounts for each filing status
const double StandardDeduction::single_filer = 12400;
const double StandardDeduction::head_of_household = 18650;
const double StandardDeduction::filing_jointly = 24800;

// Constructor
StandardDeduction::StandardDeduction(FilingStatus filingStatus) : filingStatus(filingStatus) {}


// Getters
const double StandardDeduction::getSingleFiler() {
    return single_filer;
}

const double StandardDeduction::getHeadOfHousehold() {
    return head_of_household;
}

const double StandardDeduction::getFilingJointly() {
    return filing_jointly;
}

FilingStatus StandardDeduction::getFilingStatus() const {
    return filingStatus;
}

// Overridden base class function
std::string StandardDeduction::getDeductionType() {
    return "Standard";
}

// Overridden base class function
// Calculated deduction based on filing status
double StandardDeduction::calcDeduction() {
    double deduction = 0;

    if (filingStatus == FilingStatus::Single)
        deduction = single_filer;
    else if (filingStatus == FilingStatus::HeadOfHousehold)
        deduction = head_of_household;
    else if (filingStatus == FilingStatus::Jointly)
        deduction = filing_jointly;

    return deduction;
}

