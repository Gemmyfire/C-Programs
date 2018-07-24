/*  William Saunders
    CSC 110
    Program 1
    10/6/2016 */
//gas mileage calculator using user input; works in US standard and Metric measurements
    #include <iostream>
    #include <string>
    #include <iomanip>

    using namespace std;

    int main()
    {
        string name; //store username
        float miles, gallons, milesPerGallon, kilometers, liters, kilometersPerLiter; //store respective inputs

        //get username
        cout << "Enter name: " << endl;
        cin >> name;

        //get miles
        cout << "Enter miles driven: " << endl;
        cin >> miles;
        while(miles < 0) //check if input is negative, then reevaluate
        {
            cout << "Error. Negative miles detected. Please enter positive number: " << endl;
            cin >> miles;
        }

        //get gallons
        cout << "Enter gallons used: " << endl;
        cin >> gallons;
        while(gallons < 0) //check if input is negative, then reevaluate
        {
            cout << "Error. Negative gallons detected. Please enter positive number: " << endl;
            cin >> gallons;
        }

        //calculate miles/gallon
        milesPerGallon = miles/gallons;

        //calculate metrics
        kilometers = miles * 1.60934;

        liters = gallons * 3.785;

        kilometersPerLiter = kilometers/liters;

        //output results
        cout << showpoint << fixed << setprecision(2); //output results...nicely

        cout << "For user: " << name << endl;
        cout << "Miles driven: " << miles << endl;
        cout << "Gallons used: " << gallons << endl;
        cout << "Miles per gallon: " << milesPerGallon << endl;

        cout << "In metrics: " << endl << endl;
        cout << "Kilometers driven: " << kilometers << endl;
        cout << "Liters used: " << liters << endl;
        cout << "Kilometers per liter: " << kilometersPerLiter << endl;

        return 0;
    }
