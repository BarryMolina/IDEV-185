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
    double calcFullPrice();
    int getQuantity();
    void setQuantity(int);
    int amount();
};


#endif //MOLINA_MIDTERM_MEASUREDPRODUCT_H
