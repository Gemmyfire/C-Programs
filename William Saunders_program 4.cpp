/*William Saunders
  CSC 110
  Program 4
  12/1/2016
*/

//takes in a list of grades and determines what the average grade is and what the total number 
//of grades is 
#include<iostream>

using namespace std;

//reads grades into array from error-checked user input. gradeArray starts with size of 50,
//but the actual ending index of the array is stored in endArrayIndex, which is sent to
//the ResizeArray function.
//PRE CONDITION: gradeArray[] points to valid int array of starting size 50
//POST CONDITION: gradeArray[] is correctly initialized
void InitArray(/* OUT */ int gradeArray[], /* OUT */ int& endArrayIndex);

/*if endArrayIndex is less than 49, activate function which copies contents of
  old array into a new array of the correct size without the unknown numbers on
  the end of the old gradeArray; uses a new array called int resizedGradeArray[endArrayIndex+1]*/
//PRE CONDITION: endArrayIndex < 49 and resizedGradeArray points to a valid int array
//POST CONDITION: resizedGradeArray is filled out with the correct values from gradeArray
void ResizeArray(/* IN */ int gradeArray[], /* OUT */ int resizedGradeArray[], int endArrayIndex);

//loops through gradeArray and sums each element, const
//safeguards gradeArray[] from being changed accidentally
//PRE CONDITION: gradeArray[] has been initialized with size int arraySize
//POST CONDITION: valid sum has been totalled
int SumArray(/* IN */ const int gradeArray[], /* IN */ int arraySize);

//obtains sum of gradeArray[] from the function sumArray(...), then divides the sum by
//the number of grades and returns the average
//PRE CONDITION: arraySize and sum parameters are valid
//POST CONDITION: none.
int AverageArray(/* IN */ int arraySize, /* IN */ int sum);

//loops through gradeArray[] and prints contents. displays * next to grade if it's less than the average
//PRE CONDITION: gradeArray[] and average point to valid variables
//POST CONDITION: none.
void PrintArray(/* IN */ const int gradeArray[], /* IN */ int arraySize, /* IN */ int average);
int main()
{
    int endArrayIndex = 49; //starts at 49 because it will not be modified if gradeArray contains 50 items
    int gradeArray[50]; //declare the variable for gradeArray
    int resizedGradeArray[endArrayIndex+1]; //declare variable for resizedGradeArray with size endArrayIndex+1
    int sum = 0; //holds sum of array
    int average = 0; //holds average of array
    InitArray(gradeArray, endArrayIndex); //call function to initialize array

    if(endArrayIndex < 49) //if gradeArray contained a negative number
    {
        cout << "Ending array index was less than 49. Resizing array..." << endl;

        ResizeArray(gradeArray, resizedGradeArray, endArrayIndex); //call resize array function

        cout << "Array has been resized." << endl << endl;

        //call sum and average array functions using resized array and new size
        sum = SumArray(resizedGradeArray, endArrayIndex+1);
        average = AverageArray( endArrayIndex+1, sum);
    }
    else //call sum and average using grade array and default size 50
    {
        sum = SumArray(gradeArray, 50);
        average = AverageArray(50, sum);

    }

    //print number or grades and average
    cout << "total number of grades is: " << endArrayIndex+1 << endl;
    cout << "average is: " << average << endl;

    //print array, branches for resized array and grade array
    cout << "Printing array..." << endl << endl;
    if(endArrayIndex < 49)
    {
        PrintArray(resizedGradeArray, endArrayIndex+1, average);
    }
    else
    {
        PrintArray(gradeArray, 50, average);
    }
    return 0;
}

//defining InitArray function
void InitArray(/* OUT */ int gradeArray[], /* OUT */ int& endArrayIndex)
{
    for(int i = 0; i < 50; i++)
    {
        cout << "Please enter an int value between 0 and 100 (inclusive) (enter a negative value to stop input) for gradeArray at index " << i << ": " << endl;
        cin >> gradeArray[i];

        while(!cin) //error checking for type
        {
            cin.clear();
            cin.ignore(100,'\n');

            cout << "ERROR. Please enter an INT value between 0 and 100 (inclusive) for gradeArray at index " << i << ": " << endl;
            cin >> gradeArray[i];
        }

        while(gradeArray[i] > 100) //error checking for correct value
        {
            cout << "ERROR. Please enter an int value less than 100 for gradeArray at index " << i << ": " << endl;
            cin >> gradeArray[i];
        }

        if(gradeArray[i] < 0) //checking for halt signal
        {
            endArrayIndex = i-1; //store index at which the array actually ends
            cout << "Halting input process." << endl << endl;
            break; //stop function
        }
    }
}
//defining ResizeArray function
void ResizeArray(/* IN */ int gradeArray[], /* OUT */ int resizedGradeArray[], int endArrayIndex)
{
    for(int i = 0; i <= endArrayIndex; i++)
    {
        resizedGradeArray[i] = gradeArray[i];
    }
}

//defining sumArray function
int SumArray(/* IN */ const int gradeArray[], /* IN */ int arraySize)
{
    int tempSum = 0;
    for(int i = 0; i < arraySize; i++)
    {
        tempSum += gradeArray[i];
    }
    return tempSum;
}

//defining AverageArray function
int AverageArray(/* IN */ int arraySize, /* IN */ int sum)
{
    int tempAverage = sum/arraySize;
    return tempAverage;
}

//defining PrintArray function
void PrintArray(/* IN */ const int gradeArray[], /* IN */ int arraySize, /* IN */ int average)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << gradeArray[i];
        if(gradeArray[i] < average)
        {
            cout << "* ";
        }
        else
        {
            cout << " ";
        }
        if((i > 0) && (i % 10 == 0)) //newline every 10 grades
        {
            cout << endl;
        }
    }
}
