#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long LL;
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
double ar[1005];
double br[1005];
int main()
{
//	freopen("DW.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int h=1;h<=t;h++)
	{
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%lf", &ar[i]);
		for(int i=0;i<n;i++) scanf("%lf", &br[i]);
		pii ans = mp(0,0);
		sort(ar,ar+n);sort(br,br+n);
		ans.se = n;
		int poi = 0;
		for(int i=0;i<n && poi<n;i++,poi++)
		{
			while(poi<n && ar[i]>br[poi]) poi++;
			if(poi<n) ans.se--;
		}
		poi=0;
		for(int i=0;i<n && poi<n;i++,poi++)
		{
			while(poi<n && br[i]>ar[poi]) poi++;
			if(poi<n) ans.fi++;
		}
		printf("Case #%d: %d %d\n", h,ans.fi,ans.se);
	}
}
