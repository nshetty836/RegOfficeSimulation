#include "Student.h"
#include <iostream>
using namespace std;


// default constructor
Student::Student(){
  waitTime = 0;
  time = 0;
}

// overloaded constructor
Student::Student(int t){
  waitTime = 0;
  t = time;
}

// destructor
Student::~Student(){
}

bool Student::atWindow(){
  return false;
}

int Student::getTime(){
  return time;
}

int Student::getWaitTime(){
  return waitTime;
}

void Student::addingTimeToWaitList(int t){
  waitTime += t;
}
