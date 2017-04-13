#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int times,n,number[252][252],ans1;
bool use[252][252];
bool check(int x,int y)
{
	int tx,ty;
	for (int a=1;a<=2*n-1;++a)
	for (int b=1;b<=2*n-1;++b)
	if (use[a][b])
	{
		tx=2*x-a;
		ty=2*y-b;
//	if ((x==2)&&(y==3))	printf("[%d,%d=%d,%d|%d,%d]",a,b,tx,ty,x,y);
	//	if ((x==2)&&(y==3))	printf("<%d,%d,%d>",number[tx][b],number[a][ty],number[a][b]);
	//	if ((x==2)&&(y==3))	printf("(%d,%d)",use[tx][b],use[a][ty]);
			if ((tx>=1)&&(tx<=2*n-1)&&(number[a][b]!=number[tx][b])&&(use[tx][b]))
			{
		//		if ((x==2)&&(y==3)) printf("(||%d,%d)",tx,b);
				return false;
			}				
				
			if ((ty>=1)&&(ty<=2*n-1)&&(number[a][b]!=number[a][ty])&&(use[a][ty]))
			{
		//		if ((x==2)&&(y==3)) printf("(||%d,%d)",a,ty);
				return false;
			}
	}
	return true;
}
void mem()
{
	memset(use,0,sizeof(use));
	memset(number,0,sizeof(number));
	ans1=10000000;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d",&n);
		mem();
		for (int a=1;a<=n;++a)
		for (int b=1;b<=a;++b)
		{
			scanf("%d",&number[a][(n-a+1)+(b-1)*2]);
			use[a][(n-a+1)+(b-1)*2]=1;
		}
		for (int a=n+1;a<=2*n-1;++a)
		for (int b=1;b<=2*n-a;++b)
		{
			scanf("%d",&number[a][(n+1-(2*n-a))+(b-1)*2]);
			use[a][(n+1-(2*n-a))+(b-1)*2]=1;
		}
		ans1=1000000;
		for (int a=1;a<=2*n-1;++a)
		for (int b=1;b<=2*n-1;++b)
		//if (use[a][b])
		if (check(a,b))
		{
			int t=abs(a-n)+abs(b-n);
		//	printf("[%d,%d,%d,%d]",a,b,t,n);
			if (ans1>t)
			{
				ans1=t;
			}
		}
	//	printf("%d\n",ans1);
		/*if (ans1%2==1)
		{
			ans1=(ans1/2)*2+(ans%2==0);
		}else
		{
			ans1=ans1+1;
		}*/
		ans1=n+ans1;
	//	ans1=ans1+(ans1%2==0);
		
	//	printf("%d\n",ans1);
		ans1=ans1*ans1-n*n;
		printf("Case #%d: %d\n",z,ans1);
	}
}
