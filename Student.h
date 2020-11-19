#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

//class object of a student that has entry, wait, and window times
class Student{
  public:
    //default constructor
    Student();
    //overloaded constructor
    Student(int t, int w);
    //destructor
    ~Student();

    int entryTime;
    int waitTime;
    int windowTime;

    string toString();
};
#endif
