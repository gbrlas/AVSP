#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string tic(vector<string>& v) {
	int numO, numX;
	bool complete = true;
	for (int y = 0; y < 6; y++) {
		numO = numX = 0;
		for (int x = 0; x < 4; x++) {
			char c; 
			if ( y < 4 )
				c = v[y][x];
			else if (y == 4) 
				c = v[x][x];
			else 
				c = v[3-x][x];
			if (c == 'O') numO++;
			else if (c == 'X') numX++;
			else if (c == 'T') { numO++; numX++;}
			else if (c == '.') complete = false;
		}
		if (numO == 4 || numX == 4) 
			break;
	}
	if (numO < 4 && numX < 4) {
		for (int x = 0; x < 4; x++) {
			numO = numX = 0;
			for (int y = 0; y < 4; y++) {
				char c = v[y][x];
				if (c == 'O') numO++;
				else if (c == 'X') numX++;
				else if (c == 'T') { numO++; numX++;}			
			}
			if (numO == 4 || numX == 4) 
				break;
		}
	
	} 
	if (numO == 4) 
		return "O won";
	else if (numX == 4) 
		return "X won";
	else if (complete)
		return "Draw";
	return "Game has not completed";
}

void solve(void) {
	ifstream f("data.txt");
	string line;
	getline(f, line);
	int n = atoi(line.c_str());
	
	ofstream f2("out.txt");
	
	for (int i = 0; i < n; ++i) {
		vector<string> v(4);
		getline(f, v[0]);
		getline(f, v[1]);
		getline(f, v[2]);
		getline(f, v[3]);
		f2 << "Case #" << i+1 << ": " << tic(v) << endl; 
		getline(f, line);
	}
	
	f.close();
	f2.close();
}

int main() {
	solve();
	return 0;
}
