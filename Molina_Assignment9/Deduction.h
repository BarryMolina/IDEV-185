//
// Created by Barry Molina on 3/22/21.
//

#ifndef MOLINA_ASSIGNMENT9_DEDUCTION_H
#define MOLINA_ASSIGNMENT9_DEDUCTION_H

#include <string>

// Abstract superclass for standard and itemized deduction classes
class Deduction {
public:
    // virtual function with default implementation
    virtual std::string getDeductionType();
    // Pure virtual function that must be overridden
    // returns the calculated deduction amount
    virtual double calcDeduction() = 0;
    virtual ~Deduction();
};


#endif //MOLINA_ASSIGNMENT9_DEDUCTION_H
