// Chapter 6 Programming Examples: Winning Division
// This program determines which of a company?s divisions had the highest quarterly sales.

#include <iostream>

using namespace std;

void getDivInfo(string&, long&);
bool isHigher(long, long);
void showWinner(string, long);

int main()
{
    string division, maxDivision;
    long sales, maxSales;
    char again = 'Y';

    // Initialize max with first company
    getDivInfo(division, sales);
    maxDivision = division;
    maxSales = sales;

    while (again == 'Y' || again == 'y')
    {
        getDivInfo(division, sales);
        if (isHigher(sales, maxSales))
        {
            maxSales = sales;
            maxDivision = division;
        }

        cout << "Type Y to continue: ";
        cin >> again;
    }

    showWinner(maxDivision, maxSales);

    return(0);

}

// This function returns the name of a division 
// and the quarterly sales for that division provided interactively
void getDivInfo(string& division, long& sales)
{
    cout << "Enter the name of the division: ";
    cin >> division;
    do
    {
        cout << "Enter the quarterly sales figure for the " << division << " division: ";
        cin >> sales;
    } while (sales < 0);
}

// This function returns true if value1 is > then value2, 
// otherwise it returns false. 
bool isHigher(long value1, long value2)
{
    return (value1 > value2);
}

// Displays the name and sales amount of the winner
void showWinner(string name, long sales)
{
    cout << "\nThe " << name << " division had the highest sales this quarter.";
    cout << "\nThat division's sales were $" << sales << endl;
}