#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	float nal[10000],na[10000],k[10000];
	float tmp;
	int t,i,j,cnt=0,m=0,n;
	int a[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%f",&na[i]);
		if(n>1)
			for(i=1;i<n;i++)
				for(j=0;j<(n-i);j++)
				{
					if(na[j]>na[j+1])
					{
						tmp=na[j];
						na[j]=na[j+1];
						na[j+1]=tmp;
					}
				}
		for(i=0;i<n;i++)
			nal[i]=na[i];
		
		for(i=0;i<n;i++)
			scanf("%f",&k[i]);
		if(n>1)
			for(i=1;i<n;i++)
				for(j=0;j<(n-i);j++)
				{
					if(k[j]>k[j+1])
					{
						tmp=k[j];
						k[j]=k[j+1];
						k[j+1]=tmp;
					}
				}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(k[i]<na[j])
				{
					cnt++;
					na[j]=0;
					break;
				}
		a[m]=cnt;
		m++;
		cnt=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(nal[i]<k[j])
				{
					cnt++;
					k[j]=0;
					break;
				}
		a[m]=n-cnt;
		m++;
		cnt=0;
	}
	j=1;
	for(i=0;i<m;i=i+2)
	{
		printf("Case #%d: ",j);
		printf("%d %d\n",a[i],a[i+1]);
		j++;
	}
}
