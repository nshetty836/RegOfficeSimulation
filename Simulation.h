#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
using namespace std;

class Simulation{
  public:
    //default constructor
    Simulation();
    //destructor
    ~Simulation();

    //calculations for mean etc
    void calculate();
    // for main 
    void simulation(string file);


  private:
    int students;
    // counter for window

    int windowCount;
    // number of windows
    int numWindows;

    // number of students
    int numStudents;
    // counter for student
    int studentCount;

    // student arrival time
    int arrivalTime;
    // how long student spends at window
    int windowTime;
    // minimum wait time for window
    int minimumWaitTime;

    Student *arrStudent[100]; // array of wait times
    Window *arrWindow[100]; // array of wait times

    Queue<Student> *myQueue;
};
