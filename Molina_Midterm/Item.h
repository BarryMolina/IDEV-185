//
// Created by Barry Molina on 3/11/21.
//
#include <string>
using namespace std;

#ifndef MOLINA_MIDTERM_ITEM_H
#define MOLINA_MIDTERM_ITEM_H

// Item is the super class for FreshProduce and MeasuredProduct
// It defines members shared by both classes
class Item {
private:
    static double delivery;
    static double tip;
    string name;
    double price;
public:
    Item();
    Item(string, double);
    static double getDelivery();
    static double getTip();
    string getName();
    double getPrice();
    static void setDelivery(double);
    static void setTip(double);
    void setName(string);
    void setPrice(double);
    // Pure virtual functions that must be overridden
    virtual double calcPrice() = 0;
    virtual string getAmountStr() = 0;
    // Destructor must be declared virtual so objects of derived classes
    // can be deleted through pointer to the base class
    virtual ~Item();
};


#endif //MOLINA_MIDTERM_ITEM_H
