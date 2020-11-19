#include "Window.h"
#include <iostream>

using namespace std;

//default constructor
Window::Window(){}

//overloaded constructor
Window::Window(Student *s){
  occupied = false;
  student = s;
  idleTime = 0;
}

//destructor
Window::~Window(){}

//returning window idle time
int Window::getIdleTime(){
  return idleTime;
}

void Window::increaseIdleTime(){
  idleTime++;
}

int Window::getWindowTime(){
  return student->windowTime;
}

int Window::getWaitTime(){
  return student->waitTime;
}

void Window::decreaseWindowTime(){
  student->windowTime -= 1;
}

//updating window to false = window is busy
void Window::notOccupied(){
  occupied = false;
}

//if window is occupied or not / returning t or f
bool Window::isWindowOccupied(){
  return occupied;
}

//updating window to true = window is empty
void Window::makeOccupied(){
  occupied = true;
}
