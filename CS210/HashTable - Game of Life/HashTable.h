#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <list>
#include <queue>

template <typename K, typename V, int CAP>
class HashTable
{
  struct Node
  {
    K key; 
    V value;
  };
  int(*hashCode)(const K&); // alias for hash code function
  list<Node> data[CAP];
  int siz;

public:
  HashTable(int(*)(const K &)=0);
  V operator[](const K&) const;
  V& operator[](const K&);
  bool containsKey(const K&)const;
  void deleteKey(const K&);
  queue<K> keys() const;
  int size() const { return siz; }
  void clear();
  double loadFactor() const { return 1.0 * siz / CAP; }
};


template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*x)(const K&key))
{
  siz = 0;
  hashCode = x;
}

template <typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K &key) const
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it; // getters need to use const_iterator
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;
  if (it == data[index].end()) // not found
    return false;
  else // found
    return true;
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K &key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;

  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
     break;

  if (it == data[index].end()) // not found
    return;
  else // found
  {
    it->value; // is the value
    data[index].erase(it);
    siz--;
  }
  
  return;
}

template <typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[](const K &key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it; // getters need to use const_iterator
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;

  if (it == data[index].end()) // not found
  {
    Node n; n.key = key; n.value = V();
    data[index].push_back(n);
    siz++;
    return data[index].back().value;
  }
  else // found
    return it->value;
}
  
template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[](const K &key) const
{
  V dummy;
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;

  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
   if (it->key == key)
    return it->value;

  return dummy;
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
  for (int i = 0; i < CAP; i++)
    data[i].clear();
  siz = 0;
}

template <typename K, typename V, int CAP>
queue<K> HashTable<K, V, CAP>::keys() const
{
  typename list<Node>::const_iterator it; // getters need to use const_iterator
  queue<K> q;
  for (int index = 0; index < CAP; index++)
    for (it = data[index].begin(); it != data[index].end(); it++)
      q.push(it->key);
  return q;
}

#endif
