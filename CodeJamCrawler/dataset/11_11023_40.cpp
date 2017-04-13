#include <fstream>
//freopen("a.txt","r",stdin);

#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

__int64 gcd(__int64 a , __int64 b)
{
	if(a == 0)
	{
		return b;
	}
	if(a > b)
	{
		return gcd(b , a % b);
	}
	else
	{
		return gcd(b % a , a);
	}
}


int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt2.in","r",stdin);
	
	freopen("b.txt","w",stdout);

	int t,z,n,l,h,i,j;
	int f[110];
	int c,jf;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		scanf("%d%d%d",&n,&l,&h);
		for(i=0;i<n;i++)
		{
			scanf("%d",&f[i]);
		}
		jf=-1;
		for(i=l;i<=h;i++)
		{
			c=1;
			for(j=0;j<n;j++)
			{
				if(!(f[j]%i==0||i%f[j]==0))
				{
					c=0;
					break;
				}
			}
			if(c==1)
			{
				jf=i;
				break;
			}
		}
		if(jf==-1)
		{
			printf("Case #%d: NO\n",z);
		}
		else
		{
			printf("Case #%d: %d\n",z,jf);
		}
	}
    return 0;
}