#include "ProbA.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

template<class T>
bool BinarySearch(/*Item to search for*/ const T Identifier, const T* Array, const unsigned int nElements) {
	//Identifier is last element
	if (Array[nElements - 1] == Identifier) return true;
	if (Array[0] > Identifier || Identifier > Array[nElements - 1]) return false; //Identifier too big / too small
	//Array offset(s)
	unsigned int first = 0, last = nElements;
	while (last - first > 1) {
		unsigned int midpoint = first + ((last - first) >> 1);
		if (Identifier > Array[midpoint]) first = midpoint;
		else if (Identifier < Array[midpoint]) last = midpoint;
		else return true; //Identifier is Array[midpoint]
	}
	if (Array[last] == Identifier || Array[first] == Identifier) return true;
	else return false;
}

int ProbA() {
	ifstream in("input.in");
	ofstream out("output.txt");
	if (!in || !out) return -1;

	unsigned int nCases;
	in >> nCases;

	for (unsigned int _case = 0; _case < nCases; _case++) {
		out << "Case #" << _case + 1 << ": ";
		unsigned int P, Q;
		char c;
		in >> P;
		in >> c;
		in >> Q;

		double val = log2((double)Q);
		if (floor(val) != val || val > 40) {
			out << "impossible" << endl;
			goto end;
		}

		if (P > Q >> 1) {
			out << 1 << endl;
			goto end;
		}
		
		unsigned int n = 0;
		while (P < Q) {
			Q >>= 1;
			n++;
		}

		out << n << endl;

	end:;
	}

	return 0;
}

