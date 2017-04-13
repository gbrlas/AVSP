#include <assert.h>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": " << endl;
		int		R, C;
		cin		>> R >> C;
		assert (R > 0 && C > 0);
		string	oneline;
		vector< vector<int> > tiles (R+1);
		for (int i=0; i<R; i++) {
			tiles[i].resize(C+1, 0);
			cin >> oneline;
			assert(oneline.length() == C);
			for (int j=0; j<C; j++) {
				if (oneline[j] == '#')
					tiles[i][j] = 1;
				else
					assert (oneline[j] == '.');
			}
		}
		tiles[R].resize(C+1, 0);

		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (tiles[i][j] == 1) {
					if (tiles[i][j+1] == 1 && tiles[i+1][j] == 1 && tiles[i+1][j+1] == 1) {
						tiles[i][j] = tiles[i+1][j+1] = 2;
						tiles[i][j+1] = tiles[i+1][j] = 3;
					} else {
						cout << "Impossible" << endl;
						goto nextcase;
					}
				}
			}
		}

		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				switch(tiles[i][j]) {
				case 0:
					cout << ".";
					break;
				case 2:
					cout << "/";
					break;
				case 3:
					cout << "\\";
					break;
				}
			}
			cout << endl;
		}
nextcase:
		;
	}
}
