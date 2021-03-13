//
// Created by Barry Molina on 3/11/21.
//

#ifndef MOLINA_MIDTERM_MEASUREDPRODUCT_H
#define MOLINA_MIDTERM_MEASUREDPRODUCT_H

#include "Item.h"
// MeasuredProduct inherits from Item.
// It is specialized to represent items whose price
// is calculated by quantity
class MeasuredProduct : public Item {
private:
    int quantity = 0;
public:
    MeasuredProduct(string, double, int);
    double calcPrice();
    int getQuantity();
    void setQuantity(int);
    string getAmountStr();
};


#endif //MOLINA_MIDTERM_MEASUREDPRODUCT_H
