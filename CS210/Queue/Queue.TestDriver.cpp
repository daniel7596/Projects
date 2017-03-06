#include<iostream>
using namespace std;

#include <cassert>
#include <string>

#include "Queue.h"
#include "Queue.h" // testing ifndef

int main()
{
  Queue<int> x;

  cout << "\nTesting size function\n";
  cout << "EXPECTED: Stack size is 0" << endl;
  if (x.size() == 0)
    cout << "ACTUAL: Stack size is " << x.size() << endl;
  else
    cout << "ACTUAL: Stack size does not meet the expectation " << endl;
  assert(x.size() == 0);

  cout << "\nTesting push" << endl;
  //input value in stack
  for (int i = 0; i < 5; i++)
  {
    x.push(i);
  }
  cout << "Currently on Queue: 0 1 2 3 4 " << endl;

  cout << "\nTesting front function\n";
  cout << "EXPECTED: front function is 0" << endl;
  cout << "ACTUAL: front function is " << x.front() << endl;
  assert(x.front() == 0);

  cout << "\nTesting back function\n";
  cout << "EXPECTED: back function is 4" << endl;
  cout << "ACTUAL: back function is " << x.back() << endl;
  assert(x.back() == 4);

  cout << "\nTesting pop function\n";
  x.pop();
  cout << "EXPECTED: After pop, expected value in the front is 1" << endl;
  cout << "ACTUAL: pop function is " << x.front() << endl;
  assert(x.front() == 1);

  cout << "\n\nTesting copy assignment\n";
  const Queue<int> cops = x;

  for (Queue<int> copy = cops; !copy.empty(); copy.pop())
  {
    cout << copy.front() << " " ;
  }

  //reading assignment
  cout << "\n\nTesting copy assignment\n";
  Queue<int> cops1 = x;

  for (Queue<int> copy = cops1; !copy.empty(); copy.pop())
  {
    cout << copy.front() << " " ;
  }

  x.clear();
  cout << "\n\nTesting clear function\n";
  cout << "EXPECTED output is cleared" << endl;
  if (x.empty())
    cout << "The stack is cleared" << endl << endl;
  else
    cout << "The stack is not yet cleared" << endl << endl;
  assert(x.empty() == true);
  assert(x.size() == 0);

  
  Queue<string> test1;

  cout << "\nTesting size function\n";
  cout << "EXPECTED: Stack size is 0" << endl;
  if (test1.size() == 0)
    cout << "ACTUAL: Stack size is " << test1.size() << endl;
  else
    cout << "ACTUAL: Stack size does not meet the expectation " << endl;
  assert(test1.size() == 0);

  cout << "\nTesting push" << endl;
  //input value in stack

  test1.push("Hello");

  cout << "Currently on stack: Hello" << endl;

  cout << "\nTesting front function\n";
  cout << "EXPECTED: front function is Hello" << endl;
  cout << "ACTUAL: front function is " << test1.front() << endl;
  assert(string(test1.front()) == "Hello");

  cout << "\nTesting back function (should be the same with front function)\n";
  cout << "EXPECTED: back function is Hello" << endl;
  cout << "ACTUAL: back function is " << test1.back() << endl;
  assert(string(test1.back()) == "Hello");

  cout << "\nTesting copy assignment\n";
  const Queue<string> cop = test1;

  for (Queue<string> copy = cop; !copy.empty(); copy.pop())
  {
    cout << copy.front() << " " << endl;
  }

  //reading assignment
  cout << "\nTesting copy assignment\n";
  Queue<string> cop1 = test1;

  for (Queue<string> copy = cop1; !copy.empty(); copy.pop())
  {
    cout << copy.front() << " " << endl;
  }

  cout << "\nTesting pop function\n";
  test1.pop();
  cout << "EXPECTED: After pop, empty stack size=0" << endl;
  cout << "ACTUAL: after pop function size is " << test1.size() << endl;
  assert(test1.empty() == true);
  assert(test1.size() == 0);

  test1.clear();
  cout << "\nTesting clear function\n";
  cout << "EXPECTED output is cleared" << endl;
  cout << "ACTUAL: ";
  if (test1.empty())
    cout << "The stack is cleared" << endl << endl;
  else
    cout << "The stack is not yet cleared" << endl << endl;
  assert(test1.empty() == true);
  assert(test1.size() == 0);
  
}