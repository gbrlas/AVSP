#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

using namespace std;
#define PROBLEM "A"
#define SCALE "large"
#define IN_FILE PROBLEM"-"SCALE".in"
#define OUT_FILE PROBLEM"-"SCALE".out"

typedef unsigned long long ULL;
typedef long long LL;
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

const double pi = acos(-1.);
const double eps = 1e-7;
const LL inf = 1LL<<32;

int dp[11000];
int T,N;
string row[41];
int pos[41];

int solve(int p)
{
	int i,j,k,l,m,n,x,y,s,t;
	if(p>N) return 0;
	if(pos[p]<=p) return solve(p+1);
	REP(i,p+1,N+1)
		if(pos[i]<=p) {
			for(j=i;j>p;j--)
				pos[j]=pos[j-1];
			return i-p+solve(p+1);
		}
	return 0;
}

int main()
{
	freopen(IN_FILE, "r", stdin);
	freopen(OUT_FILE, "w", stdout);

	int i,j,k,l,m,n,x,y,s,t;
	cin>>n;
	rep(i,n)
	{
		cin>>N;
		rep(j,N) cin>>row[j+1];
		rep(j,N) {
			int index=row[j+1].find_last_of('1');
			if(index==string::npos) index=0;
			else index++;
			pos[j+1]=index;
		}
		printf("Case #%d: %d\n", i+1, solve(1));
	}
	return 0;
}
