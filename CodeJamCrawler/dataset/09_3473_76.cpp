#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdlib.h>

// Compile with 'g++ gcj2.cc -O2 -o gcj2.exe'
//
// I won't be getting disqualified for speed again ...

using namespace std;

enum CellType {
	NONE,
	SINK,
	UP,
	RIGHT,
	DOWN,
	LEFT
};

typedef vector<vector<int> > Map;
typedef map<int, char> Record;

int get_maps(ifstream &f) {
	int foo;
	f >> foo;
	return foo;
}

Map get_map(ifstream &f) {
	Map result;

	int x, y;
	f >> y;
	f >> x;

	for (int yy = 0; yy < y; yy++) {
		vector<int> xv;
		for (int xx = 0; xx < x; xx++) {
			int c;
			f >> c;
			xv.push_back(c);
		}
		result.push_back(xv);
	}

	return result;
}

int mark_map_cell(Map &m, int x, int y) {
	int ys = m.size(), xs = m[0].size();
	int this_cell = m[y][x];
	int mark = SINK;
	// N, W, E, S
	if (y < ys-1) {
		if (m[y+1][x] <= this_cell) {
			mark = DOWN;
			this_cell = m[y+1][x];
		}
	}
	if (x < xs-1) {
		if (m[y][x+1] <= this_cell) {
			mark = RIGHT;
			this_cell = m[y][x+1];
		}
	}
	if (x > 0) {
		if (m[y][x-1] <= this_cell) {
			mark = LEFT;
			this_cell = m[y][x-1];
		}
	}
	if (y > 0) {
		if (m[y-1][x] <= this_cell) {
			mark = UP;
			this_cell = m[y-1][x];
		}
	}

	// Wee!
	if (this_cell == m[y][x]) mark = SINK;

	return mark;
}

Map mark_map(Map &m) {
	Map r = m;

	int y = m.size();
	int x = m[0].size();

	for (int yy = 0; yy < y; yy++) {
		for (int xx = 0; xx < x; xx++) {
			r[yy][xx] = mark_map_cell(m, xx, yy);
		}
	}

	return r;
}

int cell_sink(Map &m, int x, int y) {
	if (m[y][x] == SINK) return (x << 16) | y;

	while (1) {
		switch (m[y][x]) {
		case UP:
			y--;
			break;
		case RIGHT:
			x++;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case SINK:
			return (x << 16) | y;
		}
	}
}

void emit_cell(Map &m, int x, int y, Record &r, int &c) {
	int sink = cell_sink(m, x, y);
	if (r[sink] == 0) {
		r[sink] = 'a' + c++;
	}

	string ch = " ";
	ch[0] = r[sink];
	cout << ch;
}

void emit_map(Map &g) {
	Record sink_record;
	int c = 0;

	int y = g.size();
	int x = g[0].size();

	for (int yy = 0; yy < y; yy++) {
		for (int xx = 0; xx < x; xx++) {
			emit_cell(g, xx, yy, sink_record, c);

			if (xx < x - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main(int argc, char **argv) {
	ifstream f(argv[1]);

	int m = get_maps(f);

	for (int i = 0; i < m; i++) {
		Map g = get_map(f);

		Map mg = mark_map(g);

		cout << "Case #" << i + 1 << ":" << endl;
		emit_map(mg);
	}
}
