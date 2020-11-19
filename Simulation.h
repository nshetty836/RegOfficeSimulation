#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include "FileProcessor.h"
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Simulation{
  public:
    //default constructor
    Simulation();
    //destructor
    ~Simulation();

    void calculate();
    void readFile(string file);
    void simulate(string file);
    void updateTime(int time);

    Queue<Student> *studentQueue;
    vector<int> waitTimes;
    vector<int> idleTimes;

  private:
    int students;
    // number of windows
    int numWindows;
    // counter for student
    int studentCount;
    // student arrival time
    int arrivalTime;
    // how long student spends at window
    int windowTime;

    Window *arrWindow[100]; // array of wait times

};
