//
//  Stop.cpp
//  Project 3 - Linked Lists
//
#ifndef STOP_CPP //Header guards
#define STOP_CPP //Header guards

//Required libraries
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//Stop is the node for each node in the Line linked list
//You can think of a stop as a train station for the DC Metro
class Stop {
public:
  // Name: Stop - Default constructor
  // Desc - Default constructor for a Stop node
  // Preconditions - None
  // Postconditions - Creates a new Stop (for the Route)
  Stop();
  // Name: Stop (number, name) - Overloaded Constructor
  // Desc - Overloaded constructor
  // Preconditions - Must have number and name to create new stop
  // Postconditions - Creates a new Stop (for the Line)
  Stop(int number, string name);
  // Name: GetNumber()
  // Desc - Returns the number of the stop
  // Preconditions - None
  // Postconditions - Returns a read-only m_number
  int GetNumber();
  // Name: GetName()
  // Desc - Returns the name of the stop
  // Preconditions - None
  // Postconditions - Returns a read-only m_name
  string GetName();
  // Name: GetNext()
  // Desc - Returns a pointer to the next stop
  // Preconditions - None
  // Postconditions - Returns the pointer to the next stop
  Stop* GetNext();
  // Name: SetNext()
  // Desc - Sets the pointer to the next stop
  // Preconditions - Pointer has been defined
  // Postconditions - Updates m_next to next stop on Route
  void SetNext(Stop* newStop);
private:
  int m_number; //Number of the stop
  string m_name; //Name of the stop (train station)
  Stop *m_next; //Pointer to next stop
};

#endif //Header guard
