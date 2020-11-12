#include "FileProcessor.h"

using namespace std;

//constructor
FileProcessor::FileProcessor(){}

//overloaded constructor-
FileProcessor::FileProcessor(string fname){
  fileName = fname;
}

//checks if file can be opened
bool FileProcessor::checkFile(){
  fileIn.open(fileName);
  if (fileIn.is_open() == false)
  {
    return false;
  }
  fileIn.close();
  return true;
}


//returning file as a string
string FileProcessor::readFile(){
  fileIn.open(fileName);
  string tempLine;

  while(fileIn.eof() == false){
    fileIn >> tempLine;
    fileText += tempLine;
  }
  fileIn.close();
  return fileText;
}

//returns the line in the file at the specified line num
string FileProcessor::readLine(int num){
  fileIn.open(fileName);
  string line;
  lineNum = 0;

  while(lineNum != num){
    getline(fileIn, line);
    lineNum++;
  }
  fileIn.close();
  return line;
}

//returns how many lines are in the file
int FileProcessor::getNumOfLines(){
  fileIn.open(fileName);
  string line;

  while(getline(fileIn, line)){
    numOfLines++;
  }
  fileIn.close();
  return numOfLines;
}
