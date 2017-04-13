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

bool calc(int N, int K){
    rep(i, 0, N){
	if((K & 1) == 0) return false;
	K >>= 1;
    }
    return true;
}

int main(void){
    int T;
    cin >> T;
    rep(i, 0, T){
	int N, K;
	cin >> N >> K;
	cout << "Case #" << (i+1) << ": " << (calc(N, K) ? "ON":"OFF") << endl;
    }
    return 0;
}
