//
// Created by Barry Molina on 3/22/21.
//

#include "StandardDeduction.h"

const double StandardDeduction::getSingleFiler() const {
    return singleFiler;
}

const double StandardDeduction::getHeadOfHousehold() const {
    return headOfHousehold;
}

const double StandardDeduction::getFilingJointly() const {
    return filingJointly;
}

double StandardDeduction::calcDeduction() {
    return 0;
}
