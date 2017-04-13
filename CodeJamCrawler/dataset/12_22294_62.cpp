#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define sqr(x) ((x)*(x))
using namespace std;
const int maxn = 1010;

int r[maxn], id[maxn];
int n, w, l, task, retx[maxn], rety[maxn], R[maxn];

bool comp(int i, int j) {
	return r[i] > r[j];
}

bool check(){
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	if ( sqr(retx[i]-retx[j]) + sqr(rety[i]-rety[j]) < sqr(R[i]+R[j]) )
		return false;
	for (int i=0; i<n; i++)
	if ( !(0<=retx[i] && retx[i]<=w && 0<=rety[i] && rety[i]<=l)  )
		return false;
	return true;
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int cs=1; cs<=task; cs++) {
		scanf("%d%d%d", &n, &w, &l);
		for (int i=0; i<n; i++){
			scanf("%d", r+i);
			id[i] = i;
		}
		sort(id, id + n, comp);
		for (int i=0,j=0,x=-r[id[0]]; i < n && x<=w; i = j) {
			x += r[id[i]];
			for (int y = -r[id[i]]; j < n && y + r[id[j]] <= l; j++) {
				retx[id[j]] = x; 
				rety[id[j]] = y + r[id[j]];
				y += r[id[j]]*2;
			}
			x += r[id[i]];
		}

		//if ( !check() ) while (true);

		printf("Case #%d:", cs);
		for (int i=0; i<n; i++)
			printf(" %d %d", retx[i], rety[i]);
		printf("\n");
	}
	
	return 0;
}
