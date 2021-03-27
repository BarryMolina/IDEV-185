//
// Created by Barry Molina on 3/22/21.
//

#ifndef MOLINA_ASSIGNMENT9_ITEMIZEDDEDUCTION_H
#define MOLINA_ASSIGNMENT9_ITEMIZEDDEDUCTION_H

#include "Deduction.h"

// Derived class representing a deduction that has been itemized
class ItemizedDeduction : public Deduction {
private:
    // Expense categories that can be deducted
    double homeMortgageInterest = 0;
    double incomeTaxes = 0;
    double investmentInterest = 0;
    double medicalExpenses = 0;
    double charitableContributions = 0;
    double miscDeductions = 0;
public:
    ItemizedDeduction();
    ItemizedDeduction(double homeMortgageInterest, double incomeTaxes, double investmentInterest,
                      double medicalExpenses, double charitableContributions, double miscDeductions);
    double getHomeMortgageInterest() const;
    double getIncomeTaxes() const;
    double getInvestmentInterest() const;
    double getMedicalExpenses() const;
    double getCharitableContributions() const;
    double getMiscDeductions() const;
    std::string getDeductionType() override;
    void setHomeMortgageInterest(double homeMortgageInterest);
    void setIncomeTaxes(double incomeTaxes);
    void setInvestmentInterest(double investmentInterest);
    void setMedicalExpenses(double medicalExpenses);
    void setCharitableContributions(double charitableContributions);
    void setMiscDeductions(double miscDeductions);
    double calcDeduction() override;

};


#endif //MOLINA_ASSIGNMENT9_ITEMIZEDDEDUCTION_H
