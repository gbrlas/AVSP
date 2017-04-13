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

void calc(const string& str){
    int tab[200];
    rep(i, 0, 200) tab[i] = -1;
    int k = 1;
    vector<int> v;
    rep(i, 0, str.size()){
    //for(int i = str.size() - 1; i >= 0; --i){
	char c = str[i];
	if(tab[c] == -1){
	    tab[c] = k;
	    if(k == 1) k = 0;
	    else if(k == 0) k = 2;
	    else ++k;
	}
	v.push_back(tab[c]);
    }
    long long sum = 0;
    //for(int i = v.size() - 1; i >= 0; --i){
    if(k == 0) k = 2;
    rep(i, 0, v.size()){
	sum *= k;
	sum += v[i];
    }
    cout << sum << endl;
}

int main(void){
    int T;
    cin >> T;
    string buf;
    getline(cin, buf);
    rep(c, 1, T+1){
	cout << "Case #" << c << ": ";
	getline(cin, buf);
	calc(buf);
    }
    return 0;
}
