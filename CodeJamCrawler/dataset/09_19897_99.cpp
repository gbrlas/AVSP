/*
 * watershed.cpp
 *
 *  Created on: 03/09/2009
 *      Author: Victor
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>

#define MAX 100
#define MOD 10000

using namespace std;

int N, H, W;
int grid[MAX + 1][MAX + 1];
int pai[MAX + 1][MAX + 1];
map<int, char> alfa;

bool valido(int x, int y) {
	return (x >= 1 && x <= H) && (y >= 1 && y <= W);
}

int getPai(int px, int py, int index) {
//	cout << ">> " << px << " " << py  << " " << index << endl;
	while ((px != index / MOD) || (py != index % MOD)) {
		px = index / MOD;
		py = index % MOD;
		index = pai[px][py];
//		cout << px << " " << py << " " << pai[px][py] << endl;
	}
//	cout << endl;
	return index;
}

void completaPai() {
	int pos[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			int menor = grid[i][j], x = i, y = j;

			for (int k = 0; k < 4; k++) {
				if (valido(i + pos[k][0], j + pos[k][1])) {
					if (grid[i + pos[k][0]][j + pos[k][1]] < menor) {
						menor = grid[i + pos[k][0]][j + pos[k][1]];
						x = i + pos[k][0];
						y = j + pos[k][1];
					}
				}
			}

			pai[i][j] = x * MOD + y;
		}
	}

//	cout << "=================================" << endl;
//	for (int i = 1; i <= H; i++) {
//		for (int j = 1; j <= W; j++) {
//			cout << pai[i][j] << ") ";
//		}
//		cout << endl;
//	}

//	cout << "=================================" << endl;
//	for (int i = 1; i <= H; i++) {
//		for (int j = 1; j <= W; j++) {
//			cout << "(" << pai[i][j] / MOD << ", " << pai[i][j] % MOD << ") ";
//		}
//		cout << endl;
//	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			pai[i][j] = getPai(i, j, pai[i][j]);
		}
	}

//	cout << "=================================" << endl;
//	for (int i = 1; i <= H; i++) {
//		for (int j = 1; j <= W; j++) {
//			cout << "(" << pai[i][j] / MOD << ", " << pai[i][j] % MOD << ") ";
//		}
//		cout << endl;
//	}
}

int main() {
	cin >> N;

	for (int caso = 1; caso <= N; caso++) {
		cin >> H >> W;

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> grid[i][j];
			}
		}

		printf("Case #%d:\n", caso);

		completaPai();
		alfa.clear();
		char ch = 'a';

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (alfa.find(pai[i][j]) == alfa.end()) {
					alfa[pai[i][j]] = ch++;
				}
				putchar(alfa[pai[i][j]]);
				if (j != W)
					putchar(' ');
			}
			putchar('\n');
		}
	}

	return (0);
}
