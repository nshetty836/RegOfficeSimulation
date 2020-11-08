#include <iostream>
using namespace std;

class Student{
  public:
    Student();
    Student(int time);
    ~Student();
    bool atWindow; // if student is at window or not
    int time;
    int waitTime; // return wait time
    int getTime(); // returns time
    int getWaitTime(); // return wait time
    void addingTimeToWaitList(int t); // adds to the waitlist
};
