#include "Prob B.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int ProbB() {
	ifstream in("input.in");
	ofstream out("output.txt");
	if(!in || !out) return -1;

	unsigned int nCases;
	in >> nCases;

	out << fixed;
	out << setprecision(7);

	for(unsigned int _case = 0; _case < nCases; _case++) {
		out << "Case #" << _case + 1 << ": ";
		double C, F, X;
		in >> C; //farm cost
		in >> F; //farm inc
		in >> X; //target
		double currentCookieCount = 0;
		double cookieSpeed = 2.0;
		double timeCount = 0;
		double timeToFarm = 0, timeToFinish = 0;

		start:

		timeToFarm = C / cookieSpeed;
		timeToFinish = X / cookieSpeed;

		if(timeToFarm > timeToFinish) {
			goto end;
		} else if(timeToFarm + (X / (cookieSpeed + F)) < timeToFinish) {
			timeCount += timeToFarm;
			cookieSpeed += F;
			goto start;
		}

		end:
		timeCount += timeToFinish;

		out << timeCount << endl;
	}

	return 0;
}