#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)

using namespace std;

class PrimeClass {
	public:
	
	vector <bool> is_prime;
	vector <int> primes;
	int checkN;
	
	PrimeClass(int N) {
		checkN = N;
		is_prime.resize(checkN + 1, true);
		is_prime[0] = false;
		is_prime[1] = false;
		for(int i = 2; i <= checkN; i++)
			for(int j = i + i; j <= checkN; j += i)
				is_prime[j] = false;
		for(int i = 0; i <= checkN; i++)
			if(is_prime[i])
				primes.push_back(i);
	};
	
	bool IsPrime(long long a) {
		if(a < 2)
			return false;
		if(a <= checkN)
			return is_prime[a];
		int b = int(ceil(sqrt(a) + 1e-9) + 1e-9);
		for(int i = 0; primes[i] <= b; i++)
			if(a % primes[i] == 0 && a != primes[i])
				return false;
		return true;
	};
	
	long long NthPrime(int N) {
		if(N >= primes.size())
			return -1;
		return primes[N];
	};
};

int main() {
	int C;
	cin >> C;
	PrimeClass p(2000000);
	for(int c = 0; c < C; ++c) {
		long long A, B, P;
		cin >> A >> B >> P;
		vector <vector <long long> > all;
		for(long long i = A; i <= B; ++i)
			all.push_back(vector <long long>(1, i));
		bool change = true;
		while(change) {
			change = false;
			foreach(i, 0, p.primes) {
				if(p.primes[i] < P)
					continue;
				if(p.primes[i] > B)
					break;
				foreach(j, 0, all) {
					foreach(k, 0, all[j])
						if(all[j][k] % p.primes[i] == 0)
							goto next;
					continue;
					next:;
					foreach(k, j + 1, all)
						foreach(l, 0, all[k])
							if(all[k][l] % p.primes[i] == 0) {
								foreach(z, 0, all[k])
									all[j].push_back(all[k][z]);
								change = true;
								all[k].clear();
							}
				}
			}
			for(int i = all.size() - 1; i >= 0; --i)
				if(all[i].size() == 0)
					all.erase(all.begin() + i);
		}
		cout << "Case #" << (c + 1) << ": " << all.size() << endl;
	}
	return 0;
}
