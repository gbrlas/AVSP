#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int pd(long long x)
{
	long long y=x,z=0;
	int r=0;
	while(x!=0)
	{
		r=x%10;
		x=(long long)x/10;
		z*=10;
		z+=r;
	}
	if(z==y)
	return 1;
	else return 0;
}

int main()
{
	int t;
	long long a,b;
	long count=0;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		cin>>a>>b;
		
		long long s=ceil(sqrt(a));
		long long e=floor(sqrt(b));
		for(long long i=s;i<=e;i++)
		{
			if(!pd(i))
			continue;
			if(!pd(i*i))
			continue;
			count++;
		}
		cout<<"Case #"<<p<<": "<<count<<endl;
		count=0;
	}
}
