// Josh Williams 
// 3/20/2020
// CSC - 234 - 81A
// Chapter 11 - Program 7 - Corporate Sales

// Design a DivSales class the keeps sales data for a division. Write a program that creates an array of 6 DivSales objects.
// The program should ask for sales for four quarters for each division then display a table showing divison sales for each quarter plus total corporate sales.

#include <iostream>
#include <string>

using namespace std;

// Static data members shall appear in a namespace scope enclosing the member's class definition.
static double totalSales;

class DivSales {

private:
    double qtrSales[4];
    

public:

    double getSales(int index) {
        // Returns the value at a given index in the qtrSales[] array.
        return qtrSales[index];
    }

    void setSales(double q1, double q2, double q3, double q4) {
        // Member function to set quarterly sales values.
        qtrSales[0] = q1;
        qtrSales[1] = q2;
        qtrSales[2] = q3;
        qtrSales[3] = q4;
        // Add the sum to the total.
        totalSales += q1 + q2 + q3 + q4;
    }

    // Static member function declaration
    static double getTotalSales();
};

// Static member function definition
double DivSales::getTotalSales() {
    return totalSales;
}

int main()
{
    // Variables
    DivSales div[6];
    double sales = 0.0;
    
    // Welcome message
    cout << "Corporate Sales\n\n";

    // Gather sales
    for (int i = 0; i < 6; i++) {
        double q1, q2, q3, q4 = 0.0;
        cout << "-- Sales for Division " << i + 1 << " --\n";
        cout << "Qtr 1: $";
        cin >> q1;
        cout << "Qtr 2: $";
        cin >> q2;
        cout << "Qtr 3: $";
        cin >> q3;
        cout << "Qtr 4: $";
        cin >> q4;
        div[i].setSales(q1, q2, q3, q4);
        }
    
    // BEGIN TABLE DISPLAY

    // Header
    cout << "***********************************\n";
    cout << "*                                 *\n";
    cout << "*   Quarterly Sales by Division   *\n";
    cout << "*                                 *\n";
    cout << "***********************************\n";
    cout << "*                                 *\n";

    // Main report data
    
    // Loop through each div[]
    for (int i = 1; i < 7; i++) {
        printf("*          Division %d             *\n", i);
        // Loop through each quarter and print the sales
        for (int j = 1; j < 5; j++) {
            printf("*      Quarter %d: $%-10.2f     *\n", j, div[i - 1].getSales(j - 1));
        }
        cout << "*                                 *\n";
    }

    printf("*     Total Sales: $%-10.2f    *", DivSales::getTotalSales());

    // END TABLE DISPLAY
}

