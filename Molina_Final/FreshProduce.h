//
// Created by Barry Molina on 3/11/21.
//

#ifndef MOLINA_MIDTERM_FRESHPRODUCE_H
#define MOLINA_MIDTERM_FRESHPRODUCE_H

#include "Item.h"

// The FreshProduce class inherits from Item.
// It is specialized to represent items whose price
// is calculated by weight
class FreshProduce : public Item {
private:
    int pounds = 0;
public:
    FreshProduce(string name, double price, int pounds);
    double calcFullPrice();
    int getPounds();
    void setPounds(int);
    int amount();
};


#endif //MOLINA_MIDTERM_FRESHPRODUCE_H
