#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int total(string time) {
    int hours, mins;
    if (time.length() == 4) {
        hours = time.at(0);
        mins = ((time.at(2)) * 10) + (time.at(3));
    } else if (time.length() == 5) {
        hours = ((time.at(0)) * 10) + (time.at(1));
        mins = ((time.at(3)) * 10) + (time.at(4));
    } else {
        return 0;
    }
    return (hours * 60) + mins;
}

void displayTime(int totalMinutes) {
    int absMinutes = abs(totalMinutes);
    int hours = absMinutes / 60;
    int mins = absMinutes % 60;
    
    cout << hours << ":" << (mins < 10 ? "0" : "") << mins;
}

int main() {
    //fyck ts shit
    double minDelay = 99999, maxDelay = -99999;
    double sumDelay = 0;
    int count = 0;
    
    string filename, flightNum, maxFlight, minFlight, scheduledTime, actualTime, header;

    cout << "Enter the flight data filename: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error: Could not open file " << filename << endl;
        return 1;
    }

    // Skippppp the fuckass header
    getline(inputFile, header);

    while (inputFile >> flightNum) { 
        inputFile >> scheduledTime >> actualTime;

        int S2 = total(scheduledTime);
        int A2 = total(actualTime);
        double delay = A2 - S2;

        sumDelay += delay;
        count++;

        if (delay > maxDelay) {
            maxDelay = delay;
            maxFlight = flightNum;
        }

        if (delay < minDelay) {
            minDelay = delay;
            minFlight = flightNum;
        }
    }

    inputFile.close();

    //display bigass numbers
    if (count > 0) {
        cout << "Flight Arrival Statistics" << endl;
        cout << "Average flight delay: ";
        displayTime(static_cast<int>(sumDelay / count));
        cout << endl;

        cout << "Minimum delay: ";
        displayTime(static_cast<int>(minDelay));
        cout << " (Flight: " << minFlight << ")" << endl;

        cout << "Maximum delay: ";
        displayTime(static_cast<int>(maxDelay));
        cout << " (Flight: " << maxFlight << ")" << endl;
    } else {
        cout << "No valid flight data found." << endl;
    }

    return 0;
}