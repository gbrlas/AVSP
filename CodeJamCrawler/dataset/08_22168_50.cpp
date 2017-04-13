#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


typedef long long ll;

ll A, B, P;

vector<ll> primes;
bool isp[1000000+11];

int fu[1000*1000+11];

int find(int x) { return fu[x] < 0?  x : fu[x] = find(fu[x]); }

void link(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(fu[y] < fu[x]) swap(x, y);
	fu[x] += fu[y];
	fu[y] = x;
}

void sito() {
	primes.push_back(2);
	for(int i=3; i<1000*1000+11; i+=2) if(!isp[i]) {
		primes.push_back(i);
		for(ll j=i*(ll)i; j<1000*1000+11; j+=i) isp[j] = true;
	}
}

int main() {
	sito();
	int tcase;
	scanf("%d", &tcase) ;
	for(int zz=0; zz<tcase; zz++) {
		scanf("%Ld%Ld%Ld", &A, &B, &P);
		ll len = B - A +  1;
		memset(fu, -1, sizeof(fu));
		for(int i=0; i<(int)primes.size(); i++) {
			ll z=  primes[i];
			if( z < P ) continue;
			ll k = A / z;
			ll pos = k * z;
			while(pos + z <= B) {
				if(pos >= A) link(pos-A, pos+z-A);
				pos += z;
			}
		}
		int ile = 0;
		for(ll a = A; a<=B; a++) if(fu[a-A] < 0) ile++;
		printf("Case #%d: %d\n", zz+1, ile);

	}
}
