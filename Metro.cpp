/*
    Author: Romain Dzeinse
    Date: 10/14/24
    Objective: Build the DMV metro system
*/

#include "Metro.h"
#include <fstream>
#include <string>
#include <iomanip>

Metro::Metro(){
    m_fileLines="NO-FILE-LINES";
    m_filePass="NO-FILE-PASS";
    LoadLines();
    LoadPasses();
    MainMenu();
}
Metro::Metro(string fileLine, string filePass){
    m_fileLines = fileLine;
    m_filePass = filePass;
    LoadLines();
    LoadPasses();
    MainMenu();    
}
Metro::~Metro(){
    for(unsigned int i=0; i<m_lines.size(); i++){
        delete m_lines.at(i);
        // m_lines.at(i) = nullptr;     // you might need this, but if you valgrind and it shows no memory leaks, it's probably because of the clear functions you have included below
    }
    for(unsigned int i=0; i<m_passengers.size(); i++){
        delete m_passengers.at(i);
        // m_passengers.at(i) = nullptr;    // Same thing as for m_lines, you might not need to implement this explicitelty here, but I recommend to check with a TA.
    }
    m_lines.clear();
    m_passengers.clear();
}
void Metro::LoadLines(){
    ifstream inputLineFile;
    inputLineFile.open(m_fileLines);
    // read in each line from station
    // create a line for each color, like for red line
    // use the delimeter when inputing from the files
    string lineNum, lineColor, lineStop;
    Line *newLine = nullptr;
    if(inputLineFile.is_open()){
        while(getline(inputLineFile, lineNum, ',')){    // A getline for the first character from the file. We start by getting that value and store it in LineNum, with the delimeter used to stop the reading at that point
            getline(inputLineFile, lineColor, ',');     // Then we use more getlines to get the remaining data; this is to get the line color, which is the second inputed variable
            getline(inputLineFile, lineStop);           // This is for the lineStop variuable, or third variable
            if(LineToIndex(lineColor) == -1){  // If the lineNum, the first number in the file, is a 1, then, we create a new Line to store all the Stops
	        newLine = new Line(lineColor);     // Creates a new dynamically allocated Line variable with the Line Stop as the name
                m_lines.push_back(newLine);
            }
            m_lines.at(LineToIndex(lineColor))->AddStop(stoi(lineNum), lineStop);
	}
        inputLineFile.close();
    }
}
void Metro::LoadPasses(){
    ifstream inputStream;
    string passNum, color, startLoc, destination;
    inputStream.open(m_filePass);
    while(getline(inputStream, passNum, ',') && getline(inputStream, color, ',') && getline(inputStream, startLoc, ',') && getline(inputStream, destination)){  
        Passenger *newPass = new Passenger(stoi(passNum), color, startLoc, destination);
        m_passengers.push_back(newPass);
    }
    inputStream.close();
}
int Metro::LineToIndex(string name){
  for(unsigned int i=0; i<m_lines.size(); i++){
    if (name == m_lines[i]->GetLineName()){
	  return i;
        }
    }   
    return -1;
}
void Metro::MainMenu(){
    cout << "\033[32mWelcome to the Washington DC Metro\033[0m" << endl;
    int action;
    do{
        cout << "1. Display Lines" << endl;
        cout << "2. Display Passengers by Line" << endl;
        cout << "3. Calculate Earnings by Line" << endl;
        cout << "4. Exit" <<  endl;
        cout << "What would you like to do? " << endl;
        cout << ">>> ";
        cin >> action;
        switch(action){
            case 1:
                cout << "\033[31m**********YOU ARE NOW DISPLAYING LINES**********\033[0m" << endl;
                DisplayLines();         // This displays the lines by line color
                cout << "\033[31m**********YOU ARE DONE DISPLAYING LINES**********\033[0m" << endl << endl;
		break;
            case 2:
                cout << "\033[31m**********YOU ARE NOW DISPLAYING PASSENGERS**********\033[0m" << endl;
                DisplayPassengers();    // This displays the passengers by line color
                cout << "\033[31m**********YOU ARE DONE DISPLAYING PASSENGERS**********\033[0m" << endl << endl;
		break;
            case 3:
                cout << "\033[31m**********YOU ARE NOW CALCULATING EARNINGS BY LINE**********\033[0m" << endl;
                CalcEarnings();         // This calculate and outputs the earnings
                cout << "\033[31m**********YOU ARE DONE CALCULATING EARNINGS BY LINE**********\033[0m" << endl << endl;
		break;
        }
    }
    while(action != 4);
    cout << "\033[31mThank you for using the Metro!\033[0m" << endl;
}
void Metro::DisplayLines(){
    for(unsigned int i=0; i<m_lines.size(); i++){
        cout << "**\033[33m" + m_lines.at(i)->GetLineName() + " Line Stops\033[0m**" << endl;
        m_lines.at(i)->PrintLineDetails();      // This will output the Line at that position
        cout << endl;       // It print all the lines at that line color
    }
}
void Metro::DisplayPassengers(){
    for(unsigned int i=0; i<m_lines.size(); i++){ 
        cout << "*** \033[33m" + m_lines.at(i)->GetLineName() + "\033[0m ***" << endl;       // nested for loop
        cout << "Passengers: " << endl;
        for(unsigned int j=0; j<m_passengers.size(); j++){
	  if(m_lines.at(i)->GetLineName() == m_passengers.at(j)->GetLine()){
	      m_passengers.at(j)->DisplayPassenger();
	  }
        }
        cout << endl;
    }
}
void Metro::CalcEarnings(){
  double totalEarned;
  int lineTotal;
    for(unsigned int i=0; i<m_lines.size(); i++){
        lineTotal = 0;
	cout << "**\033[33m" + m_lines.at(i)->GetLineName() + " Line Total Earnings\033[0m**" << endl;
        for(unsigned int j=0; j<m_passengers.size(); j++){
            if(m_lines.at(i)->GetLineName() == m_passengers.at(j)->GetLine()){      // We are checking if the current iteration ofn the passenger is on the line
                lineTotal += m_lines.at(i)->CalculateDistance(m_passengers.at(j)->GetStartLocation(), m_passengers.at(j)->GetFinalDestination());
            }
        }
        totalEarned += lineTotal;
        cout << "$" << fixed << setprecision(2) << (lineTotal*PER_STOP) << endl;       // This is used to set the decimal positions to two places to the right
        cout << "Total Stops: \033[32m" << lineTotal << "\033[0m" << endl << endl;
    }
}
