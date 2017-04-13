//============================================================================
// Name        : Watersheds.cpp
// Author      : Thomasan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_ALTITUEDE 10000

using namespace std;

int token = 0;

class Label{
	int H, W;
	char **label;
public:
	void print() {
		for (int h = 1; h < H-1; h++) {
			for (int w = 1; w < W-1; w++) {
				cout << label[h][w] << " ";
			}
			cout << endl;
		}
	}

	Label(int h, int w) :
		H(h), W(w) {
		label = new char*[H];
		for (int j = 0; j < H; j++) {
			label[j] = new char[W];
		}
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				label[h][w] = '\0';
			}
		}
	}
	~Label() {
		for (int j = 0; j < H; j++) {
			if(label[j])
				delete[] label[j];
		}
		delete[] label;
	}

	char* operator [](int i) {
		return label[i];
	}
};

class Map {
	int H, W;
	int **map;
public:
	int get_h(){
		return H;
	}

	int get_w(){
		return W;
	}

	void print() {
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				cout << map[h][w] << " ";
			}
			cout << endl;
		}
	}

	Map(int h, int w) :
		H(h), W(w) {
		map = new int*[H];
		for (int j = 0; j < H; j++) {
			map[j] = new int[W];
		}
	}
	~Map() {
		for (int j = 0; j < H; j++) {
			if (map[j])
				delete[] map[j];
		}
		delete[] map;
	}

	int* operator [](int i) {
		return map[i];
	}

};

char process(Map &map, Label &label, int h, int w){
	if(label[h][w]!='\0')
		return label[h][w];

	int i = h;
	int j = w;
	if(map[h-1][w]<map[h][w])
		i = h-1;
	if(map[h][w-1]<map[i][j]){
		i = h;
		j = w-1;
	}
	if(map[h][w+1]<map[i][j]){
		i = h;
		j = w+1;
	}
	if(map[h+1][w]<map[i][j]){
		i = h+1;
		j = w;
	}
	if(i==h && j==w ){
		label[h][w] = token + 'a';
		token++;
		return label[h][w];
	}
	label[h][w] = process(map, label, i, j);
	return label[h][w];
}

int main() {
	ifstream in("B-large.in");
	string line;
	getline(in, line);
	istringstream iss(line);
	int N;
	iss >> N;
	int H, W;
	for (int i = 0; i < N; i++) {
		token = 0;
		getline(in, line);
		iss.clear();
		iss.str(line);
		iss >> H >> W;
		Map map(H + 2, W + 2);
		Label label(H+2, W+2);
		for (int h = 0; h < H + 2; h++) {
			if (h != 0 && h != H + 1) {
				getline(in, line);
				iss.clear();
				iss.str(line);
			}
			for (int w = 0; w < W + 2; w++) {
				if (h == 0 || h == H + 1 || w == 0 || w == W + 1) {
					map[h][w] = MAX_ALTITUEDE;
					continue;
				}
				if (h != 0 && h != H + 1 && w!=0 && w!=W+1) {
					iss >> map[h][w];
				}
			}
		}

		for(int k=1; k<=H; k++){
			for (int j=1; j<=W; j++){
				process(map, label, k, j);
			}
		}
		cout << "Case #" << i + 1 << ":" << endl;
//		map.print();
		label.print();


	}
	return 0;
}
