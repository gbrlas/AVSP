#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstring>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <ctime>
#include <complex>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define sqr(a) ((a)*(a))

using namespace std;

typedef long long LL;
typedef pair<int,int> PAIR;

const int maxn=203;
const LL inf=100000000000000000LL;

int t,n,m;
PAIR ay[maxn];

inline bool cmp(const PAIR &a,const PAIR &b){
	return a.first<b.first;
}

inline bool work(LL lim){
	int i;
	LL x=-inf,y;
	for1(i,1,n){
		x=max(x+m,ay[i].first-lim);
		y=x+LL(ay[i].second-1)*m;
		if (abs(y-ay[i].first)>lim)return false;
		x=y;
	}
	return true;
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>t;
	int i,j,k;
	for1(i,1,t){
		cin>>n>>m;
		m*=2;
		for1(j,1,n){
			cin>>ay[j].first>>ay[j].second;
			ay[j].first*=2;
		}
		sort(ay+1,ay+n+1,cmp);
		k=1;
		for1(j,2,n){
			if (ay[j].first==ay[k].first){
				ay[k].second+=ay[j].second;
			}else{
				ay[++k]=ay[j];
			}
		}
		n=k;
		LL x,y,mid;
		x=0,y=inf;
		while (x<y){
			mid=(x+y)>>1;
			if (work(mid))y=mid;else x=mid+1;
		}
		if (x&1)printf("Case #%d: %I64d.5\n",i,x/2);
		else printf("Case #%d: %I64d\n",i,x/2);
		//printf("Case #%d: %.10lf\n",i,(x+y)*0.5);
	}
    return 0;
}
