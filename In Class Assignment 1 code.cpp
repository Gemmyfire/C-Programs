//William Saunders
//In-Class Assignment #1
//9/27/2016
//CSC110
//calculates age using user input
#include <iostream>
using namespace std;

int main()
{
    int yearBorn;
    int currentYear;
    int age;

    cout << "In which year were you born?" << endl;
    cin >> yearBorn;

    currentYear = 2018;
    age = currentYear - yearBorn;

    cout << "You are " << age << " years old!";
    return 0;
}
