#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

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

struct Wire{
    int a, b;
    Wire(int a_, int b_) : a(a_), b(b_) {}
    bool operator<(const Wire& o) const{
	if(a != o.a) return (a < o.a);
	return (b < o.b);
    }
    bool operator>(const Wire& o) const{
	if(a != o.a) return (a > o.a);
	return (b > o.b);
    }
};

int calc(const vector<Wire>& w, const vector<vector<int> >& idx){
    int cnt = 0;
    rep(i, 0, w.size()) rep(j, 0, w[i].b){
	for(int k = idx[j].size() - 1; k >= 0; --k){
	    if(idx[j][k] < i) break;
	    ++cnt;
	}
    }
    return cnt;
}

int main(void){
    int T;
    cin >> T;
    rep(i, 0, T){
	int N;
	cin >> N;
	vector<Wire> w;
	vector<vector<int> > idx(20000);
	rep(j, 0, N){
	    int a, b;
	    cin >> a >> b;
	    w.push_back(Wire(a, b));
	}
	sort(w.begin(), w.end());
	rep(j, 0, N){
	    idx[w[j].b].push_back(j);
	}
	//sort(w.begin(), w.end(), greater<Wire>());
	//rep(j, 0, w.size()) { cout << w[j].a << " " << w[j].b << endl; }
	cout << "Case #" << (i+1) << ": " << calc(w, idx) << endl;
    }
    return 0;
}
