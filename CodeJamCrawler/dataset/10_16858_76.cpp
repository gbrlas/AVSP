#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("temp.txt","w",stdout);
	
	
	long long a[1010],next[1010],num[1010],v[1010];
	long long t,c=1,n,k,i,j,r,key,nn;
	long long sum;
	
	cin>>t;
	
	while(t--)
	{
		cin>>r>>k>>n;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		key=0;
		cout<<"Case #"<<c++<<": ";
		if(k>=sum)
		{
			cout<<sum*r<<endl;
			continue;
		}
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=i;sum+a[j]<=k;j=(j+1)%n)
				sum+=a[j];
			next[i]=j;
			num[i]=sum;
		}
		
		memset(v,0,sizeof(v));
		
		j=0;
		while(1)
		{
			if(v[j])
				break;
			v[j]=1; j = next[j];
		}
	
		nn=0;
		i=0;sum=0;
		while(i!=j)
		{
			sum+=num[i];
			i=next[i];
			nn++;	
		}
		if(nn>=r)
		{
			nn=i=0;
			while(nn<r)
			{
				key+=num[i];
				i=next[i];
				nn++;
			}	
		}
		else
		{
			int circle=1,circle_num=0;
			i=next[j];
			
			while(i!=j)
			{
				circle++;
				circle_num+=num[i];
				i=next[i];
			}
			circle_num+=num[j];
			int n1 = (r-nn)/circle;
			int n2 = (r-nn)%circle;
			key = sum + n1 * circle_num;
			nn=0; sum=0;
			while(nn<n2)
			{
				sum+=num[j];
				j=next[j];	
				nn++;	
			}
			key+=sum;
		}
		cout<<key<<endl;
	}
}
