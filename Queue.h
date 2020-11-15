#include "DoublyLinkedList.h" // from your code
#include <iostream>
#include <cstddef>
using namespace std;

template <class T>
class Queue{
public:
  // default constructor
  Queue();
  // overloaded constructor
  Queue(int maxSize);
  // destructor
  ~Queue();

<<<<<<< Updated upstream
  DoublyLinkedList<T> *myQueue;
=======
  void insert(T data);
  // removing front element in queue
  void remove();
  // checking if queue is empty
  bool isEmpty();
  // checking if queue is full
  T getSize();
  // returns front element
  T peek();
  //prints Queue
  void print();

private:
  DoublyLinkedList<T> myQueue;
>>>>>>> Stashed changes

  int front;
  int rear;

  // size of queue
  int mSize;

  // number of elements
  int totalElements;

<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
  delete [] myQueue; // ? does this work ?
=======
  // delete myQueue; // ? does this work ?
>>>>>>> Stashed changes
}

//insert element to back of queue
template<class T>
<<<<<<< Updated upstream
void Queue<T>::insert(T *d){
  myQueue -> insertBack(d);
=======
void Queue<T>::insert(T data){
  myQueue.insertBack(data);
>>>>>>> Stashed changes
  totalElements++;
}

// removing front element from queue
template<class T>
T* Queue<T>::remove(){
  totalElements--;
  return myQueue.removeFront();
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


//returning first element of queue
template<class T>
<<<<<<< Updated upstream
T* Queue<T>::peek(){
  return myQueue -> peek();
=======
T Queue<T>::peek(){
  return myQueue.getFront();
>>>>>>> Stashed changes
}

template<class T>
void Queue<T>::print(){
  myQueue.printList();
}

// getting size of queue
template<class T>
int Queue<T>::getSize(){
  return totalElements;
}
