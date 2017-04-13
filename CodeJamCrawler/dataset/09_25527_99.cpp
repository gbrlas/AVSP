#include <algorithm>
#include <cstdio>

using namespace std;

int T, R, C;
int grid [100] [100];
bool drain [100] [100] [4];
char at;
char chr [100] [100];
bool visited [100] [100];

void floodfill (int r, int c) {
	if (visited [r] [c]) {
		return;
	}
	visited [r] [c] = true;
	chr [r] [c] = at;
	if (drain [r] [c] [0]) {
		floodfill (r - 1, c);
	}
	if (drain [r] [c] [1]) {
		floodfill (r, c - 1);
	}
	if (drain [r] [c] [2]) {
		floodfill (r + 1, c);
	}
	if (drain [r] [c] [3]) {
		floodfill (r, c + 1);
	}
	visited [r] [c] = false;
}

int main () {
	
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
	
	scanf ("%d", &T);
	
	for (int t = 0; t < T; t ++) {
		
		scanf ("%d%d", &R, &C);
		for (int r = 0; r < R; r ++) {
			for (int c = 0; c < C; c ++) {
				scanf ("%d", &grid [r] [c]);
				chr [r] [c] = 0;
				visited [r] [c] = false;
				fill (drain [r] [c], drain [r] [c] + 4, false);
			}
		}
		
		for (int r = 0; r < R; r ++) {
			for (int c = 0; c < C; c ++) {
				int low = 999999999;
				int tmp;
				if (r - 1 >= 0) {
					if (grid [r] [c] > grid [r - 1] [c]) {
						if (grid [r - 1] [c] < low) {
							low = grid [r - 1] [c];
							tmp = 0; 
						}
					}
				}
				if (c - 1 >= 0) {
					if (grid [r] [c] > grid [r] [c - 1]) {
						if (grid [r] [c - 1] < low) {
							low = grid [r] [c - 1];
							tmp = 1; 
						}
					}
				}
				if (c + 1 < C) {
					if (grid [r] [c] > grid [r] [c + 1]) {
						if (grid [r] [c + 1] < low) {
							low = grid [r] [c + 1];
							tmp = 3; 
						}
					}
				}
				if (r + 1 < R) {
					if (grid [r] [c] > grid [r + 1] [c]) {
						if (grid [r + 1] [c] < low) {
							low = grid [r + 1] [c];
							tmp = 2; 
						}
					}
				}
				if (low < 999999999) {
					drain [r] [c] [tmp] = true;
					if (tmp == 0) {
						drain [r - 1] [c] [2] = true;
					}
					if (tmp == 1) {
						drain [r] [c - 1] [3] = true;
					}
					if (tmp == 2) {
						drain [r + 1] [c] [0] = true;
					}
					if (tmp == 3) {
						drain [r] [c + 1] [1] = true;
					}
				}
			}
		}
		
		at = 'a';
		
		for (int r = 0; r < R; r ++) {
			for (int c = 0; c < C; c ++) {
				if (chr [r] [c] == 0) {
					floodfill (r, c);
					at ++;
				}
			}
		}
		
		printf ("Case #%d:\n", t + 1);
		for (int r = 0; r < R; r ++) {
			for (int c = 0; c < C; c ++) {
				printf ("%c ", chr [r] [c]);
			}
			printf ("\n");
		}
	}
	
	return 0;
}
