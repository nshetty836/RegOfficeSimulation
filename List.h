#include <iostream>
#include <cstddef>
using namespace std;

template <class T>
class List{

  virtual void insertFront(T* d) = 0;
  virtual void insertBack(T* d) = 0;
  virtual T* removeFront() = 0; // made this void, maybe fix it if you want to return value
  virtual T* removeBack() = 0;
  virtual T* deletePos(int pos) = 0;
  virtual T* removeNode(T* key) = 0;
  virtual T* getFront() = 0;
  virtual T* getBack() = 0;
  virtual void printList() = 0;
  virtual int find(T* value) = 0;
};
