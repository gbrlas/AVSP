#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;

int t;

int main( int argc, const char* argv[] ) {
	
	ifstream inputFile (argv[1]);
	ofstream outputFile (argv[2]);
	
	inputFile >> t;
	
	for (int i = 0; i < t; i++) {
		printf("Test Case: %i\n", i+1);
		int c;
		inputFile >> c;
		char combined[c][3];
		for (int j = 0; j < c; j++) {
			inputFile >> combined[j];
			//printf("%s\n", combined[j]);
		}
		int d;
		inputFile >> d;
		char opposed[d][2];
		for (int j = 0; j < d; j++) {
			inputFile >> opposed[j];
			//printf("%s\n", opposed[j]);
		}
		int n;
		inputFile >> n;
		char nChar[n];
		inputFile >> nChar;
		
		vector<char> output;
		for (int j = 0; j < n; j++) {
			char newChar;
			newChar = nChar[j];
			if (output.size() != 0) {
				printf("Adding %c\n", newChar);
				char compareChar;
				compareChar = output.back();
				
				
				// Check Combine
				printf("\tCombine Check: %c | %c\n", compareChar, newChar);
				int noCombination = 1;
				if (c == 0) {
					noCombination = 1;
					printf("\t\tNo Combinations\n");
				}
				for (int k = 0; k < c; k++) {
					if (noCombination == 0) continue;
					if (strncmp(&combined[k][0],&compareChar,1) == 0 && strncmp(&combined[k][1], &newChar, 1) == 0) {
						printf("\t\tCombination adding: %c\n", combined[k][2]);
						output.pop_back();
						output.push_back(combined[k][2]);
						noCombination = 0;
					} else if (strncmp(&combined[k][1],&compareChar,1) == 0 && strncmp(&combined[k][0], &newChar, 1) == 0) {
						printf("\t\tCombination adding: %c\n", combined[k][2]);
						output.pop_back();
						output.push_back(combined[k][2]);
						noCombination = 0;
					} else {
						printf("\t\t No Combination\n");
						
					}
				}
				
				// Check Oppose
				if (noCombination == 1) {
					int noOpposition = 1;
					if (d == 0) {
						noOpposition = 1;
						printf("\t\tNo Oppositions\n");
					}
					for (int k = 0; k < d; k++) {
						for (int l = 0; l < output.size(); l++) {
							if (noOpposition == 0) continue;
							if (strncmp(&opposed[k][0],&output[l],1) == 0 && strncmp(&opposed[k][1], &newChar, 1) == 0) {
								printf("\t\tOpposition found! Deleting\n");
								noOpposition = 0;
							} else if (strncmp(&opposed[k][1],&output[l],1) == 0 && strncmp(&opposed[k][0], &newChar, 1) == 0) {
								printf("\t\tOpposition found! Deleting\n");
								noOpposition = 0;
							} else {
								printf("\t\t No Oppositions\n");
						
							}
						}
						if (noOpposition == 0) {
							//delete Vector
							int outputSize = output.size();
							for (int l = 0; l < outputSize; l++) {
								printf("\t\t\t\tPopping %c\n", output.back());
								output.pop_back();
							}
						}
					}
					if (noOpposition == 1) {
						printf("\t\t\tAdding %c\n", newChar);
						output.push_back(newChar);
					}
				}
				
			} else {
				printf("Adding %c\n", newChar);
				output.push_back(newChar);
			}
		}
		
		printf("Case #%i: [",i+1);
		outputFile << "Case #" << i+1 << ": ["; 
		if (output.size() == 0) {
			printf("]\n");
			outputFile << "]\n" << endl;
		}
		for (int j = 0; j < output.size(); j++) {
			if (j == output.size() - 1) {
				printf("%c]\n", output[j]); 
				outputFile << output[j] << "]" << endl;
			} else {
				printf("%c, ", output[j]);
				outputFile << output[j] << ", ";
			}
		}
		
		
		
	}
	
	inputFile.close();
	outputFile.close();
}