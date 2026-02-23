#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outputFile;
    outputFile.open("flightdata.dat");

    if (!outputFile) {
        cout << "Error: Could not create the output file flightData.dat" << endl;
        return 1; 
    }

    outputFile << "Flight Number    Scheduled Arrival    Actual Arrival" << endl;

    string flightNum, scheduledTime, actualTime;

    while (true) {
        cout << "Enter the flight number: ";
        cin >> flightNum;

        if (flightNum == "end") {
            break; 
        }

        cout << "Enter the scheduled/actual arrival times: ";
        cin >> scheduledTime >> actualTime;

        outputFile << flightNum << " " << scheduledTime << " " << actualTime << endl;
        
        cout << endl; 
    }
    outputFile.close();
    cout << "Data saved to flightData.dat. Program terminating..." << endl;
}