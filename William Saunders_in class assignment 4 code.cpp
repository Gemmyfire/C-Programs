/*William Saunders
  CSC 110
  In-Class Assignment 4
  10/25/2016

  and Stephanie Alvarez, Nina Salugao
*/
//interactive calculator with menu prompts, error checking, and looping
#include <iostream>
#include <iomanip>
#include <string> //just in case I end up working with strings

using namespace std;

int main()
{
    float input1, input2 = 0.0; //initialize input variables with starting value to avoid null error later
    char response; //going to store user response for choice later
    float result; //stores result
    char wantContinue = 'y'; //loop conditional to keep running program or not

    while(wantContinue == 'y') //program will run until user chooses to exit
    {
        cout << "Enter two numbers: " << endl;
        cin >> input1 >> input2;

        while(!cin) //check for cin stream failstate
        {
            cout << "Error. Not a number. " << endl;
            cin.clear(); //clear failstate flag
            cin.ignore(100,'\n'); //ignore input that caused failstate

            cout << "Enter two numbers: " << endl;
            cin >> input1 >> input2;

        }
        cout << "Would you like to (a)dd, (s)ubtract, (m)ultiply, or (d)ivide? " << endl;
        cin >> response; //expecting first letter of one of the options

        cout << setprecision(2) << showpoint << fixed; //formatting

        switch(response)
        {
            case 'A': //addition, ignoring case
            case 'a': result = input1 + input2;
            cout << "Result: " << result << endl;
            break;

            case 'S': //subtraction, ignoring case
            case 's': result = input1 - input2;
            cout << "Result: " << result << endl;
            break;

            case 'M': //multiplication, ignoring case
            case 'm': result = input1 * input2;
            cout << "Result: " << result << endl;
            break;

            case 'D': //division, ignoring case
            case 'd':
                if(input2 == 0.00) //because I have precision set to 2 decimal places
                {
                    cout << "Error. Division by 0" << endl;
                }
                else
                {
                    result = input1 / input2;
                    cout << "Result: " << result << endl;
                }
            break;

            default: cout << "Error. Not an option. " << endl;
        }
        cout << "Would you like to continue? (y/n) " << endl;
        cin >> wantContinue;

        while(!cin)
        {
            cout << "Error. Not a choice. " << endl;
            cin.clear();
            cin.ignore(100,'\n');

            cout << "Would you like to continue? (y/n) " << endl;
            cin >> wantContinue;
        }
    }
    return 0;
}
