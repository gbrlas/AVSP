//DEDICATED TO EMMA WATSON, THE BRITISH *SUNSHINE*
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
//#include <fstream>

#define eps 10e-10
#define INF 1000000000
#define PI 3.141592653589793238462
#define EU 2.71828182845904523536
#define sz(a) (int)a.size()
#define pb(a) push_back(a)
#define mset(a,hodnota) memset(a,hodnota,sizeof(a))
#define wh(a) a.begin(),a.end()
#define REP(i,n) for(__typeof(n) i=0;i<(n);++i)
#define REPS(i,n) for(int(i)=0;i<int(n.size());++i)
#define FOR(i,a,b) for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b) for(__typeof(a) i=(a);i>=(b);--i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define SQR(a) ((a)*(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
typedef long long ll;
using namespace std;
int N,K,Q;
map<string,int> mapa;
int P[1005];
int next[1005][105];
int main( )
{
	scanf("%d",&N);
	REP(ii,N)
	{
		mapa.clear();
		scanf("%d\n",&K);
		string s;
		REP(i,K)
			getline(cin,s),
			mapa[s]=i;
		scanf("%d\n",&Q);
		REP(i,Q)
			getline(cin,s),
			P[i]=mapa[s];
// 		REP(i,Q)
// 			cout<<P[i]<<" ";
// 		cout<<endl;
		mset(next,-1);

		int ans=0;
		REP(i,K)
		{
			next[Q][i]=Q;
			FORD(j,Q-1,0)
				if (P[j]==i) next[j][i]=j;
				else next[j][i]=next[j+1][i];
		}

		for(int i=0;i<Q;i=*max_element(next[i],next[i]+105))		
		{
			ans++;
		}
		printf("Case #%d: %d\n",ii+1,max(ans-1,0));
	}
  
  return 0;
}
