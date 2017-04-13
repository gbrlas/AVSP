#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>
#include <cassert>
#include <tr1/unordered_map>

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

int N, P, Q;
vector<int> cell;

struct hash_t{
    vector<int> v_;
    hash_t(int n, const vector<int>& v) : v_(v) { v_.push_back(n); }
    bool operator==(const hash_t& h) const {
	if(v_.size() != h.v_.size()) return false;
	rep(i, 0, v_.size()){
	    if(v_[i] != h.v_[i]) return false;
	}
	return true;
    }
    struct hash_func{
	size_t operator()(const hash_t& h) const{
	    int k = 0;
	    rep(i, 0, h.v_.size()){
		k = (k << 4) ^ h.v_[i];
	    }
	    return k;
	}
    };
};

tr1::unordered_map<hash_t, int, hash_t::hash_func> memo;

int split(int n, const vector<int>& v){ // split 1..n at k 
    if(v.empty()) return 0;
    if(v.size() == 1) return n - 1;
    hash_t h(n, v);
    if(memo.find(h) != memo.end()) return memo[h];
    int best = numeric_limits<int>::max();
    rep(i, 0, v.size()){
	int k = v[i];
	assert(1 <= k && k <= n);
	vector<int> s, t;
	rep(j, 0, v.size()){
	    if(v[j] < k) s.push_back(v[j]);
	    if(v[j] > k) t.push_back(v[j] - k);
	}
	int cost = (n - 1) + split(k-1, s) + split(n-k, t);
	best = min(best, cost);
    }
    memo[h] = best;
    return best;
}

void calc(void){
    memo.clear();
    cout << split(P, cell) << endl;
}

int main(void){
    cin >> N;
    rep(c, 1, N+1){
	cout << "Case #" << c << ": ";
	cin >> P >> Q;
	cell.clear();
	cell.resize(Q);
	rep(i, 0, Q){
	    cin >> cell[i];
	    //cout << cell[i] << " ";
	}
	calc();
    }
    return 0;
}
