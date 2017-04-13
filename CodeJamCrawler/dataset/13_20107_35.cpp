#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define maxn 2010
//#define maxm 30
//const double expp=1e-7;
#define mm 1000002013LL

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

struct node
{
	LL p,w;
}a[maxn];

bool cmp(const node &x,const node &y)
{
	return (x.p<y.p || (x.p==y.p && x.w>y.w));
}

LL q[maxn],w[maxn];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		LL n,m;
		LL ans=0,sum=0;
		cin>>n>>m;
		int tot=0;
		for (int i=1;i<=m;i++)
		{
			LL p1,p2,p3;
			cin>>p1>>p2>>p3;
			LL pp=p2-p1;
			//cout<<( (pp*n-(pp-1)*pp/2) %mm )*p3<<endl;
			sum=(sum+( (pp*n-(pp-1)*pp/2) %mm )*p3 )%mm;
			tot++;
			a[tot].p=p1;
			a[tot].w=p3;
			tot++;
			a[tot].p=p2;
			a[tot].w=-p3;
		}
		sort(a+1,a+tot+1,cmp);
		//for (int i=1;i<=tot;i++)
		//	cout<<a[i].p<<" "<<a[i].w<<endl;
		
		int t=0;
		for (int i=1;i<=tot;i++)
		{
			if (a[i].w>0)
			{
				t++;
				q[t]=a[i].p;
				w[t]=a[i].w;
			}
			else
			{
				a[i].w=-a[i].w;
				while (a[i].w>0)
				{
					LL w1=min(a[i].w,w[t]);
					LL pp=a[i].p-q[t];
					//cout<<"pp "<<pp<<" "<<w1<<" ";
					//cout<<( (pp*n-(pp-1)*pp/2) %mm) *w1<<endl;
					ans=(ans+( (pp*n-(pp-1)*pp/2) %mm) *w1 )%mm;
					a[i].w-=w1;
					w[t]-=w1;
					if (w[t]==0) t--;
				}
			}
		}
		//cout<<sum<<" "<<ans<<endl;
		cout<<(sum-ans+mm)%mm<<endl;
	}

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
