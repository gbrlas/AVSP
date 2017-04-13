#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)

using namespace std;

const int maxn=1003;

int n,t;
int ay[maxn];

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	scanf("%d",&t);
	int i,j,v,m,sum;
	for1(i,1,t){
		scanf("%d",&n);
		for1(j,1,n)scanf("%d",&ay[j]);
		v=0;
		sum=0;
		m=1111111;
		for1(j,1,n){
			v^=ay[j];
			m=min(m,ay[j]);
			sum+=ay[j];
		}
		if (v!=0)printf("Case #%d: NO",i);else printf("Case #%d: %d",i,sum-m);
		puts("");
	}
	return 0;
}
