#include <cstdio>

bool f(long long x, long long n, long long p){
	if(n == 0) return p >= 1;
	if((1LL << (n-1)) >= p) return 0 == x;
	return f((x-1)/2,n-1, p - (1LL << (n-1)));
}

bool g(long long x, long long n, long long p){
	if(1LL << n == p) return true;
	if( p >= (1LL << (n-1))) return x != (1LL << n) - 1;
	return g((x+1)/2, n-1, p);
}

long long bs(long long n, long long p, bool (*f)(long long, long long, long long)){
	long long a = 0;
	long long b = 1LL << n;

	while(b - a > 1){
		long long s = (a+b)/2;
		if(f(s,n,p)) a = s;
		else b = s;
	}
	return a;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		long long n,p;
		scanf("%lld %lld", &n, &p);
		printf("Case #%d: %lld %lld\n", i, bs(n, p, f), bs(n, p, g));
	}
}
