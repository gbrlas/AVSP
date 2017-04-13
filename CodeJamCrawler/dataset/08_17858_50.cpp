#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)

using namespace std;

int turn, Na, Nb;
vector <int> Astart, Aend, Bstart, Bend;

bool possible(int a, int b) {
	for(int time = 0; time <= 24 * 60; ++time) {
		foreach(i, 0, Aend)
			if(Aend[i] + turn == time)
				++b;
		foreach(i, 0, Bend)
			if(Bend[i] + turn == time)
				++a;
		foreach(i, 0, Astart)
			if(Astart[i] == time)
				--a;
		foreach(i, 0, Bstart)
			if(Bstart[i] == time)
				--b;
		if(a < 0 || b < 0)
			return false;
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		scanf("%d%d%d", &turn, &Na, &Nb);
		Astart.resize(Na);
		Aend.resize(Na);
		Bstart.resize(Nb);
		Bend.resize(Nb);
		for(int i = 0; i < Na; ++i) {
			int a, b;
			scanf("%d:%d", &a, &b);
			Astart[i] = 60 * a + b;
			scanf("%d:%d", &a, &b);
			Aend[i] = 60 * a + b;
		}
		for(int i = 0; i < Nb; ++i) {
			int a, b;
			scanf("%d:%d", &a, &b);
			Bstart[i] = 60 * a + b;
			scanf("%d:%d", &a, &b);
			Bend[i] = 60 * a + b;
		}
		for(int a = 0; a <= Na; ++a)
			for(int b = 0; b <= Nb; ++b) {
				if(!possible(a, b))
					continue;
				printf("Case #%d: %d %d\n", t + 1, a, b);
				goto next;
			}
		next:;
	}
	return 0;
}
