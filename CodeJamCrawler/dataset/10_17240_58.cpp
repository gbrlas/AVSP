#include<stdio.h>
#include<math.h>
#include<iostream.h>
using namespace std;
int main()
{
long long int test,k,i,j,q,a,b,c,p,t;
freopen("a.in","r",stdin);
freopen("output.txt","w",stdout);
cin>>test;
for(k=0;k<test;k++)
{
p=0;
	cin >>a>>b>>c;
	t=c;
	q=b;
	while(1)
	{
		if(a*c>=q) break;
		p++;
		q=(long long int) ceil(sqrt(a*q));
	    
	}
//	j=10000000000000LL;
//	cout <<j; 
	cout <<"Case #"<<k+1<<": "<<p<<"\n";//,k+1,p;
	
}
}
