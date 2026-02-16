#include <iostream>
#include <cmath>
using namespace std;

bool comparePoint(double x, double y, double a, double b, double c){
    int poly = (a * pow(x, 2)) + (b * x) + c;
    if (y < poly){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    srand(89347);
    int hieght, leftBound, rightBound;
    double  a, b, c, numDarts, poly, x, y, p=0, integral;
    cout << "input a, b, and c" << endl;
    cin >> a >> b >> c; 
    cout << "max height and Num darts" << endl;
    cin >> hieght >> numDarts;
    cout << "input leftBound and rightBound" << endl;
    cin >> leftBound >> rightBound;
    
    for(int i = 0; numDarts > i; i++){
        x = ((double)rand() / (RAND_MAX) * (rightBound - leftBound)) + leftBound;
        y = ((double)rand() / RAND_MAX * hieght);
        if(comparePoint(x, y, a, b, c)){
            p++;
        }
    }

    integral = (p/numDarts) * (hieght * (rightBound - leftBound));
    cout << "returns: " << integral;

}