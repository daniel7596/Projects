#ifndef STATICARRAY_H
#define STATICARRAY_H

template<class V, int CAPACITY>
class StaticArray
{
  V values[CAPACITY];
  V dummy;

  public:
  int capacity() const{return CAPACITY;}
  V& operator[](int);
  V operator[](int) const;
};

template<class V, int CAPACITY>
V& StaticArray<V, CAPACITY>::operator[](int index)
{
  if(index < 0 || index >= CAPACITY)
    return dummy;

  return values[index];
}

template<class V, int CAPACITY>
V StaticArray<V, CAPACITY>::operator[](int index) const
{
  if(index < 0 || index >= CAPACITY)
    return dummy;

  return values[index];
}

#endif 