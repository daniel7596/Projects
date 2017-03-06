#include <iostream> 
#include <string> 
using namespace std;

#include <cassert> 
#include <cmath> 
#include <cstdlib>
#include <ctime>

#include "PriorityQueue.h"

int main()
{
  srand(time(0)); rand(); // seed the random number generator (in case you need it)
  
  int n = 8000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int reps = n / 100; // one percent of starting n
  
  cout.setf(ios::fixed);
  cout.precision(4);
  double expectedSeconds = 0;
  double elapsedSecondsNorm = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // problem setup goes here -- create a data structure of size n
    PriorityQueue<int> test;
    
    for (int index = 0; index < n; index++) test.push(rand());
    
    // assert that n is the size of the data structure if applicable
    assert(test.size() == n); 
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int rep = 0; rep < reps; rep++)
    {
      test.push(rand());
    }
    clock_t endTime = clock();
    
    // validation block -- assure that process worked if applicable
    while (!test.empty())
    {
      int topNumber = test.top();
      test.pop();
      assert(topNumber >= test.top());
    }
    
    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0) elapsedSecondsNorm = elapsedSeconds;
    double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    
    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected)";
    else cout << " (expected " << elapsedSecondsNorm << " to " << expectedSecondsLog << ')';
    cout << " for n=" << n << endl;
  }
}