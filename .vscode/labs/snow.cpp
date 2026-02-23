#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string header, check;
    int date, snwd, snow, counter;
    char punc1, punc2;
    ifstream file1("snowfall.dat");

    bool lastnum = true;

    getline(file1, header);

    while (file1 >> date){
        file1 >> snwd >> snow;
        cout << snwd << endl;
        if(snwd == 0 && lastnum == true){
            counter++;
            lastnum = false;
        }
        else if(snwd != 0){
            lastnum = true;
        }

    }

    cout << "Total snow melts: " << counter << endl;
}