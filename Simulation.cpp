#include "Simulation.h"
#include <iostream>
#include <fstream>
using namespace std;

//default constructor
Simulation::Simulation(){
  numWindows = 0;
  windowTime = 0;
  windowCount = 0;

  numStudents = -1;
  minimumWaitTime = 0;
  arrivalTime = 0;

  students = 0;
  studentCount = 0;

  myQueue = new Queue<Student>();
}

//destructor
Simulation::~Simulation(){
  delete myQueue;
}

void Simulation::simulation(string file){
  //student objects created
  int numStudentObjects = 1;
  // file variable first time
  int first = -1;
  //file first round
  int begin = 0;

  int count = 0;
  string line;

  //dummy student tester
  Student *studentTest = new Student();

  // occupied windows at a time
  int windowOcc[numWindows];
  //windowOcc counter
  int windowOccCount = -1;

  ifstream infile(file);
  while(getline(infile, line)){
    //number of windows from first line of file
    if(count == 0){
      //number of windows being assigned
      numWindows = stoi(line);
      arrWindow[numWindows];
      for(int i = 0; i < numWindows; i++){
        arrWindow[i] = new Window();
      }
      count++;
      continue;
    }

    //student arrival time
    if(count == 1){
      arrivalTime = stoi(line);
      count++;
      continue;
    }

    if(count == 2){
      students = stoi(line);
      studentCount += students;
      count++;
      continue;
    }

    if(count == 3){
      students = stoi(line);
      // new student object
      Student *s = new Student(windowTime);
      //student placed in queue
      myQueue->insert(s);
      if(numStudentObjects < students){
        numStudentObjects++;
        continue;
      }

      //after getting all student times
      else if(numStudentObjects == students){
        count = 4;
        numStudentObjects = 1;
      }
    }

    //student at windows
    if(count = 4){
      first++;
      if(first == 0){
        for(int i = 0; i < numWindows; i++){
          arrWindow[i]->addingWaitTime(arrivalTime);
        }
        begin = arrivalTime;
      }
      else{
        for(int i = 0; i < numWindows; i++){
          if(arrWindow[i]->isWindowOccupied() == false){
            arrWindow[i]->addingWaitTime(arrivalTime);
          }
        }
      }

      //assigning student to a window
      while(numStudentObjects <= students){
        if(myQueue->isEmpty()){
          // queue empty, break
          break;
        }
        //queue not empty
        else if(myQueue->isEmpty() == false){
          studentTest = myQueue->remove();
          numStudents++;
          numStudentObjects++;

          // windows are full
          if(windowCount == numWindows){
            int occupiedTimeOfWindow [numWindows];
            int windowTrack = 0;
            //occupied times - current time = minimum time
            for(int i = 0; i < numWindows; i++){
              if(first == 0){
                occupiedTimeOfWindow [i] = arrWindow[i]->getOccupiedTime();
              }
              else if(arrWindow[i]->getOccupiedCurrently() == true){
                occupiedTimeOfWindow [i] = (arrWindow[i]->getOccupiedTime() + arrivalTime) - begin;
              }
              else if(arrWindow[i]->getOccupiedCurrently() == false){
                occupiedTimeOfWindow [i] = (arrWindow[i]->getOccupiedTime() - arrivalTime) + begin;
              }
            }
            minimumWaitTime = occupiedTimeOfWindow [0];
            // minimum occupied time
            for(int i = 1; i < numWindows; i++){
              if(occupiedTimeOfWindow [i] < minimumWaitTime){
                minimumWaitTime = occupiedTimeOfWindow [i];
                windowTrack = i;
              }
            }

            if(minimumWaitTime < 0){
              minimumWaitTime = 0;
            }

            //adding time to wait list
            studentTest->addingTimeToWaitList(minimumWaitTime);
            //adding occupied time
            arrWindow[windowTrack]->addingOccupiedTime(studentTest->getTime());
            // window occupied
            arrWindow[windowTrack]->occupiedCurrently();

            //dummy student in array
            arrStudent[numStudents] = studentTest;
          }

          //loop for number of windows
          for(int i = 0; i < numWindows; i++){
            //window not occupied
            if(arrWindow[i]->isWindowOccupied() == false){
              arrWindow[i]->occupiedCurrently();
              windowOccCount++;

              //counting occupied windows
              windowOcc[windowOccCount] = i;

              //zero wait time if no students
              studentTest->addingTimeToWaitList(0);
              arrStudent[numStudents] = studentTest;

              //window occupied
              arrWindow[i]->updateOccupied();
              arrWindow[i]->addingOccupiedTime(studentTest->getTime());

              windowCount++;
              break;
            }

            // occupied time free if wait time is 0 or less
            if(arrWindow[i]->getOccupiedTime() - arrivalTime <= 0){
              arrWindow[i]->updateAvailable();
              windowCount--;
            }
          }

          if(numStudentObjects >= students){
            count = 5;
          }
        }
      }
    }
    //going back to count 1
    if(count == 5){
      count = 1;
      numStudentObjects = 1;
      windowOccCount = -1;
      for(int i = 0; i < numWindows; i++){
        if(arrWindow[i]->isWindowOccupied() == false){
          arrWindow[i]->addingWaitTime(arrivalTime);
        }
        arrWindow[i]->notOccupiedCurrently();
      }
      for(int i = 0; i < numWindows; i++){
        windowOcc[i] = -1;
      }
      continue;
    }
  }

// file error if the number of student objects isn't 1
  if(numStudentObjects != 1){
    cout << "File error - Please check the file " << endl;
    return;
  }
  calculate();
}

