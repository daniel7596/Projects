#include <iostream>
#include <cstdlib>

using namespace std;

#include "SearchableArray.h"

int main()
{
  char buf[100];
  int index, counter = 0;
  double value;
  SearchableArray<int>y, b;

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

    y[index] = value;
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
      cout << i << ", " << y[i] << endl;
  }

  //While loop prompting user which index to look up
  cout << "\nInput the amount of value to be included in sorting: ";
  cin >> buf;
  int Search = atoi(buf);
  cout << endl;

  cout << "The sorted values are: " << endl;
  y.sort(Search);

  for (int i = 0; i < b.capacity(); i++)
  {
    if (b[i])
      cout << i << ", " << y[i] << endl;
  }
  cout << endl;

  while (true)
  {

    cout << "Input the search value [Q to quit]: ";
    cin >> buf;

    if (buf[0] == 'q' || buf[0] == 'Q')
      break;

    value = atof(buf);

    if (y.bsearch(Search, value) < 0)
      cout << "The value " << value << " was not found." << endl;
    else
      cout << "The value " << value<< " was stored at index " << y.bsearch(Search, value) << "."<< endl;
  }

  cout << "Done!" << endl;
  return 0;
}
