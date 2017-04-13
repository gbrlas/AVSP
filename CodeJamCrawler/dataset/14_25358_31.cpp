#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
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
#include <cstring> 
using namespace std; 
#define ALL(a) (a).begin(), (a).end() 
#define SZ(a) (int)(a).size() 
#define FOR(i,s,n) for(int i=(s);i<(n);++i) 
#define REP(i,n) FOR(i,0,(n)) 
#define PB(x) push_back((x)) 
#define CLR(a,v) memset((a),(v),sizeof((a))) 
typedef long long ll; 

int n,a[1010], b[1010];

int get(int pos)
{
// 	char ok = 1;
// 	REP(i,pos)if(a[i]>a[i+1])
// 	{
// 		ok=0;
// 		break;
// 	}
// 
// 	if(ok)
// 	{
// 		FOR(j,pos+1,n)if(a[j]>a[j-1])
// 		{
// 			ok=0;
// 			break;
// 		}
// 	}
// 
// 	if(ok)return 0;

	REP(i,n)b[i]=a[i];
	
	int res = 0;
	int k=max_element(b,b+n)-b;
	while (k!=pos)
	{
		++res;
		if(k<pos)swap(b[k],b[k+1]),++k;
		else swap(b[k],b[k-1]),--k;
	}

	REP(i,pos)REP(j,pos)if(b[j]>b[j+1])
	{
		++res;
		swap(b[j],b[j+1]);
	}

	FOR(i,pos+1,n)FOR(j,pos+1,n)if(b[j]<b[j+1])
	{
		++res;
		swap(b[j],b[j+1]);
	}

	return res;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int T;
	scanf("%d", &T);

	FOR(ttt,1,T+1)
	{
		scanf("%d", &n);

		REP(i,n)scanf("%d",a+i);

		int res = 0, L=0, R=n;

		REP(qqq,n-1)
		{
			int p = min_element(a+L,a+R)-a;
			if(p-L<R-1-p)
			{
				while (p!=L)
				{
					++res;
					swap(a[p],a[p-1]);
					--p;
				}
				++L;
			}
			else
			{
				while (p!=R-1)
				{
					++res;
					swap(a[p],a[p+1]);
					++p;
				}
				--R;
			}
		}

		printf("Case #%d: %d\n", ttt, res);
	}

	return 0;
}