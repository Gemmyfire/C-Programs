
//The user program that uses the class circleType

#include <iostream>
#include <iomanip>
#include "circleTypeImp.cpp"

using namespace std;

int main()                                                 //Line 1
{                                                          //Line 2
    circleType circle1(8);                                 //create a Circle using the constructor that takes parameters
    circleType circle2;                                    //create a default Circle

    double radius;                                         //Line 5

    cout << fixed << showpoint << setprecision(2);         //Line 6

    cout << "Line 7: circle1 - "			   //output the object's fields using internal functions
         << "radius: " << circle1.getRadius()
         << ", area: " << circle1.area()
         << ", circumference: " << circle1.circumference()
         << endl;                                          //Line 7

    cout << "Line 8: circle2 - "
         << "radius: " << circle2.getRadius()
         << ", area: " << circle2.area()
         << ", circumference: " << circle2.circumference()
         << endl << endl;                                  //Line 8

    cout << "Line 9: Enter the radius of a circle: ";      //Line 9
    cin >> radius;                                         //Line 10
    cout << endl;                                          //Line 11

    circle2.setRadius(radius);                             //set object's field using function

    cout << "Line 13: After setting the radius." << endl; //Line 13
    cout << "Line 14: circle2 - "
         << "radius: " << circle2.getRadius()
         << ", area: " << circle2.area()
         << ", circumference: " << circle2.circumference()
         << endl;                                          //Line 14

    return 0;                                              //Line 15
}//end main                                                //Line 16
