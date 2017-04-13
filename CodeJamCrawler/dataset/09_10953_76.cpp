#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

typedef unsigned long long u64;

int L, D, N;
map<char, vector<int> > dic[20];

void input(void){
    cin >> L >> D >> N;
    // process of dictionary
    vector<string> org;
    for(int i = 0; i < D; ++i){
	string s;
	cin >> s;
	assert(s.size() == L);
	for(int j = 0; j < L; ++j){
	    dic[j][s[j]].push_back(i);
	}
	org.push_back(s);
    }
}
u64 count(const vector<vector<char> > &m){
    vector<int> v(D, 1);
    for(int j = 0; j < L; ++j){
	vector<int> w(D, 0);
	for(size_t i = 0; i < m[j].size(); ++i){
	    const vector<int> &z = dic[j][m[j][i]];
	    for(size_t k = 0; k < z.size(); ++k){
		w[z[k]] = 1;
	    }
	}
	for(size_t k = 0; k < w.size(); ++k){
	    if(w[k] == 0) v[k] = 0;
	}
    }
    int ret = 0;
    for(size_t i = 0; i < v.size(); ++i) ret += v[i];
    return ret;
}
void calc(void){
    // process of words
    for(int i = 0; i < N; ++i){
	string s;
	cin >> s;
	vector<vector<char> > m;
	int j = 0;
	for(size_t k = 0; k < s.size(); ++j, ++k){
	    vector<char> v;
	    if(s[k] != '('){
		if(!dic[j][s[k]].empty()) v.push_back(s[k]);
	    }else{
		for(++k; s[k] != ')'; ++k){
		    if(!dic[j][s[k]].empty()) v.push_back(s[k]);
		}
	    }
	    m.push_back(v);
	}
	// count
	cout << "Case #" << (i+1) << ": " << count(m) << endl;
    }
}
int main(void){
    input();
    calc();
    return 0;
}
