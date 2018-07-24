/*William Saunders
  Teammate: Larry Montegomery
  CSC 110
  11/8/2016
*/
//game: a random number generator picks a number, and the user guesses it 
//using the prompt
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int randNum = 1; //stores the generated number
    int guess = 1; //stores the user's guess
    bool tooHigh = false; //true if guess is too high, false otherwise
    bool match = false; //true if guess matches generated number

    srand(time(NULL)); //seed random generator

    randNum = (rand() % 101 + 1); //generate and store random number in range

    cout << "A random number has been generated. Enter a number between 1 and 100 to guess: " << endl; //get user input
    cin >> guess;

        while(!cin || (guess < 1 && guess > 100)) //error check
        {
            cout << "Error. Please enter a number between 1 and 100: " << endl;
            if(!cin) //if user entered a non-number
            {
                cin.clear();
                cin.ignore(100,'\n');
            }
            cin >> guess;
        }
        do //begin loop for game, loop once before checking condition
        {
            if(guess < randNum) //if user input is too low
            {
                cout << "Too low! Guess again: " << endl;
                cin >> guess;

                while(!cin || (guess < 1 && guess > 100)) //error check again
                {
                    cout << "Error. Please enter a number between 1 and 100: " << endl;
                    if(!cin)
                    {
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    cin >> guess;
                }
            }

            else if(guess > randNum) //if user input is too high, set boolean flag true
            {
                tooHigh = true;
            }
            else //if user input matches the random number, set boolean flag true
            {
                match = true;
            }

            if(tooHigh == true) //if guess was too high
            {
                cout << "Too high! Guess again: " << endl;
                cin >> guess;

                while(!cin || (guess < 1 && guess > 100)) //error check again
                {
                    cout << "Error. Please enter a number between 1 and 100: " << endl;
                    if(!cin)
                    {
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    cin >> guess;
                }
            }
        }while(!match); //end of loop, which runs once and afterwards under the condition there was no match

    cout << "Correct! Ending game. " << endl; //print out when input matches random num

    return 0;
}
