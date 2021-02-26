#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(string name1, int age1)
    {
        name = name1;
        age = age1;
    }
    int getAge() { return age; }
    string getName() { return name; }
};

struct Rectangle
{
    int width, height;
};


int main()
{
    Rectangle *pRect = nullptr;
    Person *pPerson = nullptr;

    Rectangle rect;
    pRect = &rect;
    (*pRect).height = 12;
    pRect->width = 10;
    cout << "Area of the first rectangle is "
        << pRect->width * pRect->height;

    pRect = new Rectangle;
    pRect->height = 6;
    pRect->width = 5;

    cout << "\nArea of the second rectangle is "
        << pRect->width * pRect->height;
    delete pRect;
    pRect = nullptr;

    pPerson = new Person("Miquel E. Gonzalez", 23);
    cout << "\n\nThe person's name is " << pPerson->getName();
    cout << "\n\nThe person's age is " << pPerson->getAge() << endl;

    delete pPerson;
    pPerson = nullptr;

    return 0;
}
