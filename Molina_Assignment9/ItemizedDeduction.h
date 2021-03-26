//
// Created by Barry Molina on 3/22/21.
//

#ifndef MOLINA_ASSIGNMENT9_ITEMIZEDDEDUCTION_H
#define MOLINA_ASSIGNMENT9_ITEMIZEDDEDUCTION_H

#include "Deduction.h"

class ItemizedDeduction : public Deduction {
private:
    double homeMortgageInterest = 0;
    double incomeTaxes = 0;
    double investmentInterest = 0;
    double medicalExpenses = 0;
    double charitableContributions = 0;
    double miscDeductions = 0;
public:
    double getHomeMortgageInterest() const;
    void setHomeMortgageInterest(double homeMortgageInterest);
    double getIncomeTaxes() const;
    void setIncomeTaxes(double incomeTaxes);
    double getInvestmentInterest() const;
    void setInvestmentInterest(double investmentInterest);
    double getMedicalExpenses() const;
    void setMedicalExpenses(double medicalExpenses);
    double getCharitableContributions() const;
    void setCharitableContributions(double charitableContributions);
    double getMiscDeductions() const;
    void setMiscDeductions(double miscDeductions);
    ItemizedDeduction(double homeMortgageInterest, double incomeTaxes, double investmentInterest,
                      double medicalExpenses, double charitableContributions, double miscDeductions);
    ItemizedDeduction();
    std::string getDeductionType() override;
    double calcDeduction() override;

};


#endif //MOLINA_ASSIGNMENT9_ITEMIZEDDEDUCTION_H
