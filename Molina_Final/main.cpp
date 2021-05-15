// Barry Molina
// ITDEV-185-900
// Final
// 5/14/21

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "FreshProduce.h"
#include "MeasuredProduct.h"
#include "MenuError.h"
#include "InputError.h"
using namespace std;

// Global constants
const double DELIVERY_FEE = 20.00,
             TIP = 5.00;

const int freshProduceSize = 3,
          meatAndSeafoodSize = 3,
          frozenFoodSize = 3;

const int NAME_COL = 15;
const int PRICE_COL = 10;
const int AMOUNT_COL = 15;
const int CALC_PRICE_COL = 15;

// Item info
const string freshProduceNames [] = { "Gala apples", "Bananas", "Grapes" };
const double freshProducePrices [] = { 3.99, 0.48, 2.99 };

const string meatAndSeafoodNames [] = { "Whole chicken", "Ground beef", "Salmon" };
const double meatAndSeafoodPrices [] = { 6.99, 4.99, 9.99 };

const string frozenFoodNames [] = { "Waffles", "Pizza", "Popsicle" };
const double frozenFoodPrices [] = { 6.99, 4.99, 2.99 };

// Vector of pointers to items in the users cart
vector<Item*> cart;

// UI functions
void orderStart();
void mainMenu();
void freshProduceMenu();
void meatAndSeafoodMenu();
void frozenFoodsMenu();
void displayCart();
void checkout();

// Utility functions
void clearScreen();
void clearOrder();
int convertInput(string input);
void validateChoice(int maxChoice, int input);
int getMenuSelection(int maxChoice);
int inputAmount();

int main() {
    bool quit = false;
    string again;

    while (!quit) {
        orderStart();

        cout << "\nPlace another order? y/n: ";
        cin >> again;
        if (tolower(again[0]) != 'y')
            quit = true;
        else {
            clearOrder();
        }
    }
    cout << "\nThank you for shopping with us. Goodbye.";
    return 0;
}

// orderStart gets the users delivery preference
void orderStart() {
    int choice;

    clearScreen();
    cout << "ORDER START" << endl;
    cout << "\nPlease select one of the following options\n" << endl;
    cout << "(1) Pickup" << endl;
    cout << "(2) Delivery" << endl;
    cout << "(3) Exit" << endl;

    choice = getMenuSelection(3);

    switch (choice) {
        case 2:
            Item::setDelivery(DELIVERY_FEE);
            Item::setTip(TIP);
        case 1:
            mainMenu();
        case 3:
            break;
    }
}

// The Main Menu lets the user pick a category of food
void mainMenu() {
    int choice;
    bool checkedOut = false;

    while(!checkedOut) {
        clearScreen();
        cout << "MAIN MENU" << endl;
        cout << "\nPlease select one of the following options\n" << endl;
        cout << "(1) Fresh Produce" << endl;
        cout << "(2) Meat and Seafood" << endl;
        cout << "(3) Frozen Foods" << endl;
        cout << "(4) Check Out" << endl;

        choice = getMenuSelection(4);

        switch (choice) {
            case 1:
                freshProduceMenu();
                break;
            case 2:
                meatAndSeafoodMenu();
                break;
            case 3:
                frozenFoodsMenu();
                break;
            case 4:
                checkout();
                checkedOut = true;
                break;
        }
    }
}

// User shops for fresh produce
void freshProduceMenu() {
    const int returnOption = freshProduceSize + 1;
    int pounds,
        choice,
        selectIdx;
    bool goBack = false;

    FreshProduce *item = nullptr;

    cout << fixed << setprecision(2);

    while (!goBack) {
        clearScreen();
        cout << "FRESH PRODUCE" << endl;
        cout << "\nPlease select one of the following options\n" << endl;

        for (selectIdx = 0; selectIdx < freshProduceSize; selectIdx++) {
            cout << "(" << (selectIdx + 1) << ") " << freshProduceNames[selectIdx]
                 << " $" << freshProducePrices[selectIdx] << "/lb" << endl;
        }
        cout << "(" << (returnOption) << ") Return to Main Menu" << endl;

        choice = getMenuSelection(returnOption);

        if (choice == returnOption)
            goBack = true;
        else {
            cout << "\nEnter pounds: ";
            pounds = inputAmount();

            item = new FreshProduce(
                    freshProduceNames[choice - 1],
                    freshProducePrices[choice - 1],
                    pounds);

            cart.push_back(item);
            cout << "\n" << item->amount() << " lb" << (item->amount() > 1 ? "s " : " ") << "of " << item->getName()
                 << " added to cart." << endl;
            item = nullptr;

            cout << "\nPress <enter> to continue";
            cin.ignore();
            cin.get();
        }
    }
}

// User shops for meat and seafood
void meatAndSeafoodMenu() {
    const int returnOption = meatAndSeafoodSize + 1;
    int pounds,
        choice,
        selectIdx;
    bool goBack = false;

    FreshProduce *item = nullptr;

    cout << fixed << setprecision(2);

    while (!goBack) {
        clearScreen();
        cout << "MEAT AND SEAFOOD" << endl;
        cout << "\nPlease select one of the following options\n" << endl;

        for (selectIdx = 0; selectIdx < meatAndSeafoodSize; selectIdx++) {
            cout << "(" << (selectIdx + 1) << ") " << meatAndSeafoodNames[selectIdx]
                 << " $" << meatAndSeafoodPrices[selectIdx] << "/lb" << endl;
        }
        cout << "(" << (returnOption) << ") Return to Main Menu" << endl;

        choice = getMenuSelection(returnOption);

        if (choice == returnOption)
            goBack = true;
        else {
            cout << "\nEnter pounds: ";
            pounds = inputAmount();

            item = new FreshProduce(
                    meatAndSeafoodNames[choice - 1],
                    meatAndSeafoodPrices[choice - 1],
                    pounds);

            cart.push_back(item);
            cout << "\n" << item->amount() << " lb" << (item->amount() > 1 ? "s " : " ") << "of " << item->getName()
                 << " added to cart." << endl;
            item = nullptr;

            cout << "\nPress <enter> to continue";
            cin.ignore();
            cin.get();
        }
    }

}

