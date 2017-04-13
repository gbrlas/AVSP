#include <iostream>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define NORTH 'u'
#define SOUTH 'd'
#define WEST  'l'
#define EAST  'r'

using namespace std;

bool isSink(int x, int y, int **alti, int h, int w) {
	int min = alti[x][y];

	if (x-1 >= 0)
		min = MIN(min, alti[x-1][y]);
	if (x+1 < h)
		min = MIN(min, alti[x+1][y]);
	if (y-1 >= 0)
		min = MIN(min, alti[x][y-1]);
	if (y+1 < w)
		min = MIN(min, alti[x][y+1]);

	return min == alti[x][y];
}

int flood(int x, int y, int **alti, int **label, int h, int w) {
	int min  = alti[x][y];
	char dir = '.';

	if (x-1 >= 0 && alti[x-1][y] < min) {
		min = alti[x-1][y];
		dir = NORTH;
	}

	if (y-1 >= 0 && alti[x][y-1] < min) {
		min = alti[x][y-1];
		dir = WEST;
	}

	if (y+1 < w && alti[x][y+1] < min) {
		min = alti[x][y+1];
		dir = EAST;
	}

	if (x+1 < h && alti[x+1][y] < min) {
		min = alti[x+1][y];
		dir = SOUTH;
	}

	switch (dir) {
	case NORTH:
		if (label[x-1][y] != 0)
			label[x][y] = label[x-1][y];
		else
			label[x][y] = flood(x-1, y, alti, label, h, w);
		break;
	case WEST:
		if (label[x][y-1] != 0)
			label[x][y] = label[x][y-1];
		else
			label[x][y] = flood(x, y-1, alti, label, h, w);
		break;
	case EAST:
		if (label[x][y+1] != 0)
			label[x][y] = label[x][y+1];
		else
			label[x][y] = flood(x, y+1, alti, label, h, w);
		break;
	case SOUTH:
		if (label[x+1][y] != 0)
			label[x][y] = label[x+1][y];
		else
			label[x][y] = flood(x+1, y, alti, label, h, w);
		break;
	}
	return label[x][y];
}

void relabel(int **label, char **end, int h, int w, int value, char start) {
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (label[i][j] == value) {
				end[i][j] = start;
				label[i][j] = 0;
			}
}

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int h, w;
		cin >> h >> w;

		// Initialization of the arrays
		int  **alti  = new int*[h];
		int  **label = new int*[h];
		char **end   = new char*[h];
		for (int j = 0; j < h; j++) {
			alti[j]  = new int[w];
			label[j] = new int[w];
			end[j]   = new char[w];
			for (int k = 0; k < w; k++) {
				cin >> alti[j][k];
				label[j][k] = 0;
				end[j][k]   = '.';
			}
		}

		// The lookout for the sinks starts
		// Sinks will be labeled with a number in [1,+inf)
		int sinks = 0;
		for (int j = 0; j < h; j++)
			for (int k = 0; k < w; k++)
				if (isSink(j, k, alti, h, w))
					label[j][k] = ++sinks;

		// The flooding starts
		for (int j = 0; j < h; j++)
			for (int k = 0; k < w; k++)
				if (label[j][k] == 0)
					flood(j, k, alti, label, h, w);

		// Labelling time
		char start = 'a';
		for (int j = 0; j < h; j++)
			for (int k = 0; k < w; k++)
				if (label[j][k] != 0)
					relabel(label, end, h, w, label[j][k], start++);

		// Printing nicely
		cout << "Case #" << i << ":\n";
		for (int j = 0; j < h; j++)
			for (int k = 0; k < w; k++) {
				if (k != w-1)
					cout << end[j][k] << " ";
				else
					cout << end[j][k] << endl;
			}
	}
}


