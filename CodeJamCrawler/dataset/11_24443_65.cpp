#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

bool solve(vector<vector<char> > & grid, int r, int c) {
	if (r < 2 || c < 2) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (grid[i][j] == '#')
					return false;
		return true;
	}

	if (c > 1)
		for (int i = 0; i < r - 1; ++i) {
			if (grid[i][c - 1] == '#') {
				if (grid[i + 1][c - 1] != '#' || grid[i][c - 2] != '#'
						|| grid[i + 1][c - 2] != '#')
					return false;
				else {
					grid[i][c - 2] = '/';
					grid[i][c - 1] = '\\';
					grid[i + 1][c - 2] = '\\';
					grid[i + 1][c - 1] = '/';
				}
			}
		}

	if (r > 1)
		for (int j = 0; j < c - 1; ++j) {
			if (grid[r - 1][j] == '#') {
				if (grid[r - 1][j + 1] != '#' || grid[r - 2][j] != '#'
						|| grid[r - 2][j + 1] != '#')
					return false;
				else {
					grid[r - 2][j] = '/';
					grid[r - 1][j] = '\\';
					grid[r - 2][j + 1] = '\\';
					grid[r - 1][j + 1] = '/';
				}
			}
		}

	return solve(grid, r - 1, c - 1);
}

int main(void) {
	string s;
	int i, j, k, t, r, c;
	vector<vector<char> > grid;
	for (i = 1, cin >> t; i <= t; ++i) {
		// Read input
		cin >> r >> c;
		grid.resize(r, vector<char> (c, '.'));
		for (j = 0; j < r; ++j)
			for (k = 0, cin >> s; k < c; ++k)
				grid[j][k] = s[k];

		// Print the result
		printf("Case #%d:\n", i);
		if (solve(grid, r, c))
			for (j = 0; j < r; ++j) {
				for (k = 0; k < c; ++k)
					printf("%c", grid[j][k]);
				printf("\n");
			}
		else
			printf("Impossible\n");
		grid.clear();
	}
}
