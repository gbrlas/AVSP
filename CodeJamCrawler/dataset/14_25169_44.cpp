#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long t,test,n,i,j,k,p,q,count1,count2;
	cin>>test;
	for(t=1;t<=test;t++)
	{
		cin>>n;
		double a[n],b[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		p=0;q=0;count1=0;
		while(p<n&&q<n)
		{
			if(a[p]>=b[q])
			{
				p++;q++;
				count1++;
			}
			else
			{
				p++;
			}
		}
		p=0;q=0;count2=0;
		while(p<n&&q<n)
		{
			if(a[p]<b[q])
			{
				p++;q++;
				
			}
			else
			{
				q++;
				count2++;
			}
		}
		cout<<"Case #"<<t<<": "<<count1<<" "<<count2<<endl;
	}
	return 0;
}