// calculations
void Simulation::calculate(){
  // student wait time mean
  float natural = 0;
  // mean counter
  float m = 0;
  for(int i = 0; i < studentCount; i++){
    natural += arrStudent[i]->getWaitTime();
    m++;
  }

  // 0/n
  if(natural == 0.0){
    natural = 0.0;
  }
  else
  {
    //mean is n - not zero
    natural  = natural/m;
  }
  cout << "The mean student wait time : " << natural << endl;
  // student wait time median
  float median = 0.0f;
  int med;
  // wait times in array in order
  int medianArr[studentCount];

  for(int i = 0 ; i < studentCount; i++){
    medianArr[i] = arrStudent[i]->getWaitTime();
  }
  // ordering array
  for(int i = 0; i < studentCount; i++ ){
    for(int j = i + 1; j < studentCount ; j++){
      if(medianArr[i] < medianArr[j]){
        median = medianArr[i];
        medianArr[i] = medianArr[j];
        medianArr[j] = median;
      }
    }
  }
  numStudents++;

// remainder
  med = numStudents%2;

//if remainder
  if(med == 1){
    med = (numStudents/2);
    cout << "The median for student wait time is: " << medianArr[med] << endl;
  }
  else{
    med = (numStudents/2);
    median = ((medianArr[med + 1] + medianArr[med]) /2);
    cout << "The median student wait time : " << median << endl;
  }
  cout << "The longest student wait time : " << medianArr[0] << endl;

  int tenMinStudent = 0;
  for(int i = 0 ; i < studentCount ; i++){
    if (medianArr[i] >= 10){
      tenMinStudent++;
    }
	}
  cout << "The number of students waiting over 10 minutes : " << tenMinStudent << endl;
  cout << endl;

  //window idle time mean
  int meanWindow[numWindows];
  float windowSum = 0.0;

  for(int i = 0; i < numWindows; i++){
    // getting wait time
    meanWindow[i] = arrWindow[i]->getWaitTime();
  }
  for(int i = 0; i < numWindows; i++){
    windowSum += meanWindow[i];
  }

  float windowMean = windowSum / numWindows;

  cout << "The mean window idle time : " << windowMean << endl;

  // dummy window counter test
  int windowTest = 0;

  for(int i = 0; i < numWindows; i++ ){
    for(int j = i + 1; j < numWindows; j++){
      if(meanWindow[i] < meanWindow[j]){
        windowTest = meanWindow[i];
        meanWindow[i] = meanWindow[j];
        meanWindow[j] = windowTest;
      }
    }
  }
  cout << "The longest window idle time : " << meanWindow[0] << endl;
  int fiveMinStudent = 0;
  for(int i = 0 ; i < numWindows; i++){
    if (meanWindow[i] >= 5){
      fiveMinStudent++;
    }
	}
  cout << "Number of windows idle for over 5 minutes : " << fiveMinStudent << endl;
  cout << endl;
}
