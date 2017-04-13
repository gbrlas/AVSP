#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (int)b; ++i)

template<typename T>
vector<T> split(const string& str){
    vector<T> ret;
    istringstream is(str);
    T tmp;
    while(is >> tmp) ret.push_back(tmp);
    return ret;
}

template<typename T>
inline void resize(vector<vector<T> > &v, int X, int Y){
    v.resize(X); for(int x = 0; x < X; ++x) v[x].resize(Y);
}

static vector<long long> next, cost;
void calc_next_cost(int R, int k, const vector<int>& r){
    next.clear();
    cost.clear();
    rep(i, 0, r.size()){
	long long sum = 0;
	rep(j, 0, r.size()){
	    long long old = sum;
	    long long z = (i + j) % r.size();
	    sum += r[z];
	    if(sum > k){
		next.push_back(z);
		cost.push_back(old);
		break;
	    }
	    if(j == r.size() - 1){
		next.push_back(i);
		cost.push_back(sum);
		break;
	    }
	}
    }
    assert(next.size() == r.size());
    assert(cost.size() == r.size());
    //cout << "next:"; rep(i, 0, r.size()) cout << " " << next[i]; cout << endl;
    //cout << "cost:"; rep(i, 0, r.size()) cout << " " << cost[i]; cout << endl;
}

long long calc(int R, int k, const vector<int>& r){
    calc_next_cost(R, k, r);
    
    long long total = 0;
    vector<bool> visit(r.size(), false);
    for(int i = 0, run = 0; run < R; ++run){
	total += cost[i];
	visit[i] = true;
	i = next[i];

#if 1
	if(visit[i] && run + 1 < R){
	    fill(visit.begin(), visit.end(), false);
	    long long cycle = 0, mul = 0;
	    for(int j = i; !visit[j]; j = next[j]){
		mul += cost[j];
		visit[j] = true;
		++cycle;
	    }
	    //cout << R << " " << run << " " << total << " " << i << " " << mul << " " << cycle << endl;
	    assert(visit[i]);
	    total += mul * ((R - run - 1) / cycle);
	    for(int j = i, k = 0; k < (R - run - 1) % cycle; ++k){
		total += cost[j];
		j = next[j];
	    }
	    break;
	}
#endif
    }
    return total;
}

int main(void){
    int T;
    cin >> T;
    rep(i, 1, T+1){
	int R, k, N;
	cin >> R >> k >> N;
	vector<int> r(N);
	rep(j, 0, N){
	    cin >> r[j];
	}
	cout << "Case #" << i << ": " << calc(R, k, r) << endl;
    }
    return 0;
}
