#include "ProbB.h"
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

int ProbB() {
	ifstream in("input.in");
	ofstream out("output.txt");
	if (!in || !out) return -1;

	unsigned int nCases;
	in >> nCases;

	for (unsigned int _case = 0; _case < nCases; _case++) {
		out << "Case #" << _case + 1 << ": ";
		unsigned int A, B, X;

		in >> A;
		in >> B;
		in >> X;

		unsigned int t = 0;
		for (unsigned int i = 0; i < X; i++) t |= i;

		unsigned int total = 0;
		for (unsigned int a = 0; a < A; a++) {
			for (unsigned int b = 0; b < B; b++) {
				for (unsigned int i = 0; i < X; i++) if ((a & b) == i) total++;
			}
		}
		out << total << endl;
	}

	return 0;
}
