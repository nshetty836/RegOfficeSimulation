using namespace std;
#include <iostream>
#include <cstddef>

template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    T data;
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
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  delete next;
  delete prev;
}

template <class T>
class DoublyLinkedList{
//single linked List
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertFront(T d);
    void insertBack(T d);
    void removeFront(); // made this void, maybe fix it if you want to return value
    T removeBack();
    T deletePos(T pos);
    T removeNode(T key);
    void printList();
    T find(T value);

  private:
    ListNode<T> *front;
    ListNode<T> *back;
    T size;

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //RESEARCH in ZYBOOKS
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0){
    //empty List
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(front == NULL){
    //empty List
    front = back;
  }
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::removeFront(){
  ListNode<T>* curr = front;
  if(back == NULL)
    return;
  if(front->next == NULL){
    back = NULL;
  }
  else{
    front->next->prev = NULL;
  }
  front = front->next;
  curr->next = NULL;
  // T temp = curr->data;

  --size;
  delete curr;
}

//CHECK THIS MIGHT BE WRONG
template <class T>
T DoublyLinkedList<T>::removeBack(){
  // ListNode *curr = back->prev;
  // ListNode *nodeToDelete = back;
  //
  // int temp = back->data;
  //
  // if(front->next == NULL){
  //   back = NULL;
  //   front = NULL;
  // }
  // else{
  //   curr->next = NULL;
  // }
  // back = curr;
  // nodeToDelete->prev = NULL;
  // delete nodeToDelete;
  // --size;
  //
  // return temp;
  T temp = back->data;
  if(back != NULL){

  	ListNode<T> curr = back;

  	if(back->prev == NULL)
      back = NULL;
  	else
      back->prev->next = NULL;

  	back = back->prev;
  	curr->prev = NULL;

    size--;

  	delete curr;
  }
  return temp;
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr -> data << endl; //printing out data in current pointer
    curr = curr -> next;
  }
}

//PRINTFROMBACK()
//if you wanna print from the back, curr would be back and curr = curr->prev

template <class T>
T DoublyLinkedList<T>::find(T value){
  T pos = -1;
  ListNode<T> *curr = front;

  while(curr != NULL){
    //iterate until we reach the end and hopefully we find what we're looking for
    ++pos;
    if(curr->data == value){ //if value is found break the loop
      break;
    }
    curr = curr -> next;  //checking next pointer
  }

  if(curr == NULL)   //value not found, reset pos to -1
    pos = -1;

  return pos;

}

//removing node at a given position
template <class T>
T DoublyLinkedList<T>::deletePos(T pos){
  T p = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  //iterate to the correct position
  while(p != pos){
    prev = curr;
    curr = curr->next;
    p++;
  }
  //we found the position and our pointers are in their respective positions

  prev->next = curr ->next;
  curr->next = NULL;

  T temp = curr->data;
  size--;

  delete curr;
  return temp;
}

//searching for node by value and then removing it
template <class T>
T DoublyLinkedList<T>::removeNode(T key){
  ListNode<T> *curr = front;

  //check if empty before proceeding **importanT*
  if(size == 0){
    return -1;
  }
  //if not empty, you can leverage find() to determing if value exists

  while(curr->data != key){
    //iterate until we reach the end and hopefully we find what we're looking for
    curr = curr->next;

    if(curr == NULL){ //i reached the end of the list and value does not exist
      return -1;  //exits the function
    }
  }

  //if i make it here i found the node that needs to be deleted

  //3 cases: front, back, or between
  if(curr == front ){
    front = curr -> next;
    front->prev = NULL;
  }
  else if(curr == back){
    back = curr->prev;
    back->next = NULL;

  }
  else{ //between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;

  T temp = curr->data;
  size--;
  delete curr;

  return temp;

}
