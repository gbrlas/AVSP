#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream fout ("a.out");
ifstream fin ("a.in");
int T;

int main () {
	fin >> T;
	for(int j=1; j<= T; j++){
		int lenTyped, totalLen;
		fin >> lenTyped >> totalLen;
		double probRightSoFar = 1.0;
		double minExpected = 100000000;
		for(int i=0;i<=lenTyped;i++){
			double curProb;
			if(i!=lenTyped)
				fin >> curProb;
			minExpected = min(minExpected,probRightSoFar*(lenTyped - i + totalLen - i + 1) + (1-probRightSoFar)*(lenTyped - i + totalLen - i + 1 + totalLen + 1));
			if(i!=lenTyped)
				probRightSoFar *= curProb;
		}
		fout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		fout.precision(6);
		fout << "Case #" << j << ": " << min(minExpected,(double)totalLen+2) << endl;
	}
}