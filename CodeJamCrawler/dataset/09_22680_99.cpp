#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define INF 1000000000


int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tt;
	cin >> tt;
	string s;
	getline(cin, s);

	REP(t,tt)
	{		
		cout << "Case #" << t+1 << ": ";
		getline(cin, s);
		int ans[4];
		long long w[19];
		REP(i, 19)
			w[i]=0;

		int p=0;
		int n=s.length();
		while ((p<n)&&(s[p]!='w'))
			p++;
		if(p!=n)
		{
			while (p<n)
			{
				switch (s[p])	//WELCOME_TO_CODE_JAM
				{				//0123456789012345678
				case 'w':
					w[0]++;
					break;
				case 'e':
					w[1]+=w[0];
					w[6]+=w[5];
					w[14]+=w[13];
					break;
				case 'l':
					w[2]+=w[1];
					break;
				case 'c':
					w[3]+=w[2];
					w[11]+=w[10];
					break;
				case 'o':
					w[4]+=w[3];
					w[9]+=w[8];
					w[12]+=w[11];
					break;
				case 'm':
					w[5]+=w[4];
					w[18]+=w[17];
					break;
				case ' ':
					w[7]+=w[6];
					w[10]+=w[9];
					w[15]+=w[14];
					break;
				case 't':
					w[8]+=w[7];
					break;
				case 'd':
					w[13]+=w[12];
					break;
				case 'j':
					w[16]+=w[15];
					break;
				case 'a':
					w[17]+=w[16];
					break;
				}
				p++;
				REP(j,19)
					w[j]%=10000;
			}
		}
		REP(i,4)
		{
			ans[i]=w[18]%10;
			w[18]/=10;
		}
		cout << ans[3] << ans[2] << ans[1] << ans[0] << endl;
	}
	return 0;
}