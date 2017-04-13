#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define size(x) int((x).size())
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
typedef long long I64; typedef unsigned long long U64;
const double EPS=1e-12;
const int INF=999999999;
typedef vector<int> VI;
typedef vector<string> VS;

bool flag[1010];
VI prime;

int A,B,P;
int father[1010];

int find(int x)
{
	return (father[x]==x)?x:father[x]=find(father[x]);
}

bool check(int x,int y)
{
	foreach(i,prime) {
		int p=*i;
		if(x%p==0 && y%p==0) return 1;
	}
	return 0;
}

int solve()
{
	scanf("%d%d%d",&A,&B,&P);
	prime.clear();
	for(int i=P;i<=1000;i++) if(!flag[i]) prime.push_back(i);
	
	for(int i=A;i<=B;i++) father[i]=i;	
	for(int i=A;i<=B;i++)
		for(int j=i+1;j<=B;j++) if(check(i,j)) {
			int x=find(i),y=find(j);
			father[x]=y;
		}

	int ans=0;
	for(int i=A;i<=B;i++) if(find(i)==i) ans++;
	return ans;
}

int main()
{
	memset(flag,0,sizeof(flag));
	for(int i=2;i*i<=1000;i++) if(!flag[i])
		for(int j=i*i;j<=1000;j+=i) flag[j]=1;

	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) printf("Case #%d: %d\n",i,solve());

	return 0;
}
