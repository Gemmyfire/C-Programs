/*William Saunders
  CSC 110
  In-class Assignment 2
  10/6/2016*/
//weekly paycheck calculator with input error checking
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string firstName, lastName; //store user's first and last name
    char middleInit; //store user's middle initial
    float hourlyWage, hoursWorked, salary; //can also be double, stores user's hourly wage, hours worked, and resulting salary


    //the class method:
     //Get username
       cout << "Please enter first name: " << endl;
       cin >> firstName; cin.ignore(1,'\n'); //need to get rid of newline character
       cout << "Please enter middle initial(Enter _ if not applicable): " << endl;
       cin.get(middleInit);
       cout << "Please enter last name: " << endl;
       cin >> lastName;





    //messing around with input stream
    /*cout << "Enter full name: " << endl; //get username
    cin >> firstName >> middleInit >> lastName; //store username using input stream*/

    /*cout << "That was: " << endl << "first name: " << firstName << endl << "middle init: " << middleInit << endl
    << "last name: " << lastName << endl; */ //used for testing

    //get user's hourly wage
    cout << showpoint << fixed << setprecision(2); //format nicely to output decimal point and typical money style precision
    cout << "Enter hourly wage: " << endl << "$ ";
    cin >> hourlyWage;
    if(hourlyWage <= 0 && (!cin)) //check number
    {
        if(!cin)
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "That's not a number!" << endl;
        }
        else
        {
            cout << "Error, wage too low." << endl;
        }
        cout << "Please enter another number: " << endl << "$ "; //re-prompt
        cin >> hourlyWage; //accept new number
    }

    //get user's hours worked
    cout << "Enter number of hours worked: " << endl;
    cin >> hoursWorked;
    if(hoursWorked > 40 || hoursWorked < 0 || (!cin))//check number
    {
        if(!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "That's not a number!" << endl;
        }
        else
        {
            cout << "Error, hours out of bound." << endl;
        }
        cout <<"Please enter number between 0 and 40: " << endl; //re-prompt
        cin >> hoursWorked; //accept new number
    }

    //calculate salary
    salary = hourlyWage * hoursWorked;

    //echo username
    cout << "Your name is: " << firstName << " " << middleInit << " " << lastName << endl;
    //output result
    cout << "Your weekly salary = $" << salary;

    return 0;
}