// User shops for frozen foods
void frozenFoodsMenu() {
    const int returnOption = frozenFoodSize + 1;
    int choice,
        selectIdx,
        quantity;
    bool goBack = false;

    MeasuredProduct *item = nullptr;

    cout << fixed << setprecision(2);

    while (!goBack) {
        clearScreen();
        cout << "FROZEN FOODS" << endl;
        cout << "\nPlease select one of the following options\n" << endl;

        for (selectIdx = 0; selectIdx < frozenFoodSize; selectIdx++) {
            cout << "(" << (selectIdx + 1) << ") " << frozenFoodNames[selectIdx]
                 << " $" << frozenFoodPrices[selectIdx] << endl;
        }
        cout << "(" << (returnOption) << ") Return to Main Menu" << endl;

        choice = getMenuSelection(returnOption);

        if (choice == returnOption)
            goBack = true;
        else {
            cout << "\nEnter quantity: ";
            quantity = inputAmount();

            item = new MeasuredProduct(
                    frozenFoodNames[choice - 1],
                    frozenFoodPrices[choice - 1],
                    quantity);

            cart.push_back(item);
            cout << "\n" << item->getName() << " x" << item->amount() << " added to cart" << endl;
            item = nullptr;

            cout << "\nPress <enter> to continue";
            cin.ignore();
            cin.get();
        }
    }

}

// Display each item in the users cart and the total cost
void checkout() {
    double cartTotal = 0;
    ostringstream ss1, ss2, ss3, ss4;
    string dashes;

    dashes.assign(55, '-');
    clearScreen();

    cout << "CHECK OUT\n" << endl;
    cout << left << setw(NAME_COL) << "Item Name"
         << right << setw(PRICE_COL) << "Price Per"
         << setw(AMOUNT_COL) << "Amount"
         << setw(CALC_PRICE_COL) << "Calculated"
         << endl;
    cout << dashes << endl;

    // String streams for formatting
    ss1 << fixed << setprecision(2);
    ss2 << fixed << setprecision(2);
    ss3 << fixed << setprecision(2);
    ss4 << fixed << setprecision(2);

    for(Item *item : cart) {
        ss1 << item->getPrice();
        ss2 << item->calcFullPrice();
        cout << left << setw(NAME_COL) << item->getName()
             << right << setw(PRICE_COL) << "$" + ss1.str()
             << setw(AMOUNT_COL) << "x" << item->amount()
             << setw(CALC_PRICE_COL) << "$" + ss2.str()
             << endl;
        ss1.str("");
        ss2.str("");

        cartTotal += item->calcFullPrice();
    }

    ss1 << cartTotal;
    ss2 << Item::getDelivery();
    ss3 << Item::getTip();
    ss4 << cartTotal + Item::getDelivery() + Item::getTip();

    cout << right << endl;
    cout << setw(40) << "Item Subtotal:" << setw(10) << "$" + ss1.str() << endl;
    cout << setw(40) << "Delivery Fee:" << setw(10) << "$" + ss2.str() << endl;
    cout << setw(40) << "Tip:" << setw(10) << "$" + ss3.str() << endl;
    cout << setw(40) << "Order Total:" << setw(10) << "$" + ss4.str() << endl;
}

void clearScreen()
{
    string newScreen;
    newScreen.assign(20, '\n');
    cout << newScreen;
}

// reset values and empty cart
void clearOrder() {
    Item::setTip(0);
    Item::setDelivery(0);

    for (int i = 0; i < cart.size(); i++) {
        delete cart[i];
    }
    cart.clear();
}

// Convert string to int. Throw InputError if non-numeric character is found.
int convertInput(string input) {
    for (char c : input) {
        if (isdigit(c) == 0) {
            throw InputError();
        }
    }
    return stoi(input);
}

// Throw MenuError if input is outside range given
void validateChoice(int maxChoice, int input) {
    if (input < 1 || input > maxChoice) {
        throw MenuError();
    }
}

// Get valid menu selection given a max choice.
int getMenuSelection(int maxChoice) {
    string input;
    int choice;
    bool validChoice = false;

    do {
        cout << "\n>>> ";
        cin >> input;

        try {
            choice = convertInput(input);
            validateChoice(maxChoice, choice);
            validChoice = true;
        }
        catch (InputError inputError) {
            cout << "\nInvalid input character detected. Closing application." << endl;
            exit(EXIT_FAILURE);
        }
        catch (MenuError menuError) {
            cout << "\nMenu choice entered is out of range. Please try again" << endl;
        }
    } while (!validChoice);

    return choice;
}

// Get valid numerical input
int inputAmount() {
    string input;
    int amount;

    cin >> input;

    try {
        amount = convertInput(input);
    }
    catch (InputError inputError) {
        cout << "\nInvalid input character detected. Closing application." << endl;
        exit(EXIT_FAILURE);
    }
    return amount;
}

