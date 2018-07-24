/*William (Keith) Saunders
  CSC 210
  Lab 1
  1/25/2017
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "fraction.cpp"             //includes the header file and the fraction class because of inheritance
using namespace std;



ifstream fin ("fractionIn.txt");    //create input and output file objects
ofstream fout ("fractionOut.txt");


//--------------------------Prototypes-------------------------------


//prototype for function to print the header of the output
//PRECONDITION: None
//POSTCONDITION: None
void printHeader();

//prototype for function to print the addition section of output, takes fraction parameters for frac1, frac2, added
//PRECONDITION: frac1, frac2, added all point to valid objects
//POSTCONDITION: None
void printAdd(fraction frac1, fraction frac2, fraction added);

//prototype for function to print the subtraction section, takes frac1, frac2, substracted fraction result
//PRECONDITION: frac1, frac2, subtracted all point to valid objects
//POSTCONDITION: None
void printSub(fraction frac1, fraction frac2, fraction subtracted);

//prototype prints multiplication section
//PRECONDITION: frac1, frac2, mult all point to valid objects
//POSTCONDITION: None
void printMult(fraction frac1, fraction frac2, fraction mult);

//prototype prints division section
//PRECONDITION: frac1, frac2, div all point to valid objects
//POSTCONDITION: None
void printDiv(fraction frac1, fraction frac2, fraction div);

//prototype prints inversion of frac1
//PRECONDITION: frac1 and inv1 point to valid objects
//POSTCONDITION: None
void printInv1(fraction frac1, fraction inv1);

//prototype pints inversion of frac2
//PRECONDITION: frac2 and inv2 point to valid objects
//POSTCONDITION: None
void printInv2(fraction frac2, fraction inv2);

//prototype pints getDecimal() of frac1
//PRECONDITION: frac1 points to valid object
//POSTCONDITION: None
void printEq1(fraction frac1);

//prototype pints getDecimal() of frac2
//PRECONDITION: frac2 points to valid object
//POSTCONDITION: None
void printEq2(fraction frac2);

//prototype prints the improper fraction made from input and frac1 section
//PRECONDITION: frac1Improp. frac1, and improp1 point to valid objects
//POSTCONDITION: None
void printImprop1(int frac1Improp, fraction frac1, fraction improp1);

//prototype prints the improper fraction made from input and frac2 section
//PRECONDITION: frac2Improp. frac2, and improp2 point to valid objects
//POSTCONDITION: None
void printImprop2(int frac2Improp, fraction frac2, fraction improp2);

//prototype prints the decimal conversion of a fraction
//PRECONDITION: deci and makeFrac point to  valid objects
//POSTCONDITION: None
void printMakeFrac(double deci, fraction makeFrac);



int main()
{

    int frac1Num, frac1Denom, frac2Num, frac2Denom;             //first four inputs on every line of input file are ints
    double deci;                                                //then there's always a decimal number (a double)
    int frac1Improp, frac2Improp;                               //finally, two more ints


    //priming read (read lines first, then work with data)
    fin >> frac1Num >> frac1Denom >> frac2Num >> frac2Denom;    //read all data from first line
    fin >> deci >> frac1Improp >> frac2Improp;

    printHeader();                                              //print header output

    for(int counter = 1; !fin.eof(); counter++)                 //for loop while there's still data left in the file; use counter
    {                                                           //variable to keep track of iterations for data set line





        cout << "         Data Set" << counter;                 //keeping these out lines in main because they rely on the local loop counter
        cout << "  Fraction 1" << "     Fraction 2" << "        Solution" << endl;
        cout << setw(18) << "  ----------";
        cout << "  " << "----------" << "     " << "----------" << "        " << "--------" << endl;

        fout << "         Data Set" << counter;
        fout << "  Fraction 1" << "     Fraction 2" << "        Solution" << endl;
        fout << setw(18) << "  ----------";
        fout << "  " << "----------" << "     " << "----------" << "        " << "--------" << endl;


        //----------------------creation section--------------------------

        fraction frac1(frac1Num, frac1Denom); //create first fraction
        frac1 = frac1.reduce(frac1);          //reduce first fraction

        fraction frac2(frac2Num, frac2Denom); //create second fraction
        frac2 = frac2.reduce(frac2);          //reduce second fraction

        //----------------------addition section--------------------------

        fraction added = frac1.add(frac2);    //create fraction to hold result of adding frac1 and frac2
        added = added.reduce(added);          //reduce added

        printAdd(frac1, frac2, added);        //call function to print the addition line


        //----------------------subtraction section--------------------------

        fraction subtracted = frac1.subtract(frac2);    //fraction to hold result of frac1-frac2
        subtracted = subtracted.reduce(subtracted);     //reduce

        printSub(frac1, frac2, subtracted);

        //----------------------multiplication section--------------------------

        fraction mult = frac1.multiply(frac2);          //frac1*frac2
        mult = mult.reduce(mult);                       //reduce

        printMult(frac1, frac2, mult);

        //----------------------division section--------------------------

        fraction div = frac1.divide(frac2);             //frac1/frac2
        div = div.reduce(div);                          //reduce

        printDiv(frac1, frac2, div);


        //----------------------frac1 inversion section--------------------------
        fraction inv1 = frac1.getInverse();

        printInv1(frac1, inv1);

        //----------------------frac2 inversion section--------------------------
        fraction inv2 = frac2.getInverse();

        printInv2(frac2, inv2);

        //----------------------Equiv. frac1 section--------------------------
        printEq1(frac1);


        //----------------------Equiv. frac2 section--------------------------
        printEq2(frac2);


        //----------------------Improper frac1 section--------------------------
        fraction improp1 = frac1.makeImproperFraction(frac1Improp, frac1); //improp made from input and frac1
        improp1 = improp1.reduce(improp1);                                 //reduce

        printImprop1(frac1Improp, frac1, improp1);


        //----------------------Improper frac2 section--------------------------
        fraction improp2 = frac2.makeImproperFraction(frac2Improp, frac2); //improp made from input and frac2
        improp2 = improp2.reduce(improp2);                                 //reduce

        printImprop2(frac2Improp, frac2, improp2);


         //----------------------Deci. to fraction section-----------------------

        fraction makeFrac = frac2.makeFraction(deci);

        printMakeFrac(deci, makeFrac);

        //-----------------------------------------------------------------------

        cout << endl << endl;                                               //create gap for next iteration
        fout << endl << endl;

        fin >> frac1Num >> frac1Denom >> frac2Num >> frac2Denom;            //priming read for next iteration
        fin >> deci >> frac1Improp >> frac2Improp;


    }
        fin.close();
        fout.close();

	return 0;
}


//-------------------------function definition section----------------
//(all functions very self-explanatory. pretty much all doing simple printing
void printHeader()
{
    cout << "                F R A C T I O N   O P E R A T I O N S        " << endl;
    cout << "                -------------------------------------" << endl << endl;
    cout << "                      Written by Keith Saunders" << endl << endl;

    //file output section
    fout << "                F R A C T I O N   O P E R A T I O N S        " << endl;
    fout << "                -------------------------------------" << endl << endl;
    fout << "                      Written by Keith Saunders" << endl << endl;
}


void printAdd(fraction frac1, fraction frac2, fraction added)
{
    cout << "         Addition:  "; frac1.print();

    cout << "   + ";  frac2.print();
    cout << "   =  "; added.print(); cout << endl << endl;

    //file output section
    fout << "         Addition:  ";  frac1.print(fout);

    fout << "   + ";  frac2.print(fout);
    fout << "   =  "; added.print(fout); fout << endl << endl;
}


void printSub(fraction frac1, fraction frac2, fraction subtracted)
{
    cout << "      Subtraction:  "; frac1.print();
    cout << "   - "; frac2.print();
    cout << "   =  "; subtracted.print(); cout << endl << endl;

    //file output section
    fout << "      Subtraction:  "; frac1.print(fout);

    fout << "   - "; frac2.print(fout);
    fout << "   =  "; subtracted.print(fout); fout << endl << endl;
}

void printMult(fraction frac1, fraction frac2, fraction mult)
{
    cout << "   Multiplication:  "; frac1.print();

    cout << "   * "; frac2.print();
    cout << "   =  "; mult.print(); cout << endl << endl;

    //file output section
    fout << "   Multiplication:  "; frac1.print(fout);

    fout << "   * "; frac2.print(fout);
    fout << "   =  "; mult.print(fout); fout << endl << endl;
}

void printDiv(fraction frac1, fraction frac2, fraction div)
{
    cout << "         Division:  "; frac1.print();

    cout << "   / "; frac2.print();
    cout << "   =  "; div.print(); cout << endl << endl;

    //file output section
    fout << "         Division:  "; frac1.print(fout);

    fout << "   / "; frac2.print(fout);
    fout << "   =  "; div.print(fout); fout << endl << endl;
}

void printInv1(fraction frac1, fraction inv1)
{
    cout << "          Inverse:  "; frac1.print();

    cout << "               ";
    cout << "   =  "; inv1.print(); cout << endl << endl;

    //file output section
    fout << "          Inverse:  "; frac1.print(fout);

    fout << "               ";
    fout << "   =  "; inv1.print(fout); fout << endl << endl;
}

void printInv2(fraction frac2, fraction inv2)
{
    cout << "          Inverse:  " << "               ";
    frac2.print();

    cout << "   =  "; inv2.print(); cout << endl << endl;

    //file output section
    fout << "          Inverse:  " << "               ";
    frac2.print(fout);

    fout << "   =  "; inv2.print(fout); fout << endl << endl;
}

void printEq1(fraction frac1)
{
    cout << fixed << showpoint; //get formatting ready to print a decimal number
    cout << "Equiv. fraction 1:  "; frac1.print();

    cout << "               ";
    cout << "   =   " << setw(9) << setprecision(6) << frac1.getDecimal() << endl << endl;

    //file output section
    fout << fixed << showpoint; //get formatting ready to print a decimal number
    fout << "Equiv. fraction 1:  "; frac1.print(fout);

    fout << "               ";
    fout << "   =   " << setw(9) << setprecision(6) << frac1.getDecimal() << endl << endl;
}

void printEq2(fraction frac2)
{
    cout << fixed << showpoint; //get formatting ready to print a decimal number
    cout << "Equiv. fraction 2:  "; cout << "               ";

    frac2.print();
    cout << "   =   " << setw(9) << setprecision(6) << frac2.getDecimal() << endl << endl;

    //file output section
    fout << fixed << showpoint; //get formatting ready to print a decimal number
    fout << "Equiv. fraction 2:  "; fout << "               ";

    frac2.print(fout);
    fout << "   =   " << setw(9) << setprecision(6) << frac2.getDecimal() << endl << endl;
}

void printImprop1(int frac1Improp, fraction frac1, fraction improp1)
{
    cout << "Improper fraction:  ";

    cout << "      " << setw(4) << frac1Improp; cout << "  and"; frac1.print();
    cout << "   =  "; improp1.print(); cout << endl << endl;

    //file output section
    fout << "Improper fraction:  ";

    fout << "      " << setw(4) << frac1Improp; fout << "  and"; frac1.print(fout);
    fout << "   =  "; improp1.print(fout); fout << endl << endl;
}

void printImprop2(int frac2Improp, fraction frac2, fraction improp2)
{
    cout << "Improper fraction:  ";

    cout << "      " << setw(4) << frac2Improp; cout << "  and"; frac2.print();
    cout << "   =  "; improp2.print(); cout << endl << endl;

    //file output section
    fout << "Improper fraction:  ";

    fout << "      " << setw(4) << frac2Improp; fout << "  and"; frac2.print(fout);
    fout << "   =  "; improp2.print(fout); fout << endl << endl;
}

void printMakeFrac(double deci, fraction makeFrac)
{
    cout << "Deci. to Fraction:  ";

    cout << "                "; cout << setprecision(6) << setw(9) << deci;
    cout << "   =  "; makeFrac.print(); cout << endl << endl;

    //file output section
    fout << "Deci. to Fraction:  ";

    fout << "                "; fout << setprecision(6) << setw(9) << deci;
    fout << "   =  "; makeFrac.print(fout); fout << endl << endl;
}
