#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MOD 1000002013
#define BIG 1000
#define ll long long

using namespace std;

ll N, M, o[BIG], e[BIG], p[BIG];

ll cost(ll dist){
	if(dist<0) dist=-dist;
	ll ans = N*(N+1)/2 - (N-dist)*(N-dist+1)/2;
	return ans%MOD;
}

int main(){
	int cases;
	cin >> cases;

	for(int qq=1; qq<=cases; ++qq){
		cout << "Case #" << qq << ": ";
		cin >> N >> M;
		ll actual=0;
		vector<pair<int,int> > v;

		for(int i=0; i<M; ++i){
			cin >> o[i] >> e[i] >> p[i];
			actual += cost(e[i]-o[i]) * p[i];

			v.push_back(make_pair(o[i], p[i]));
			v.push_back(make_pair(e[i]+1, -p[i]));

			actual %= MOD;
		}

		ll opt=0;
		sort(v.begin(), v.end());
		map<int,int> m;

		for(int i=0; i<2*M; ++i){
			if(v[i].second > 0){
				int add = v[i].second; // get on
				m[v[i].first] += add;

		//		cout << v[i].first << ": add " << add << '\n';
			}
			else{
		//		cout << v[i].first << ": off " << -v[i].second << '\n';

				int off = -v[i].second; // get off
				while(!m.empty() && off > 0){
					map<int,int> :: iterator mi = m.end(); --mi;
					int noff = min(off, mi->second);
					off -= noff;
					m[mi->first] -= noff;
					opt += noff * cost(mi->first - v[i].first + 1);
					opt %= MOD;
					if(m[mi->first] == 0) m.erase(mi);
				}
			}
		}

	//	cout << actual << ' ' << opt << '\n';
		opt = actual-opt;
		opt += MOD;
		opt %= MOD;
		cout << opt;

		cout << '\n';
	}
	return 0;
}