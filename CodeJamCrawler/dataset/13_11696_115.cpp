#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

int main()
{
	int testSize;

	scanf("%d", &testSize);

	for(int testCaseNum = 0; testCaseNum < testSize; ++testCaseNum) {

		int h, w;
		vector<pair<int, pair<int, int> > > as;
		vector<int> xc, yc;
		bool yes = true;

		scanf("%d%d", &h, &w);
		as.reserve(h * w);
		xc.resize(w); yc.resize(h);
		for(int y = 0; y < h; ++y) {
			for(int x = 0; x < w; ++x) {
				int t;
				scanf("%d", &t);
				as.push_back(make_pair(t, make_pair(x, y)));
			}
		}

		sort(as.begin(), as.end());

		for(int lit = 0; lit < h * w;) {

			int rit = lit + 1;
			while(rit < h * w && as[lit].first == as[rit].first)
				rit += 1;

			for(int i = lit; i < rit; ++i) {
				int x = as[i].second.first;
				int y = as[i].second.second;
				xc[x] += 1;
				yc[y] += 1;
			}

			for(int i = lit; i < rit; ++i) {
				int x = as[i].second.first;
				int y = as[i].second.second;
				if(xc[x] != h && yc[y] != w)
					yes = false;
			}

			lit = rit;
		}

		printf("Case #%d: %s\n", testCaseNum + 1, yes ? "YES" : "NO");
	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
