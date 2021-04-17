// Barry Molina
// ITDEV-185-900
// Assignment 11
// 4/17/21
#include <iostream>
#include <string>
using namespace std;

// Ask user for word and check it with isPalindrome().
void inputWord();
// Use recursion to check if inputted word is a palindrome.
bool isPalindrome(string input, int lower, int upper);

// Application start. Provides user with a main menu
// where they can choose to check if a word is a palindrome
// or quit the application.
int main() {
    bool quit = false;
    int ans;
    while (!quit) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "MAIN MENU\n" << endl;
        cout << "1. Check if word is a palindrome" << endl;
        cout << "2. Quit" << endl;
        cout << "\n>>> ";
        cin >> ans;
        while (ans < 1 || ans > 2) {
            cout << "\nInvalid selection." << endl;
            cout << "\n>>> ";
            cin >> ans;
        }
        if (ans == 1) {
            inputWord();
        }
        else {
            quit = true;
        }
    }
    return 0;
}

// Ask user for word and check it with isPalindrome().
// If no word is entered returns to the main menu.
void inputWord() {
    string word;
    bool isPal;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cin.ignore();

    do {
        word.clear();
        cout << "\nInput word or press <enter> to return to the Main Menu" << endl;
        cout << ">>> ";
        getline(cin, word);

        if (!word.empty()) {
            isPal = isPalindrome(word, 0, word.length() - 1);

            cout << endl << word << " is " << (isPal ? "" : "not ") << "a palindrome" << endl;
        }
    } while (!word.empty());
}

// Recursive function to check if word is a palindrome.
// Parameters
// input: string holding the word to be checked
// lower: index of first character to compare
// upper: index of second character to compare

bool isPalindrome(string input, int lower, int upper) {
    // Returns true if index of first char is greater than or equal to the second.
    // This means that either there are no more characters to check
    // or the function is asked to check if a character is equal to itself.
    if (lower >= upper) {
        return true;
    }
    // If the characters at lower and upper index match, continue checking
    // the rest of the word.
    else if (tolower(input[lower]) == tolower(input[upper])) {
        return isPalindrome(input, ++lower, --upper);
    }
    // Characters differ, stop checking word
    else {
        return false;
    }
}
