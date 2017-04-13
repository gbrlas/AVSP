#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <numeric>
#include <iterator>

#define foreach(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;


inline string perm(string &s, vector<int> &p) {
	int k = p.size();
	int n = s.length() / k;
	string ret = s;

	for(size_t i = 0; i < n; ++i)
	{
		for(size_t j = 0; j < k; ++j)
		{
			ret[i*k + j] = s[i*k + p[j]];
		}
	}
	return ret;
}


int main() {
	int nn;
	cin >> nn;
	
	for(size_t ii = 0; ii < nn; ++ii)
	{
		int k;
		cin >> k;
		
		string S, T;
		cin >> S;
		
		vector<int> p(k);
		
		for(size_t i = 0; i < k; ++i)
			p[i] = i;
		
		int res = S.length();
		
		do {
			T = perm(S, p);
			res = min(res, unique(T.begin(), T.end()) - T.begin());
		} while(next_permutation(p.begin(), p.end()));
		
		cout << "Case #" << ii+1 << ": " << res << endl;
	}
}