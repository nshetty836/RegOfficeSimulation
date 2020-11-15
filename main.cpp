#include "Simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){

  if(argc == 1){
   cout << "Enter the file name after ./a.out" << endl;
   return 0;
  }

  Simulation* s = new Simulation();
  s->simulation(file);

}
