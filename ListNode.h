#include <iostream>
#include <cstddef>

template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T* d);
    ~ListNode();
    T* data;
    ListNode<T> *next;
    ListNode<T> *prev;
};

template <class T>
ListNode<T>::ListNode(){
  data = 0;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T* d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  delete next;
  delete prev;
}
