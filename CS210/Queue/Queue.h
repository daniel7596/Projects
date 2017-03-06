#ifndef Queue_h
#define Queue_h
using namespace std;

template <typename V>
class Queue
{
  struct Node
  {
    V value;
    Node* next;
  };

  Node* firstNode; // the head pointer 
  Node* lastNode; // private data member
  int siz; // tracking the number of nodes
  V dummy;

public:
  Queue(); // may have a defaulted parameter
  void push(const V&);
  V& front(); // return a mutable reference to the oldest node
  V& back(); // return a mutable reference to the newest node
  void pop(); // remove the oldest node
  int size() const { return siz; }
  bool empty() const { return 0 == siz; }
  void clear();
  //memory management
  Queue<V>& operator=(const Queue<V>&);
  Queue(const Queue<V>&);
  ~Queue();
};

template <typename V>
Queue<V>::~Queue()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

template <typename V>
Queue<V>::Queue()
{
  firstNode = 0;
  lastNode = 0; // whenever the list is empty
  siz = 0;
}

template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  firstNode = 0;
  lastNode = 0; // tail
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }

    // build new queue
    Node* lastNode = 0; // temporary tail
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

template <typename V>
void Queue<V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
  lastNode = 0; // whenever the list is empty
}

template <typename V>
void Queue<V>::push(const V& value)
{
  Node* temp = new Node;
  temp->value = value;
  temp->next = 0;
  if (lastNode) lastNode->next = temp;
  else firstNode = temp;
  lastNode = temp;
  ++siz;
}

template <typename V>
void Queue<V>::pop()
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
  if(siz==0)
    lastNode = 0;
}

template<class V>
V& Queue<V>::front()
{
  if (firstNode == 0) return dummy;
  return firstNode->value;
}

template<class V>
V& Queue<V>::back()
{
  if (lastNode == 0) return dummy;
  return lastNode->value;
}


#endif //Queue_h