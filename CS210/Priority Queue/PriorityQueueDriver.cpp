#include <cassert>
#include <iostream>

using namespace std;

#include "PriorityQueue.h"

int main()
{
  PriorityQueue<int> x;

  cout << "Enqueue function" << endl;
  cout << "Inserting 2 10 and 11 in the list" << endl;
  x.push(2);
  x.push(13);
  x.push(11);

  cout << "\nSize function" << endl;
  cout << "Expectation: size is 3"<<endl;
  if(x.size()==3)
  cout << "Result: size is " << x.size()<< endl;
  else
  cout << "Result: Size is not 3"<<endl;
  assert(x.size() == 3);

  cout << "\nFront function" << endl;
  cout << "Expectation: front function is 13 " << endl;
  if(x.top()==13)
  cout << "Result: Front function is " << x.top() << endl;
  else
  cout << "Result: Front function is not 13"<<endl;
  assert(x.top() == 13);

  cout << "\nDequeue function" << endl;
  x.pop();
  cout << "Expectation: The top is now 11\n";
  if(x.top()==11)
  cout << "Result: The top is " << x.top()<< endl;
  else
  cout << "Result: Top is now not 11"<<endl;
  assert(x.top() == 11);

  cout << "\nEmpty function" << endl;
  cout << "Expectation: List should be empty or returning false"<<endl;
  if(x.empty()==false)
  cout << "Result: List is " << x.empty() << endl;
  else
  cout << "Result list is not empty"<<endl;
  assert(x.empty() == false);

  

  cout << "\nClear function"<< endl;
  x.clear();
  cout << "Expectation: List should be cleared or 0"<<endl;
  if(x.size()==0)
  cout << "Result: List is " << x.size() << endl;
  else
  cout << "Result: List is not yet cleared"<<endl;
  assert(x.size() == 0);
}
