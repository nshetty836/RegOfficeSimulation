#include <iostream>
using namespace std;

class Window{
  public:
    Window();
    Window(int t);
    ~Window();

    // updating avaliable window
    void updateAvailable();

    // occupied at the moment
    void occupiedCurrently();
    // not occupied at the moment
    void notOccupiedCurrently();
    // returning whether window is occupied or not t-f
    bool getOccupiedCurrently();

    // checking if window is occupied - return t or f
    bool isWindowOccupied();
    // updating occupied window
    void updateOccupied();

    // adding wait time
    void addingWaitTime(int t);
    // returning wait time
    int getWaitTime();

    // adding to occupied time
    void addingOccupiedTime(int t);
    // returning occupied time
    int getOccupiedTime();

  private:
    // occupied time 
    int ot;
    bool current;
    bool occupied;
    int time;

};
