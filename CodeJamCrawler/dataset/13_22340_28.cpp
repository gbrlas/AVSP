#include <cstdio>
#include <iostream>

using namespace std;

long long n,p;

long long worst(long long x){
	long long ret=0;
	for (int i=0; i<n; ++i){
		if (x==0) return ret;
		ret+=1LL<<(n-i-1);
		x=(x-1)/2;
	}
	return ret;
}

long long solve1(){
	long long l=0, r=(1LL<<n)-1;
	long long ret=0;
	while (l<=r){
		long long m=(l+r)/2;
		if (worst(m)<p){
			ret=m; l=m+1;
		} else
			r=m-1;
	}
	return ret;
}

long long solve2(){
	long long l=0, r=(1LL<<n)-1;
	long long ret=0;
	while (l<=r){
		long long m=(l+r)/2;
		long long tmp=(1LL<<n)-1-worst((1LL<<n)-1-m);
		if (tmp<p){
			ret=m; l=m+1;
		} else
			r=m-1;
	}
	return ret;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		cin>>n>>p;
		cout<<"Case #"<<T<<": "<<solve1()<<" "<<solve2()<<endl;
	}
}
