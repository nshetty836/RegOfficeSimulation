#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor
Student::Student(){
  waitTime = 0;
  entryTime = 0;
  windowTime = 0;
}

// overloaded constructor
Student::Student(int t, int w){
  waitTime = 0;
  entryTime = t;
  windowTime = w;
}

// destructor
Student::~Student(){}

string Student::toString(){
  string temp = "Entry Time: " + to_string(entryTime) + " Window Time: " + to_string(windowTime);
  return temp;
}
