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

#define MAX_WIDTH  100
#define MAX_HEIGHT 100
#define MAX_ELEM   MAX_WIDTH * MAX_HEIGHT

int width  = 0;
int height = 0;


int att[MAX_HEIGHT][MAX_WIDTH] = { 0 };
int root[MAX_ELEM] = { 0 };

int getRoot (int t)
{
	if (root[t] < 0) {
		return t;
	} else {
		return root[t] = getRoot(root[t]);
	}
}

int main ()
{
	int N = 0;
	scanf ("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf ("%d %d", &height, &width);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				scanf ("%d", &att[y][x]);
				root[y * MAX_WIDTH + x] = -1;
			}
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int direction = 0;
				int minValue = att[y][x];
				if (y > 0 && att[y-1][x] < minValue) {
					minValue = att[y-1][x];
					direction = 1;
				}
				if (x > 0 && att[y][x-1] < minValue) {
					minValue = att[y][x-1];
					direction = 2;
				}
				if (x + 1 < width && att[y][x+1] < minValue) {
					minValue = att[y][x+1];
					direction = 3;
				}
				if (y + 1 < height && att[y+1][x] < minValue) {
					minValue = att[y+1][x];
					direction = 4;
				}
				switch (direction) {
					case 1:
						root[y * MAX_WIDTH + x] = getRoot ((y-1) * MAX_WIDTH + x);
						break;
					case 2:
						root[y * MAX_WIDTH + x] = getRoot (y * MAX_WIDTH + x - 1);
						break;
					case 3:
						root[y * MAX_WIDTH + x] = getRoot (y * MAX_WIDTH + x + 1);
						break;
					case 4:
						root[y * MAX_WIDTH + x] = getRoot ((y+1) * MAX_WIDTH + x);
						break;
				}
			}
		}

		printf ("Case #%d:\n", n+1);

		char mark = 'a';
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int r = getRoot(y * MAX_WIDTH + x);
				if (root[r] == -1) {
					root[r] = -mark;
					mark++;
				}
				printf ("%c ", (char)(-root[r]));
			}
			printf ("\n");
		}
	}
	return 0;
}