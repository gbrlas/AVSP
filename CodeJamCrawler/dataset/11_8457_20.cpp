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
		int n;

		inputFile >> n;

		char games[n][n];

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				inputFile >> games[j][k];
				printf("Read: %c", games[j][k]);
			}
			printf("\n");
		}

		double wp[n];
		for (int j = 0; j < n; j++) {
			int sum = 0;
			int numberGames = 0;
			for (int k = 0; k < n; k++) {
				switch (games[j][k]) {
				case '1':
					sum++;
					numberGames++;
					break;
				case '0':
					numberGames++;
					break;
				case '.':
					break;
				}
			}
			wp[j] = (double) sum / (double) numberGames;
			printf("WP team: %i , %0.12f\n", j, wp[j]);
		}

		float owp[n];
		for (int j = 0; j < n; j++) {
			double sum = 0;
			int numberGames = 0;
			for (int k = 0; k < n; k++) {
				if (games[j][k] != '.') {
					double wpTeam;

					int smallsum = 0;
					int smallnumberGames = 0;
					for (int m = 0; m < n; m++) {
						if (m != j) {
							switch (games[k][m]) {
							case '1':
								smallsum++;
								smallnumberGames++;
								break;
							case '0':
								smallnumberGames++;
								break;
							case '.':
								break;
							}
						}
					}
					wpTeam = (double) smallsum / (double) smallnumberGames;
					sum += wpTeam;
					numberGames++;
				}
			}
			owp[j] = (double) sum / (double) numberGames;
			printf("OWP team: %i , %0.12f\n", j, owp[j]);
		}

		float oowp[n];
		for (int j = 0; j < n; j++) {
			double sum = 0;
			int numberGames = 0;
			for (int k = 0; k < n; k++) {
				if (games[j][k] != '.') {
					sum += owp[k];
					numberGames++;
				}
			}
			oowp[j] = (double) sum / (double) numberGames;
			printf("OOWP team: %i , %0.12f\n", j, oowp[j]);
		}
		outputFile << "Case #"<< i+1 << ":" << endl;
		outputFile.precision(14);
		for (int j = 0; j < n; j++) {
			double rpi = 0.25 * wp[j] + 0.50 * owp[j] + 0.25 * oowp[j];
			printf("RPI team: %i , %0.12f\n", j, rpi);
			outputFile << rpi << endl;
		}
	}

	return 0;
}
