//
//  Passenger.h
//  Project 3 - Linked Lists
//

#ifndef PASSENGER_H //Header guards
#define PASSENGER_H //Header guards

//Required libraries
#include <string>
#include <iostream>
using namespace std;

//This class is used to store information about a passenger on the DC metro
class Passenger {
public:
  // Name: Passenger() 
  // Desc: Default Constructor for a passenger with -1 for number
  //        no line, start or finish
  // Preconditions: None
  // Postconditions: Creates a new Passenger
  Passenger();
  // Name: Passenger(int, string, string, string)
  // Desc: Overloaded Constructor for a passenger including number, line,
  //        start location (where they board), final destination
  //        (where they get off)
  // Preconditions: Passenger num, line, start, and end required
  // Postconditions: Creates a new Passenger
  Passenger(int, string, string, string);
  // Name: GetNumber
  // Desc: Returns passenger number
  // Preconditions: Passenger number required
  // Postconditions: Returns passenger number
  int GetNumber();
  // Name: GetLine
  // Desc: Returns line (red, orange, yellow, blue, green, or silver)
  // Preconditions: Passenger line required
  // Postconditions: Returns passenger line
  string GetLine();
  // Name: GetStartLocation
  // Desc: Returns starting location
  // Preconditions: Passenger start location required
  // Postconditions: Returns starting location
  string GetStartLocation();
  // Name: GetFinalDestination
  // Desc: Returns final location
  // Preconditions: Passenger final destination required
  // Postconditions: Returns final destination
  string GetFinalDestination();
  // Name: DisplayPassenger
  // Desc: Displays passenger information in this form:
  //       Passenger Number: starting location to final destination
  // Preconditions: Passenger data required
  // Postconditions: Outputs passenger data
  void DisplayPassenger();
private:
  int m_number; //Unique identifier of a passenger
  string m_line; //Indentifies which line this passenger is traveling on
  string m_startLocation; //Starting location (Where they get on)
  string m_finalDestination; //Final destination (where they get off)
};

#endif /* PASSENGER_H */
