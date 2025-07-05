#include "Metro.h"
#include "Line.h"
#include "Stop.h"
#include "Passenger.h"

#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
  if (argc < 3) {
    cout << "You are missing data files." << endl;
    cout << "Expected usage ./proj3 proj3_stations.txt proj3_data1.txt" << endl;
    cout << "File 1 should be a file with one or more Metro Lines" << endl;
    cout << "File 2 should be a file of passengers" << endl;
  }
  else {
    Metro M = Metro(argv[1], argv[2]);
  }
  return 0;
}
