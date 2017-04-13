#include<iostream>
#include<cmath>
using namespace std;

bool work(int i,int j)
{
	int f[10];
	f[0]=1;
	for (int k=1;k<=8;k++)
		f[k]=f[k-1]*10;
	int p1=i,p2=j,d=0;
	while (p1>0 && p2>0)
	{
		d++;
		p1/=10;
		p2/=10;
	}
	if (p1!=0 || p2!=0) return false;
	for (int p=1;p<d;p++)
		if ((i%f[p])*(f[d]/f[p])+(i/f[p])==j) return true;
	return false;
}

int count(int a,int b)
{
	int ans=0;
	for (int i=a;i<b;i++)
		for (int j=i+1;j<=b;j++)
			if (work(i,j)) ans++;
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t=0;
	cin>>t;
	for (int tt=1;tt<=t;tt++)
	{
		int i=0,j=0;
		cin>>i>>j;
		cout<<"Case #"<<tt<<": "<<count(i,j)<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
