/*
Workshop 3: File IO and Function Decomposition
Authors:
Hahnemann
Alexi

Gabriel Garso
Purpose:
-Practice your debugging skills.
-Practice your skills in analyzing existing code written by
someone else.
-Practice your skills in analyzing code that includes unfamiliar
elements.
-Introduce you to user-defined functions.
Task: Analyze & debug the program!
-Determine and document the program's purpose. What does it do?
What does
each function do?
-Debug. This program includes AT LEAST 4 bugs. Note that as
programs get more
complex, the odds of a bug we didn't intend go up!
During the workshop, you have access to one of the previous
developers
(Alexi). You may freely ask them questions.
Evaluation:
-If you are following along and submit Monday, full credit.
-Otherwise, 4 points for documentation and 1 point each per bug
identified
and corrected, up to a total of 10 points.
Expected Terminal Output:
-------------------------
0
1
two
3
4
five
6
7
8
9
Bad input: two
Bad input: five
Success! The sum is: 38
---------------------------
Expected Environment:
--------------------------------------------------
.
out
sum.txt
The file sum.txt should contain the sum "38" only.
--------------------------------------------------
*/
// g++ workshop3.cpp -o workshop3.out && ./workshop3.out

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isFileOpen(const ifstream& file, const string& filePath){
    if (!file.is_open()){ //bug missing 1
        cout << "Failed to open the file [" << filePath << ']' <<
        endl;
        return false;
    }
    return true;
}

void printFileLines(ifstream& file){
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
}

int sumIntegersFromFile(ifstream& file){
    int sum {0};
    int num;
    while (file.eof()){
        if (file >> num){
            sum += num;
            cout << "debug1" << endl;
        }
        else if (file.fail() && !file.eof()){
            cout << "debug2" << endl;
            file.clear();
            string word;
            file >> word;
            cout << "Bad input: " << word << endl;
        }
        else{
            break;
        }
    }
    return sum;
}

bool writeResultToFile(int result, const string& outFilePath){
    ofstream outFile(outFilePath);
    if (!outFile.is_open()){
        cout << "Failed to open output file [" << outFilePath << ']' << endl;
        return false;
    }
    outFile << result;
    outFile.close();
    return true;
}

int main(){
    string inFileName {"mostlyNumbers.txt"};
    string inPath {"in"};
    string filePath = inPath + "\\" + inFileName; //need forward slashes here
    ifstream inFile(filePath);
    
    if (!isFileOpen(inFile, filePath)){
        return 1;
    }

    printFileLines(inFile); // need to rset this file stream afterwards
    inFile.clear(); //close it so we can open a new copy
    inFile.open(filePath);
    cout << "debug3" << endl;

    int sum {sumIntegersFromFile(inFile)};
    inFile.close();
    string outFileName {"sum.txt"};
    string outPath {"out"};
    string outFilePath = outPath + "\\" + outFileName; //also happens here 
    if (!writeResultToFile(sum, outFilePath)){
        return 1;
    }
    cout << "Success! The sum is: ";
    cout << sum << endl;
    return 0;
}