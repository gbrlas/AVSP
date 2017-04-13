#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi; 
typedef vector<string> vs;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define rep(i, n) for(int i = 0; i < n; ++i) 
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it) 
#define INT_INF 0x7FFFFFFF 

int certo(pair<long long,long long> a, pair<long long,long long> b, pair<long long,long long> c ) {
	if ((a.first+b.first+c.first)%3 == 0 && (a.second+b.second+c.second)%3 == 0) {
		return 1;
	}
	else
		return 0;
}

main() {
	int N;
	scanf("%d", &N);
	
	rep(asd,N) {
		int n;
		scanf("%d", &n);
		
		vector<pair<long long, long long> > v(n);
		long long A;
		long long B;
		long long C;
		long long D;
		long long M;
		long long X; 
		long long Y;
		long long x0;
		long long y0;
		
		scanf("%lld %lld %lld %lld %lld %lld %lld", &A, &B, &C, &D, &x0, &y0, &M);
		X = x0;
		Y = y0;
		v[0].first = x0;
		v[0].second = y0;
		//printf("n = %d\n", n);
		//printf("%d %d\n", x0, y0);
		for(long long k = 1;  k < n ;k++) {
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			v[k].first = X;
			v[k].second = Y;
			//printf("%d %d\n", X, Y);
		}
		long long qt = 0;
		for( long long i = 0; i < n; i++) {
			for(long long j = i+1; j < n ; j++) {
				for(long long k = j+1; k < n ; k++) {
					if(certo(v[i],v[j],v[k])) {
						qt++;
					}
				}
			}
		}
		printf("Case #%d: %d\n", asd+1, qt);
	}
}	
