#include "ProbA.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>
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
		unsigned int nStrings;
		unsigned int minChars = 9999, maxChars = 0;
		in >> nStrings;
		std::string* Strings = new std::string[nStrings];
		std::string pattern;
		for (unsigned int i = 0; i < nStrings; i++) {
			std::string patternt;
			in >> Strings[i];
			minChars = min(minChars, Strings[i].size());
			maxChars = max(maxChars, Strings[i].size());
			char c = Strings[i][0];
			patternt += c;
			unsigned int ndiff = 1;
			for (unsigned int j = 0; j < Strings[i].size(); j++) {
				if (Strings[i][j] != c) {
					ndiff++;
					c = Strings[i][j];
					patternt += c;
					//out << c;
				}
			}
			if (i == 0) {
				pattern = patternt;
			}
			if (pattern != patternt) {
				goto impossible;
			}
			minChars = min(minChars, ndiff);
		}

		unsigned int grand_total = 0;
		for (unsigned int i = 0; i < minChars; i++) {
			int total = 0;
			for (unsigned int j = 0; j < nStrings; j++) {

				int nRepeats = 0;
				char c = Strings[j][0];
				for (unsigned int k = 0, difChars = 0; k < Strings[j].size(); k++) {
					if (Strings[j][k] != c) {
						if (difChars == i) {
							break;
						}
						difChars++;
						c = Strings[j][k];
						nRepeats = 1;
					}
					else nRepeats++;
				}

				total += nRepeats;

			}
			total /= nStrings;
			int nDeviances = 0;
			for (unsigned int j = 0; j < nStrings; j++) {

				int nRepeats = 0;
				char c = Strings[j][0];
				for (unsigned int k = 0, difChars = 0; k < Strings[j].size(); k++) {
					if (Strings[j][k] != c) {
						if (difChars == i) {
							break;
						}
						difChars++;
						c = Strings[j][k];
						nRepeats = 1;
					}
					else nRepeats++;
				}

				nDeviances += abs(total - nRepeats);

			}
			//if (nDeviances != 0) {
			//	out << nDeviances;
			//	out << pattern[i];
			//}
			grand_total += nDeviances;
		}

		out << grand_total << endl;
		goto end;

	impossible:

		out << "Fegla Won" << endl;

	end:

		delete[] Strings;
	}

	return 0;
}
