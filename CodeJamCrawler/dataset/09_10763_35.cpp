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
#include <fstream>


using namespace std;

typedef long double ld;
typedef unsigned long long ll;
double EPS = 1e-9;
ll INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


vector<ll> heh(ll N) {
	vector<ll> ds(9);
	while(N) {
		ll dig = N%10;
		if(dig) ds[dig-1]++;
		N/=10;
	}
	return ds;
}


ll getNum(vector<ll> digs) {
	ll ret = 0;
	for(ll i = 0; i < digs.size(); i++) {
		ret*=10;
		ret+=digs[i];
	}
	return ret;
}

string  output(vector<ll> digs) {
	stringstream ret;
for(int i = 0; i < digs.size(); i++) ret << digs[i];
return ret.str();

}

int main(){
	ll T;
	string temp;
	getline(cin, temp);
	T = atoi(temp.c_str());

	for(ll cnt = 0; cnt < T; cnt++) {
		getline(cin, temp);
		ll N = atoi(temp.c_str());
		vector<ll> digs;
		for(ll i = 0; i< temp.size(); i++) if(isdigit(temp[i]))digs.push_back(temp[i]-'0');
		string ans;
		if(next_permutation(digs.begin(), digs.end())) {
			ans  = output(digs);
		} else {
			digs.push_back(0);
			sort(digs.begin(), digs.end());
			ll nz = 0;
			ll curpos = 0;
			while(digs[curpos]==0){
				nz++;
				curpos++;
			}
			vector<ll> newdigs;
			newdigs.push_back(digs[curpos]);
			curpos++;
			while(nz) {
				newdigs.push_back(0);
				nz--;
			}
			while(curpos < digs.size()) {
				newdigs.push_back(digs[curpos]);
				curpos++;
			}
			ans = output(newdigs);
		}



		cout << "Case #" << (cnt+1) << ": " << ans << endl;
	}
}


