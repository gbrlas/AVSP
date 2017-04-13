#include <iostream>
#include <cmath>

using namespace std;

unsigned long int T,k,n;

int main(){
	cin >> T;
	for (unsigned long int t=1; t<=T; t++){
		cin >> n >> k;
		unsigned long int power = pow(2.0,n*1.0);
		bool on = (k % (power) == (power)-1);
		cout << "Case #" << t << ": ";
		if (on)
			cout << "ON" << endl;
		else
			cout << "OFF" << endl;
	}
	return 0;
}