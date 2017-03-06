#include <iostream>
using namespace std;

#include <cassert>
#include <string>

#include "DynamicArray.h"
#include "DynamicArray.h"  //ifndef test

int main()
{
  DynamicArray<int> a;

  // testing Array::capacity
  cout << "\nTesting Array::capacity\n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(2 == a.capacity());

  // testing the Array::operator[ ] setter
  a[1] = 123;
  a[20] = 456;
  cout << "\nTesting Array::operator[ ] setter" << endl;
  cout << "EXPECTED: 123 for a[1]\n";
  cout << "ACTUAL: " << a[1] << endl;
  assert(123 == a[1]);
  cout << "EXPECTED: 456 for a[20]\n";
  cout << "ACTUAL: " << a[20] << endl;
  assert(456 == a[20]);
  a[-100] = -999;
  cout << "EXPECTED: -999 for a[-100]\n";
  cout << "ACTUAL: " << a[-100] << endl;

  // testing Array::capacity
  cout << "\nTesting Array::capacity again\n";
  cout << "EXPECTED: 40\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(40 == a.capacity());

  // testing the Array::operator[ ] getter
  const DynamicArray<int> b = a;
  cout << "\nTesting Array::operator[ ] getter\n";
  cout << "EXPECTED: 123 for b[1]\n";
  cout << "ACTUAL: " << b[1] << endl;
  assert(123 == b[1]);
  cout << "EXPECTED: 456 for b[20]\n";
  cout << "ACTUAL: " << b[20] << endl;
  assert(456 == b[20]);

  // const object copy test
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == b[i]);

  //testing to decrease the dynamic's array capacity
  cout << "\nTesting Array::capacity a.capacity\n";
  cout << "EXPECTED: 40\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(40 == a.capacity());
  a.capacity(10);
  cout << "\nTesting Array::capacity a.capacity again, after decreasing it to 10\n";
  cout << "EXPECTED: 10\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(10 == a.capacity());

  // object assignment test
  DynamicArray<int> c;
  c = a;
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < c.capacity(); i++)
    assert(a[i] == c[i]);

  //testing with string data type
  DynamicArray<string> d(100);

  // testing Array::capacity
  cout << "\nTesting Array::capacity using the main constructor to initialize array capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << d.capacity() << endl;
  assert(100 == d.capacity());

  // testing the Array::operator[ ] setter
  d[1] = "hello";
  d[20] = "comsc";
  cout << "\nTesting Array::operator[ ] setter" << endl;
  cout << "EXPECTED: hello for d[1]\n";
  cout << "ACTUAL: " << d[1] << endl;
  assert(string("hello") == d[1]);
  cout << "EXPECTED: comsc for d[20]\n";
  cout << "ACTUAL: " << d[20] << endl;
  assert(string("comsc") == d[20]);
  d[-100] = "error";
  cout << "EXPECTED: error for d[-100]\n";
  cout << "ACTUAL: " << d[-100] << endl;

  return 0;
}
