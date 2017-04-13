#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
  freopen("small.in", "rt", stdin);
  //freopen("large.in", "rt", stdin);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
	  int k;
	  cin >> k;
	  string s;
	  cin >> s;
	  vector<int> p;
	  for (int i = 0; i < k; i++)
		  p.push_back(i);
	  int res  = s.size();
	  do {
		string S = s;
		int base = 0;
		for (int i = 0; i < S.size(); i++) {
			if (i % k == 0)	base = i;
			S[i] = s[base + p[i - base]];
		}
		int r = 1;
		for (int i = 1; i < S.size(); i++)
			if (S[i] != S[i - 1]) r++;
		res = min(r, res);
	  } while (next_permutation(p.begin(), p.end()));
    cout << "Case #" << t + 1 << ": " << res << endl;
  }

  return 0;
}