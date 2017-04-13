#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <map>
#define DEBUG 0
using namespace std;

int N,M;
int n,m;
int i,j,k;
int T,t;

#define PII pair<int, int>
#define DD first //Pos
#define LL second //Len
#define HH first //Height
#define II second // Index
vector<PII> L;
int d,l;
int end;
#define MP make_pair
#define PB push_back
set<PII> S;
queue<PII> Q; // height and index
PII cur;
int ci,ch,ni,nh;
void reset() {
	while(!Q.empty()) {
		Q.pop();
	}
	L.clear();
	S.clear();

}
bool testc() {
	reset();
	scanf("%d", &N);
	for(int i=0;i<N;i++) {
		scanf("%d %d",&d, &l);
		if(DEBUG) printf("d %d l %d\n",d,l);
		L.PB(MP(d,l));
	}
	scanf("%d", &end);
	assert(L[0].DD<=L[0].LL);
	Q.push(MP(L[0].DD,0)); //height is initial distance
	S.insert(MP(L[0].DD,0)); //height is initial distance
	while(!Q.empty()) {
		cur = Q.front();
		Q.pop();
		ci=cur.II;
		ch=cur.HH;
		if(DEBUG) printf("possible: ci %d ch %d\n",ci,ch);
			
		//check for end
		if(L[ci].DD + ch >= end) return true;
		//search forward
		ni = ci-1;
		while(ni>=0 && abs(L[ci].DD-L[ni].DD)<=ch) {
			//is possible:
			nh = min(abs(L[ci].DD-L[ni].DD), L[ni].LL);
			if(S.find(MP(nh,ni))==S.end()) { // not yet
				S.insert(MP(nh,ni));
				Q.push(MP(nh,ni));
			}
			ni--;
		}
		//search bw
		ni = ci+1;
		while(ni<N && abs(L[ci].DD-L[ni].DD)<=ch) {
			//is possible:
			nh = min(abs(L[ci].DD-L[ni].DD), L[ni].LL);
			if(S.find(MP(nh,ni))==S.end()) { // not yet
				if(DEBUG) printf("insert: ni %d pos %d nh %d\n",ni,L[ni].DD,nh);
				S.insert(MP(nh,ni));
				Q.push(MP(nh,ni));
			}
			ni++;
		}
	}
	return false;
}
int main() {
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		if(testc()) {
			printf("Case #%d: YES\n",t+1);
		} else {
			printf("Case #%d: NO\n",t+1);
		}
	}
	return 0;
}
