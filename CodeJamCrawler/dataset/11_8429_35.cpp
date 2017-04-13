#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;

int t;

int main( int argc, const char* argv[] ) {
	ifstream inputFile (argv[1]);
	ofstream outputFile (argv[2]);
	
	inputFile >> t;
	
	//printf("TestCases: %i\n", t);
	
	for (int testCaseCounter = 0; testCaseCounter < t; testCaseCounter++) {
		//printf("Current TestCase: %i\n", testCaseCounter+1);
		int n;
		inputFile >> n;
		//printf("Number of Buttons to Push: %i\n", n);
		
		vector<int> oVector;
		int oStep = 1;
		int oSeqPointer = 0;
		int oForward = 1;
		vector<int> bVector;
		int bStep = 1;
		int bSeqPointer = 0;
		int bForward = 1;
		vector<char> sequenceVector;
		int sequencePointer = 0;
		
		for (int i = 0; i < n; i++) {
			char bot;
			inputFile >> bot;
			sequenceVector.push_back(bot);
			//printf("\t%c added to sequenceVector\n", bot);
			int button;
			inputFile >> button;
			if (strncmp(&bot, "B", 1) == 0) {
				bVector.push_back(button);
				//printf("\t%i added to bVector\n", button);
			} else {
				oVector.push_back(button);
				//printf("\t%i added to oVector\n", button);
			}
		}
		
		//printf("oVector size %lu\n", oVector.size());
		//printf("bVector size %lu\n", bVector.size());
		
		//printf("start Walking\n");
		int done = 0;
		int oDone = 0;
		int bDone = 0;
		
		int time = 0;
		
		while (done == 0) {
			if (bVector.size() == 0) {
				bDone == 1;
			}
			if (oVector.size() == 0) {
				oDone = 1;
				//printf("!!!!!!!!!!!!!!");
			} else {
				//printf("NOOOOOOOOOOT");
			}
			if (strncmp(&sequenceVector[sequencePointer], "B", 1) == 0) {
				//printf("\tNext Robot to Push Button: B\n");
				/*
				if (bSeqPointer >= bVector.size()) {
					bDone = 1;
					printf("\t\t\tB waiting - Done\n");
				*/
				if (bDone == 1) {
					//printf("\t\t\tB waiting - Done\n");
				} else if (bStep == bVector[bSeqPointer]) {
					//printf("\t\tB pushed Button at %i\n", bStep);
					if (bSeqPointer == bVector.size() - 1) {
						bDone = 1;
						sequencePointer++;
						//printf("\t\t\tB waiting - Done\n");
					} else if (bVector[bSeqPointer] < bVector[bSeqPointer+1]) {
						bForward = 1;
						//printf("\tB fw\n");
						bSeqPointer++;
						sequencePointer++;
					} else {
						//printf("\tB bw\n");
						bForward = 0;
						bSeqPointer++;
						sequencePointer++;
					}
					time++;
				} else {
					if (bForward == 1) {
						bStep++;
					} else {
						bStep--;
					}
					//printf("\t\tB walked to %i\n", bStep);
					time++;
				}
				if (oVector.size() == 0) continue;
				if (oStep < oVector[oSeqPointer]) {
					oStep++;
					//printf("\t\tO walked to %i\n", oStep);
				} else if (oStep > oVector[oSeqPointer]){
					oStep--;
					//printf("\t\tO walked to %i\n", oStep);
				} else {
					//printf("\t\tO stayed at %i\n", oStep);
				}
			} else {
				//printf("\tNext Robot to Push Button: O\n");
				if (oDone == 1) {
					//printf("\t\t\tO waiting - Done\n");
				} else if (oStep == oVector[oSeqPointer]) {
					//printf("\t\tO pushed Button at %i\n", oStep);
					if (oSeqPointer == oVector.size() - 1) {
						oDone = 1;
						sequencePointer++;
						//printf("\t\t\tO waiting - Done\n");
					} else if (oVector[oSeqPointer] < oVector[oSeqPointer+1]) {
						oForward = 1;
						//printf("\tO fw\n");
						oSeqPointer++;
						sequencePointer++;
					} else {
						//printf("\tO bw\n");
						oForward = 0;
						oSeqPointer++;
						sequencePointer++;
					}
					time++;
					
				} else {
					if (oForward == 1) {
						oStep++;
					} else {
						oStep--;
					}
					//printf("\t\tO walked to %i\n", oStep);
					time++;
				}
				if (bVector.size() == 0) continue;
				if (bStep < bVector[bSeqPointer]) {
					bStep++;
					//printf("\t\tB walked to %i\n", bStep);
				} else if (bStep > bVector[bSeqPointer]) {
					bStep--;
					//printf("\t\tB walked to %i\n", bStep);
				} else {
					//printf("\t\tB stayed at %i\n", bStep);
				}
			}
			
			if (bDone == 1 && oDone == 1) {
				done = 1;
			}
			
		}
		
		printf("Case: %i Time: %i\n", testCaseCounter, time);
		outputFile << "Case #" << testCaseCounter+1 << ": " << time << endl;
		
	}
	
}