//
// Created by Barry Molina on 3/22/21.
//

#include "StandardDeduction.h"

const double StandardDeduction::single_filer = 12400;
const double StandardDeduction::head_of_household = 18650;
const double StandardDeduction::filing_jointly = 24800;


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

const double StandardDeduction::getSingleFiler() {
    return single_filer;
}

const double StandardDeduction::getHeadOfHousehold() {
    return head_of_household;
}

const double StandardDeduction::getFilingJointly() {
    return filing_jointly;
}

StandardDeduction::StandardDeduction(FilingStatus filingStatus) : filingStatus(filingStatus) {}
