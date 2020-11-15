#include "Window.h"
#include <iostream>

using namespace std;

//default constructor
Window::Window(){
  time = 0;
  ot = 0;
}

//overloaded constructor
Window::Window(int t){
  time = t;
  occupied = false;
  current = false;

}

//destructor
Window::~Window(){
}

// window is occupied at the momement
void Window::occupiedCurrently(){
  current = true;
}
// window is not occupied at the momement
void Window::notOccupiedCurrently(){
  current = false;
}
// returning whether window is occupied or not
bool Window::getOccupiedCurrently(){
  return current;
}

//adding window wait time
void Window::addingWaitTime(int t){
  time = t;
}

//returning window wait time
int Window::getWaitTime(){
  return time;
}

//updating window to false = window is busy
void Window::updateAvailable(){
  occupied = false;
}

//if window is occupied or not / returning t or f
bool Window::isWindowOccupied(){
  return occupied;
}

//updating window to true = window is empty
void Window::updateOccupied(){
  occupied = true;
}

//adding to overall occupied time
void Window::addingOccupiedTime(int t){
  ot += t;
}

//returning occupied time
int Window::getOccupiedTime(){
  return ot;
}
