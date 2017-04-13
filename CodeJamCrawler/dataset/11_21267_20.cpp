/*
 * QA.cpp
 *
 *  Created on: 2011-5-7
 *      Author: Administrator
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-out.out");

char R[100];
int P[100];
void Solve(int cn) {
	int N, i; int pB = 1, pO = 1, BT = 0, OT = 0;
	//char R[100];
	int ans;
	fin >> N;
//	cerr << "N = " << N << endl;
	for(i=0; i<N; i++) {
		fin >> R[i];
		fin >> P[i];
//		cerr << "Ri = " << R[i] << endl;
//		cerr << "Pi = " << P[i] << endl;

	}
	for(i=0; i<N; i++) {
		char cur = R[i]; int p = P[i]; int add;
		if(cur == 'O') {
			add = abs(p - pO); pO = p; OT += add;
			OT = (OT < BT)? BT+1: OT +1;
		}
		else {
			add = abs(p - pB); pB = p; BT += add;
			BT = (BT < OT)? OT+1: BT+1;
		}
//		cerr << "OT = " << OT << endl;
//		cerr << "BT = " << BT << endl;
	}

	if(BT > OT) ans = BT;
	else ans = OT;
	fout << "Case #" << cn+1 << ": " << ans << endl;
//	cerr << "Case #" << cn+1 << ": " << ans << endl;
}

int main() {

	int CASES, i;
	fin >> CASES;
	for(i=0; i<CASES; i++) Solve(i);
    return 0;
}
