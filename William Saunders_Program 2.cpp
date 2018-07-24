/*William Saunders
  CSC 110
  Program 2
  10/28/2016
*/
//takes an integer from the user and outputs facts about it, like if it's even/odd
//negative/positive
#include <iostream>

using namespace std;

int main()
{
    int num = 0; //tracks input
    char keepGoing = 'y'; //used as conditional for program loop
    while (keepGoing == 'y')
    {
        cout << "Please enter a number: " << endl; //get input
        cin >> num;
        while(!cin) //error check input
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Error. Not a number. Please enter a number. " << endl;
            cin >> num;
        }
        if(num >= 0) //test for positive or negative
        {
            cout << num << " is positive" << endl;
        }
        else
        {
            cout << num << " is negative" << endl;
        }
        if (num%2 == 0) //test for even or odd
        {
            cout << num << " is even" << endl;
        }
        else
        {
            cout << num << " is odd" << endl;
        }
        cout << "Would you like to enter another number? (y/n) " << endl; //ask for continuation
        cin >> keepGoing;
        while(!cin) //error check response
        {
            cout << "Error. Not an option. Would you like to enter another number? (y/n) " << endl;
            cin >> keepGoing;
        }

    }
    cout << "OK. Goodbye!" << endl; //print upon exiting loop
    return 0;
}
