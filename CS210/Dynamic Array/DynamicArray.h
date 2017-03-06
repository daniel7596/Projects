#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <vector> 
using namespace std;

#include<algorithm>

template <class T>
class DynamicArray
{
  private:
  int cap;
  T* values;
  T dummy;

  public:
  DynamicArray(int = 2);
  T& operator[](int);
  T operator[](int) const;
  void capacity(int);
  int capacity() const { return cap; }
  //memory management
  DynamicArray(const DynamicArray<T>&);
  DynamicArray<T>& operator=(const DynamicArray<T>&);
  ~DynamicArray() { delete[] values; }
};

template<class T>
DynamicArray<T>::DynamicArray(int init_cap)
{
  cap = init_cap;
  values = new T[cap];
}

template<class T>
T& DynamicArray<T>::operator[](int index)
{
  if (index < 0) return dummy;

  if (index >= cap)
    capacity(2 * index);

  return values[index];
}

template<class T>
T DynamicArray<T>::operator[](int index) const
{
  if (index < 0 || index >= this->cap) 
    return dummy;

  return values[index];
}

template<class T>
void DynamicArray<T>::capacity(int newcap)
{
  T* temp = new T[newcap];

  int limit = min(newcap, this->cap); 

  for (int i = 0; i < limit; i++)
    temp[i] = values[i];

  delete[] values;
  values = temp;
  this->cap = newcap;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
  cap = original.cap;
  values = new T[cap];

  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
  if (this != &original) 
  {
    delete[] values;

    cap = original.cap;
    values = new T[cap]; 
    for (int i = 0; i < cap; i++) 
      values[i] = original.values[i]; 
  }

  return *this;
}

#endif // DYNAMICARRAY_H
