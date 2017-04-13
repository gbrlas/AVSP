#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int read_int() { int x; scanf("%d", &x); return x; }
ll read_long() { ll x; scanf("%lld", &x); return x; }

const int MAX = 1000001;
int notPrime[MAX];
int primeCount = 0;
vector<int> primes;

ll maxPow(ll N, ll p) {
    int res = 0;
    ll power = 1;
    while(power * p <= N) {
        power *= p;
        ++res;
    }
    return res;
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    notPrime[0] = 1;
    notPrime[1] = 1;
    for(int i = 2; i * i <= MAX; ++i) 
        if(!notPrime[i])
            for(int j = i * i; j < MAX; j += i)
                notPrime[j] = 1;
    for(int i = 2; i < MAX; ++i)
        if(!notPrime[i]) {
            primes.push_back(i);
            ++primeCount;
        }

    int T = read_int();
    for(int tests = 1; tests <= T; ++tests) {
        printf("Case #%d: ", tests);
        ll N = read_long();
        if(N == 1) {
            printf("0\n");
            continue;
        }
        ll hi = 1, lo = 0;
        for(int i = 0; i < primeCount; ++i) {
            ll prime = primes[i];
            if(prime * prime > N) break;
            ll maxp = maxPow(N, prime);
            hi += maxp;
            if(maxp > 0) ++lo;
        }
        printf("%lld\n", hi - lo);
    }

    return 0;
}