#include<iostream>
using namespace std;

int cannotlose(long long num, long long p, long long n) {
	long long rank = 0;
	int round = 1;
	num++;
	while(num>1) {
		num/=2;
		rank+=((long long)1)<<(n-round);
		round++;
	}
	return rank<p;
}

int canwin(long long num, long long p, long long n) {
	long long rank = 0;
	int round = 1;
	num = (((long long)1)<<n) - num - 1;
	num ++;
	while(num>1) {
		num/=2;
		rank+=((long long)1)<<(n-round);
		round++;
	}
	rank = (((long long)1)<<n) - rank - 1;
	return rank<p;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		long long n,p;
		cin>>n>>p;
		long long mini = 0;
		long long maxi = ((long long)1) << n;
		while(maxi-mini>1) {
			long long mid = (maxi+mini)/2;
			if(canwin(mid, p, n)) {
				mini = mid;
			} else 
				maxi = mid;
		}
		long long z = mini;
		mini = 0;
		maxi = ((long long)1) << n;
		while(maxi-mini>1) {
			long long mid = (maxi+mini)/2;
			if(cannotlose(mid, p, n)) {
				mini = mid;
			} else 
				maxi = mid;
		}
		long long y = mini;
		cout<<"Case #"<<tn+1<<": "<<y<<' '<<z<<endl;

	}
}
