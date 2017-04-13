#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// I know this probably isn't fast enough

using namespace std;

const long long mod = 1000000007;

int do_case() {
	unsigned int N;
	cin >> N;

	vector<string> trains(N);
	for( size_t i=0; i<N; ++i ) {
		cin >> trains[i];
	}

	sort( trains.begin(), trains.end() );

	long long ways = 0;
	do {
		vector<bool> used(26, false);
		char prev = '0';
		bool valid = true;
		for( size_t i=0; i<N; ++i ) {
			for( char c : trains[i] ) {
				if( prev!=c && used[c-'a'] ) {
					valid = false;
					break;
				} else {
					used[c-'a'] = true;
					prev = c;
				}
			}
			if( !valid ) break;
		}
		if( valid ) ways = (ways+1) % mod;
	} while( next_permutation(trains.begin(), trains.end()) );

	map<string, int> beun;
	for( string a : trains ) {
		auto it = beun.find( a );
		if( it == beun.end() ) {
			beun[a] = 1;
		} else {
			beun[a] *= 2;
		}
	}
	for( auto p : beun ) {
		ways = ways*p.second % mod;
	}

	return ways;
}

int main() {
	unsigned int cases;
	cin >> cases;

	for( size_t i=0; i<cases; ++i ) {
		cout << "Case #" << (i+1) << ": " << do_case() << endl;
	}
}
