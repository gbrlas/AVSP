#include <stdio.h>
#include <iostream>
using namespace std;

long long a[3][3];
long long n,A,B,C,D,M;
int t,T;
long long x0,y0,x,y;
int main()
{
	freopen ("A-large.in","r",stdin);
	freopen ("A-large.out","w",stdout);

	int i;
	int j;
	int i1,j1;
	int i2,j2;
	int i3,j3;
	cin>>T;
	for (t=0;t<T;t++)
	{
		memset(a,0,sizeof(a));
		cin>>n>>A>>B>>C>>D>>x0>>y0>>M;
		x=x0;
		y=y0;
		a[x%3][y%3]++;
		for (i=1;i<n;i++)
		{
			x = (A * x + B) % M;
			y = (C * y + D) % M;
			a[x%3][y%3]++;
		}
		long long res=0;
		for (i1=0;i1<3;i1++) for (j1=0;j1<3;j1++)
		for (i2=0;i2<3;i2++) for (j2=0;j2<3;j2++)
		for (i3=0;i3<3;i3++) for (j3=0;j3<3;j3++)
		{
			if ((i1+i2+i3)%3==0 && (j1+j2+j3)%3==0 && (i1!=i2 || j1!=j2) && (i1!=i3 || j1!=j3) && (i3!=i2 || j3!=j2) )
			{
				res+=a[i1][j1]*a[i2][j2]*a[i3][j3];
			}
		}
		res/=6;
		for (i1=0;i1<3;i1++) for (j1=0;j1<3;j1++)
		for (i2=0;i2<3;i2++) for (j2=0;j2<3;j2++)
		{
			if ((i1+i1+i2)%3==0 && (j1+j1+j2)%3==0 && (i1!=i2 || j1!=j2) )
			{
				res+=(a[i1][j1]*(a[i1][j1]-1))/2*a[i2][j2];
			}
		}
		for (i1=0;i1<3;i1++) for (j1=0;j1<3;j1++)
		{
			res+=(a[i1][j1]*(a[i1][j1]-1)*(a[i1][j1]-2))/6;
		}
		
		printf("Case #%d: %lld\n",t+1,res);
	}


	return 0;
}