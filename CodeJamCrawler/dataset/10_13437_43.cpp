#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void snapper(int t, int n, long k);

int main(int argc, char *argv[]) {
	ifstream in;
	if ( argc >=1 )
		in.open(argv[1]);
	else
		in.open("A-small.in");

	if (!in) {
		cout << "file open failed";
		exit(1);
	}
	
	int problems = 0;

	in >> problems;

	int n, k;

	for ( int i = 1; i <= problems; i++ ) {
		in >> n;
		in >> k;
		snapper(i,n,k);
	}
}

void snapper(int t, int n, long k) {
	int state = 1;
	int states[n];
	for ( int nn = 0; nn < n; nn++ ) states[nn] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++ ) {
			if ( states[j] == 0 ) {
				states[j] = 1;
				break;
			} else {
				states[j] = 0;
			}
		}
	}

	for (int j = 0; j < n; j++ ) {
		if ( states[j] == 0 ) {
			state = 0;
			break;
		}
	}

	if ( state == 1 )
		printf("Case #%d: ON\n", t);
	else
		printf("Case #%d: OFF\n", t);
}
