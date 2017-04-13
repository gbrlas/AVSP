#include <fstream>

using namespace std;

bool is_sink(int **map, int h, int w, int x, int y) {
	int altitude = map[x][y];
	bool north, south, east, west;
	if (x == 0 || map[x - 1][y] >= altitude)
		north = true;
	else
		north = false;
	if (x == h - 1 || map[x + 1][y] >= altitude)
		south = true;
	else
		south = false;
	if (y == 0 || map[x][y - 1] >= altitude)
		west = true;
	else
		west = false;
	if (y == w - 1 || map[x][y + 1] >= altitude)
		east = true;
	else
		east = false;
	return north && south && west && east;
}

char label_cell(int **map, char **label, int h, int w, int x, int y) {
	if (label[x][y] != -1)
		return label[x][y];
	else {
		int lowest = 10000;
		int dx, dy;
		if (x != 0 && map[x - 1][y] < lowest) {
			lowest = map[x - 1][y];
			dx = -1;
			dy = 0;
		}
		if (y != 0 && map[x][y - 1] < lowest) {
			lowest = map[x][y - 1];
			dx = 0;
			dy = -1;
		}
		if (y != w - 1 && map[x][y + 1] < lowest) {
			lowest = map[x][y + 1];
			dx = 0;
			dy = 1;
		}
		if (x != h - 1 && map[x + 1][y] < lowest) {
			lowest = map[x + 1][y];
			dx = 1;
			dy = 0;
		}
		label[x][y] = label_cell(map, label, h, w, x + dx, y + dy);
		return label[x][y];
	}
}

int main() {
	ifstream in("B-large.in");
	ofstream out("B-large.out");
	
	int T, H, W;
	in >> T;
	for (int i = 0; i < T; i++) {
		in >> H >> W;
		int u, v, x, y;
		char lab = 'A';
		char reallab = 'a';
		int **map = new int*[H];
		char **label = new char*[H];
		for (u = 0; u < H; u++) {
			map[u] = new int[W];
			label[u] = new char[W];
			for (v = 0; v < W; v++) {
				in >> map[u][v];
				label[u][v] = -1;
			}
		}
		for (u = 0; u < H; u++)
			for (v = 0; v < W; v++)
				if (is_sink(map, H, W, u, v)) {
					label[u][v] = lab;
					lab++;
				}
		for (u = 0; u < H; u++)
			for (v = 0; v < W; v++)
				label_cell(map, label, H, W, u, v);
		
		for (u = 0; u < H; u++)
			for (v = 0; v < W; v++) {
				if (label[u][v] >= 'A' && label[u][v] <= 'Z') {
					char origin = label[u][v];
					for (x = 0; x < H; x++)
						for (y = 0; y < W; y++)
							if (label[x][y] == origin)
								label[x][y] = reallab;
					reallab++;
				}
			}
			
		out << "Case #" << i + 1 << ": " << endl;
		for (u = 0; u < H; u++) {
			for (v = 0; v < W; v++)
				out << label[u][v] << " ";
			out << endl;
		}
	}
	
	return 0;
}
