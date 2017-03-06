#ifndef SortableArray_H
#define SortableArray_H

using namespace std;

#include<algorithm>

template <class T>
class SortableArray
{
  private:
  int cap;
  T* values;
  T dummy;

  public:
  SortableArray(int = 2);
  T& operator[](int);
  T operator[](int) const;
  void capacity(int);
  int capacity() const { return cap; }
  void sort(int);
  //memory management
  SortableArray(const SortableArray<T>&);
  SortableArray<T>& operator=(const SortableArray<T>&);
  ~SortableArray() { delete[] values; }
};

template<class T>
SortableArray<T>::SortableArray(int init_cap)
{
  cap = init_cap;
  values = new T[cap];
}

template<class T>
T& SortableArray<T>::operator[](int index)
{
  if (index < 0) return dummy;

  if (index >= cap)
    capacity(2 * index);

  return values[index];
}

template<class T>
T SortableArray<T>::operator[](int index) const
{
  if (index < 0 || index >= this->cap) 
    return dummy;

  return values[index];
}

template<class T>
void SortableArray<T>::capacity(int newcap)
{
  T* temp = new T[newcap];

  int limit = min(newcap, this->cap); 

  for (int i = 0; i < limit; i++)
    temp[i] = values[i];

  delete[] values;
  values = temp;
  this->cap = newcap;
}

template <class T>
void SortableArray<T>::sort(int n)
{
  T* temp = new T[n];
  for (int pivot = 1; pivot < n; pivot *= 2)
  {
    int index = 0;
    for (int s = 0; s < n; s++)
      temp[s] = values[s];
    for (int s = 0; s < n; s += 2 * pivot)
    {
      int left = s;
      int MaxL = min(left + pivot, n);
      int right = MaxL;
      int MaxR = min(right + pivot, n);
      while (true)
      {
        if (left == MaxL && right == MaxR)
          break;
        if (left == MaxL)
          values[index++] = temp[right++];
        else if (right == MaxR)
          values[index++] = temp[left++];
        else if (temp[right] < temp[left])
          values[index++] = temp[right++];
        else values[index++] = temp[left++];
      }

    }
  }
  delete [] temp;
}

template<class T>
SortableArray<T>::SortableArray(const SortableArray<T>& original)
{
  cap = original.cap;
  values = new T[cap];

  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <class T>
SortableArray<T>& SortableArray<T>::operator=(const SortableArray<T>& original)
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

#endif 
