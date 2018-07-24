/*William Saunders
  CSC 110
  Program 3
  11/17/2016
*/
//number fact machine but structured with a functional design
#include <iostream>

using namespace std;

int ErrorCheck(); //declare function prototypes up here!!
void NumTest(int num);

int main()
{
    int num = 0; //tracks input
    char keepGoing = 'y'; //used as conditional for program loop
    while (keepGoing == 'y')
    {
        cout << "Please enter a number: " << endl; //get input
        cin >> num;

        if(!cin)
            num = ErrorCheck(); //assign the results of ErrorCheck() to num

        NumTest(num); //call NumTest and have it print its stuff

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

int ErrorCheck()
{
    int num = 0; //create local num variable and assign new input to it
    while(!cin) //error check input
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Error. Not a number. Please enter a number. " << endl;
        cin >> num;
    }

    return num; //return the new, correct value of num
}

void NumTest(int num) //prints its results instead of returning them
{
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
}
