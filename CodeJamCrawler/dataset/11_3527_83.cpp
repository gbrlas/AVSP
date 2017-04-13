#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

ll n;

bool is_prime[1<<22];
vector<ll> primes;

void sieve(){
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < (1<<11); i++)
		if (is_prime[i])
			for (int j = i*i; j < (1<<22); j += i)
				is_prime[j] = false;
	for (int i = 2; i < (1<<22); i++)
		if (is_prime[i])
			primes.push_back(i);
}

int main(){
	sieve();
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> n;
		int ans = 1;
		for (int i = 0; primes[i]*primes[i] <= n && i < primes.size(); i++){
			int left = n;
			int curr = 0;
			while(left){
				left /= primes[i];
				curr++;
			}
			curr--;
			ans += curr-1;
		}
		if (n == 1) ans = 0;
		cout << "Case #" << zz << ": " << ans << endl;
	}
	
	return 0;
}
