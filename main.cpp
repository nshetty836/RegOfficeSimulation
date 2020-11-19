// #include "Queue.h"
// #include "Student.h"
#include "Simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  //checking if there at least 2 arguments in command line to get file name
  if(argc >= 2)
  {
    Simulation s;
    s.simulate(argv[1]);
  }
  else
    cout << "\nError: Please give a text file name in the command line.\n" << endl;

  return 0;
}
