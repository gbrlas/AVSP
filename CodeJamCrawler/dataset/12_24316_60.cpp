/*By Zine.Chant*/
#include<algorithm>
#include<iterator>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
const int maxn=3000001;
int v,a,b,x,y,z,t;
int d[maxn];
bool o[maxn];
long long ans;
int c[9];
int w(int x)
{
	int s=0;
	while (x>0)
	{
		x/=10;
		s++;
	}
	return s;
}
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d\n",&v);
	c[1]=1;
	for (int i=2;i<=8;i++)
		c[i]=c[i-1]*10;
	memset(o,false,sizeof(o));
	for (int u=1;u<=v;u++)
	{
		ans=0;
		scanf("%d %d\n",&a,&b);
		for (int i=a;i<=b;i++)
		{
			y=w(i);
			x=i;
			t=0;
			for (int j=1;j<y;j++)
			{
				z=x%10;
				x/=10;
				x+=z*c[y];
				if (o[x]||x<=i||z==0||x>b||x<a) continue;
				ans++;
				t++;
				d[t]=x;
				o[x]=true;
				}
			for (int j=1;j<=t;j++)
				o[d[j]]=false;
		}
		cout<<"Case #"<<u<<": "<<ans<<endl;
	}
	return 0;
}
