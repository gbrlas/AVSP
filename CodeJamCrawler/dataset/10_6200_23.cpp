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
typedef vector<vector<int> > vii;
typedef vector<double> vd;
typedef vector<vector<double> > vdd;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int dx[]={0,1,1,1};
int dy[]={1,0,1,-1};

char g[50][50], r[50][50];

#define LARGE

int main()	{

	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

#ifdef SMALE
	freopen("a_small.in","r",stdin);
	freopen("a_small.out","w",stdout);
#endif

#ifdef LARGE
	freopen("a_large.in","r",stdin);
	freopen("a_large.out","w",stdout);
#endif

	int t,n,k;
	cin>>t;
	for(int tt=1;tt<=t;tt++)		{
		cin>>n>>k;
		FOR(i,n)
			FOR(j,n)	{
				cin>>g[i][j];
				r[i][j]='.';
		}
		FOR(i,n)	{
			string s="";
			FOR(j,n)	{
				if(g[i][j]=='.') continue;
				s+=g[i][j];
			}
			for(int j=0;j<s.size();j++)
				r[n-s.size()+j][n-1-i]=s[j];
		}

		set<char> res;

		FOR(i,n)
			FOR(j,n)	{
				if(r[i][j]=='.') continue;
				char cur=r[i][j];
				FOR(d,4)	{
					int x=i, y=j, cnt;
					for(cnt=0;cnt<k-1;cnt++) {
						x+=dx[d]; y+=dy[d];
						if(x<0 || y<0 || x>=n || y>=n || r[x][y]!=cur) break;
					}
					if(cnt==k-1) res.insert(cur);
				}
			}

		if(res.size()==0)
			printf("Case #%d: Neither\n", tt);
		else if(res.size()==2)
			printf("Case #%d: Both\n", tt);
		else printf("Case #%d: %s\n", tt, (*res.begin()=='B'?"Blue":"Red"));
	}

	return 0;
}
