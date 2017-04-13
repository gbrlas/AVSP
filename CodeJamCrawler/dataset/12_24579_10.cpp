 //Written by technolt~h

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define DOWN(i,a,b) for(int i=a;i>=b;i--)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define maxn 1011

int n,l[maxn],p[maxn],id[maxn];

bool lower(int i,int j) {

/*
	if (p[i]<p[j]) return p[i]<p[j];
	else if (l[i]<l[j]) return l[i]<l[j];
	else return i<j;
*/	
	double x=(double)l[i]*(double)p[i]/(double)100+(double)(l[i]+l[j])*(double)(100-p[i])/(double)(100)*(double)(p[j])/(double)100;
	double y=(double)l[j]*(double)p[j]/(double)100+(double)(l[i]+l[j])*(double)(100-p[j])/(double)(100)*(double)(p[i])/(double)100;
	if (x!=y) return x<y;
	return i<j;
	if (l[i]*p[i]!=l[j]*p[j]) return l[i]*p[i]>l[j]*p[j];
	else return i<j;
}

int main() {
	freopen("a.inp","r",stdin);
	int _;
	cin >> _;
	FOR(z,1,_) {
		cin >> n;
		FOR(i,0,n-1) cin >> l[i];
		FOR(i,0,n-1) cin >> p[i];
		FOR(i,0,n-1) id[i]=i;
		sort(id,id+n,lower);
		cout << "Case #"<<z<<": ";
		FOR(i,0,n-1) cout << id[i] << " ";
		cout << endl;
	}
}
