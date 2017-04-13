#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// main
int main(){
	ifstream cin;
	cin.open("cookis_ca_test.txt");
	ofstream cout;
	cout.open("cookis_ca_sol.txt");
	// store T & proceed
	int T; cin >> T;
	for (int t=0; t<T; t++){
		// store input
		double C; cin >> C;
		double F; cin >> F;
		double X; cin >> X;
		// compute best time
		double seconds=0, inc=2.0;
		while (true){
			double t1 = (X/inc);
			double t2 = (C/inc)+(X/(inc+F));
			if (t1 <= t2){
				seconds += t1;
				break;
			} else {
				seconds += (C/inc);
				inc += F;
			}
		}
		// print the result
		cout << "Case #" << (t+1) << ": " << setprecision(15) << seconds << '\n';
	}
	return 0;
}
