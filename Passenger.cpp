/*
    Author: Romain Dzeinse
    Date: 10/14/24
    Objective: Build the DMV metro system
*/
#include "Passenger.h"

// Creates a new Passenger and gives them these default values
Passenger::Passenger(){
    m_number = -1;
    m_line = "NO LINE";
    m_startLocation = "NO LOCATION";
    m_finalDestination = "NO DESTINATION";
}

// Creates a new Passenger and gives it these values to store rather than default values like the one above
// Using an initialization list to keep everything on one line
Passenger::Passenger(int number, string line, string startLocation, string finalDestination): m_number(number), m_line(line), m_startLocation(startLocation), m_finalDestination(finalDestination){}

int Passenger::GetNumber(){
    return m_number;
}

string Passenger::GetLine(){
    return m_line;
}

string Passenger::GetStartLocation(){
    return m_startLocation;
}

string Passenger::GetFinalDestination(){
    return m_finalDestination;
}

void Passenger::DisplayPassenger(){
  cout << "\033[32mPassenger" << GetNumber() << ": " +  GetStartLocation() + " to " + GetFinalDestination() + "\033[0m" << endl;
}
