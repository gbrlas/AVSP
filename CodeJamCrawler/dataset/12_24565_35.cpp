//Written by technolt
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define maxn 11111
#define sqr(x) ((x)*(x))

int n;
bool found;
long long w,l,x[maxn],y[maxn],r[maxn],X[maxn],Y[maxn];
pair<long long,int> a[maxn];

bool inside(long long x,long long y) {
    return (0<=x && x<=w && 0<=y && y <=l);
}

long long dist(long long x1, long long y1, long long x2,long long y2) {
    return (sqr(x1-x2)+sqr(y1-y2));
}

bool chk(int i) {
    if (!inside(x[i]+r[i],y[i]+r[i])) return false;
    FOR(j,1,i-1) 
        if (dist(x[j]+r[j],y[j]+r[j],x[i]+r[i],y[i]+r[i])<sqr(r[i]+r[j])) return false;
    return true;
}

void print() {
    FOR(i,1,n) {
        X[a[i].second]=x[i]+r[i];
        Y[a[i].second]=y[i]+r[i];
    }
}

void att(int i) {
    if (i>n) {
        print();
        found=true;
        return;
    }
    DOWN(j,i-1,1) {
        x[i]=max(-r[i],x[j]+2*r[j]);
        y[i]=max(-r[i],y[j]);
        if (chk(i)) att(i+1);
        if (found) return;
        x[i]=max(-r[i],x[j]);
        y[i]=max(-r[i],y[j]+2*r[j]);
        if (chk(i)) att(i+1);
        if (found) return;
    }
}

int main() {
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    int numtest;
    cin >> numtest;
    FOR(test,1,numtest) {
        cout << "Case #" << test << ": ";
        cin >> n >> w >> l;
        FOR(i,1,n) {
            long long t;
            cin >> t;
            a[i].first=-t;
            a[i].second=i;
        }
        sort(a+1,a+n+1);
        FOR(i,1,n) r[i]=-a[i].first;
        x[1]=-r[1];
        y[1]=-r[1];
        found=false;
        att(2);
        FOR(i,1,n) cout << X[i] << " "<<Y[i] << " ";
        cout << endl;
        cerr << test << " " << found <<endl;
    }
    while(1);
	return 0;
}
