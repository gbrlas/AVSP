#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
#include<cstring>
using namespace std;

#define SZ(v) ((v).size())
#define ALL(v) ((v).begin()), ((v).end())
#define CLR(a,v) memset((a), (v), sizeof(a))
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR2(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define REP(it,v) for(typeof(v)::iterator (it)=(v).begin(); (it)!=(v).end(); (it)++)
#define MP make_pair
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int p;
vector<vector<int> > v;
vector<int> m;
long long dp[20][2000][20];
long long INF = 2000000000;

long long f(int row, int col, int cnt)		{
	if(row==-1) {
		if(cnt>=m[col]) return 0;
		return INF;
	}
	if(dp[row][col][cnt]!=-1) return dp[row][col][cnt];
	long long res = f(row-1, col*2, cnt+1)+f(row-1, col*2+1, cnt+1)+v[row][col];
	res = min(res, f(row-1, col*2, cnt)+f(row-1, col*2+1, cnt));
	return dp[row][col][cnt]=res;
}

#define LARGE

int main()	{

	freopen("b.in","r",stdin);
	
#ifdef SMALE	
	freopen("b_small.in","r",stdin);
	freopen("b_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("b_large.in","r",stdin);
	freopen("b_large.out","w",stdout);
#endif
	
	int tc, temp;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		cin>>p;
		v.clear();
		v.resize(p);
		m.clear();
		m.resize(1<<p);
		
		for(int i=0;i<(1<<p);i++) {
			cin>>m[i];
			m[i]=p-m[i];
		}

		for(int i=0;i<p;i++) {
			for(int j=0;j<(1<<(p-i-1));j++)	{
				cin>>temp;
				v[i].push_back(temp);
			}
		}

		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %d\n", tt, (int)f(v.size()-1, 0, 0));
	}
	

	return 0;
}
