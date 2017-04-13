#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>/*
#define MAXN 32770
bool np[MAXN]={1,1};
int p[3520]={2},tot=1;
void prime()
{ 
	int i,j;
    for(i=3;i<=MAXN;i+=2)
	{
		if(!np[i])
			p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=MAXN;j++)
		{
			np[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
		
	}
}

bool isprime(int x)
{
	if(x==2)return 1;
	if(x%2==0)return 0;
	return !np[x];
}
int f[256],t=0;
void factor(int c)
{
	f[t++]=1;
	for(i=0;i<tot&&p[i]<=t;i++)
		while(c%p[i]==0)
		{
			f[t++]=p[i];
			//while(c%p[i]==0)c/=p[i];
		}
}
int */
bool random(int m,int n,int A)
{
	int i,j,k,p;
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			for(k=0;k<=m;k++)
				for(p=0;p<=n;p++)
					if(i*p-j*k==A||j*k-i*p==A)
					{
						printf("0 0 %d %d %d %d\n",i,j,k,p);
						return 1;
					}
	return 0;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.txt","w",stdout);
	int pk;
	scanf("%d",&pk);
	int k;
	for(k=1;k<=pk;k++)
	{

		int n,m,A;
		scanf("%d %d %d",&n,&m,&A);
		printf("Case #%d: ",k);
		if(!random(n,m,A))printf("IMPOSSIBLE\n");
	}
	return 0;
}