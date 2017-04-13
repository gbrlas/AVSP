#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;

int t;

int main(int argc, const char* argv[]) {

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	inputFile >> t;

	printf("TestCases: %i\n", t);

	for (int i = 0; i < t; i++) {
		int r;
		int c;
		inputFile >> r;
		inputFile >> c;

		char picture[r][c];

		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				inputFile >> picture[j][k];
				printf("%c", picture[j][k]);
			}
			printf("\n");
		}

		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				switch (picture[j][k]) {
				case '#':
					if (j != r - 1 && k != c - 1) {
						if (picture[j][k + 1] == '#' && picture[j + 1][k]
								== '#' && picture[j + 1][k + 1] == '#') {
							picture[j][k] = '/';
							picture[j][k + 1] = '\\';
							picture[j + 1][k] = '\\';
							picture[j + 1][k + 1] = '/';
						}
					}
					break;
				case '.':
					break;
				case '/':
					break;
				case '\\':
					break;
				}
			}
			printf("\n");
		}

		int possible = 1;
		for (int j = 0; j < r; j++) {
			printf("\t");
			for (int k = 0; k < c; k++) {
				printf("%c", picture[j][k]);
				switch (picture[j][k]) {
				case '#':
					possible = 0;
					break;
				default:
					break;
				}
			}
			printf("\n");
		}

		outputFile << "Case #" << i + 1 << ":" << endl;
		if (possible == 0) {
			outputFile << "Impossible" << endl;
		} else {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					outputFile << picture[j][k];
				}
				outputFile << endl;
			}
		}

	}

	return 0;

}
