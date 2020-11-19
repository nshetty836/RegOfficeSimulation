#include "Simulation.h"
using namespace std;

//default constructor
Simulation::Simulation(){
  numWindows = 0;
  windowTime = 0;

  arrivalTime = 0;

  students = 0;
  studentCount = 0;

  studentQueue = new Queue<Student>();
}

//destructor
Simulation::~Simulation(){}

//read through file and assign variables to lines
void Simulation::readFile(string file){
  FileProcessor *fp = new FileProcessor(file);

  //if file can be opened, read through
  if(fp->checkFile()){
    int numLines = fp->getNumOfLines();
    int lineType = 1;
    int line = 2;

    numWindows = stoi(fp->readLine(1));

    arrWindow[numWindows];
    for(int i = 0; i < numWindows; i++){
      arrWindow[i] = new Window(new Student());
    }

    //reading through the file to get necessary values for student
    while(line < numLines){
      switch (lineType)
      {
        //clock tick number in this line
        case (1):
        {
          try
          {
            //getting student arrival time
           	arrivalTime = stoi(fp->readLine(line));
            lineType++;
            line++;
          }
          catch (exception e)
          {
            cout << "\nError in text file.\n" << endl;
            exit(EXIT_FAILURE);
          }
          break;
        }
        // Number of students in this line
        case (2):
        {
          //getting number of students
       		students = stoi(fp->readLine(line));
          studentCount += students;
          for (int i = 0; i < students; ++i)
          {
            try
            {
              line++;
              windowTime = stoi(fp->readLine(line));
              if(line > numLines)
                break;
            }
            catch(exception e)
            {
                cout << "\nError in text file.\n" << endl;
                exit(EXIT_FAILURE);
            }
            Student* s = new Student(arrivalTime, windowTime);
            studentQueue->insert(s);
          }
          // making the next line type as clock tick
          line++;
          lineType = 1;
          break;
        }
      }
    }
  }
  else{
    cout << "\nError: text file can not be opened.\n" << endl;
    exit(EXIT_FAILURE);
  }
}

//changes the window and wait times of the students if applicable
void Simulation::updateTime(int time){
  for(int i = 0; i < numWindows; ++i){
    if(arrWindow[i]->isWindowOccupied() == true){
      arrWindow[i]->decreaseWindowTime();
    }
  }
  if(studentQueue->getSize() > 0){
    for(int i = 0; i < studentQueue->getSize(); i++){
      if(studentQueue->getValue(i)->entryTime < time){
        studentQueue->getValue(i)->waitTime++;
      }
    }
  }
}

//carry out entire simulation of registrar office
void Simulation::simulate(string file){
  bool run = true;
  int clockTick = 1;

  readFile(file);

  //while loop to go through each clock tick
  while(true){
    //if the queue is empty, check if students at windows are done
    if(studentQueue->isEmpty()){
      int numDone = 0;
      for(int i = 0; i < numWindows; i++){
        if(arrWindow[i]->getWindowTime() < 1){
          arrWindow[i]->notOccupied();
          numDone++;
        }
      }
      //if queue and windows are empty, exit loop
      if(numDone == numWindows){
        break;
      }
    }

    //checking windows and moving student to a window if empty
    for(int i = 0; i < numWindows; ++i){
      if(arrWindow[i]->getWindowTime() < 1){
        if(!studentQueue->isEmpty()){
          Student *stud = studentQueue->peek();
          if(stud->entryTime < clockTick){
            arrWindow[i]->student = studentQueue->remove();
            arrWindow[i]->makeOccupied();
            waitTimes.push_back(arrWindow[i]->getWaitTime());
          }
        }
        //if queue is empty, mark the window as not occupied
        else{
          arrWindow[i]->notOccupied();
        }
      }
    }

    //if the window is not occupied and window time is 0, increase idle time of window
    for(int i = 0; i < numWindows; i++){
      if(arrWindow[i]->isWindowOccupied() == false && arrWindow[i]->getWindowTime() == 0){
        arrWindow[i]->increaseIdleTime();
      }
    }

    updateTime(clockTick);
    clockTick++;
  }

  //calculate stats after simulation is over
  calculate();
}

// calculations
void Simulation::calculate(){
  float meanWait = 0, meanIdle = 0;
  int meanSize = 0, idleSize = 0, size = waitTimes.size();
  int median;

  //finding mean wait time value
  for(int i = 0; i < size; i++){
    if(waitTimes.at(i) != 0){
      meanSize++;
      meanWait += waitTimes.at(i);
    }
  }
  if(meanSize == 0)
    meanWait = 0;
  else
    meanWait = meanWait/meanSize;

  //finding median value by sorting vector
  sort(waitTimes.begin(), waitTimes.end());
  median = waitTimes[size / 2];

  //finding number of students with wait time over 10 minutes
  int tenMinStudent = 0;
  for(int i = 0; i < size; i++){
    if(waitTimes[i] > 10){
      tenMinStudent++;
    }
  }
  cout << "\nThe mean student wait time : " << fixed << setprecision(2) << meanWait << endl;
  cout << "The median student wait time : " << median << endl;
  cout << "The longest student wait time : " << waitTimes.back() << endl;
  cout << "The number of students waiting over 10 minutes : " << tenMinStudent << endl;

  // adding idle times to vector
  for(int i = 0; i < numWindows; i++){
    idleTimes.push_back(arrWindow[i]->getIdleTime());
  }

  //finding the mean idle time
  for(int i = 0; i < idleTimes.size(); i++){
    if(idleTimes.at(i) != 0){
      idleSize++;
      meanIdle += idleTimes.at(i);
    }
  }
  if(meanIdle == 0)
    meanIdle = 0;
  else
    meanIdle = meanIdle/idleSize;

    //finding num of windows with idle time
    int fiveMinIdle = 0;
    for(int i = 0; i < idleTimes.size(); i++){
      if(idleTimes[i] > 5){
        fiveMinIdle++;
      }
    }

    sort(idleTimes.begin(), idleTimes.end());

    cout << "The mean window idle time : " << fixed << setprecision(2) << meanIdle << endl;
    cout << "The longest window idle time : " << idleTimes.back() << endl;
    cout << "Number of windows idle for over 5 minutes : " << fiveMinIdle << "\n" << endl;
}
