#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << setprecision(7) << fixed;
	int T;
	double X,C,F, time, rate;
	cin >> T;
	for (int I=0;I<T;I++){
		cin >> C >> F >> X;
		time = 0;
		for (rate=2; X/rate > C/(rate) + X/(rate + F); rate += F){
			time += C/rate;
		}
		time += X/rate;
		cout << "Case #" << I+1 << ": " << time << endl;
	}
	return 0;
}
