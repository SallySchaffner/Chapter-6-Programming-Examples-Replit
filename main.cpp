// Chapter 6 Programming Examples: Lowest Score Drop
// Displays the average of a group of test scores with the lowest score dropped.

#include <iostream>
#include <iomanip>

using namespace std;

double getScore();
bool isLower(double, double);
double calcAverage(double, int, double);

const double MAXSCORE = 100;
const double sentinel = -1;

int main()
{
  double totalScores = 0, score, minScore, avgScore;
  int scoreCounter = 0;

  score = getScore();
  minScore = score;
  do
  {
    totalScores += score;
    if (isLower(score, minScore))
      minScore = score;
    scoreCounter++;
    score = getScore();
  } while (score >= 0);

  avgScore = calcAverage(totalScores, scoreCounter, minScore);

  cout << "The average of the scores is: " << avgScore << endl;
  cout << "Number of scores used in average is: " << (scoreCounter - 1) << endl;
  cout << "The lowest dropped score was: " << minScore << endl;

  return 0;
}

// Gets a test score from interactive input (score must be between 0 and MAXSCORE).
// Returns the validated score
double getScore()
{
  double score;
  do
  {
    cout << "Enter a test score (must be " << MAXSCORE << ") or -1 to quit: ";
    cin >> score;
    if (score > MAXSCORE)
      cout << "Error, score too high, please renter" << endl;
  } while (score > MAXSCORE);

  return score;

}

// Given two double numbers, returns true if value1 < value2, otherwise returns false
bool isLower(double value1, double value2)
{
  return (value1 < value2);
}

double calcAverage(double total, int count, double lowest)
{
  double average;
  average = (total - lowest) / (count - 1);
  return average;
}