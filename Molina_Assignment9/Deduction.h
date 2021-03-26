//
// Created by Barry Molina on 3/22/21.
//

#ifndef MOLINA_ASSIGNMENT9_DEDUCTION_H
#define MOLINA_ASSIGNMENT9_DEDUCTION_H

#include <string>

class Deduction {
public:
    virtual std::string getDeductionType();
    virtual double calcDeduction() = 0;
};


#endif //MOLINA_ASSIGNMENT9_DEDUCTION_H
