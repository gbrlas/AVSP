#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int TTT; cin >> TTT;
	for (int ZZZ=1;ZZZ<=TTT;ZZZ++) {
		int R, C;
		cin >> R >> C;
		
		char matx[50][50];
		for (int i=0; i < R; i++) {
			for (int j=0; j < C; j++) {
				char n;
				cin >> n;
				matx[i][j] = n;
			}
		}
		bool possible = true;
		for (int i=0; i < R; i++) {
			for (int j=0; j < C; j++) {
				if (matx[i][j] == '#') {
					if (i < R-1 && j < C-1 && matx[i+1][j] == '#' && matx[i][j+1] == '#' && matx[i+1][j+1] == '#') {
						matx[i][j] = '/';
						matx[i+1][j] = '\\';
						matx[i][j+1] = '\\';
						matx[i+1][j+1] = '/';
					} else {
						possible = false;
					}
				}
			}
		}
		
		if (!possible) {
			cout << "Case #" << ZZZ << ":" << endl << "Impossible" <<  endl;
		} else {
			cout << "Case #" << ZZZ << ":" << endl;
			for (int i=0; i < R; i++) {
				for (int j=0; j < C; j++) {
					cout << matx[i][j];
				}
				cout << endl;
			}
		}
	}
}