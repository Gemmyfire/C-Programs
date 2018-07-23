/* William Saunders
   Team: me, Larry Montegomery, Tim Haddox
   CSC 110
   In-Class Assignment 5
   11/3/2016
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    int numTimes, maxNum = 0; //number of times user wants program to run, maximum number they want to print

    //prompt user for numTimes
    cout << "Please enter how many random numbers you want (positive, whole numbers only please): " << endl;
    cin >> numTimes;

    //check !cin first because cin will be assigned 0 if it's in a failstate!
    while(!cin)
    {
        cout << "Error. Not a number: " << endl;
        cin.clear();
        cin.ignore(100, '\n');

        cout << "Please enter how many random numbers you want (positive, whole numbers only please): " << endl;
        cin >> numTimes;
    }

    //error-check numTimes
    while(numTimes <= 0)
    {
        cout << "Error. Please enter a number greater than 0: " << endl;
        cin >> numTimes;
    }

    //prompt user for maxNum
    cout << "Please enter the highest possible random number you want (positive, whole numbers only please): " << endl;
    cin >> maxNum;

    //check for !cin first
    while(!cin)
    {
        cout << "Error. Not a number: " << endl;
        cin.clear();
        cin.ignore(100, '\n');

        cout << "Please enter how the highest possible random number you want (positive, whole numbers only please): " << endl;
        cin >> maxNum;
    }

    //error-check maxNum
    while(maxNum <= 0)
    {
        cout << "Error. Please enter a number greater than 0: " << endl;
        cin >> maxNum;
    }


    //seed rand() with time(NULL)
    srand(time(NULL));

    cout << endl << endl; //formats output to have some space before random number printing

    //run loop to print a random number numTimes
    for(int i = 0; i < numTimes; i++)
    {
        cout << setw(2) << (rand() % maxNum) + 1 << " " ; //make sure printed number is between 1 and maxNum
        if((i % 9) == 0) //print newline every 10 numbers
        {
            cout << endl;
        }
    }
    return 0;
}
