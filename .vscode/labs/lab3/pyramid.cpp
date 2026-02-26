#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double upper, base, height, surface, volume;
	cout << "Input top, base, and height" << endl;
	cin >> upper; 
	cin >> base; 
	cin >> height;
	
	volume = ((pow(upper, 2) + pow(base, 2) + (base * upper)) * height) / 3.0;
	surface = (pow(upper, 2) + pow(base, 2)) + (2.0 * (base + upper)) * sqrt((((base * upper)/2.0) * ((base * upper)/2.0)) + pow(height, 2));
	
	cout << "volume: " << volume << endl;
	cout << "surface area: " << surface << endl;
}
