#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

int main () {
	// FILE * fin = fopen("e:/in.txt", "r");
	FILE * fin = fopen("e:/C-small-attempt0.in", "r");
	FILE * fout = fopen("e:/out.txt", "w");
	int nCase = 0;
	fscanf(fin, "%d", &nCase);
	for (int caseIndex = 1; caseIndex <= nCase; caseIndex++) {
		int n = 0;
		int minValue = 1<<30;
		int sum = 0;
		int current = 0;
		fscanf(fin, "%d", &n);
		for (int i = 0; i < n; i++) {
			int t = 0;
			fscanf(fin, "%d", &t);
			minValue = min(minValue, t);
			sum += t;
			current = current ^ t;
		}
		if (current == 0) {
			fprintf(fout, "Case #%d: %d\n", caseIndex, sum - minValue);
		} else {
			fprintf(fout, "Case #%d: NO\n", caseIndex);
		}
	}
	return 0;	
}