#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <numeric>
#include <sstream>
#include <queue>

using namespace std;

#define MAX_WIDTH  20
#define MAX_HEIGHT 20
#define MAX_ELEM   MAX_WIDTH * MAX_HEIGHT

int width  = 0;
int height = 0;

int t[MAX_HEIGHT][MAX_WIDTH];
int h[MAX_HEIGHT][MAX_WIDTH];
int v[MAX_HEIGHT][MAX_WIDTH];

int c[MAX_HEIGHT][MAX_WIDTH][4];

void input ()
{
	scanf ("%d %d", &height, &width);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			scanf ("%d %d %d", &h[y][x], &v[y][x], &t[y][x]);
			while (t[y][x] > 0) {
				t[y][x] -= (h[y][x] + v[y][x]);
			}
		}
	}
}

bool isGreenV (int x, int y, int tick)
{
	return ( (tick - t[y][x]) % (h[y][x] + v[y][x]) ) < h[y][x];
}

bool isGreenH (int x, int y, int tick)
{
	return ( (tick - t[y][x]) % (h[y][x] + v[y][x]) ) >= h[y][x];
}

int f ()
{
	int current = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int k = 0; k < 4; k++) {
				c[y][x][k] = -1;
			}
		}
	}
	c[height-1][0][2] = 0;
	while (1) {
		current++;
		if (c[0][width - 1][0] > 0) {
			return c[0][width - 1][0];
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				// handle 0
				int cost = 0;
				int best = INT_MAX;

				if (x < width - 1) {
					if (c[y][x+1][3] >= 0) {
						cost = c[y][x+1][3] + 2;
						best = min (best, cost);
					}
				}
				if (y > 0) {
					if (c[y-1][x][1] >= 0) {
						cost = c[y-1][x][1] + 2;
						best = min (best, cost);
					}
				}
				if (c[y][x][3] >= 0 && isGreenH(x, y, current-1)) {
					cost = c[y][x][3] + 1;
					best = min (best, cost);
				}
				if (c[y][x][1] >= 0 && isGreenV(x, y, current-1)) {
					cost = c[y][x][1] + 1;
					best = min (best, cost);
				}
				if (best != INT_MAX && best <= current && c[y][x][0] == -1) {
					c[y][x][0] = current;
				}

				// handle 1
				cost = 0;
				best = INT_MAX;

				if (x < width - 1) {
					if (c[y][x+1][2] >= 0) {
						cost = c[y][x+1][2] + 2;
						best = min (best, cost);
					}
				}
				if (y < height - 1) {
					if (c[y+1][x][0] >= 0) {
						cost = c[y+1][x][0] + 2;
						best = min (best, cost);
					}
				}
				if (c[y][x][2] >= 0 && isGreenH(x, y, current-1)) {
					cost = c[y][x][2] + 1;
					best = min (best, cost);
				}
				if (c[y][x][0] >= 0 && isGreenV(x, y, current-1)) {
					cost = c[y][x][0] + 1;
					best = min (best, cost);
				}
				if (best != INT_MAX && best <= current && c[y][x][1] == -1) {
					c[y][x][1] = current;
				}

				// handle 2
				cost = 0;
				best = INT_MAX;

				if (x > 0) {
					if (c[y][x-1][1] >= 0) {
						cost = c[y][x-1][1] + 2;
						best = min (best, cost);
					}
				}
				if (y < height - 1) {
					if (c[y+1][x][3] >= 0) {
						cost = c[y+1][x][3] + 2;
						best = min (best, cost);
					}
				}
				if (c[y][x][1] >= 0 && isGreenH(x, y, current-1)) {
					cost = c[y][x][1] + 1;
					best = min (best, cost);
				}
				if (c[y][x][3] >= 0 && isGreenV(x, y, current-1)) {
					cost = c[y][x][3] + 1;
					best = min (best, cost);
				}
				if (best != INT_MAX && best <= current && c[y][x][2] == -1) {
					c[y][x][2] = current;
				}

				// handle 3
				cost = 0;
				best = INT_MAX;

				if (x > 0) {
					if (c[y][x-1][0] >= 0) {
						cost = c[y][x-1][0] + 2;
						best = min (best, cost);
					}
				}
				if (y > 0) {
					if (c[y-1][x][2] >= 0) {
						cost = c[y-1][x][2] + 2;
						best = min (best, cost);
					}
				}
				if (c[y][x][0] >= 0 && isGreenH(x, y, current-1)) {
					cost = c[y][x][0] + 1;
					best = min (best, cost);
				}
				if (c[y][x][2] >= 0 && isGreenV(x, y, current-1)) {
					cost = c[y][x][2] + 1;
					best = min (best, cost);
				}
				if (best != INT_MAX && best <= current && c[y][x][3] == -1) {
					c[y][x][3] = current;
				}
			}
		}
	}
}

int main ()
{
	int N = 0;
	scanf ("%d", &N);
	for (int n = 0; n < N; n++) {
		input ();
		int res = f ();
		printf ("Case #%d: %d\n", n + 1, res);
	}
	return 0;
}