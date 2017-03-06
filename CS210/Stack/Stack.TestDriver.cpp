#include<iostream>
using namespace std;

#include <cassert>
#include <string>

#include "Stack.h"
#include "Stack.h" // testing ifndef

int main()
{
	Stack<int> x;
		
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
	cout << "Currently on stack: 4 3 2 1 0 " << endl;
	
	cout << "\nTesting peek function\n";
	cout << "EXPECTED: peek function is 4" << endl;
	cout << "ACTUAL: peek function is " << x.peek() << endl;
	assert(x.peek() == 4);

	cout << "\nTesting pop function\n";
	x.pop();
	cout << "EXPECTED: After pop, expected value is is 3" << endl;
	cout << "ACTUAL: pop function is " << x.peek() << endl;
	assert(x.peek() == 3);

	cout << "\nTesting copy assignment\n";
	const Stack<int> cops = x;

	for (Stack<int> copy = cops; !copy.empty(); copy.pop())
	{
		cout << copy.peek() << " " << endl;
	}

	//reading assignment
	cout << "\nTesting copy assignment\n";
	Stack<int> cops1 = x;
	
	for (Stack<int> copy = cops1; !copy.empty(); copy.pop())
	{
		cout << copy.peek() << " " << endl;
	}

	x.clear();
	cout << "\nTesting clear function\n";
	cout << "EXPECTED output is cleared" << endl;
	if (x.empty())
		cout << "The stack is cleared" << endl << endl;
	else
		cout << "The stack is not yet cleared" << endl << endl;
	assert(x.empty() == true);
	assert(x.size() == 0);


  Stack<string> test1;

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
  
  cout << "Currently on stack: Hello " << endl;

  cout << "\nTesting peek function\n";
  cout << "EXPECTED: peek function is 4" << endl;
  cout << "ACTUAL: peek function is " << test1.peek() << endl;
  assert(string(test1.peek()) == "Hello");


  cout << "\nTesting copy assignment\n";
  const Stack<string> cop = test1;

  for (Stack<string> copy = cop; !copy.empty(); copy.pop())
  {
    cout << copy.peek() << " " << endl;
  }

  //reading assignment
  cout << "\nTesting copy assignment\n";
  Stack<string> cop1 = test1;

  for (Stack<string> copy = cop1; !copy.empty(); copy.pop())
  {
    cout << copy.peek() << " " << endl;
  }

  cout << "\nTesting pop function\n";
  test1.pop();
  cout << "EXPECTED: After pop, empty stack size=0" << endl;
  cout << "ACTUAL: after pop function size is " << test1.size() << endl;
  assert(x.empty() == true);
  assert(x.size() == 0);

  test1.clear();
  cout << "\nTesting clear function\n";
  cout << "EXPECTED output is cleared" << endl;
  if (x.empty())
    cout << "The stack is cleared" << endl << endl;
  else
    cout << "The stack is not yet cleared" << endl << endl;
  assert(x.empty() == true);
  assert(x.size() == 0);
}