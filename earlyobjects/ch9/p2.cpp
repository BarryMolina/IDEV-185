#include <iostream>
using namespace std;

int binarySearch(const int [], int, int);

int main()
{
    const int SIZE = 20;

    int IDnums[SIZE] = {101, 142, 147, 189, 199, 207, 222,
                        234, 289, 296, 310, 319, 388, 394,
                        417, 429, 447, 521, 536, 600};

    int empID,
        result;

    cout << "Enter the employee ID you wish to search for: ";
    cin >> empID;

    result = binarySearch(IDnums, SIZE, empID);

    if (result == -1)
        cout << "That ID is not in the array.\n";
    else
    {
        cout << "ID " << empID << "was found in element "
            << result << " of the array.\n";
    }
    return 0;
}

int binarySearch(const int array[], int size, int value)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;

    bool found = false;
    int count = 0;

    while (!found && first <= last)
    {
        count++;
        middle = (first + last) / 2;
        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    cout << count << endl;
    return position;
}
