#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>

using namespace std;

class Coin
{
private:
    string sideUp;
    bool heads;
    double value;

public:
    Coin();
    Coin(double);
    void toss();

    bool getHeads()
    {
        return heads;
    }

    double getValue()
    {
        return value;
    }

    string getSideUp()
    {
        return sideUp;
    }
};

Coin::Coin()
{
    unsigned seed;
    seed = time(0);
    srand(seed);
    toss();
}

Coin::Coin(double val)
{
    Coin();
    value = val;
}

void Coin::toss()
{
    heads = rand() % 2;

    sideUp = (heads ? "HEADS" : "tails");
}

const double WINNING_AMOUNT = 1.00;
const int ROUND_COL = 8;
const int QUARTER_COL = 10;
const int DIME_COL = 8;
const int NICKLE_COL = 8;

void clearScreen();
double tossCoin(Coin &coin);
bool compareFloat(double a, double b, double epsilon = 0.001f);

int main() {

    Coin quarter(0.25)
         ,dime(0.10)
         ,nickle(0.05);

    double balance,
           roundTotal;
    int round;
    string again,
           dashes;
    bool quit = false;

    dashes.assign(41, '-');

    cout << "\n\nWelcome to the CoinToss game!" <<
            "\n\nIn this game, three simulated coins are tossed for you" <<
            "\neach round, one representing a quarter, one representing" <<
            "\na dime, and one representing a nickle. If a coin lands" <<
            "\nheads up, the value of that coin is added to your balance." <<
            "\nAt the end of each round, if your balance is exactly $1" <<
            "\nyou win the game. However, if it goes above $1 you lose." <<
            "\n\nLet's play!" << endl;

    cout << "\nPress <enter> to begin";
    cin.get();
    clearScreen();

    while (!quit)
    {
        round = 1;
        balance = 0.00;

        cout << left << setw(ROUND_COL) << "Round" << setw(QUARTER_COL) << "Quarter"
             << setw(DIME_COL) << "Dime" << setw(NICKLE_COL) << "Nickle"
             << "Balance" << endl;
        cout << dashes << endl;

        while (balance < WINNING_AMOUNT)
        {
            roundTotal = 0.00;

            roundTotal += tossCoin(quarter);
            roundTotal += tossCoin(dime);
            roundTotal += tossCoin(nickle);
            balance += roundTotal;

            cout << fixed << setprecision(2);
            cout << setw(ROUND_COL) << round;
            cout << setw(QUARTER_COL) << quarter.getSideUp();
            cout << setw(DIME_COL) << dime.getSideUp();
            cout << setw(NICKLE_COL) << nickle.getSideUp();
            cout << "$" << balance;
            cout << endl;
            round++;
        }
        cout << endl;

        if (compareFloat(balance, WINNING_AMOUNT))
        {
            cout << "Balance is exactly $" << WINNING_AMOUNT << endl;
            cout << "Congratulations, you win!" << endl;
        }
        else
        {
            cout << fixed << setprecision(2);
            cout << "Balance went over $" << WINNING_AMOUNT << " so you lose." << endl;
        }
        cout << "\nPlay again? y/n: ";
        cin >> again;

        if (tolower(again[0]) != 'y')
            quit = true;

        clearScreen();
    }
    cout << "\n\nThank you for playing!. Goodbye." << endl;

    return 0;
}

double tossCoin(Coin &coin)
{
    coin.toss();

    if (coin.getHeads())
        return coin.getValue();
    return 0.00;
}

bool compareFloat(double a, double b, double epsilon)
{
    return abs(a - b) < epsilon;
}

void clearScreen()
{
    string newScreen;
    newScreen.assign(20, '\n');
    cout << newScreen;
}
