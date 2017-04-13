#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void insertionSort(int arrayToBeSorted[], const int &lowerLimit, const int &upperLimit) {
        int index = 0;
        int currentValue = 0;
        for (int pass = lowerLimit+1; pass <= upperLimit; pass++) {
                index = pass;
                currentValue = arrayToBeSorted[pass];
                while ((currentValue < arrayToBeSorted[index-1]) && (index > lowerLimit)) {
                        arrayToBeSorted[index] = arrayToBeSorted[index-1];
                        index--;
                }
                arrayToBeSorted[index] = currentValue;
        }
}

int main(int argc, char **argv) {
	FILE * fin;
	fin = fopen (argv[1], "r");
	ofstream fout(argv[2]);

	int numberOfTestcases = 0;

	fscanf(fin,"%d",&numberOfTestcases);
	cout << numberOfTestcases << endl;

	int j = 0;

	for (j = 0; j < numberOfTestcases; j++) {
	
		int turnaroundInterval;
		fscanf(fin, "%d", &turnaroundInterval);
		cout << "turnaroundInterval " << turnaroundInterval << endl;

		int na, nb;

		int * naa, * nad, * nba, * nbd;
		fscanf(fin,"%d %d", &na, &nb);
		
		nad = new int[na]; nba = new int[na];
		nbd = new int[nb]; naa = new int[nb];

		int i;
		int hh, mm, time;
		for (i=0; i<na; i++) {
			fscanf(fin, "%d:%d", &hh, &mm);
			time = hh * 60 + mm;
			nad[i] = time;
			insertionSort(nad, 0, i);

			fscanf(fin, "%d:%d", &hh, &mm);
			time = hh * 60 + mm;
			nba[i] = time;
			insertionSort(nba, 0, i);
		}
		cout << "sorted nad and nba arrays.. " << endl;
		for (i=0; i < na; i++) {
			cout << nad[i] << "\t\t\t" << nba[i] << endl;
		}

		for (i=0; i<nb; i++) {
			fscanf(fin, "%d:%d", &hh, &mm);
			time = hh * 60 + mm;
			nbd[i] = time;
			insertionSort(nbd, 0, i);

			fscanf(fin, "%d:%d", &hh, &mm);
			time = hh * 60 + mm;
			naa[i] = time;
			insertionSort(naa, 0, i);
		}
		cout << "sorted nbd and naa arrays.. " << endl;
		for (i=0; i < nb; i++) {
			cout << nbd[i] << "\t\t\t" << naa[i] << endl;
		}

		int aout = 0, bout = 0;
		int index = 0;
		for (i=0; i<na; i++) {
			if ((index >= nb) || (nad[i] < (naa[index] + turnaroundInterval))) {
				aout++;
			} else {
				index++;
			}
		}

		index=0;
		for (i=0; i<nb; i++) {
			if ((index >=na) || (nbd[i] < (nba[index] + turnaroundInterval))) {
				bout++;
			} else {
				index++;
			}
		}

		fout << "Case #" << j+1 << ": " << aout << " " << bout << endl;

	}

	fout.close();
	fclose(fin);

	return 0;
}
