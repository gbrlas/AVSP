#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MaxN=1111;
double now,tt,cnt;
int tmp,Len,Walk,Run,Run_time,N;
struct node
{
	int ll,rr,ss;
}a[MaxN];


bool cmp(node a, node b)
{
	return a.ss<b.ss;
}

void init()
{
	scanf("%d %d %d %d %d",&Len,&Walk,&Run,&Run_time,&N);
	tmp=Len;
	for (int i=1; i<=N; ++i)
	{
		scanf("%d %d %d",&a[i].ll,&a[i].rr,&a[i].ss);
		tmp-=(a[i].rr-a[i].ll);
	}
	a[0].ll=0;
	a[0].rr=tmp;
	a[0].ss=0;
	sort(a,a+N+1,cmp);
}

void run()
{
	now=0;
	cnt=0;
	for (int i=0; i<=N; ++i)
	{
//		cnt+=(a[i].rr-a[i].ll)/(a[i].ss+Walk);
		tt=min((double)(a[i].rr-a[i].ll)/(a[i].ss+Run),Run_time-now);
		now+=tt;
		cnt+=((a[i].rr-a[i].ll-tt*(a[i].ss+Run))/(a[i].ss+Walk)+tt);
//		cout<<i<<":"<<cnt<<endl;
	}
	printf("%.10lf\n",cnt);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	int Testnum;
	cin>>Testnum;
	for (int Test=1; Test<=Testnum; ++Test)
	{
		printf("Case #%d: ",Test);
		init();
		run();
	}
	
	return 0;
}