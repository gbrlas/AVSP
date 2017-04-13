#include<stdio.h>
#include<iostream>
using namespace std;
void quicksort(double a[],int f,int l)
{
	if(f<l)
	{
		double p=a[f],t;
		int i=f+1,j;
		for(j=f+1;j<=l;j++)
		{
			if(a[j]<p)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				i++;
			}
		}
		i--;
		t=a[f];
		a[f]=a[i];
		a[i]=t;
		quicksort(a,f,i-1);
		quicksort(a,i+1,l);
	}
}
int main()
{
	freopen("D-small.in", "r", stdin);
    freopen("D-small.txt", "w", stdout);
	double a1[11],a2[11];
	int t,i,j,n,ans1,ans2,lost,k,x,l;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		ans1=ans2=lost=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%lf",&a1[j]);
		for(j=0;j<n;j++)
			scanf("%lf",&a2[j]);
		quicksort(a1,0,n-1);
		quicksort(a2,0,n-1);
		x=0;
		for(j=0;j<n;j++)
		{
			for(k=x;k<n;k++)
			{
				if(a1[j]<a2[k])
				{
					x=k+1;
					lost++;
					break;
				}
			}
		}
		ans2=n-lost;
		lost=0;
		l=n-1;
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a2[k]!=0)
				{
					if(a2[k]>a1[j])
					{
						a2[l--]=0;
						lost++;
					}
					else
						a2[k]=0;
					break;
				}
			}
		}
		ans1=n-lost;
		printf("Case #%d: %d %d\n",i,ans1,ans2);
	}
}
