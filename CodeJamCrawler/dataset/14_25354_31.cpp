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

int n,X,S[10010];

// int f()
// {
// 	
// }

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int T;
	scanf("%d", &T);

	FOR(ttt,1,T+1)
	{
		scanf("%d %d", &n, &X);

		REP(i,n)scanf("%d",S+i);

		multiset<int, greater<int>> s(S,S+n);
		int res = 0;

		while (!s.empty())
		{
			int a = *s.begin();
			s.erase(s.begin());
			++res;

			if(s.empty())break;

			int b = X-a;
			multiset<int, greater<int>>::iterator it = s.lower_bound(b);
			if(it == s.end())continue;

			if (*it+a<=X)
			{
				s.erase(it);
			}
		}


		printf("Case #%d: %d\n", ttt, res);
	}

	return 0;
}