#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cctype>
using namespace std;

#define llong long long

int k;
string s;

string apply(string tmp, const vector<int> &perm) {
	string ret=tmp;
	for(int i=0;i<k;i++) ret[i]=tmp[perm[i]];
	return ret;
}

int solve(const vector<int> &perm) {
	string res;
	for(int i=0;i<s.size();i+=k) {
		string tmp=s.substr(i,k);
		res+=apply(tmp,perm);
	}
	int ret=1;
	for(int i=1;i<res.size();i++) if(res[i]!=res[i-1]) ret++;
	return ret;
}

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cin>>k>>s;
		vector<int> perm;
		for(int i=0;i<k;i++) perm.push_back(i);
		int ret=-1;
		do {
			int res=solve(perm);
			if(ret==-1||res<ret) ret=res;
		} while(next_permutation(perm.begin(),perm.end()));
		cout<<"Case #"<<tc<<": "<<ret<<endl;
	}
}

