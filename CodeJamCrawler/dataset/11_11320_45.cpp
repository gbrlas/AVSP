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
#include <ctime>
#include <string>
#include <string.h>
#define pb push_back

#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef  long long LL;
typedef  long long ll;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t=GI;
	int cases=0;
	while(t--){
		cases++;
		int n=GI;
		vector<int>input;
		int xo=0;
		for(int i=0;i<n;i++){
			int x=GI;
			input.pb(x);
			xo^=x;
		}
		if(xo==0){
			int sum=0;
			for(int i=0;i<input.size();i++)sum+=input[i];
			int m=*min_element(input.begin(),input.end());
			printf("Case #%d: %d\n",cases,sum-m);
		}
		else{
			printf("Case #%d: NO\n",cases);
		}
	}
    GI; 
    return 0;
}
