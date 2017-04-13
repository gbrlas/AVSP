#include<iostream>
#include<map>
#include<stdio.h>

using namespace std;

int main(){
	long long int t,i,n,s,p,ts,j,sc[2],c1,c2,c3,g;
	scanf("%lld",&t);
	map<long long int,long long int> googlers;
	for(i=0;i<t;i++){
		ts = 0;
		c1 = c2 = c3 = g = 0;
		scanf("%lld%lld%lld",&n,&s,&p);
		for(j=0;j<n;j++){
			scanf("%lld",&googlers[j]);
			}
		sc[0] = (3*p) - 4;
		sc[1] = (3*p) - 3;
		for(j=0;j<n;j++){
			//cout<<googlers[j]<<endl;	
			if(googlers[j]==sc[0])
				{if(p>=2)c1++;}	
			else if(googlers[j]==sc[1])
				{if(p>=2)c2++;}
			else if(googlers[j]>sc[1])
				c3++;
			}
			//cout<<c1<<endl<<c2<<endl;
		g = c1 + c2;
		long long int add;
		add = g>s?s:g;
		c3 = c3 + add;
		cout<<"Case #"<<i+1<<": "<<c3<<endl;
		}
	return 0;
	}
