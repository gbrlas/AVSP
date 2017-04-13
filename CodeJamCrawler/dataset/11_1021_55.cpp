#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define FORD(i,a,b) for(int i=a,_b=b;i>=b;i--)
#define REPD(i,a) FORD(i,a-1,0)
#define ALL(x) (x).begin(),(x).end()
#define ABS(x) (x<0?-x:x)
#define _m(a,b) memset(a,b,sizeof(a))
#define LL long long
#define st first
#define nd second

typedef pair<int,int> PII;
typedef pair<int,string> PIS;

int C, D;
map<int,int> M;
map<int,int>::iterator Miter;

bool check(double time) {
	double last = -2000000000000.0;
	double pos;
	int num;
	double dist;
	
	for(Miter = M.begin(); Miter != M.end(); Miter++) {
		pos = (double)Miter->st;
		num = Miter->nd;
		
		REP(i, num) {
			dist = (pos - (last + D));
			
			if(dist > 0) {
				last = pos - min(dist, time);
			} else {
				if(-dist > time) return false;
				last = pos - dist;
			}
		}
	}
	
	return true;
}

void run(int testcaseNumber) {
	int P, V;

	scanf("%d %d", &C, &D);
	M.clear();
	REP(i, C) { scanf("%d %d", &P, &V); M[P] += V; }
	
	double low = 0, high = 1000000000000.0, mid, midok;
	while(low <= high) {
		mid = (low + high) / 2.0;
		
		if(check(mid)) {
			high = mid - 1e-12;
			midok = mid;
		} else {
			low = mid + 1e-12;
		}
	}
	
	printf("Case #%d: %.1lf\n", testcaseNumber, midok);
}

int main(void) {
	int T; scanf("%d", &T); REP(i, T) run(i + 1);
	return 0;
}
