// Chapter 6 Programming Examples - Markup
// Calculates retail cost of items given their wholesale price and markup percentage. 
// Repeats as long as the user has more items to enter. 

#include <iostream>
#include <iomanip>

using namespace std;

void getCost_Markup(double&, double&);
double calcRetail(double, double);
void displayRetail(double);


int main()
{
  double wholesaleCost, markupPercentage, retailPrice;
  char again;

  do
  {
    getCost_Markup(wholesaleCost, markupPercentage);
    retailPrice = calcRetail(wholesaleCost, markupPercentage);
    displayRetail(retailPrice);

    cout << "Do you want to continue (Y/N) ";
    cin >> again;
  } while (again == 'Y' || again == 'y');

  return 0;
}

// Gets the wholesale and markup from interactive input, validates,
// and returns the validated wholesale and markup values
void getCost_Markup(double& wholesale, double& markup)
{
  do
  {
    cout << "Enter the wholesale cost: $";
    cin >> wholesale;
  } while (wholesale < 0);

  do
  {
    cout << "Enter the markup percentage: ";
    cin >> markup;
  } while (markup < 0);
}

// Given the wholesale cost and markup percentage of an item,
// calculates and returns the retail price
double calcRetail(double wholesale, double markup)
{
  double retail;
  retail = wholesale + wholesale * markup / 100;
  return retail;
}

// Given the retail price, displays it
void displayRetail(double retail)
{
  cout << fixed << showpoint << setprecision(2) << "Retail price is $" << retail << endl;
}