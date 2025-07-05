//
//  Line.h
//  Project 3 - Linked Lists
//
#ifndef LINE_H //Header guards
#define LINE_H //Header guards

//Required libraries
#include <string>
#include <fstream>
#include <iostream>
#include "Stop.h"
using namespace std;

//Lines are the routes a train would take from stop to stop
//In this case, it is a linked list that is made up of stops (nodes)
class Line {
public:
  // Name: Line() - Default Constructor
  // Desc: Creates a new empty line
  // Preconditions: None
  // Postconditions: Sets everything to either nullptr or 0
  Line();
  // Name: Line() - Overloaded Constructor
  // Desc: Creates a new empty line with passed name
  // Preconditions: None
  // Postconditions: Sets everything to either nullptr or 0
  Line(string line);
  // Name: ~Line - Destructor
  // Desc: Removes all of the stops from the line
  // Preconditions: Line must have nodes
  // Postconditions: Line will be empty and m_head and m_tail
  //                  will be nullptr
  ~Line();
  // Name: GetLineName
  // Desc: Returns the name of the line
  // Preconditions: Line must have a name
  // Postconditions: Returns m_lineName;
  string GetLineName();
  // Name: AddStop()
  // Desc: Dynamically allocates new stop and inserts at end of line
  //        (passes stop number and name)  
  // Preconditions: Line allocated and data for stop available
  // Postconditions: New stop inserted in end of line
  void AddStop(int, string);
  // Name: PrintLineDetails()
  // Desc: Prints information about a specific line
  // Preconditions: Line allocated and data for next stop available
  // Postconditions: Displays list of each stop on a line
  //                 including number, name, and (lineName)
  void PrintLineDetails();
  // Name: CalculateDistance(string start, string end)
  // Desc: Calculates the number of stops between the
  //        starting station and ending station
  // Preconditions: Line allocated with start and stop on correct line
  // Postconditions: Returns number of stops between two stations
  // There will always be at least two stops (start != stop)
  // For example, if the line is station 1 to station 2, the distance is 2
  // If the line is station 1 to station 4, the distance is 4
  int CalculateDistance(string start, string end);
  // Name: ReverseLine (ONLY REQUIRED FOR EXTRA CREDIT)
  // Desc: At the end of a line, the line can be reversed
  //        (as in the train turns around)
  // Recommendations: Code only if you complete the base project
  // Preconditions: Line has been completed
  // Postconditions: Reverses this line in place (no new nodes)
  // void ReverseLine();
private:
  Stop* m_head; //First stop of the line (head of linked list)
  Stop* m_tail; //Last stop of the line (tail of linked list)
  int m_totalStops; //Total stops on the line (size of linked list)
  string m_lineName; //Name of line
};

#endif /* LINE_H */
