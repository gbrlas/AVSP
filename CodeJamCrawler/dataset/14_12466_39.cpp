#include "Prob A.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int ProbA() {
	ifstream in("input.in");
	ofstream out("output.txt");
	if(!in || !out) return -1;

	unsigned int nCases;
	in >> nCases;

	for(unsigned int _case = 0; _case < nCases; _case++) {
		out << "Case #" << _case + 1 << ": ";
		unsigned int firstArray[16], secondArray[16], firstRow, secondRow;
		in >> firstRow;
		for(unsigned int i = 0; i < 16; i++) {
			in >> firstArray[i];
		}
		in >> secondRow;
		for(unsigned int i = 0; i < 16; i++) {
			in >> secondArray[i];
		}

		unsigned int firstRowSelection[4], secondRowSelection[4];
		for(unsigned int i = 0; i < 4; i++) {
			firstRowSelection[i] = firstArray[i + (firstRow * 4) - 4];
			secondRowSelection[i] = secondArray[i + (secondRow * 4) - 4];
		}

		unsigned int nMatches = 0;
		unsigned int match = 0;
		for(unsigned int i = 0; i < 4; i++) {
			for(unsigned int j = 0; j < 4; j++) {
				if(firstRowSelection[i] == secondRowSelection[j]) {
					match = firstRowSelection[i];
					nMatches++;
				}
			}
		}

		if(nMatches == 0) out << "Volunteer cheated!" << endl;
		else if(nMatches > 1) out << "Bad magician!" << endl;
		else out << match << endl;
	}

	return 0;
}