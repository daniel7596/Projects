#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#include "PriorityQueue.h"
#include "PriorityQueue.h"

int main()
{
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  int n = 8000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int REPS = n / 100;
  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    PriorityQueue<int> x;

    for (int i = 0; i < n; i++)
      x.push(i);

    clock_t startTime = clock();
    for (int rep = 0; rep < REPS; rep++)
      x.push(n + rep);
    clock_t endTime = clock();

    
    // validation block -- assure that process worked
    for (int i = 0; i < x.size(); i++)
    {
      int test1 = x.top();
      x.pop();
      assert(x.top() <= test1);
    }

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(1)")
      expectedSeconds = elapsedSecondsNorm;
    else if (bigOh == "O(log n)")
      expectedSeconds = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0)
      cout << " (expected " << bigOh << ')';
    else
      cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
}
