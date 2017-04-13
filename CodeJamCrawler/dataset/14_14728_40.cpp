/*
TASK: Growing Vegetables is Fun
LANG: C++
NAME: Hirotaka Isa JPN03
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define INF 1000000000
#define eps 1e-10
int num[300005],n;
vector<int>vec;
vector<int>pos[300005];
struct BIT
{
  ll bit[(1<<19)+5];
  void init(){ memset(bit,0LL,sizeof(bit));}
  int f(int x)
  {
    return x&-x;
  }
  void add(int i,int x)
  {
    for(int s=i;s<=(1<<19);s += f(s)) bit[s]+=x;
  }
  ll sum(int i)
  {
    ll res=0;
    for(int s=i;s>0;s -= f(s)) res+=bit[s];
    return res;
  }
}bit;
int big[300005];

int main()
{
int t;
cin >> t;
for(int cas = 1;cas<=t;cas++)
{
	printf("Case #%d: ",cas);
	
	  scanf("%d",&n); vec.clear();
	  for(int i=0;i<300005;i++) pos[i].clear();
	  for(int i=1;i<=n;i++)
	    {
	      scanf("%d",&num[i]); vec.pb(num[i]);
	    }
	  sort(vec.begin(),vec.end());
	  vec.erase(unique(vec.begin(),vec.end()),vec.end());
	  for(int i=1;i<=n;i++)
	    {
	      int id=1+lower_bound(vec.begin(),vec.end(),num[i])-vec.begin();
	      num[i]=id;
	      pos[id].pb(i);
	    }
	    bit.init();
	  for(int i=1;i<=n;i++)
	    {
	      big[i]=bit.sum((1<<19))-bit.sum(num[i]);
	      bit.add(num[i],1);
	    }
	  ll ret=0; int tot=n;
	  for(int i=1;i<=vec.size();i++)
	    {
	      for(int j=0;j<pos[i].size();j++)
		{
		  ret+=min(big[pos[i][j]],(int)(tot-pos[i].size())-big[pos[i][j]]);
		}
	      tot-=pos[i].size();
	    }
	  cout << ret << endl;
	}
}