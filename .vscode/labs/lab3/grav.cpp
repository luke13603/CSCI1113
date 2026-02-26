#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double mass1, mass2, grav, dis, force;
	cout << "input mass1, mass2, dis" << endl;
	cin >> mass1 >> mass2 >> dis;
	force = ((6.673 * pow(10, -8)) * mass1 * mass2) / pow(dis, 2);
	
	cout << force << endl;
}
