#ifndef SearchableArray_H
#define SearchableArray_H

using namespace std;

#include<algorithm>

template <class T>
class SearchableArray
{
private:
  int cap;
  T* values;
  T dummy;

public:
  SearchableArray(int = 2);
  T& operator[](int);
  T operator[](int) const;
  void capacity(int);
  int capacity() const { return cap; }
  void sort(int);
  int bsearch(int, const T&) const;
  //memory management
  SearchableArray(const SearchableArray<T>&);
  SearchableArray<T>& operator=(const SearchableArray<T>&);
  ~SearchableArray() { delete[] values; }
};

template<class T>
SearchableArray<T>::SearchableArray(int init_cap)
{
  cap = init_cap;
  values = new T[cap];
}

template<class T>
T& SearchableArray<T>::operator[](int index)
{
  if (index < 0) return dummy;

  if (index >= cap)
    capacity(2 * index);

  return values[index];
}

template<class T>
T SearchableArray<T>::operator[](int index) const
{
  if (index < 0 || index >= this->cap)
    return dummy;

  return values[index];
}

template<class T>
void SearchableArray<T>::capacity(int newcap)
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
void SearchableArray<T>::sort(int n)
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
  delete[] temp;
}

template<class T>
int SearchableArray<T>::bsearch(int n, const T& matchThis) const
{
  int s = 0; // start of a range of the array to search
  int e = n; // end of a range of the array to search
  int m = 0; // the matching value's index
  int dummy = -999;
  while (m != n) // "n" means no match was found
  {
    m = (s + e - 1) / 2; // the middle element 
    if (matchThis == values[m]) break; // got lucky -- matches middle element 
    else if (s >= e - 1) m = n; // 1-element array and it did not match 
    else if (matchThis < values[m]) e = m; // look between s and m-1 
    else s = m + 1; // look between m+1 and e-1 
  }
  if (m != n)
    return m;
  else
    return dummy;
}

template<class T>
SearchableArray<T>::SearchableArray(const SearchableArray<T>& original)
{
  cap = original.cap;
  values = new T[cap];

  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <class T>
SearchableArray<T>& SearchableArray<T>::operator=(const SearchableArray<T>& original)
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
