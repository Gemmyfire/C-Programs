/*William Saunders
  CSC 110
  In-Class Activity Functional Calculator
  11/22/2016

*/
//a calculator which takes user input
//written using functional structure
#include <iostream>
#include <iomanip>
#include <string> //just in case I end up working with strings

using namespace std;

//prompt user for two values, store values, return these new values (modify them) into the previously declared input1/input2
//Pre: input1 and input2 are declared but not necessarily defined
//Post: input1 and input2 contain valid values entered by the user
void GetNums(/* out */ float &input1, /* out */ float& input2);

//Prompt user for choice of valid calculating operation ('A', 'S', 'M', 'D'), then return which valid choice the user made
//Pre: None
//Post: Returns the valid choice
char GetOp();

//Take operation choice, select operation, return result
//Pre: input1, input2 contain valid float values and op contains valid char value
//Post: Return calculated result
float GetResult(/* in */ char op, /* in */ float input1, /* in */ float input2);


int main()
{
    float input1, input2 = 0.0; //initialize input variables with starting value to avoid null error later

    char wantContinue = 'y'; //loop conditional to keep running program or not

    char operation = '.'; //using a variable to store GetOp(), so it doesn't run more than once

    while(wantContinue == 'y') //program will run until user chooses to exit
    {
        cout << setprecision(2) << showpoint << fixed; //formatting

        GetNums(input1, input2); //get user input

        operation = GetOp(); //get user input for operation one time

        cout << "Result is: " << GetResult(operation, input1, input2) << endl; //output result

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


//defining GetNums
void GetNums(/* out */ float &input1, /* out */ float& input2)
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
}


//defining GetOp
char GetOp()
{
    char response; //stores user response until time of return
    cout << "Would you like to (a)dd, (s)ubtract, (m)ultiply, or (d)ivide? " << endl;
    cin >> response; //expecting first letter of one of the options

    while(!cin) //check for cin stream failstate
    {
        cout << "Error. Not a letter. " << endl;
        cin.clear(); //clear failstate flag
        cin.ignore(100,'\n'); //ignore input that caused failstate

        cout << "Enter a letter: " << endl;
        cin >> response;

    }

    /* the switch statement for result used to be here (in the previous version of this program)
       but that is now part of GetResult, so I replaced it with this long conditional checking for
       correctness of input */
    while(response != 'a' && response != 'A' &&
          response != 's' && response != 'S' &&
          response != 'm' && response != 'M' &&
          response != 'd' && response != 'D')
    {
        cout << "Error. Not a choice. " << endl;
        cin >> response;
    }
    return response;
}




//defining GetResult
float GetResult(/* in */ char response, /* in */ float input1, /* in */ float input2)
{
    float result = 0; //holds result of operation until time of return
    switch(response)
    {
        case 'A': //addition, ignoring case
        case 'a': result = input1 + input2;
        cout << "Adding..." << endl; //a little message for politeness
        break;

        case 'S': //subtraction, ignoring case
        case 's': result = input1 - input2;
        cout << "Subtracting..." << endl;
        break;

        case 'M': //multiplication, ignoring case
        case 'm': result = input1 * input2;
        cout << "Multiplying..." << endl;
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
                cout << "Dividing..." << endl;
            }
            break;

        default: cout << "Error. Not an option. " << endl;
    }
    return result;
}
