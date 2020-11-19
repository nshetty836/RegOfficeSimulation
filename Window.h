#include <iostream>
#include "Student.h"
using namespace std;

//window class to represent one registrar window
class Window{
  public:
    Window();
    Window(Student *s);
    ~Window();

    int getIdleTime();
    void notOccupied();
    void makeOccupied();
    bool isWindowOccupied();
    int getWaitTime();
    void increaseIdleTime();
    int getWindowTime();
    void decreaseWindowTime();

    Student *student;
    int idleTime;

  private:
    bool occupied;

};
