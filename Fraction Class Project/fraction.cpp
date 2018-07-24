/*William Keith Saunders
  CSC 210
  Lab 1
  1/25/2017
*/
//defines each function from the class template


#include<iostream>
#include<iomanip>
#include "fraction.h" //includes the header file




//constructor with 2 default parameters
fraction::fraction(int n, int d) //style: class name::function name
{
    if(d == 0)                      //if denominator is 0, force a denominator of 1 instead of running normally or crashing
    {
        cout << "Error. Denominator cannot be 0." << endl;
    }
    numerator = n;
    denominator = d;

    //check for a negative denominator and move the negative sign to the numerator
    if(d < 0)
    {
        denominator = -d;           //uses a unary operator to change the sign
        numerator = -n;
    }

}

fraction::~fraction(){} //destructor function (deallocates memory from where the object was when done. Doing this manually instead of Java's garbage collector

//returns numerator
int fraction::getNumer()
{
    return numerator;
}

//returns denominator
int fraction::getDenom()
{
    return denominator;
}

//sets numerator to i
void fraction::setNumer(int i)
{
    numerator = i;
}

//sets denominator to i
void fraction::setDenom(int i)
{
    denominator = i;
}

//adds parameter fraction to calling fraction
fraction fraction::add(fraction a)
{
    int num1 = numerator * a.denominator; //cross-multiplication, numerator of this fraction * denominator of param fraction
    int num2 = a.numerator * denominator; //this + num1 = numerator of result fraction
    int denom = denominator * a.denominator; //denominator of the result fraction
    fraction result(num1 + num2, denom); //create a result fraction, use num1 + num2 for numerator, denom for denominator
    return result;
}

//nearly the same code as add function with the only difference being that result is created with num1 - num2
fraction fraction::subtract(fraction a)
{
    int num1 = numerator * a.denominator; //cross-multiplication, numerator of this fraction * denominator of param fraction
    int num2 = a.numerator * denominator; //this + num1 = numerator of result fraction
    int denom = denominator * a.denominator; //denominator of the result fraction
    fraction result(num1 - num2, denom); //create a result fraction, use num1 - num2 for numerator, denom for denominator
    return result;
}

//multiplies this fraction and another fraction, returns the resulting fraction
fraction fraction::multiply(fraction a)
{
    int num = numerator * a.numerator; //resulting numerator is product of both numerators
    int denom = denominator * a.denominator; //resulting denominator is product of both denominators
    fraction result(num, denom); //create resultant fraction
    return result;
}

//divides calling fraction by parameter fraction
fraction fraction::divide(fraction a)
{
    fraction InverseA = a.getInverse(); //inverse a
    return multiply(InverseA); //use inversed a in multiplication function
}

//swaps numerator and denominator values
fraction fraction::getInverse()
{
    //using variables to work with numerator and denominator so that the original values
    //aren't modified
    int num = numerator;
    int denom = denominator;
    int temp = num; //use temporary variable to hold num
    num = denom;
    denom = temp;
    fraction result(num, denom);
    return result;
}

//takes a double and makes a fraction out of it
fraction fraction::makeFraction(double d)
{
    double resNum = d * 1000000000; //multiply d by 1 billion, had to use 10e9 notation to avoid operand error?? strange
    int resDenom = 1000000000; //make denom 1 billion
    fraction result(static_cast<int>(resNum), resDenom); //create fraction to hold values, cast resNum as int
    result = reduce(result); //reduce result
    return result;
}

//takes an int and a fraction, combines them
fraction fraction::makeImproperFraction(int i, fraction a)
{
    int num = i * a.denominator; //numerator of first fraction will be the int * denominator of the second fraction
    int denom = a.denominator; //denom is same as a.denom
    fraction unreducedFraction (num, denom); //create fraction out of int
    fraction result = unreducedFraction.add(a); //add the two fractions
    return result;
}
//reduce a fraction by finding its gcf and returning a new fraction with the old one's
//numerator and denominator divided by the gcf
fraction fraction::reduce(fraction a)
{
    int factor = gcf(a.numerator, a.denominator); //get greatest common factor of fraction a's numer and denom
    int num = a.numerator/factor; //resultant numerator is a's numer divided by greatest common factor
    int denom = a.denominator/factor;
    fraction result(num, denom);
    return result;
}

//returns decimal version of fraction
double fraction::getDecimal() const
{
    return numerator/static_cast<double>(denominator);
}
//uses Euler's gcf algorithm
int fraction::gcf(int n, int d)
{
    int resGCF = 0; //declaration of result GCF
    int remainder = 0; //initialize remainder to

    while (d != 0) //loops until denominator
    {
        remainder = n % d; //remainder of the n/d div
        n = d; //assign denominator to numerator
        d = remainder; //assign remainder to denominator
    }
    resGCF = n; //assign numerator to result
    return resGCF; //return result GCF
}

//prints to the display in the format given by example
void fraction::print() const //still needs to be formatted to be according to example on handout
{


    cout << fixed << showpoint << setprecision(6);

    cout << setw(4) << numerator << " /";
    cout << setw(4) << denominator;

}

//prints to file "fractionOut.txt" in format given by example
void fraction::print(ostream& fout) const //overloaded to use ostream (output stream) parameter
{

    fout << fixed << showpoint << setprecision(6);
    fout << setw(4) << numerator << " /";
    fout << setw(4) << denominator;

}
