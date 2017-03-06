#include<iostream>

using namespace std;

#include "Stack.h"

int main()
{
  Stack<double> m;
  char buf[100];

  while (true)
  {
    cout << "Enter: ";
    for (Stack<double> copy = m; !copy.empty(); copy.pop())
    {
	cout << copy.peek() << " ";
    }
    cin >> buf;
						
    // addition
    if (buf[0] == '+' && m.size() >= 2)
    {
       double a, b, c;
       a = m.peek();
       m.pop();
       b = m.peek();
       m.pop();
       c = b + a;
       m.push(c);
    }

    // multiplication
    else if (buf[0] == '*' && m.size() >= 2)
    {
       double a, b, c;
       a = m.peek();
       m.pop();
       b = m.peek();
       m.pop();
       c = b * a;
       m.push(c);
    }

    // subtraction
    else if (buf[0] == '-' && m.size() >= 2)
    {
       double a, b, c;
       a = m.peek();
       m.pop();
       b = m.peek();
       m.pop();
       c = b - a;
       m.push(c);
    }

    // division
    else if (buf[0] == '/' && m.size() >= 2)
    {
       double a, b, c;
       a = m.peek();
       m.pop();
       b = m.peek();
       m.pop();
       c = b / a;
       m.push(c);
    }

    //quit the program using q button
    else if (buf[0] == 'q' || buf[0] == 'Q') break;
					
    else
    {
       double a = atof(buf);
       m.push(a);
    }
  }
}