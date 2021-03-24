//
// Created by Barry Molina on 3/22/21.
//

#ifndef MOLINA_ASSIGNMENT9_STANDARDDEDUCTION_H
#define MOLINA_ASSIGNMENT9_STANDARDDEDUCTION_H

#include "Deduction.h"


class StandardDeduction : Deduction {
private:
    const double singleFiler = 12400;
    const double headOfHousehold = 18650;
    const double filingJointly = 24800;
public:
    const double getSingleFiler() const;
    const double getHeadOfHousehold() const;
    const double getFilingJointly() const;
    double calcDeduction() override;

};


#endif //MOLINA_ASSIGNMENT9_STANDARDDEDUCTION_H
