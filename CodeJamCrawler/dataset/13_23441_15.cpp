#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long N, p;

long long oktop( long long k ){
	long long x = k, y = N-k-1;
	long long ret = N;
	while ( x>0 ){
		ret >>= 1;
		x = (x-1)/2;
	}
	return N-ret+1;
}

long long okdown( long long k ){
	long long x = k, y = N-k-1;
	long long ret = N;
	while ( y>0 ){
		ret >>= 1;
		y = (y-1)/2;
	}
	return ret;
}

long long doit1(){
	long long s=0, t=N-1, h, ret=0;
	while (s<=t){
		h = (s+t)/2;
		if ( oktop( h )<=p ){
			ret = h;
			s = h+1;
		}else t = h-1;
	}
	return ret;
}

long long doit2(){
	long long s=0, t=N-1, h, ret=t;
	while (s<=t){
		h = (s+t)/2;
		if ( okdown( h )<=p ){
			ret = h;
			s = h+1;
		}else t = h-1;
	}
	return ret;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int task, CS=1;
	for (scanf("%d", &task); task--; CS++){
		scanf("%d%d", &n, &p);
		long long hh = n;
		N = 1<<hh;
		printf("Case #%d: %lld %lld\n", CS, doit1(), doit2());
	}
	return 0;
}
