#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

int main () {
	// FILE * fin = fopen("e:/in.txt", "r");
	FILE * fin = fopen("e:/A-small-attempt0.in", "r");
	FILE * fout = fopen("e:/out.txt", "w");
	int nCase = 0;
	fscanf(fin, "%d", &nCase);
	for (int caseIndex = 1; caseIndex <= nCase; caseIndex++) {
		int n = 0;
		int bluePos = 1;
		int blueCost = 0;
		int orangePos = 1;
		int orangeCost = 0;
		fscanf(fin, "%d", &n);
		for (int i = 0; i < n; i++) {
			char c;
			int p;
			fscanf(fin, " %c %d", &c, &p);
			if (c == 'B') {
				blueCost = max(blueCost + abs(p - bluePos) + 1, orangeCost + 1);
				bluePos = p;
			} else {
				orangeCost = max(orangeCost + abs(p - orangePos) + 1, blueCost + 1);
				orangePos = p;
			}
		}
		fprintf(fout, "Case #%d: %d\n", caseIndex, max(orangeCost, blueCost));
	}
	return 0;	
}