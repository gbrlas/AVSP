#include<iostream>
#include<vector>
using namespace std;

vector<long long> primes;

int isprime(long long x) {
	for(int i=0;i<primes.size() && primes[i]*primes[i]<=x;i++) {
		if(x % primes[i]==0)
			return 0;
	}
	return 1;
}

inline long long getans(long long n) {
	long long ans = 0;
	if(n>1)
		ans++;
	for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++) {
		long long temp = primes[i];
		while(temp<=n) {
			temp*=primes[i];
			ans++;
		}
		ans--;
	}
	return ans;
}

int main() {
	for(int i=2;i<=1000000;i++)
		if(isprime(i))
			primes.push_back(i);
	int t;
	cin>>t;
	for(int tn = 0;tn<t;tn++) {
		long long n;
		cin>>n;
		cout<<"Case #"<<tn+1<<": "<<getans(n)<<endl;
	}

}
