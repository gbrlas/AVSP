#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

int n;
long long p;

long long get(long long x, long long v) {
	long long res = 0;
	for(int round=n-1;round>=0;round--) {
		if(v == 0) break;
		v--;
		v/=2;
		res |= (1LL<<round);
	}
	return res;
}

bool can1(long long x) {
	return get(x, x) < p;
}

bool can2(long long x) {
	long long record = get(x, (1LL<<n)-x-1);
	record ^= (1LL<<n)-1;
	return record < p;
}

long long f(bool (*can)(long long)) {
	long long st=0, end=(1LL<<n)-1;
	while(st < end) {
		long long mid = (st+end+1)/2;
		if(can(mid))
			st = mid;
		else
			end = mid-1;
	}
	return st;
}

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		cin>>n>>p;
		cout<<"Case #"<<tt<<": "<<f(can1)<<" "<<f(can2)<<endl;
	}

	return 0;
}
