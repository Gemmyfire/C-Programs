/*William Saunders
  CSC 110
  Assignment 13 (modification of in class activity arrays 2)
  12/1/2016
*/

//sets up functions to allow a user to enter value into an array at the prompt and then
//tells the user what the total of the values entered is, returns the values,
//and provides functionality to compare two arrays
#include<iostream>

using namespace std;

// Initialize array with values input from the user
// Pre: numArray should point at a valid float array and num should hold the
//      number of array elements
// Post: numArray should contain floats entered by the user
void InitArray(/* OUT */ float numArray[], /* IN */ int num);

// Calculate the sum of all elements in the array and return the result
// Pre: numArray should contain valid values
// Post: Return the sum of all values in the array. numArray is unchanged.
float SumArray(/* IN */ const float numArray[], /* IN */ int num); //numArray is const here in order to avoid altering contents

// Print out the contents of an array
// Pre: Valid array and number of elements in the array
// Post: Prints array contents
void PrintArray(/* IN */ const float numArray[], /* IN */ int num);


// Compares if two arrays contain equivalent elements and returns true or false
// Pre: Both arrays contain the same number of elements, specified by
//      integer in the third parameter
// Post: Returns true if the arrays are equal, false otherwise
bool CompareArrays(/* IN */ const float numArray1[], /* IN */ const float numArray2[], /* IN */ int num);


int main()
{
    const int num = 5;
    float numArray[num];
    float numArray2[num];

    InitArray (numArray, num);
    cout << "Sum: " << SumArray(numArray, num) << endl;

    cout << "Now printing numArray: " << endl;
    PrintArray(numArray, num);

    cout << endl << endl;

    InitArray (numArray2, num);
    cout << "numArray2 has been created. " << endl;

    cout << "Now printing numArray2: " << endl;
    PrintArray(numArray2, num);

    cout << endl << endl;

    cout << "Now comparing numArray and numArray2... " << endl << endl;

    bool compareResult = CompareArrays(numArray, numArray2, num);
    if(compareResult == true)
    {
        cout << "numArray and numArray2 have the same contents." << endl;
    }
    else
    {
        cout << "numArray and numArray2 do not have the same contents." << endl;
    }

    return 0;
}


//defining InitArray with a for loop to get user input until array is filled out
void InitArray(/* OUT */ float numArray[], /* IN */ int num)
{
    //loop through the array to each element and use error-checked input to assign values
    for(int i = 0; i < num; i++)
    {
        cout << "Enter a floating point value: " << endl;
        cin >> numArray[i];

        while(!cin) //error checking for types included
        {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Enter a FLOAT value: " << endl;
            cin >> numArray[i];
        }
    }

}

//defining SumArray
float SumArray(/* IN */ const float numArray[], /* IN */ int num)
{
    float sum = 0.0; //sum variable to be returned after adding all array elements

    for(int i = 0; i < num; i++) //loop through array and add each element to the running sum
    {
       sum += numArray[i];
    }

    return sum; //return the ending sum value
}

//defining PrintArray
void PrintArray(/* IN */ const float numArray[], /* IN */ int num)
{
    for(int i = 0; i < num; i++)
    {
        cout << numArray[i] << " ";
    }
    cout << endl;
}
//defining CompareArrays
bool CompareArrays(/* IN */ const float numArray1[], /* IN */ const float numArray2[], /* IN */ int num)
{
    //loop through both arrays at the same time and end if there is a mismatch found
    for(int i = 0; i < num; i++)
    {
        if(numArray1[i] != numArray2[i])
        {
            return false;
        }
    }
    return true;
}
