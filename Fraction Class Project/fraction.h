
//header file for lab 1
//template for a Fraction class, which owns various functions
//like addition, subtraction, etc. with other fraction objects,
//type conversion, and toString printing
//utilizes abstraction between publicly accessible functions
//and private fields

/* fraction.h  (Header file for the class, fraction)
   Written by William (Keith) Saunders
   Conditions:  a fraction has an integer numerator and denominator
   The class will demonstrate all fraction operations from elem. school
*/
#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

class fraction
{
   public:
   	fraction (int n = 0, int d = 1);	// constructor with 2 default params
	~fraction();              	   	// destructor explained more in class
        fraction add(fraction);      		// adds two fractions returning a third
   	fraction subtract(fraction);   		// subtracts two fractions returning third
        fraction multiply(fraction);  		// multiplies two fractions returning third
        fraction divide(fraction);		// divides two fractions returning a third
        fraction makeFraction(double);		// converts any decimal to a fraction
	fraction makeImproperFraction(int, fraction); // input a whole & fract -> improper
	fraction getInverse();                  // swaps the numerator and denominator
	fraction reduce(fraction);              // reduces the fraction to lowest terms
	double getDecimal() const;       	// return fraction's decimal equivalent;
	void setNumer(int);              	// sets the private member numerator
	void setDenom(int);                     // sets the private member denominator
	int getNumer();                         // gets the private member numerator
	int getDenom();                         // gets the private member denominator
	void print() const;                     // prints the fraction to the console
	void print(ostream&) const;    	        // prints the fraction to the file

   private:
	int numerator;                   // private int member for numerator
	int denominator;                 // private int member for denominator
	int gcf(int, int);               // private function for greatest comm factor
};

#endif // FRACTION_H

