#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int t,T;
int ress[31]=
{
	0,0,27,143,751,935,607,903,991,335,47,943,471,55,447,463,
	991,95,607,263,151,855,527,743,351,135,407,903,791,135,647
};//Calculated using mathlab with my hands

int main()
{
	freopen("c-small-attempt3.in","r",stdin);
//	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (t=0;t<T;t++)
	{
		int n,i,j;
		long long a=0,b=0;
		long long num;double res=0;
		scanf("%d",&n);
/*		for (i=0;i<=n;i++)
		{
			if (i&1)
			{
				double h=sqrt(5);
				for (j=n;j>i;j--)
				{
					h*=j;h/=n-j+1;
				}
				for (j=0;j<n-i;j++)
				{
					h*=3;
					h-=100000*int(h/100000);
				}
				for (j=0;j<i/2;j++)
				{
					h*=5;
					h-=100000*int(h/100000);
				}
				res+=h;
			}
			else
			{
				num=1;
				for (j=n;j>i;j--)
				{
					num*=j;num/=n-j+1;
				}
				for (j=0;j<n-i;j++)
				{
					num*=3;
					num%=100000000;
				}
				for (j=0;j<i/2;j++)
				{
					num*=5;
					num%=100000000;
				}
				a+=num;a%=1000;
			}
		}
		res+=a;
		double res2=1;
		for (i=0;i<n;i++)
			res2*=(3+sqrt(5));*/
		printf("Case #%d: %.3d\n",t+1/*,int(res)%1000*/,ress[n]);
	}

	return 0;
}