#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[10000],tt,t,xor1,i,n,sum;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (tt=0;tt<t;tt++) {
		cin>>n;
		for ( i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		xor1=a[0];
		for (i=1;i<n;i++) xor1=xor1^a[i];
		if (xor1==0) {
			sum=0;
			for ( i=1;i<n;i++) sum+=a[i];
			cout<<"Case #"<<tt+1<<": "<<sum<<endl;
		} else cout<<"Case #"<<tt+1<<": "<<"NO"<<endl;
	}
	return 0;
}	