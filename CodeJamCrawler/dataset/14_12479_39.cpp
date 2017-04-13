#include "Prob D.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <stdio.h>

using namespace std;

void ArraySortAsc(double* array, const unsigned int nElements) {
	for(unsigned int i = 0; i < nElements; i++) {
		for(unsigned int t = 0; t < nElements; t++) {
			if(i > t) {
				if(array[i] < array[t]) {
					swap(array[i], array[t]);
				}
			} else if (i < t) {
				if(array[i] > array[t]) {
					swap(array[i], array[t]);
				}
			}
		}
	}
}

void ArraySortDec(double* array, const unsigned int nElements) {
	for(unsigned int i = 0; i < nElements; i++) {
		for(unsigned int t = 0; t < nElements; t++) {
			if(i < t) {
				if(array[i] < array[t]) {
					swap(array[i], array[t]);
				}
			} else if (i > t) {
				if(array[i] > array[t]) {
					swap(array[i], array[t]);
				}
			}
		}
	}
}

int ProbD() {
	ifstream in("input.in");
	ofstream out("output.txt");
	if(!in || !out) return -1;

	unsigned int nCases;
	in >> nCases;

	for(unsigned int _case = 0; _case < nCases; _case++) {
		out << "Case #" << _case + 1 << ": ";
		unsigned int nBlocks;
		in >> nBlocks;
		double *NaomiBlocks = new double[nBlocks], *KenBlocks = new double[nBlocks];

		for(unsigned int i = 0; i < nBlocks; i++) {
			in >> NaomiBlocks[i];
		}
		for(unsigned int i = 0; i < nBlocks; i++) {
			in >> KenBlocks[i];
		}

		ArraySortDec(NaomiBlocks, nBlocks);
		ArraySortDec(KenBlocks, nBlocks);

		unsigned int* nPairPos = new unsigned int[nBlocks];
		for(unsigned int i = 0; i < nBlocks; i++) {
			nPairPos[i] = nBlocks;
			for(unsigned int j = 0; j < nBlocks; j++) {
				bool taken = false;
				for(unsigned int k = 0; k < nBlocks; k++) {
					if(nPairPos[k] == j) {
						taken = true;
						break;
					}
				}
				if(NaomiBlocks[i] > KenBlocks[j] && !taken) {
					nPairPos[i] = j;
					break;
				}
			}
			if(nPairPos[i] == nBlocks) {
				for(unsigned int j = 0; j < nBlocks; j++) {
					bool taken = false;
					for(unsigned int k = 0; k < nBlocks; k++) {
						if(nPairPos[k] == j) {
							taken = true;
							break;
						}
					}
					if(!taken) {
						nPairPos[i] = j;
						break;
					}
				}
				if(nPairPos[i] == nBlocks) throw(exception());
			}
		}

		unsigned int nWinsDec = 0;
		for(unsigned int i = 0; i < nBlocks; i++) {
			if(NaomiBlocks[i] > KenBlocks[nPairPos[i]]) {
				nWinsDec++;
			}
		}

		delete[] nPairPos;
		nPairPos = new unsigned int[nBlocks];
		for(unsigned int i = 0; i < nBlocks; i++) {
			nPairPos[i] = nBlocks;
			for(unsigned int j = 0; j < nBlocks; j++) {
				bool taken = false;
				for(unsigned int k = 0; k < nBlocks; k++) {
					if(nPairPos[k] == j) {
						taken = true;
						break;
					}
				}
				if(KenBlocks[i] > NaomiBlocks[j] && !taken) {
					nPairPos[i] = j;
					break;
				}
			}
			if(nPairPos[i] == nBlocks) {
				for(unsigned int j = 0; j < nBlocks; j++) {
					bool taken = false;
					for(unsigned int k = 0; k < nBlocks; k++) {
						if(nPairPos[k] == j) {
							taken = true;
							break;
						}
					}
					if(!taken) {
						nPairPos[i] = j;
						break;
					}
				}
				if(nPairPos[i] == nBlocks) throw(exception());
			}
		}

		unsigned int nWinsWar = 0;
		for(unsigned int i = 0; i < nBlocks; i++) {
			if(NaomiBlocks[nPairPos[i]] > KenBlocks[i]) {
				nWinsWar++;
			}
		}

		out << nWinsDec << ' ' << nWinsWar << endl;

		delete[] NaomiBlocks;
		delete[] KenBlocks;
		delete[] nPairPos;
	}

	return 0;
}