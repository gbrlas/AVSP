#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

char get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y) {
	float s1_x, s1_y, s2_x, s2_y;
	s1_x = p1_x - p0_x;
	s1_y = p1_y - p0_y;
	s2_x = p3_x - p2_x;
	s2_y = p3_y - p2_y;

	float s, t;
	s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
	t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
		return 1;
	}

	return 0; // No collision
}

int main(int argc, char *argv[]) {
	ifstream in;
	if ( argc >=1 )
		in.open(argv[1]);
	else
		in.open("B-small.in");

	if (!in) {
		cout << "file open failed";
		exit(1);
	}
	
	long problems = 0;

	in >> problems;

	float a[1000], b[1000];
	int n;

	for ( long p = 1; p <= problems; p++ ) {
		in >> n;
		for ( int i = 0; i < n; i++ ) {
			in >> a[i];
			in >> b[i];
		}

		bool nc[1000][1000] = {false};

		int is = 0;

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				if ( j == i ) continue;
				if ( nc[i][j] == true || nc[j][i] == true )
					continue;
				if ( get_line_intersection(-50.0,a[i],50.0,b[i],-50.0,a[j],50.0,b[j]) ) {
					is++;
				}
				nc[i][j] = nc[j][i] = true;
			}
		}

		cout << "Case #" << p << ": " << is;
		cout << endl;
	}
}
