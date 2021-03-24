//
// Created by Barry Molina on 3/22/21.
//

#ifndef MOLINA_ASSIGNMENT9_STANDARDDEDUCTION_H
#define MOLINA_ASSIGNMENT9_STANDARDDEDUCTION_H

#include "Deduction.h"
#include "FilingStatus.h"


class StandardDeduction : public Deduction {
private:
    static const double single_filer;
    static const double head_of_household;
    static const double filing_jointly;
    FilingStatus filingStatus;

public:
    StandardDeduction(FilingStatus filingStatus);

    static const double getSingleFiler();
    static const double getHeadOfHousehold();
    static const double getFilingJointly();
    double calcDeduction() override;

};


#endif //MOLINA_ASSIGNMENT9_STANDARDDEDUCTION_H
