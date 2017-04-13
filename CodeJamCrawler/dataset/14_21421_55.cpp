#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double a[1005],b[1005];
bool f[1005];
int main()
{
	int T,L;
	cin>>T;
	for (L=1;L<=T;L++)
	{
		int i,j,k,l,n,ans1=0,ans2=0;
		cin>>n;
		for (i=0;i<n;i++) cin>>a[i];
		for (i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		memset(f,0,sizeof(f));
		for (i=0;i<n;i++)
		{
			bool t=0;
			for (j=0;j<n;j++) if (!f[j] && b[j]>a[i])
			{
				f[j]=1;
				t=1;
				break;
			}
			if (!t)
			{
				for (j=0;j<n;j++) if (!f[j]) {f[j]=1; break;}
				ans1++;
			}
		}
		memset(f,0,sizeof(f));
		for (i=0;i<n;i++)
		{
			bool t=0;
			for (j=0;j<n;j++) if (!f[j] && a[j]>b[i])
			{
				f[j]=1;
				t=1;
				break;
			}
			if (!t)
			{
				for (j=0;j<n;j++) if (!f[j]) {f[j]=1; break;}
			}
			else
			{
				ans2++;
			}
		}
		printf("Case #%d: %d %d\n",L,ans2,ans1);
	}
}
