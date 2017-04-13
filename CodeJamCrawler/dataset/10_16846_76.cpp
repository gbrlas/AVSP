#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int gcd(int x,int y)
{
	if(y==0) return x;
	if(x==0) return y;
	return gcd(y,x%y);
}
int main()
{
		freopen("B-small-attempt4.in","r",stdin);
	freopen("temp.txt","w",stdout);
	
	
	int t,i,num,cas = 1;
	int n,a[10];
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		num = a[n-1]-a[n-2];
	
		for(i=n-2;i>=1;i--)
			num = gcd(num,a[i]-a[i-1]);
		
		cout<<"Case #"<<cas++<<": ";
		if(num==0 || a[0]%num==0) cout<<0<<endl;
		else cout<<(num-a[0]%num)<<endl;
	}
}
