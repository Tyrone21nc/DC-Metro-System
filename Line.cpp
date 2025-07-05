/*
    Author: Romain Dzeinse
    Date: 10/14/24
    Given: 10/10/24
    Due: 10/31/24   (Halloween)  Don't let big Randy take your candy
    Objective: Build the DMV metro system
*/

#include "Line.h"

Line::Line(){
    m_head = nullptr;
    m_tail = nullptr;
    m_totalStops = 0;
    m_lineName = "NO LINE NAME";
}

Line::Line(string line){
    m_head = nullptr;
    m_tail = nullptr;
    m_totalStops = 0;
    m_lineName = line;
}

Line::~Line(){
    Stop *curr = m_head;

    for(int i=0; i<m_totalStops; i++){
        m_head = curr;
        curr = m_head->GetNext();
        delete m_head;
	// if(curr->GetNext() == m_tail){       // The goal for this is to check if the curr is pointing to the tail, if yes, then delete tail, but I feel like the loop already does that.
        //     delete m_tail;
        // } 
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_totalStops = 0;
}

string Line::GetLineName(){
    return m_lineName;
}

void Line::AddStop(int stopNumber, string stopName){
    Stop *newStop = new Stop(stopNumber, stopName);
    // *****This is the long way to add a Stop*****
    // Stop *curr = m_head;
    // Stop *prev = m_head;
    // while(curr != nullptr){
    //     prev = curr;
    //     curr = m_head->GetNext();
    // }
    // curr = newStop;
    // newStop = m_tail;
    
    // *****This is the easier way*****
    if(m_totalStops == 0){
        m_head = newStop;
        m_tail = newStop;
    }
    else{
        m_tail->SetNext(newStop);
        m_tail = newStop;
    }
    m_totalStops++;     // we are incrementing the value of total stops by one since we are adding the value of the Line
}

void Line::PrintLineDetails(){
    Stop *temp = m_head;
    while(temp != nullptr){
        cout << temp->GetNumber() << ": \033[32m" + temp->GetName() + "(" + GetLineName() + ")\033[0m" << endl;
        temp = temp->GetNext();
    }
}

int Line::CalculateDistance(string start, string end){
    int numStops = 0;
    Stop *temp = m_head;
    bool hitStart = false;      // hitstart is a boolean checker variable; it checks if I have gotten to the starting location 
    while (temp != nullptr){    // add an or statement to check if the current equals end
        if(temp->GetName() == start){
            hitStart = true;
            // numStops++;      // I don't think we're including the starting stop on the counter
        }
        else if(hitStart){
            numStops++;
        }
        if(temp->GetName() == end){
            hitStart = false;
            numStops++;
            break;
        }
        temp = temp->GetNext();
    }
    return numStops;
}
