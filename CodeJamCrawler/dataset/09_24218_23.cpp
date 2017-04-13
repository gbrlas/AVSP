#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define QMAX 105

int t;
int P, Q;
int in[QMAX];
int rez = 0;
bool m[QMAX];

int points(int pos) {
	int ret = 0;
	for (int i=pos-1; i>0; i--) {
		if (m[i]==true) break;
		ret++;
	}
	for (int i=pos+1; i<=P; i++) {
		if (m[i]==true) break;
		ret++;
	}
	return ret;
}

void go(int srez) {
	bool flag = false;
	for (int i=0; i<Q; i++) {
		if (m[in[i]]==false) {
			flag = true;
			m[in[i]] = true;
			go(srez+points(in[i]));
			m[in[i]] = false;
		}
	}
	if (flag==false) rez = min(rez, srez);
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &t);
	for (int k=0; k<t; k++) {
		scanf("%d%d", &P, &Q);
		for (int i=0; i<Q; i++) scanf("%d", &in[i]);
		memset(m, 0, sizeof(m));
		rez = 1<<30;
		go(0);
		printf("Case #%d: %d\n", k+1, rez);
	}
	return 0;
}