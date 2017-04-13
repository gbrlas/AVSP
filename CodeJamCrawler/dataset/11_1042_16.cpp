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
#define _m(a,b) memset(a,b,sizeof(a))
#define LL long long
#define st first
#define nd second

typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef pair<int,string> PIS;

#define MAX 1000
#define LENGTH 1001000

int X, S, R, T, N;
PIII E[MAX];
PII RE[MAX];

void add(int a, int b, int s) {
	E[N].st.st = a;
	E[N].st.nd = b;
	E[N].nd = s;
	N++;
}

double count() {
	double t = 0.0, temp;
	double leftt, leftx;
	double res = 0.0;
	
	REP(i, N) {
		RE[i].st = E[i].nd;
		RE[i].nd = E[i].st.nd - E[i].st.st;
	}
	
	sort(RE, RE+N);
	
	REP(i, N) {
		if(t < (double)T) {
			temp = (double)RE[i].nd / (double)(RE[i].st - S + R);
			if(t + temp < (double)T) {
				t += temp;
				res += temp;
			} else {
				leftt = (double)T - t;
				res += leftt;
				leftx = (double)RE[i].nd - (leftt * (RE[i].st - S + R));
				res += (double)leftx / (double)RE[i].st;
				t = (double)T;
			}
		} else {
			res += (double)RE[i].nd / (double)RE[i].st;
		}
	}
	
	return res;
}

void run(int testcaseNumber) {
	double res = 0.0;
	double t = 0.0, temp;
	scanf("%d %d %d %d %d", &X, &S, &R, &T, &N);
	REP(i, N) {
		scanf("%d %d %d", &E[i].st.st, &E[i].st.nd, &E[i].nd);
		E[i].nd += S;
	}
	sort(E, E+N);
	
	for(int i=N-1; i>=0; i--) {
		if(i == 0) {
			if(E[i].st.st != 0)
				add(0, E[i].st.st, S);
		}
		
		if(i == N-1) {
			if(E[i].st.nd < X)
				add(E[i].st.nd, X, S);
		}
		
		if(i > 0) {
			if(E[i].st.st != E[i-1].st.nd)
				add(E[i-1].st.nd, E[i].st.st, S);
		}
	}
		
	sort(E, E+N);
	REP(i, N) E[i].nd = max(E[i].nd, S);
	
	if(E[N-1].st.nd > X) {
		E[N].st.st = X;
		E[N].st.nd = E[N-1].st.nd;
		E[N].nd = S;
		N++;
		res = count();
		N-=2;
		E[N].st.st = E[N-1].st.nd;
		E[N].st.nd = X;
		E[N].nd = S;
		N++;
		res = min(res, count());
	} else {
		res = count();
	}
	
	printf("Case #%d: %.6lf\n", testcaseNumber, res + 5e-7);
}

int main(void) {
	int T; scanf("%d", &T); REP(i, T) run(i + 1);
	return 0;
}
