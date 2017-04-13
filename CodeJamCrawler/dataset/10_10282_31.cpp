#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
struct party
{
	__int64 mp[12];
	__int64 v;
}data[3000];
__int64 n;
__int64 Min(__int64 a,__int64 b) { return a>b?b:a; }
void fun(__int64 now,__int64 pos)
{
	__int64 i,j;
	if(pos==n) 
	{
		for(i=0;i<12;i++) 
			data[now].mp[i]=0x7ffffff;
		data[now].mp[n-data[now].v]=0;
		return ;
	}
	fun(now*2+1,pos+1);
	fun(now*2,pos+1);
	
	for(i=0;i<12;i++)
	{
		if(i>pos) data[now].mp[i]=0x7ffffff;
		__int64 a,b,c;
		a=0x7ffffff; b=0x7ffffff; c=0x7ffffff;
		for(j=i+1;j>=0;j--)
		{
			a=Min(a,data[now*2].mp[j]);
			b=Min(b,data[now*2+1].mp[j]);
		}
		c=a+b+data[now].v;
		a=0x7ffffff;
		b=0x7ffffff;
		for(j=i;j>=0;j--)
		{
			a=Min(a,data[now*2].mp[j]);
			b=Min(b,data[now*2+1].mp[j]);
		}
		c=Min(c,a+b);
		data[now].mp[i]=c;
	}
	return ;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("ans.out","w",stdout);
	__int64 CA,T;
	scanf("%I64d",&T);
	for(CA=1;CA<=T;CA++)
	{
		scanf("%I64d",&n);
		__int64 p,q;
		__int64 m=1<<n;
		for(p=n;p>=0;p--)
		{
			for(q=0;q<(1<<p);q++)	
				scanf("%I64d",&data[q+(1<<p)].v);
		}
		fun(1,0);
		printf("Case #%I64d: %I64d\n",CA,data[q].mp[0]);
	}
	return 0;
}