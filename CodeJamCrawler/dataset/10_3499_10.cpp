#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int check(int d, int K){
	if(d>=K){
		if(d==K)
			return 1;
		else
			return 0;
	}
	else{
		return check(d,K-d-1);
	}
}
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("Output.txt","w",stdout);
	int T,N,K;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N>>K;
		int d=(int)pow(2,N)-1;
		if( check(d,K) )
				cout<<"Case #"<<i<<": ON\n";
		else
			cout<<"Case #"<<i<<": OFF\n";
	}
	return 0;
}
