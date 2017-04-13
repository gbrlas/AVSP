#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define SIZE(v) ((int)(v).size())

#define FOR(i,a,b) for (int i=(a),_n=(b); i < _n; i++) 
#define FORE(i,a,b) for (int i=(a),_n=(b); i <= _n; i++) 

#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)

#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))

#define FORI(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define CLEAR(x) memset(x,0,sizeof(x)); 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

typedef long long LL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI; 
typedef vector<string> VS;
typedef pair <int, int> pii; 

#define D(X) {cerr << #X << " = '" << (X) << "'" << endl;}

const double pi=acos(-1.0);

int ulim[15];

int main()
{
	ulim[0] = 1;
	FOR(i,1,15)
	{
		ulim[i] = ulim[i-1] * 2;
	}
	
	int C;cin >> C;
	for(int cs=1;cs<=C;cs++)
	{
		int N,M;
		cin >> N >> M;
		D(N)
		D(M)
		vector< vector<int> > flavor(M);
		vector< vector<int> > melted(M);
		REP(i,M)
		{
			int T; cin >> T;
			flavor[i].resize(T);
			melted[i].resize(T);
			REP(j,T)
			{
				cin >> flavor[i][j];
				//flavor[i][j]--;
				cin >> melted[i][j];
			}
		}
		
		int result = 1000;
		int rones = 1000;
		
		for(int mask=0;mask<ulim[N];mask++)
		//for(int mask=2;mask<3;mask++)
		{
			//D(mask)
			int nones = 0;
			int b = mask;
			while(b)
			{
				nones += b%2;
				b /= 2;
			}
			bool notgood = false;
			REP(i,M)
			{
				bool satisfied = false;
				for(int d=1;d<=N;d++)
				{
					//D((0+i))
					REP(j,flavor[i].size())
					{
						//D(j)
						//D(melted[i][j])
						int g = (mask & ulim[d-1]);
						if(g)
							g = 1;
						//D(g)
						if(d == flavor[i][j] && g == melted[i][j])
						{
							satisfied = true;
						}
					}
				}
				if(satisfied == false)
				{
					notgood = true;
				}
			}
			if(notgood)
			{
				continue;
			}
			if(nones < rones)
			{
				rones = nones;
				result = mask;
			}
		}
		cout << "Case #" << cs << ":";
		if(result == 1000)
		{
			cout << " IMPOSSIBLE" << endl;
		}
		else
		{
			//D(result)
			char a[N];
			int pos = 0;
			REP(i,N)
				a[i] = '0';
			int b = result;
			while(b)
			{
				a[pos] = '0' + (b%2);
				pos++;
				b/=2;
			}
			REP(i,N)
			{
				cout << " " << a[i];
			}
			cout << endl;
		}
	}
	//D(ulim[5-1])
	return 0;
}
