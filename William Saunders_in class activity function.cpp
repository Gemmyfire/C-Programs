/*William Saunders
  CSC 110
  In Class Activity (First Function)
  11/17/2016
*/
//does some simple input checking and functional design
#include <iostream>

using namespace std;

void CheckParams(int a, int b); //ALWAYS have function prototypes at top!!

int main()
{
    int a, b = 0; //variables that will store user input
    bool negInput = false; //flag for do while loop

    do
    {
        cout << "Please enter two positive integers (enter a negative integer to exit program): " << endl; //get input
        cin >> a >> b;

        while(!cin) //check for wrong type of input
        {
            cin.clear(); //clear failstate
            cin.ignore(100, '\n'); //ignore input that caused the failstate

            cout << "Please enter INTEGERS: " << endl; //reprompt
            cin >> a >> b;
        }

        if(a < 0 || b < 0) //if input is negative, set flag
            negInput = true;

        else //if everything is okay, run program
        {
            CheckParams(a,b);
        }

    } while(!negInput);

    cout << "See ya later!" << endl;
    return 0;
}

void CheckParams(int a, int b) //define function
{
    if(a == b) //if a and b are equal
    {
        cout << "Equal!" << endl;
    }
    else //if not
        cout << "Not equal." << endl;
}
