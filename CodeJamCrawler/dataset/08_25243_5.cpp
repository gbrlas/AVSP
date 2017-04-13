//============================================================================
// Name        : google1.cpp
// Author      : Joey Allcock
//============================================================================

#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

struct road {
	string from;
	string to;
	int cost;
};

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);

	int t;
	vector<road> roads;
	vector<string> journey;

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		int n, i, j;
		string c;
		scanf("%d %s", &n, c);
		journey.push_back(c);
		roads.resize(n);
		for (i = 0; i < n; i++) {
			scanf("%s %s %d", roads[i].from, roads[i].to, roads[i].cost);
		}

		cout << "Case #" << test << ": " << roads[0].from << endl;
		roads.clear();
		journey.clear();
	}

	return 0;
}
