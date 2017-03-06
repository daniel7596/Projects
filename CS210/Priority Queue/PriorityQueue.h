#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <algorithm>
using namespace std;

template <typename V>
class PriorityQueue
{
  int siz;
  int cap;
  void capacity(int);
  V* values;
  
  public:
  PriorityQueue(int = 2);
  PriorityQueue(const PriorityQueue<V>&);
  PriorityQueue<V>& operator=(const PriorityQueue<V>&);
  ~PriorityQueue() {delete [] values;}
  void push(const V&);
  void pop();
  const V& top() const {return values[0];}
  int size() const {return siz;}
  bool empty() const;
  void clear() {siz = 0;}
};

template <typename V>
void PriorityQueue<V>::capacity(int cap)
{
  // allocate a new array with the new capacity
  V* temp = new V[cap];
  int limit = min(cap, this->cap);
  
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  
  delete [ ] values;

  values = temp;
 
  this->cap = cap;
}

template <typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
  siz = 0;
  this->cap = cap;
  values = new V[this->cap];
}

template <typename V>
bool PriorityQueue<V>::empty() const
{
  if (siz == 0)
    return true;
  else
    return false;
}

template <typename V>
void PriorityQueue<V>::pop()
{
  if (siz <= 0)
    return;
  
  //create an int index for traversing through the hierarchy, initialized to zero
  int index = 0;
  while (true)
  {
    //compute the left- and right-child indexes of the value at "index"
    int left = index*2+1;
    int right = index*2+2;

    if (left >= siz)
      break;
    
    if (right >= siz || values[right] < values[left])
    {
      values[index] = values[left];
      index = left;
    }
    //else (the right-child wins), copy its value to position "index", and set "index" to the right-child's index
    else
    {
      values[index] = values[right];
      index = right;
    }
  }
  siz--;
 
  //copy the value at index "siz" to position "index"
  values[index] = values[siz];
  while (true)
  {
    //compute the parent index of the value at "index"
    int parent = ((index+1)/2)-1;
    
    if (parent < 0 || values[index] < values[parent])
      break;
    
    V temp = values[index];
    values[index] = values[parent];
    values[parent] = temp;
    
    index = parent;
  }
}

template <typename V>
void PriorityQueue<V>::push(const V& a)
{
  //if the array is full, double its capacity
  if (siz == cap)
    capacity(2 * cap);
  
  //copy the new value to V* values; array at index "siz"
  values[siz] = a;
  
  //create an int index (for traversing up the hierarchy) and initialize it to siz
  int index = siz;
  
  while (true)
  {
    //compute the parent index of the value at "index"
    int parent = (index + 1) / 2 - 1;
    
    if (parent < 0 || values[index] < values[parent])
      break;
    
    V temp = values[index];
    values[index] = values[parent];
    values[parent] = temp;
      
    index = parent;
  }
  siz++;
}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
  if (this != &original) // if it's not a self copy...
  {
    // do what the destructor does
    delete [ ] values;
    
    // do what the copy constructor does
    cap = original.cap; // still just a copy
    siz = original.siz;
    values = new V[cap]; // not a copy -- new object gets its own array
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
      values[i] = original.values[i]; // ...to the copy
  }
  return *this; // return a self reference
}

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
  cap=original.cap; // still just a copy
  siz=original.siz;
  values=new V[cap]; //not a copy -- new object gets its own array
  for(int i=0; i< cap; i++)//copy the contents of the array from the original...
    values[i]=original.values[i]; // ...to the copy
}

#endif