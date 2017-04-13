#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream input;
	ofstream output;
	input.open("B-small-attempt1.in");
	output.open("B-small-attempt1.out");
	if (!input.good() || !output.good()) return -1;
	int cases, cc = 1;
	double C, F, X, time, timeToWin, timeToBuy, CPS;
	input >> cases;
	output.precision(20);
	while (cc <= cases) {
		time = 0.0;
		CPS = 2.0;
		input >> C >> F >> X;
		timeToWin = X / CPS;
		timeToBuy = C / CPS;

		while (timeToBuy + (X/ (CPS+F)) < timeToWin) {
			time += timeToBuy;
			CPS+=F;
			
			timeToWin = X / CPS;
			timeToBuy = C / CPS;
		}	
		time += timeToWin;	
		
		output << "Case #"<<cc <<": "<<(double)time<<endl;
		
		cc++;
	}
	input.close();
	output.close();
	return 0;
}