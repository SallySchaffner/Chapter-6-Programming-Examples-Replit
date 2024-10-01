// Chapter 6 Programming Examples: Falling Distance
// Create a table showing the distance traveled by an object for seconds 1 through 10.

#include <iostream>
#include <iomanip>

using namespace std;

double getDistance(int);

int main()
{
  double distance;

  cout << fixed << setprecision(1) << showpoint;
  cout << "Distance traveled in Meters" << endl;
  cout << "Time (in seconds)     Distance (in meters)" << endl;

  for (int seconds = 1; seconds <= 10; seconds++)
  {
    distance = getDistance(seconds);
    cout << setw(5) << seconds << setw(25) << distance << endl;
  }
  cout << endl;

  return 0;
}

double getDistance(int time)
{
  const double GRAVITY = 9.8;
  double distance;
  distance = .5 * GRAVITY * time * time;
  return distance;
}