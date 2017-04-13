#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
ll INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back

ll figure(ll R, ll k, ll N, vector<ll> & people) {
	vector<ll> moveahead(N);
	vector<ll> winmoney(N);
	
	for(ll i = 0; i < N; i++){
		ll mv = 1;
		ll cursum = people[i];
		ll blah = 1;
		while(++blah <= N && cursum + people[(i+mv)%N] <= k){
			cursum += people[(i+mv)%N];
			mv++;
		}
		moveahead[i] = mv % N;
		winmoney[i] = cursum;
	}
	
	ll ret = 0;
	ll curpos = 0;
	for(ll i = 0; i < R; i++) {
		ret += winmoney[curpos];
		curpos = (curpos + moveahead[curpos])%N;
	}
	
	return ret;
}

int main(){
	ll T;
	cin >> T;
	
	string line;
	getline(cin,line);

	for(ll cnt = 0; cnt < T; cnt++) {
		getline(cin, line);
		stringstream ss(line.c_str());
		ll R, k, N;
		ss >> R >> k >> N;
		vector<ll> people;
		getline(cin, line);
		stringstream ss2(line.c_str());
		ll temp;
		while(ss2 >> temp) people.push_back(temp);
		assert(people.size() == N);
		
		cout << "Case #" << (cnt+1) << ": " << figure(R, k, N, people) << endl;
	}
}
	
	
	
	