//
//  Metro.h
//  Project 3 - Linked Lists
//
#ifndef METRO_H //Header Guards
#define METRO_H //Header Guards

//Required classes
#include "Line.h"
#include "Passenger.h"

//Required libraries (do not add libraries)
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

//Constants
const double PER_STOP = 1.25; //Cost per passenger per stop
const int NUM_LINES = 6; //Number of lines in DC Metro System

//This class manages the entire metro including the lines and passengers
class Metro {
 public:
  // Name: Metro (default constructor)
  // Desc: Populates m_fileLine and m_filePass with default values
  //       Calls LoadLines, LoadPassengers, and then MainMenu
  // Preconditions: None
  // Postconditions: A new metro system is created.
  Metro();
  // Name: Metro (overloaded constructor)
  // Desc: Populates m_fileLine and m_filePass.
  //       Calls LoadLines, LoadPassengers, and then MainMenu
  // Preconditions: Filename is included
  // Postconditions: A new metro system is created with lines and
  //                 passengers using passed input files
  Metro(string fileLine, string filePass);
  // Name:  Metro (destructor)
  // Preconditions: None
  // Postconditions: All lines (linked lists) are destroyed.
  //                 All vectors are cleared out.
  ~Metro();
  // Name:  LoadLines
  // Desc: Populates a vector of dynamically allocated
  //       Lines (Lines are linked lists) for input file of metro lines
  // Preconditions: Valid file name of lines
  // Postconditions: Loads all lines in input file (can be many)
  void LoadLines();
  // Name:  LoadPasses
  // Desc: Populates vector of dynamically allocated passengers
  //       from input file
  // Preconditions: Valid file name of lines
  // Postconditions: Loads all passengers in input file to m_passengers
  void LoadPasses();
  // Name: LineToIndex
  // Desc: Returns the index of the line based on the name
  //       For example, if the red line is in m_lines index 0, returns 0
  // Preconditions: m_lines must be populated
  // Postconditions: Returns the index of the line based on the name
  int LineToIndex(string name);
  // Name: MainMenu
  // Desc: Asks user to Display Lines, Display Passengers per Line,
  //       Calculate Earnings by Line, or exit.
  // Preconditions: None
  // Postconditions: When exit, quits program with no memory leaks or errors
  void MainMenu();
  // Name:  DisplayLines
  // Desc: Iterates over the vector and calls the
  //       PrintLineDetails for each line
  // Preconditions: At least one line in m_lines;
  // Postconditions: Displays details of each line in m_lines
  void DisplayLines();
  // Name:  DisplayPassengers
  // Desc: Displays information about each passenger from each line
  // Preconditions: Has line loaded and passenger loaded
  // Postconditions: Displays information about each passenger
  void DisplayPassengers();
  // Name:  CalcEarnings()
  // Desc: Displays total earnings based on passengers
  //       Displays earnings by line
  // Preconditions: Has lines and passengers loaded
  // Postconditions: Displays line with stop data
  void CalcEarnings();
private:
  string m_fileLines; //Stores input file name of lines
  string m_filePass; //Stores input file name of passengers
  vector<Line*> m_lines; //Stores all 6 metro lines as "Lines"
  vector<Passenger*> m_passengers; //Stores all passengers loaded from file
};

#endif //Header guard
