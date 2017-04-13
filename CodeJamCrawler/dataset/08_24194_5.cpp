#include<iostream>
#include<string.h>
#include<algorithm>
#include<fstream>
#define INF 1000000000

using namespace std;

int s1[1000];
int s2[1000];

int cmp(int a, int b)
{
	return a>b;
}

int cmp2(int a, int b)
{
	return a<b;
}

int main()
{
	long long sum;
	int p,ncase,i,j,k,m,n;
	ifstream cin("11.in");
	ofstream cout("1.out");
	cin>>ncase;
	for(p=1;p<=ncase;p++)
	{
		sum=0;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>s1[i];
		for(i=0;i<n;i++)
			cin>>s2[i];
		sort(s1,s1+n,cmp);
		sort(s2,s2+n,cmp2);
		for(i=0;i<n;i++)
			sum+=s1[i]*s2[i];
		cout<<"Case #"<<p<<": "<<sum<<endl;
	}
	return 0;
}
