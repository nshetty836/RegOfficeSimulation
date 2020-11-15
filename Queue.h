#include "DoublyLinkedList.h" // from your code
#include <iostream>
using namespace std;

template <class T>
class Queue{
  // default constructor
  Queue();
  // overloaded constructor
  Queue(int maxSize);
  // destructor
  ~Queue();

  DoublyLinkedList<T> *myQueue;

  int front;
  int rear;

  // size of queue
  int mSize;

  // number of elements
  int totalElements;

  void insert(T *d);
  // removing front element in queue
  T* remove();
  // checking if queue is empty
  bool isEmpty();
  // checking if queue is full
  bool isFull();
  // returning size of queue
  int getSize();
  // returns front element
  T* peek();
};

//default constructor
template<class T>
Queue<T>::Queue(){
  front = 0;
  rear = -1;
  totalElements = 0;
}

//overloaded constructor
template<class T>
Queue<T>::Queue(int maxSize){
  front = 0;
  rear = -1;
  totalElements = 0;
  myQueue = new DoublyLinkedList<T>();
}

//destructor
template<class T>
Queue<T>::~Queue(){
  delete [] myQueue; // ? does this work ?
}

//insert element to back of queue
template<class T>
void Queue<T>::insert(T *d){
  myQueue -> insertBack(d);
  totalElements++;
}

// removing front element from queue
template<class T>
T* Queue<T>::remove(){
  totalElements--;
  return myQueue -> removeFront();
}

//returns true or false - checking whether queue is empty
template<class T>
bool Queue<T>::isEmpty(){
  if(totalElements == 0){
    return true;
  }
  else {
    return false;
  }
}

//returns if true or false -  checking whether queue is full
template<class T>
bool Queue<T>::isFull(){
  return(totalElements == mSize);
}

//returning first element of queue
template<class T>
T* Queue<T>::peek(){
  return myQueue -> peek();
}


// getting size of queue
template<class T>
int Queue<T>::getSize(){
  return totalElements;
}
