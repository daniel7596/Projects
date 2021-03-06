#include <iostream>
#include <cstdlib>
using namespace std;

#include "DynamicArray.h"

int main()
{
  char buf[100];
  int index, x, counter = 0;
  double value;
  DynamicArray<double> a, b;

  for (int i = 0; i < b.capacity(); i++)
    b[i] = false;

  //While loop that ask user to input an index and value that will be stored 
  while (true)
  {
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf;

    if (buf[0] == 'q' || buf[0] == 'Q')
      break;

    index = atoi(buf);

    cin >> buf;
    value = atof(buf);

    a[index] = value;
    if (b.capacity() <= index)
    {
      int temp = b.capacity();
      b.capacity(2 * index);
      for (int i = temp; i < b.capacity(); i++)
        b[i] = false;
    }
    b[index] = true;
  }

  for (int i = 0; i < b.capacity(); i++)
  {
    if (b[i])
      counter++;
  }

  cout << "\nYou stored this many value: " << counter;
  cout << "\nThe values are:\n";

  for (int i = 0; i < b.capacity(); i++)
  {
    if (b[i])
      cout << i << " " << a[i] << endl;
  }

  //While loop prompting user which index to look up
  while (true)
  {
    cout << "\nInput an index to look up [Q to quit]: ";
    cin >> buf;
    x = atoi(buf);

    if (buf[0] == 'q' || buf[0] == 'Q')
      break;

    if (x < 0 || x >= b.capacity())
    {
      cout << "I didn't find it" << endl;
      continue;
    }

    if (b[x])
      cout << "Found it -- the value stored at " << x << " is " << a[x] << endl;
    else
      cout << "I didn't find it" << endl;
  }
  return 0;
}
