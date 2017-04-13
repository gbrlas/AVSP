#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		int n;
		double a[1200],b[1200];
		int ab[1200]={0},bb[1200]={0};
		cin>>n;
		for(int i=0;i<n;i++)
		scanf("%lf",&a[i]);
		for(int i=0;i<n;i++)
		scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int flag,count2=0;
		for(int i=0;i<n;i++)
		{
			flag=0;
			for(int j=0;j<n;j++)
			{
				if(a[i]<b[j]&&bb[j]==0)
				{
					flag=1;
					bb[j]=1;
					break;
				}
			}
			if(flag==0)
			{
				int l=0;
				while(bb[l])
				l++;
				bb[l]=1;
				count2++;
			}
		}
		reverse(a,a+n);
		reverse(b,b+n);
		int cc[1200]={0};
		int count1=0;
		//for(int i=0;i<n;i++)
		//cout<<bb[i]<<" ";
		//cout<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i]>b[j]&&ab[i]==0&&cc[j]==0)
				{
					count1++;
					ab[i]=1;
					cc[j]=1;
					break;
				}
			}
		}
		printf("Case #%d: %d %d\n",k,count1,count2);
	}
	return 0;
}
