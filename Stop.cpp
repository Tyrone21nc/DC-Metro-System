/*
    Author: Romain Dzeinse
    Date: 10/14/24
    Objective: Build the DMV metro system
*/

#include "Stop.h"

// This is the Constructor that will deal with the Stops for the DC Metro; We can think of it as a train station
Stop::Stop(){
    m_number = 0;               // Since we don't know what the number is, we can set the default to 0
    m_name = "NO STOP NAME";    // Since we also don't know the name of the stop, we can just set it to just mumbo jumbo words
    m_next = nullptr;           // Since there's nothing in the Linked List (LL) yet, we can just set the next pointer to nullptr
}

Stop::Stop(int number, string name){
    // We want to create a new Stop so we need a number and a name
    if(number < 0){         // just to check if the user enters a number less than 0, it will make it zero
        cout << "\033[31mThe Stop number was less than zero so I made it zero!\033[0m" << endl;
        m_number = 0;       // setting m_number equal to zero
    }
    else{
        m_number = number;  // if the user entered a valid number, >=0, then we make m_number that number
    }
    m_name = name;          // We set the name to the name of the Stop
    m_next = nullptr;       // Again, LL is empty so we set m_next to nullptr
}

// The Getters for train number and stop name
int Stop::GetNumber(){
    return m_number;    // returns the number of the stop
}
string Stop::GetName(){
    return m_name;      // returns the name of the stop
}

// Getter and Setter for the Stop
Stop* Stop::GetNext(){              // We know we need to return a pointer of type Stop
    //Stop *nxtStop = new Stop(); // Since we need to return a pointer of type Stop, we create a new pointer of type Stop
    return m_next;     // then we return the next of that pointer of type Stop
}
void Stop::SetNext(Stop *newStop){  // We also know that we're pointing the current m_next to the next value in the pointer
    m_next = newStop;       // We then say we want m_next to point to whatever the newStop was pointing to
}

