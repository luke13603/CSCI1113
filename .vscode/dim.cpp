#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 3) {
        cout << "Error: Please provide exactly two files." << endl;
        cout << "Usage: ./a.out file1.txt file2.txt" << endl;
        return 1;
    }

    ifstream file1("file1.txt"); // Type the actual name here
    ifstream file2("file2.txt"); // Type the actual name here

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Error: Could not open one or both files." << endl;
        return 1;
    }

    string line1, line2;
    bool match = true;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            match = false;
            break; 
        }
    }

    if (match) {
        if (file1.eof() && file2.eof()) {
            cout << "files match" << endl;
        } else {
            cout << "files differ" << endl;
        }
    } else {
        cout << "files differ" << endl;
    }

    return 0;
}