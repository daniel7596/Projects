#include <iostream>
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h"  //ifndef test

int main()
{
  StaticArray<double,100> a;

  // testing Array::capacity
  cout << "\nTesting Array::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(100 == a.capacity());

  // testing the Array::operator[ ] setter
  a[1] = 12.33;
  a[2] = 45.6;
  cout << "\nTesting Array::operator[ ] setter"<< endl;
  cout << "EXPECTED: 12.33 for a[1]\n";
  cout << "ACTUAL: " << a[1] << endl;
  assert(12.33 == a[1]);
  cout << "EXPECTED: 45.6 for a[2]\n";
  cout << "ACTUAL: " << a[2] << endl;
  assert(45.6 == a[2]);
  a[-1000] = -999.99;
  cout << "EXPECTED: -999.99 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;

  // testing the Array::operator[ ] getter
  const StaticArray<double,100> b = a;
  cout << "\nTesting Array::operator[ ] getter\n";
  cout << "EXPECTED: 12.33 for b[1]\n";
  cout << "ACTUAL: " << b[1] << endl;
  assert(12.33 == b[1]);
  cout << "EXPECTED: 45.6 for b[2]\n";
  cout << "ACTUAL: " << b[2] << endl;
  assert(45.6 == b[2]);
  cout << "EXPECTED: -999.99 for b[-1000]\n";
  cout << "ACTUAL: " << b[-1000] << endl;

  // testing the upper, lower and out-of-range index
  assert(-999.99 == b[-6]);
  assert(-999.99 == b[-1000]);
  assert(-999.99 != b[99]);
  assert(-999.99 != b[0]);

  // const object copy test
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);

  // object assignment test
  StaticArray<double,100> c;
  c = a;
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == c[i]);

  return 0;
}
