#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long i64;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T sqr(const T &a) {
	return a * a;
}

int n;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ti=1; ti<=t; ++ti){
		scanf("%d", &n);
		int s = 0, f = 1000000000, sum = 0;
		for (int i=0; i<n; ++i){
			int a;
			scanf("%d", &a);
			s ^= a;
			sum += a;
			f = min(f, a);
		}
		printf("Case #%d: ", ti);
		if (s)
			printf("NO\n");
		else
			printf("%d\n", sum-f);
	}
	return 0;
}
