#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student{
  public:
    //default constructor
    Student();
    //overloaded constructor
    Student(int givenTime);
    //destructor
    ~Student();

    int time;
    int waitTime;

    // if student is at window or not / t-f
    bool atWindow();
    // returning wait time
    int getWaitTime();
    int getTime();
    // adding time to wait list
    void addingTimeToWaitList(int t);
    string toString();
    // friend ostream & operator<<(const ostream & os, Student & s);
};
#endif
